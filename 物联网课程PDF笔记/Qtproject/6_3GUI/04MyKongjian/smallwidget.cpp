#include "smallwidget.h"
#include <QHBoxLayout>

smallwidget::smallwidget(QWidget *parent)
    : QWidget{parent}
{
    slider = new QSlider(Qt::Horizontal,this);  //在这个窗口创建一个水平方向的滑动条。
    spin = new QSpinBox(this);

    //创建布局（控件）对象
    QHBoxLayout *layout = new QHBoxLayout;
    //将控件添加到布局中
    layout->addWidget(spin);
    layout->addWidget(slider);
    //将布局设置到窗口中
    this->setLayout(layout);

    //添加消息响应
    connect(spin,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),slider,&QSlider::setValue);
    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}
