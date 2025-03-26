//一、Qt简介
/*
    1.1 什么是QT
        Qt 是一个 跨平台 的 C++图形用户界面应用程序框架。它为应用程序开发者提供建立艺术级图形界面所需的所有功能。
        它是完全面向对象的，很容易扩展，并且允许真正的组件编程。

    1.2 Qt 的发展史
        1991年Qt最早由奇趣科技开发
        1996年 进入商业领域，它也是目前流行的Linux桌面环境KDE的基础
        2008年 奇趣科技被诺基亚公司收购，Qt称为诺基亚旗下的编程语言
        2012年 Qt 又被 Digia 公司收购
        2014年4月跨平台的集成开发环境QtCreator3.1.0发布，同年5月20日配发了Qt5.3正式版，

        至此 Qt 实现了对 i0S、Android、WP 等各平台的全面支持。
        当前Ql最新版本为 5.13.2(2019.12之前)
    1.3支持的平台
        Windows  - XP、Vista、Win7、Win8、Win2008、 Winl0
        Uinux/X11-Linux,Sun Solaris、HP-Ux, Compaq Tru64UNIX, IBMAIX、 SGI IRIX, FreeBSD、BSD/OS、和其他很多X11平台
        Macintosh- Mac OS X
        Embedded - 有帧缓冲支持的嵌入式Linux平台，Windows CE
    1.4 Qt 版本
        Qt按照不同的版本发行，分为商业版和开源版
        商业版
            为商业软件提供开发，他们提供传统商业软件发行版，并且提供在商业有效期内的免费升级和技术支持服务。
        开源的 LGPL 版本:
            为了开发自有而设计的开放源码软件，它提供了和商业版本同样的功能，在 GN 通用公共许可下，它是免费的。

    1.5 QT的下载与安装
        1.5.1 下载地址
            http://www.qt.io/download-open-source/
            或者
            http://download.qt.io/archive/qt/
        1.5.2 安装
            按照默认安装即可
            Qt 对不同的平台提供了不同版本的安装包，可根据实际情况自行下载安装，本文档使用
            qt-opensource-windows-x86-mingw530-5.8.0 版本进行讲解(32 位和 64 位均可安装)
    1.6 Qt 的优点
        * 跨平台，几乎支持所有的平台
        * 接口简单，容易上手，学习 QT 框架对学习其他框架有参考意义。
        * 一定程度上简化了内存回收机制
        * 开发效率高，能够快速的构建应用程序。
        * 有很好的社区氛围，市场份额在缓慢上升。
        * 可以进行嵌入式开发。
    1.7成功案例
        Linux 桌面环境 KDE
        Skype 网络电话
        Google Earth 谷歌地图
        VLC 多媒体播放器
        VirtualBox 虚拟机软件
        咪咕音乐
        WPS Office
        极品飞车

*/
//二、创建Qt项目
/*
    2.1 使用向导创建
        打开 Qt Creator 界面选择 New Project 或者选择菜单栏 【文件】-【新建文件或项目】 菜单项

    注意：
        * 在讲c++时，采用QT写c++代码的应用程序时，选择的是Non-QT-Project(非QT的项目)
            但现在是用QT做界面，所以选择带界面的应用程序，故选APPlication -> Qt Widgets Application (带QT控件的一个应用程序)

        * 在Details 里面的 Base class 是基类的选择，
            基类的选择决定了创建项目时窗口长什么样子，
                QMainWindow 就是普通的带工具栏的界面
                ADialog     就是带对话框的窗口，
                Qwidget     就是什么都不带的界面，单就一个窗口。   一般选这种，

            generate form 是生成窗口（一个画图的工具，可以在上面画图，画完图他就可以把控件显示在上面）。

        * 生成的项目里面： pro是创建项目的时候自动生成的，我们之后会根据该文件去生成makefile，去编译一个东西，
        *               pro是工程项目文件，QT有一个工具 叫：qmake。qmake讲这个东西生成一个makefile(用于编译的脚本).qmake就是解析这个pro里面的东西。


    2.1 QT 写代码的框架
        系统会默认给我们添加main.cpp、mywidget.cpp、mywidget.h和一个.pro项目文件，点击完成即可创建出一个QT桌面程序。

    main.cpp:
            #include "widget.h"

            #include <QApplication>     //QT的框架，是必须添加的

            int main(int argc, char *argv[])    //QT的框架初始化。
            {
                QApplication a(argc, argv);
//                Widget w;     //定义了一个窗口
//                w.show();     //窗口的show，进行显示

                //就是我们定义了一个QT的一个对象。
                return a.exec();    //a.exe 作用是让程序不死，类似于while(1).循环检测事件的产生。
            }
    注意:
        .exe可执行程序在 buile 的 debug包里面。
        根据pro文件 经过qmake工具解析 生成的makefile 是用来编译的。

    2.2 手动创建
        添加一个空项目

        #include <QDebug>
        qDebug() << "hello"; //在程序里面输出不再使用cout ,而是创建一个匿名对象:qDebug(),才能应用程序输出。

    例：
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
    注意：
        QT中的命名规则：
            对于类的命名：首个字母大写，且首个单词的首字母大写   （大驼峰法）
            对于函数命名：首个字母小写，但首个单词的首字母大写   （小驼峰法）

    2.4最简单的QT应用程序解释；
        解释：
            * QT系统提供的标准类名声明头文件没有.h后缀
            * Qt一个类对应一个头文件，类名就是头文件名
            * QApplication 应用程序类
                * 管理图形用户界面应用程序的控制流和主要设置
                * 是Qt的整个后台管理的命脉 它包含 主事件循环，在其中来自窗口系统 和 其它资源的所有事件处理 和调度。它也处理应用程序的初始化和结束，并且提供 对话管理。
            * 对于任何一个使用Qt的图形用户界面应用程序，都正好存在一个QApplication 对象，而不论这个应用程序在同一时间内是不是有0、1、2或更多个窗口。
            * a.exec()
                程序进入消息循环 ，等待对用户输入进行响应。这里main()把控权转交给Qt，Qt 完成事件处理工作，当应用程序退出的时候exec()的值就会返回。
                 在exec()中，Qt接受并处理用户和系统的事件并且把他们传递给适当的窗口部件。
*/
//三、设置窗口属性
/*
    3.1 代码书写位置
        通过之前内容见讲解，新创建的qt项目工程的文件结构如01unititlied所示

        那么如果要设置窗口的属性或者添加一些控件，代码应该在哪个文件书写呢?
        .pro 文件用于生成可执行文件，.h存放头文件、类等，widget.cpp 中主要存放.h文件中函数的实现过程，main.cpp
        主要是主程序.

    main。cpp文件中有一句代码：
        widget w;
    Widget 类实例化的对象 w，此时会调用构造函数，对如果对当前 Widget 类中的构造函数中写入设置的属性或者添加一些控件，当实例化对象是就会调用构造函数，从而实现想要达到的目的，并且这样做也不会使得主函数中有多余的代码
    所以一般窗口的属性和添加控件以及对控件的操作都会在类的构造函数中书写。

    3.2 Qt助手
        通常在安装Qt时都会自带一个Qt助手，方便去査询Qt中的要使用的类和函数等。
        一般会在开始菜单的Qt目录中，一般叫做 Assistant。

        Qt自带帮助文档。
            Header: 需要添加的头文件
            qmake : .pro 里面需要添加的东西
            Inherits:
            Inherits By：继承了那些类

    3.3 设置窗口属性
        把窗口属性需要的设置，写在构造函数里面。
    例：
        Widget::Widget(QWidget *parent)
            : QWidget(parent)
        {
            //widget的构造函数，代码可以写在这里，设置窗口属性
            //this指向这个窗口。

            //设置窗口标题
            this->setWindowTitle("hello qt");

            //设置宽高大小，设置完后窗口还可以拉伸
            this->resize(600,400);

            //设置固定大小，设置完完毕后窗口大小不能再改变。
            this->setFixedSize(800,400);

        }
*/
//四、按钮的创建和属性设置
/*
    4.按钮的创建和属性设置
        类名： QPushButton
       头文件：#include <QPushButton>

        4.1 按钮的创建
          在Qt程序中，最常用的控件之一就是按钮，首先我们来看下如何创建一个按钮。
        例：
        .h:
            class Widget : public QWidget
            {
                Q_OBJECT

            public:
                Widget(QWidget *parent = nullptr);
                ~Widget();

                QPushButton *button;    //在类里面定义一个PushButton的指针。
            };

        .cpp:
            Widget::Widget(QWidget *parent)
                : QWidget(parent)
            {

            //1.如果这样来定义使用的话，由于生命周期只有这个构造函数，故，出了构造函数之后，就会销毁，只会闪一下。
            //2.因此，需要在.h里面定义一个PushButton的指针。
            //    QPushButton button;
            //    button.show();

            //3.用指针接收new出来的QPushButton，再调用函数，new的button出了函数不会销毁。
            //4.但显示时，button是单独创建一个窗口，并没有把按钮放到第一个窗口里面。
            //    button = new QPushButton;
            //7.也可以在new时，直接传this指针
            //    button = new QPushButton(this);
            //8.可以在7的基础上设置文本
                button = new QPushButton("登入",this);
                //如果不给按钮指定父对象，那么按钮和窗口是单独显示，如果给按钮制定了父对象，只要父对象显示了，按钮也会显示。
                button->show(); //

            //5.要使按钮放到窗口里面，需要指定按钮的父类是窗口
            //    button->setParent(this); //设置button的父类是this这个窗口。
            //6.设置按钮的大小 以及 按钮里面的显示文本：
                button->resize(300,200);
                button->move(100,100);
                button->setText("登录");
            }

        4.2 对象模型（对象树）
            在Qt中创建对象的时候会提供一个Parent对象指针，下面来解释这个parent 到底是干什么的。
            * QObject是 以对象树的形式 组织起来的。
                * 当你创建一个QObject对象时,会看到QObject的构造函数接收一个QObject指针作为参数，
                   这个参数就是parent，也就是父对象指针。
                   这相当于，在创建QObject 对象时，可以提供一个其父对象，我们创建的这个 QObject 对象
                   会自动添加到其父对象的 children()列表。

            * 当父对象析构的时候，这个列表中的所有对象也会被析构。(注意，这里的父对象并不是继承意义上的父类!)
            * QWidget是能够在屏幕上显示的一切组件的父类。
                * QWidget 继承自 QObject，因此也继承了这种对象树关系。一个孩子自动地成为父组件的一个子组件。
                  因此，它会显示在父组件的坐标系统中，被父组件的边界剪裁。例如，当用户关闭一个对话框的时候，应用程序将其删除，
                  那么，我们希望属于这个对话框的按钮、图标等应该一起被删除。事实就是如此，因为这些都是对话框的子组件。
                * 当然，我们也可以自己删除子对象，它们会自动从其父对象列表中删除。
                  比如，当我们删除了一个工具栏时，其所在的主窗口会自动将该工具栏从其子对象列表中删除，并且自动调整屏幕显示。

            Qt引入对象树的概念，在一定程度上解决了内存问题。
                * 当一个QObject 对象在堆上创建的时候，Qt会同时为其创建一个对象树。不过，对象树中对象的顺序是没有定义的。这意味着，销毁这些对象的顺序也是未定义的。
                * 任何对象树中的QObject对象delete 的时候,如果这个对象有parent,则自动将其从parent 的 children()列表中删除;如果有孩子，则自动delete 每一个孩子。
                  Qt保证没有 QObject 会被 delete 两次，这是由析构顺序决定的。

            如果 QObject 在栈上创建，Qt 保持同样的行为。正常情况下，这也不会发生什么问题。
            例如下面代码片段:
            {
                QWidget window;
                QPushButton quit = QPushButton("退出",&window);
            }
            作为 父组件的window 和 作为子组件的quit 都是 QObject的子类(事实上，它们都是 QWidget 的
            子类，而 QWidget 是 QObject 的子类)。这段代码是正确的，quit 的析构函数不会被调用两次，
            因为标准C++要求，局部对象的析构顺序应该按照其创建顺序的相反过程。因此，这段代码在超出作
            用域时，会先调用quit的析构函数，将其从父对象window的子对象列表中删除，然后才会再调用 window 的析构函数。


            但是，如果使用以下代码
            {
                QPushButton quit("Quit");
                Qwidget window;
                quit.setParent(&window);
            }
            情况又有所不同，析构顺序就有问题了，我们看到，在上面的代码中，作为父对象的window会首先被析构，因为它是最后一个创建的对象，
            在析构过程中，他会调用子对象列表中每一个对象的析构函数，也就是说， quit 此时就被析构了。
            然后，代码继续执行，在 window析构之后，quit 也会被析构，因为 quit也是一个局部变量，在超出作用域的时候当然也需要析构。
            但是，这时候已经是第二次调用 quit 的析构函数了，C++不允许调用两次析构函数，因此，程序崩溃了。
            由此我们看到，Qt的对象树机制 虽然帮助我们在一定程度上解决了内存问题，但是也引入了一些值
            得注意的事情。这些细节在今后的开发过程中很可能时不时跳出来烦扰一下，所以，我们最好从开始就养成良好习惯。

            在 Qt中,尽量在构造的时候就指定parent对象,并且大胆在堆上创建.

        4.3 Qt窗口坐标系

        坐标系:
        以左上角为原点(0,0),x向右增加,Y向下增加

        对于嵌套窗口,其坐标是相对于父窗口来说的。
*/
//五、信号 与 槽 机制
/*
    5.信号 与 槽 机制
        信号槽是 Qt 框架引以为豪的机制之一。所谓信号槽，实际就是观察者模式。
        当某个事件发生之后，比如，按钮检测到自己被点击了一下，它就会发出一个信号(signal),这种发出是没有目的的,
        类似广播。如果有对象对这个信号感兴趣，它就会使用连接(connect)函数，意思是，将想要处理的信号和自己的一个函数(称为槽(slot))绑定 来处理这个信号。
        也就是说，当信号发出时，被连接的槽函数会自动被回调。这就类似观察者模式:当发生了感兴趣的事件，某一个操作就会被自动触发。

        即：鼠标点击了按钮，按钮就会产生一个漫无目的的信号（signal）,现在有一个窗口Window想要接收这个信号，就需要使用connect函数去设置window窗口接收到这个信号，返回回调slot函数（槽函数）。（connect的作用就是：设置当window接收到了signal信号，就会回调window里面的 回调函数--槽函数）
        发送者         信号          接收者         槽函数
        开关     =>   被按下    =>    灯    =>      灯亮了

        5.1 系统自带的信号和槽
            下面我们完成一个小功能，上面我们已经学习了按钮的创建，但是还没有体现出按钮的功能，按钮最大的功能也就是点击后触发一些事情,
            比如我们点击按钮,就把当前的窗口给关闭掉,那么在 Qt中,这样的功能如何实现呢?
                其实无非两行代码就可以搞定了，我们看下面的代码：
                QPushButton *quitBtn = new QPushButton("关闭窗口"，this);
                connect(quitBtn,&QPushButton::clicked,this,&MyWidget::close);

                第一行是创建一个关闭按钮，这个之前就已经学过了，第二行就是核心，也就是信号槽的使用方式
                connect()函数最常用的一般形式：

                connect（sender,signal,receiver,slot）;
                参数解释：
                * sender : 发出信号的对象
                * signal : 发送对象发出的信号
                * receiver : 接收信号的对象
                * slot   : 接收对象在接收到信号之后所需要调用的函数（槽函数）

            例:
                #include "widget.h"
                #include <QPushButton>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    //创建一个按钮 点击按钮关闭窗口
                //    this->close();    //这个函数直接关闭窗口。但我们需要让其在按钮按下后再调用该函数。

                    //堆区new一个按钮，命名为:关闭窗口，父类为Widget
                    QPushButton *p = new QPushButton("关闭窗口",this);
                    //设置点击按钮 会调用窗口的close函数
                    //设置连接 点击按钮产生信号  会调用窗口的close函数
                //    * sender :   按钮发出
                //    * signal :   信号是 QPushButton里面的点击信号
                //    * receiver : 窗口接收
                //    * slot   :   调用的 一定是接收信号的对象里面的槽函数
                    connect(p,&QPushButton::clicked,this,&QWidget::close);

                }

            5.2 按钮常用的信号
                那么系统自带的信号和槽通常如何查找呢，这个就需要利用帮助文档了，在帮助文档中比如我们上面的按钮的点击信号，
                在帮助文档中输入 QPushButton，首先我们可以在 Contents 中寻找关键字 signals，信号的意思，但是我们发现并没有找到，
                这时候我们应该想到也许这个信号的被父类继承下来的，因此我们去他的父类 QAbstractButton中就可以找到该关键字，
                点击signals 索引到系统自带的信号有如下几个：
                void clicked(bool checked=false)
                void pressed()
                void released()
                void toggled(bool checked
                    * signals inherited,fron Qfidget
                    * signals inherited fron Qobject
                这里的 clicked 就是我们要找的，槽函数的寻找方式 和 信号一样，只不过他的关键字是 slot。

            5.3 自定义信号和槽
                使用connect()可以让我们连接系统提供的信号和槽。但是，Qt的信号槽机制并不仅仅是使用系统提供的那部分，还会允许我们自己设计自己的信号和槽。
                下面我们看看使用 Qt 的信号槽

                5.3.1 自定义的 槽函数
                注意：
                    定义一个public的槽函数，注意：该函数需不需要参数，需要去看&QPushButton::pressed有没有参数。
                    如果 信号没有参数，则槽函数也不需要参数。 如果信号有参数，槽函数可以有也可以没有参数。

                    Fn + F1：跳转到对应的帮助文档。
                    Fn + F4：从.h 跳转到 .c 文件

                widget.cpp：
                    #include "widget.h"
                    #include <QDebug>
                    Widget::Widget(QWidget *parent)
                        : QWidget(parent)
                    {
                        //创建一个按钮
                        button = new QPushButton;
                        button->setParent(this);
                        button->setText("打印志杰牛逼");
                        //注册信号与槽的连接
                        //槽函数可以是普通的成员函数，还可以是自定义槽函数
                        connect(button,&QPushButton::pressed,this,&Widget::print);

                    }

                    Widget::~Widget()
                    {
                    }

                    void Widget::print()
                    {
                        qDebug() << "志杰牛逼";
                    }

                widget.h：
                    #ifndef WIDGET_H
                    #define WIDGET_H

                    #include <QWidget>
                    #include <QPushButton>

                    class Widget : public QWidget
                    {
                        Q_OBJECT

                    public:
                        Widget(QWidget *parent = nullptr);
                        ~Widget();
                        QPushButton *button;    //Fn + F1：跳转到对应的帮助文档。
                                                //Fn + F4：从.h 跳转到 .c 文件
                    public slots:

                        void print();   //定义一个public的槽函数，注意：该函数需不需要参数，需要去看&QPushButton::pressed有没有参数。
                        //如果 信号没有参数，则槽函数也不需要参数。 如果信号有参数，槽函数可以有也可以没有参数。
                    };
                    #endif // WIDGET_H

                5.3.2 自定义的 信号
                    原理见课程图解。

                例：
                sonwidget.h:
                    #ifndef SONWIDGET_H
                    #define SONWIDGET_H

                    #include <QWidget>
                    #include <QPushButton>

                    class SonWidget : public QWidget
                    {
                        Q_OBJECT
                    public:
                        explicit SonWidget(QWidget *parent = nullptr);
                        QPushButton *sbutton;   //子窗口的按钮（作用：按下后隐藏子窗口，显示父窗口，注意，子类显示父类窗口只能用信号与槽机制）
                    signals:
                        //在信号这里定义一个信号
                        //信号可以有参数，也可以没有参数，信号没有返回值。信号不需要定义，只需要声明！！
                        void show_hide_signal(int a);
                    public slots:
                        //定义槽函数
                        void emit_mysignal();
                    };

                    #endif // SONWIDGET_H

                widget.h:
                    #ifndef WIDGET_H
                    #define WIDGET_H

                    #include <QWidget>
                    #include "sonwidget.h"
                    #include <QPushButton>

                    class Widget : public QWidget   //父窗口Widget
                    {
                        Q_OBJECT

                    public:
                        Widget(QWidget *parent = nullptr);
                        ~Widget();
                        SonWidget *sonwindow;   //父类定义子类窗口指针，用于构造函数new一个窗口。
                        QPushButton *fbutton;   //父窗口的按钮（作用：按了之后隐藏父窗口，显示子窗口，这里显示子窗口可以通过QObject显示子类窗口）

                    public slots:
                        //定义槽函数：点击按钮产生信号
                        void button_cb();
                        //再定义一个槽函数，用于接收到子窗口信号后的作用
                        void signal_cb(int a);
                    };
                    #endif // WIDGET_H

                sonwidget.cpp:
                    #include "sonwidget.h"

                    SonWidget::SonWidget(QWidget *parent):QWidget{parent}
                    {
                        //子窗口的按键命名
                        sbutton = new QPushButton("隐藏子窗口，显示父窗口",this);

                        //在子窗口的构造函数设置窗口参数
                        this->setWindowTitle("子窗口");

                        //子窗口连接:当点击了子类窗口的按钮，就发送一个信号，然后让父窗口接收这个信号
                        connect(sbutton,&QPushButton::clicked,this,&SonWidget::emit_mysignal);
                    }

                    void SonWidget::emit_mysignal()
                    {
                        //点击按钮 槽函数发送信号
                        emit show_hide_signal(10);
                    }

                widget.cpp:
                    #include "widget.h"
                    #include "QDebug"

                    Widget::Widget(QWidget *parent)
                        : QWidget(parent)
                    {
                        //设置父窗口的窗口参数
                        this->setWindowTitle("父窗口");

                        //创建子类窗口
                        this->sonwindow = new SonWidget;
                        sonwindow->show();

                        //父窗口按钮的功能实现
                        fbutton = new QPushButton;
                        fbutton->setText("隐藏父窗口，显示子窗口");
                        fbutton->setParent(this);


                        //设置父窗口信号与本窗口的按键槽的连接
                        connect(fbutton,&QPushButton::clicked,this,&Widget::button_cb);
                        //设置父窗口与子窗口发送的信号 的连接
                        connect(sonwindow,&SonWidget::show_hide_signal,this,&Widget::signal_cb);
                        //这里不是emit_mysignal，而是show_hide_signal,子窗口发送信号的函数是show_hide_signal。
                    }

                    Widget::~Widget()
                    {
                    }

                    void Widget::button_cb()
                    {
                        //将父窗口隐藏
                        this->hide();
                        //显示子窗口(找到子窗口，再调用子窗口的show显示)
                        this->sonwindow->show();
                    }

                    void Widget::signal_cb(int a)
                    {
                        //打印接收到的信号a
                        qDebug() << a;
                        //显示父窗口,隐藏子窗口
                        this->show();
                        this->sonwindow->hide();
                    }

                5.3.3 自定义信号槽需要注意的事项
                    * 发送者 和 接收者都需要是QObject的子类(当然，槽函数是全局函数、Lambda 表达式等无需接收者的时候除外);
                    * 信号和槽函数返回值是 void
                    * 信号只需要声明，不需要实现
                    * 槽函数需要声明也需要实现
                    * 槽函数是普通的成员函数，作为成员函数，会受到public、private、protected 的影响;
                    * 使用emit 在恰当的位置发送信号;
                    * 使用connect()函数连接信号和槽。
                    * 任何成员函数、static 函数、全局函数和Lambda 表达式都可以作为槽函数
                    * 信号槽要求信号和槽的参数一致，所谓一致，是参数类型一致。
                    * 如果信号和槽的参数不一致，允许的情况是，槽函数的参数可以比信号的少，即便如此，槽函数存在的那些参数的顺序也必须和信号的前面几个一致起来。这是因为，你可以在槽函数中选择忽略信号传来的数据（也就是槽函数的参数比信号的少）

            5.4 信号槽的拓展
                * 一个信号可以和多个槽相连
                    如果是这种情况，这些槽会一个接一个的被调用，但是 他们的调用顺序是不确定的。
                * 多个信号可以连接到一个槽
                    只要任意一个信号发出，这个槽就会被调用。
                * 一个信号可以连接到另外的一个信号
                    当第一个信号发出时，第二个信号被发出。初始之外，这种信号-信号的形式和信号-槽的形式没有什么区别。
                * 槽可以被取消链接
                    这种情况并不经常出现，因为当一个对象delete之后，Qt自动取消所有连接到这个对象上面的槽
                * 信号槽可以断开
                    利用disconnect 关键字可以断开信号槽的连接
                * 使用Lambda表达式
                    在使用 Qt 5 的时候，能够支持Qt 5 的编译器都是支持Lambda表达式的。
                    在连接信号和槽的时候，槽函数可以使用Lambda表达式的方式进行处理，后面我们会详细介绍什么是Lambda表达式。

            5.5 Qt4版本的信号槽写法
                connect(zt,SIGNAL(hungry(QString)),st,SLOT(treat(QString)))

                这里使用了 SIGNAL和 SLOT 这两个宏，将两个函数名转换成了字符串。注意到connect()函数的signal和slot 都是接受字符串，一旦出现连接不成功的情况，
                Qt4是没有编译错误的(因为一切都是字符串，编译期是不检查字符串是否匹配)，而是在运行时给出错误。这无疑会增加程序的不稳定性。

                Qt5 在语法上完全兼容 Qt4，而反之是不可以的。

                Qt5写法：
                QObject::connect(&button,&QPushButton::clicked,&app,&QApplication::quit);
                编译期间检查类型是否匹配。Qt5 中，任何成员函数、static 函数、全局函数和 Lambda 表达式都可以作为槽函数。

                Qt4写法：
                QObject::connect(&button,SIGNAL(clicked()),&app, SLOT(quit()));
                Qt4是没有编译错误的(因为一切都是字符串，编译期是不检查字符串是否匹配)，即：SIGNAL和 SLOT不会检查里面的字符串是否正确，而是在运行时给出错误。

            5.6 Lambda 表达式
                c++ 11中的Lambda表达式 用于定义并创建匿名的函数对象，以简化编程工作。首先看一下Lambda表达式的基本构成：
                [capture](parameters)mutable -> return-type
                {
                    statement
                }
                [函数对象参数]（操作符重载函数参数）multable -> 返回值[函数体]
                1. 函数对象参数：
                    []，标识一个Lambda的开始，这部分必须存在，不能省略。函数对象参数是传递给编译器自动生成的函数对象类的构造函数的。
                    函数对象参数只能使用那些到定义1ambda为止时Lambda所在作用范围内可见的局部变量(包括Lambda所在类的this)。函数对象参数有以下形式:
                        * 空。没有使用任何函数对象参数。
                        * = 。函数体内可以使用Lambda所在作用范围内所有可见的局部变量(包括Lambda所在类的this,并且是值传递方式(相当于编译器自动为我们按值传递了所有局部变量)。
                        * & 。函数体内可以使用Lambda所在作用范围内所有可见的局部变量(包括Lambda 所在类的this)，并且是引用传递方式(相当于编译器自动为我们按引用传递了所有局部变量)。
                        * this。函数体内可以使用Lambda所在类中的成员变量。
                        * a。将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。要修改传递进来的a的拷贝，可以添加mutable修饰符。
                        * &a。将a按引用进行传递。
                        * a,&b。将a按值进行传递，b按引用进行传递。
                        * =,&a，&b。除a和b按引用进行传递外，其他参数都按值进行传递。
                        * &,a,b。除a和b按值进行传递外，其他参数都按引用进行传递

                2.操作符重载函数参数;
                    标识重载的()操作符的参数，没有参数时，这部分可以省略。参数可以通过按值(如:(a.b))和 按引用(如:(&a.&b))两种方式进行传递。
                3.可修改标示符：
                    mutable声明，这部分可以省略。按值传递函数对象参数时，加上mutable修饰符后，可以修改按值传递进来的拷贝(注意是能修改拷贝，而不是值本身)。
                4.函数返回值
                    ->返回值类型，标识函数返回值的类型，当返回值为void,或者函数体中只有一处return 的地方（此时编译器可以自动推断出返回值类型）时，这部分可以省略。
                5.是函数体：
                    {}，标识函数的实现，这部分不能省略，但函数体可以为空。
*/
// QMainWindow
/*
    五、QMainWindow（之前学的是QWidget是什么都不带的一个窗口界面）
        QMainWindow是一个为用户提供主窗口程序的类，包含一个菜单栏(menu bar)、多个工具栏(tool bars)、多个铆接部件(dock widgets)、一个状态栏(status bar)及一个中心部件(central widget)
        是许多应用程序的基础，如文本编辑器，图片编辑器等。
    5.1 菜单栏

    5.2 工具栏
        主窗口的工具栏上可以有多个工具条，通常采用一个菜单对应一个工具条的方式，也可以根据需要进行工具条的划分。
        创建工具栏：
            #include <QToolBar>
            QToolBar->QToolBar(QWidget *parent = Q_NULLPTR)
        添加工具栏
            QMainWindow -->
                void addToolBar(QToolBar *toolbar)
                void addToolBar(Qt::ToolBarArea area,QToolBar *toolbar)
                    Qt::LeftToolBarArea 左边显示
                    Qt::RightToolBarArea 右边显示
        例：
                #include "mainwindow.h"
                #include <QMenuBar>
                #include <QMenu>
                #include <QAction>
                #include <QToolBar>

                MainWindow::MainWindow(QWidget *parent)
                    : QMainWindow(parent)
                {
                    //这种带菜单栏和工具栏的界面是不会直接显示的，如果想要显示菜单栏和工具栏,就需要把他们取出来。
                    //取出菜单栏：
                    QMenuBar *menubar1 = this->menuBar();
                    //向菜单栏添加 菜单
                    QMenu *filemenu = menubar1 ->addMenu("文件");
                    QMenu *fileedit = menubar1 ->addMenu("编辑");
                    //向菜单栏添加菜单项
                    QAction *openaction = filemenu->addAction("打开");//菜单栏的返回是QAction*类型，

                    filemenu ->addSeparator(); //添加分割线
                    QAction *saveaction = filemenu->addAction("保存");

                    //获取工具栏
                    QToolBar *toolbar = this->addToolBar("");
                    //向工具栏中添加工具（添加菜单项）
                    toolbar->addAction(openaction);
                    toolbar->addAction(saveaction);


                }

                MainWindow::~MainWindow()
                {
                }

        5.3 状态栏
                例：
                        #include "mainwindow.h"
                        #include <QMenuBar>
                        #include <QMenu>
                        #include <QAction>
                        #include <QToolBar>
                        #include <QStatusBar>
                        #include <QLabel>

                        MainWindow::MainWindow(QWidget *parent)
                            : QMainWindow(parent)
                        {
                            this -> resize(600,400);
                            //这种带菜单栏和工具栏的界面是不会直接显示的，如果想要显示菜单栏和工具栏,就需要把他们取出来。
                            //取出菜单栏：
                            QMenuBar *menubar1 = this->menuBar();
                            //向菜单栏添加 菜单
                            QMenu *filemenu = menubar1 ->addMenu("文件");
                            QMenu *fileedit = menubar1 ->addMenu("编辑");
                            //向菜单栏添加菜单项
                            QAction *openaction = filemenu->addAction("打开");//菜单栏的返回是QAction*类型，

                            filemenu ->addSeparator(); //添加分割线
                            QAction *saveaction = filemenu->addAction("保存");

                            //获取工具栏
                            QToolBar *toolbar = this->addToolBar("");
                            //向工具栏中添加工具（添加菜单项）
                            toolbar->addAction(openaction);
                            toolbar->addAction(saveaction);

                            //取出状态栏
                            QStatusBar *status = this ->statusBar();
                            status->addWidget(new QLabel("状态"));//添加一个新的标签,向状态栏添加控件
                        }

                        MainWindow::~MainWindow()
                        {
                        }

        5.4 铆接控件
            相当于我们的悬浮窗口（一些工具栏或窗口修改位置），添加一个浮动窗口

            QDockWidget，也称浮动窗口，可以有多个。
            创建铆接部件:
                QDockWidget -->
                    QDockWidget (const QString &title, QWidget *parent = Q_NULLPTR)
            添加铆接部件:
                QMainWindow-->
                    void addDockWidget(Qt::DockWidgetArea area，QDockWidget *dockwidget)
                        Qt::LeftDockWidgetArea 左边
                        Qt::RightDockWidgetArea右边
                        Qt::TopDockWidgetArea  上边
                        Qt::BottomDockWidgetArea下边

        5.5 核心部件（中心部件）
            除了以上几个部件，中心显示的部件都可以作为核心部件，例如一个记事本文件，可以利用 QTextEdit 做核心部件

            添加中心部件:
                QMainWindow -->void setCentralWidget(QWidget *widget)

            QTextEdit *edit = new QTextEdit("文本编辑器"，this);
            this->setCentralwidget(edit);

            例：
                    #include "mainwindow.h"
                    #include <QMenuBar>
                    #include <QMenu>
                    #include <QAction>
                    #include <QToolBar>
                    #include <QStatusBar>
                    #include <QLabel>
                    #include <QDockWidget>
                    #include <QTextEdit>

                    MainWindow::MainWindow(QWidget *parent)
                        : QMainWindow(parent)
                    {
                        this -> resize(600,400);
                        //这种带菜单栏和工具栏的界面是不会直接显示的，如果想要显示菜单栏和工具栏,就需要把他们取出来。
                        //取出菜单栏：
                        QMenuBar *menubar1 = this->menuBar();
                        //向菜单栏添加 菜单
                        QMenu *filemenu = menubar1 ->addMenu("文件");
                        QMenu *fileedit = menubar1 ->addMenu("编辑");
                        //向菜单栏添加菜单项
                        QAction *openaction = filemenu->addAction("打开");//菜单栏的返回是QAction*类型，

                        filemenu ->addSeparator(); //添加分割线
                        QAction *saveaction = filemenu->addAction("保存");

                        //获取工具栏
                        QToolBar *toolbar = this->addToolBar("");
                        //向工具栏中添加工具（添加菜单项）
                        toolbar->addAction(openaction);
                        toolbar->addAction(saveaction);

                        //取出状态栏
                        QStatusBar *status = this ->statusBar();
                        status->addWidget(new QLabel("状态"));//添加一个新的标签,向状态栏添加控件

                        //创建铆接部件
                    //    QDockWidget * dockwidget = new QDockWidget("这是一个铆接部件",this);
                    //    this->addDockWidget(Qt::TopDockWidgetArea,dockwidget);  //将浮动窗口添加到mainwindow

                        //创建中心控件
                        QTextEdit *edit = new QTextEdit("文本编辑器",this);  //新建了一个文本编辑器，并取标题名，指定父对象
                        this->setCentralWidget(edit);   //将文本编辑器设置为中心控件。

                    }

                    MainWindow::~MainWindow()
                    {
                    }

            5.6 资源文件
                Qt 资源系统 是一个跨平台的资源机制,用于将程序运行时所需要的资源 以二进制的形式存储于可执行文件内部。
                如果你的程序需要加载特定的资源(图标、文本翻译等)，那么，将其放置在资源文件中，就再也不需要担心这些文件的丢失。
                也就是说，如果你将 资源 以 资源文件形式存储，它是会编译到可执行文件内部。
                使用 QtCreator 可以很方便地创建资源文件。我们可以在工程上点右键，选择“添加新文件…”可以在 Qt 分类下找到“Qt 资源文件”:

            添加过程：添加新文件 - 》 Qt -》Qt Resource file -> 添加前缀 -》 添加文件
            注意：资源文件只能添加项目文件里面的文件
            如果要使用：选择文件 右键 复制资源路径到剪贴板。

            详细步骤见文档。
            例：

                    #include "mainwindow.h"
                    #include <QMenuBar>
                    #include <QMenu>
                    #include <QAction>
                    #include <QToolBar>
                    #include <QStatusBar>
                    #include <QLabel>
                    #include <QDockWidget>
                    #include <QTextEdit>
                    #include <QPixmap>
                    MainWindow::MainWindow(QWidget *parent)
                        : QMainWindow(parent)
                    {
                        this -> resize(600,400);
                        //这种带菜单栏和工具栏的界面是不会直接显示的，如果想要显示菜单栏和工具栏,就需要把他们取出来。
                        //取出菜单栏：
                        QMenuBar *menubar1 = this->menuBar();
                        //向菜单栏添加 菜单
                        QMenu *filemenu = menubar1 ->addMenu("文件");
                        QMenu *fileedit = menubar1 ->addMenu("编辑");
                        //向菜单栏添加菜单项
                        QAction *openaction = filemenu->addAction("打开");//菜单栏的返回是QAction*类型，

                        filemenu ->addSeparator(); //添加分割线
                        QAction *saveaction = filemenu->addAction("保存");

                        //获取工具栏
                        QToolBar *toolbar = this->addToolBar("");
                        //向工具栏中添加工具（添加菜单项）
                        toolbar->addAction(openaction);
                        toolbar->addAction(saveaction);

                        //取出状态栏
                        QStatusBar *status = this ->statusBar();
                        status->addWidget(new QLabel("状态"));//添加一个新的标签,向状态栏添加控件

                        //创建铆接部件
                    //    QDockWidget * dockwidget = new QDockWidget("这是一个铆接部件",this);
                    //    this->addDockWidget(Qt::TopDockWidgetArea,dockwidget);  //将浮动窗口添加到mainwindow

                        //创建中心控件
                        QTextEdit *edit = new QTextEdit("文本编辑器",this);  //新建了一个文本编辑器，并取标题名，指定父对象
                        this->setCentralWidget(edit);   //将文本编辑器设置为中心控件。

                        //:/new/prefix1/a.bmp
                        //在指定的菜单项上设置图片
                        //创建图片控件
                        QPixmap pix;    //定义一个图片对象
                        //选择图片
                        pix.load(":/new/prefix1/a.bmp");    //给图片对象 加载图片
                        //给菜单项设置图片
                        openaction->setIcon(QIcon(pix));  //用pix图片创建QIcon资源，将菜单项（的打开）设置一个资源 ；setIcon(设置图标)

                    }

                    MainWindow::~MainWindow()
                    {
                    }


*/
//六、对话框QDialog
/*
    6.1 基本概念
        对话框是GUI程序中不可或缺的组成部分。很多不能 或者
   不适合放入主窗口的功能组件都必须放在对话框中设置。
        对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的
   用户交互。

        Qt中 使用 QDialog类 实现对话框。就像主窗口一样，我们通常会设计一个类继承
   QDialog。 QDialog(及其子类，以及所有 Qt::Dialog类型的类)的对于其 parent
   指针都有额外的解释: 如果 parent 为 NULL，则该对话框会作为一个顶层窗口，否则
   则作为其父组件的子对话框(此时，其默认出现的位置是parent的中心）
        顶层窗口与非顶层窗口的区别在于，顶层窗口在任务栏会有自己的位置，而非顶层窗口则会共享其父组件的位置。

        对话框分为模态对话框和非模态对话框。
            * 模态对话框，就是会阻塞同一应用程序中其它窗口的输入。
              模态对话框很常见，比如“打开文件”功能。你可以尝试一下记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的。
            * 与此相反的是非模态对话框，例如查找对话框，我们可以在显示着查找对话框的同时,继续对记事本的内容进行编辑。

    6.2 标准对话框
        所谓标准对话框，是Qt内置的一系列对话框，用于简化开发。事实上，有很多对话框都是通用的，
        比如打开文件、设置颜色、打印设置等。这些对话框在所有程序中几乎相同，因此没有必要在每一个程序中都自己实现这么一个对话框。
        Qt的内置对话框大致分为以下几类:
            QColorDialog:               选择颜色
            QFileDialog:                选择文件或者目录
            QFontDialog:                选择字体
            QInputDialog:               允许用户输入一个值，并将其值返回
            QMessageBox:                模态对话框，用于显示信息、询问问题等
            QPageSetupDialog:           为打印机提供纸张相关的选项
            QPrintDialog                打印机配置
            QPrintPreviewDialog         打印预览
            QProgressDialog             显示操作过程

        例：
                #include "widget.h"
                #include <QFileDialog>
                #include <QString>
                #include <QDebug>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    this->resize(600,400);
                    button  = new QPushButton("选择文件",this);
                    button->resize(100,100);
                    button -> move(300,100);
                    connect(button,&QPushButton::clicked,this,[](){
                        //当点了按钮的时候，弹出对话框，返回文件的名字
                        //获取一个文件的名字。
                //        QString str = QFileDialog::getOpenFileName();
   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名
                //        qDebug() << str;    //他就打印你选择的文件的名字。

                        //若要打印多个文件名，则改为：文件列表 ，Names
                        QStringList str = QFileDialog::getOpenFileNames();
   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名 qDebug()
   << str;    //他就打印你选择的文件的名字。
                    });
                }

                Widget::~Widget()
                {
                }


    6.3 自定义消息框
        6.3.1 模态对话框
            * Qt有两种级别的模态对话框
                * 应用程序级别的模态
                    当该种模态的对话框出现时，用户必须首先对的对话框进行交互，直到关闭对话框，然后才能访问程序中其它的窗口。
                * 窗口级别的模态
                    该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。窗口级别的模态尤其适用多窗口模式。
                一般默认是应用程序级别的模态。

                在下面的示例中，我们调用了exec()将对话框显示出来，因此这就是一个模态对话框。当对话框出现时，我们不能与主窗口进行任何交互，直到我们关闭了该对话框。
                    QDialog dialog;
                    dialog.setWindowTitle(tr("Hello,dailog!"));
                    dialog.exec();

        6.3.2 非模态对话框
            下面我们试着将exec()修改为show()，看看非模态对话框：
                    QDialog dialog(this);
                    dialog.setWindowTitle(tr("Hello,dialog!"));
                    dialog.show();
                是不是事与愿违？对话框一闪而过！这是因为show()函数不会阻塞当前线程，对话框会显示是不是事与愿违?对话框竟然一闪而过!这是因为，show()函数不会阻塞当前线程，对话框会显示出来，
                然后函数立即返回，代码继续执行。注意，dialog是建立在栈上的，show()函数返回，MainWindow::open()函数结束，dialog超出作用域被析构，因此对话框消失了。
            知道了原因就好改我们将 dialog 改成堆上建立，当然就没有这个问题了:
                    QDialog *dialog=new QDialog;
                    dialog->setWindowTitle(tr("Hello, dialog!"));
                    dialog->show();
            如果你足够细心，应该发现上面的代码是有问题的:dialog存在内存泄露!dialog
   使用 上分配空间，却一直没有 delete。解决方案也很简单:将 NainWindow 的指针赋给
   dialog 即可。 还记得我们之前说的Qt的对象系统吗？
            不过，这样做有一个问题：如果我们的对话框不是在一个界面类中出现呢？由于QWidget
   的parent必须是QWidget指针，那就限制了我们不能将一个普通的C++类指针传给Qt对话框。
            另外，如果对内存占用有严格限制的话，当我们将主窗口作为parent时，主窗口不关闭，对话框就不会被销毁，所以会一直占用内存。
            在这种情况下，我们可以设置dialog的WindowAttribute:
                QDialog *dialog = new QDialog;
                dialog->setAttribute(Qt::WA_DeleteOnClose);
                dialog->setWindowTitle(tr("Hello,dialog!"));
                dialog->show();
            setAttribute()函数设置对话框关闭时，自动销毁对话框。


对话框例子：
    widget.cpp:
                #include "widget.h"
                #include <QFileDialog>
                #include <QString>
                #include <QDebug>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    this->resize(600,400);
                    button  = new QPushButton("选择文件",this);
                    button->resize(100,100);
                    button -> move(300,100);
                    connect(button,&QPushButton::clicked,this,[](){
                        //当点了按钮的时候，弹出对话框，返回文件的名字
                        //获取一个文件的名字。
                //        QString str = QFileDialog::getOpenFileName();   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名
                //        qDebug() << str;    //他就打印你选择的文件的名字。

                        //若要打印多个文件名，则改为：文件列表 ，Names
                        QStringList str = QFileDialog::getOpenFileNames();   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名
                        qDebug() << str;    //他就打印你选择的文件的名字。
                    });

                    //设置button1
                    button1  = new QPushButton("模态对话框按钮",this);
                    button1->resize(100,100);
                    button1 -> move(300,200);
                    connect(button1,&QPushButton::clicked,this,[](){
                        //再创建一个对话框
                        QDialog dialog;
                        //设置对话框的标题
                        dialog.setWindowTitle(tr("Hello,dailog!"));
                        //阻塞对话框
                        dialog.exec();
                    });

                    //设置button2
                    button2  = new QPushButton("非模态对话框按钮",this);
                    button2->resize(100,100);
                    button2 -> move(400,200);
                    connect(button2,&QPushButton::clicked,this,[](){
                        //再创建一个对话框
                        QDialog *dialog = new QDialog;

                        //因此需要让对话框自动释放：
                        dialog->setAttribute(Qt::WA_DeleteOnClose); //需要一个宏，关闭窗口的时候，会自动释放内存

                        //设置对话框的标题
                        dialog->setWindowTitle(tr("非模态,dailog!"));
                        //非阻塞对话框
                        dialog->show(); //在堆区开辟固然可以避免出作用域后的自动销毁，但在之后没有手动销毁该空间，会内存泄露
                    });

                }

                Widget::~Widget()
                {
                }

        widget.h:
                #ifndef WIDGET_H
                #define WIDGET_H

                #include <QWidget>
                #include <QPushButton>

                class Widget : public QWidget
                {
                    Q_OBJECT

                public:
                    Widget(QWidget *parent = nullptr);
                    ~Widget();
                    QPushButton *button;    //标准对话框按钮：当点了按钮的时候，弹出对话框，返回文件的名字
                    QPushButton *button1;   //模态对话框按钮
                    QPushButton *button2;   //非模态对话框按钮


                };
                #endif // WIDGET_H


        6.4 消息对话框
            QMessageBox用于显示消息提示。我们一般会使用其提供的几个static 函数:
            * 显示关于对话框。
                void about(QWidget * parent, const QString &title, const QString &text)
            这是一个最简单的对话框，其标题是 title，内容是text，父窗口是parent。对话框只有个OK按钮。
            * 显示关于 Qt 对话框。该对话框用于显示有关 Qt 的信息。
                void aboutQt(QWidget *parent, const QString &title = QString()):
            * 显示严重错误对话框。
                StandardButton critical(QWidget *parent,const QString &title,const QString &text,StandardButtons buttons = Ok,StandardButton defaultButton = NoButton);
            这个对话框将显示一个红色的错误符号。我们可以通过buttons 参数指明其显示的按钮。默认情况下只有一个ok 按钮，我们可以使用StandardButtons 类型指定多种按钮。
            * 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个普通信息图标。
                StandardButton information(QWidget * parent,const QString & title,const OString & text,StandardButtons buttons = Ok，StandardButton defaultButton = NoButton)
            * 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个问号图标，并且其显示的按钮是“是”和“否”
            StandardButton question(QWidget* parent,const QString & title,const QString & text,StandardButtons buttons = StandardButtons( Yes | No ),StandardButton defaultButton= NoButton)
            * 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个黄色叹号图标。
            StandardButton warning(QWidget * parent,const QString &fitle，const OString & text，StandardButtons buttons = Ok,StandardButton defaultButton = NoButton)

            我们可以通过下面的代码来演示下如何使用 QessageBox。
                if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"), tr(" Are you OK?"), QMessageBox::Yes |QMessageBox::No,QMessageBox::Yes))
                {
                    QMessageBox::information(this, tr("Hmmm..."),tr("I'm glad to hear that!"));
                }
                else
                {
                    QMessageBox::information(this, tr("Hmmm..."),tr("I'm sorry!"));
                }
                我们使用QMessageBox::question()来询问一个问题。
                * 这个对话框的父窗口是this.
                    QMessageBox是QDialog的子类，这意味着它的初始显示位置将会是在parent窗口的中央
                * 第二个参数是对话框的标题



*/
//七、布局管理器
/*
7.布局管理器
    所谓 GUI界面，归根结底，就是 一堆组件的叠加。我们创建一个窗口，把按钮放上面，把图标放上面，这样就成了一个界面。
    在放置时，组件的位置尤其重要。我们必须要指定组件放在哪里，以便窗口能够按照我们需要的方式进行渲染。这就涉及到组件定位的机制。

    Qt 提供了两种组件定位机制:绝对定位和布局定位。
        * 绝对定位就是一种最原始的定位方法:给出这个组件的坐标和长宽值。这样，Qt就知道该把组件放在哪里以及如何设置组件的大小。
            但是这样做带来的一个问题是，如果用户改变了窗口大小，比如点击最大化按钮或者使用鼠标拖动窗口边缘，采用绝对定位的组件是不会有任何响应的。
            这也很自然，因为你并没有告诉Qt，在窗口变化时，组件是否要更新自己以及如何更新。或者，还有更简单的方法:禁止用户改变窗口大小。但这总不是长远之计。

        * 布局定位:你只要把组件放入某一种布局，布局由专门的布局管理器进行管理。当需要调整大小或者位置的时候，Qt使用对应的布局管理器进行调整。
            布局定位完美的解决了使用绝对定位的缺陷。

    Qt 提供的布局中以下三种是我们最常用的:
            * QHBoxLayout:按照水平方向从左到右布局:
            * QVBoxLayout:按照竖直方向从上到下布局:
            * QGridLayout:在一个网格中进行布局，类仪于HTML的table:

    7.1 系统提供的布局控件
        vertical Layout
        Horizontal Layout
        Grid Layout
        Form Layout
        这四个是系统给我们提供的布局的控件，但是使用起来不是非常的灵活，这里就不详细介绍了。

    7.2 利用 widget做布局
        第二种布局方式是利用控件里的widget来做布局 ，在Containers中

    注意：
        * 课程ui中的按钮设置里面有路径问题，ui的添加资源后的相对路径是相对与Makefile的文件的路径。如果资源没有在项目下，则.exe可执行文件在执行时可能会找不到资源（加载不出来），因此最好把资源就拷贝到项目路径下。

        * 并且，对于按钮的 信号与槽：对于按钮进行右键，然后点击转到槽，再选择信号，就会跳转到widget.cpp的clicked槽函数,这里直接在函数体内去实现功能即可，
          这里不需要使用connect进行连接的原因是：在文件build文件里面，有一个ui_widget.h文件，里面有一句话：QMetaObject::connectSlotsByName(Widget); 这个函数设置了 会自动根据你的控件的名字然后自动生成了槽函数，这个函数帮我们根据名字设置了连接按钮和槽函数的操作。

    相对路径：如果是在qt中运行，代码中的相对路径是依据于makefile的
            如果是手动运行，代码中的相对路径是依据于.exe的可执行程序。
*/
//八、常用控件
/*
八、常用控件
    Qt 为我们应用程序界面开发提供的一系列的控件，下面我们介绍两种最常用一些控件，所有控件的使用方法我们都可以通过帮助文档获取。

    8.1 QLabel控件使用
        QLabel是我们最常用的控件之一，其功能很强大，我们可以用来显示文本，图片和动画等。
        8.1.1显示文字(普通文本、html)
        通过 QLabel类的 setText 函数设置显示的内容:
            void setText(const QString &)
        * 可以显示普通文本字符串
            QLable *label = new QLable;
            label->setText("Hello. World!");
        * 可以显示 HTML格式的字符串
            比如显示一个链接:
                QLabel *label= new QLabel(this);
                label ->setText("Hello, World");
                label ->setText("<hl><ahref=\"https://www.baidu.com\">百度-下</a><hl>");
                label ->setOpenExternalLinks(true);
        其中 setOpenExternalLinks()函数是用来设置用户点击链接之后是否自动打开链接，如果参数指定为 true 则会自动打开。

    8.1.2 放一个图片
    8.1.3 放一个gif动态图
        例：
                #include "widget.h"
                #include <QPixmap>
                #include <QMovie>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    this->resize(600,400);
                    label = new QLabel(this);
                    label->resize(100,100);
                    label->move(100,100);
                //    label -> setText("我是一个标签");
                    label -> setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>"); //a 表示超链接，显示的文本是“百度一下”
                    label -> setOpenExternalLinks(true);    //设置：点击链接 可以跳转

                    label_pic = new QLabel(this);
                    label_pic->resize(300,200);
                    label_pic->move(200,200);
                //    label -> setText("我是一个标签");
                    label_pic -> setPixmap(QPixmap("../02untitled/picture/1.jpg"));
                    //设置一个自适应大小：
                    label_pic -> setScaledContents(true);

                    label_move = new QLabel(this);
                    label_move->resize(100,100);
                    label_move->move(300,200);

                    QMovie *move = new QMovie("../02untitled/picture/1.gif");
                    label_move->setMovie(move);
                    label_move->setScaledContents(true);
                    move->start();  //启用

                }

                Widget::~Widget()
                {
                }


    8.2 设置获取行编辑内容
        8.2.1 设置/获取内容
            * 获取编辑框内容使用text()，函数声明如下：
                QString text() const
            * 设置编辑框内容
                void setText(const QString &)
        例;
            #include "widget.h"
            #include "ui_widget.h"
            #include <QDebug>
            Widget::Widget(QWidget *parent)
                : QWidget(parent)
                , ui(new Ui::Widget)
            {
                ui->setupUi(this);
                ui->lineEdit->setText("hello"); //设置行编辑的内容
            }

            Widget::~Widget()
            {
                delete ui;
            }


            void Widget::on_lineEdit_returnPressed()
            {
                qDebug() << ui->lineEdit->text(); //获取行编辑的内容
            }


        8.2.2 设置显示模式
            使用QLineEdit类的setEchoMode()函数设置文本的显示模式，函数声明：
                void setEchoMode(EchoMode mode)
            EchoMode 是一个枚举类型，一共定义了四种显示模式
                * QLineEdit::Normal 模式显示方式，按照输入的内容显示
                * QLineEdit::NoEcho 不显示任何内容，此模式下无法看到用户的输入。
                * QLineEdit::Password 密码模式，输入的字符会根据平台转换为特殊字符
                * QLineEdit::PasswordEchoOnEdit 编辑时显示字符否则显示字符作为密码。
            另外，我们再使用QLineEdit 显示文本的时候，希望在左侧留出一段空白的区域，那么，就可以使用QLineEdit给我们提供的，setTextMargins函数：
                void setTextMargins(int left,int top,int right,int botton)
            用此函数可以指定显示的文本与输入框上下左右边界的间隔的像素数。
        例：
        设置行编辑和密码模式：
                #include "widget.h"
                #include "ui_widget.h"
                #include <QDebug>
                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                    , ui(new Ui::Widget)
                {
                    ui->setupUi(this);
                    //设置显示模式
                    ui->lineEdit->setEchoMode(QLineEdit::Password); //显示为密码模式
                    ui->lineEdit->setTextMargins(80,0,0,0);    //设置间距。 参数：左上右下的像素空多少。
                //    ui->lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);//输入时是可视的，不输入时是不可视的
                    ui->lineEdit->setText("hello"); //设置行编辑的内容
                    //设置空几个像素

                }

                Widget::~Widget()
                {
                    delete ui;
                }

                void Widget::on_lineEdit_returnPressed()
                {
                    qDebug() << ui->lineEdit->text(); //获取行编辑的内容
                }

        8.3 自定义控件
            在搭建 Qt窗口界面的时候，在一个项目中很多窗口，或者是窗口中的某个模块会被经常性的重复使用。
            一般遇到这种情况我们都会将这个窗口或者模块拿出来做成一个独立的窗口类，以备以后重复使用。
            在使用 Qt的ui 文件搭建界面的时候，工具栏 栏中只为我们提供了标准的窗口控件，如果我们想使用自定义控件怎么办?
            例如:我们从QTidget派生出一个类SmallWidget，实现了一个自定窗曰,
        8.4 定时器
            QTimer:定时触发。

        例：
        widget:
                #ifndef WIDGET_H
                #define WIDGET_H

                #include <QWidget>
                #include <QTimer>

                QT_BEGIN_NAMESPACE
                namespace Ui { class Widget; }
                QT_END_NAMESPACE

                class Widget : public QWidget
                {
                    Q_OBJECT

                public:
                    Widget(QWidget *parent = nullptr);
                    ~Widget();
                    QTimer *t;


                private slots:
                    void on_pushButton_clicked();

                    void on_pushButton_2_clicked();

                private:
                    Ui::Widget *ui;
                };
                #endif // WIDGET_H


        widget.cpp
                #include "widget.h"
                #include "ui_widget.h"
                #include <QDebug>
                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                    , ui(new Ui::Widget)
                {
                    ui->setupUi(this);
                    t = new QTimer;
                    //有了定时器，可以设置定时器的超时事件，如果超时 会发出一个超时信号。

                    //这里定时器超时后就会在这里链接到Lambda表达式
                    connect(t,&QTimer::timeout,this,[](){
                        qDebug() << "timeout";
                    });
                    //定时器必须启动

                }

                Widget::~Widget()
                {
                    delete ui;
                }


                void Widget::on_pushButton_clicked()    //ui自链接的槽函数，点击一次开始，然后就会在这里开始启动定时器
                {
                    t->start(1000); //启动定时器。 1000*1ms 超时一次，超时一次就调用槽函数
                }


                void Widget::on_pushButton_2_clicked()
                {
                    t->stop();  //停止定时器。
                }





*/
//九、Qt消息机制和事件
/*
    9.1 事件处理过程
        事件(event) 是由 系统 或者 Qt本身 在不同的时刻发出的。当用户按下鼠标、敲下键盘，或者是窗口需要重新绘制的时候，都会发出一个相应的事件。

        一些事件在对用户操作做出响应时发出，如键盘事件等;另一些事件则是由系统自动发出，如计时器事件。

        事件处理过程:
            1)在 Qt 内部，Qt 通过 QApplication:exec()启动的主事件循环不停的抓取事件队列中的事件。

            2)当事件发生时，Qt将创建一个事件对象。Qt中所有事件类都继承于QEvent.

            3)在事件对象创建完毕后，Qt将 这个事件对象 传递给 QObject的 event()函数。 event()函数并不直接处理事件,而是 按照事件对象的类型 分派给 特定的事件处理函数(event hander)。event()函数主要用于事件的分发:

            widget窗口
            QApplication::exec() //主时间循环 检测是否有事件产生
            一旦有事件产生，就会生成一个事件对象，
            例如
                鼠标点击事件 就会产生鼠标对象
                键盘事件    就会产生键盘对象
            事件对象创建完毕后 Qt把事件对象传递给QObject的 event()函数,再由event函数按照事件对象的类型分派给特定的事件处理函数
            由于QWidget函数体内有许多虚函数，而这些虚函数默认都是空实现，因此，在产生事件的时候，我们只需要重写虚函数即可。


    9.2 常用事件处理
        在所有控件的父类 QWidget中,定义了很多事件处理的回调函数。这些函数都是 protected virtual 的，也就是说
        我们可以在子类中重新实现这些函数。实现函数 要遵循虚函数的语法规则，自定义的类中保证函数名、参数 的一致性。

        9.2.1 鼠标事件(QMouseEvent)
        流程图片请参考:流程图片\第03天\01鼠标事件

        参考代码:code\day03\01 MouseEvent

        //重写父类的虚函数

        protected:
        virtual void mousePressEvent(QMouseEvent*);//鼠标点击事件
        virtual void mouseReleaseEvent(QMouseEvent*); //鼠标抬起事件
        virtual void mouseDoubleClickEvent(QMouseEvent *); //鼠标双击事件
        virtual void mouseMoveEvent(QMouseEvent*);//鼠标移动事件

        9.2.2 滚轮事件（QWheelEvent）
            参考代码:
            code\day03\02 QWheelEvent
            //virtual void wheelEvent(QWheelEvent*);//鼠标滚轮滑动

            //鼠标滚轮滑动
            void Widget::wheelEvent(QWheelEvent *e)
            {
                if(e->orientation()== Qt::Vertical)//如果方向是垂直
                {
                    QPoint point = e->angleDelta();
                    QString str = QString("滚轮垂直滑动(%1,%2)");
                    .arg(point.x()).arg(point.y());
                    ui->label->setText(str);
                }
            }

        9.2.3 键盘事件（QKeyEvent）
        //virtual void keyPressEvent(QKeyEvent *); //键盘按下事件
        //virtual void keyReleaseEvent(QKeyEvent *); //键盘抬起事件

        //键盘按下事件
        void Widget::keyPressEvent(QKeyEvent *e)
        {
            QString str;
        }

        9.2.4 大小改变事件（QResizeEvent）
        //virtual void resizeEvent(QResizeEvent *); //大小改变事件

        //大小改变事件
        void Widget::resizeEvent(QResizeEvent *e)
        {
            //变化前的窗口大小
            qDebug()<< "e->oldSize() =" << e->oldSize();

            //变化后的窗口大小
            qDebug() << "e->size() =" << e->size();
        }

        9.2.5 进入离开区域事件（enterEvent\leaveEvent）

        //virtual void enterEvent(QEvent *); //进入事件
        //virtual void leaveEvent(QEvent *); //离开事件

*/
//十、Qt绘图机制
/*
 十、Qt绘图机制
    Qt的绘图机制 为屏幕显示 和 打印显示 提供了统一的AP|接口，主要有三部分组成:QPainter 类、QPaintDevice类和 QPaintEngine 类
    I QPainter 类 提供了画图操作的各种接口，可方便地绘制各种各样的图形。
    I QPaintDevice 类提供可用于画图的空间，及画图容器。
    I PaintEngine 类是抽象类，提供了 QPainter 如何在指定的平台上给指定的设备绘画的抽象接口，对开发者而言, 一般不会用到。

    Qt的绘图系统实际上是，使用QPainter 在QPainterDevice上进行绘制，他们之间使用QPaintEngine进行通讯（也就是翻译QPainter的指令）


    qt中所有的图都是画出来的。例如按钮 窗口 标签上的图
    画图需要两个东西：
        画家：
        QPainter

        画板：
        QPainterDevice(常见的控件 按钮 label 窗口)

    一旦窗口改变了，就会产生画图事件：
    qwidget
    {
        void Widget::paintEvent(QPaintEvent *e); //重写虚函数
        注意：画图必须在这个函数里面画。
    }

*/
//更新绘图
/*
    调用this下面的update更新绘图
*/
//笔记区
//############################################################################
//代码区












#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}



