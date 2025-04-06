#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QPushButton *button;    //Fn + F1：跳转到对应的帮助文档。
                            //Fn + F4：从.h 跳转到 .c 文件
public slots:

    void print();   //定义一个public的槽函数，注意：该函数需不需要参数，需要去看&QPushButton::pressed有没有参数。
    //如果 信号没有参数，则槽函数也不需要参数。 如果信号有参数，槽函数可以有也可以没有参数。
};
#endif // WIDGET_H
