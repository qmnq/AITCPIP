#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QWheelEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标点击坐标"<<event->x()<<","<<event->y();
    if(event->button()==Qt::LeftButton){
        qDebug()<<"点击了左键";
    }else if(event->button()==Qt::RightButton){
        qDebug()<<"点击了右键";
    }

}

void Widget::mouseMoveEvent(QMouseEvent *event){
    qDebug()<<"鼠标点击不动的坐标"<<event->x()<<","<<event->y();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event){
    qDebug()<<"鼠标双击的坐标"<<event->x()<<","<<event->y();
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    qDebug()<<"鼠标释放了";
}

//void Widget::wheelEvent(QWheelEvent *event){
//    if(event->angleDelta() == Qt::Vertical)//如果滚动方向是垂直方向
//    {
//        qDebug()<<"滚轮"<< event->x() <<","<<event->y();

//    }
//}

void Widget::keyPressEvent(QKeyEvent *event){
    qDebug()<<event->key();
    //打印出按下的键的ASCII码  a--65
    if(event->modifiers()==Qt::ShiftModifier){
        qDebug()<<"按下了shift按键";
    }
    else if(event->modifiers()==Qt::ControlModifier){
        qDebug()<<"按下了Ctrl按键";
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event){
    qDebug()<<"释放了"<<event->key()<<"按键";
}

void Widget::resizeEvent(QResizeEvent *event){
    qDebug()<<"窗口大小发生了改变";
    qDebug()<<"改变前的大小"<<event->oldSize();
    qDebug()<<"改变后的大小"<<event->size();
}

void Widget::enterEvent(QEvent *event){
    qDebug()<<"进入";
}

void Widget::leaveEvent(QEvent *event){
    qDebug()<<"离开";
}
