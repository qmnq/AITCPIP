#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new mybutton;  //在堆区创建的button,如果不指定父类为this窗口,那么窗口析构的时候,是不会析构button的
    //但如果制定了button,那么在析构窗口的时候,就会调用button的析构函数.
    button ->setParent(this);
}

Widget::~Widget()
{
}

