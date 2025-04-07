//#include "widget.h"
//#include <QFileDialog>
//#include <QString>
//#include <QDebug>

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//{
//    this->resize(600,400);
//    button  = new QPushButton("选择文件",this);
//    button->resize(100,100);
//    button -> move(300,100);
//    connect(button,&QPushButton::clicked,this,[](){
//        //当点了按钮的时候，弹出对话框，返回文件的名字
//        //获取一个文件的名字。
////        QString str = QFileDialog::getOpenFileName();   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名
////        qDebug() << str;    //他就打印你选择的文件的名字。

//        //若要打印多个文件名，则改为：文件列表 ，Names
//        QStringList str = QFileDialog::getOpenFileNames();   //这句话弹出一个对话框，然后你选择文件，str就保存了文件的绝对路径名
//        qDebug() << str;    //他就打印你选择的文件的名字。
//    });

//    //设置button1
//    button1  = new QPushButton("模态对话框按钮",this);
//    button1->resize(100,100);
//    button1 -> move(300,200);
//    connect(button1,&QPushButton::clicked,this,[](){
//        //再创建一个对话框
//        QDialog dialog;
//        //设置对话框的标题
//        dialog.setWindowTitle(tr("Hello,dailog!"));
//        //阻塞对话框
//        dialog.exec();
//    });

//    //设置button2
//    button2  = new QPushButton("非模态对话框按钮",this);
//    button2->resize(100,100);
//    button2 -> move(400,200);
//    connect(button2,&QPushButton::clicked,this,[](){
//        //再创建一个对话框
//        QDialog *dialog = new QDialog;

//        //因此需要让对话框自动释放：
//        dialog->setAttribute(Qt::WA_DeleteOnClose); //需要一个宏，关闭窗口的时候，会自动释放内存

//        //设置对话框的标题
//        dialog->setWindowTitle(tr("非模态,dailog!"));
//        //非阻塞对话框
//        dialog->show(); //在堆区开辟固然可以避免出作用域后的自动销毁，但在之后没有手动销毁该空间，会内存泄露
//    });

//}

//Widget::~Widget()
//{
//}



#include "widget.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //消息对话框
    //button
    this->resize(600,400);
    button  = new QPushButton("关于",this);
    button->resize(100,100);
    button->move(100,100);
    connect(button,&QPushButton::clicked,this,[&](){
        //消息对话框里面包含了很多的静态函数：
        QMessageBox::about(this,"标题","内容");
    });


    //button1
    button1  = new QPushButton("询问",this);
    button1 ->resize(100,100);
    button1 ->move(200,100);
    connect(button1,&QPushButton::clicked,this,[&](){
        //当按了按钮，就调该匿名函数
        QMessageBox::StandardButton ret = QMessageBox::question(this,"标题","你需要吗？",QMessageBox::Open|QMessageBox::Save);//默认会给YES或NO
        if(ret == QMessageBox::Open)
        {
            qDebug() << "Open";
        }
        else
        {
            qDebug() << "Save";
        }
    });
}

Widget::~Widget()
{
}

