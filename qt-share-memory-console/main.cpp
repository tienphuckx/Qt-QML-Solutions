#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include "SharedMemoryManager.h"

void showMenu()
{
    qDebug() << "\nChoose an option:";
    qDebug() << "1 - Write data to shared memory";
    qDebug() << "2 - Read data from shared memory";
    qDebug() << "0 - Exit";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    SharedMemoryManager manager;
    QTextStream input(stdin);

    bool exit = false;

    while (!exit) {
        showMenu();

        qDebug() << "Enter your choice: ";
        QString choice = input.readLine(); // Use readLine() to read the entire input line

        if (choice == "1") {
            qDebug() << "Enter the data to write to shared memory: ";
            QString dataToWrite = input.readLine(); // Read user input using readLine()

            if (manager.writeToSharedMemory(dataToWrite)) {
                qDebug() << "Data written successfully.";
            } else {
                qDebug() << "Failed to write data to shared memory.";
            }

        } else if (choice == "2") {
            qDebug() << "Reading data from shared memory...";
            QString dataRead = manager.readFromSharedMemory();

            if (!dataRead.isEmpty()) {
                qDebug() << "Data read from shared memory: " << dataRead;
            } else {
                qDebug() << "No data available or error reading shared memory.";
            }

        } else if (choice == "0") {
            qDebug() << "Exiting the application...";
            exit = true;

        } else {
            qDebug() << "Invalid choice. Please try again.";
        }
    }

    return 0;
}
