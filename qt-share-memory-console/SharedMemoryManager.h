#ifndef SHAREDMEMORYMANAGER_H
#define SHAREDMEMORYMANAGER_H

#include <QObject>
#include <QSharedMemory>
#include <QString>
#include <QSystemSemaphore>

class SharedMemoryManager : public QObject
{
    Q_OBJECT

public:
    explicit SharedMemoryManager(QObject *parent = nullptr);

    // Writes a message to the shared memory
    bool writeToSharedMemory(const QString &message);

    // Reads a message from the shared memory
    QString readFromSharedMemory();

private:
    QSharedMemory sharedMemory;      // Shared memory object
    QSystemSemaphore writeSemaphore; // Semaphore for write synchronization
    QSystemSemaphore readSemaphore;  // Semaphore for read synchronization
};

#endif // SHAREDMEMORYMANAGER_H
