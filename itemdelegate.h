#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H

#include <QObject>

class ItemDelegate : public QObject
{
    Q_OBJECT
public:
    explicit ItemDelegate(QObject *parent = nullptr);

signals:

};

#endif // ITEMDELEGATE_H
