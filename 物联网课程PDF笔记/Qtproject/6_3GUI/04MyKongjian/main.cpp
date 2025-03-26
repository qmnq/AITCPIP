#include "widget.h"

#include <QApplication>
#include "smallwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    smallwidget s;
//    s.show();

    //把自定义控件添加到窗口。
    return a.exec();
}
