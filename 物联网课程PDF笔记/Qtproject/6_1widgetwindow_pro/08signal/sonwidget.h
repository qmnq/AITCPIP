#ifndef SONWIDGET_H
#define SONWIDGET_H

#include <QWidget>
#include <QPushButton>

class SonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SonWidget(QWidget *parent = nullptr);
    QPushButton *sbutton;   //子窗口的按钮（作用：按下后隐藏子窗口，显示父窗口，注意，子类显示父类窗口只能用信号与槽机制）
signals:
    //在信号这里  定义一个信号
    //信号可以有参数，也可以没有参数，信号没有返回值。信号不需要定义，只需要声明！！
    void show_hide_signal(int a);
public slots:
    //定义槽函数，用于发射信号。
    void emit_mysignal();
};

#endif // SONWIDGET_H
