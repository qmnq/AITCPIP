/*
  1.1 简述
        “c++"中的++来自于c语言中的递增运算符++，该运算符将变量加 1。c++起初也叫"c with class",通过名称表明，c++
        是对C的扩展，因此 c++是c语言的超集，这意味着任何有效的c程序都是有效的 c++程序。c++程序可以使用己有
        的c程序库。

        库是编程模块的集合，可以在程序中调用它们。库对很多常见的编程问题提供了可靠的解决方法，因此可以节省
        程序员大量的时间和工作量。

        c++语言在c语言的基础上添加了面向对象编程和泛型编程的支持。c++继承了c语言高效，简洁，快速和可移植的
        传统。

        c++融合了3种不同的编程方式:
            c语言代表的  过程性语言
            c++在c语言基础上添加的 类 代表的 面向对象语言
            c++模板支持的 泛型编程。

            对于面向过程和面向对象：以做蛋炒饭为例
                面向过程：撒油，撒盐，放蛋，放饭等
                面向过程：先做一份饭，再做一个炒蛋，把炒蛋放到饭上。

        c语言和c++语言的关系:
        c++语言是在C语言的基础上，添加了 面向对象、模板 等现代程序设计语言的特性而发展起来的。两者无论是从语
        法规则上，还是从运算符的数量和使用上，都非常相似，所以我们常常将这两门语言统称为“C/C++"。

        C语言和C++并不是对立的竞争关系:
        1.C++是C语言的加强，是一种更好的C语言。
        2.C++是以C语言为基础的，并且完全兼容C语言的特性。

        c语言和 C++语言的学习是可以相互促进。学好c语言，可以为我们将来进一步地学习 C++语言打好基础，而 C++
        语言的学习，也会促进我们对于C语言的理解，从而更好地运用C语言。

    1.2 c++ 起源
        c++之父-本贾尼-斯特劳斯特卢普 20世纪80年代在贝尔实验室创建

*/

/*
    1.1.2
        存储相关关键子
        register、static、const、auto、 extern

        1、register 是 寄存器的意思，用 register 修饰的变量 是 寄存器变量
        （好处是 ： 运行的速率会更快。不用regester修饰的变量都是在内存中运行的，而内存中数据的运行效率是没有寄存器快的）

        即:在编译的时候告诉编译器这个变量是寄存器变量，尽量 将其存储空间分配在寄存器中。
        注意:
            (1):定义的变量 不一定 真的存放在寄存器中。            （若寄存器的空间不够使用，则不会放在寄存器当中的）
            (2):cPu取数据的时候去寄存器中拿数据比去内存中拿数据要快
            (3):因为寄存器比较宝贵，所以 不能定义寄存器数组        （尽量不要在寄存器当中定义变量）
            (4):register只能修饰 字符型及整型的，不能修饰浮点型    （寄存器当中不能存储 浮点型的变量）

                register char ch;
                register short int b;
                register int c;
                register float d;//错误的

            (5):因为register 修饰的变量可能存放在寄存器中，不存放在内存中，所以
                不能对寄存器变量取地址。因为 只有存放在内存中的数据 才有地址。

                register int a;
                int *p;
                p=&a://错误的 a 可能没有地址

        2、static 是静态的意思
            static 可以修饰全局变量、局部变量、函数
            (使用static 修饰的变量，此变量保存在 内存的 静态区空间 中)
            这个以后的课程中重点讲解。
        3、const
            const 是常量的意思
            用 const,修饰的变量是 *只读的* ，不能修改它的值

            const int a=101;//在定义a的时候用 const 修饰·并赋初值为 101 , 从此以后，就不能再给a赋值了
            a = 111;       //错误的

            const可以修饰指针，这个在以后课程中重点讲解

        4、 auto int a;和 int a是等价的，auto 关键字现在基本不用

        5、extern 是外部的意思，一般用于函数和全局变量的声明，这个在后面的课程中，会用到

    1.1.3 控制语句相关的关键字
        if、else 、break、 continue、for 、while、 do、 switch、 case、 goto、default

    1.1.4 其他关键字
        sizeof、 typedef、volatile
        1、sizeof
        使用来测变量、数组的占用存储空间的大小(字节数)
            例3:
            int a=10:
            int num
            num=sizeof(a);
        2.typedef 重命名相关的关键字
        3.volatile：具有与优化、多线程相关的特殊属性
            告诉编译器该变量可能会在程序外部被修改，因此需要从内存中读取变量的值，而不是从缓存或寄存器中读取。
*/
/*
2.1QT安装
    Qt [1]是一个 1991年由 Qt Company 开发的跨平台 C++图形用户界面应用程序开发框架。
    它既可以开发 GU1 程序，也可用于开发非 GU1程序，比如控制台工具和服务器。Qt是面向对象的框架，使用特殊
    的代码生成扩展(称为元对象编译器(Meta ObjectCompiler,moc))以及一些宏，Qt 很容易扩展，并且允许真正地
    组件编程。
    2008年，QtCompany 科技被诺基亚公司收购，Qt也因此成为诺基亚旗下的编程语言工具。
    2012 年，Qt 被 Digia 收购。
    2014年4月，跨平台集成开发环境 QtCreator 3.1.0正式发布，实现了对于 ios的完全支持，新增 WinRT、Beautifier
    等插件，废弃了无 Python 接口的 GDB 调试支持，集成了基于 clang 的 C/C++代码模块，并对 Android 支持做出了
    调整，至此实现了全面支持i0s、Android、Wp,它提供给应用程序开发者建立艺术级的图形用户界面所需的所有功
    能。基本上，Qt同xWindow 上的 Motif,Openwin，GTK 等图形界面库和 Windows 平台上的 MFC,OWL, VCL,
    ATL 是同类型的东西。
*/

