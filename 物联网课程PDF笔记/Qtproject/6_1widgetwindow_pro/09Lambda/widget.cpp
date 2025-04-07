#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("点我",this);
    //槽函数可以是Lambda的表示
    int a = 10;
    int b = 20;
    //槽函数可以是一个Lambda表达式
    //Lambda表达式中[]中写的是=,    代表将上面的函数中的局部变量以值传递的方式传入到Lambda表达式
    //Lambda表达式中[]中写的是&,    代表将上面的函数中的局部变最以引用传递的方式传入到Lambda表达式
    //Lambda表达式中[]中写的是a,    代表将上面的函数中的局部变量a以值传递的方式传入到Lambda表达式
    //Lambda表达式中[]中写的是a,b,  代表将上面的函数中的局部变量a和b以值传递的方式传入到Lambda表达式
    //Lambda表达式中[]中写的是&a,   代表将上面的函数中的局部变量a以引用传递的方式传入到Lambda表达式
    //mutable修饰 作用：可以在Lambda中修改传入变量的值 ，如果有返回值int类型：  -> int
    connect(button,&QPushButton::clicked,this,[&]()mutable -> int{    //以值传递的方式传a //上面所有参数都是以引用方式传递进来
//        a = 100;//a不能改变值,如果要改变a的值，加一个mutable。但上面的a仍然没有改变（因为是值传递方式传的参数）
        qDebug() << a;
        qDebug() << b;
        qDebug() << "点我";
    }); //[]表示匿名函数 （）表示没有参数{}是函数的函数体
}

Widget::~Widget()
{
}

