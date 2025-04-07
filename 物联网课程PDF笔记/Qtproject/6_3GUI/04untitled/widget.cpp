#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    t = new QTimer;
    //有了定时器，可以设置定时器的超时事件，如果超时 会发出一个超时信号。

    //这里定时器超时后就会在这里链接到Lambda表达式
    connect(t,&QTimer::timeout,this,[](){
        qDebug() << "timeout";
    });
    //定时器必须启动

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()    //ui自链接的槽函数，点击一次开始，然后就会在这里开始启动定时器
{
    t->start(1000); //启动定时器。 1000*1ms 超时一次，超时一次就调用槽函数
}


void Widget::on_pushButton_2_clicked()
{
    t->stop();  //停止定时器。
}

