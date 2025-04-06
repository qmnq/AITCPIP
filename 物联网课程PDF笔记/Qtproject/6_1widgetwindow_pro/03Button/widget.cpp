#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

//1.如果这样来定义使用的话，由于生命周期只有这个构造函数，故，出了构造函数之后，就会销毁，只会闪一下。
//2.因此，需要在.h里面定义一个PushButton的指针。
//    QPushButton button;
//    button.show();

//3.用指针接收new出来的QPushButton，再调用函数，new的button出了函数不会销毁。
//4.但显示时，button是单独创建一个窗口，并没有把按钮放到第一个窗口里面。
//    button = new QPushButton;
//7.也可以在new时，直接传this指针
//    button = new QPushButton(this);
//8.可以在7的基础上设置文本
    button = new QPushButton("登入",this);
    //如果不给按钮指定父对象，那么按钮和窗口是单独显示，如果给按钮制定了父对象，只要父对象显示了，按钮也会显示。
    button->show(); //

//5.要使按钮放到窗口里面，需要指定按钮的父类是窗口
//    button->setParent(this); //设置button的父类是this这个窗口。
//6.设置按钮的大小 以及 按钮里面的显示文本：
    button->resize(300,200);
    button->move(100,100);
    button->setText("登录");
}

Widget::~Widget()
{
}