/*
2.2第一个hello world 程序
#include <iostream>//标准输入输出文件
using namespace std; //声明了命名空间std ,std里面有很多对象，cout就存在于std作用域下

int main()
{
    //cout 标准输出流 <<
    //endl :换行
    cout << "hello world" << endl;
    return 0;
}

2.3面向过程：
    面向过程是一种以过程为中心的编程思想。
    通过分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一个一个依次调用就可以
    了。
    面向过程编程思想的核心:功能分解，自顶向下，还层细化(程序=数据结构+算法)。
    面向过程编程语言存在的主要缺点是不符合人的思维习惯，而是要用计算机的思维方式去处理问题，而且面向过程编程语言重用性低，维护困难。

    以五子棋为例：
        1.开始游戏 2.黑子先走 3.绘制画面 4.判度输赢 5.白子走 6.绘制画面 7.判度输赢...返回结果，输出结果
        以函数方式编写所有过程

2.4 面向对象编程思想：
    对象：世界上的一切事物都可以被抽象成一个对象（属性+行为）
    以五子棋为例：
        对象有：棋子，界面，判断输赢。
        将这三个对象实例化，则工程完结.
    面向对象相对于面向过程的优点:重复率低,易于维护。

2.5 面向对象的三大特点：
    封装：（将属性和方法封装在一起抽象成一个类，并且对类中的成员 加以 权限控制）
        把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行隐藏。
        类将成员变量和成员函数封装在类的内部，根据需要设置访问权限，通过成员函数管理内部状态。

    继承（将一个类中属性和方法继承到另一个类中）
        继承所表达的是类之间相关的关系，这种关系使得对象可以继承另外一类对象的特征和能力。
        继承的作用:避免公用代码的重复开发，减少代码和数据冗余。

    多态（一个接口多种形态，分为：静态多态（在编译时已经确认了函数的调用地址） 动态多态（在调用的时候才会确认函数调用的地址））
        多态性可以简单地概括为“一个接口，多种方法"，字面意思为多种形态。程序在运行时才决定调用的函数，它是
        向对象编程领域的 核心概念。
*/

/*

3章 c++ 对 c的扩展
    3.1 :: 作用域 运算符
    :: 运算符是一个作用域，若::前面什么都不加，代表使全局作用域。

        通常情况下，如果有两个同名变量，一个是全局变量，另一个是局部变量，那么局部变量在其作用域内具有较高
        的优先权，它将屏蔽全局变量
      例：
        #include <iostream>
        using namespace std;

        int a = 100;
        void test()
        {
            //局部变量
            int a = 20;
            //全局 a 被隐藏,打印局部作用域的a 以及 打印全局作用域的a
            cout << "a:"<<a<<endl;    //在 c中 局部变量赋值后，就不能再在局部环境中输出全局变量了
            cout << "a:"<< ::a <<endl;//在c++中可使用“::”，即 ::a  使变成全局作用域下的a
        }

        int main()
        {
            cout << "a:"<<a<<endl;
            test();
            cout << "a:"<<a<<endl;
            return 0;
        }

    3.2名字控制
    创建名字是程序设计过程中一项最基本的活动，当一个项目很大时，它会不可避免地包含大量名字。c++允许我们
    对名字的产生和名字的可见性进行控制。

    我们之前在学习c语言可以通过 static 关键字来使得名字只得在本编译单元内可见，在 c++中我们将通过一种通过
    命名空间来控制对名字的访问。
        3.2.1C++命名空间(namespace)
        namespace:本质是作用域,可以更好的控制标识符的作用域
        命名空间 就可以存放 变量 函数 类 结构体...

            在 c++中，名称(name) 可以是符号常量、变量、函数、结构、枚举、类和对象等等。工程越大，名称互相冲突
            性的可能性越大。另外使用多个厂商的类库时，也可能导致名称冲突。为了避免，在大规模程序的设计中，以及
            在程序员使用各种各样的 C++库时，这些标识符的命名发生冲突，标准C++引入关键字 namespace(命名空间/名字
            空间/名称空间)，可以更好地控制标识符的作用域。
        3.2.2命名空间使用语法
            创建一个命名空间：
                namespace A{}

            命名空问的定义 必须定义在全局范国
            命名空间下可以存放 变量 函数 结构体 类
            命名空间可以重名 重名的命名空间相当于做合并操作
            命名空问可以嵌套命名空问
            命名空间可以无名称：表示静态变量
            命名空间可以取别名
            命名空间的函数可以先声明，再外部定义实现
         例如：
            #include <iostream>，定义时需加命名空间作用域
            using namespace std;

            namespace A //命令包含
            {
                int a = 10; //变量
                void fun()  //函数
                {
                    cout << "hello"<<endl;
                }

                struct std //结构体
                {

                };

                class obj //类
                {

                };
            }
            namespace B
            {
                int a = 20;
                int b = 10;

            }
            namespace B //重名 做合并
            {
                int c = 20;
                int d = 10;

            }
            namespace C     //嵌套
            {
                int d = 10;
                namespace B
                {
                    namespace D
                    {
                        int d = 20;
                    }
                }
            }
            void test01()
            {
                cout << A::a <<endl;
                cout << B::a <<endl;
                cout << B::b <<endl;
            }
            int main()
            {
                test01();
                return 0;
            }

         例2：
            #include <iostream>
            using namespace std;

            namespace A //命令包含
            {
                void fun(int arg);
            }
            void fun(int arg){} //该函数与上面的声明没有关系，该函数作用于全局，上面的声明只是A作用域下的函数

            void A::fun(int arg){}

注意 ： 若命名空间没有名称，则变量都为静态变量，相当于给所有的变量都加上了static标识符，使得作为内部连接，只能被当前文件调用，属于内部链接属性

        命名空间 取别名：
        namespace shortName = longName;
        如：
            namespace newname = olename
*/

/*
   3.2.3、using 的声明
        using 的声明可使得指定标识符可用
        注意：当 using 声明的标识符和其它同名标识符有作用域冲突时，会产生二义性。

        例如：
            #include <iostream>
            using namespace std;

            namespace nameA
            {
                int a = 10;
                void foo()
                {
                    cout << "hello" <<endl;
                }
            }

            void test01()
            {
                //注意：当 using 声明标识符 和 其它标识符有作用域冲突时，会产生二义性。
            //    int a = 100;
                cout << nameA::a <<endl;
                cout << nameA::a <<endl;
                cout << nameA::a <<endl;

                using nameA::a;
                cout << a <<endl;
            }
*/

/*
        3.2.4 using 编译指令
            using 编译指令使整个命令空间标识符可用
            并且 命名空间标识符 如果和 局部变量的标识符同名，不会有冲突。优先使用局部变量。

    注意：using 声明标识符时，和 局部变量重名 会 发生冲突
         但using 编译指令 和 局部变量重名时 ，不会冲突，而是访问局部变量。

        3.2.5命名空间使用
    即：在全局写 using namespace nameA;

        需要记住的关键问题是 当引入一个全局的 using编译指令时，就为该文件打开了该命名空间，它不会影响任何其他
        的文件，所以可以在每一个实现文件中调整对命名空间的控制。

        比如，如果发现某一个实现文件中有太多的 using 指令而产生的命名冲突，就要对该文件做个简单的改变，通过明确的限定或者using 声明来消除名字冲突，这样不
        需要修改其他的实现文件。
*/

