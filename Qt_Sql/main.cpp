#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the database" << db.lastError();
        return false;
    }
    return true;
}

void updateProduct(int id, const QString &newProductName, double newPrice)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE products SET product_name = :product_name, price = :price WHERE id = :id");
    query.bindValue(":product_name", newProductName);
    query.bindValue(":price", newPrice);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error updating product:" << query.lastError();
    } else {
        qDebug() << "Product updated successfully!";
    }
}

void deleteProduct(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting product:" << query.lastError();
    } else {
        qDebug() << "Product deleted successfully!";
    }
}

void deleteProducts(const QList<int> &ids)
{
    if (ids.isEmpty()) {
        qDebug() << "No IDs provided for deletion.";
        return;
    }
    QStringList idStrings;
    for (int id : ids) {
        idStrings << QString::number(id);
    }
    QString idsStr = idStrings.join(", ");
    QSqlQuery query;
    QString deleteQuery = "DELETE FROM products WHERE id IN (" + idsStr + ")";
    if (!query.exec(deleteQuery)) {
        qDebug() << "Error deleting products:" << query.lastError();
    } else {
        qDebug() << "Products with IDs (" << idsStr << ") deleted successfully!";
    }
}

void createTable(const QString &tableName, const QStringList &columns)
{
    QSqlQuery query;
    QString createTableStr = "CREATE TABLE IF NOT EXISTS " + tableName + " (";

    for (int i = 0; i < columns.size(); ++i) {
        createTableStr += columns[i];
        if (i < columns.size() - 1) {
            createTableStr += ", ";
        }
    }
    createTableStr += ")";
    if (!query.exec(createTableStr)) {
        qDebug() << "Error creating table:" << query.lastError();
    }
}

void insertProduct(const QString &productName, double price)
{
    QSqlQuery query;
    query.prepare("INSERT INTO products (product_name, price) VALUES (:product_name, :price)");
    query.bindValue(":product_name", productName);
    query.bindValue(":price", price);

    if (!query.exec()) {
        qDebug() << "Error inserting product:" << query.lastError();
    }
}

void queryProduct()
{
    QSqlQuery query("SELECT id, product_name, price FROM products");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString productName = query.value(1).toString();
        double price = query.value(2).toDouble();
        qDebug() << "ID:" << id << ", Product Name:" << productName << ", Price:" << price;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (connectToDatabase()) {
        QStringList productColumns;
        productColumns << "id INTEGER PRIMARY KEY AUTOINCREMENT"
                       << "product_name TEXT"
                       << "price REAL";
        createTable("products", productColumns);

        insertProduct("ESP32", 190.00);
        insertProduct("DHT11", 80.50);
        insertProduct("Raspberry Pi Pico", 99.99);

        qDebug() << "Querying products after insertion:";
        queryProduct();
    }
    return a.exec();
}
