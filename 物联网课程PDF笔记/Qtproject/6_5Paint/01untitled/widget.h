#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent * event);   //这个函数是：只要窗口发生改变，就会产生一个画图事件，画图的事件就会自动调用该函数。我们只需要在该类里面重写该虚函数即可
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
