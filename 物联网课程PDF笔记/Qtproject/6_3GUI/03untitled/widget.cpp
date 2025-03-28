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

