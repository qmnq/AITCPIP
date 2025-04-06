#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>

class smallwidget : public QWidget
{
    Q_OBJECT
public:
    explicit smallwidget(QWidget *parent = nullptr);
    QSpinBox *spin;
    QSlider *slider;    //滑动条

signals:

};

#endif // SMALLWIDGET_H
