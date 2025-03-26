#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int i;
    int j;
protected:
    void paintEvent(QPaintEvent *event);

    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
