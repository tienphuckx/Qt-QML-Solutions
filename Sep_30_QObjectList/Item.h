#ifndef ITEM_H
#define ITEM_H

#include <QObject>

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString gender READ gender WRITE setGender NOTIFY genderChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)

public:
    explicit Item(QObject *parent = nullptr)
        : QObject(parent)
    {}

    QString name() const { return m_name; }
    void setName(const QString &name)
    {
        if (m_name != name) {
            m_name = name;
            emit nameChanged();
        }
    }

    QString gender() const { return m_gender; }
    void setGender(const QString &gender)
    {
        if (m_gender != gender) {
            m_gender = gender;
            emit genderChanged();
        }
    }

    QString position() const { return m_position; }
    void setPosition(const QString &position)
    {
        if (m_position != position) {
            m_position = position;
            emit positionChanged();
        }
    }

signals:
    void nameChanged();
    void genderChanged();
    void positionChanged();

private:
    QString m_name;
    QString m_gender;
    QString m_position;
};

#endif // ITEM_H