/*
    3.3 全局变量检测增强
    c代码：
        int a = 10; //赋值，当作定义
        int a;      //未赋值，当作声明

        int main()
        {
            printf("a : %d\n",a);
            return EXIT_SUCCESS;
        }
    此代码在 c++下编译失败，在c编译下通过

    3.4 c++中所有的变量和函数都必须有类型
        c语言中的函数的形参类型可以不写，没有返回值可以使用return，实参的个数不做检测
        例如：对于c++
        void foo(x,y)       //报错：形参必须有类型
        {
            return 100;     //报错：没有返回值但返回
        }

        void test01()
        {
            foo(1);         //实参与形参的个数不一致
            foo(1,2);
            foo(1,2,3);
        }

        而c++中，形参类型必须写，没有返回值的话不可以返回，实参的个数做检测


    3.5 更严格的类型转换
        在c++ ，不同类型的变量一般是不能直接赋值的，需要相应的强转。
        c代码：
            typedef enum COLOR{ GREEN, RED, YELLOW } color;
            int main(){

            color mycoLor = GREEN;
            mycolor = 10;
            printf("mycolor:%d\n",mycolor);
            char*p= malloc(10);             //c++中必须强转（char *）
            return EXIT_SUCCESS;
            }
    3.6 struct 类型增强
        在c中：定义需要完整地写：struct stu obj;
            struct stu
            {
                int a;
                int b;
            }

            void test03()
            {
                struct stu obj;
            }

            int main()
            {

            }
        而在 c++中，可以只用 stu obj。可以不写struct关键字
    3.7 新增 “bool” 类型关键字
        标准 c++的bool类型有两种内建的常量true(转换为整数 1)和false(转换为整数 0)表示状态。这三个名字都是关键字。
        bool类型只有两个值，true(1值)，false(0 值)
        bool类型占1个字节大小
        给 bool 类型赋值时，非0值会自动转换为true(1),0值会自动转换 false(0)

    例：在c语言中，以下代码的布尔类型，需要包含 stdbool.h 头文件。但c++中可以直接使用，即：c++中可以直接使用 bool类型。
        void test04()
        {
            cout<<sizeof(false)<<endl; //为1，//bool类型占一个字节大小
            bool flag = true;//c语言中没有这种类型
            flag = 100;//给booL类型赋值时，非日值会自动转换为true(1),日 值会自动转换 faLse(@)
        }
    3.8 三目运算符功能的增强
    c++中的三目运算符表达式返回的可以是一个变量，但c语言中返回的是一个常量。
        void test05()
        {
            int a = 10;
            int b = 20;
            //printf("%d\n",a<b?a:b);
            (a<b?a:b) = 100;//报错,在c语言中，三目运算符返回的是表达式的 值，是常量。因此应写为： *（a<b? &a:&b）= 100;
                            //而在c++中，三目运算符返回的是变量a。故可以赋值
        }
    3.9 c/c++中的const
        3.9.1 const 概述
            const 单词字面意思为常数，不变的。它是c/c++中的一个关键字，是一个限定符，它用来限定一个变量不允许改变，他将一个对象转换成一个常量。

            const int a =10;
            A = 100;    //编译错误，const 是一个常量，不可以修改。

        3.9.2 C/C++中const 的区别
            3.9.2.1  C中的 const
                常量的引进是在 c++早期版本中，当时标准C规范正在制定。那时，尽管C委员会决定在C中引入const,但是，他
                们c中的 const 理解为"一个不能改变的普通变量”，也就是认为 const 应该是一个只读变量，既然是变量那么就会
                给 const 分配内存，并且在c中 const 是一个 全局只读变量 ,c语言中 const 修饰的只读变量是外部连接的。


                    int arr[arrSize];
                看似是一件合理的编码，但是这将得出一个错误。 因为arsize占用某块内存，所以C编译器不知道它在编译时的
                值是多少?
                品至在海常同奇
                看似是一件合理的编码，但是这将得出一个错误。因为arrSize占用某块内存，所以C编译器不知道他在编译时的值是多少？

     3.9.1.const 概述
                    const 修饰的对象为一个常量，不能被改变。
     3.9.2.c/c++中的const的区别:

            3.9.2.1 c中的const
                    1.const修饰的局部变量，存在栈区，虽然不能通过 const修饰的变量 去改变 变量指向的栈区的内容，但可以用指针地址去修改

                    2.const修饰的全局变量，存于常量区，常量区的值是 只读的，不能通过 变量名 和 地址 去修改

                    3.const修饰的全局变量，若其他文件需要使用，则需使用 extern 声明外部可用。

                #include <stdio.h>

                //const 修饰的全局变量，保存在常量区。即 b 确实是指向10 的，但 10 是 常量，因此不能修改常量值（常量区的值是只读的，非法内存访问）。
                const int b = 10;

                //const修饰的全局变量。
                void test02()
                {
                    b = 100;//不能修改。
                    int *p = &b
                    *p = 100;//
                }

                //const 修饰的局部变量
                void test01()
                {
                //在c语言中，const 修饰的变量保存在 栈区。
                    const int a =10;
                    //a = 100;  //不能修改
                    int *p = &a;
                    *p = 100;   //使用指针可以修改值
                }

            3.9.2.2 C++中的 const
                    1.const 修饰的局部变量赋值常量时，保存于 符号表 里。
                    2.const 修饰的全局变量保存于常量区，不能被修改。
                    3.const 修饰的全局变量，默认是 内部链接属性，要改为 外部链接属性，则需要在 const 前加 extern

                #include <iostream>
                using namespace std;

                //b是const修饰的全局变量，存在常量区，
                const int b = 1;

                void test02()
                {
                    int *p = (int *)&b; //故得到常量区的地址后修改常量区的值会报错。
                    *p = 100;
                    cout << b <<endl;
                }


                //c++中const 修饰的局部变量
                void test01()
                {
                    const int a = 10;
                    //a = 100;
                    int *p = (int *)&a;//需要强制转换
                    *p = 100;          //c++中不能通过指针的地址去修改值，但没有报错，是因为：c++中const 修饰的局部变量，是存放在 符号表 里面的。（c中存于栈区）
                                       //之所以取地址没有报错，是因为：对const修饰的局部变量取地址，编译器会产生一个临时变量来保存 a 的地址。
                                       //即： int tmp = a; int *p = &tmp; 而tmp是存在栈区的，tmp是有地址和值的，p实际上指向的是tmp的地址，当tmp离开作用域之后就会释放。
                    cout << a <<endl;
                }

                void test03()
                {
                    extern const int num;
                    cout << num <<endl;
                }//会报错，因为编译链接文件的过程中，在链接的时候，由于const修饰的全局变量默认了它的连接属性是内部链接属性，因此不能被其它文件去链接的，
                 //故，要想 const修饰的全局变量让其他的文件去链接他，则需要改成外部连接属性。 即在定义的时候为: extern const int num = 1;
                 //使 const 修饰的全局变量 ，变为外部链接属性。


            3.9.2.3 C/C++中的 const异同。
                相同点：
                    c 和 c++中的const修饰的全局变量都是保存在常量区，都不能被修改
                不同点：
                    c语言中const修饰的 局部变量 赋值为常量时，保存在 栈区，可以被指针修改
                    c++中const 修饰的 局部变量 赋值为常量时，保存在 符号表中，不能被修改，

                    c语言中const 修饰的 全局变量 默认是 内部链接属性。
                    c++  中const 修饰的 全局变量 默认是 外部链接属性。

                    c++中const修饰的变量，分配内存情况：
                            1.const 修饰的全局变量，在 常量区 分配 内存。

                            2.const 修饰的局部变量，赋值为 常量 时，没有分配内存，存在符号表中，
                                                                对其取地址，会在 栈区 分配一个临时内存空间
                            3.const 修饰的局部变量，赋值为 变量 时，局部变量 保存在 栈区。
                            4.const 修饰的局部变量 如果是一个 自定义变量，也 保存在 栈区。

                            5.仅 const修饰的局部变量 赋值为 常量 时，这个局部变量 保存在 符号表 中，没有 内存（不分配 内存）。（即2.）

                            （const 修饰的 全局变量 在 常量区 分配了内存
                              const 修饰的 局部变量 赋值为常量时，对其取地址，会在 栈区 分配临时的内存空间）

              例：

                //c++中内存分配：
                #include <iostream>
                using namespace std;

                const int a = 1;//const修饰的全局变量，变量在常量区分配了内存。
                void test01()
                {
                    const int a = 10;//const 修饰的局部变量赋值为 常量，则没有分配内存，存于符号表。
                    int *p = (int *)&a; //对const修饰的局部变量取地址为常量的变量取地址，会分配一个临时的空间。

                }
                void test02()
                {
                    int b =2;
                    //const 修饰的局部变量 赋值 变量时
                    const int a = b;
                    int *p = (int *)&a;
                    *p = 100;
                    cout << a <<endl;//a的值可以被修改，存在栈区
                }

                struct stu
                {
                    int a;
                    int b;
                };
                void test03()
                {
                    const struct stu obj = {1,2};   //const 修饰的变量 是自定义变量时，也是保存在 栈区。
                    struct stu *p = (struct stu*)&obj; //
                    p->a = 3;
                    p->b = 4;
                    cout <<obj.a<<" "<< obj.b<<endl;
                }
                int main()
                {
                    test03();
                    return 0;
                }
    3.9.2.3C/C++中const异同总结
        c语言全局 const 会被存储到只读数据段。
        c++中全局 const ，当声明 extern 或者对变量取地址时，编译器会分配存储地址，变量存储在只读数据段。两个都受到了只读数据段的保护，不可修改。
            const int const A = 10.
            int main(){
            int*p= (int*)&constA,
            *p=200
            }

    以上代码在 c/c++中编译通过，在运行期，修改 constà 的值时，发生写入错误。原因是修改只读数据段的数据。

        c语言中局部 const存储在堆栈区，只是不能通过变量直接修改 const ,只读变量的值，但是可以跳过编译器的检查,
        通过指针间接修改 const 值。


*/

