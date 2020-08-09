#ifndef STARDELEGATE_H
#define STARDELEGATE_H

#include <QStyledItemDelegate>

class StarDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit StarDelegate(QObject *parent = nullptr);

private slots:
    void commitAndCloseEditor();


private:
    QPolygon poly;

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // STARDELEGATE_H
