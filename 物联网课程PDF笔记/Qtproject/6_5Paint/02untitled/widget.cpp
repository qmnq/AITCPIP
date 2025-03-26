#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    i = 0;
    j = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
   p.drawPixmap(i,j,100,100,QPixmap("../01untitled/picture/1.jpg"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    i = event->x();
    j = event->y();
    //刷新绘图
    this->update();
}
