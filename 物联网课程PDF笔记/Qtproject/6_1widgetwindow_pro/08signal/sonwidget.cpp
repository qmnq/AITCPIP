#include "sonwidget.h"

SonWidget::SonWidget(QWidget *parent):QWidget{parent}
{
    //子窗口的按键命名
    sbutton = new QPushButton("隐藏子窗口，显示父窗口",this);

    //在子窗口的构造函数设置窗口参数
    this->setWindowTitle("子窗口");

    //子窗口连接:当点击了子类窗口的按钮，就发送一个信号，然后让父窗口接收这个信号
    connect(sbutton,&QPushButton::clicked,this,&SonWidget::emit_mysignal);
}

void SonWidget::emit_mysignal()
{
    //点击按钮 槽函数发送信号
    emit show_hide_signal(10);
}
