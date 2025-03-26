#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标点击移动事件，键按下拖动鼠标变化的
    void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件

//    void wheelEvent(QWheelEvent *event);//滚轮事件

    void keyPressEvent(QKeyEvent *event); //键盘按下事件
    void keyReleaseEvent(QKeyEvent *event); //键盘抬起事件

    void resizeEvent(QResizeEvent *event); //窗口大小改变事件

    void enterEvent(QEvent *event); //鼠标进入界面事件
    void leaveEvent(QEvent *event); //鼠标离开界面事件

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
