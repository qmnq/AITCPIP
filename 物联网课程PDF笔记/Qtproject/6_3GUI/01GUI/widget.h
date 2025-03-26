#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget   //注意：这个Widget是QWidget，窗口
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

private:
    //窗口里面有一个UI指针，指向.ui的界面的控件
    Ui::Widget *ui; //而这个Widget是Ui_Widget类（定义在ui_widget.h里面）
};
#endif // WIDGET_H
