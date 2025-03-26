#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮 点击按钮关闭窗口
//    this->close();    //这个函数直接关闭窗口。但我们需要让其在按钮按下后再调用该函数。

    //堆区new一个按钮，命名为:关闭窗口，父类为Widget
    QPushButton *p = new QPushButton("关闭窗口",this);
    //设置点击按钮 会调用窗口的close函数
    //设置连接 点击按钮产生信号  会调用窗口的close函数
//    * sender :   按钮发出
//    * signal :   信号是 QPushButton里面的点击信号
//    * receiver : 窗口接收
//    * slot   :   调用的 一定是接收信号的对象里面的槽函数
    connect(p,&QPushButton::clicked,this,&QWidget::close);

}

Widget::~Widget()
{
}

