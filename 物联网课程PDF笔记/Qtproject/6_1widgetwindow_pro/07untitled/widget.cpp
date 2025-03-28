#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    button = new QPushButton;
    button->setParent(this);
    button->setText("打印志杰牛逼");
    //注册信号与槽的连接
    //槽函数可以是普通的成员函数，还可以是自定义槽函数
    connect(button,&QPushButton::pressed,this,&Widget::print);

}

Widget::~Widget()
{
}

void Widget::print()
{
    qDebug() << "志杰牛逼";
}
