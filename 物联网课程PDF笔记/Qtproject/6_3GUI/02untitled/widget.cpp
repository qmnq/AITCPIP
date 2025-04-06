#include "widget.h"
#include <QPixmap>
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(600,400);
    label = new QLabel(this);
    label->resize(100,100);
    label->move(100,100);
//    label -> setText("我是一个标签");
    label -> setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>"); //a 表示超链接，显示的文本是“百度一下”
    label -> setOpenExternalLinks(true);    //设置：点击链接 可以跳转

    label_pic = new QLabel(this);
    label_pic->resize(300,200);
    label_pic->move(200,200);
//    label -> setText("我是一个标签");
    label_pic -> setPixmap(QPixmap("../02untitled/picture/1.jpg"));
    //设置一个自适应大小：
    label_pic -> setScaledContents(true);

    label_move = new QLabel(this);
    label_move->resize(100,100);
    label_move->move(300,200);

    QMovie *move = new QMovie("../02untitled/picture/1.gif");
    label_move->setMovie(move);
    label_move->setScaledContents(true);
    move->start();  //启用

}

Widget::~Widget()
{
}

