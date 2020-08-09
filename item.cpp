#include "item.h"

Item::Item(QObject *parent) : QObject(parent)
{

}

Item::Item(const QString & name, const int & id, const int & rate, QObject *parent): QObject(parent), m_name(name), m_id(id), m_rate(rate){

}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &name)
{
    m_name = name;
}

int Item::id() const
{
    return m_id;
}

void Item::setId(int id)
{
    m_id = id;
}

int Item::rate() const
{
    return m_rate;
}

void Item::setRate(int rate)
{
    m_rate = rate;
}
