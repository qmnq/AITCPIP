#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPainter>
#include <QPen>
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

void Widget::paintEvent(QPaintEvent * event)
{
//    qDebug() << "###";

    //绘图一定要在这个函数中绘图
    //画家
    QPainter p(this);//画家需要指定一个画图的设备。this就是窗口————定义了一个画家并制定了绘图的设备
    p.drawPixmap(0,0,this->width(),this->height(),QPixmap("../01untitled/picture/1.jpg")); //画一个图，宽高
    QPen pen;   //定义一支笔
    pen.setColor(QColor(Qt::red));  //设置笔的颜色
    p.setPen(pen);//将笔要给到画家
    p.drawLine(50,50,300,300);
}
