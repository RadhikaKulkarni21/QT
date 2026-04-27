#ifndef CONTACTSLISTMODELS_H
#define CONTACTSLISTMODELS_H

#include <QAbstractListModel>
#include <QQmlEngine>

class ContactsListModels : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    enum ContactsRoles {
        FirstName = 0,
        LastName,
        Age,
        PhoneNumber
    };

    ContactsListModels();

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent) override;

private:
    QStringList firstNames;
    QStringList lastNames;
    QList<int> ages;
    QStringList phoneNumbers;
};

#endif // CONTACTSLISTMODELS_H