/*
3.10 引用（reference）
    3.10.1 引用基本用法：
        引用是 c++对c的重要扩充。在 c/c++中指针的作用基本都是一样的，但是c++增加了另外一种给函数传递地址的途
        径，这就是按 引用 传递(pass-by-reference)，它也存在于其他一些编程语言中，并不是 c++的发明。

        变量名实质上是一段连续内存空间的别名，是一个标号(门牌号)
        程序中通过变量来申请并命名内存空间
        通过变量的名字可以使用存储空间

        对一段连续的内存空间只能取一个别名吗?
        c++中新增了引用的概念，引用可以作为一个已定义变量的别名。

        基本语法:
         Type& ref= val;
         原类型名 & 别名 = 旧名;

         *（& 在等号 右边 ，为取地址，在等号 坐标，为引用）*

        注意事项:
            引用一旦初始化， 不能改变引用指向。
            引用 在 声明引用变量时 必须 初始化
            不能有NULL引用。必须确保引用是一块合法的存储单元关联。
            引用可以引用任意类型 包括数组
            &在等号 左边 表示引用；在等号 右边，表示 取地址

            & 在此不是求地址运算，而是起标识作用。
            类型标识符是指 目标变量的类型

        例：
            #include <iostream>

            using namespace std;

            void test01()
            {
                int a = 10;
                //引用一旦初始化之后，就不能改变引用的指向对象。
                int &b = a;
                b = 20;
                cout << a << endl;
                int c = 100;
                b = c;//不代表给c取别名b ,而是指将c的值赋值给b。
                //int &d; 错误，引用必须初始化

            }

            void test02()
            {
                //对数组的引用：
                int a[5] = {1,2,3,4,5};
                int (&b)[5] = a;

                typedef int ARR[5]; //定义数组类型 ARR.
                ARR &c = a;

                for(int i = 0;i<5;i++)
                {
                    cout<<b[i]<<endl;
                }
            }
            int main()
            {
                test01();
                return 0;
            }


        3.10.2  函数中的引用
                最常见 引用 的地方是在 函数参数 和 返回值 中。当 引用 被用作 函数参数时，在函数内 对 任何引用的修改 ，还将
            对 函数外的参数 产生改变。
                当然，可以通过传递一个指针来做相同的事情，但引用具有更清晰的语法。
            如果从函数中返回一个引用，必须像从函数中返回一个指针一样对待。当函数返回值时，引用关联的内存一定要存在。

            通过 引用参数 产生的效果 同 地址传递是一样的。引用的语法更清除简单:
                1)函数调用时传递的 实参 不必加 “&" 符
                2)在被调函数中不必在参数前加“*”符
                引用 作为 其它变量的别名 而存在，因此在 一些场合 可以代替指针。C++主张用引用传递 取代 地址传递的方式，因为 引用 语法 容易 且 不易出错。
        例：
            // 函数引用：
                *引用可以作为函数的形参
                *不能返回局部变量的引用

            #include <iostream>

            using namespace std;

            void swap(int *x,int *y)
            {
                int tmp = *x;
                *x = *y;
                *y = tmp;

            }
            void test01()//地址传参
            {
                int a = 10;
                int b = 20;
                swap(&a,&b);

                cout<< a <<" "<< b <<endl;
            }

            void swap2(int & x,int & y) //int & x = a;int & y = b;
            {
                int tmp = x;
                x = y;
                y = tmp;
            }
            void test02()//引用传参
            {
                int a = 10;
                int b = 20;
                swap2(a,b);

                cout<< a <<" "<< b <<endl;
            }

            //开辟空间，指针（需用到二级指针）与引用（类似于引用赋值）
            void get_mem(int **q)
            {
                *q = (int *)malloc(5*sizeof(int));
            }
            void get_mem_ref(int* (&q)) //int * (&q) = p;
            {
                q = (int *)malloc(5*sizeof(int));
            }
            void test03()
            {
                int *p = NULL;
                get_mem(&p);
                get_mem_ref(p);
            }
            int & test04()  //引用的返回：不能返回局部变量的引用
            {
                static int b = 20;
                int a = 10;
                return b;
            }

            int main()
            {
            //    test01();
            //    test02();
                test03();
                test04() = 1000;
                return 0;
            }

        3.10.3 引用的本质
            引用的本质在 c++ 内部实现是一个 指针常量 ( * const p)
            Type & ref = val; // Type *const ref = &val;
            c++编译器在编译过程中使用常量指针作为引用的内部实现，因此引用所占用的空间大小与指针相同，只是这个过程是编译器内部实现，用户不可见。

            //发现是引用，转换为 int *const ref = &a;
            void testFunc(int &ref)
            {
                ref = 100;//ref 是引用，转换为 *ref = 100;
            }
            int main(){
                int a = 10;
                int & aRef = a;//自动转换为 int *const aRef = &a; 这也说明引用为什么必须初始化
                aRef = 20;//内部发现aRef是引用，自动帮我们转换为 ： *aRef = 20;
                cout << "a："<< a <<endl;

        例如：

                #include <iostream>
                using namespace std;

                void test01()
                {
                    int a = 10;
                    int & b = a;//编译器进行优化： int *const b = &a;
                    //指针常量 不能改变 指针变量的指向
                    //  b = 0x100; b的值不能改变。
                    b = 1000; //正确，等效于 *b = 1000; //只是b的值（地址） 不能改变，b指向的地址的内容 可以改变。
                }

                void func(int* &b)  //int *& q = p ==> 编译器优化为： int ** const q = &p     //取地址p,使p成为二级指针，因此左侧也是二级指针
                {

                }
                void test02()
                {
                    int *p = NULL;
                    int ** const q = &p;
                    func(p); //p是一个指针
                }

                int main()
                {

                    return 0;
                }

        3.10.4  指针的引用
            在 c 语言中如果想要改变一个指针的指向 而不是他所指向的内容，函数声明可能这样：

            套用引用公式：type &q = p
                假设：
                    //Type为指针类型
                    void fun(int*&q)
                    {
                    }

                    void test()
                    {
                        int *p = NULL;
                        fun(p);
                    }
        3.10.5  常量引用
            常量引用的定义格式：
                const Type & ref = val; //const修饰的是 引用            常量引用注意：
                字面量不能赋给引用，但可以赋给const 引用
                const 修饰的引用，不能修改。

            常量引用表示 不能通过引用 修改引用标识的空间内容。



            例如：
                //常量引用：
                #include <iostream>
                using namespace std;

                void test01()
                {
                    int a = 10;
                    //const 修饰的是 引用，不能通过引用 修改 引用指向地址里的内容。
                    const int &b = a;
                    //b = 100; //错误，不能修改内容值。
                }

                void test02()
                {
                    //int &b = 100;//报错，100是常量，不能取地址。故 不能引用常量

                    const int &b = 1000; //先定义一个int tmp =  1000;    const int &b = tmp;
                                        //他会开辟一块临时空间，再对该临时空间进行引用。
                }

*/

