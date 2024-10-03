#include "SharedMemoryManager.h"
#include <QByteArray>
#include <QDebug>
#include <QSharedMemory>
#include <QSystemSemaphore>

SharedMemoryManager::SharedMemoryManager(QObject *parent)
    : QObject(parent)
    , sharedMemory("SharedMemoryKey")
    , // Set a unique key for shared memory
    writeSemaphore("writeSemaphore", 1, QSystemSemaphore::Open)
    ,                                                         // Semaphore for writing
    readSemaphore("readSemaphore", 0, QSystemSemaphore::Open) // Semaphore for reading
{}

bool SharedMemoryManager::writeToSharedMemory(const QString &message)
{
    // Acquire the write semaphore to ensure exclusive access
    writeSemaphore.acquire();

    if (!sharedMemory.isAttached()) {
        if (!sharedMemory.create(1024)) {
            if (sharedMemory.error() == QSharedMemory::AlreadyExists) {
                if (!sharedMemory.attach()) {
                    qDebug() << "Error: Unable to attach to existing shared memory.";
                    writeSemaphore.release(); // Release semaphore on failure
                    return false;
                }
            } else {
                qDebug() << "Error: Unable to create shared memory.";
                writeSemaphore.release(); // Release semaphore on failure
                return false;
            }
        }
    }

    // Lock the shared memory for writing
    if (!sharedMemory.lock()) {
        qDebug() << "Error: Failed to lock shared memory.";
        writeSemaphore.release();
        return false;
    }

    // Prepare the data to write
    QByteArray byteArray = message.toUtf8();
    int dataSize = qMin(byteArray.size(), sharedMemory.size());

    // Get pointer to shared memory
    char *sharedData = static_cast<char *>(sharedMemory.data());
    if (!sharedData) {
        qDebug() << "Error: Failed to access shared memory data.";
        sharedMemory.unlock();
        writeSemaphore.release();
        return false;
    }

    // Copy data into shared memory
    memcpy(sharedData, byteArray.constData(), dataSize);

    // Zero-pad remaining memory if the message is smaller
    if (dataSize < sharedMemory.size()) {
        memset(sharedData + dataSize, 0, sharedMemory.size() - dataSize);
    }

    // Unlock shared memory after writing
    sharedMemory.unlock();

    // Release the semaphore for the reader
    readSemaphore.release();

    qDebug() << "Data written to shared memory.";
    return true;
}

QString SharedMemoryManager::readFromSharedMemory()
{
    // Acquire the read semaphore to ensure exclusive access
    readSemaphore.acquire();

    if (!sharedMemory.isAttached()) {
        if (!sharedMemory.attach()) {
            qDebug() << "Error: Unable to attach to shared memory.";
            writeSemaphore.release(); // Release write semaphore if attaching fails
            return QString();
        }
    }

    // Lock shared memory for reading
    if (!sharedMemory.lock()) {
        qDebug() << "Error: Failed to lock shared memory.";
        writeSemaphore.release();
        return QString();
    }

    // Get pointer to shared memory data
    const char *sharedData = static_cast<const char *>(sharedMemory.data());
    if (!sharedData) {
        qDebug() << "Error: Failed to access shared memory data.";
        sharedMemory.unlock();
        writeSemaphore.release();
        return QString();
    }

    // Convert shared memory data to QByteArray and ensure it's null-terminated
    QByteArray byteArray(sharedData, sharedMemory.size());
    int nullTerminatorIndex = byteArray.indexOf('\0');
    if (nullTerminatorIndex != -1) {
        byteArray.truncate(nullTerminatorIndex); // Truncate to null terminator
    }

    // Convert QByteArray to QString
    QString message = QString::fromUtf8(byteArray);

    // Unlock shared memory after reading
    sharedMemory.unlock();

    // Release write semaphore for the writer
    writeSemaphore.release();

    qDebug() << "Data read from shared memory.";
    return message;
}
