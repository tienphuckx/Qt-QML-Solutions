#include "SharedMemory.h"

SharedMemoryManager::SharedMemoryManager(QObject *parent) : QObject(parent) {
    // Set a unique key for the shared memory segment
    sharedMemory.setKey("SharedMemoryKey");
}

bool SharedMemoryManager::writeToSharedMemory(const QString &message) {
    // If the shared memory is not created, try to create it
       if (!sharedMemory.create(1024)) {

           if (sharedMemory.error() == QSharedMemory::AlreadyExists) {
                       // If already exists, attach to it
               qDebug() << "shared memory segment.exists";
                       sharedMemory.attach();
            }
           else {
                       qDebug() << "Unable to create shared memory segment.";
                       return false;
                   }

       }
        qDebug() << "Able to create shared memory segment.";
       // Lock the shared memory for writing
         sharedMemory.lock();
         char *to = (char*)sharedMemory.data();
         qDebug() << "Received message: " << message;
         qDebug() << " shared memory segment : " << to;
         QByteArray dataArray = message.toUtf8();
         const char *from = dataArray;
         memcpy(to, from, qMin(sharedMemory.size(), 1024));
         sharedMemory.unlock();

         return true;
}

QString SharedMemoryManager::readFromSharedMemory() {
    // Attach to the shared memory segment if not already attached
    if (!sharedMemory.isAttached()) {
        // qDebug() << "Unable to attach to shared memory segment.";
        qDebug() << "The process is still not attached";
        if (!sharedMemory.attach(QSharedMemory::ReadOnly)) {
            qDebug() << "Cannot attach too share memory to read";
            return "";
        }
    }

    // Lock the shared memory for reading

    sharedMemory.lock();
    const char *from = (const char *) sharedMemory.constData();
    QString message = QString::fromUtf8(from);
    sharedMemory.unlock();
    return message;
}
