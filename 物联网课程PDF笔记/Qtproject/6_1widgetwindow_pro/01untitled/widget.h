#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget       //Widget��̳���QWidget�����пؼ��Ļ��࣬������Ϊ����һ�����ڣ�������WidgetҲ��һ�����ڡ�
{
    Q_OBJECT    //������ܣ��źŴ����ʱ���õ���Ĭ���ǻ���ϵġ�

public:
    Widget(QWidget *parent = nullptr);  //���캯������һ���Դ��������ɴ��οɲ�����
    ~Widget();      //��������
};
#endif // WIDGET_H
