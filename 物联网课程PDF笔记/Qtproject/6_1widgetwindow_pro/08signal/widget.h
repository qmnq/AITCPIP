#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "sonwidget.h"
#include <QPushButton>

class Widget : public QWidget   //父窗口Widget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    SonWidget *sonwindow;   //父类定义子类窗口指针，用于构造函数new一个窗口。
    QPushButton *fbutton;   //父窗口的按钮（作用：按了之后隐藏父窗口，显示子窗口，这里显示子窗口可以通过QObject显示子类窗口）

public slots:
    //定义槽函数：点击按钮产生信号
    void button_cb();
    //再定义一个槽函数，用于接收到子窗口信号后的作用
    void signal_cb(int a);
};
#endif // WIDGET_H
