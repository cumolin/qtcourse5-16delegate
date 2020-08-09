#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "itemmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_AddBtn_clicked();

    void on_RemoveBtn_clicked();

private:
    Ui::Widget *ui;
    ItemModel  * model;
};
#endif // WIDGET_H