/*

    3.12 内联函数
        3.12.1 内联函数的引出
            c++从c中继承的一个重要特征就是效率。
            在c中我们经常把一些短并且执行频繁的计算写成宏，而不是函数，这样做的理由是为了执行效率，宏可以避免函数调用的开销，这些都由预处理来完成。

            但是在 c++出现之后，使用预处理宏会出现两个问题:
                *第一个在c中也会出现，宏看起来像一个函数调用，但是会有隐藏一些难以发现的错误。
                *第二个问题是c++特有的， 预处理器 不允许访问 类的成员，也就是说  预处理器  宏不能用作类类的成员函数。
                (**内联函数的作用：内联函数 继承了 宏 的高效，不会出错，且能作为 类的成员函数**)

            为了保持预处理宏的效率又增加安全性，而且还能像一般成员函数那样  可以在类里访问自如  ，c++引入了内联函数  (inline function).

            内联函数为了继承宏函数的效率，没有函数调用时开销，然后又可以像普通函数那样，可以进行参数，返回值类型的安全检查，又可以作为成员函数。
        3.12.2宏函数与内联函数
            3.12.2.1 预处理宏的缺陷
                预处理器宏存在问题的关键是 我们可能认为预处理器的行为 和 编译器的行为 是一样的。当然也是由于 宏函数调用 和 函数调用 在外表看起来是一样的，
                因为也容易被混淆。但是其中也会有一些微妙的问题出现:
                问题一:
                    宏函数是直接替换，使用时可能会产生不同结果
                        #define MYADD(a,b) a+b
                        int c = MYADD(a,b)*5

                问题二：
                在使用前置++时，宏函数更容易产生错误
                        #define MYCOMPARE(a,b) a<b?a:b

                        inline int mycompare(int a,int b)
                        {
                            return a<b?a:b;
                        }

                        int c = MYCOMPARE(++a,b);   //结果为3
                        int d = mycompare(++a,b);   //结果为2


            3.12.2.2 宏函数和内联函数的区别
                宏函数  的替换发生在  预处理阶段，不需要调用。
                内联函数的替换发生在  编译阶段

                宏函数易出错，内联函数不会
                内联函数 同 宏函数一样，都省去了调用函数的开销。
            例子：

                #include <iostream>
                using namespace std;

                #define MYADD(a,b) a+b
                                            //有没有一个宏函数，既能不出错，又能像宏函数一样直接替换吧不用调用？
                                            //在函数前面加 inline :内联函数
                inline int myadd(int a,int b)
                {
                    return a+b;
                }

                //int myadd(int a,int b)  //普通函数需要开辟空间传参，效率低。
                //{
                //    return a+b;
                //}


                void test01()
                {
                    int a = 10;
                    int b = 20;
                    int c = MYADD(a,b)*5;       //注意：1.替换为 a + b * 5，  宏函数  替换发生在 预处理阶段。
                    int d = myadd(a,b)*5;       //     2.替换为（a + b）*5，内联函数  替换发生在  编译阶段。同宏函数一样，只替换，不产生开销。
                    cout << c << endl;
                    cout << d << endl;
                }

                #define MYCOMPARE(a,b) a<b?a:b

                inline int mycompare(int a,int b)
                {
                    return a<b?a:b;
                }

                void test02()
                {
                    int a = 1;
                    int b = 5;
                    int c = MYCOMPARE(++a,b);   //注意： 1.替换成 ++a<b?++a:b; 结果为3
                    int d = mycompare(++a,b);   //      2.替换结果为2
                    cout << c <<endl;
                    cout << d <<endl;

                }
                int main()
                {
                //    test01();
                    test02();
                    return 0;
                }
            3.12.3 内联函数
                3.12.3.1 内联函数的基本概念
                    在 c++中，预定义宏 的概念是用 内联函数 来实现的，而内联函数本身也是一个真正的函数。内联函数具有普通函数
                    的所有行为。
                    唯一不同之处在于：内联函数会在适当的地方像预定义宏一样展开，所以不需要函数调用的开销。因此，应该不使用宏，使用内联函数。

                    在普通函数(非成员函数),前面加上 inline 关键字使之成为内联函数,但是必须注意必须函数体和声明结合在一起，否则编译器将它作为普通函数来对待。

                    inline void func(int a);
                    以上写法没有任何效果，仅仅是声明函数，应该如下方式来做:
                    inline int func(int a){return ÷÷;}

                    注意: 编译器 将会检查函数参数列表使用是否正确，并返回值(进行必要的转换)。这些事 预处理器 无法完成的。

                        **内联函数的确占用空问，但是内联函数相对于普通函数的优势只是省去了函数调用时候的压栈，跳转，返回的开销。我们可以理解为内联函数是以空间换时间。

                3.12.3.2 类的内联函数（类的成员函数  默认编译器会将它做成  内联函数）
                    为了定义内联函数，通常必须在函数定义前面放一个inline 关键字。但是在 类内部定义内联函数时 并不是必须的。

                    //任何在 类内部定义的函数自动成为内联函数

                    class Person{
                        public:
                            person(){cout << "构造函数！" <<endl;}               //默认在这两行前面 加上了关键字 inline,自动成为内联函数
                            void PrintPerson(){cout << "输出Person!"<<endl;}
                    }
                3.12.3.3 内联函数 和 编译器
                    内联函数并不是何时何地都有效，为了理解内联函数何时有效，应该要知道编译器碰到内联函数会怎么处理?

                    对于任何类型的函数，编译器会将函数类型(包括函数名字，参数类型，返回值类型)放入到符号表中。
                    同样，当编译器看到内联函数，并且对内联函数体进行分析没有发现错误时，也会将内联函数放入符号表。

                    当调用一个内联函数的时候，编译器首先确保传入参数类型是正确匹配的，或者如果类型不正完全匹配，但是可以将其转换为正确类型，并且返回值在目标表达式里匹配正确类型，或者可以转换为目标类型，内联函数就会直接替换函数调用，这就消除了函数调用的开销。假如内联函数是成员函数，对象this 指针也会被放入合适位置。

                    类型检查和类型转换、包括在合适位置放入对象this指针这些都是预处理器不能完成的。

                    但是c++内联编译会有一些限制，以下情况编译器可能考虑不会将函数进行内联编译:
                        **不能存在任何形式的循环语句
                        **不能存在过多的条件判断语句
                        **函数体不能过于庞大
                        **不能对函数进行取址操作

                    **内联仅仅只是给编译器一个建议，编译器不一定会接受这种建议，如果你没有将函数声明为内联函数，那么编译器也可能将此函数做内联编译。
                    一个好的编译器将会内联小的、简单的函数。
         3.13 函数的默认参数
            c++在声明函数原型的同时，可为一个或多个参数指定默认（缺少的）参数值，当函数调用的时候如果没有指定这个值，编译器会自动默认值代替。

                void TestFunc01(int a = 10,int b = 20)//给一个默认参数。即称为：缺省参数。
                {
                    cout << "a + b = "<<a+b<<endl;
                }

        //注意：
            //1.设置默认参数时 有一个参数设置了默认参数,从这个参数往后的每一个参数都要设置默认参数
                void TestFunc02(int a,int b= 10,int c = 10){}
            //2.默认参数在设置时，声明 和 定义 只能选择一处设置默认参数。
                void TestFunc03(int a = 0,int b = 0);
                void TestFunc03(int a ,int b){ }
            //3.有实参用实参，没有传参数，则用默认参数

            例子：
                #include <iostream>
                using namespace std;

                //默认参数在设置时，声明 和 定义 只能选择一处设置默认参数。
                //设置默认参数时 有一个参数设置了默认参数,从这个参数往后的每一个参数都要设置默认参数
                void fun01(int a = 11,int b = 22)
                {
                    cout << a <<" "<< b <<endl;
                }

                int main()
                {
                    fun01();
                    fun01(1,3);
                    fun01(1);

                    return 0;
                }

        3.14 函数的占位参数  （在后面：操作符重载的后置++要用到）
            c++ 在声明函数时，可以设置占位参数，占位参数  *只有参数类型声明* ，而 *没有参数名声明* ，一般情况下，在函数体内部无法使用占位参数。
            (占位参数给函数形参设置的，调用时需要传参，也可以设置占位参数为默认参数)

            void TestFunc01(int a,int b,int)
            {
                //函数内部无法使用占位参数
                cout <<"a+b ="<<a+b<<endl;
            }

            //占位参数也可以设置默认值
            void TestFunc02(int a,int b,int = 20)
            {
                //函数内部依旧无法使用占位参数
                cout <<"a+b ="<<a+b<<endl;
            }
            int main(){

                //错误调用，占位参数也是参数，必须传参数
                //TestFunc01(10,20);

                //正确调用
                TestFunc01(10,20,30);
                TestFunc02(10,20);

        3.15 函数重载（overload）(目的是：方便地使用函数名。)
            3.15.1  函数重载概述
                能使名字方便使用，是任何程序设计语言的一个重要特征！

                c++中函数的名字是可以重名地，即可以有多个相同函数名的函数存在。名字相同，意义不同

                在传统c语言中，函数名必须是唯一的，程序中不允许出现同名的函数。在c++中是允许出现同名的函数，这种现象称为函数重载。


            3.15.2 函数重载
                3.15.2.1 函数重载基本语法
                    实现函数重载的条件:
                        在同一个作用域下：
                                参数 *个数* 不同
                                参数 *类型* 不同
                                参数 *顺序* 不同
                 //1. 函数重载条件：同作用域下。个数、类型、顺序可重载
                    namespace A{
                        void MyFunc()                {cout<< "无参数!"                    <<endl;}
                        void MyFunc(int a)           {cout<< "a: "   <<a                 <<endl;}
                        void myFunc(string b)        {cout<< "b: "   <<b                 <<endl;}
                        void myFunc(int a, string b) {cout<< "a: "   << a << " b: " << b <<endl;}
                        void MyFunc(string b, int a) {cout<< "a: "   << a << " b: " << b <<endl;}

                    注意：有重载时，尽量不用默认参数，会产生二义性。
                        void fun(int a,int b)
                        void fun(int a,int b =2)

                        fun(1); //函数调用会产生二义性。

                //2.返回值不作为的数重载依据
                        void MyFunc(int a)           {cout<< "a: "   <<a                 <<endl;}
                        int  MyFunc(int a)           {cout<< "a: "   <<a                 <<endl;}
                        //报错

            引申：函数返回值为何不能作为重载条件？
                    思考:为什么函数返回值不作为重载条件呢?
                    当编译器能从上下文中确定唯一的函数的时，如int ret=func(),这个当然是没有问题的。然而，我们在编写程序过程中可以忽略他的返回值。那么这个时候,一个函数为void func(int x);另一个为int func(int x);当我们直接调用 func(10),这个时候编译需就不确定调用那个函数。所以在c++中禁止使用返回值作为重载的条件。

            3.15.2.2 函数重载（实现原理）本质
            编译器为了实现函数重载，用不同的参数类型来修饰不同的函数名，比如 void func();编译器可能会将函数名修饰成func，当编译器碰到void func(int x),编译器可能将函数名修饰为funcint,当编译器碰到void func(int x,charc),编译器可能会将函数名修饰为funcintchar,这里使用"可能"，是因为编译器如何修饰重载的函数名称并没有一个统一的标准，所以不同的编还器可能会产生不同的内部名
            void func(){}
            void func(int x){}
            void func(int x,char y){}
            以上3个函数在linux下生成的编译之后的函数名为：
                _Z4funcv  // v 代表void ，无参数
                _Z4funci  // i 代表参数为 int 类型
                _Z4funcic // i 代表第一个参数为 int 类型，第二个参数为char类型

        3.15.3 extern "C" 浅析

            以下在 Linux 下测试:
                c函数  :void MyFunc(){},被编译成函数: Myfunc
                c++所数:void MyFunc(){},被编译成函数:_Z6Myfuncv

            **通过这个测试，由于c++中需要支持函数重载，所以c和c++中对同一个函数经过编译后生成的函数名是不相同的，
            这就导致，如果在c++中调用一个使用c语言编写模块中的某个函数，那么 c++是根据 c++的名称修饰方式来查找并链接这个函数，那么就会发生链接错误**

            以上例，c++中调用Myfunc函数，在链接阶段会去找Z6Myfuncv，结果是没有找到的，因为这个MyFunc函数是c语言编写的，生成的符号是Myfunc。
            那么如果我想在 c++调用c的函数怎么办?
            exern "c"的主要作用就是为了实现 c++代码能够调用其他c语言代码。加上exten "c"后，这部分代码编译器按c语言的方式进行编译和链接，而不是按c++的方式。
            MyModule.h

      **例如：**
        main.cpp:
                #include <iostream>
                #include "myadd.h"

                using namespace std;

                int main()
                {
                    cout << myadd(2,3)<<endl;//会产生无法解析的外部命令。
                    //因为使用的是c++的编译器，而c++的编译器会对函数名称进行修改。
                    //纠正方法：在函数声明时改为： extern "C" int myadd(int a,int b);告诉编译器函数是.c的代码，叫他不要修改函数名称。
                    /%由于每次都添加的话会很麻烦，故可改为：
                            #if __cplusplus
                            extern "C"{
                            #endif
                                    int myadd(int a,int b);
                            #if __cplusplus
                            }
                            #endif
                    %/

                    return 0;
                }
        myadd.c
                int myadd(int a,int b)
                {
                    return a+b;
                }
        myadd.h
            方法一:
                #pragma once
                extern "C" int myadd(int a,int b);
            方法二:
                #if __cplusplus
                extern "C"{
                #endif
                        int myadd(int a,int b);
                #if __cplusplus
                }
                #endif

*/



