#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //widget�Ĺ��캯�����������д��������ô�������
    //thisָ��������ڡ�

    //���ô��ڱ���
    this->setWindowTitle("hello qt");

    //���ÿ�ߴ�С��������󴰿ڻ���������
    this->resize(600,400);

    //���ù̶���С����������Ϻ󴰿ڴ�С�����ٸı䡣
    this->setFixedSize(800,400);

}

Widget::~Widget()
{
}

