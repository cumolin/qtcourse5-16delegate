#ifndef ITEM_H
#define ITEM_H

#include <QObject>

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = nullptr);
    Item(const QString & name, const int & id, const int & rate, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    int id() const;
    void setId(int id);

    int rate() const;
    void setRate(int rate);

signals:

private:
    QString m_name;
    int m_id;
    int m_rate;

};

#endif // ITEM_H