//笔记区
//##############################################################################################################################################################################################################################
//代码区



/*

//#include <iostream>

//using namespace std;

//int main()
//{
//    //std::cout << "Hello World!\n";
//    cout << "Hello World!" << endl;
//    return 0;
//}

//*************************************
//#include <iostream>
//using namespace std;

//int a = 100;
//void test()
//{
//    //局部变量
//    int a = 20;
//    //全局 a 被隐藏
//    cout << "a:"<<a<<endl;
//    cout << "a:"<<::a<<endl;
//}

//int main()
//{
//    cout << "a:"<<a<<endl;
//    test();
//    cout << "a:"<<a<<endl;
//    return 0;
//}


//*******************************
//#include <iostream>
//using namespace std;

//namespace A //命令包含
//{
//    int a = 10; //变量
//    void fun()  //函数
//    {
//        cout << "hello"<<endl;
//    }

//    struct std //结构体
//    {

//    };

//    class obj //类
//    {

//    };
//}
//namespace B
//{
//    int a = 20;
//    int b = 10;

//}
//namespace B //重名 做合并
//{
//    int c = 20;
//    int d = 10;

//}
//namespace C     //嵌套
//{
//    int d = 10;
//    namespace B
//    {
//        namespace D
//        {
//            int d = 20;
//        }
//    }
//}
//void test01()
//{
//    cout << A::a <<endl;
//    cout << B::a <<endl;
//    cout << B::b <<endl;
//}
//int main()
//{
//    test01();
//    return 0;
//}

//*****************************************************

//#include <iostream>
//using namespace std;

//namespace A //命令包含
//{
//    void fun(int arg);
//}
//void fun(int agr) //该函数与上面的声明没有关系，该函数作用于全局，上面的声明只是A作用域下的函数
//{}
//void A::fun(int agr)
//{}

//***************************************************
//#include <iostream>
//using namespace std;

//namespace nameA
//{
//    int a = 10;
//    void foo()
//    {
//        cout << "hello" <<endl;
//    }
//}

//void test01()
//{
//    //注意：当 using 声明标识符 和 其它标识符有作用域冲突时，会产生二义性。
//    int a = 100;
//    cout << nameA::a <<endl;
//    cout << nameA::a <<endl;
//    cout << nameA::a <<endl;

//    using nameA::a;
//    cout << a <<endl;
//}
//*****************************************************
//#include <iostream>
//using namespace std;

//namespace nameA
//{
//    int a = 10;
//    void foo()
//    {
//        cout << "hello" <<endl;
//    }
//}

//void test01()
//{
//    //注意：当 using 声明标识符 和 其它标识符有作用域冲突时，会产生二义性。
////    int a = 100;
//    cout << nameA::a <<endl;
//    cout << nameA::a <<endl;
//    cout << nameA::a <<endl;

//    using nameA::a;
//    cout << a <<endl;
//}

//void test02()
//{
//    int a = 1000;
//    using namespace nameA;//using 编译指令使整个命名空间标识符可用
//    cout << a <<endl;

//}

//￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥
//c++中内存分配：
//#include <iostream>
//using namespace std;

//const int a = 1;//const修饰的全局变量，变量在常量区分配了内存。
//void test01()
//{
//    const int a = 10;//const 修饰的局部变量赋值为 常量，则没有分配内存，存于符号表。
//    int *p = (int *)&a; //对const修饰的局部变量取地址为常量的变量取地址，会分配一个临时的空间。

//}
//void test02()
//{
//    int b =2;
//    //const 修饰的局部变量 赋值 变量时
//    const int a = b;
//    int *p = (int *)&a;
//    *p = 100;
//    cout << a <<endl;//a的值可以被修改，存在栈区
//}

//struct stu
//{
//    int a;
//    int b;
//};
//void test03()
//{
//    const struct stu obj = {1,2};   //const 修饰的变量 是自定义变量时，也是保存在 栈区。
//    struct stu *p = (struct stu*)&obj; //
//    p->a = 3;
//    p->b = 4;
//    cout <<obj.a<<" "<< obj.b<<endl;
//}
//int main()
//{
//    test03();
//    return 0;
//}


//&**************************************
////引用：

//#include <iostream>

//using namespace std;

//void test01()
//{
//    int a = 10;
//    //引用一旦初始化之后，就不能改变引用的指向对象。
//    int &b = a;
//    b = 20;
//    cout << a << endl;
//    int c = 100;
//    b = c;//不代表给c取别名b ,而是指将c的值赋值给b。
//    //int &d; 错误，引用必须初始化

//}
//void test02()
//{
//    //对数组的引用：
//    int a[5] = {1,2,3,4,5};
//    int (&b)[5] = a;
//    typedef int ARR[5];
//    ARR &c = a;
//    for(int i = 0;i<5;i++)
//    {
//        cout<<b[i]<<endl;

//    }
//}

//int main()
//{
//    test02();
//    return 0;
//}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// 函数引用：
#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int *x,int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;

}
void test01()//地址传参
{
    int a = 10;
    int b = 20;
    swap(&a,&b);

    cout<< a <<" "<< b <<endl;
}

void swap2(int & x,int & y) //int & x = a;int & y = b;
{
    int tmp = x;
    x = y;
    y = tmp;
}
void test02()//引用传参
{
    int a = 10;
    int b = 20;
    swap2(a,b);

    cout<< a <<" "<< b <<endl;
}

void get_mem(int **q)
{
    *q = (int *)malloc(5*sizeof(int));
}
void get_mem_ref(int* (&q)) //int * (&q) = p;
{
    q = (int *)malloc(5*sizeof(int));
}
void test03()
{
    int *p = NULL;
    get_mem(&p);
    get_mem_ref(p);
}

int & test04()
{
    static int b = 20;
    return b;   //不能返回局部变量的引用
}

int main()
{
//    test01();
//    test02();
    test04();
   int &d = test04();
    cout<<d <<endl;
    d = 10;
    cout <<d<<" "<<endl;
    return 0;
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// 引用的本质是 指针常量
//#include <iostream>
//using namespace std;

//void test01()
//{
//    int a = 10;
//    int & b = a;//编译器进行优化： int *const b = &a;
//    //指针常量 不能改变 指针变量的指向
//    //  b = 0x100; b的值不能改变。
//    b = 1000; //正确，等效于 *b = 1000; //只是b的值（地址） 不能改变，b指向的地址的内容 可以改变。
//}

//void func(int* &b)  //int *& q = p ==> 编译器优化为： int ** const q = &p     //取地址p,使p成为二级指针，因此左侧也是二级指针
//{

//}
//void test02()
//{
//    int *p = NULL;
//    int ** const q = &p;
//    func(p); //p是一个指针
//}

//int main()
//{

//    return 0;
//}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//常量引用：
#include <iostream>
using namespace std;

void test01()
{
    int a = 10;
    //const 修饰的是 引用，不能通过引用 修改 引用指向地址里的内容。
    const int &b = a;
    //b = 100; //错误，不能修改内容值。
}

void test02()
{
    //int &b = 100;//报错，100是常量，不能取地址。故 不能引用常量

    const int &b = 1000; //先定义一个int tmp =  1000;    const int &b = tmp;
                        //他会开辟一块临时空间，再对该临时空间进行引用。
}
int main()
{

}

*/

