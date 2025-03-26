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
