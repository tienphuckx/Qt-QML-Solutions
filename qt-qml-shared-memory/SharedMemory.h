#ifndef SHAREDMEMORYMANAGER_H
#define SHAREDMEMORYMANAGER_H

#include <QObject>
#include <QSharedMemory>
#include <QDebug>

class SharedMemoryManager : public QObject {
    Q_OBJECT
public:
    explicit SharedMemoryManager(QObject *parent = nullptr);

    Q_INVOKABLE bool writeToSharedMemory(const QString &message);
    Q_INVOKABLE QString readFromSharedMemory();

private:
    QSharedMemory sharedMemory;
};

#endif // SHAREDMEMORYMANAGER_H
