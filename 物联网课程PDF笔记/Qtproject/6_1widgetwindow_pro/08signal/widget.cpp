#include "widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置父窗口的窗口参数
    this->setWindowTitle("父窗口");

    //创建子类窗口
    this->sonwindow = new SonWidget;
    sonwindow->show();

    //父窗口按钮的功能实现
    fbutton = new QPushButton;
    fbutton->setText("隐藏父窗口，显示子窗口");
    fbutton->setParent(this);


    //设置父窗口信号与本窗口的按键槽的连接
    connect(fbutton,&QPushButton::clicked,this,&Widget::button_cb);
    //设置父窗口与子窗口发送的信号 的连接
    connect(sonwindow,&SonWidget::show_hide_signal,this,&Widget::signal_cb);
    //这里不是emit_mysignal，而是show_hide_signal,子窗口发送信号的函数是show_hide_signal。
}

Widget::~Widget()
{
}

void Widget::button_cb()
{
    //将父窗口隐藏
    this->hide();
    //显示子窗口(找到子窗口，再调用子窗口的show显示)
    this->sonwindow->show();
}

void Widget::signal_cb(int a)
{
    //打印接收到的信号a
    qDebug() << a;
    //显示父窗口,隐藏子窗口
    this->show();
    this->sonwindow->hide();
}
