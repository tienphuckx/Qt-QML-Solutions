#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QFile>
#include <QList>
#include <QObject>
#include <QTextStream>
#include "Item.h"

class ItemList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> items READ items NOTIFY itemsChanged)

public:
    explicit ItemList(QObject *parent = nullptr)
        : QObject(parent)
    {
        loadItems(); // Try to load items from the external file or resource
    }

    // Return the list of items
    QList<QObject *> items() const { return m_items; }

    // Function to add a new item
    Q_INVOKABLE void addItem(const QString &name, const QString &gender, const QString &position)
    {
        Item *newItem = new Item(this); // Create a new item
        newItem->setName(name);         // Set its name
        newItem->setGender(gender);     // Set its gender
        newItem->setPosition(position); // Set its position
        m_items.append(newItem);        // Add it to the list
        emit itemsChanged();            // Notify QML that the list has changed

        saveItems(); // Save the new item to the file
    }

private:
    QList<QObject *> m_items; // The list of items

    // External file path to save/load dynamic data
    QString itemsFilePath() const
    {
        return "items.txt"; // External file where changes will be saved
    }

    // Function to save items to an external file
    void saveItems()
    {
        QFile file(itemsFilePath()); // Save to external items.txt
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (const auto &item : m_items) {
                Item *i = qobject_cast<Item *>(item);
                if (i) {
                    // Write the item's data as comma-separated values
                    out << i->name() << "," << i->gender() << "," << i->position() << "\n";
                }
            }
            file.close();
        }
    }

    // Function to load items from an external file or resource file
    void loadItems()
    {
        QFile file(itemsFilePath());

        // Try to load from external file first
        if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            loadItemsFromStream(&file);
            file.close();
        } else {
            // Load from resource file (read-only) if external file doesn't exist
            QFile resourceFile(":/employee.txt"); // Load from resource file
            if (resourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                loadItemsFromStream(&resourceFile);
                resourceFile.close();
            }
        }
    }

    // Function to load items from a QTextStream (both external and resource files)
    void loadItemsFromStream(QFile *file)
    {
        QTextStream in(file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 3) {
                addItem(fields[0], fields[1], fields[2]); // Add the item to the list
            }
        }
    }

signals:
    void itemsChanged(); // Signal emitted when the items list changes
};

#endif // ITEMLIST_H
