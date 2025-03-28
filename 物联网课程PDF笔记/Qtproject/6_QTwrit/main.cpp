//һ��Qt���
/*
    1.1 ʲô��QT
        Qt ��һ�� ��ƽ̨ �� C++ͼ���û�����Ӧ�ó����ܡ���ΪӦ�ó��򿪷����ṩ����������ͼ�ν�����������й��ܡ�
        ������ȫ�������ģ���������չ���������������������̡�

    1.2 Qt �ķ�չʷ
        1991��Qt��������Ȥ�Ƽ�����
        1996�� ������ҵ������Ҳ��Ŀǰ���е�Linux���滷��KDE�Ļ���
        2008�� ��Ȥ�Ƽ���ŵ���ǹ�˾�չ���Qt��Ϊŵ�������µı������
        2012�� Qt �ֱ� Digia ��˾�չ�
        2014��4�¿�ƽ̨�ļ��ɿ�������QtCreator3.1.0������ͬ��5��20���䷢��Qt5.3��ʽ�棬

        ���� Qt ʵ���˶� i0S��Android��WP �ȸ�ƽ̨��ȫ��֧�֡�
        ��ǰQl���°汾Ϊ 5.13.2(2019.12֮ǰ)
    1.3֧�ֵ�ƽ̨
        Windows  - XP��Vista��Win7��Win8��Win2008�� Winl0
        Uinux/X11-Linux,Sun Solaris��HP-Ux, Compaq Tru64UNIX, IBMAIX�� SGI IRIX, FreeBSD��BSD/OS���������ܶ�X11ƽ̨
        Macintosh- Mac OS X
        Embedded - ��֡����֧�ֵ�Ƕ��ʽLinuxƽ̨��Windows CE
    1.4 Qt �汾
        Qt���ղ�ͬ�İ汾���У���Ϊ��ҵ��Ϳ�Դ��
        ��ҵ��
            Ϊ��ҵ����ṩ�����������ṩ��ͳ��ҵ������а棬�����ṩ����ҵ��Ч���ڵ���������ͼ���֧�ַ���
        ��Դ�� LGPL �汾:
            Ϊ�˿������ж���ƵĿ���Դ����������ṩ�˺���ҵ�汾ͬ���Ĺ��ܣ��� GN ͨ�ù�������£�������ѵġ�

    1.5 QT�������밲װ
        1.5.1 ���ص�ַ
            http://www.qt.io/download-open-source/
            ����
            http://download.qt.io/archive/qt/
        1.5.2 ��װ
            ����Ĭ�ϰ�װ����
            Qt �Բ�ͬ��ƽ̨�ṩ�˲�ͬ�汾�İ�װ�����ɸ���ʵ������������ذ�װ�����ĵ�ʹ��
            qt-opensource-windows-x86-mingw530-5.8.0 �汾���н���(32 λ�� 64 λ���ɰ�װ)
    1.6 Qt ���ŵ�
        * ��ƽ̨������֧�����е�ƽ̨
        * �ӿڼ򵥣��������֣�ѧϰ QT ��ܶ�ѧϰ��������вο����塣
        * һ���̶��ϼ����ڴ���ջ���
        * ����Ч�ʸߣ��ܹ����ٵĹ���Ӧ�ó���
        * �кܺõ�������Χ���г��ݶ��ڻ���������
        * ���Խ���Ƕ��ʽ������
    1.7�ɹ�����
        Linux ���滷�� KDE
        Skype ����绰
        Google Earth �ȸ��ͼ
        VLC ��ý�岥����
        VirtualBox ��������
        �乾����
        WPS Office
        ��Ʒ�ɳ�

*/
//��������Qt��Ŀ
/*
    2.1 ʹ���򵼴���
        �� Qt Creator ����ѡ�� New Project ����ѡ��˵��� ���ļ���-���½��ļ�����Ŀ�� �˵���

    ע�⣺
        * �ڽ�c++ʱ������QTдc++�����Ӧ�ó���ʱ��ѡ�����Non-QT-Project(��QT����Ŀ)
            ����������QT�����棬����ѡ��������Ӧ�ó��򣬹�ѡAPPlication -> Qt Widgets Application (��QT�ؼ���һ��Ӧ�ó���)

        * ��Details ����� Base class �ǻ����ѡ��
            �����ѡ������˴�����Ŀʱ���ڳ�ʲô���ӣ�
                QMainWindow ������ͨ�Ĵ��������Ľ���
                ADialog     ���Ǵ��Ի���Ĵ��ڣ�
                Qwidget     ����ʲô�������Ľ��棬����һ�����ڡ�   һ��ѡ���֣�

            generate form �����ɴ��ڣ�һ����ͼ�Ĺ��ߣ����������滭ͼ������ͼ���Ϳ��԰ѿؼ���ʾ�����棩��

        * ���ɵ���Ŀ���棺 pro�Ǵ�����Ŀ��ʱ���Զ����ɵģ�����֮�����ݸ��ļ�ȥ����makefile��ȥ����һ��������
        *               pro�ǹ�����Ŀ�ļ���QT��һ������ �У�qmake��qmake�������������һ��makefile(���ڱ���Ľű�).qmake���ǽ������pro����Ķ�����


    2.1 QT д����Ŀ��
        ϵͳ��Ĭ�ϸ��������main.cpp��mywidget.cpp��mywidget.h��һ��.pro��Ŀ�ļ��������ɼ��ɴ�����һ��QT�������

    main.cpp:
            #include "widget.h"

            #include <QApplication>     //QT�Ŀ�ܣ��Ǳ�����ӵ�

            int main(int argc, char *argv[])    //QT�Ŀ�ܳ�ʼ����
            {
                QApplication a(argc, argv);
//                Widget w;     //������һ������
//                w.show();     //���ڵ�show��������ʾ

                //�������Ƕ�����һ��QT��һ������
                return a.exec();    //a.exe �������ó�������������while(1).ѭ������¼��Ĳ�����
            }
    ע��:
        .exe��ִ�г����� buile �� debug�����档
        ����pro�ļ� ����qmake���߽��� ���ɵ�makefile ����������ġ�

    2.2 �ֶ�����
        ���һ������Ŀ

        #include <QDebug>
        qDebug() << "hello"; //�ڳ��������������ʹ��cout ,���Ǵ���һ����������:qDebug(),����Ӧ�ó��������

    ����
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
    ע�⣺
        QT�е���������
            ��������������׸���ĸ��д�����׸����ʵ�����ĸ��д   �����շ巨��
            ���ں����������׸���ĸСд�����׸����ʵ�����ĸ��д   ��С�շ巨��

    2.4��򵥵�QTӦ�ó�����ͣ�
        ���ͣ�
            * QTϵͳ�ṩ�ı�׼��������ͷ�ļ�û��.h��׺
            * Qtһ�����Ӧһ��ͷ�ļ�����������ͷ�ļ���
            * QApplication Ӧ�ó�����
                * ����ͼ���û�����Ӧ�ó���Ŀ���������Ҫ����
                * ��Qt��������̨��������� ������ ���¼�ѭ�������������Դ���ϵͳ �� ������Դ�������¼����� �͵��ȡ���Ҳ����Ӧ�ó���ĳ�ʼ���ͽ����������ṩ �Ի�����
            * �����κ�һ��ʹ��Qt��ͼ���û�����Ӧ�ó��򣬶����ô���һ��QApplication ���󣬶��������Ӧ�ó�����ͬһʱ�����ǲ�����0��1��2���������ڡ�
            * a.exec()
                ���������Ϣѭ�� ���ȴ����û����������Ӧ������main()�ѿ�Ȩת����Qt��Qt ����¼�����������Ӧ�ó����˳���ʱ��exec()��ֵ�ͻ᷵�ء�
                 ��exec()�У�Qt���ܲ������û���ϵͳ���¼����Ұ����Ǵ��ݸ��ʵ��Ĵ��ڲ�����
*/
//�������ô�������
/*
    3.1 ������дλ��
        ͨ��֮ǰ���ݼ����⣬�´�����qt��Ŀ���̵��ļ��ṹ��01unititlied��ʾ

        ��ô���Ҫ���ô��ڵ����Ի������һЩ�ؼ�������Ӧ�����ĸ��ļ���д��?
        .pro �ļ��������ɿ�ִ���ļ���.h���ͷ�ļ�����ȣ�widget.cpp ����Ҫ���.h�ļ��к�����ʵ�ֹ��̣�main.cpp
        ��Ҫ��������.

    main��cpp�ļ�����һ����룺
        widget w;
    Widget ��ʵ�����Ķ��� w����ʱ����ù��캯����������Ե�ǰ Widget ���еĹ��캯����д�����õ����Ի������һЩ�ؼ�����ʵ���������Ǿͻ���ù��캯�����Ӷ�ʵ����Ҫ�ﵽ��Ŀ�ģ�����������Ҳ����ʹ�����������ж���Ĵ���
    ����һ�㴰�ڵ����Ժ���ӿؼ��Լ��Կؼ��Ĳ�����������Ĺ��캯������д��

    3.2 Qt����
        ͨ���ڰ�װQtʱ�����Դ�һ��Qt���֣�����ȥ��ѯQt�е�Ҫʹ�õ���ͺ����ȡ�
        һ����ڿ�ʼ�˵���QtĿ¼�У�һ����� Assistant��

        Qt�Դ������ĵ���
            Header: ��Ҫ��ӵ�ͷ�ļ�
            qmake : .pro ������Ҫ��ӵĶ���
            Inherits:
            Inherits By���̳�����Щ��

    3.3 ���ô�������
        �Ѵ���������Ҫ�����ã�д�ڹ��캯�����档
    ����
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
*/
//�ġ���ť�Ĵ�������������
/*
    4.��ť�Ĵ�������������
        ������ QPushButton
       ͷ�ļ���#include <QPushButton>

        4.1 ��ť�Ĵ���
          ��Qt�����У���õĿؼ�֮һ���ǰ�ť������������������δ���һ����ť��
        ����
        .h:
            class Widget : public QWidget
            {
                Q_OBJECT

            public:
                Widget(QWidget *parent = nullptr);
                ~Widget();

                QPushButton *button;    //�������涨��һ��PushButton��ָ�롣
            };

        .cpp:
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

        4.2 ����ģ�ͣ���������
            ��Qt�д��������ʱ����ṩһ��Parent����ָ�룬�������������parent �����Ǹ�ʲô�ġ�
            * QObject�� �Զ���������ʽ ��֯�����ġ�
                * ���㴴��һ��QObject����ʱ,�ῴ��QObject�Ĺ��캯������һ��QObjectָ����Ϊ������
                   �����������parent��Ҳ���Ǹ�����ָ�롣
                   ���൱�ڣ��ڴ���QObject ����ʱ�������ṩһ���丸�������Ǵ�������� QObject ����
                   ���Զ���ӵ��丸����� children()�б�

            * ��������������ʱ������б��е����ж���Ҳ�ᱻ������(ע�⣬����ĸ����󲢲��Ǽ̳������ϵĸ���!)
            * QWidget���ܹ�����Ļ����ʾ��һ������ĸ��ࡣ
                * QWidget �̳��� QObject�����Ҳ�̳������ֶ�������ϵ��һ�������Զ��س�Ϊ�������һ���������
                  ��ˣ�������ʾ�ڸ����������ϵͳ�У���������ı߽���á����磬���û��ر�һ���Ի����ʱ��Ӧ�ó�����ɾ����
                  ��ô������ϣ����������Ի���İ�ť��ͼ���Ӧ��һ��ɾ������ʵ������ˣ���Ϊ��Щ���ǶԻ�����������
                * ��Ȼ������Ҳ�����Լ�ɾ���Ӷ������ǻ��Զ����丸�����б���ɾ����
                  ���磬������ɾ����һ��������ʱ�������ڵ������ڻ��Զ����ù����������Ӷ����б���ɾ���������Զ�������Ļ��ʾ��

            Qt����������ĸ����һ���̶��Ͻ�����ڴ����⡣
                * ��һ��QObject �����ڶ��ϴ�����ʱ��Qt��ͬʱΪ�䴴��һ�����������������������ж����˳����û�ж���ġ�����ζ�ţ�������Щ�����˳��Ҳ��δ����ġ�
                * �κζ������е�QObject����delete ��ʱ��,������������parent,���Զ������parent �� children()�б���ɾ��;����к��ӣ����Զ�delete ÿһ�����ӡ�
                  Qt��֤û�� QObject �ᱻ delete ���Σ�����������˳������ġ�

            ��� QObject ��ջ�ϴ�����Qt ����ͬ������Ϊ����������£���Ҳ���ᷢ��ʲô���⡣
            �����������Ƭ��:
            {
                QWidget window;
                QPushButton quit = QPushButton("�˳�",&window);
            }
            ��Ϊ �������window �� ��Ϊ�������quit ���� QObject������(��ʵ�ϣ����Ƕ��� QWidget ��
            ���࣬�� QWidget �� QObject ������)����δ�������ȷ�ģ�quit �������������ᱻ�������Σ�
            ��Ϊ��׼C++Ҫ�󣬾ֲ����������˳��Ӧ�ð����䴴��˳����෴���̡���ˣ���δ����ڳ�����
            ����ʱ�����ȵ���quit����������������Ӹ�����window���Ӷ����б���ɾ����Ȼ��Ż��ٵ��� window ������������


            ���ǣ����ʹ�����´���
            {
                QPushButton quit("Quit");
                Qwidget window;
                quit.setParent(&window);
            }
            �����������ͬ������˳����������ˣ����ǿ�����������Ĵ����У���Ϊ�������window�����ȱ���������Ϊ�������һ�������Ķ���
            �����������У���������Ӷ����б���ÿһ�����������������Ҳ����˵�� quit ��ʱ�ͱ������ˡ�
            Ȼ�󣬴������ִ�У��� window����֮��quit Ҳ�ᱻ��������Ϊ quitҲ��һ���ֲ��������ڳ����������ʱ��ȻҲ��Ҫ������
            ���ǣ���ʱ���Ѿ��ǵڶ��ε��� quit �����������ˣ�C++�������������������������ˣ���������ˡ�
            �ɴ����ǿ�����Qt�Ķ��������� ��Ȼ����������һ���̶��Ͻ�����ڴ����⣬����Ҳ������һЩֵ
            ��ע������顣��Щϸ���ڽ��Ŀ��������кܿ���ʱ��ʱ����������һ�£����ԣ�������ôӿ�ʼ����������ϰ�ߡ�

            �� Qt��,�����ڹ����ʱ���ָ��parent����,���Ҵ��ڶ��ϴ���.

        4.3 Qt��������ϵ

        ����ϵ:
        �����Ͻ�Ϊԭ��(0,0),x��������,Y��������

        ����Ƕ�״���,������������ڸ�������˵�ġ�
*/
//�塢�ź� �� �� ����
/*
    5.�ź� �� �� ����
        �źŲ��� Qt �������Ϊ���Ļ���֮һ����ν�źŲۣ�ʵ�ʾ��ǹ۲���ģʽ��
        ��ĳ���¼�����֮�󣬱��磬��ť��⵽�Լ��������һ�£����ͻᷢ��һ���ź�(signal),���ַ�����û��Ŀ�ĵ�,
        ���ƹ㲥������ж��������źŸ���Ȥ�����ͻ�ʹ������(connect)��������˼�ǣ�����Ҫ������źź��Լ���һ������(��Ϊ��(slot))�� ����������źš�
        Ҳ����˵�����źŷ���ʱ�������ӵĲۺ������Զ����ص���������ƹ۲���ģʽ:�������˸���Ȥ���¼���ĳһ�������ͻᱻ�Զ�������

        ����������˰�ť����ť�ͻ����һ������Ŀ�ĵ��źţ�signal��,������һ������Window��Ҫ��������źţ�����Ҫʹ��connect����ȥ����window���ڽ��յ�����źţ����ػص�slot�������ۺ���������connect�����þ��ǣ����õ�window���յ���signal�źţ��ͻ�ص�window����� �ص�����--�ۺ�����
        ������         �ź�          ������         �ۺ���
        ����     =>   ������    =>    ��    =>      ������

        5.1 ϵͳ�Դ����źźͲ�
            �����������һ��С���ܣ����������Ѿ�ѧϰ�˰�ť�Ĵ��������ǻ�û�����ֳ���ť�Ĺ��ܣ���ť���Ĺ���Ҳ���ǵ���󴥷�һЩ����,
            �������ǵ����ť,�Ͱѵ�ǰ�Ĵ��ڸ��رյ�,��ô�� Qt��,�����Ĺ������ʵ����?
                ��ʵ�޷����д���Ϳ��Ը㶨�ˣ����ǿ�����Ĵ��룺
                QPushButton *quitBtn = new QPushButton("�رմ���"��this);
                connect(quitBtn,&QPushButton::clicked,this,&MyWidget::close);

                ��һ���Ǵ���һ���رհ�ť�����֮ǰ���Ѿ�ѧ���ˣ��ڶ��о��Ǻ��ģ�Ҳ�����źŲ۵�ʹ�÷�ʽ
                connect()������õ�һ����ʽ��

                connect��sender,signal,receiver,slot��;
                �������ͣ�
                * sender : �����źŵĶ���
                * signal : ���Ͷ��󷢳����ź�
                * receiver : �����źŵĶ���
                * slot   : ���ն����ڽ��յ��ź�֮������Ҫ���õĺ������ۺ�����

            ��:
                #include "widget.h"
                #include <QPushButton>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    //����һ����ť �����ť�رմ���
                //    this->close();    //�������ֱ�ӹرմ��ڡ���������Ҫ�����ڰ�ť���º��ٵ��øú�����

                    //����newһ����ť������Ϊ:�رմ��ڣ�����ΪWidget
                    QPushButton *p = new QPushButton("�رմ���",this);
                    //���õ����ť ����ô��ڵ�close����
                    //�������� �����ť�����ź�  ����ô��ڵ�close����
                //    * sender :   ��ť����
                //    * signal :   �ź��� QPushButton����ĵ���ź�
                //    * receiver : ���ڽ���
                //    * slot   :   ���õ� һ���ǽ����źŵĶ�������Ĳۺ���
                    connect(p,&QPushButton::clicked,this,&QWidget::close);

                }

            5.2 ��ť���õ��ź�
                ��ôϵͳ�Դ����źźͲ�ͨ����β����أ��������Ҫ���ð����ĵ��ˣ��ڰ����ĵ��б�����������İ�ť�ĵ���źţ�
                �ڰ����ĵ������� QPushButton���������ǿ����� Contents ��Ѱ�ҹؼ��� signals���źŵ���˼���������Ƿ��ֲ�û���ҵ���
                ��ʱ������Ӧ���뵽Ҳ������źŵı�����̳������ģ��������ȥ���ĸ��� QAbstractButton�оͿ����ҵ��ùؼ��֣�
                ���signals ������ϵͳ�Դ����ź������¼�����
                void clicked(bool checked=false)
                void pressed()
                void released()
                void toggled(bool checked
                    * signals inherited,fron Qfidget
                    * signals inherited fron Qobject
                ����� clicked ��������Ҫ�ҵģ��ۺ�����Ѱ�ҷ�ʽ �� �ź�һ����ֻ�������Ĺؼ����� slot��

            5.3 �Զ����źźͲ�
                ʹ��connect()��������������ϵͳ�ṩ���źźͲۡ����ǣ�Qt���źŲۻ��Ʋ���������ʹ��ϵͳ�ṩ���ǲ��֣��������������Լ�����Լ����źźͲۡ�
                �������ǿ���ʹ�� Qt ���źŲ�

                5.3.1 �Զ���� �ۺ���
                ע�⣺
                    ����һ��public�Ĳۺ�����ע�⣺�ú����費��Ҫ��������Ҫȥ��&QPushButton::pressed��û�в�����
                    ��� �ź�û�в�������ۺ���Ҳ����Ҫ������ ����ź��в������ۺ���������Ҳ����û�в�����

                    Fn + F1����ת����Ӧ�İ����ĵ���
                    Fn + F4����.h ��ת�� .c �ļ�

                widget.cpp��
                    #include "widget.h"
                    #include <QDebug>
                    Widget::Widget(QWidget *parent)
                        : QWidget(parent)
                    {
                        //����һ����ť
                        button = new QPushButton;
                        button->setParent(this);
                        button->setText("��ӡ־��ţ��");
                        //ע���ź���۵�����
                        //�ۺ�����������ͨ�ĳ�Ա���������������Զ���ۺ���
                        connect(button,&QPushButton::pressed,this,&Widget::print);

                    }

                    Widget::~Widget()
                    {
                    }

                    void Widget::print()
                    {
                        qDebug() << "־��ţ��";
                    }

                widget.h��
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
                        QPushButton *button;    //Fn + F1����ת����Ӧ�İ����ĵ���
                                                //Fn + F4����.h ��ת�� .c �ļ�
                    public slots:

                        void print();   //����һ��public�Ĳۺ�����ע�⣺�ú����費��Ҫ��������Ҫȥ��&QPushButton::pressed��û�в�����
                        //��� �ź�û�в�������ۺ���Ҳ����Ҫ������ ����ź��в������ۺ���������Ҳ����û�в�����
                    };
                    #endif // WIDGET_H

                5.3.2 �Զ���� �ź�
                    ԭ����γ�ͼ�⡣

                ����
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
                        QPushButton *sbutton;   //�Ӵ��ڵİ�ť�����ã����º������Ӵ��ڣ���ʾ�����ڣ�ע�⣬������ʾ���ര��ֻ�����ź���ۻ��ƣ�
                    signals:
                        //���ź����ﶨ��һ���ź�
                        //�źſ����в�����Ҳ����û�в������ź�û�з���ֵ���źŲ���Ҫ���壬ֻ��Ҫ��������
                        void show_hide_signal(int a);
                    public slots:
                        //����ۺ���
                        void emit_mysignal();
                    };

                    #endif // SONWIDGET_H

                widget.h:
                    #ifndef WIDGET_H
                    #define WIDGET_H

                    #include <QWidget>
                    #include "sonwidget.h"
                    #include <QPushButton>

                    class Widget : public QWidget   //������Widget
                    {
                        Q_OBJECT

                    public:
                        Widget(QWidget *parent = nullptr);
                        ~Widget();
                        SonWidget *sonwindow;   //���ඨ�����ര��ָ�룬���ڹ��캯��newһ�����ڡ�
                        QPushButton *fbutton;   //�����ڵİ�ť�����ã�����֮�����ظ����ڣ���ʾ�Ӵ��ڣ�������ʾ�Ӵ��ڿ���ͨ��QObject��ʾ���ര�ڣ�

                    public slots:
                        //����ۺ����������ť�����ź�
                        void button_cb();
                        //�ٶ���һ���ۺ��������ڽ��յ��Ӵ����źź������
                        void signal_cb(int a);
                    };
                    #endif // WIDGET_H

                sonwidget.cpp:
                    #include "sonwidget.h"

                    SonWidget::SonWidget(QWidget *parent):QWidget{parent}
                    {
                        //�Ӵ��ڵİ�������
                        sbutton = new QPushButton("�����Ӵ��ڣ���ʾ������",this);

                        //���Ӵ��ڵĹ��캯�����ô��ڲ���
                        this->setWindowTitle("�Ӵ���");

                        //�Ӵ�������:����������ര�ڵİ�ť���ͷ���һ���źţ�Ȼ���ø����ڽ�������ź�
                        connect(sbutton,&QPushButton::clicked,this,&SonWidget::emit_mysignal);
                    }

                    void SonWidget::emit_mysignal()
                    {
                        //�����ť �ۺ��������ź�
                        emit show_hide_signal(10);
                    }

                widget.cpp:
                    #include "widget.h"
                    #include "QDebug"

                    Widget::Widget(QWidget *parent)
                        : QWidget(parent)
                    {
                        //���ø����ڵĴ��ڲ���
                        this->setWindowTitle("������");

                        //�������ര��
                        this->sonwindow = new SonWidget;
                        sonwindow->show();

                        //�����ڰ�ť�Ĺ���ʵ��
                        fbutton = new QPushButton;
                        fbutton->setText("���ظ����ڣ���ʾ�Ӵ���");
                        fbutton->setParent(this);


                        //���ø������ź��뱾���ڵİ����۵�����
                        connect(fbutton,&QPushButton::clicked,this,&Widget::button_cb);
                        //���ø��������Ӵ��ڷ��͵��ź� ������
                        connect(sonwindow,&SonWidget::show_hide_signal,this,&Widget::signal_cb);
                        //���ﲻ��emit_mysignal������show_hide_signal,�Ӵ��ڷ����źŵĺ�����show_hide_signal��
                    }

                    Widget::~Widget()
                    {
                    }

                    void Widget::button_cb()
                    {
                        //������������
                        this->hide();
                        //��ʾ�Ӵ���(�ҵ��Ӵ��ڣ��ٵ����Ӵ��ڵ�show��ʾ)
                        this->sonwindow->show();
                    }

                    void Widget::signal_cb(int a)
                    {
                        //��ӡ���յ����ź�a
                        qDebug() << a;
                        //��ʾ������,�����Ӵ���
                        this->show();
                        this->sonwindow->hide();
                    }

                5.3.3 �Զ����źŲ���Ҫע�������
                    * ������ �� �����߶���Ҫ��QObject������(��Ȼ���ۺ�����ȫ�ֺ�����Lambda ���ʽ����������ߵ�ʱ�����);
                    * �źźͲۺ�������ֵ�� void
                    * �ź�ֻ��Ҫ����������Ҫʵ��
                    * �ۺ�����Ҫ����Ҳ��Ҫʵ��
                    * �ۺ�������ͨ�ĳ�Ա��������Ϊ��Ա���������ܵ�public��private��protected ��Ӱ��;
                    * ʹ��emit ��ǡ����λ�÷����ź�;
                    * ʹ��connect()���������źźͲۡ�
                    * �κγ�Ա������static ������ȫ�ֺ�����Lambda ���ʽ��������Ϊ�ۺ���
                    * �źŲ�Ҫ���źźͲ۵Ĳ���һ�£���νһ�£��ǲ�������һ�¡�
                    * ����źźͲ۵Ĳ�����һ�£����������ǣ��ۺ����Ĳ������Ա��źŵ��٣�������ˣ��ۺ������ڵ���Щ������˳��Ҳ������źŵ�ǰ�漸��һ��������������Ϊ��������ڲۺ�����ѡ������źŴ��������ݣ�Ҳ���ǲۺ����Ĳ������źŵ��٣�

            5.4 �źŲ۵���չ
                * һ���źſ��ԺͶ��������
                    ����������������Щ�ۻ�һ����һ���ı����ã����� ���ǵĵ���˳���ǲ�ȷ���ġ�
                * ����źſ������ӵ�һ����
                    ֻҪ����һ���źŷ���������۾ͻᱻ���á�
                * һ���źſ������ӵ������һ���ź�
                    ����һ���źŷ���ʱ���ڶ����źű���������ʼ֮�⣬�����ź�-�źŵ���ʽ���ź�-�۵���ʽû��ʲô����
                * �ۿ��Ա�ȡ������
                    ������������������֣���Ϊ��һ������delete֮��Qt�Զ�ȡ���������ӵ������������Ĳ�
                * �źŲۿ��ԶϿ�
                    ����disconnect �ؼ��ֿ��ԶϿ��źŲ۵�����
                * ʹ��Lambda���ʽ
                    ��ʹ�� Qt 5 ��ʱ���ܹ�֧��Qt 5 �ı���������֧��Lambda���ʽ�ġ�
                    �������źźͲ۵�ʱ�򣬲ۺ�������ʹ��Lambda���ʽ�ķ�ʽ���д����������ǻ���ϸ����ʲô��Lambda���ʽ��

            5.5 Qt4�汾���źŲ�д��
                connect(zt,SIGNAL(hungry(QString)),st,SLOT(treat(QString)))

                ����ʹ���� SIGNAL�� SLOT �������꣬������������ת�������ַ�����ע�⵽connect()������signal��slot ���ǽ����ַ�����һ���������Ӳ��ɹ��������
                Qt4��û�б�������(��Ϊһ�ж����ַ������������ǲ�����ַ����Ƿ�ƥ��)������������ʱ�������������ɻ����ӳ���Ĳ��ȶ��ԡ�

                Qt5 ���﷨����ȫ���� Qt4������֮�ǲ����Եġ�

                Qt5д����
                QObject::connect(&button,&QPushButton::clicked,&app,&QApplication::quit);
                �����ڼ��������Ƿ�ƥ�䡣Qt5 �У��κγ�Ա������static ������ȫ�ֺ����� Lambda ���ʽ��������Ϊ�ۺ�����

                Qt4д����
                QObject::connect(&button,SIGNAL(clicked()),&app, SLOT(quit()));
                Qt4��û�б�������(��Ϊһ�ж����ַ������������ǲ�����ַ����Ƿ�ƥ��)������SIGNAL�� SLOT������������ַ����Ƿ���ȷ������������ʱ��������

            5.6 Lambda ���ʽ
                c++ 11�е�Lambda���ʽ ���ڶ��岢���������ĺ��������Լ򻯱�̹��������ȿ�һ��Lambda���ʽ�Ļ������ɣ�
                [capture](parameters)mutable -> return-type
                {
                    statement
                }
                [�����������]�����������غ���������multable -> ����ֵ[������]
                1. �������������
                    []����ʶһ��Lambda�Ŀ�ʼ���ⲿ�ֱ�����ڣ�����ʡ�ԡ�������������Ǵ��ݸ��������Զ����ɵĺ���������Ĺ��캯���ġ�
                    �����������ֻ��ʹ����Щ������1ambdaΪֹʱLambda�������÷�Χ�ڿɼ��ľֲ�����(����Lambda�������this)���������������������ʽ:
                        * �ա�û��ʹ���κκ������������
                        * = ���������ڿ���ʹ��Lambda�������÷�Χ�����пɼ��ľֲ�����(����Lambda�������this,������ֵ���ݷ�ʽ(�൱�ڱ������Զ�Ϊ���ǰ�ֵ���������оֲ�����)��
                        * & ���������ڿ���ʹ��Lambda�������÷�Χ�����пɼ��ľֲ�����(����Lambda �������this)�����������ô��ݷ�ʽ(�൱�ڱ������Զ�Ϊ���ǰ����ô��������оֲ�����)��
                        * this���������ڿ���ʹ��Lambda�������еĳ�Ա������
                        * a����a��ֵ���д��ݡ���ֵ���д���ʱ���������ڲ����޸Ĵ��ݽ�����a�Ŀ�������ΪĬ������º�����const�ġ�Ҫ�޸Ĵ��ݽ�����a�Ŀ������������mutable���η���
                        * &a����a�����ý��д��ݡ�
                        * a,&b����a��ֵ���д��ݣ�b�����ý��д��ݡ�
                        * =,&a��&b����a��b�����ý��д����⣬������������ֵ���д��ݡ�
                        * &,a,b����a��b��ֵ���д����⣬���������������ý��д���

                2.���������غ�������;
                    ��ʶ���ص�()�������Ĳ�����û�в���ʱ���ⲿ�ֿ���ʡ�ԡ���������ͨ����ֵ(��:(a.b))�� ������(��:(&a.&b))���ַ�ʽ���д��ݡ�
                3.���޸ı�ʾ����
                    mutable�������ⲿ�ֿ���ʡ�ԡ���ֵ���ݺ����������ʱ������mutable���η��󣬿����޸İ�ֵ���ݽ����Ŀ���(ע�������޸Ŀ�����������ֵ����)��
                4.��������ֵ
                    ->����ֵ���ͣ���ʶ��������ֵ�����ͣ�������ֵΪvoid,���ߺ�������ֻ��һ��return �ĵط�����ʱ�����������Զ��ƶϳ�����ֵ���ͣ�ʱ���ⲿ�ֿ���ʡ�ԡ�
                5.�Ǻ����壺
                    {}����ʶ������ʵ�֣��ⲿ�ֲ���ʡ�ԣ������������Ϊ�ա�
*/
// QMainWindow
/*
    �塢QMainWindow��֮ǰѧ����QWidget��ʲô��������һ�����ڽ��棩
        QMainWindow��һ��Ϊ�û��ṩ�����ڳ�����࣬����һ���˵���(menu bar)�����������(tool bars)�����í�Ӳ���(dock widgets)��һ��״̬��(status bar)��һ�����Ĳ���(central widget)
        �����Ӧ�ó���Ļ��������ı��༭����ͼƬ�༭���ȡ�
    5.1 �˵���

    5.2 ������
        �����ڵĹ������Ͽ����ж����������ͨ������һ���˵���Ӧһ���������ķ�ʽ��Ҳ���Ը�����Ҫ���й������Ļ��֡�
        ������������
            #include <QToolBar>
            QToolBar->QToolBar(QWidget *parent = Q_NULLPTR)
        ��ӹ�����
            QMainWindow -->
                void addToolBar(QToolBar *toolbar)
                void addToolBar(Qt::ToolBarArea area,QToolBar *toolbar)
                    Qt::LeftToolBarArea �����ʾ
                    Qt::RightToolBarArea �ұ���ʾ
        ����
                #include "mainwindow.h"
                #include <QMenuBar>
                #include <QMenu>
                #include <QAction>
                #include <QToolBar>

                MainWindow::MainWindow(QWidget *parent)
                    : QMainWindow(parent)
                {
                    //���ִ��˵����͹������Ľ����ǲ���ֱ����ʾ�ģ������Ҫ��ʾ�˵����͹�����,����Ҫ������ȡ������
                    //ȡ���˵�����
                    QMenuBar *menubar1 = this->menuBar();
                    //��˵������ �˵�
                    QMenu *filemenu = menubar1 ->addMenu("�ļ�");
                    QMenu *fileedit = menubar1 ->addMenu("�༭");
                    //��˵�����Ӳ˵���
                    QAction *openaction = filemenu->addAction("��");//�˵����ķ�����QAction*���ͣ�

                    filemenu ->addSeparator(); //��ӷָ���
                    QAction *saveaction = filemenu->addAction("����");

                    //��ȡ������
                    QToolBar *toolbar = this->addToolBar("");
                    //�򹤾�������ӹ��ߣ���Ӳ˵��
                    toolbar->addAction(openaction);
                    toolbar->addAction(saveaction);


                }

                MainWindow::~MainWindow()
                {
                }

        5.3 ״̬��
                ����
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
                            //���ִ��˵����͹������Ľ����ǲ���ֱ����ʾ�ģ������Ҫ��ʾ�˵����͹�����,����Ҫ������ȡ������
                            //ȡ���˵�����
                            QMenuBar *menubar1 = this->menuBar();
                            //��˵������ �˵�
                            QMenu *filemenu = menubar1 ->addMenu("�ļ�");
                            QMenu *fileedit = menubar1 ->addMenu("�༭");
                            //��˵�����Ӳ˵���
                            QAction *openaction = filemenu->addAction("��");//�˵����ķ�����QAction*���ͣ�

                            filemenu ->addSeparator(); //��ӷָ���
                            QAction *saveaction = filemenu->addAction("����");

                            //��ȡ������
                            QToolBar *toolbar = this->addToolBar("");
                            //�򹤾�������ӹ��ߣ���Ӳ˵��
                            toolbar->addAction(openaction);
                            toolbar->addAction(saveaction);

                            //ȡ��״̬��
                            QStatusBar *status = this ->statusBar();
                            status->addWidget(new QLabel("״̬"));//���һ���µı�ǩ,��״̬����ӿؼ�
                        }

                        MainWindow::~MainWindow()
                        {
                        }

        5.4 í�ӿؼ�
            �൱�����ǵ��������ڣ�һЩ�������򴰿��޸�λ�ã������һ����������

            QDockWidget��Ҳ�Ƹ������ڣ������ж����
            ����í�Ӳ���:
                QDockWidget -->
                    QDockWidget (const QString &title, QWidget *parent = Q_NULLPTR)
            ���í�Ӳ���:
                QMainWindow-->
                    void addDockWidget(Qt::DockWidgetArea area��QDockWidget *dockwidget)
                        Qt::LeftDockWidgetArea ���
                        Qt::RightDockWidgetArea�ұ�
                        Qt::TopDockWidgetArea  �ϱ�
                        Qt::BottomDockWidgetArea�±�

        5.5 ���Ĳ��������Ĳ�����
            �������ϼ���������������ʾ�Ĳ�����������Ϊ���Ĳ���������һ�����±��ļ����������� QTextEdit �����Ĳ���

            ������Ĳ���:
                QMainWindow -->void setCentralWidget(QWidget *widget)

            QTextEdit *edit = new QTextEdit("�ı��༭��"��this);
            this->setCentralwidget(edit);

            ����
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
                        //���ִ��˵����͹������Ľ����ǲ���ֱ����ʾ�ģ������Ҫ��ʾ�˵����͹�����,����Ҫ������ȡ������
                        //ȡ���˵�����
                        QMenuBar *menubar1 = this->menuBar();
                        //��˵������ �˵�
                        QMenu *filemenu = menubar1 ->addMenu("�ļ�");
                        QMenu *fileedit = menubar1 ->addMenu("�༭");
                        //��˵�����Ӳ˵���
                        QAction *openaction = filemenu->addAction("��");//�˵����ķ�����QAction*���ͣ�

                        filemenu ->addSeparator(); //��ӷָ���
                        QAction *saveaction = filemenu->addAction("����");

                        //��ȡ������
                        QToolBar *toolbar = this->addToolBar("");
                        //�򹤾�������ӹ��ߣ���Ӳ˵��
                        toolbar->addAction(openaction);
                        toolbar->addAction(saveaction);

                        //ȡ��״̬��
                        QStatusBar *status = this ->statusBar();
                        status->addWidget(new QLabel("״̬"));//���һ���µı�ǩ,��״̬����ӿؼ�

                        //����í�Ӳ���
                    //    QDockWidget * dockwidget = new QDockWidget("����һ��í�Ӳ���",this);
                    //    this->addDockWidget(Qt::TopDockWidgetArea,dockwidget);  //������������ӵ�mainwindow

                        //�������Ŀؼ�
                        QTextEdit *edit = new QTextEdit("�ı��༭��",this);  //�½���һ���ı��༭������ȡ��������ָ��������
                        this->setCentralWidget(edit);   //���ı��༭������Ϊ���Ŀؼ���

                    }

                    MainWindow::~MainWindow()
                    {
                    }

            5.6 ��Դ�ļ�
                Qt ��Դϵͳ ��һ����ƽ̨����Դ����,���ڽ���������ʱ����Ҫ����Դ �Զ����Ƶ���ʽ�洢�ڿ�ִ���ļ��ڲ���
                �����ĳ�����Ҫ�����ض�����Դ(ͼ�ꡢ�ı������)����ô�������������Դ�ļ��У�����Ҳ����Ҫ������Щ�ļ��Ķ�ʧ��
                Ҳ����˵������㽫 ��Դ �� ��Դ�ļ���ʽ�洢�����ǻ���뵽��ִ���ļ��ڲ���
                ʹ�� QtCreator ���Ժܷ���ش�����Դ�ļ������ǿ����ڹ����ϵ��Ҽ���ѡ��������ļ����������� Qt �������ҵ���Qt ��Դ�ļ���:

            ��ӹ��̣�������ļ� - �� Qt -��Qt Resource file -> ���ǰ׺ -�� ����ļ�
            ע�⣺��Դ�ļ�ֻ�������Ŀ�ļ�������ļ�
            ���Ҫʹ�ã�ѡ���ļ� �Ҽ� ������Դ·���������塣

            ��ϸ������ĵ���
            ����

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
                        //���ִ��˵����͹������Ľ����ǲ���ֱ����ʾ�ģ������Ҫ��ʾ�˵����͹�����,����Ҫ������ȡ������
                        //ȡ���˵�����
                        QMenuBar *menubar1 = this->menuBar();
                        //��˵������ �˵�
                        QMenu *filemenu = menubar1 ->addMenu("�ļ�");
                        QMenu *fileedit = menubar1 ->addMenu("�༭");
                        //��˵�����Ӳ˵���
                        QAction *openaction = filemenu->addAction("��");//�˵����ķ�����QAction*���ͣ�

                        filemenu ->addSeparator(); //��ӷָ���
                        QAction *saveaction = filemenu->addAction("����");

                        //��ȡ������
                        QToolBar *toolbar = this->addToolBar("");
                        //�򹤾�������ӹ��ߣ���Ӳ˵��
                        toolbar->addAction(openaction);
                        toolbar->addAction(saveaction);

                        //ȡ��״̬��
                        QStatusBar *status = this ->statusBar();
                        status->addWidget(new QLabel("״̬"));//���һ���µı�ǩ,��״̬����ӿؼ�

                        //����í�Ӳ���
                    //    QDockWidget * dockwidget = new QDockWidget("����һ��í�Ӳ���",this);
                    //    this->addDockWidget(Qt::TopDockWidgetArea,dockwidget);  //������������ӵ�mainwindow

                        //�������Ŀؼ�
                        QTextEdit *edit = new QTextEdit("�ı��༭��",this);  //�½���һ���ı��༭������ȡ��������ָ��������
                        this->setCentralWidget(edit);   //���ı��༭������Ϊ���Ŀؼ���

                        //:/new/prefix1/a.bmp
                        //��ָ���Ĳ˵���������ͼƬ
                        //����ͼƬ�ؼ�
                        QPixmap pix;    //����һ��ͼƬ����
                        //ѡ��ͼƬ
                        pix.load(":/new/prefix1/a.bmp");    //��ͼƬ���� ����ͼƬ
                        //���˵�������ͼƬ
                        openaction->setIcon(QIcon(pix));  //��pixͼƬ����QIcon��Դ�����˵���Ĵ򿪣�����һ����Դ ��setIcon(����ͼ��)

                    }

                    MainWindow::~MainWindow()
                    {
                    }


*/
//�����Ի���QDialog
/*
    6.1 ��������
        �Ի�����GUI�����в��ɻ�ȱ����ɲ��֡��ܶ಻�� ����
   ���ʺϷ��������ڵĹ��������������ڶԻ��������á�
        �Ի���ͨ������һ�����㴰�ڣ������ڳ������ϲ㣬����ʵ�ֶ���������߼���
   �û�������

        Qt�� ʹ�� QDialog�� ʵ�ֶԻ��򡣾���������һ��������ͨ�������һ����̳�
   QDialog�� QDialog(�������࣬�Լ����� Qt::Dialog���͵���)�Ķ����� parent
   ָ�붼�ж���Ľ���: ��� parent Ϊ NULL����öԻ������Ϊһ�����㴰�ڣ�����
   ����Ϊ�丸������ӶԻ���(��ʱ����Ĭ�ϳ��ֵ�λ����parent�����ģ�
        ���㴰����Ƕ��㴰�ڵ��������ڣ����㴰���������������Լ���λ�ã����Ƕ��㴰����Ṳ���丸�����λ�á�

        �Ի����Ϊģ̬�Ի���ͷ�ģ̬�Ի���
            * ģ̬�Ի��򣬾��ǻ�����ͬһӦ�ó������������ڵ����롣
              ģ̬�Ի���ܳ��������硰���ļ������ܡ�����Գ���һ�¼��±��Ĵ��ļ��������ļ��Ի������ʱ�������ǲ��ܶԳ��˶Ի���֮��Ĵ��ڲ��ֽ��в����ġ�
            * ����෴���Ƿ�ģ̬�Ի���������ҶԻ������ǿ�������ʾ�Ų��ҶԻ����ͬʱ,�����Լ��±������ݽ��б༭��

    6.2 ��׼�Ի���
        ��ν��׼�Ի�����Qt���õ�һϵ�жԻ������ڼ򻯿�������ʵ�ϣ��кܶ�Ի�����ͨ�õģ�
        ������ļ���������ɫ����ӡ���õȡ���Щ�Ի��������г����м�����ͬ�����û�б�Ҫ��ÿһ�������ж��Լ�ʵ����ôһ���Ի���
        Qt�����öԻ�����·�Ϊ���¼���:
            QColorDialog:               ѡ����ɫ
            QFileDialog:                ѡ���ļ�����Ŀ¼
            QFontDialog:                ѡ������
            QInputDialog:               �����û�����һ��ֵ��������ֵ����
            QMessageBox:                ģ̬�Ի���������ʾ��Ϣ��ѯ�������
            QPageSetupDialog:           Ϊ��ӡ���ṩֽ����ص�ѡ��
            QPrintDialog                ��ӡ������
            QPrintPreviewDialog         ��ӡԤ��
            QProgressDialog             ��ʾ��������

        ����
                #include "widget.h"
                #include <QFileDialog>
                #include <QString>
                #include <QDebug>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    this->resize(600,400);
                    button  = new QPushButton("ѡ���ļ�",this);
                    button->resize(100,100);
                    button -> move(300,100);
                    connect(button,&QPushButton::clicked,this,[](){
                        //�����˰�ť��ʱ�򣬵����Ի��򣬷����ļ�������
                        //��ȡһ���ļ������֡�
                //        QString str = QFileDialog::getOpenFileName();
   //��仰����һ���Ի���Ȼ����ѡ���ļ���str�ͱ������ļ��ľ���·����
                //        qDebug() << str;    //���ʹ�ӡ��ѡ����ļ������֡�

                        //��Ҫ��ӡ����ļ��������Ϊ���ļ��б� ��Names
                        QStringList str = QFileDialog::getOpenFileNames();
   //��仰����һ���Ի���Ȼ����ѡ���ļ���str�ͱ������ļ��ľ���·���� qDebug()
   << str;    //���ʹ�ӡ��ѡ����ļ������֡�
                    });
                }

                Widget::~Widget()
                {
                }


    6.3 �Զ�����Ϣ��
        6.3.1 ģ̬�Ի���
            * Qt�����ּ����ģ̬�Ի���
                * Ӧ�ó��򼶱��ģ̬
                    ������ģ̬�ĶԻ������ʱ���û��������ȶԵĶԻ�����н�����ֱ���رնԻ���Ȼ����ܷ��ʳ����������Ĵ��ڡ�
                * ���ڼ����ģ̬
                    ��ģ̬����������Ի�������Ĵ��ڣ�������Ȼ�����û���������������ڽ��������ڼ����ģ̬�������öര��ģʽ��
                һ��Ĭ����Ӧ�ó��򼶱��ģ̬��

                �������ʾ���У����ǵ�����exec()���Ի�����ʾ��������������һ��ģ̬�Ի��򡣵��Ի������ʱ�����ǲ����������ڽ����κν�����ֱ�����ǹر��˸öԻ���
                    QDialog dialog;
                    dialog.setWindowTitle(tr("Hello,dailog!"));
                    dialog.exec();

        6.3.2 ��ģ̬�Ի���
            �����������Ž�exec()�޸�Ϊshow()��������ģ̬�Ի���
                    QDialog dialog(this);
                    dialog.setWindowTitle(tr("Hello,dialog!"));
                    dialog.show();
                �ǲ�������ԸΥ���Ի���һ��������������Ϊshow()��������������ǰ�̣߳��Ի������ʾ�ǲ�������ԸΥ?�Ի���Ȼһ������!������Ϊ��show()��������������ǰ�̣߳��Ի������ʾ������
                Ȼ�����������أ��������ִ�С�ע�⣬dialog�ǽ�����ջ�ϵģ�show()�������أ�MainWindow::open()����������dialog������������������˶Ի�����ʧ�ˡ�
            ֪����ԭ��ͺø����ǽ� dialog �ĳɶ��Ͻ�������Ȼ��û�����������:
                    QDialog *dialog=new QDialog;
                    dialog->setWindowTitle(tr("Hello, dialog!"));
                    dialog->show();
            ������㹻ϸ�ģ�Ӧ�÷�������Ĵ������������:dialog�����ڴ�й¶!dialog
   ʹ�� �Ϸ���ռ䣬ȴһֱû�� delete���������Ҳ�ܼ�:�� NainWindow ��ָ�븳��
   dialog ���ɡ� ���ǵ�����֮ǰ˵��Qt�Ķ���ϵͳ��
            ��������������һ�����⣺������ǵĶԻ�������һ���������г����أ�����QWidget
   ��parent������QWidgetָ�룬�Ǿ����������ǲ��ܽ�һ����ͨ��C++��ָ�봫��Qt�Ի���
            ���⣬������ڴ�ռ�����ϸ����ƵĻ��������ǽ���������Ϊparentʱ�������ڲ��رգ��Ի���Ͳ��ᱻ���٣����Ի�һֱռ���ڴ档
            ����������£����ǿ�������dialog��WindowAttribute:
                QDialog *dialog = new QDialog;
                dialog->setAttribute(Qt::WA_DeleteOnClose);
                dialog->setWindowTitle(tr("Hello,dialog!"));
                dialog->show();
            setAttribute()�������öԻ���ر�ʱ���Զ����ٶԻ���


�Ի������ӣ�
    widget.cpp:
                #include "widget.h"
                #include <QFileDialog>
                #include <QString>
                #include <QDebug>

                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                {
                    this->resize(600,400);
                    button  = new QPushButton("ѡ���ļ�",this);
                    button->resize(100,100);
                    button -> move(300,100);
                    connect(button,&QPushButton::clicked,this,[](){
                        //�����˰�ť��ʱ�򣬵����Ի��򣬷����ļ�������
                        //��ȡһ���ļ������֡�
                //        QString str = QFileDialog::getOpenFileName();   //��仰����һ���Ի���Ȼ����ѡ���ļ���str�ͱ������ļ��ľ���·����
                //        qDebug() << str;    //���ʹ�ӡ��ѡ����ļ������֡�

                        //��Ҫ��ӡ����ļ��������Ϊ���ļ��б� ��Names
                        QStringList str = QFileDialog::getOpenFileNames();   //��仰����һ���Ի���Ȼ����ѡ���ļ���str�ͱ������ļ��ľ���·����
                        qDebug() << str;    //���ʹ�ӡ��ѡ����ļ������֡�
                    });

                    //����button1
                    button1  = new QPushButton("ģ̬�Ի���ť",this);
                    button1->resize(100,100);
                    button1 -> move(300,200);
                    connect(button1,&QPushButton::clicked,this,[](){
                        //�ٴ���һ���Ի���
                        QDialog dialog;
                        //���öԻ���ı���
                        dialog.setWindowTitle(tr("Hello,dailog!"));
                        //�����Ի���
                        dialog.exec();
                    });

                    //����button2
                    button2  = new QPushButton("��ģ̬�Ի���ť",this);
                    button2->resize(100,100);
                    button2 -> move(400,200);
                    connect(button2,&QPushButton::clicked,this,[](){
                        //�ٴ���һ���Ի���
                        QDialog *dialog = new QDialog;

                        //�����Ҫ�öԻ����Զ��ͷţ�
                        dialog->setAttribute(Qt::WA_DeleteOnClose); //��Ҫһ���꣬�رմ��ڵ�ʱ�򣬻��Զ��ͷ��ڴ�

                        //���öԻ���ı���
                        dialog->setWindowTitle(tr("��ģ̬,dailog!"));
                        //�������Ի���
                        dialog->show(); //�ڶ������ٹ�Ȼ���Ա�������������Զ����٣�����֮��û���ֶ����ٸÿռ䣬���ڴ�й¶
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
                    QPushButton *button;    //��׼�Ի���ť�������˰�ť��ʱ�򣬵����Ի��򣬷����ļ�������
                    QPushButton *button1;   //ģ̬�Ի���ť
                    QPushButton *button2;   //��ģ̬�Ի���ť


                };
                #endif // WIDGET_H


        6.4 ��Ϣ�Ի���
            QMessageBox������ʾ��Ϣ��ʾ������һ���ʹ�����ṩ�ļ���static ����:
            * ��ʾ���ڶԻ���
                void about(QWidget * parent, const QString &title, const QString &text)
            ����һ����򵥵ĶԻ���������� title��������text����������parent���Ի���ֻ�и�OK��ť��
            * ��ʾ���� Qt �Ի��򡣸öԻ���������ʾ�й� Qt ����Ϣ��
                void aboutQt(QWidget *parent, const QString &title = QString()):
            * ��ʾ���ش���Ի���
                StandardButton critical(QWidget *parent,const QString &title,const QString &text,StandardButtons buttons = Ok,StandardButton defaultButton = NoButton);
            ����Ի�����ʾһ����ɫ�Ĵ�����š����ǿ���ͨ��buttons ����ָ������ʾ�İ�ť��Ĭ�������ֻ��һ��ok ��ť�����ǿ���ʹ��StandardButtons ����ָ�����ְ�ť��
            * ��QMessageBox::critical()���ƣ���֮ͬ����������Ի����ṩһ����ͨ��Ϣͼ�ꡣ
                StandardButton information(QWidget * parent,const QString & title,const OString & text,StandardButtons buttons = Ok��StandardButton defaultButton = NoButton)
            * ��QMessageBox::critical()���ƣ���֮ͬ����������Ի����ṩһ���ʺ�ͼ�꣬��������ʾ�İ�ť�ǡ��ǡ��͡���
            StandardButton question(QWidget* parent,const QString & title,const QString & text,StandardButtons buttons = StandardButtons( Yes | No ),StandardButton defaultButton= NoButton)
            * ��QMessageBox::critical()���ƣ���֮ͬ����������Ի����ṩһ����ɫ̾��ͼ�ꡣ
            StandardButton warning(QWidget * parent,const QString &fitle��const OString & text��StandardButtons buttons = Ok,StandardButton defaultButton = NoButton)

            ���ǿ���ͨ������Ĵ�������ʾ�����ʹ�� QessageBox��
                if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"), tr(" Are you OK?"), QMessageBox::Yes |QMessageBox::No,QMessageBox::Yes))
                {
                    QMessageBox::information(this, tr("Hmmm..."),tr("I'm glad to hear that!"));
                }
                else
                {
                    QMessageBox::information(this, tr("Hmmm..."),tr("I'm sorry!"));
                }
                ����ʹ��QMessageBox::question()��ѯ��һ�����⡣
                * ����Ի���ĸ�������this.
                    QMessageBox��QDialog�����࣬����ζ�����ĳ�ʼ��ʾλ�ý�������parent���ڵ�����
                * �ڶ��������ǶԻ���ı���



*/
//�ߡ����ֹ�����
/*
7.���ֹ�����
    ��ν GUI���棬�����ף����� һ������ĵ��ӡ����Ǵ���һ�����ڣ��Ѱ�ť�����棬��ͼ������棬�����ͳ���һ�����档
    �ڷ���ʱ�������λ��������Ҫ�����Ǳ���Ҫָ�������������Ա㴰���ܹ�����������Ҫ�ķ�ʽ������Ⱦ������漰�������λ�Ļ��ơ�

    Qt �ṩ�����������λ����:���Զ�λ�Ͳ��ֶ�λ��
        * ���Զ�λ����һ����ԭʼ�Ķ�λ����:����������������ͳ���ֵ��������Qt��֪���ð�������������Լ������������Ĵ�С��
            ����������������һ�������ǣ�����û��ı��˴��ڴ�С����������󻯰�ť����ʹ������϶����ڱ�Ե�����þ��Զ�λ������ǲ������κ���Ӧ�ġ�
            ��Ҳ����Ȼ����Ϊ�㲢û�и���Qt���ڴ��ڱ仯ʱ������Ƿ�Ҫ�����Լ��Լ���θ��¡����ߣ����и��򵥵ķ���:��ֹ�û��ı䴰�ڴ�С�������ܲ��ǳ�Զ֮�ơ�

        * ���ֶ�λ:��ֻҪ���������ĳһ�ֲ��֣�������ר�ŵĲ��ֹ��������й�������Ҫ������С����λ�õ�ʱ��Qtʹ�ö�Ӧ�Ĳ��ֹ��������е�����
            ���ֶ�λ�����Ľ����ʹ�þ��Զ�λ��ȱ�ݡ�

    Qt �ṩ�Ĳ���������������������õ�:
            * QHBoxLayout:����ˮƽ��������Ҳ���:
            * QVBoxLayout:������ֱ������ϵ��²���:
            * QGridLayout:��һ�������н��в��֣�������HTML��table:

    7.1 ϵͳ�ṩ�Ĳ��ֿؼ�
        vertical Layout
        Horizontal Layout
        Grid Layout
        Form Layout
        ���ĸ���ϵͳ�������ṩ�Ĳ��ֵĿؼ�������ʹ���������Ƿǳ���������Ͳ���ϸ�����ˡ�

    7.2 ���� widget������
        �ڶ��ֲ��ַ�ʽ�����ÿؼ����widget�������� ����Containers��

    ע�⣺
        * �γ�ui�еİ�ť����������·�����⣬ui�������Դ������·���������Makefile���ļ���·���������Դû������Ŀ�£���.exe��ִ���ļ���ִ��ʱ���ܻ��Ҳ�����Դ�����ز��������������ð���Դ�Ϳ�������Ŀ·���¡�

        * ���ң����ڰ�ť�� �ź���ۣ����ڰ�ť�����Ҽ���Ȼ����ת���ۣ���ѡ���źţ��ͻ���ת��widget.cpp��clicked�ۺ���,����ֱ���ں�������ȥʵ�ֹ��ܼ��ɣ�
          ���ﲻ��Ҫʹ��connect�������ӵ�ԭ���ǣ����ļ�build�ļ����棬��һ��ui_widget.h�ļ���������һ�仰��QMetaObject::connectSlotsByName(Widget); ������������� ���Զ�������Ŀؼ�������Ȼ���Զ������˲ۺ�����������������Ǹ����������������Ӱ�ť�Ͳۺ����Ĳ�����

    ���·�����������qt�����У������е����·����������makefile��
            ������ֶ����У������е����·����������.exe�Ŀ�ִ�г���
*/
//�ˡ����ÿؼ�
/*
�ˡ����ÿؼ�
    Qt Ϊ����Ӧ�ó�����濪���ṩ��һϵ�еĿؼ����������ǽ����������һЩ�ؼ������пؼ���ʹ�÷������Ƕ�����ͨ�������ĵ���ȡ��

    8.1 QLabel�ؼ�ʹ��
        QLabel��������õĿؼ�֮һ���书�ܺ�ǿ�����ǿ���������ʾ�ı���ͼƬ�Ͷ����ȡ�
        8.1.1��ʾ����(��ͨ�ı���html)
        ͨ�� QLabel��� setText ����������ʾ������:
            void setText(const QString &)
        * ������ʾ��ͨ�ı��ַ���
            QLable *label = new QLable;
            label->setText("Hello. World!");
        * ������ʾ HTML��ʽ���ַ���
            ������ʾһ������:
                QLabel *label= new QLabel(this);
                label ->setText("Hello, World");
                label ->setText("<hl><ahref=\"https://www.baidu.com\">�ٶ�-��</a><hl>");
                label ->setOpenExternalLinks(true);
        ���� setOpenExternalLinks()���������������û��������֮���Ƿ��Զ������ӣ��������ָ��Ϊ true ����Զ��򿪡�

    8.1.2 ��һ��ͼƬ
    8.1.3 ��һ��gif��̬ͼ
        ����
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
                //    label -> setText("����һ����ǩ");
                    label -> setText("<h1><a href=\"https://www.baidu.com\">�ٶ�һ��</a></h1>"); //a ��ʾ�����ӣ���ʾ���ı��ǡ��ٶ�һ�¡�
                    label -> setOpenExternalLinks(true);    //���ã�������� ������ת

                    label_pic = new QLabel(this);
                    label_pic->resize(300,200);
                    label_pic->move(200,200);
                //    label -> setText("����һ����ǩ");
                    label_pic -> setPixmap(QPixmap("../02untitled/picture/1.jpg"));
                    //����һ������Ӧ��С��
                    label_pic -> setScaledContents(true);

                    label_move = new QLabel(this);
                    label_move->resize(100,100);
                    label_move->move(300,200);

                    QMovie *move = new QMovie("../02untitled/picture/1.gif");
                    label_move->setMovie(move);
                    label_move->setScaledContents(true);
                    move->start();  //����

                }

                Widget::~Widget()
                {
                }


    8.2 ���û�ȡ�б༭����
        8.2.1 ����/��ȡ����
            * ��ȡ�༭������ʹ��text()�������������£�
                QString text() const
            * ���ñ༭������
                void setText(const QString &)
        ��;
            #include "widget.h"
            #include "ui_widget.h"
            #include <QDebug>
            Widget::Widget(QWidget *parent)
                : QWidget(parent)
                , ui(new Ui::Widget)
            {
                ui->setupUi(this);
                ui->lineEdit->setText("hello"); //�����б༭������
            }

            Widget::~Widget()
            {
                delete ui;
            }


            void Widget::on_lineEdit_returnPressed()
            {
                qDebug() << ui->lineEdit->text(); //��ȡ�б༭������
            }


        8.2.2 ������ʾģʽ
            ʹ��QLineEdit���setEchoMode()���������ı�����ʾģʽ������������
                void setEchoMode(EchoMode mode)
            EchoMode ��һ��ö�����ͣ�һ��������������ʾģʽ
                * QLineEdit::Normal ģʽ��ʾ��ʽ�����������������ʾ
                * QLineEdit::NoEcho ����ʾ�κ����ݣ���ģʽ���޷������û������롣
                * QLineEdit::Password ����ģʽ��������ַ������ƽ̨ת��Ϊ�����ַ�
                * QLineEdit::PasswordEchoOnEdit �༭ʱ��ʾ�ַ�������ʾ�ַ���Ϊ���롣
            ���⣬������ʹ��QLineEdit ��ʾ�ı���ʱ��ϣ�����������һ�οհ׵�������ô���Ϳ���ʹ��QLineEdit�������ṩ�ģ�setTextMargins������
                void setTextMargins(int left,int top,int right,int botton)
            �ô˺�������ָ����ʾ���ı���������������ұ߽�ļ������������
        ����
        �����б༭������ģʽ��
                #include "widget.h"
                #include "ui_widget.h"
                #include <QDebug>
                Widget::Widget(QWidget *parent)
                    : QWidget(parent)
                    , ui(new Ui::Widget)
                {
                    ui->setupUi(this);
                    //������ʾģʽ
                    ui->lineEdit->setEchoMode(QLineEdit::Password); //��ʾΪ����ģʽ
                    ui->lineEdit->setTextMargins(80,0,0,0);    //���ü�ࡣ �������������µ����ؿն��١�
                //    ui->lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);//����ʱ�ǿ��ӵģ�������ʱ�ǲ����ӵ�
                    ui->lineEdit->setText("hello"); //�����б༭������
                    //���ÿռ�������

                }

                Widget::~Widget()
                {
                    delete ui;
                }

                void Widget::on_lineEdit_returnPressed()
                {
                    qDebug() << ui->lineEdit->text(); //��ȡ�б༭������
                }

        8.3 �Զ���ؼ�
            �ڴ Qt���ڽ����ʱ����һ����Ŀ�кܶര�ڣ������Ǵ����е�ĳ��ģ��ᱻ�����Ե��ظ�ʹ�á�
            һ����������������Ƕ��Ὣ������ڻ���ģ���ó�������һ�������Ĵ����࣬�Ա��Ժ��ظ�ʹ�á�
            ��ʹ�� Qt��ui �ļ�������ʱ�򣬹����� ����ֻΪ�����ṩ�˱�׼�Ĵ��ڿؼ������������ʹ���Զ���ؼ���ô��?
            ����:���Ǵ�QTidget������һ����SmallWidget��ʵ����һ���Զ���Ի,
        8.4 ��ʱ��
            QTimer:��ʱ������

        ����
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
                    //���˶�ʱ�����������ö�ʱ���ĳ�ʱ�¼��������ʱ �ᷢ��һ����ʱ�źš�

                    //���ﶨʱ����ʱ��ͻ����������ӵ�Lambda���ʽ
                    connect(t,&QTimer::timeout,this,[](){
                        qDebug() << "timeout";
                    });
                    //��ʱ����������

                }

                Widget::~Widget()
                {
                    delete ui;
                }


                void Widget::on_pushButton_clicked()    //ui�����ӵĲۺ��������һ�ο�ʼ��Ȼ��ͻ������￪ʼ������ʱ��
                {
                    t->start(1000); //������ʱ���� 1000*1ms ��ʱһ�Σ���ʱһ�ξ͵��òۺ���
                }


                void Widget::on_pushButton_2_clicked()
                {
                    t->stop();  //ֹͣ��ʱ����
                }





*/
//�š�Qt��Ϣ���ƺ��¼�
/*
    9.1 �¼��������
        �¼�(event) ���� ϵͳ ���� Qt���� �ڲ�ͬ��ʱ�̷����ġ����û�������ꡢ���¼��̣������Ǵ�����Ҫ���»��Ƶ�ʱ�򣬶��ᷢ��һ����Ӧ���¼���

        һЩ�¼��ڶ��û�����������Ӧʱ������������¼���;��һЩ�¼�������ϵͳ�Զ����������ʱ���¼���

        �¼��������:
            1)�� Qt �ڲ���Qt ͨ�� QApplication:exec()���������¼�ѭ����ͣ��ץȡ�¼������е��¼���

            2)���¼�����ʱ��Qt������һ���¼�����Qt�������¼��඼�̳���QEvent.

            3)���¼����󴴽���Ϻ�Qt�� ����¼����� ���ݸ� QObject�� event()������ event()��������ֱ�Ӵ����¼�,���� �����¼���������� ���ɸ� �ض����¼�������(event hander)��event()������Ҫ�����¼��ķַ�:

            widget����
            QApplication::exec() //��ʱ��ѭ�� ����Ƿ����¼�����
            һ�����¼��������ͻ�����һ���¼�����
            ����
                ������¼� �ͻ����������
                �����¼�    �ͻ�������̶���
            �¼����󴴽���Ϻ� Qt���¼����󴫵ݸ�QObject�� event()����,����event���������¼���������ͷ��ɸ��ض����¼�������
            ����QWidget��������������麯��������Щ�麯��Ĭ�϶��ǿ�ʵ�֣���ˣ��ڲ����¼���ʱ������ֻ��Ҫ��д�麯�����ɡ�


    9.2 �����¼�����
        �����пؼ��ĸ��� QWidget��,�����˺ܶ��¼�����Ļص���������Щ�������� protected virtual �ģ�Ҳ����˵
        ���ǿ���������������ʵ����Щ������ʵ�ֺ��� Ҫ��ѭ�麯�����﷨�����Զ�������б�֤������������ ��һ���ԡ�

        9.2.1 ����¼�(QMouseEvent)
        ����ͼƬ��ο�:����ͼƬ\��03��\01����¼�

        �ο�����:code\day03\01 MouseEvent

        //��д������麯��

        protected:
        virtual void mousePressEvent(QMouseEvent*);//������¼�
        virtual void mouseReleaseEvent(QMouseEvent*); //���̧���¼�
        virtual void mouseDoubleClickEvent(QMouseEvent *); //���˫���¼�
        virtual void mouseMoveEvent(QMouseEvent*);//����ƶ��¼�

        9.2.2 �����¼���QWheelEvent��
            �ο�����:
            code\day03\02 QWheelEvent
            //virtual void wheelEvent(QWheelEvent*);//�����ֻ���

            //�����ֻ���
            void Widget::wheelEvent(QWheelEvent *e)
            {
                if(e->orientation()== Qt::Vertical)//��������Ǵ�ֱ
                {
                    QPoint point = e->angleDelta();
                    QString str = QString("���ִ�ֱ����(%1,%2)");
                    .arg(point.x()).arg(point.y());
                    ui->label->setText(str);
                }
            }

        9.2.3 �����¼���QKeyEvent��
        //virtual void keyPressEvent(QKeyEvent *); //���̰����¼�
        //virtual void keyReleaseEvent(QKeyEvent *); //����̧���¼�

        //���̰����¼�
        void Widget::keyPressEvent(QKeyEvent *e)
        {
            QString str;
        }

        9.2.4 ��С�ı��¼���QResizeEvent��
        //virtual void resizeEvent(QResizeEvent *); //��С�ı��¼�

        //��С�ı��¼�
        void Widget::resizeEvent(QResizeEvent *e)
        {
            //�仯ǰ�Ĵ��ڴ�С
            qDebug()<< "e->oldSize() =" << e->oldSize();

            //�仯��Ĵ��ڴ�С
            qDebug() << "e->size() =" << e->size();
        }

        9.2.5 �����뿪�����¼���enterEvent\leaveEvent��

        //virtual void enterEvent(QEvent *); //�����¼�
        //virtual void leaveEvent(QEvent *); //�뿪�¼�

*/
//ʮ��Qt��ͼ����
/*
 ʮ��Qt��ͼ����
    Qt�Ļ�ͼ���� Ϊ��Ļ��ʾ �� ��ӡ��ʾ �ṩ��ͳһ��AP|�ӿڣ���Ҫ�����������:QPainter �ࡢQPaintDevice��� QPaintEngine ��
    I QPainter �� �ṩ�˻�ͼ�����ĸ��ֽӿڣ��ɷ���ػ��Ƹ��ָ�����ͼ�Ρ�
    I QPaintDevice ���ṩ�����ڻ�ͼ�Ŀռ䣬����ͼ������
    I PaintEngine ���ǳ����࣬�ṩ�� QPainter �����ָ����ƽ̨�ϸ�ָ�����豸�滭�ĳ���ӿڣ��Կ����߶���, һ�㲻���õ���

    Qt�Ļ�ͼϵͳʵ�����ǣ�ʹ��QPainter ��QPainterDevice�Ͻ��л��ƣ�����֮��ʹ��QPaintEngine����ͨѶ��Ҳ���Ƿ���QPainter��ָ�


    qt�����е�ͼ���ǻ������ġ����簴ť ���� ��ǩ�ϵ�ͼ
    ��ͼ��Ҫ����������
        ���ң�
        QPainter

        ���壺
        QPainterDevice(�����Ŀؼ� ��ť label ����)

    һ�����ڸı��ˣ��ͻ������ͼ�¼���
    qwidget
    {
        void Widget::paintEvent(QPaintEvent *e); //��д�麯��
        ע�⣺��ͼ����������������滭��
    }

*/
//���»�ͼ
/*
    ����this�����update���»�ͼ
*/
//�ʼ���
//############################################################################
//������












#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}



