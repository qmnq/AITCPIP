#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new mybutton;  //�ڶ���������button,�����ָ������Ϊthis����,��ô����������ʱ��,�ǲ�������button��
    //������ƶ���button,��ô���������ڵ�ʱ��,�ͻ����button����������.
    button ->setParent(this);
}

Widget::~Widget()
{
}

