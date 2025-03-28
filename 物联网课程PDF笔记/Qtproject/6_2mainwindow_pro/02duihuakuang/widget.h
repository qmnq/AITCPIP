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
    QPushButton *button;    //标准对话框按钮：当点了按钮的时候，弹出对话框，返回文件的名字
    QPushButton *button1;   //模态对话框按钮
    QPushButton *button2;   //非模态对话框按钮


};
#endif // WIDGET_H
