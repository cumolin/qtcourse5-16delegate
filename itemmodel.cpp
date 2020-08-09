#include "itemmodel.h"
#include "item.h"

ItemModel::ItemModel(QObject *parent) : QAbstractTableModel(parent)
{
    items.append(new Item("餅乾", 0, 2));
    items.append(new Item("巧克力", 1, 5));
    items.append(new Item("牛奶", 2, 2));
    items.append(new Item("冰淇淋", 3, 5));
    items.append(new Item("蘋果", 4, 2));
    items.append(new Item("起司", 5, 3));
}

ItemModel::~ItemModel(){
    qDeleteAll(items);
}

int ItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return items.size();
}

int ItemModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

bool ItemModel::hasChildren(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if(parent.column() == 0)
        return  false;
    return true;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= items.count())
        return QVariant();
    Item * item = items[index.row()];
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        if(index.column() == 0){
            //Name
            return item->name();
        }
        if(index.column() == 1){
            //ID
            return item->id();
        }
        if(index.column() == 2){
            //Rate
            return item->rate();
        }
    }

    if(role == NameRole){
        return  item->name();
    }
    if(role == IDRole){
        return  item->id();
    }
    if(role == RateRole){
        return item->rate();
    }
    if(role == Qt::ToolTipRole){
        return  item->name();
    }
    return  QVariant();
}

bool ItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) {
        return false;
    }

    Item * item = items[index.row()];
    bool somethingChanged = false;

    switch (role) {

    case Qt::EditRole:
    {

        if(index.column() == 0){
            //Name
            if( item->name() != value.toString()){
                item->setName(value.toString());
                somethingChanged = true;
            }
        }

        if(index.column() == 1){
            //ID
            if(item->id() !=value.toInt()){
                item->setId(value.toInt());
                somethingChanged  = true;
            }
        }

        if(index.column() == 2){
            //Rate
            if(item->rate() != value.toInt()){
                item->setRate(value.toInt());
                somethingChanged  = true;
            }
        }

    }break;


    case NameRole:
    {
        if( item->name() != value.toString()){
            item->setName(value.toString());
            somethingChanged = true;
        }
    }
        break;


    case IDRole:
    {
        if(item->id() !=value.toInt()){
            item->setId(value.toInt());
            somethingChanged  = true;
        }
    }
        break;

    case RateRole:
    {
        if(item->rate() != value.toInt()){
            item->setRate(value.toInt());
            somethingChanged  = true;
        }
    }
    }

    if(somethingChanged){
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

QVariant ItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0 :
            return QString("商品名稱");
        case 1 :
            return QString("ID");
        case 2:
            return QString("評價");
        }
    }
    // vertical rows
    return QString("商品 %1").arg(section);
}

bool ItemModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row+count-1);

    for (int i = 0; i < count; ++i) {
        items.insert(row,new Item());
    }
    endInsertRows();
    return  true;
}

bool ItemModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row+count-1);

    for (int i = 0; i < count; ++i) {
        items.removeAt(row);
    }
    endRemoveRows();
    return true;
}

Qt::ItemFlags ItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> ItemModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[NameRole] = "name";
    roles[IDRole] = "id";
    roles[RateRole] = "rate";
    return  roles;
}

void ItemModel::addItem(Item *item)
{
    /*
    const int index = persons.size();
    beginInsertRows(QModelIndex(),index,index);
    persons.append(person);
    endInsertRows();
    */
    insertRows(items.size(),1);
    setData(index(items.size() -1,0),item->name(),Qt::EditRole);
    setData(index(items.size() -1,1),item->id(),Qt::EditRole);
    setData(index(items.size() -1,2),item->rate(),Qt::EditRole);
}

void ItemModel::addItem()
{
    Item *item = new Item("新商品", 0, 5);
    addItem(item);
}

void ItemModel::addItem(const QString &name, const int &id, const int & rate)
{
    Q_UNUSED(rate);
    Item *item = new Item(name, id, 5);
    addItem(item);
}

void ItemModel::removeItem(QModelIndex index)
{
    /*
    beginRemoveRows(QModelIndex(),index.row(),index.row());

    persons.removeAt(index.row());

    endRemoveRows();
    */
    removeRows(index.row(),1);
}
