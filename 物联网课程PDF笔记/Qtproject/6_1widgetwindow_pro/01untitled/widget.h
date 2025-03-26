#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget       //Widget类继承了QWidget（所有控件的基类，可以认为就是一个窗口），所以Widget也是一个窗口。
{
    Q_OBJECT    //这个不管，信号处理的时候用到。默认是会加上的。

public:
    Widget(QWidget *parent = nullptr);  //构造函数，有一个自带参数，可传参可不传参
    ~Widget();      //析构函数
};
#endif // WIDGET_H
