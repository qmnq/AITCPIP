#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

//1.�������������ʹ�õĻ���������������ֻ��������캯�����ʣ����˹��캯��֮�󣬾ͻ����٣�ֻ����һ�¡�
//2.��ˣ���Ҫ��.h���涨��һ��PushButton��ָ�롣
//    QPushButton button;
//    button.show();

//3.��ָ�����new������QPushButton���ٵ��ú�����new��button���˺����������١�
//4.����ʾʱ��button�ǵ�������һ�����ڣ���û�аѰ�ť�ŵ���һ���������档
//    button = new QPushButton;
//7.Ҳ������newʱ��ֱ�Ӵ�thisָ��
//    button = new QPushButton(this);
//8.������7�Ļ����������ı�
    button = new QPushButton("����",this);
    //���������ťָ����������ô��ť�ʹ����ǵ�����ʾ���������ť�ƶ��˸�����ֻҪ��������ʾ�ˣ���ťҲ����ʾ��
    button->show(); //

//5.Ҫʹ��ť�ŵ��������棬��Ҫָ����ť�ĸ����Ǵ���
//    button->setParent(this); //����button�ĸ�����this������ڡ�
//6.���ð�ť�Ĵ�С �Լ� ��ť�������ʾ�ı���
    button->resize(300,200);
    button->move(100,100);
    button->setText("��¼");
}

Widget::~Widget()
{
}

