#include "widget.h"
#include "ui_widget.h"
#include "stardelegate.h"
#include <QInputDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new ItemModel(this);

    StarDelegate * starDelegate = new StarDelegate(this);

    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    ui->treeView->setModel(model);
    ui->tableView->setItemDelegateForColumn(2, starDelegate);
    ui->treeView->setItemDelegateForColumn(2, starDelegate);

    ui->tableView->setSelectionModel(ui->listView->selectionModel());
    ui->treeView->setSelectionModel(ui->listView->selectionModel());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_AddBtn_clicked()
{
    bool ok;
       QString name = QInputDialog::getText(nullptr, "Item Name",
                                            tr("Item name:"), QLineEdit::Normal,
                                            "Type in name", &ok);

       if (ok && !name.isEmpty()){

           int id = QInputDialog::getInt(nullptr,"Item ID","ID",0,0,120);

            Item * item = new Item(name,id, 5,this);

            model->addItem(item);
       }else{
           QMessageBox::information(nullptr,"Failure","Must specify name and age");
       }
}

void Widget::on_RemoveBtn_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeItem(index);
}
