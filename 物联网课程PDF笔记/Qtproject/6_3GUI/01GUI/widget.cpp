#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
//ui_widget.h 这个.h的来源是：系统有一个UIC的工具用于解析.ui文件，就会生成这样的一个.h（详细见带ui的项目课程）


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    qDebug() << "hello";
}

