#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //widget的构造函数，代码可以写在这里，设置窗口属性
    //this指向这个窗口。

    //设置窗口标题
    this->setWindowTitle("hello qt");

    //设置宽高大小，设置完后窗口还可以拉伸
    this->resize(600,400);

    //设置固定大小，设置完完毕后窗口大小不能再改变。
    this->setFixedSize(800,400);

}

Widget::~Widget()
{
}

