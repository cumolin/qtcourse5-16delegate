#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QAbstractTableModel>
#include "item.h"

class ItemModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ItemModel(QObject *parent = nullptr);
    ~ItemModel() override;
    enum ItemRoles{
        NameRole = Qt::UserRole +1,
        IDRole,
        RateRole
    };

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    bool hasChildren(const QModelIndex &parent) const override; //在treeView不會在最左邊顯柿子物件選項
    QVariant data(const QModelIndex &index, int role) const override;   //設定tableView顯示的內容
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;   //修改model內容
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override; //設定最左邊及最上面的標題
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;//插入一列
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;//刪除一列
    Qt::ItemFlags flags(const QModelIndex &index) const override;   //設定Item的flag
    QHash<int, QByteArray> roleNames() const override;

    void addItem(Item *item);
    void addItem();
    void addItem(const QString & name,const int & id, const int & rate);
    void removeItem(QModelIndex index);

private:
    QList<Item *> items;

};

#endif // ITEMMODEL_H
