#include "SharedMemory.h"

SharedMemoryManager::SharedMemoryManager(QObject *parent)
    : QObject(parent)
{
    // Set a unique key for the shared memory segment
    sharedMemory.setKey("SharedMemoryKey");
}

QString SharedMemoryManager::readFromSharedMemory()
{
    // Ensure shared memory is attached, try to attach if it's not
    if (!sharedMemory.isAttached() && !sharedMemory.attach()) {
        qDebug() << "Error: Unable to attach to shared memory.";
        return QString();
    }

    // Attempt to lock the shared memory for reading
    if (!sharedMemory.lock()) {
        qDebug() << "Error: Failed to lock shared memory.";
        return QString();
    }

    // Get pointer to shared memory data
    const char *sharedData = static_cast<const char *>(sharedMemory.data());
    if (!sharedData) {
        qDebug() << "Error: Failed to access shared memory data.";
        sharedMemory.unlock();
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

    // Unlock the shared memory
    sharedMemory.unlock();

    return message;
}

bool SharedMemoryManager::writeToSharedMemory(const QString &message)
{
    // Ensure shared memory is attached, create or attach if not
    if (!sharedMemory.isAttached()) {
        if (!sharedMemory.create(1024)) {
            if (sharedMemory.error() == QSharedMemory::AlreadyExists) {
                if (!sharedMemory.attach()) {
                    qDebug() << "Error: Unable to attach to existing shared memory.";
                    return false;
                }
            } else {
                qDebug() << "Error: Unable to create shared memory.";
                return false;
            }
        } else {
            qDebug() << "Shared memory created successfully.";
        }
    }

    // Attempt to lock shared memory for writing
    if (!sharedMemory.lock()) {
        qDebug() << "Error: Failed to lock shared memory.";
        return false;
    }

    // Prepare the data to write
    QByteArray byteArray = message.toUtf8();
    int dataSize = qMin(byteArray.size(), sharedMemory.size());

    // Get pointer to shared memory and verify it's valid
    char *sharedData = static_cast<char *>(sharedMemory.data());
    if (!sharedData) {
        qDebug() << "Error: Failed to access shared memory data.";
        sharedMemory.unlock();
        return false;
    }

    // Copy data to shared memory
    memcpy(sharedData, byteArray.constData(), dataSize);

    // Zero-pad the rest of the shared memory if message is smaller
    if (dataSize < sharedMemory.size()) {
        memset(sharedData + dataSize, 0, sharedMemory.size() - dataSize);
    }

    // Unlock shared memory after writing
    sharedMemory.unlock();

    qDebug() << "Data written successfully to shared memory.";
    return true;
}