/*
//宏函数 与 内联函数

#include <iostream>
using namespace std;

#define MYADD(a,b) a+b
                            //有没有一个宏函数，既能不出错，又能像宏函数一样直接替换吧不用调用？
                            //在函数前面加 inline :内联函数
inline int myadd(int a,int b)
{
    return a+b;
}

//int myadd(int a,int b)  //普通函数需要开辟空间传参，效率低。
//{
//    return a+b;
//}


void test01()
{
    int a = 10;
    int b = 20;
    int c = MYADD(a,b)*5;       //注意：1.替换为 a + b * 5，  宏函数  替换发生在 预处理阶段。
    int d = myadd(a,b)*5;       //     2.替换为（a + b）*5，内联函数  替换发生在  编译阶段。同宏函数一样，只替换，不产生开销。
    cout << c << endl;
    cout << d << endl;
}

#define MYCOMPARE(a,b) a<b?a:b

inline int mycompare(int a,int b)
{
    return a<b?a:b;
}

void test02()
{
    int a = 1;
    int b = 5;
    int c = MYCOMPARE(++a,b);   //注意： 1.替换成 ++a<b?++a:b; 结果为3
    int d = mycompare(++a,b);   //      2.替换结果为2
    cout << c <<endl;
    cout << d <<endl;

}
int main()
{
//    test01();
    test02();
    return 0;
}

*/

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//13、函数

//#include <iostream>
//using namespace std;

//默认参数在设置时，声明 和 定义 只能选择一处设置默认参数。
//设置默认参数时 有一个参数设置了默认参数,从这个参数往后的每一个参数都要设置默认参数
//void fun01(int a = 11,int b = 22)
//{
//    cout << a <<" "<< b <<endl;
//}

//int main()
//{
//    fun01();
//    fun01(1,3);
//    fun01(1);

//    return 0;
//}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//
#include <iostream>
#include "myadd.h"

using namespace std;


int main()
{
    cout << myadd(2,3)<<endl;//会产生无法解析的外部命令。
    //因为使用的是c++的编译器，而c++的编译器会对函数名称进行修改。
    //纠正方法：在函数声明时改为： extern "C" int myadd(int a,int b);告诉编译器函数是.c的代码，叫他不要修改函数名称。
    //由于每次都添加的话会很麻烦，故可改为：
    /*
            #if __cplusplus
            extern "C"{
            #endif

                    int myadd(int a,int b);

            #if __cplusplus
            }
            #endif
    */
    return 0;
}










