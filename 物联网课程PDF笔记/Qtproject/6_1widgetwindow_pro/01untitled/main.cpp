#include "widget.h"
#include "QWidget"
#include <QApplication>     //QT�Ŀ�ܣ��Ǳ�����ӵ�
#include <QDebug>
int main(int argc, char *argv[])    //QT�Ŀ�ܳ�ʼ����
{
    QApplication a(argc, argv);

    QWidget w;     //������һ������
    w.show();     //���ڵ�show��������ʾ

    w.resize(400,300); //���ô��ڴ�С��400*300
    w.setWindowTitle("Hello qt");
    qDebug() << "hello";    //Ӧ�ó������ �� ���hello

    //�������Ƕ�����һ��QT��һ������
    return a.exec();    //a.exe �������ó�������������while(1).ѭ������¼��Ĳ�����
}



























