#include "widget.h"
#include "QWidget"
#include <QApplication>     //QT的框架，是必须添加的
#include <QDebug>
int main(int argc, char *argv[])    //QT的框架初始化。
{
    QApplication a(argc, argv);

    QWidget w;     //定义了一个窗口
    w.show();     //窗口的show，进行显示

    w.resize(400,300); //设置窗口大小：400*300
    w.setWindowTitle("Hello qt");
    qDebug() << "hello";    //应用程序输出 里 输出hello

    //就是我们定义了一个QT的一个对象。
    return a.exec();    //a.exe 作用是让程序不死，类似于while(1).循环检测事件的产生。
}



























