/*
    4、类和对象
        4.1类和对象的基本概念
            4.1.1 c 和 c++中 struct区别
                c  中 struct 只有变量            （c语言中结构体不能存放函数，也就是 数据 和 行为 是分离的）
                c++中 struct既有变量，也有函数    （c++ 中结构体是可以存放函数的，即  数据 和 行为 是封装在一起的）

            4.1.2 类的封装
                4.1.2.1 类
                我们编写程序的目的是为了解决现实中的问题，而这些问题的构成，都是由各种事物组成，我们在计算机中要解决这种问题，首先要做就是要将这个问题的参与者:事和物抽象到计算机程序中，也就是用程序语言表示现实的事物。
                那么现在问题是如何用程序语言来表示现实事物?现实世界的事物所具有的共性就是每个事物都具有自身的属性，一些自身具有的行为，所以如果我们能把事物的属性和行为表示出来，那么就可以抽象出来这个事物。

                在c语言中，我们可以这么表示人这个对象:
                  #include <iostream>
                  using namespace std;
                  //c语言的结构体不能放函数
                  struct stu
                  {
                      int a;
                      int b[5];
                  }
                  //c++中可以放函数
                  struct stu1
                  {
                      int a;
                      int b[5];
                      void prtint_stu()
                      {
                            cout<<a<<endl;
                      }
                  };
                  struct student
                  {
                      //学生的属性 和 数据
                      int age;
                      int id;
                      char name[256];
                      //操作属性的叫做 方法 或 行为 -- 函数

                      void prtint()
                      {
                            cout<<age<<id<<name<<endl;
                      }
                  };
                  void test01()
                  {
                    student obj;
                    obj.age = 10;
                    obj.id = 20;
                    strcpy(obj.name,"lucy");
                    obj.print();
                    }
                    int main()
                    {
                        test01();
                    }
                4.1.2.2 c语言中表示事物的方法存在的问题
                    例如： 属性和行为分开可能导致，行为被别人调用。导致程序逻辑出错
                        #include <stdio.h>
                        #include <string.h>
                        //表示人
                        struct Person
                        {
                            int age;
                            char name[128];
                        };

                        void Person_eat(struct Person* p)
                        {
                            printf("%s 在吃饭\n",p->name);
                        }

                        //表示狗
                        struct Dog
                        {
                            int age;
                            char name[128];
                        };

                        void Dog_eat(struct Dog* p)
                        {
                            printf("%s 在吃屎\n",p->name);
                        }
                        void test01()
                        {
                            struct Person p1;
                            p1.age = 20;
                            strcpy(p1.name,"bob");
                            Person_eat(&p1);

                            struct Dog d1;
                            d1.age = 3;
                            strcpy(d1.name,"Tom");
                            Dog_eat(&d1);

                            //人调用了狗的行为。即：属性和行为分开，可能导致行为被别人调用。
                            Dog_eat(&p1);


                        }
                        int main()
                        {
                            test01();
                        }
                4.1.2.3  c++ 中 用类对事物的封装。（结构体封装无法控制访问权限，默认全公共，类封装可以控制访问权限，默认全私密）
                        * c++将事物的属性和行为封装在一起
                        * 类和结构体的一个区别在于，类 对成员 可以进行访问的权限控制，而结构体不行。
                        * 类 = 类型（事物的行为和属性）  类实例化出来的变量叫做对象。
                        * 类中的函数 可以访问 到 类里面的成员。

                例如：
                    // c++ 里面对事物的封装。
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    using namespace std;

                    //c++ 中对事物的封装，将属性 和 行为 封装在一起。
                    //类 将事物抽象成属性和行为，并且 封装在一起。   将struct 改为 class
                    //struct Person
                    //{
                    //    //人的属性
                    //    int age;
                    //    char name[128];
                    //    //人的行为
                    //    void Person_eat()
                    //    {
                    //        cout << name<<"吃饭"<<endl;
                    //    }
                    //};

                    //struct 和 class 的区别：
                    // 类中所有的成员 访问权限都是私有的（private），只能类内访问，类外无法访问。
                    // 而结构体中所有的成员，默认都是公有的，类中的所有成员默认是私有的。也可以修改成员访问权限的属性：public:
                    class Person
                    {

                        //人的属性
                    public:
                        int age;
                        char name[128];
                        //人的行为
                        void Person_eat()
                        {
                            cout << name<<"吃饭"<<endl;
                        }
                    };

                    struct Dog
                    {
                        //人的属性
                        int age;
                        char name[128];
                        //人的行为
                        void Dog_eat()
                        {
                            cout << name<<"吃饭"<<endl;
                        }
                    };

                    void test01()
                    {
                        //通过类 实例化出一个变量，这个变量叫对象
                        Person p1 = {10,"bob"};
                        p1.Person_eat();

                        Dog b1 = {3,"Tom"};
                        b1.Dog_eat();
                    }
                    int main()
                    {
                        test01();
                        return 0;
                    }

            4.1.3  将成员变量设置为 private
                1.可赋子客户端访问数据的一致性。
                    如果成员变量不是 public，客户端唯一能够访问对象的方法就是通过成员函数。
                    如果类中所有 public 权限的成员  都是函数，客户在访问类成员时只会默认访问函数，不需要考虑访问的成员需不需要添加(),这就省下了许多搔首弄耳的时间。

                        public:     //公有的，类内 类外 都可访问
                            int tall;//多高，可以让外人知道
                        protected:  //保护的，类外不可访问，类内可以访问。    在继承中：子类可以访问
                            int money;//有多少钱，只能儿孙知道
                        private:    //私有的，类外不可访问，类内可以访问。    子类不可访问
                            int Age;  //不想外人知道

                2.可细微划分访问控制。
                    尽量设置成员变量为私有权限。
                        设置成员为私有的优点：
                            *对变量的设置范围的控制。
                            *可以给变量设置只读权限
                            *可以给变量设置只写权限
                            *可以给变量设置读写权限
                    使用成员函数 可使得我们对变量的控制处理更加精细。如果我们让所有的成员变量为public，每个人都可以读写它。如果我们设置为 private，我们可以实现“不准访问”、“只读访问"、“读写访问"，甚至你可以写出"只写访问”。

                        class AccessLevels{
                        public:
                            //对只读属性进行只读访间
                            int getReadonly(){ return readOnly;}

                            //对读写属性进行读写访问
                            void setReadWrite(int val){readWrite = val;}
                            int  getReadWrite() {return readWrite;}

                            //对只写属性进行只写访问
                            void setWriteOnly(int val) {writeOnly = val;}
                        private:
                            int readOnly; //对外只读访问
                            int noAccess; //外部不可访问
                            int readWrite;//读写访问
                            int writeOnly;//只写访问
                        protected:
                            ;
                        };
            例如：
                //类 成员的 权限控制

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                using namespace std;


                class Person
                {
                    void show()
                    {
                        cout << tall <<endl;
                        cout << money <<endl;
                        cout << Age <<endl;
                    }
                public:     //公有的，类内 类外 都可访问
                    int tall;//多高，可以让外人知道
                protected:  //保护的，类外不可访问，类内可以访问。    在继承中：子类可以访问
                    int money;//有多少钱，只能儿孙知道
                private:    //私有的，类外不可访问，类内可以访问。    子类不可访问
                    int Age;  //不想外人知道
                };

                void test01()
                {
                    Person p;
                    p.tall = 180;
                }

                int main()
                {
                    return 0;
                }

            4.1.4 练习：
                设计一个Person类，具有name 和 age 属性，提供初始化函数 Init,并提供对 name 和 age 的读写函数（set，get）
                但必须确保age 赋值在有效范围（0-100），超出范围则拒绝赋值，并提供方法输出名字和年龄
        程序：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            using namespace std;

            class Person{
                public:
                    void person_init(int age1,char *name1)
                    {
                        age = age1;
                        strcpy(name,name1);
                    }

                    void show_person()
                    {
                        cout << age <<" "<<name<<endl;
                    }

                    int get_age()
                    {
                        return age;
                    }

                    void set_age(int age1)
                    {
                        if(age1 >= 0&& age1<= 100)
                        {
                            age = age1;
                        }
                    }

                    char* get_name()
                    {
                        return  name;
                    }
                    void set_name(char* name1)
                    {
                        strcpy(name,name1);
                    }
                private:
                    int age;
                    char name[128];
            };

            void test01()
            {
                Person p1;
                p1.person_init(20,"Bob");
                p1.show_person();
                p1.set_age(30);
                p1.set_name("Tom");
                p1.show_person();

            }
            int main()
            {
                test01();
                return 0;
            }

        4.2 面向对象程序设计案例
            4.2.1 设计立方体类
                设计立方体类（Cube),求出立方体的面积（2ab + 2ac +2bc）和体积（a*b*c），分别用全局函数和成员函数判度两个立方体是否相等。
            案例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                using namespace std;

                class Cube
                {
                public:

                    void set_L(int l)
                    {
                        L = l;
                    }
                    void set_W(int w)
                    {
                        W = w;
                    }
                    void set_H(int h)
                    {
                        H = h;
                    }

                    int get_L()
                    {
                        return L;
                    }
                    int get_W()
                    {
                        return W;
                    }
                    int get_H()
                    {
                        return H ;
                    }

                    //求体积
                    int get_cube_V()
                    {
                        return L*W*H;
                    }
                    //求面积
                    int get_cube_S()
                    {
                        return 2*W*L+2*W*H+2*L*H;
                    }
                    //判度两个立方体是否相等
                    bool compare_cube(Cube & c1)
                    {
                        return (c1.get_H() == H && c1.get_L()==L &&c1.get_W() == W);
                    }
                private:
                    int L;
                    int W;
                    int H;
                };

                bool compare_cube(Cube &a,Cube &b)
                {
                    return a.get_H() == b.get_H()&& a.get_L() == b.get_L()&&a.get_W()==b.get_W();
                }

                void test01()
                {
                    Cube c1;
                    c1.set_L(10);
                    c1.set_W(20);
                    c1.set_H(30);
                   cout<< c1.get_cube_S()<<" "<< c1.get_cube_V()<<endl;

                   Cube c2;
                   c2.set_L(20);
                   c2.set_W(20);
                   c2.set_H(30);
                   if(c1.compare_cube(c2))
                   {
                       cout<< "两个立方体相等"<<endl;
                   }
                   else
                   {
                        cout<< "两个立方体不相等"<<endl;
                   }

                   if(compare_cube(c1,c2))
                   {
                       cout<< "两个立方体相等"<<endl;
                   }
                   else
                   {
                        cout<< "两个立方体不相等"<<endl;
                   }

                }


                int main()
                {
                    test01();

                    return 0;
                }
            4.2.2 点和圆的关系
                设计一个圆形类(AdvCircle)，和一个点类(Point)，计算点和圆的关系。
                假如圆心坐标为 x0,y0,半径为r，点的坐标为 x1, y1:
                    1)点在圆上:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)==r*r
                    2)点在圆内:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)<r*r
                    3)点在圆外:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)>r*r
            案例：
                //点和圆类，判断距离
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                using namespace std;

                //点类
                class Point{
                public:
                    void setX(int x){mX = x;}
                    void setY(int y){mY = y;}

                    int getX(){ return mX; }
                    int getY(){ return mY; }
                private:
                    int mX;
                    int mY;
                };

                //圆类
                class Circle
                {
                public:
                    void setP(int x,int y){
                        mP.setX(x);
                        mP.setY(y);
                        }
                    void setR(int r){mR=r;}
                    Point& getP(){return mP;}//返回圆心点时，返回的是别名
                    int getR(){return mR;}//返回半径

                    //判断点和圆的关系
                    void IsPointInCircle(Point& point)//传点的类
                    {
                        int distance = ((point.getX()-mP.getX()) * (point.getX()-mP.getX())+(point.getY()- mP.getY())*(point.getY()- mP.getY()));
                        int radius =mR*mR;
                        if(distance< radius){
                            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆内!"<< endl;
                        }
                        else if(distance > radius){
                            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆外!"<< endl;
                        }
                        else
                        {
                            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆上!"<< endl;
                        }
                    }
                private:
                    Point mP; //圆心
                    int mR; //半径
                };

                void test(){
                    //实例化圆对象
                    Circle circle;
                    circle.setP(20,20);
                    circle.setR(5);
                    //实例化点对象
                    Point point;
                    point.setX(25);
                    point.setY(20);
                    cout<< "("<<circle.getP().getX()<<","<<circle.getP().getY()<< ")" <<"  "<<circle.getR()<<endl;
                    circle.IsPointInCircle(point);
                }
                int main()
                {
                    test();
                    return 0;
                }
*/
/*
    4.3 对象的构造和析构
        4.3.1 初始化 和 清理
            产品都有一个初始设置，也就是这些产品对被创建的时候会有一个基础属性值。随着时间越久，会新增很多文件数据，若不再使用，则应将增加的数据删除掉，保护自己的信息数据。
            由此，所有的事物在起初的时候都应该有个初始状态，当这个事物完成其使命时，应及时清除外界作用于上面的一些信息数据。

            那么我们 c++中这种思想也是来源于现实，是对现实事物的抽象模拟，具体来说，当我们创建对象的时候,这个对多象应该有一个初始状态，当对象销毁之前应该销毁自己创建的一些数据。
            对象的初始化和清理也是两个非常重要的安全问题，一个对象或者变量没有初始状态时，对其使用后果是未知，同样,使用完一个变量，没有及时清理，也会造成一定的安全问题。

            c++为了给我们提供这种问题的解决方案，构造函数 和 析构函数，这两个函数将会被编译器自动调用，完成 对象初始化 和 对象清理 工作。
            无论你是否喜欢，对象的初始化和清理工作是编译器强制我们要做的事情，即使你不提供初始化操作和清理操作,编译器也会给你增加默认的操作，只是这个默认初始化操作不会做任何事，所以编写 类 就应该顺便提供初始化函数。

            为什么初始化操作是 自动调用 而不是 手动调用 ?既然是必须操作，那么自动调用会更好，如果靠程序员自觉，那么就会存在遗漏初始化的情况出现。

        4.3.2 构造函数 和 析构函数
            构造函数 主要用于 创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
            析构函数 主要用于 对象销毁前，系统自动调用，执行一些清理工作。

            构造函数语法:
                构造函数 函数名 与 类名相同，没有返回值，不能有void，但可以有参数。
                ClassName(){}

                析构函数语法：
                析构函数函数名是在类名前面加 “ ~ ”组成，没有返回值，不能有void ，不能有参数，不能重载。
                ~ClassName(){}
        总结：
            构造函数：
                * 没有返回值
                * 函数名 与 类名 一致
                * 有参数，且可以有多个参数。
                * 可以函数重载
                * 创建对象时，构造函数自动调用。

            析构函数
                * 没有返回值
                * 函数名：类名前 加 “~”
                * 没有参数
                * 不能发生重载
                * 对象销毁前自动调用
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>

                using namespace std;

                class Person{
                    public:
                        int m_age;
                        //string 字符串类，头文件:  #include <string>
                        string m_name;//可赋值为 char* 的指针 或者 字符串。

                        //构造函数，函数名 与 类名 一致，无返回值，可以有参数，可函数重载。
                        Person(int age,string name)
                        {
                            m_age = age;
                            m_name = name;
                            cout<<"构造函数！"<<endl;
                        }

                        //析构函数，函数名 在 类名 前加“ ~ ”，没有返回值，不能有参数，不能发生重载。
                        ~Person()
                        {
                            cout<<"析构函数！"<<endl;
                        }
                };

                void test()
                {
                    //构造函数是在 实例化对象时创建，即，在内存 开辟空间 时调用。
                    //构造函数的传参 类似于 函数传参，就直接：Person p1(30,"lisa")
                    Person p1(30,"lisa");

                    //p1出作用域时，销毁，而析构函数 就是在 销毁时自动调用。
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.3 构造函数 的分类 及 调用
            按参数类型：无参数构造函数 和 有参构造函数
            按类型分类：普通构造函数   和 拷贝构造函数（复制构造函数）

            拷贝构造函数的写法:
                类名（const 类名 &obj）{}

            注意：若自定义了 普通构造函数（有参或无参），则不再提供普通构造函数
                 若自定义了 拷贝构造函数，则不再提供默认的拷贝构造函数。
                 默认的拷贝构造，是简单的默认 值拷贝。
                 若创建对象时，不能调用对应的构造函数，将不能创建出对象。（创建了有参但没有无参，则p1创建不出来）

        例如:
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //无参构造
                Person()
                {
                    cout << "无参构造!" << endl;
                }

                //有参构造
                Person(int age,string name)
                {
                    cout << "有参构造" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
                //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
                Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"拷贝构造"<<endl;
                }
            };

            void test()
            {
                //注意：使用无参构造时，不能加括号。
                //如果人为提供了有参和无参构造，系统将不在提供默认的无参构造
                //若人为没提供构造函数，则系统默认生成一个空无参构造。
                Person p1;
                Person p2(30,"Lisa");

                Person p3(p2);//调用系统默认提供的拷贝构造：
                //拷贝构造调用时机：旧对象初始化新对象

                 cout<<p3.m_age<<"  " << p3.m_name <<endl;
            }
            int main()
            {
                test();
                return 0;
            }
        4.3.4 拷贝构造函数的调用时机
            1.匿名对象调用：
                //匿名对象，没有名字，其生命周期在当前行。
                Person(10,"lucy");//调用有参构造创建匿名对象，
                Person();//匿名对象调用无参构造需要加括号
                Person p1(10,"lisa");
                //Person(p1);//错误，匿名对象 不能使用 括号法 调用 拷贝构造。
            2.显示法调用：
                Person p1 = Person(10,"lucy");//只调用了 一次 有参构造 和 一次 析构函数，即有参构造 是 匿名对象 调用的。  用p1 这个名字去接替 匿名构造 构造出的空间。（没有再创建一个类来调用拷贝构造）
                Person P2 = Person(p1);       //显示法 调用 拷贝构造函数
                Person P3 = Person();         //显示法 调用 无参构造
            3.隐式法调用：
                Person p1 = {10,"lucy"};      //隐式法 调用    有参构造
                Person P2 = p1;               //隐式法 调用    拷贝构造
                Person P3;                    //隐式法 不能调用 无参构造

            关键字：explicit，修饰构造函数，不能通过隐式法调用构造函数。

        例如：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //无参构造
                explicit Person()
                {
                    cout << "无参构造!" << endl;
                }

                //有参构造
                explicit Person(int age,string name)
                {
                    cout << "有参构造" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
                //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
                //关键字：explicit。作用：用户不能通过隐式法调用构造函数
                explicit Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"拷贝构造"<<endl;
                }

                ~Person()
                {
                    cout << "析构函数" << endl;
                }
            };

            void test()
            {
                //匿名对象，没有名字，其生命周期在当前行。
                Person(10,"lucy");//调用有参构造创建匿名对象，
                Person();//匿名对象调用无参构造需要加括号
                Person p1(10,"lisa");
                //Person(p1);//错误，匿名对象 不能使用 括号法 调用 拷贝构造。
            }

            //显示法调用构造函数
            void test1()
            {
                Person p1 = Person(10,"lucy");//只调用了 一次 有参构造 和 一次 析构函数，即有参构造 是 匿名对象 调用的。  用p1 这个名字去接替 匿名构造 构造出的空间。（没有再创建一个类来调用拷贝构造）
                Person P2 = Person(p1);       //显示法 调用 拷贝构造函数
                Person P3 = Person();         //显示法 调用 无参构造
            }

            //隐式法 调用 构造函数
            //若想 别人不能使用隐式法 来调用你的构造函数，则可在构造函数前 加关键字：explicit，用户不能通过隐式法调用构造函数
            void test2()
            {
            //    Person p1 = {10,"lucy"};      //隐式法 调用    有参构造
            //    Person P2 = p1;               //隐式法 调用    拷贝构造
            //    Person P3;                    //隐式法 不能调用 无参构造
            }
            int main()
            {
                test1();
                return 0;
            }

        拷贝构造函数的调用时机
            总结：就一种情况，旧对象 初始化 新对象。
            分类：
                * 旧对象初始化新对象
                * 形参  作为对象
                * 返回值作为对象
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //无参构造
                explicit Person()
                {
                    cout << "无参构造!" << endl;
                }

                //有参构造
                explicit Person(int age,string name)
                {
                    cout << "有参构造" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
                //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
                //关键字：explicit。作用：用户不能通过隐式法调用构造函数
                Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"拷贝构造"<<endl;
                }

                ~Person()
                {
                    cout << "析构函数" << endl;
                }
            };

            //1.旧对象初始化新对象
            void test1()
            {
                Person p(10,"lili");
                Person p1(p);   //调用拷贝构造
                Person p2 = Person(p);//显示法调用 拷贝构造函数
                Person p3 = p;//隐式法调用拷贝构造，相当于 Person p2 = Person(p);
            }

            //2.传递的参数是普通对象，函数参数也是普通对象，传递将会调用拷贝构造。
            void doBussiness(Person p){}    //Person p = p;

            void test2()
            {
                Person p(20,"lisa");//有参构造初始化
                doBussiness(p); //拷贝构造，旧对象初始化新对象
            }

            //3.函数 返回值。返回值局部对象
            Person MyBusiness()
            {
                Person p(30,"lihua"); //有参构造 初始化局部对象
                cout << "局部p:"<<(int *)&p <<endl;   //输出局部对象的地址
                return p;   //这里返回的时候 应该调用一次拷贝构造，返回一个匿名对象
            }

            void test3()
            {
                // vs release、 qt下没有调用拷贝构造函数
                // vs debug 下调用一次拷贝构造函数
                Person p = MyBusiness();//这里赋值 也应该调用一次拷贝构造。由于编译器有优化，使得直接将p命名给了匿名对象。
                //
                cout << "局部p:"<< (int*) &p << endl; //输出局部对象返回的地址，（课程里两次打印的地址是不同的，因为 函数返回时 是调用 匿名拷贝构造，重新开辟的内存空间）而我的两个地址是一样的。故销毁也只销毁一次，他销毁两次。
            }

            int main()
            {
                test3();
                return 0;
            }

      c++默认增加的函数
            默认情况下，c++编译器至少为我们写的类增加3个函数

            1. 默认构造函数（无参，函数体为空）
            2. 默认析构函数（无参，函数体为空）
            3. 默认拷贝构造函数，对类中非静态成员属性 简单值拷贝
               如果用户定义了拷贝构造函数，         c++不会再提供任何默认构造函数
               如果用户定义了普通构造函数（非拷贝），c++不会再提供任何默认无参构造，但会提供默认拷贝构造

    4.3.6 深拷贝 和 浅拷贝
        4.3.6.1 浅拷贝
            简单的值拷贝，可能导致析构函数释放同一块空间
        例：
        #define _CRT_SECURE_NO_WARNINGS
        #include <iostream>
        #include <string.h>
        #include <string>
        using namespace std;

        class Person
        {
        public:
            int m_age;
            char* m_name;

            Person(int age,char *str)
            {
                cout << "有参构造"<<endl;
                m_age = age;
                m_name = (char*)malloc(strlen(str)+1);
                strcpy(m_name,str);
            }

            void show()
            {
                cout << m_name << " " <<m_age<<endl;
            }

            ~Person()
            {
                cout << "析构"<<endl;
                if(m_name != NULL)
                {
                    free(m_name);
                    m_name = NULL;
                }
            }
        };

        void test()
        {
            Person p(10,"lihua");
            p.show();
            Person p1(p);//调用默认拷贝构造 进行简单值拷贝，字符串指针指向同一块地址。因此运行到出函数时，两个对象的析构函数分别free同一地址，导致程序错误。
        }
        int main()
        {
            test();
            return 0;
        }

        4.3.6.2 深拷贝
            重新开辟内存空间用于存放
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                int m_age;
                char* m_name;

                Person(int age,char *str)
                {
                    cout << "有参构造"<<endl;
                    m_age = age;
                    m_name = (char*)malloc(strlen(str)+1);
                    strcpy(m_name,str);
                }

                Person(const Person &p)
                {
                    m_age = p.m_age;
                    m_name = (char *)malloc(strlen(p.m_name)+1);
                    strcpy(m_name,p.m_name);
                }
                void show()
                {
                    cout << m_name << " " <<m_age<<endl;
                }


                ~Person()
                {
                    cout << "析构"<<endl;
                    if(m_name != NULL)
                    {
                        free(m_name);
                        m_name = NULL;
                    }
                }
            };

            void test()
            {
                Person p(10,"lihua");
                p.show();
                Person p1(p);//调用默认拷贝构造 进行简单值拷贝，字符串指针指向同一块地址。因此运行到出函数时，两个对象的析构函数分别free同一地址，导致程序错误。
            }
            int main()
            {
                test();
                return 0;
            }
*/
/*
    4.3.7 多个对象 构造 和 析构
        4.3.7.1 初始化列表
            构造函数 和 其他函数不同，除了有名字，参数列表，函数体之外，还有初始化列表。
            初始化列表简单使用：Person(int a,int b, int c):mA(a),mB(b),mC(c){}
                            //给构造函数成员赋值的时候，可以把赋值的方式写在函数的后面
            注意：
                * 初始化列表：先声明 在调用构造函数时 定义 并 初始化，定义 初始化的顺序 需要同声明一致。
                * 普通的构造函数：先定义，再赋值。
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                using namespace std;

                class Person{
                public:
                #if 0
                    //传统方式初始化:先在外面 定义 变量，再在这里初始化赋值。相当于下面是定义，这里是初始化
                    Person(int a,int b,int c)
                    {
                        mA = a;
                        mB = b;
                        mC = c;
                    }
                #endif
                    //初始化列表方式初始化:先 声明 变量，再根据 声明的顺序 进行定义初始化。相当于下面三个只是声明，在这里冒号后面才是 定义 和 初始化。
                    //注意：这里定义的顺序，就是冒号后面的顺序。定义的顺序需要同声明的顺序一致。
                    Person(int a,int b, int c):mA(a),mB(b),mC(c){}//给构造函数成员赋值的时候，可以把赋值的方式写在函数的后面

                    void printperson(){
                        cout << "mA: " << mA << endl;
                        cout << "mB: " << mB << endl;
                        cout << "mC: " << mC << endl;
                    }
                private:
                    int mA;
                    int mB;
                    int mC;
                };

                void test()
                {
                    Person p(2,3,5);
                    p.printperson();
                }

                int main(){
                    test();
                    return 0;
                }
        4.3.7.2 类对象 作为 成员
            在类中 定义的数据成员 一般都是基本的数据类型。但是，类中的成员 也可以是 对象，叫做 对象成员。
            C++中当创建一个对象的时候，c++编译器 必须确保调用了所有 子对象的构造函数。如果所有的子对象 有默认构造的函数，编译器可以自动调用他们。但是如果子对象没有默认的构造的数，或想指定调用某个构造函数怎么办?
            那么是否可以在 类的构造函数 直接调用 子类的属性 完成初始化呢?但是如果子类的成员属性是私有的，我们是没有办法访问并完成初始化的。
            解决办法非常简单:对于子类调用构造函数，c++为此提供了专门的语法，即  构造函数初始化列表。
            当调用构造函数时，首先按各对象成员在类定义中的顺序(和参数列表的顺序无关)依次调用它们的构造函数。
            对这些对象初始化，最后再调用本身的函数体。也就是说，*先调用对象成员的构造函数*，*再调用本身的构造函数*。
            *析构函数和构造函数调用顺序相反，先构造，后析构。*

            总结:
                * 类中有多个对象时,构造的顺序是 先构造里面的再构造外面的对象
                * 类中有多个对象时,析构时顺序是 先析构外面的再析构外面的对象
        例:
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Game
            {
              public:
                Game(string name)
                {
                    cout << "game 的构造函数" << endl;
                    gam_name = name;
                }
                ~Game()
                {
                    cout<< "game 的析构"<<endl;
                }
                string gam_name;
            };
            class Phone
            {
            public:
                //构造函数：
                Phone(string name)
                {
                    cout << "phone 的构造函数" << endl;
                    pho_name = name;
                }
                ~Phone()
                {
                    cout<< "phone 的析构"<<endl;
                }
                string pho_name;


            };
            class Person
            {
            public:
                //由于这么写是先定义三个变量，而定义的类没有无参构造，所以定义会出错。因此要使用 初始化列表来进行初始化

//                Person(string per_name1,string pho_name1,string gam_name1)
//                {
//                    per_name = per_name1;
//                    phone.pho_name = pho_name1;
//                    game.gam_name = gam_name1;
//                }

                Person(string per_name1,string pho_name1,string gam_name1):per_name(per_name1),phone(pho_name1),game(gam_name1){
                    cout << "person 的构造函数" << endl;
                }

                void show()
                {
                    cout << per_name<<"拿着" <<phone.pho_name<<"玩"<<game.gam_name << endl;
                }

                ~Person()
                {
                    cout<< "person 的析构"<<endl;
                }
                string per_name;
                Phone phone; //一个对象作为另一个对象的成员。
                Game game;
            };

            void test()
            {
                Person p1("Bob","诺基亚","原神");
                p1.show();
            }
            int main()
            {
                test();
                return 0;
            }

            //phone 的构造函数
            //game 的构造函数
            //person 的构造函数
            //Bob拿着诺基亚玩原神
            //person 的析构
            //game 的析构
            //phone 的析构
            //由此知,先构造里面的在构造外面的,先析构外面的再析构里面的
*/

/*

    4.3.8 explicit 关键字
        c++ 提供了关键字 explicit,禁止通过构造函数进行隐式转换，声明为explicit的构造函数不能在隐式转换中使用。
        注意：
            explicit 用于修饰构造函数，防止隐式转化
            是针对单参数的构造函数（或者除了第一个参数外其余参数都有默认值的多参构造）而言。
 */

/*
    4.3.9 动态对象创建
        当创建数组时，总需要提前预定数组长度，再编译器分配预定长度的数组空间，在使用数组时也许空间太大或不足，所以若能根据需要进行分配空间大小就好了
        所以 动态 即为 不确定性。
        为了解决该编程问题，在运行中可以创建和销毁对象是最基本的要求，当然c早就提供了动态内存分配，然而，这些函数在c++中不能很好地运行，因为他不能帮我们完成对象的初始化工作。

        （由于malloc和free在创建和销毁空间的时候 不会调用构造和析构函数，因此涉及到对象的动态创建方法：new、delete）
        例如：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>

                using namespace std;
                class Person
                {
                public:
                    Person()
                    {
                        cout << "Person 的无参构造" << endl;
                    }
                    int a;
                    ~Person()
                    {
                        cout << "Person 的析构函数" << endl;
                    }
                };

                void test()//函数调用时 不会调用构造和析构函数
                {
                    Person *p = (Person *)malloc(sizeof(Person));
                    free(p);
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.9.1 对象创建
            当创建一个c++对象会发生两件事
            1. 为对象分配内存
            2. 调用构造函数 来初始化 该内存

            第一步一定能实现，但还需确保第二步一定能发生。c++强迫我们这么做是因为使用未初始化的对象是程序出错的一个重要原因。

            类型 *p = new 类型;
            delete p;

            类型 *p = new 类型[n]
            delete []p;

        4.3.9.2 C动态分配内存方法
            为了在运行时动态分配内存，c在他的标准库中提供了一些函数，malloc以及它的变种 calloc和realloc释放内存的free,这些函数是有效的、但原始的，需要程序员理解和小心使用。(为了使用c的动态内存分配函数在堆上创建一个类的实例，我们必须这样做：)

            问题：
                1. 程序员必须确定对象的长度。
                2. malloc返沪一个void指针，c++不允许将void赋值给其它任何指针，必须强转。
                3. malloc可能申请内存失败，故必须判度返回值来确保内存分配成功。
                4. 用户在使用对象之前必须记住对他初始化，构造函数不能显示调用初始化（构造函数是由编译器调用），用户有可能忘记调用初始化函数。

                c的动态内存分配函数太复杂，容易令人混淆，是不能接受的，c++中我们推荐使用运算符new和delete.

        4.3.9.3 new operatoe
            c++中解决动态内存分配的方案是把创建一个对象所需要的操作都结合在一个称为new的运算符里。
            当new创建一个对象时，他就会在 堆 里为对象分配内存并调用构造函数完成初始化
        用法：
            类型 * p = new 类型;
            Person* person = new Person;

        相当于：
            Person* person = (Person *)malloc(sizeof(Person));
            if(person == NULL)
            {
                return 0;
            }
            person->Init();//构造函数。

            new操作符 能确定在调用构造函数初始化之前内存分配是成功的，所以不用显式确定调用是否成功。
            现在我们发现在堆里创建对象的过程变得简单了，一个表达式，他内置的长度计算、类型转换和安全检查。这样在堆创建一个对象和在栈里创建对象一样简单。

        4.3.9.4 delete operator
            new 表达式的 反面是 delete 表达式。delete 表达式先调用析构函数，然后释放内存。正如 new 表达式返回一个 指向对象的指针 一样，delete 需要一个对象的地址。
            delete 只适用于由 new 创建的对象。

            如果使用一个由 malloc 或者 calloc或者realoc创建的对象使用 delete,这个行为是未定义的。因为大多数 new 和 delete 的实现机制都使用了malloc和free,所以很可能没有调用析构函数就释放了内存。
            如果正在删除的对象的指针 是 NULL,将不发生任何事，因此建议在删除指针后，立即把指针赋值为 NULL，以免对它删除两次，对一些对象删除两次可能会产生某些问题。
        4.3.9.5 用于数组的 new 和 delete
            使用new 和 delete 在堆上创建数组：

        4.3.9.6 delete void *可能会出错
            如果对一个void *指针执行delete操作，这将可能成为一个程序错误，除非指针指向的内容非常简单，因为他不会执行析构函数，例如以下代码未调用析构函数，导致可用内存减少

        4.3.9.7 使用new和delete采用相同形式
            即：
                Person *p = new Person[10];
                delete []p;

    new和delete的使用，例：

            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            #include <stdlib.h>
            using namespace std;

            class Person
            {
            public:
                Person()//无参调用
                {
                    cout << "无参构造" << endl;
                }
                Person(int a)//有参调用
                {
                    age = a;
                    cout << "有参构造" << endl;
                }
                int age;
                ~Person()
                {
                    cout << "析构函数" << endl;
                }
            };

            //new一个数
            void test()
            {
                int *p = new int;//申请一块sizeof(int)大小的堆空间。并且对这块空间进行初始化。
                cout << *p << endl;//并且对这块空间进行初始化
                *p = 100;
                cout << *p << endl;
                delete p;//释放申请的空间。
            }
            //new一个对象
            void test1()
            {
                Person * p = new Person;
                delete p;

            }
            //new一个有参构造和 对象数组
            void test3()
            {
                //new时 调用有参构造
                Person * p =new Person(10);
                delete p;
                Person * a =new Person[10];//注意new数组时，不能调用有参构造，只能调用无参构造。
                delete []a;//
            }
            //new一个数组
            void test2()
            {
                //new一个数组时返回的是其首元素地址。
                int*p = new int[10];
                for(int i = 0;i<10;i++)
                {
                   cout << (p[i] = i+100)<< endl;
                }
                delete []p;//如果这样写只会释放首个元素和首元素地址。后面的不会释放，因此释放数组应写为：delete [] p;
            }
            void test4()
            {
                void* p = new Person;
                delete p;   //p类型是void *所以不会调用析构函数
            }
            int main()
            {
                test2();
                return 0;
            }




*/

/*
  4.3.10 静态成员
    在类 定义中，它的成员（包括成员变量和成员函数），这些成员可以用关键字static声明为静态的，称为静态成员。
    不管这个类创建了多少个对象，静态成员只有一个拷贝，这个拷贝被所有属于这个类的对象共享。

    4.3.10.1 静态成员变量
        在一个类中，若将一个成员 变量声明为static ，这种成员称为 静态成员变量。
        注意：
            1. 静态成员变量 与 一般的数据成员 不同，无论建立了多少个对象，都只有一个静态数据的拷贝。静态成员变量，属于某个类，所有对象共享。
            2. 静态变量，是在 编译阶段就分配空间，对象还没有创建时，就已经分配空间。
            3. 静态成员变量必须在 类中 声明，在 类外 定义。
            4. 静态数据成员 不属于某个对象，在为对象分配空间中 不包括 静态成员所占空间。
            5. 静态数据成员 可以通过 类名 或 对象名 来引用。

           总结：
            * 静态成员变量在内存中只有一份，多个对象共享一个静态变量
            * 静态成员变量必须类内声明，类外定义
            * 静态成员变量可以通过类的作用域来访问，
            * 静态成员变量还可以通过实例化类的对象来访问。

            例：
                //静态成员变量
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                  public:
                    int a;       //局部变量是在运行阶段就确定好了内存的地址。
                    //静态成员变量不能在类内初始化，只能在类内声明，定义在全局。声明的作用只是限制了静态成员变量的作用域。并且，静态变量是存在静态全局区。
                    static int b;//静态成员变量，在编译阶段就分配好了内存。初始化：不能在类内初始化，如：static int b = 10;就会报错，因为他在编译器件就确定好了地址，而每次定义对象的时候就会修改它，是会出错的
                };
                int b;//这是作用在全局区域下的变量b，不表示为Person类下的成员
                int Person::b = 10; //所以应该加一个Person的作用域。

                //静态成员变量的实例化使用
                void test()
                {
                    Person p;
                    p.b = 100;
                    cout << p.b <<endl;
                }
                //静态成员变量的作用域使用，并与普通成员变量进行对比
                void test1()
                {
                    //这样也是可以的，因为虽然没有定义对象，但由于b在编译阶段就已经分配好了空间，并且初始化的值为10。
                    cout << Person::b <<endl;//通过类的作用域来访问类的静态成员函数
                    //cout << Person::a <<endl;// 错误，不能访问a.必须实例化一个对象才会有a。
                }
                //静态成员变量独此一份
                void test2()
                {
                    Person p;
                    p.b = 100;
                    cout << p.b <<endl; //100
                    Person k;
                    k.b = 200;
                    cout << p.b <<endl; //200 ,因此静态成员变量独此一份。
                }

                int main()
                {
                    test2();
                    return 0;
                }

        4.3.10.2 静态成员函数
            在类定义中，前面有static修饰的成员函数 称为 静态成员函数。静态成员函数使用方式和静态变量一样，同样在对
            象没有创建前，即可通过类名调用。静态成员函数主要为了访问静态变量，但是，不能访问普通成员变量。
            静态成员函数的意义，不在于信息共享，数据沟通，而在于管理静态数据成员，完成对静态数据成员的封装。

        注意：
            静态成员函数的使用和静态成员变量一样: 可通过作用域 和 对象访问
            静态成员函数也有访问权限
            普通成员函数 可访问 静态成员变量、也可以访问非静态成员变量
            静态成员函数 只能 访问静态变量，不能访问 普通成员变量
        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                public:
                    int a;
                    static int b;

                    void show()
                    {
                        cout << a << " " << b <<endl;
                    }

                    //静态成员函数，可以访问静态成员变量，不能访问 非静态成员变量（普通成员变量）。
                    //因为静态成员函数在编译的时候就已经有了，因此，可以用作用域来调用，即：Person::static_show()，此时对象都还没创建，还没有创建a,因此访问不了a
                    static void  static_show()
                    {
                //        cout << a << " " << b <<endl;//a不能访问，
                        cout << "静态成员函数！" <<endl;
                    }

                };

                int Person::b = 10;

                void test()
                {
                    Person::static_show();//通过类的作用域访问静态成员函数

                    Person p1;
                    p1.static_show();//通过对象访问静态成员函数
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.10.3 const修饰的静态成员属性
            如果一个类的成员，既要实现共享，又要实现不可改变，则需使用 static const 修饰，定义静态 const 数据成员时，最好在类内部初始化。

        总结：
            * const 修饰的静态成员变量 保存在 常量区。是只读的，在内存中只有一份
            * const 修饰的静态成员变量 可以在类内定义，且 初始化，与静态成员变量是不同的（类内声明，类外定义）
            * const 修饰的静态成员变量 可以通过类的作用域进行访问
            * const 修饰的静态成员变量 可以通过对象访问。
            * 静态成员函数 可以访问 const 修饰的静态成员变量。（编译时，静态成员函数以及存在）

        例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                public:
                    int a;

                    //静态成员变量不能在类内初始化，只能在类内声明，定义在全局。声明的作用只是限制了静态成员变量的作用域。并且，  静态变量是 存在 静态全局区，是可以被改变的。
                    static int b;//静态成员变量，在编译阶段就分配好了内存。初始化：不能在类内初始化，如：static int b = 10;就会报错，因为他在编译器件就确定好了地址，而每次定义对象的时候就会修改它，是会出错的

                    const static int c = 1000;// const 修饰的全局变量保存在常量区， 同理，const 修饰的静态成员变量 是保存在 常量区，不可被修改（只读的），在内存也中只有一份。const 修饰的静态成员变量是一个常量，可以在类里面赋值。不用放在类外再实现定义赋值。
                    //并且由于他是const 修饰的静态成员变量， 因此在编译的时候也定义好了，静态成员函数可以直接访问。

                    void show()
                    {
                        cout << a << " " << b <<endl;
                    }

                    //静态成员函数，可以访问静态成员变量，不能访问 非静态成员变量（普通成员变量）。
                    //因为静态成员函数在编译的时候就已经有了，因此，可以用作用域来调用，即：Person::static_show()，此时对象都还没创建，还没有创建a,因此访问不了a
                    static void  static_show()
                    {
                //        cout << a << " " << b <<endl;//a不能访问，
                        cout << "静态成员函数！" <<endl;
                        cout << c << endl;
                    }

                };

                int Person::b = 10;

                void test()
                {
                    cout << Person::c << endl;//可以通过作用域进行访问。

                    Person p;
                    cout << p.c <<endl;// 也可以通过定义一个对象来访问。

                    p.static_show();//静态成员函数 也可以直接调用 const 修饰的静态成员变量。

                }

                int main()
                {
                    test();
                    return 0;
                }
        4.3.10.4 静态成员实现 单例模式:（一个类只能创建出一个对象）
            例如主席的位置只有一个，电脑的任务管理器。这样可以节省资源

            单例模式 是一种常用的软件设计模式。其核心结构中只包含一个被成为单例的特殊类。通过单例模式 可以保证系统中一个类只有一个实例，而且，该实例易于外界访问，从而方便对实例个数的控制并节约系统资源
            如果希望在系统中某个类的对象只能存在一个，单例模式是最好的解决方案。


            Singleton(单例):在单例类的内部实现只生成一个实例，同时它提供一个静态的 getinstance()工厂方法，让客户可以访问它的唯一实例;
            为了防止在外部对其实例化，将其 默认构造函数 和 拷贝构造函数 设计为私有;
            在 单例类 内部定义了一个 singleton 类型的静态对象，作为外部共享的唯一实例。

            用单例模式，模拟公司员工使用打印机场景，打印机可以打印员工要输出的内容，并且可以累积打印机使用次数。

        总结：单例 的实现 4步骤： （3私有，1接口）
             1. 私有化 构造函数
             2. 私有化 拷贝函数
             3. 私有化 静态成员指针变量指向new出来的唯一的对象(外部定义)。
             4. 定义静态成员函数接口，提供获得唯一对象的地址的静态接口。

        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Feifei
                {
                public:
                    int age;
                    int yanzhi;

                    //4.思考方式：由于在外面无法再创建对象，故在里面new一个对象
                    //5.但由于它是 成员变量，需要先有对象，才会有这个成员变量。
                    //6.但实例化不出对象，故仍然得不到这个变量。因此需要将变量变成静态的，加static进行修饰,让其成为静态成员变量。
                    //static Feifei* single;//7.静态成员变量，类内声明，类外定义

                    //11.定义一个接口,静态的成员函数(普通的成员函数需要对象调用)
                    static Feifei * instance()
                    {
                        return single;//将single返回，让其只读，不能修改。
                    }
                private:
                    static Feifei *single;

                    Feifei()//无参构造私有化。
                    {

                    }
                    Feifei(const Feifei&p)
                    {

                    }
                };
                //8.定义静态成员变量，完成单例的实现。但有一个问题:调用拷贝构造仍然可以实现后面的对象构造,因此需要将拷贝构造也进行私有化。
                Feifei * Feifei::single= new Feifei;//类外定义

                void test()
                {
                    //1.事先得不到只创建一个对象的类
                    //2.故先得一个，一个对象都创建不了的类，即：构造函数私有化。（由于对象的创建需要调用无参构造，如果让他调用不了无参构造，则无法创建对象。）
                //    Feifei p;   //3.由于无参构造是私有的，因此都不能创建对象。
                //    Feifei p1;//

                    // 2.1通过类的作用域实现对single的操作。
                //    Feifei::single->age = 30;         //12.由于接口函数的出现，不能再用此方法使用single
                //    Feifei::single->yanzhi = 100;

                     //9.调用拷贝构造 实例化出 另一个对象,因此,需要将拷贝构造也进行私有化
                    //Feifei p1(*Feifei::single);

                    //10.还有一个问题，若不小心将single 的地址赋值为 NULL，则再也不能找到其地址，因此也需要将创建私有化
                }

                void test1()
                {
                    //13.单例的使用
                    Feifei *p = Feifei::instance();//获得唯一指针
                    p->age = 30;
                    p->yanzhi = 100;

                    Feifei *p1 = Feifei::instance();
                    cout << p1->age<< " " << p1->yanzhi <<endl;
                }

                int main()
                {
                    test1();
                    return 0;
                }

*/

/*
    4.4 c++面向对象模型初探
        4.4.1 成员变量 和 函数 的储存
            （在类里面 哪些变量和函数是存在于对象里面的？    哪些变量又不属于类里面？只是仅仅声明在这个类里面。（例如静态成员变量，是存于静态全局区的））
            在c语言中，“分开来声明的，也就是说，语言本身并没有支持"数据"和"函数"之间的关联性我们把这种程序方法称为“程序性的"，由一组“分布在各个以功能为导航的函数中”的算法驱动，它们处理的是共同的外部数据。

            c++实现了“封装”，那么数据(成员属性)和操作(成员函数)是什么样的呢?
            "数据"和“处理数据的操作(函数)"是分开存储的。

            c++中的非静态数据成员直接内含在类对象中，就像c struct一样。
            成员函数(member function)虽然内含在 class 声明之内，却不出现在对象中。
            每一个非内联成员函数(non-inline member function)只会诞生一份函数实例.

        总结：给对象申请内存时，仅普通成员变量才会占用对象的空间。
            * 类对象成员 普通成员变量 占用 对象空间大小
            * 类对象成员 静态成员变量 不占用 对象空间大小
            * 类对象成员 普通成员函数 不占用 对象空间大小
            * 类对象成员 静态成员函数 不占用 对象空间大小

        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;


                //由此知：只有普通成员变量 才属于这个 类的实例化对象 的一个内存。（给对象申请内存时，仅普通成员变量才会占用对象的空间）
                class Person
                {
                public:
                    int a;//普通成员变量
                    static int b;//静态成员变量不存在于类实例化的对象中，只是声明在类中。存放在静态全局区。

                    //俩函数存放在代码区。
                    void show()//普通成员函数，也不存在于类实例化的对象中
                    {
                        cout << a << " " << b << endl;
                    }
                    static void show1()//静态成员函数，也不存在于类实例化的对象中
                    {
                        cout << b << endl;
                    }

                };

                int Person::b = 1;
                void test()
                {

                    //1. 空类的大小是1 不是0（有地址，故有空间大小）
                    //2. 再加上 普通成员变量 a 后 为 4字节。
                    //3. 再加上 静态成员变量 b 后 为 4字节，可见静态成员变量不属于类
                    //4. 再加上 普通成员函数 大小仍为4，可见，new一个对象后，成员函数并不会占用类的这个对象的空间大小
                    Person p;
                    p.show();
                    p.show1();
                    cout << sizeof(Person) <<endl;
                }
                int main()
                {
                    test();
                    return 0;
                }
        4.4.2 this 指针
            4.4.2.1 this指针的工作原理：
                通过上例我们知道，c++的 数据 和 操作 也是分开存储，并且每一个非内联成员函数(non-inline member function)只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码。
                那么问题是:这一块代码是如何区分哪个对象调用自己的呢?

                c++通过提供特殊的对象指针，this 指针，解决上述问题。this 指针指向被调用的成员函数所属的对象。
                c++规定，this 指针是隐含在对象成员函数内的一种指针。当一个对象被创建后，它的每一个成员函数都含有一个系统自动生成的隐含指针this，用以保存这个对象的地址，也就是说虽然我们没有写上this 指针，编译器在编译的时候也是会加上的。
                因此 this 也称为“指向本对象的指针"，this 指针并不是对象的一部分，不会影响 sizeof(对象)的结果。

                this 指针是C++实即封装的一种机制，它将对象和该对象调用的成员函数连接在一起，在外部君来，每一个对象都拥有自己的函数成员。一般情况下，并不写this,而是让系统进行默认设置。this 指针永远指向当前对象。
                成员函数通过 this 指针即可知道操作的是那个对象的数据。This 指针是一种隐含指针,它隐含于每个类的非静态成员函数中。This指针无需定义，直接使用即可。

            注意:静态成员函数 内部 没有this指针，静态成员函数 不能操作 非静态成员变量。
                c++编译器对普通成员函数做了一个内部处理。

            总结：
                * 类的成员函数默认编译器加上了this指针，这个this指针指向调用该成员函数的对象。（Person * const this）

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Person
                    {
                    public:
                        int a;
                        static int b;

                        //由于函数存在于代码区，只有一份，则问题是调这个函数 打印 a的时侯，怎么知道是p还是p1的a?
                        //因为，类的成员函数后面 编译器 默认加了一个参数: Person * const this   ; this指针 指向 调用该函数的对象，故，谁调用该函数，函数就获得谁的地址。
                        //对象调用成员函数，会将对象的地址传给this指针。
                        void show() //Person * const this，编译器默认加了这个类型。(指针常量，this的指向不能改变)
                        {
                            cout << a << " " << b << endl;          //所以这里就变成了 cout << this->a << " "  << this->b << endl;
                        }
                        static void show1()
                        {
                            cout << b << endl;
                        }

                    };

                    int Person::b = 1;

                    void test()
                    {
                        Person p1;
                        p1.a = 100;

                        Person p2;
                        p2.a = 1000;

                        //show函数存在代码区，仅一份，p1对象调用函数的时候，函数怎么知道是打印p1还是p2的a?
                        p1.show();
                        p2.show();
                    }

            4.4.2.2 this 指针的使用
                当 形参 和 成员变量 同名 时，可用this指针来区分
                在类的非静态成员函数中返回对象本身，可以使用 return *this.
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Person
                    {
                    public:
                        Person(int age,string name) //因为每个成员函数都会有一个this指针，指向调用成员函数的对象的地址。故this指针指向 p的地址。
                        {
                    //        age = age;     //这里两个 age 和 name都是指的形参。不会进行赋值
                    //        name = name;

                            this->age = age;
                            this->name = name;
                        }
                        int age;
                        string name;
                        void show()
                        {
                            cout << age << " " << name << endl;
                        }

                        Person person_add(Person &p1)// 写在类里，作为成员函数，实现相加
                        {
                            Person p(this->age+p1.age,this->name+p1.name);
                            return p;
                        }

                    };

                    //类外定义作为 全局函数 实现相加
                    Person person_add(Person &p1,Person &p2)
                    {
                        Person p(p1.age+p2.age,p1.name+p2.name);
                        return p;
                    }

                    void test()
                    {
                        Person p(10,"lucy");
                        p.show();
                    }
                    void test1()
                    {
                        Person p1(10,"hello");
                        Person p2(20,"world");

                        //实现：p3 = p1+p2 30 helloworld

                        //方法一、全局函数
                        Person p3 = person_add(p1,p2);
                        p3.show();

                        //方法二、成员函数
                        Person p4 = p1.person_add(p2);
                        p4.show();

                    }
                    int main()
                    {
                        test1();
                        return 0;
                    }

            4.4.2.3 const 修饰的成员函数
                由于成员函数 的this指针类型为： Person * const this。因此this本身地址不能改变，但其指向的内容可以改变，如this->age = 200;这可能会导致其它问题。

            总结：
                * 在成员函数后面加上 const,这是一个常函数，
                * 这个const 修饰的是this指针，使其成为 常量指针常量: const Person * const this
                * 常函数 不能通过 this指针修改其指向空间的内容。

            例子：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Person
                    {
                    public:
                        Person(int age,string name)
                        {
                            this->age = age;
                            this->name = name;
                        }
                        int age;
                        string name;
                        void show()
                        {
                            cout << age << " " << name << endl;
                        }

                        //Person * const this -----> p1     //因此应改为 常量指针常量：const Person * const this，这样指针指向的的空间内容便不能修改
                        //由于Person * const this 被隐藏了，因此const 直接放后面：Person person_add(Person &p1)const
                        //成员函数后面加了 const这种函数，称为 常函数。不能通过this指针修改其指向的对象内容。
                        Person person_add(Person &p1) const
                        {
                    //        this->age = 100;
                            Person p(this->age+p1.age,this->name+p1.name);
                            return p;
                        }

                    };

                    void test()
                    {
                        Person p(10,"lucy");
                        p.show();
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }


*/

/*
    4.5 友元（插入到4.3.1）
        类 的主要特点之一是数据隐藏， 即 类的私有成员 无法在 类的外部(作用域之外)访问。
        但是，有时候需要 在类的外部 访问 类的私有成员，怎么办?
        解决方法是使用友元函数，友元的函数是一种特权函数，c++允许这个特权函数访问私有成员。这一点从现实生活中也可以很好的理解:
        比如你的家，有客厅，有你的室，那么你的客厅是Public的，所有来的客人都可以进去，但是你的卧室是私有的。也就是说只有你能进去。但是呢。你也可以允许你的闺蜜好基友进去。
        码农 可以把 一个全局函数、某个类中的成员函数、甚至整个类 声明为友元。

        * 如果想让全局函数 或 一个类的成员函数 访问 另一个类的私有成员。只需要声明 友元 即可。
        4.5.1 友元语法
            friend 关键字只出现在声明处
            其它类、类成员函数、全局函数都可声明为友元
            友元函数不是类的成员，不带this指针
            友元函数可访问对象任意成员属性，包括私有属性

            4.5.1.1 全局函数成为类的友元：

                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Building
                    {
                        friend void print_building(Building &p);// 加friend声明该函数是该类的友元，此时函数就可以访问该类的私有成员了。
                    public:
                        Building(string hall,string bedroom)
                        {
                            this->bedroom = bedroom;
                            this->hall = hall;
                        }
                        string hall;
                    private:
                        string bedroom;
                    };

                    void print_building(Building &p)
                    {
                        cout << p.hall <<" " <<p.bedroom <<endl;//b访问不了私有成员，因此可以使用友元，把这个全局函数声明为这个类的友元，就可以访问私有成员了
                    }

                    void test()
                    {
                        Building b1("凌霄殿","闺房");
                        print_building(b1);
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

            4.5.1.2 一个类 成为 另一个类的友元 以及 类的成员函数 成为 另一个类的友元
            例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Building;//声明

                //好朋友类
                class Goodgay
                {
                public:
                    Goodgay(string hall,string bedroom);//构造函数，类内声明，类外实现。

                    void visit();//可以访问b对象的一个成员函数

                    Building *b;
                };

                //
                class Building
                {
                    friend class Goodgay;               //一个类          成为 另一个类的友元
                    friend void Goodgay::visit();       //一个类的成员函数 成为 另一个类的友元
                public:
                    Building(string hall,string bedroom)
                    {
                        this->bedroom = bedroom;
                        this->hall = hall;
                    }
                    string hall;
                private:
                    string bedroom;
                };


                //注意：这里使用类外声明，以及为何不能写在Building类定义的前面，是因为：这个函数如果类内实现的时候，new一个Building对象是new不出来的。因为上面并没有Building的定义，只有一个声明。
                Goodgay::Goodgay(string hall,string bedroom)
                {
                    //new一个Building对象，放到Goodgay里面的Building指针成员里面
                    Goodgay::b = new Building(hall,bedroom);
                }

                void Goodgay::visit()
                {
                    cout << b->hall << " " << b->bedroom << endl;//b不能访问类内的私有成员。
                }


                void test()
                {
                    Goodgay gd("凌霄殿","闺房");
                    gd.visit();
                }

                int main()
                {
                    test();
                    return 0;
                }


        4.5.2 课堂练习
            1.编写电视机类，有开机和关机状态，有音量，频道，提供音量操作的方法，频道操作的方法。由于电视机只能逐一调整频道，不能指定频道，增加遥控类，遥控类除了拥有电视机已有的功能，再增加根据输入调台的功能。
            提示：遥控类可作电视机类的友元。
        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                //声明遥控器类
                class Remote;

                class Television
                {
                    friend class Remoter;
                public:
                    enum    //电视机状态
                    {
                        on,
                        off
                    };
                    enum    //音量从0~100
                    {
                        MIN_V = 0,
                        MAX_V = 100
                    };
                    enum    //频道从1~255
                    {
                        MIN_CH = 1,
                        MAX_CH = 255
                    };

                    Television()
                    {
                        mState = off;
                        mVolume = MIN_V;
                        mChannel = MIN_CH;
                    }

                    void power()
                    {
                        mState = mState ?off:on;
                    }

                    void volumeUp()
                   {
                        if(mVolume != MAX_V)
                        {
                            mVolume++;
                        }
                        showInfo();
                   }

                    void volumeDown()
                    {
                        if(mVolume != MIN_V)
                        {
                            mVolume--;
                        }
                        showInfo();
                    }

                    void channelUp()
                    {
                        if(mChannel != MAX_CH)
                        {
                            mChannel++;
                        }
                        showInfo();
                    }

                    void channelDown()
                    {
                        if(mChannel != MIN_CH)
                        {
                            mChannel--;
                        }
                        showInfo();
                    }

                    void showInfo()
                    {
                        if(mState)
                        {
                            cout << "status ON, volume " << mVolume << ", channel " << mChannel <<endl;  //输出格式也可以自行修改
                        }
                    }

                private:
                    int mState;     //电视状态
                    int mVolume;     //声音
                    int mChannel;    //频
                };

                //定义遥控器类
                class Remoter
                {
                private:
                   Television *mTv;

                public:
                   Remoter(Television *tv)
                   {
                        mTv = tv;
                   }
                   void power()
                   {
                        mTv->power();
                   }
                   void vUp()
                   {
                        mTv->volumeUp();
                   }
                   void vDown()
                   {
                        mTv->volumeDown();
                   }
                   void chUp()
                   {
                        mTv->channelUp();
                   }
                   void chDown()
                   {
                        mTv->channelDown();
                   }

                   void setChannel(int ch)
                   {
                        if(ch >= mTv->MIN_CH && ch <= mTv->MAX_CH)
                        {
                            mTv->mChannel = ch;
                            mTv->showInfo();
                        }
                   }
                };

                void test()  //测试函数可以根据自己需求修改
                {
                    Television *tv = new Television();
                    Remoter remoter(tv);
                    remoter.power();
                    remoter.setChannel(25);
                    remoter.vUp();
                    remoter.vUp();
                    remoter.vUp();
                    remoter.chDown();
                    remoter.power();
                    delete tv;
                }

                int main()
                {
                    test();
                    return 0;
                }

            2.强化训练（数组类封装）
            MyArray.h：

                #ifndef MYARRAY_H
                #define MYARRAY_H

                class MyArray {
                public:
                    //无参构造函数，用户没有指定容量，则初始化为100
                    MyArray();
                    //有参构造函数，用户指定容量初始化
                    explicit MyArray(int capacity);
                    //用户操作接口
                    //根据位置添加元素
                    void SetData(int pos, int val);
                    //获得指定位置数据
                    int GetData(int pos);
                    //尾插法
                    void PushBack(int val);
                    //获得长度
                    int GetLength();
                    //析构函数，释放数组空间
                    ~MyArray();
                private:
                    int mCapacity; //数组一共可容纳多少个元素
                    int mSize; //当前有多少个元素
                    int* pAdress; //指向存储数据的空间
                };

                #endif

            Myarray.cpp:

                #include"myarray.h"

                //无参构造，默认指定数组容量大小
                MyArray::MyArray() {
                    this->mCapacity = 100;
                    this->mSize = 0;
                    //在堆开辟空间
                    this->pAdress = new int[this->mCapacity];
                }
                //有参构造函数，用户指定容量初始化
                MyArray::MyArray(int capacity) {
                    this->mCapacity = capacity;
                    this->mSize = 0;
                    //在堆开辟空间
                    this->pAdress = new int[capacity];
                }
                //根据位置添加元素
                void MyArray::SetData(int pos, int val)
                {
                    if (pos < 0 || pos > mCapacity - 1) {
                        return;
                    }
                    pAdress[pos] = val;
                }
                //获得指定位置数据
                int MyArray::GetData(int pos) {
                    return pAdress[pos];
                }
                //尾插法
                void MyArray::PushBack(int val) {
                    if (mSize >= mCapacity) {
                        return;
                    }
                    this->pAdress[mSize] = val;
                    this->mSize++;
                }
                //获得长度
                int MyArray::GetLength() {
                    return this->mSize;
                }
                //析构函数，释放数组空间
                MyArray::~MyArray() {
                    if (this->pAdress != nullptr) {
                        delete[] this->pAdress;
                    }
                }


         TestMyArray.cpp：

                #include "MyArray. h"

                void test(){

                    //创建数组
                    MyArray myarray(50);
                    //数组中插入元素
                    for (int i =0; i< 50; i++){
                        //尾插法
                        myarray.PushBack(i);
                        //myarray.setData(i,i);
                    }
                    //打印数组中元素

                    for(int i=0;i< myarray.GetLength(); i++){
                        cout << myarray.GetData(i)<<" ";
                    }
                    cout << endl;
                }

*/

/*
    4.6 运算符重载
        4.6.1 运算符重载基本概念
            运算符重载，就是对已有的运算符重新进行定义，赋子其另一种功能，以适应不同的数据类型。

            运算符重载(operator overloading)只是一种"语法上的方便",也就是它只是另一种函数调用的方式。

            在 c++中,可以定义一个处理类的新运算符。这种定义很像一个普通的函数定义,只是函数的名字由关键字operator及其紧跟的运算符组成。差别仅此而己。它像任何其他函数一样也是一个函数，当编译器遇到适当的模式时，就会调用这个函数。

            语法:
                定义重载的运算符就像定义函数，只是该函数的名字是 operator @, 这里的@代表了被重载的运算符。函数的参数中参数个数取决于两个因素。
                    运算符是一元(一个参数)的还是二元(两个参数);
                    运算符被定义为 全局函数 (对于一元是一个参数，对于二元是两个参数) 还是 成员函数 (对于一元没有参数，对于二元是一个参数————此时该类的对象 用作 左耳参数)

            [两个极端]
                有些人很容易滥用运算符重载。它确实是一个有趣的工具。但是应该注意，它仅仅是一种语法上的方便而己，是另外一种函数调用的方式。从这个角度来看，只有在能使涉及类的代码更易写，尤其是更易读时(请记住，读代码的机会比我们写代码多多了)才有理由重载运算符。如果不是这样，就改用其他更易用，更易读的方式。

                对于运算符重载，另外一个常见的反应是恐慌:突然之间，C运算符的含义变得不同寻常了，一切都变了，所有C代码的功能都要改变!并非如此，对于内置的数据类型的表达式的的运算符是不可能改变的。(例如想重载 int类型数据的+号）

        总结:运算符重载，就是给运算符赋予一个新的意义。

            运算符只能运算内置的数据类型，         对于自定义的数据类型，不能运算
            int a = 3;                          Person a;
            int b = 2;                          Person b;
            int c = a+b;                        Person c = a+b;

            所以可以重载运算符。

        例1：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                public:
                    Person(int age)
                    {
                        this ->age = age;
                    }

                    //方法二：类的成员函数
                    Person Person_ADD(Person &p2)
                    {
                        Person p(this->age+p2.age);
                        return p;
                    }

                    //方法三：成员函数：operator+
                    Person operator+ (Person &p2)   //将方法二的函数名 改为 operator+ 即可。
                    {
                        Person p(this->age+p2.age);
                        return p;
                    }

                    int age;
                };

                //方法一：全局函数实现类的对象相加。
                Person Person_add(Person &p1,Person&p2)
                {
                    Person p(p1.age+p2.age);
                    return p;
                }

                //方法四、全局函数：operator+
                //Person operator+ (Person &p1,Person&p2)
                //{
                //    Person p(p1.age+p2.age);
                //    return p;
                //}

                void test1()
                {
                    Person p1(10);
                    Person p2(20);
                    //要使用p3.age = p1.age + p2.age;这种形式的话，编译器会先去找 方法三 和 方法四这两种重构。
                    //方法三、四的调用方式：
                    //注意定义了全局的函数 就不能 再有成员函数，会报错
                    Person p5 = p1 + p2;    //但若想用此方法，则需在方法二的基础上 将函数名 改为 operator+ ,若有该函数则可以用，若编译器找不到该函数则不能使用此方法。
                    Person p6 = p1.operator+(p2);

                    //方法一的调用
                    Person p3 = Person_add(p1,p2);

                    //方法二的调用
                    Person p4 = p1.Person_ADD(p2);
                }

            例2：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                public:
                    int age;
                    Person(int age)
                    {
                        this->age = age;
                    }
                    Person operator+ (Person&p2)
                    {
                        Person p(this->age+p2.age);
                        return p;
                    }
                };

                //全局实现
                //Person operator+ (Person &p1,Person &p2)
                //{
                //    Person p(p1.age+p2.age);
                //    return p;
                //}

                void test1()
                {
                    Person p1(10);
                    Person p2(20);

                    //会去找 operator+ 的函数,有两种形式：operator+(p1,p2) 和 p1.operator(p2)
                    //全局 和 成员函数 不能同时存在，否则会歧义报错。
                    Person p3 = p1+p2;

                    cout << p3.age << endl;
                }

                int main()
                {
                    test1();
                    return 0;
                }

        4.6.2 运算符重载碰上友元函数
            友元函数是一个全局函数，和我们上例写的全局函数类似，只是友元函数可以访问某个私有数据。
            案例： 重载左移操作符（ << ）,使得 cout 可以输出对象。

        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            class person
            {
                //声明友元，使其能够访问私有成员age.
                friend ostream& operator<<(ostream &cout, person &p);
            public:
                person(int age)
                {
                    this->age = age;
                }
            private:
                int age;
            };

            ostream& operator<<(ostream &cout, person &p) //cout的类型是：ostream
            {
                //注意：如果age是私有的，则该函数输出不了age。因此需要加一个声明 友元。
                cout << p.age;
                //对于返回值的选择（void 还是 ostream& ?）,选择后者，因为要输出endl，即 <<endl;故返回不能为空，因为空不能输出endl,即不能使其 void << endl;
                //因此，返回值选择 ostream 类型的 cout。
                return cout;
            }

            void test01()
            {
                person p1(10);
                cout << p1 <<endl;  //直接输出
                // operator<<(cout,p1) //cout.operator<<(p1)，但对于cout类的 类内重载不太现实，因此选择前者全局函数重载。
            }
            int main()
            {
                test01();
                return 0;
            }

        4.6.3 可重载的运算符
            几乎C中所有的运算符都可以重载，但运算符重载在使用时相当受限制的。
            特别是不能使用C中当前没有意义的运算符(例如用**求幂)不能改变运算符优先级，不能改变运算符的参数个数。
            这样的限制有意义，否则，所有这些行为产生的运算符 只会混淆 而不是 澄清寓语意。

            可重载的操作符：
                +       -       *       /       %       ^       &       |       ~
                !       =       <       >       +=      -=      *=      /=      %
                ^=      &=      |=      <<      >>      >>=     <<=     ==      !=
                <=      >=      &&      ||      ++      --      ->*     ‘       ->
                []      ()      new     delete  new[]   delete[]

            不能重载的运算符
                .       ::      .*      ?:      sizeof

        4.6.4 重载自加自减运算符
            ++a  a++    --a  a--

        对于代码：存在问题
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;
                class Myint
                {
                //    friend ostream & operator<<(ostream &cout, Myint &p);
                public:
                    Myint(int num)//this
                    {
                        this->num = num;
                    }
                    Myint& operator++()
                    {
                        this->num = this->num + 1;
                        return *this;
                    }
                    Myint operator++(int)
                    {
                        Myint tmp = *this;
                        //加加
                        this->num = this->num + 1;
                        return tmp;

                    }
                    int num;
                };
                //前置++，可以使用引用传参，后置++不能使用引用传参
                //ostream & operator<<(ostream &cout, Myint &p)
                //{
                //    cout << p.num;
                //    return cout;
                //}
                ostream & operator<<(ostream &cout, Myint p)
                {
                    cout << p.num;
                    return cout;
                }
                void  test01()
                {
                    Myint p1(10);
                    cout << p1 << endl;
                    ++p1;//operator++(p1)  p1.operator++()
                    cout << ++p1 << endl;
                    cout << p1++ << endl;//p1.operator++(int)
                }
                int  main()
                {
                    test01();

                    return 0;
                }

        问题探究：c++左移运算符重载的第二参数问题（与后置++运算符重载联用），见：https://blog.csdn.net/weixin_41054491/article/details/135579799
            该代码涉及到++运算符重载与<<运算符重载的联合使用。

        值得提出的问题：在左移运算符<<重载中，为什么第二个参数不能使用&引用？使用引用时会报错。

            需要注意区分的是:
            （1）在前置++运算符重载与<<运算符重载联用的过程中，<<运算符重载第二参数使用引用不会报错；
            （2）在后置++运算符重载与<<运算符重载联用的过程中，<<运算符重载第二参数使用引用会报错；

                （1）前置++运算符重载，重载函数返回的值是引用类型，即MyInteger类中的本对象，这个对象是早已存在的对象。

                （2）后置++运算符重载，重载函数返回的值是值类型，即MyInteger类中的一个临时对象，这个对象在后置++运算符重载函数运行完毕即消失。

                （3）在前置++运算符与<<运算符重载联用过程，如果第二参数使用&，没有问题，这是因为&后面的对象不会消失。

                （4）在后置++运算符与<<运算符重载联用过程，如果第二参数使用&，有问题，这是因为&后面的对象会消失。在输出之前已经消失了，再也输出不了任何东西，所以会报错。
            总之：
                由于前置++ 的 operator++（） 返回的是返回对象引用，
                而  后置++ 的operator++（int）返回的是 临时对象temp,
                因此<<的重载，输出前置++的时候，第二个参数可以是引用；但输出 后置++的时候，不能是引用。

        4.6.5 指针运算符（*、->）重载
            智能指针：
            总结：我们经常new一个对象，忘记释放，所以我们使用智能指针来维护
            其实质是一个局部对象，该局部对象维护了new出来的对象的地址，在局部对象的析构函数，会帮忙释放new出来的对象。

            对智能指针我们重载了 -> 和 * 使智能指针和普通指针一样使用。

        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Person
                {
                public:
                    Person(int age)
                    {
                        this->age = age;
                    }
                    int age;

                };

                class Smartpoint
                {
                public:
                    Smartpoint(Person *p1)
                    {
                        this->p = p1;
                    }

                    Person * operator->()
                    {
                        return p;
                    }

                    Person& operator* ()
                    {
                        return *p;
                    }

                    ~Smartpoint()
                    {
                        delete p;
                        cout << "Smartpoint 释放 p" << endl;
                    }

                    Person *p ;
                };

                void test()
                {
                    //第一个问题：能否定义一个局部对象，在释放之前如果可以帮助我们释放p ————智能指针
                    //已知对象在出作用域被释放的时候会调用析构函数，因此可以在析构函数里面释放该空间。

                    Person *p = new Person(10);
                    Smartpoint sp(p);

                    //上面两行代码也可缩写为：
                    Smartpoint ssp(new Person(100));

                    cout << p->age <<endl;
                    cout << sp->age <<endl; //第二个问题，能否使sp 返回 p:sp -> p  Person* sp.operator->(){return p;}
                    cout << (*sp).age <<endl; //第三个问题，能否使*sp指向age  ： sp.operator*()
                    //容易忘记释放 p指向的申请对象。
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.6.6 赋值（=）运算符重载
            赋值符初学者易混淆，因为"="在编程中是最基本的运算符，可以进行赋值操作，也能引起拷贝构造函数的调用。

        总结：编译器默认给每一个类加上了4个函数：
                                * 默认无参构造
                                * 默认值拷贝构造
                                * 默认析构函数
                                * 默认的operator=()函数
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Person
                    {
                    public:
                        Person()
                        {

                        }
                        Person(int age1,char *name1)
                        {
                            age = age1;

                            //这样写避免了 name1指向的字符串可能被误释放了。
                            name = new char[strlen(name)+1];
                            strcpy(name,name1);
                        }

                    //    Person & operator=(Person &p1) //this指针指向p2
                    //    {
                    //        //做了简单的值拷贝。
                    //        this->age = p1.age;
                    //        this->name = p1.name;

                    //        return *this; //返回值 返回的是p2,使其可以连续调用，如：P3 = p2 = p1;
                    //    }
                        Person & operator=(Person &p1) //重写operator=函数
                        {
                            //做深拷贝
                            this->age = p1.age;
                            this->name = new char[strlen(p1.name)+1];
                            strcpy(this->name,p1.name);

                            return *this;
                        }
                        ~Person()
                        {
                            delete []name;
                        }

                        int age;
                        char *name;
                    };

                    void test()
                    {
                        Person p1(10,"Bob");
                        Person p2;

                        //这么写并没有调用构造函数（旧对象 赋值 旧对象）。如果是Person p2 = p1才是调用构造函数（旧对象 初始化 新对象）。
                        p2 = p1;//这里之所以没有报错，是因为内置一个 operator= 函数,相当于 p2.operator(p1).
                        cout << p2.age << " " << p2.name <<endl;
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

        4.6.7 等于 和 不等于（== 、 ！=）运算符重载
            （直接重载，没有前面的弯弯绕绕。）
                bool operator==(Person p2)  //p1调用
                {
                    return this->age == p2.age && this->name == p2.name;
                }

                bool operator!=(Person p2)  //p1调用
                {
                    return this->age != p2.age || this->name != p2.name;
                }
        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Person
                {
                public:
                    Person(int age1 ,string name1)
                    {
                        this->age = age1;
                        this->name = name1;
                    }

                    bool operator==(Person p2)  //p1调用
                    {
                        return this->age == p2.age && this->name == p2.name;
                    }

                    bool operator!=(Person p2)  //p1调用
                    {
                        return this->age != p2.age || this->name != p2.name;
                    }

                    int age;
                    string name;
                };

                void test()
                {
                    Person p1(10,"lilu");
                    Person p2(10,"lili");
                    if(p1 == p2)    //
                    {
                        cout << "p1 == p2" << endl;
                    }
                    if(p1 != p2)    //
                    {
                        cout << "p1 != p2" << endl;
                    }
                }
                int main()
                {
                    test();
                    return 0;
                }

        4.6.8 函数调用符号() 重载
            一个类中重载了（）的类，那么这个类定义出来的对象可以像函数一样使用，本质上是调用了operator()函数。
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Myadd
                {
                public:
                    int add(int a,int b)
                    {
                        return a+b;
                    }
                    int operator()(int x,int y)
                    {
                        return x+y;
                    }
                };

                void test()
                {
                    //类 的 普通成员函数不能这么调用，只有静态的成员函数才会有函数，普通成员函数仅在对象创建后才会有。
                    Myadd p;
                    cout << p.add(3,4) << endl;

                    //p() 可以像函数一样调用对象，称为函数对象。
                    cout << p(3,4) << endl; //把对象当作函数来用。 p.operator() (3,4)

                    cout << Myadd()(3,4) <<endl;//Myadd()(3,4)：Myadd(),类名+括号 表示 匿名对象，再调用operator()函数

                }

                int main()
                {
                    test();
                    return 0;
                }

        4.6.9   不用重载 && 和 ||
                这两个逻辑符可以重载，但不建议重载。

                不能重载 operator&& 和 operator|| 的原因是，无法在这两种情况下实现内置操作符的完整语义。说得更具体一些，内置版本 版本特殊之处在于:内置版本的 &&和 || 首先计算左边的表达式，如果这完全能够决定结果，就无需计算右边的表达式了,
                而且能够保证不需要。我们都已经习惯这种方便的特性了。

                我们说操作符重载其实是另一种形式的函数调用而己，对于函数调用总是在函数执行之前对所有参数进行求值。

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Complex{
                    public:
                        Complex(int flag){
                            this->flag = flag;
                        }
                        Complex& operator+=(Complex& complex){
                            this->flag = this->flag + complex.flag;
                            return *this;
                        }
                        bool operator&&(Complex& complex){
                            return this->flag && complex.flag;
                        }
                    public:
                        int flag;
                    };
                    int main()
                    {
                        Complex complex1(0); //flag 0
                        Complex complex2(1); //flag 1

                        //原来情况，应该从左往右运算，左边为假，则退出运算，结果为假
                        //这边却是，先运算（complex1+complex2），导致，complex1的flag变为complex1+c
                        //plex2的值， complex1.a = 1
                        // 1 && 1
                        //complex1.operator&&(complex1.operator+=(complex2))

                        if (complex1 && (complex1 += complex2)){
                             //complex1.operator+=(complex2)
                             cout << "真!" << endl;
                        }
                        else{
                            cout << "假!" << endl;
                        }
                        return EXIT_SUCCESS;
                    }

        4.6.10  符号重载总结
            =，[],()和-> 操作符只能通过成员函数进行重载
            << 和 >> 只能通过全局函数配合友元函数进行重载
            不要重载&&和||操作符，因为无法实现短路规则

        4.6.10 强化训练——字符串类封装

        //MyString.h:

                #define _CRT_SECURE_NO_WARNINGS
                #pragma once
                #include <iostream>
                using namespace std;

                class MyString
                {
                    friend ostream& operator<< (ostream &out,MyString &str);
                    friend istream& operator>> (istream &in ,MyString &str);
                public:
                    MyString(const char *);
                    MyString(const MyString&);
                    ~MyString();

                    char& operator[] (int index);//[]重载

                    //=重载
                    MyString& operator= (const char *str);
                    MyString& operator= (const MyString& str);

                    //字符串拼接 +重载
                    MyString operator+ (const char *str);
                    MyString operator+ (const MyString& str);

                    //字符串比较
                    bool operator== (const char *str);
                    bool operator== (const MyString& str);
                private:
                    char * pString;//指向堆区空间
                    int m_Size;    //字符串长度 不算 ‘\0’
                };


        //MyString.cpp

                #include "MyString.h"

                //左移运算符
                ostream& operator<< (ostream &out,MyString &str)
                {
                    out << str.pString;
                    return out;
                }

                //右移运算符
                istream& operator>> (istream &in,MyString &str)
                {
                    //先将原有的数据释放
                    if(str.pString != NULL)
                    {
                        delete[] str.pString;
                        str.pString = NULL;
                    }

                    char buf[1024]; //开辟临时的字符串数组，保存用户输入内容。
                    in >> buf;

                    str.pString = new char[strlen(buf) + 1];
                    strcpy(str.pString,buf);
                    str.m_Size = strlen(buf);

                    return in;
                }

                //构造函数
                MyString::MyString(const char * str)
                {
                    this->pString = new char[strlen(str) + 1];
                    strcpy(this->pString,str);
                    this->m_Size = strlen(str);
                }

                //拷贝构造
                MyString::MyString(const MyString &str)
                {
                    this->pString = new char[strlen(str.pString) + 1];
                    strcpy(this->pString,str.pString);
                    this->m_Size = str.m_Size;
                }

                //析构函数
                MyString::~MyString()
                {
                    if(this->pString != NULL)
                    {
                        delete []this->pString;
                        this->pString = NULL;
                    }
                }

                char& MyString::operator[] (int index)  //返回str[index]的引用，便于更改这个值
                {
                    return this->pString[index];
                }

                MyString& MyString::operator= (const char * str)    //str = "hello";
                {
                    if(this->pString != NULL)
                    {
                        delete []this->pString;
                        this->pString = NULL;
                    }
                    this->pString = new char[strlen(str) +1];
                    strcpy(this->pString,str);
                    this->m_Size = strlen(str);
                    return *this;
                }

                MyString& MyString::operator= (const MyString &str)
                {
                    if(this->pString != NULL)
                    {
                        delete []this->pString;
                        this->pString = NULL;
                    }
                    this->pString = new char[strlen(str) + 1];
                    strcpy(this->pString,str.pString);
                    this->m_Size = str.m_Size;
                    return *this;
                }

                MyString MyString::operator+ (const char *str)
                {
                    int newsize = this->m_Size + strlen(str) + 1;
                    char *temp = new char[newsize]; //这里是new一个newsize大小的空间，返回的是char指针的变量
                    memset(temp,0,newsize);         //将上面创建的空间对应的内容全部赋值为0；
                    strcat(temp,this->pString);
                    strcat(temp,str);

                    MyString newstring(temp);       //这里是用char指针的变量 创建一个 对象。
                    delete []temp;                  //把临时空间删去

                    return newstring;               //返回新的对象。
                }

                MyString MyString::operator+ (const MyString &str)
                {
                    int newsize = this->m_Size + str.m_Size + 1;
                    char *temp = new char[newsize];
                    memset(temp,0,newsize);
                    strcat(temp,this->pString);
                    strcat(temp,str);

                    MyString newstring(temp);       //这里是用char指针的变量 创建一个 对象。
                    delete []temp;                  //把临时空间删去
                    return newstring;
                }

                bool MyString::operator== (const char *str)
                {
                    if(strcmp(this->pString,str) == 0 && strlen(str) == this->m_Size)
                    {
                        return true;
                    }

                    return false;
                }

                bool MyString::operator== (const MyString &str)
                {
                    if(strcmp(this->pString,str.pString) == 0 && str.m_Size == this->m_Size)
                    {
                        return true;
                    }

                    return false;
                }

        //TestMyString.cpp

                void test()
                {
                    MyString str("hello world");

                    cout << str << endl;

                    //cout << "请输入MyString 类型字符串" << endl;
                    //cin >> str;

                    //cout << "字符串为：" << str <<endl;

                    //测试[]
                    cout << "MyString 的第一个字符为：" << str[0] << endl;

                    //测试=
                    MyString str2 = "^_^";
                    MyString str3 = "";
                    str3 = "aaa";
                    str3 = str2;
                    cout << "str2 = " << str2 << endl;
                    cout << "str3 = " << str3 << endl;

                    //测试+
                    MyString str4 = "我爱";
                    MyString str5 = "北京";
                    MyString str6 = str4 + str5;
                    MyString str7 = str6 + "天安门";

                    cout << str7 <<endl;

                    //测试==
                    if(str6 == str7)
                    {
                        cout << "s6 与 s7相等" << endl;
                    }
                    else
                    {
                        cout << "s6 与 s7不等" << endl;
                    }
                }

        4.6.11 附录：运算符的优先级
                一共15级优先级，同c基本一致。
*/
/*
    4.7.1 继承概述
        4.7.1.1 为何需要继承
            A 继承 B，即：A把B的东西拷贝过来。

            //person(个人)类                               //employee（职工）类
            class person                                class employee
            {                                           {
            private:                                    private:
                char name[10];                              char name[10];
                int age;                                    int age;
                char sex;                                   char sex;

            public:                                         char department[20];
                void print();                               float salary;
            };                                          public:
                                                            void print();
                                                        };

            若直接定义employee类，代码重复会比较严重。

        总结：
            一个类继承另一个类，这样类中就可以少定义一些成员。

        4.7.1.2 继承基本概念
            c++最重要的特征是代码重用，通过继承机制可以利用己有的数据类型来定义新的数据类型，新的类不仅拥有旧类的成员，还拥有新定义的成员。

            一个 B类 继承于 A类，或称从 类A 派生 类B。这样的话，类A 成为 基类(父类)，类B 成为 派生类(子类)
            派生类中的成员，包含两大部分:
                一部分是从基类继承过来的，一部分是自己增加的成员。
                从基类继承过来的表现其共性，而新增的成员体现了其个性。

        4.7.1.3 派生类定义
            派生类定义格式：
                class 派生类名：继承方式 基类名
                {
                    //派生类新增的数据成员和成员函数
                }
            三种继承方式：
                public：公有继承
                private：私有继承
                protected：保护继承
            从继承源上分类：
                单继承：指每个派生类只直接继承了一个基类的特征
                多继承：指多个基类派生出一个派生类的继承关系，多继承的派生类直接继承了不止一个基类的特征。
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    //基类
                    class Animal
                    {
                    public:
                        int age;
                        void print()
                        {
                            cout << age <<endl;
                        }
                    };

                    class Dog:public Animal
                    {
                    public:
                        int tail_len;

                        //继承，相当于拷贝过来
                    //    int age;
                    //    void print()
                    //    {
                    //        cout << age <<endl;
                    //    }
                    };

                    void test()
                    {
                        Dog d;
                        //d有三个成员:
                    //    d.age;
                    //    d.tail_len;
                    //    d.print();
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }
        4.7.2   派生类访问控制
            派生类继承基类，派生类拥有基类中全部变量 和 成员方法（除了构造和析构之外的成员方法），但在派生类中，继承的成员并不一定能直接访问，不同的继承方式会导致不同的访问权限。

            派生类的访问权限规则如下：
                公有派生类                   私有派生类               保护派生类
            基类属性  派生类权限         基类属性  派生类权限       基类属性  派生类权限
            私有      不能访问           私有      不能访问       私有       不能访问
            保护      保护              保护      私有          保护       保护
            公有      公有              公有      私有          公有       保护

        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Base
                {
                public:
                    int a;
                protected:
                    int b;
                private:
                    int c;
                };

                //公有继承方式：基类中是什么权限，继承到 子类中，也是什么权限。
                class A:public Base
                {
                    //公有继承 就是 拷贝
                public:
                    int d;
                    void show()
                    {
                        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
                //        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
                        //由此，子类不能访问父类的私有成员。
                    }
                //    int a;
                //protected:
                //    int b;
                //private:
                //    int c;

                };


                //保护继承：把公有变成保护的，其它不变
                class B:protected Base
                {
                public:
                    int d;
                    void show()
                    {
                        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
                //        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
                    }

                //protected:
                //    int a;
                //protected:
                //    int b;
                //private:
                //    int c;

                };

                class C:private Base
                {

                public:
                    int d;
                    void show()
                    {
                        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
                //        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
                    }

                    //私有继承：将父类的成员权限都变成私有的
                //private:
                //    int a;
                //private:
                //    int b;
                //private:
                //    int c;
                };

                void test()
                {
                    //公有测试：
                    A e;
                //    A.a;
                //    A.d;

                    //保护测试：
                    B f;
                //    f.d;

                    //私有测试：
                    C g;
                //    g.d


                }
                int main()
                {

                    return 0;
                }

        4.7.3  继承中的构造和析构
            4.7.3.1 继承中的对象模型
                在c++编译器的内部可以理解为结构体，子类是由父类成员叠加子类新成员而成。

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class A
                    {
                    public:
                        int a;
                        int b;
                    };

                    class B:public A
                    {
                    public:
                        int c;
                    };

                    class C:public B
                    {
                    public:
                        int d;
                    };

                    void test()
                    {
                        //类似于结构体
                        cout << "A size" <<sizeof(A) <<endl;    //8
                        cout << "A size" <<sizeof(B) <<endl;    //12
                        cout << "A size" <<sizeof(C) <<endl;    //16
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.3.2 对象构造和析构的调用原则
            总结：
            继承中的构造和析构：
                * 子类对象在创建时会首先调用父类的构造函数，父类构造函数执行完毕后，才会调用子类的构造函数
                * 当父类构造函数有参数时，需要在子类初始化列表（参数列表）中显示调用父类构造函数
                * 析构函数调用顺序和构造函数相反
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Base
                    {
                    public:
                        Base(int age1,string name1)
                        {
                            this->age = age1;
                            this->name = name1;

                            cout << "Base,父类的构造函数" << endl;
                        }

                        ~Base()
                        {
                            cout << "Base 父类的析构函数" << endl;
                        }
                        int age;
                        string name;
                    };

                    //创建子类对象的时候，必须先构建父类对象，需要先调用父类的构造函数。
                    class Son:public Base
                    {
                    public:
                        //子类的构造函数：有参构造，创建三个参数。在调用子类的构造函数之前，需要先去调用父类的构造函数，就需要把参数传进去，传参方式如下：
                        Son(int id,int age,string name):Base(age,name)
                        {
                            this->id = id;
                            cout << "Son 子类构造函数" << endl;
                        }
                        ~Son()
                        {
                            cout << "Son 子类的析构函数" << endl;
                        }
                        int id;
                    };

                    void test()
                    {
                        Son p(12,20,"Bob");
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.4 继承中同名成员的处理方法
                当子类成员 和 父类成员 同名时，子类依然从父类继承同名成员
                若子类有成员和父类同名，子类访问其成员默认访问子类的成员（本作用域，就近原则）
                在子类通过作用域:: 进行同名成员区分（在派生类中使用基类的同名成员，显示使用类名限定符）

            总结：
                如果子类 和 父类 有同名的成员变量或成员函数，发生继承时，父类的成员变量和成员函数会被隐藏。
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Base
                    {
                    public:
                        Base(int a)
                        {
                            this->a = a;
                        }

                        void foo()
                        {
                            cout << "父类的foo函数" << endl;
                        }
                        int a;
                    };

                    class Son:public Base
                    {
                    public:
                        Son(int a1,int a2):Base(a1)
                        {
                            this->a = a2;
                        }

                        void foo()
                        {
                            cout << "子类的foo函数" << endl;
                        }
                        int a;
                    };

                    void test()
                    {
                        Son p(10,20);
                        //如果子类和 父类有重名的成员变量，父类的成员变量会被隐藏。访问的是子类的成员变量。
                        //如果子类和 父类有重名的成员变量，父类的成员函数会被隐藏。访问的是子类的成员函数。
                        cout << p.a <<endl;//20 ,访问到的是子类的成员。
                        p.foo();
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.5 非自动继承的函数


                不是所有的函数都能自动从基类继承到派生类中。构造函数和析构函数用来处理对象的创建和析构操作，构造和析构函数只知道对它们的特定层次的对象做什么，也就是说构造函数和析构函数不能被维承，必须为每一个特定的派生类分别创建。
                另外 operator= 也不能被继承，因为它完成类似构造函数的行为。也就是说尽管我们知道如何由=右边的对象如何初始化=左边的对象的所有成员，但是这个并不意味着对其派生类依然有效。
                在继承的过程中，如果没有创建这些函数，编译器会自动生成它们。

            总结：
                发生继承时，子类不会继承父类的构造函数，析构函数 和 operator=函数。

            4.7.6 继承中的静态成员特性
                静态成员函数 和 非静态成员函数的共同点：
                    1. 他们都可以被继承到派生类中
                    2. 若重新定义一个静态成员函数，所有在基类中的其它重载函数都会被隐藏。
                    3. 若我们改变基类中的一个函数的特性，所有使用该函数名的基类版本都会被隐藏。
            总结：
                发生继承时，子类和父类有同名的静态成员变量 或 静态成员函数，父类中的静态成员变量 或 静态成员函数 都会被隐藏。

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Base
                    {
                    public:
                        static int getNum()
                        {
                            return sNum;
                        }
                        static int getNum(int param)
                        {
                            return sNum + param;
                        }
                    public:
                        static int sNum;
                    };
                    int Base::sNum = 10;

                    class Derived : public Base
                    {
                    public:
                        static int sNum; //基类静态成员属性将被隐藏
                    #if 0
                        //重定义一个函数，基类中重载的函数被隐藏
                        static int getNum(int param1,int param2)
                        {
                            return sNum + param1 + param2;
                        }
                    #else
                        //改变基类函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数
                        //父类有两个静态成员函数，子类有一个，
                        static void getNum(int param1,int param2)
                        {
                            cout << sNum + param1 + param2 << endl;
                        }
                    #endif
                    };
                    int Derived::sNum = 20;

                    void test()
                    {
                        Derived p1;
                        cout << p1.sNum <<endl;//20,
                        //因此，当子类和父类有同名的静态成员变量，父类的静态成员变量会被隐藏，调用的是子类的静态成员变量。

                    //    p1.getNum();     //不传参数，调用不了，因此，不能调用父类的无参静态成员函数。
                    //    p1.getNum(10);   //传一个参数，也调用不了，因此，不能调用父类的静态成员函数。
                        p1.getNum(10,20);  //传两个参数的才可以调用，因此，只能调用子类的静态成员函数。
                    //如果子类和父类有同名的静态成员函数，父类中的静态成员函数 都 会被隐藏，

                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.7 多继承
                4.7.7.1 多继承概念：
                    我们可以从一个类继承，我们也可以 同时从 多个类继承，这就是多继承。
                    但是，由于多继承时非常受争议的，从多个类继承可能会因为函数、变量等同名导致较多的歧义。

                例：
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <string>
                        using namespace std;

                        class A
                        {
                        public:
                            int a;
                        };

                        class B
                        {
                        public:
                            int a;
                            int b;
                        };

                        class C:public A,public B
                        {
                        public:
                            int c;
                        };

                        void test()
                        {
                            C p;
                            p.A::a = 10;
                            p.B::a = 20;
                            p.b = 20;
                            p.c = 30;
                        }

                        int main()
                        {
                            test();
                            return 0;
                        }

                4.7.7.2  菱形继承 和 虚继承
                    两个派生类 继承 同一个基类 而又有 某个类 同时继承两个派生类，这种继承被称为菱形继承，或钻石型继承。
                例：
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <string>
                        using namespace std;

                        class Animal
                        {
                        public:
                            int age;

                        };

                        class sheep:virtual public Animal
                        {
                        public:
                            int id;
                        };

                        class cow:virtual public Animal
                        {
                        public:
                            int num;
                        };

                        class Shenshou:public sheep,public cow
                        {
                        public:
                            int a;
                        };

                        void test()
                        {
                            Shenshou p;
                            //实际上，我们仅希望Shenshou只继承一个age,
                            //实现方法：使用虚继承关键字：virtual
                        //    p.sheep::age = 100;
                        //    p.cow::age = 200;

                            //虚继承
                            p.age = 100;

                        }

                        int main()
                        {
                            test();
                            return 0;
                        }

                4.7.7.3 虚继承实现原理
                    结合代码，注释 以及 笔记截图分析。
            总结：
                主要需要知道：虚继承多了一个vbptr指针 其指向 虚基类表(vbtable).
                           多继承（继承两个类）有两个虚基类指针，

                最终结果：1.age只有一个
                        2.多了两个虚基类ptr指针(vbptr)
                        3.多了两个虚基类表
                        4.这两个指针和两个表 是在 调用这个类的构造函数的时候去初始化的。
            例：
            代码：
                    //我们需要知道：每个类在内存中是如何存储的，以及加上 virtual关键字后，虚继承的类是如何在内存中存储的。
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Animal
                    {
                    public:
                        int age;

                    };

                    class Sheep:virtual public Animal
                    {
                    public:
                        int id;
                    };

                    class Cow:virtual public Animal
                    {
                    public:
                        int num;
                    };

                    class Shenshou:public Sheep,public Cow
                    {
                    public:
                        int a;
                    };

                    void test()
                    {
                        Shenshou p;
                        //实际上，我们仅希望Shenshou只继承一个age,
                        //实现方法：使用虚继承关键字：virtual
                    //    p.sheep::age = 100;
                    //    p.cow::age = 200;

                        //虚继承
                        p.age = 100;

                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            分析：
                    //在开始菜单里的 vs的开发人员命令提示符 下写如下命令:      若找不到，可打开vscode,再在 工具->命令行->开发者命令提示，再写入如下代码：
                    //cd D:\Qtproject\5_2_cplusplus_lei
                    //dir
                    //cl /d1 reportSingleClassLayoutAnimal main.cpp    //这里指令表示：report Single Class Layout Animal,报告单个类显示Animal在main.cpp文件当中，注意，要编译之后，才会生成Animal的布局。

                    //动物类的布局：
                    //class Animal    size(4):
                    //        +---
                    // 0      | age
                    //        +---

                    //分析：Animal只有4个字节 int类型的 age

                    //羊类的布局：
                    //class Sheep     size(12):
                    //        +---
                    // 0      | {vbptr}
                    // 4      | id
                    //        +---
                    //        +--- (virtual base Animal)
                    // 8      | age
                    //        +---

                    //Sheep::$vbtable@:
                    // 0      | 0
                    // 1      | 8 (Sheepd(Sheep+0)Animal)

                    //由于继承是虚继承，里面有三个东西：羊继承的age，一个id,此外，里面还有一个vbptr(virtual base ptr 虚基类ptr指针，指针占4个字节，虚基类指针 会指向一张表（虚基类表（vbtable））,虚基类指针开始是不会被初始化的，但当我们调用这个类的构造函数的时候，他会创建一张表，并且把表的地址给到vbptr指针)。
                    //由（Sheep::$vbtable@:）可知，表里有两个成员，一个是0，一个是8，这里8是指age的偏移量。也就是说，他在虚继承的时候，a虽然继承过来了，但，去访问age的时候并不是直接得到age，而是通过指针得到age的偏移量，然后再访问到age。

                    //也就是说当定义了 sheep p;
                    //再去访问(p.age)时，编译器做了许多事情: *（int *）((char*)&p+ *((int *)(*（int *）&p) + 1)) //*(int*)(p的地址+偏移量8)

                    //即，过程为：首先要找到vbptr指针，即：首先由p的地址(32位编译器)转成(int*)再取*：*（int*）&p   => 这个就是vbptr这个值，注意不是指针，其指向虚基类表。
                    //我们对这个值的地址转成int *,再加1，即从原来的指向0，变成指向8，再将这个8取出来（解引用*）,至此得到偏移量8: *((int *)((int *)&p) + 1）
                    //为了得到age的地址，需要在p的地址上加上偏移量： ((char*)&p + *((int *)(*（int *）&p) + 1))
                    //对得到的地址转成(int *),再解引用,得到age的值： *（int *）((char*)&p + *((int *)(*（int *）&p) + 1))


                    //牛类的布局：
                    //class Cow       size(12):
                    //        +---
                    // 0      | {vbptr}
                    // 4      | num
                    //        +---
                    //        +--- (virtual base Animal)
                    // 8      | age
                    //        +---

                    //Cow::$vbtable@:
                    // 0      | 0
                    // 1      | 8 (Cowd(Cow+0)Animal)


                    //神兽的布局：
                    //class Shenshou  size(24):
                    //        +---
                    // 0      | +--- (base class Sheep)
                    // 0      | | {vbptr}
                    // 4      | | id
                    //        | +---
                    // 8      | +--- (base class Cow)
                    // 8      | | {vbptr}
                    //12      | | num
                    //        | +---
                    //16      | a
                    //        +---
                    //        +--- (virtual base Animal)
                    //20      | age
                    //        +---

                    //Shenshou::$vbtable@Sheep@:
                    // 0      | 0
                    // 1      | 20 (Shenshoud(Sheep+0)Animal)

                    //Shenshou::$vbtable@Cow@:
                    // 0      | 0
                    // 1      | 12 (Shenshoud(Cow+0)Animal)
                    //vbi:       class  offset o.vbptr  o.vbte fVtorDisp
                    //          Animal      20       0       4 0

                    //对于神兽有4个成员：继承了sheep的虚基类表和id、继承了cow的虚基类表和num、自己的a 和 只继承了一份的age。
                    //而这里,在sheep的虚基类表里：age的偏移量是20；在cow的虚基类表里：age的偏移量是12。



            vs的开发人员命令提示符窗口内容：

                    //D:\Qtproject\5_2_cplusplus_lei>dir
                    // 驱动器 D 中的卷是 Data
                    // 卷的序列号是 4D3B-BBAE

                    // D:\Qtproject\5_2_cplusplus_lei 的目录

                    //2024/12/20  22:52    <DIR>          .
                    //2024/12/18  11:55    <DIR>          ..
                    //2024/12/07  00:18               133 5_2_cplusplus_lei.pro
                    //2024/12/20  01:28            19,159 5_2_cplusplus_lei.pro.user
                    //2024/12/07  00:32               732 c_person.c
                    //2024/12/20  22:52           197,990 main.cpp
                    //2024/12/20  22:52            76,800 main.exe
                    //2024/12/20  22:52             2,146 main.obj
                    //               6 个文件        296,960 字节
                    //               2 个目录 199,913,979,904 可用字节

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Animal    size(4):
                    //        +---
                    // 0      | age
                    //        +---
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutSheep m
                    //ain.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Sheep     size(12):
                    //        +---
                    // 0      | {vbptr}
                    // 4      | id
                    //        +---
                    //        +--- (virtual base Animal)
                    // 8      | age
                    //        +---

                    //Sheep::$vbtable@:
                    // 0      | 0
                    // 1      | 8 (Sheepd(Sheep+0)Animal)
                    //vbi:       class  offset o.vbptr  o.vbte fVtorDisp
                    //          Animal       8       0       4 0
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCow mai
                    //n.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Cow       size(12):
                    //        +---
                    // 0      | {vbptr}
                    // 4      | num
                    //        +---
                    //        +--- (virtual base Animal)
                    // 8      | age
                    //        +---

                    //Cow::$vbtable@:
                    // 0      | 0
                    // 1      | 8 (Cowd(Cow+0)Animal)
                    //vbi:       class  offset o.vbptr  o.vbte fVtorDisp
                    //          Animal       8       0       4 0
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutShenshou main.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Shenshou  size(24):
                    //        +---
                    // 0      | +--- (base class Sheep)
                    // 0      | | {vbptr}
                    // 4      | | id
                    //        | +---
                    // 8      | +--- (base class Cow)
                    // 8      | | {vbptr}
                    //12      | | num
                    //        | +---
                    //16      | a
                    //        +---
                    //        +--- (virtual base Animal)
                    //20      | age
                    //        +---

                    //Shenshou::$vbtable@Sheep@:
                    // 0      | 0
                    // 1      | 20 (Shenshoud(Sheep+0)Animal)

                    //Shenshou::$vbtable@Cow@:
                    // 0      | 0
                    // 1      | 12 (Shenshoud(Cow+0)Animal)
                    //vbi:       class  offset o.vbptr  o.vbte fVtorDisp
                    //          Animal      20       0       4 0
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>


*/
/*
    4.8 多态：（一种接口，多种形态）
        多态 是 面向对象程序设计语言中 数据抽象 和 继承之外的第三个基本特征。
        多态性(polymorphism) 提供 接口 与 具体实现 之间的另一层隔离，从而将"what"和"how"分离开来。多态性改善了代码的可读性和组织性，同时也使创建的程序具有可扩展性，项目不仅在最初创建时期可以扩展，而且当项目在需要有新的功能时也能扩展。

    多态分为:静态多态 和 动态多态
        c++支持  编译时多态(静态多态) 和 运行时多态(动态多态)，运算符重载 和 函数重载 就是 编译时多态，而 派生类和虚函数 实现 运行时多态。

        静态多态 和 动态多态的区别就是 函数地址 是 早绑定(静态联编) 还是 晚绑定(动态联编)。

        如果函数的调用，在编译阶段就可以确定函数的调用地址，并产生代码，就是静态多态(编译时多态)，就是说地址是早绑定的。
        而如果函数的调用地址 不能编译 不能在编译期间确定，而 需要在运行时才能决定 ,这就属于晚绑定(动态多态,运行时多态)。

        例如：同一种函数实现多种功能：foo(int);            这三个就是一种 静态多态，编译时期就完成了地址的绑定。
                                foo(int ,int);
                                foo(int,char,short);

    总结：多态就是 一种接口，多种形态
        分为
            静态多态：在编译时，地址早绑定（静态联编）
            动态多态：在运行时，才确定需要调用的地址。（动态联编）

        发生多态的四大条件：（在这四大基本条件之后，就可以实现一个接口多种形态）
            * 父类中有虚函数（加了virtual的函数）。
            * 子类必须发生继承，继承基类。
            * 子类必须重写虚函数。（重写：函数的返回值 函数名称 函数参数 一致，函数体重写。）
            * 父类的指针或引用，指向子类的对象。 （在本案例中，父类的指针和引用是作为函数形参来使用的。）

        注意：在本案例中，若没有加virtual关键字，子类继承后，函数调用时 是 地址早绑定(编译时期就完成了地址的绑定)。若加了virtual则是地址晚绑定(运行时才绑定地址)。
        例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Animal
                {
                public:

                //    void speak()
                //    {
                //        cout << "动物在说话！" << endl;
                //    }

                    //6.如果不是上面这种，而是像下面这种，加了virtual关键字的虚函数。
                    //7.首先，有虚函数，其次，Dog又继承了这个基类，并且，子类中又重写了这个虚函数。  （重写：函数返回值 函数名 参数值 一致，就叫重写）

                    virtual void speak()
                    {
                        cout << "动物在说话！" << endl;
                    }

                };

                //2.但 如果两个类发生了继承，父类和子类，可以自动转换。
                //3.此时 可以用do_work()来调用p2的speak
                class Dog:public Animal
                {
                public:
                    void speak()
                    {
                        cout << "狗在说话！" << endl;
                    }

                };

                //1.这种没有继承的方式，不能用do_work()来调用p2的speak（）。
                //class Dog
                //{
                //public:
                //    void speak()
                //    {
                //        cout << "狗在说话！" << endl;
                //    }

                //};

                //11.再增一个cat类，并继承Animal.
                class Cat:public Animal
                {
                public:
                    void speak()
                    {
                        cout << "猫在说话" << endl;
                    }

                };

                //8.最后，用父类的指针 指向 子类的对象，这个时候，打印的就是 "狗在说话"
                void do_work(Animal &obj)
                {
                    obj.speak();  //5.这里就是地址早绑定，//9.在继承了虚函数之后，就是地址晚绑定。
                    //10.即：地址早绑定 -> 在基类的函数前面加上virtual关键字 -> 地址晚绑定。
                }

                //12.在这个程序中，test函数就是接口，一个接口，可以实现多种形态。
                void test()
                {
                    Animal p1;
                    do_work(p1);

                    Dog p2;
                    //4.但注意，这里打印的还是"动物在说话",因为这个地址 早绑定了。在编译器编译的时期就已经绑定了。
                    do_work(p2);

                    Cat p3;
                    do_work(p3);
                }
                int main()
                {
                    test();
                    return 0;
                }

        4.8.2 案例 多态实现计算器案例
            例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Calc
                {
                public:
                    virtual int Mycalc(int a,int b)
                    {
                        return 0;
                    }

                };

                class Add:public Calc
                {
                public:
                    int Mycalc(int a,int b)
                    {
                        return a + b;
                    }
                };

                class Reduce:public Calc
                {
                public:
                    int Mycalc(int a,int b)
                    {
                        return a - b;
                    }
                };

                class Multi:public Calc
                {
                public:
                    int Mycalc(int a,int b)
                    {
                        return a * b;
                    }
                };

                int do_work(int a,int b,Calc &p)
                {
                //    cout << p.Mycalc(a,b) << endl;
                    return p.Mycalc(a,b);
                }

                void test()
                {
                    Add p1;
                    cout << do_work(6,4,p1) << endl;

                    Reduce p2;
                    cout << do_work(6,2,p2) << endl;

                    Multi p3;
                    cout << do_work(3,5,p3) << endl;;

                }

                int main(int argc, char *argv[])
                {
                    test();
                    return 0;
                }

        4.8.3 c++如何实现动态绑定
            动态绑定什么时候发生?
            所有的工作都是由编译器在幕后完成。当我们告诉通过创建一个 virtual 函数来告诉编译器要进行动态绑定，那么编译器就会根据动态绑定机制来实现我们的要求，不会再执行早绑定。

            问题:C++的动态捆绑机制是怎么样的?
            首先，我们看看 编译器如何处理虚函数。当编译器发现我们的类中有虚函数的时候，编译器会创建一张虚函数表,
            把虚函数的函数入口地址放到虚函数表中，并且 在类中 秘密增加一个指针，
            这个指针就是 vpointer(缩写 vptr)，（注意区分于上面继承中的vbptr(virtual base ptr 虚基类ptr指针）
            这个指针是指向对象的虚函数表。在多态调用的时候，根据vptr 指针，找到虚函数表来实现动态绑定。

            验证对象中的虚指针。
    注意：
        虚函数在类中增加的指针是vpointer(缩写 vptr)，注意区分于上面 继承中的vbptr(virtual base ptr 虚基类ptr指针）

        例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Animal
                    {
                    public:
                        virtual void speak()
                        {
                            cout << "动物在说话！" << endl;
                        }

                    };

                    class Dog:public Animal
                    {
                    public:
                        void speak()
                        {
                            cout << "狗在说话！" << endl;
                        }

                    };

                    class Cat:public Animal
                    {
                    public:
                        void speak()
                        {
                            cout << "猫在说话" << endl;
                        }

                    };

                    void do_work(Animal &obj)
                    {
                        obj.speak();
                    }

                    void test()
                    {
                        Animal p1;
                        do_work(p1);

                        Dog p2;
                        do_work(p2);

                        Cat p3;
                        do_work(p3);
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

                    //这里再次使用到vscode,详细操作步骤见前面 虚继承的实现原理.
            窗口内容：
                    //D:\c++代码\angle\Myadd_self>cd D:\Qtproject\5_2_cplusplus_lei

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Animal    size(4):
                    //        +---
                    // 0      | {vfptr}
                    //        +---

                    //Animal::$vftable@:
                    //        | &Animal_meta
                    //        |  0
                    // 0      | &Animal::speak

                    //Animal::speak this adjustor: 0
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
                    //main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutDog main.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class Dog       size(4):
                    //        +---
                    // 0      | +--- (base class Animal)
                    // 0      | | {vfptr}
                    //        | +---
                    //        +---

                    //Dog::$vftable@:
                    //        | &Dog_meta
                    //        |  0
                    // 0      | &Dog::speak

                    //Dog::speak this adjustor: 0
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
                    //main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCat main.cpp
                    //用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
                    //版权所有(C) Microsoft Corporation。保留所有权利。

                    //main.cpp

                    //class _s__CatchableType size(28):
                    //        +---
                    // 0      | properties
                    // 4      | pType
                    // 8      | _PMD thisDisplacement
                    //20      | sizeOrOffset
                    //24      | copyFunction
                    //        +---

                    //class _s__CatchableTypeArray    size(4):
                    //        +---
                    // 0      | nCatchableTypes
                    // 4      | arrayOfCatchableTypes
                    //        +---

                    //class Cat       size(4):
                    //        +---
                    // 0      | +--- (base class Animal)
                    // 0      | | {vfptr}
                    //        | +---
                    //        +---

                    //Cat::$vftable@:
                    //        | &Cat_meta
                    //        |  0
                    // 0      | &Cat::speak

                    //Cat::speak this adjustor: 0
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
                    //main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>


             分析：

                //1.当定义一个Dog类的对象的时候，会先构造父类的对象，即：先构造Animal的对象，由于本例中，Animal没有成员变量，只有虚函数，所以多了vfptr(虚函数指针)，该指针指向虚函数表（vftable）。当构造子类的对象的时候，因为会调用构造函数，在调用构造函数时他会 把虚函数的函数入口地址 放到虚函数表（vftable）
                //2.因此，此时这个虚函数 就指向 父类的这个 speak函数。
                    //Animal 的布局：
                    //class Animal    size(4):
                    //        +---
                    // 0      | {vfptr}
                    //        +---

                    //Animal::$vftable@:
                    //        | &Animal_meta
                    //        |  0
                    // 0      | &Animal::speak


                //3.然后开始构造子类。由于构造子类的时候 继承了 虚函数指针（vfptr）以及虚函数表（vftable）,此时他调用子类的构造函数时，子类的构造函数里面 会去做：1.会重写虚函数，2.把这个子类的这个dog speak函数的函数指针放进继承的 虚数表（vftable)里面，即，把vfptr指针的值替换。
                //4.因此，重写实际上就是替换掉 vftable里面的函数的地址。
                //5.此时再去调 p.sprak的时候，它里面实际调用的是vfptr指向的这个vftable里面的函数。而该函数在 创建子类的构造函数的时候就已经更改了。

                    //Dog 的布局：
                    //class Dog       size(4):
                    //        +---
                    // 0      | +--- (base class Animal)
                    // 0      | | {vfptr}
                    //        | +---
                    //        +---

                    //Dog::$vftable@:
                    //        | &Dog_meta
                    //        |  0
                    // 0      | &Dog::speak



                    //cat 的布局：
                    //class _s__CatchableType size(28):
                    //        +---
                    // 0      | properties
                    // 4      | pType
                    // 8      | _PMD thisDisplacement
                    //20      | sizeOrOffset
                    //24      | copyFunction
                    //        +---

                    //class _s__CatchableTypeArray    size(4):
                    //        +---
                    // 0      | nCatchableTypes
                    // 4      | arrayOfCatchableTypes
                    //        +---

                    //class Cat       size(4):
                    //        +---
                    // 0      | +--- (base class Animal)
                    // 0      | | {vfptr}
                    //        | +---
                    //        +---

                    //Cat::$vftable@:
                    //        | &Cat_meta
                    //        |  0
                    // 0      | &Cat::speak

        4.8.4   抽象基类 和 纯虚函数（pure virtuaal function）
            在设计时，常常希望  基类 仅仅作为 其派生类的 一个接口。
            这就是说，仅想对基类进行向上类型转换，使用它的接口，而不希望用户实际的创建一个基类的对象。
            同时创建一个纯虚函数 允许接口中放置成员原函数，而不一定要提供一段可能对这个函数毫无意义的代码。
            做到这点，可以在基类中加入至少一个纯虚函数(pure virtual function),使得基类称为抽象类(abstract class).

              纯虚函数使用关健字 virtual，并在其后面加上 =0。如果试图去实例化一个抽象类，编译器则会阻止这种操作。

              当继承一个抽象类的时候，必须实现所有的纯虚函数，否则由抽象类派生的类也是一个抽象类。
              Virtual void fun()=0;告诉编译器在 vtable 中为函数保留一个位置，但在这个特定位置不放地址。
            建立公共接口目的是为了将子类公共的操作抽象出来，可以通过一个公共接口来操纵一组类，且这个公共接口不
            需要事先(或者不需要完全实现)。可以创建一个公共类,

            要点：
                1.在之前的计算器类的基础上，在后面加 = 0；使其变成 纯虚函数（ 虚函数 = 0 ）
                2.纯虚函数作用： 已知在构造父类的时候，vfptr指向了vftable,而vftable里面放了一个 父类的函数的地址，但如果写成纯虚函数的话，代表把这个函数地址赋值为NULL。
                3.virtual int Mycalc(int a,int b) = 0;这句话赋值为0，代表将vfptr虚函数指针 指向的 虚函数表 里面的 函数入口地址 赋值为NULL。之后子类再去重写时，会把那个虚函数表里面的函数重写更改。

                4.把 含有纯虚函数的类 称作 抽象类,抽象类不能实例化对象。
                5.如果子类 继承了 抽象类，则 子类 也是 抽象类
                6.但如果 继承了 抽象类 的 子类 重写了虚函数。就不再是抽象类。

            总结：
                纯虚函数，将虚函数 赋值为 0，实质是将虚函数表的函数入口地址赋值为NULL。
                抽象类 一个类中如果有纯虚函数，那么这个类就是一个抽象类，
                继承了抽象类的子类也是抽象类。如果子类重写了虚函数，则子类不再是抽象类。
                抽象类不能实例化对象


            例：

                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Calc
                    {
                    public:
                        //1.在之前的计算器类的基础上，在后面加 = 0；使其变成 纯虚函数（ 虚函数 = 0 ）
                        //2.纯虚函数作用： 已知在构造父类的时候，vfptr指向了vftable,而vftable里面放了一个 父类的函数的地址，但如果写成纯虚函数的话，代表把这个函数地址赋值为NULL。
                        //3.virtual int Mycalc(int a,int b) = 0;这句话赋值为0，代表将vfptr虚函数指针 指向的 虚函数表 里面的 函数入口地址 赋值为NULL。之后子类再去重写时，会把那个虚函数表里面的函数重写更改。

                        //4.把 含有纯虚函数的类 称作 抽象类,抽象类不能实例化对象。
                        //5.如果子类 继承了 抽象类，则 子类 也是 抽象类
                        //6.但如果 继承了 抽象类 的 子类 重写了虚函数。就不再是抽象类。
                        virtual int Mycalc(int a,int b) = 0;

                    //    {
                    //        return 0;
                    //    }

                    };
                    class Mod:public Calc
                    {
                    //    Calc a;//报错，抽象类不能实例化
                    //    Mod a;//继承了抽象类的子类也是抽象类，不能实例化。

                    };

                    void test1()
                    {

                    }

                    class Add:public Calc
                    {
                    public:
                        int Mycalc(int a,int b)
                        {
                            return a + b;
                        }
                    };

                    class Reduce:public Calc
                    {
                    public:
                        int Mycalc(int a,int b)
                        {
                            return a - b;
                        }
                    };

                    class Multi:public Calc
                    {
                    public:
                        int Mycalc(int a,int b)
                        {
                            return a * b;
                        }
                    };

                    int do_work(int a,int b,Calc &p)
                    {
                    //    cout << p.Mycalc(a,b) << endl;
                        return p.Mycalc(a,b);
                    }

                    void test()
                    {
                        Add p1;
                        cout << do_work(6,4,p1) << endl;

                        Reduce p2;
                        cout << do_work(6,2,p2) << endl;

                        Multi p3;
                        cout << do_work(3,5,p3) << endl;;

                    }

                    int main(int argc, char *argv[])
                    {
                        test();
                        return 0;
                    }

            4.8.5 纯虚函数 和 多继承
                多继承带来了一些争议，但是接口继承可以说一种毫无争议的运用了。
                绝大数面向对象语言都不支持多继承，但是绝大数面向对象对象语言都支持接口的概念，

                c++中没有接口的概念,但是可以通过纯虚函数实现接口。

                接口类中只有函数原型定义，没有任何数据定义。

                多重继承接口不会带来二义性和复杂性问题。接口类只是一个功能声明，并不是功能实现，子类需要根据功能说明定义功能实现。
            注意:除了析构函数外，其他声明都是纯虚函数。

            4.8.6  虚析构函数
                4.8.6.1 虚析构函数作用
                    虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。

                总结：
                    虚析构的作用：在调用父类的析构函数之前，会先调用子类的析构函数。
                例：

                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <stdlib.h>
                        #include <string>
                        using namespace std;

                        class Animal
                        {
                        public:
                            virtual void speak()
                            {
                                cout << "动物在说话" << endl;
                            }

                            virtual ~Animal()
                            {
                                cout << "动物 析构" << endl;
                            }
                        };

                        class Dog:public Animal
                        {
                        public:
                            void speak()
                            {
                                cout << "狗在说话" << endl;
                            }
                            ~Dog()
                            {
                                cout << "狗 析构" << endl;
                            }
                        };

                        void dp_work(Animal &obj)
                        {
                            obj.speak();
                        }

                        void test()
                        {
                            Animal *p = new Dog;

                            p->speak(); //1.因为引用的是dog的对象，所以 打印 狗在说。
                            delete p;   //2.因为是父类的指针      所以 析构 是动物析构，所以释放的是基类,子类的对象没有被释放。
                            //3.在之前，创建子类对象时；先创父类，再创子类。析构是：先析构子类，再析构父类；但这里由于指针是Animal指针，所以先释放的是父类。
                            //4.那么，能不能让其在释放父类之前，先释放子类？ => 只需要在父类的析构函数前面加关键字virtual ,这就是虚析构。
                            //5.虚析构的作用：在调用父类的析构函数之前，会先调用子类的析构函数。
                        }

                        int main()
                        {
                            test();
                            return 0;
                        }
            4.8.6.2 纯虚析构函数
                纯虚析构函数在c++中是合法的，但是在使用的时候有一个额外的限制:必须为纯虚析构函数提供一个函数体。
                那么问题是:如果给虚析构函数提供函数体了，那怎么还能称作纯虚析构函数呢?
                纯虚析构函数和非纯析构函数之间唯一的不同之处在 于纯虚析构函数使得基类是抽象类，不能创建基类的对象。

            总结：
                纯虚析构函数，就是虚函数置为0，没有函数体。
            例：
                class Animal
                {
                public:
                    virtual void speak()
                    {
                        cout << "动物在说话" << endl;
                    }

                //    virtual ~Animal()   //虚析构
                //    {
                //        cout << "动物 析构" << endl;
                //    }

                    //纯虚析构函数就是：没有实现的函数体。
                    virtual ~Animal() = 0;
                };
        4.8.7 重写 重载 重定义
            重载(同一作用域的同名函数)
                1. 同一个作用域
                2.参数个数，参数顺序，参数类型不同
                3.和函数返回值，没有关系
                4.const 也可以作为重载条件 //例如：对于参数传参（传变量还是传常量）：do(const Teacher& t){} do(Teacher& t)

            重定义(隐藏)
                5.发生继承
                6.子类(派生类)重新定义父类(基类)的同名成员(非irtual函数)
            重写(覆盖)
                7.有继承
                8.子类(派生类)重写父类(基类)的virtual函数
                9.函数返回值，函数名字，函数参数，必须和基类中的虚函数一致

            总结：
                重载：
                    * 同一作用域
                    * 函数名相同
                    * 参数的个数，顺序，类型不一致
                    * const也可作为重载条件
                重定义
                    * 发生继承
                    * 子类和父类有同名的变量和函数，父类中同名的变量和函数会被隐藏
                重写
                    * 父类中有虚函数
                    * 发生了继承
                    * 子类重写了虚函数： 返回值  函数名  参数 一致，函数体不一致。

*/

/*
 *
5 c++ 模板
    最重要的技术：类型参数化。

    5.1 模板概述（主要用于减少代码的重复率）
        c++提供了函数模板(functiontemplate.)所谓函数模板，实际上是 建立一个通用函数，其 函数类型 和 形参类型 不具体制定，用一个 虚拟的类型 来代表。

    例：
        对于一个函数 fun() 如果形参需要传不同的参数类型，如int char short void* 等
        在之前如果用 重载等 来写，则会出现：需要写很多的仅修改了形参的函数体，代码重复率太高。因此模板就是类型不指定，用通用类型来代替，在调用时由调用处的实参来指定。由实参类型来推导出形参类型。

        这个通用函数就成为函数模板。凡是函数体相同的函数都可以用这个模板代替,不必定义多个函数，只需在模板中定义一次即可。
        在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现不同函数的功能。

        c++提供两种模板机制:
            函数模板（类型参数化）：形参的类型不指定，用通用类型来代替，在调用时，编译器会根据实推导出形参类型。
            类模板
                类属 - 类型参数化，又称参数模板
        总结:
            模板 把 函数 或 类 要处理的 数据类型 参数化，表现为 参数的多态性，成为类属。
            模板 用于表达 逻辑结构相同，但 具体数据元素类型 不同的 数据对象的

    5.2 函数模板
        5.2.1 什么是函数模板？
            //定义一个通用模板，模板的通用类型为T。 class 和 typename都是一样的，用哪个都可以。
            template<class T>
            //下面紧跟函数的定义
            void swap_temp(T &a,T&b)
            {
                T tmp = a;
                a = b;
                b = tmp;
            }
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            #if 0
            //交换int型数据
            void swap(int & x,int &y)
            {
                int tmp = x;
                x = y;
                y = tmp;
            }
            //交换char型数据
            void swap(char & x,char &y)
            {
                char tmp = x;
                x = y;
                y = tmp;
            }

            void test()
            {
                int a = 1;
                int b = 2;
                swap(a,b);
                cout << a <<" " <<b << endl;
            }
            #endif

            //函数模板来实现
            template<class T> //定义一个通用模板，模板的通用类型为T。 class 和 typename都是一样的，用哪个都可以。
            //下面紧跟函数的定义
            void swap_temp(T &a,T&b)
            {
                T tmp = a;
                a = b;
                b = tmp;
            }

            void test1()
            {
                char a = 1;
                char b = 2;
                int c = 3;
                int d = 4;
                swap_temp(a,b);//自动类型推导，
            //    swap_temp(a,c);//推导类型不一致会出错。
                swap_temp(c,d);
                cout << a <<" " <<b << endl;
                cout << c <<" " <<d << endl;
            }

            int main()
            {
                test1();
                return 0;
            }

        5.2.2 课堂练习
            使用 函数模板实现对char 和 int 类型数组进行排序

        注意：
            函数模板可以 自动推导 也可以 显示指定类型。因为推导会比较麻烦
            template<class T>
            void swap_temp(T &a,T &b){}
            swap_temp(a,b);      //自动类型推导。
            swap_temp<char>(a,b);//显示指定类型。
        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //函数模板 用于排序
                template<class T>
                void array_sort(T *p,int n)//传数组首元素地址和数组个数
                {
                    for(int i = 0;i < n-1;i++)
                    {
                        for(int j = i+1; j <n ;j++)
                        {
                            if(p[i]>p[j])
                            {
                                T temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;
                            }
                        }
                    }
                }

                template <class T>
                void print_array(T *p,int n)
                {
                    for(int i = 0;i < n;i++)
                    {
                        cout << p[i] << " ";
                    }
                    cout << endl;
                }

                void test()
                {
                    int a[10] = {12,55,44,63,84,9,22,11,3,77};
                    array_sort(a,sizeof(a)/sizeof(a[0]));
                    print_array(a,sizeof(a)/sizeof(a[0]));
                }

                void test1()
                {
                    double a[10] = {12.1,1.8,3.2,4.5,7.4,6.3,4.2,9.9,7.6,5.3};
                //    array_sort(a,sizeof(a)/sizeof(a[0]));        //自动类型推导
                    array_sort<double>(a,sizeof(a)/sizeof(a[0]));  //显示指定类型
                    print_array(a,sizeof(a)/sizeof(a[0]));
                }
                int main()
                {
                    test1();
                    return 0;
                }

    5.3 函数模板和普通函数区别
        函数模板不允许自动类型转化
        普通函数能够自动进行类型转化

    总结：
        普通函数可以自动进行类型转换
        函数模板不能自动进行类型转换
    例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //普通函数
            int My_Add(int a,int b)
            {
                cout<<"普通函数" <<endl;
                return a + b;
            }

            //模板
            template <class T>
            T My_Add(T a,T b)
            {
                cout<<"模板函数" <<endl;
                return a + b;
            }

            void test()
            {

            }


            int main()
            {

                int a = 10;
                char b = 20;
                My_Add(a,a);     //直接调用普通函数，不用推导，如果还是想用模板函数，则加 <>,
                My_Add<int>(a,a);//显示指定类型
                My_Add<>(a,a);   //指定自动推导
                My_Add(b,b);     //普通函数类型不匹配，自动调用模板函数

                My_Add(a,b);     //这种类型不相同的，调用的是普通函数，可以实现自动类型转换。char转为int。但如果用模板则会报错
            //    My_Add<>(a,b);     //如果用模板则会报错,因为自动推导出的两个类型不一致，函数模板不会做自动类型转换。
                return 0;
            }

    5.4 函数模板 和 普通函数在一起调用规则
        c++编译器优先考虑普通函数

        如果实在要用函数模板，可以通过空模板实参列表的语法限定编译器只能通过模板匹配，即加<>指定调用模板

        函数模板 可以像 普通函数 那样可以被 重载

        如果函数模板可以产生一个更好的匹配，那么选择模板

    总结：
        * c++编译器优先考虑普通函数
        * 可以通过加 <> ,限定编译器只能调用模板进行匹配
        * 函数模板可以像普通函数那样被重载
        * 函数模板如果有更好的匹配，优先使用函数模板

    例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //函数模板
            template<class T>
            T Myplus(T a,T b)
            {
                cout << "函数模板" << endl;
                return a + b;
            }

            //普通函数
            int Myplus(int a,int b)
            {
                cout << "普通函数" << endl;
                return a + b;
            }

            //重载函数模板
            template <class T>
            T Myplus(T a, T b,T c)
            {
                cout << "模板函数" << endl;
                return a + b + c;
            }

            void test()
            {
                int a = 10;
                int b = 20;
                char c = 'a';
                char d = 'b';
                //如果函数模板和普通函数都能匹配，c++编译器优先考虑普通函数
                cout << Myplus(a,b) << endl;
                //如果要求必须调用模板，则加<>
                cout << Myplus<>(a,b) << endl;
                //此时普通函数也可以匹配，因为普通函数可以自动类型转换
                //但是此时函数模板能够有更好的匹配
                //如果函数模板可以产生一个更好的匹配，那么选择模板(两个类型都是char，如果是调用普通函数就需要转两次类型，因此匹配模板更好)
                cout << Myplus(c,d) << endl;

            }
            int main()
            {
                test();
                return 0;
            }

    5.5 模板机制剖析
        思考:为什么函数模板可以和普通函数放在一起？ c++编译器是如何实现函数模板机制的？

        5.5.1 编译过程
            hello.cpp程序是高级c语言程序，这种程序易于被人读懂给。为了在系统上运行hello.c程序，每一条c语句都必须转化为低级的机器指令。然后将这些及其指令打包成可执行目标文件格式，并以二进制形式存储于磁盘中。
            预处理（Pre-processing）-> 编译（Compiling）->汇编（Assembling）->链接（Linking）

            hello.i                 hello.s             hello.o             hello.exe

hello.c     预处理器       =》       编译器        =》     汇编器       =》      链接器


            hello.c经过预处理器，将宏展开，生成的文件hello.i
            hello.i经过编译器，将文件编译成汇编语言，生成文件为hello.s
            hello.s经过汇编器，将文件编译成目标文件hello.o（win下为hello.obj）
            hello.o经过链接器，将文件编译成可执行文件

        5.5.2 模板实现机制(函数模板的本质)
            函数模板机制结论：
                编译器 并不是把 函数模板 处理成 能够处理任何类型的函数
                而是，函数模板 通过 具体类 型产生不同的函数
                编译器会对函数模板进行 两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的 代码进行编译。

            总结：
                函数模板的本质 就是 进行二次编译。
                    第一次对函数模板进行编译：对模板代码本身进行编译
                    第二次在函数调用处，对函数模板展开，进行二次编译。：对参数替换后的代码进行编译

                这个机制实际就是为了解决宏定义无法对类型检查的缺陷，第一次编译是检查模板是否有语法错误，第二次编译是在调用函数的时候，为例得到相对应类型的函数，会再次进行编译。
                根据编译器对函数模板的二次编译可知，函数模板并不是一个实际存在的函数，而是产生实际函数的模板，但我们使用参数进行调用，编译器第二次编译后才会产生一个真正的函数。0

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //普通函数
                int My_Add(int a,int b)
                {
                    cout<<"普通函数" <<endl;
                    return a + b;
                }

                //模板
                template <class T>
                T My_Add(T a,T b)
                {
                    cout<<"模板函数" <<endl;
                    return a + b;
                }
                //1.第一次编译，对函数模板语法进行编译（编译器从上往下走，走到这里时，对语法进行编译）
                //3.展开后的代码如下：注意，展开后也没有template <class T>了。
                //int My_Add(int a,int b)
                //{
                //    cout<<"模板函数" <<endl;
                //    return a + b;
                //}
                //4.如果再一个char类型大的调用，则展开为：展开之后，也要进行第二次编译，
                //char My_Add(char a,char b)
                //{
                //    cout<<"模板函数" <<endl;
                //    return a + b;
                //}
                //5.由上面两个可知，函数模板 的本质就是 进行二次编译。

                void test()
                {
                    int a = 10;
                    char b = 20;
                    My_Add(a,a);        //2.由于a是int类型，在调用的时候，他会对这个模板进行展开（因为编译器推导出a是int类型，则展开时，用int替换T），
                    My_Add<int>(a,a);
                    My_Add<>(a,a);
                    My_Add(b,b);

                    My_Add(a,b);
                //    My_Add<>(a,b);

                }


                int main()
                {
                    test();
                    return 0;
                }

    5.6 模板的局限性
        局限性：如果T是自定义类型，结构体，数组，地址，类等，则很可能无法处理，或出现我们不希望的操作。比如在比大小的时候。若要实现比大小，则需要使用operator进行重载>、= 等。

        假如没有模板函数
        template<class T>
        void f(T a,T b){...}

        如果代码实现时定义了赋值操作a = b,但是T为数组，这种假设就不成立了。
        同样，如果里面的语句为判断语句if(a>b),但T如果是结构体，该假设也不成立，另外如果是传入的数组，数组名为地址，因此它比较的是地址，而这也不是我们所希望的操作。

        总之，编写的模板函数很可能无法处理某些类型，另一方面，有时候通用化是有意义的，但 c++语法不允许这样做。为了解决这种问题，可以提供模板的重载，为这些特定的类型提供具体化的模板。

    复习：
        类里面 有4个自带函数：operator=函数、无参构造、拷贝构造、析构函数。
    注意:
        函数具体化格式：（含数具体化极少用，遇到认识即可），在函数的前面加 template<>,并把所有T替换成自定义数据类型。
        template<> void mySwap(Person &p1,Person &p2)
    例：  ’
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //1.第一种方法：若是自定义类型的数据类型（但如果是数组结构体是不行的），但如果是自定义数据类型，就可以去修改这个类，修改里面的operator重载函数，从而实现所需功能，
            //2.如T是Person,里面有name和age。进行比较和赋值。
            //3.对于该自定义的数据类型，那么它是调用operator=函数，或者比较>号，则，去这个类里面去重写一个operator>这样的运算符重载函数 进行重载。
            //4.此时就需要自己进行实现函数体。
            class Person
            {
            public:
                Person(string name,int age)
                {
                    this -> mName = name;
                    this ->mAge = age;
                }
                string mName;
                int mAge;
            };

            //普通交换函数
            //5.例如对于这个交换函数，如果传的Person类型，可能是交换不了的，
            //6.除了写operator重载函数外，还可以把函数具体化，
            template<class T>
            void mySwap(T &a,T &b)
            {
                T tmp = a;
                a = b;//这里调用的是operator=函数。
                b = tmp;
            }


            //第三代具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
            //具体化优先于常规模板
            //7.例如下面这种，就是具体化。前面加template<> 然后把所有T，换成自定义数据类型。
            //8.但函数具体化很少用，因为很麻烦需要注意的地方很多，不如去写一个全局函数进行赋值，或者写一个类内的函数进行赋值。
            template<> void mySwap(Person &p1,Person &p2)
            {
                string nameTemp;
                int ageTemp;

                nameTemp = p1.mName;
                p1.mName = p2.mName;
                p2.mName = nameTemp;

                ageTemp = p1.mAge;
                p1.mAge = p2.mAge;
                p2.mAge = ageTemp;
            }

            void test()
            {
                Person p1("Tom",10);
                Person p2("Jerry",20);

                cout << "P1 Name = " << p1.mName << "P1 Age = " << p1.mAge <<endl;
                cout << "P2 Name = " << p2.mName << "P2 Age = " << p2.mAge <<endl;
                mySwap(p1,p2);
                cout << "P1 Name = " << p1.mName << "P1 Age = " << p1.mAge <<endl;
                cout << "P2 Name = " << p2.mName << "P2 Age = " << p2.mAge <<endl;
            }
            int main()
            {
                test();
                return 0;
            }

    5.7 类模板
        5.7.1 类模板的基本概念
            类模板 和 函数模板的定义和使用类似。有时，有两个或多个类，其功能是相同的，仅仅是数据类型不同。
            类模板用于实现类所需数据的类型参数化。
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //class Animal
            //{
            //public:
            //    int age;
            //    int data;
            //};

            //class Animal_1
            //{
            //public:
            //    int age;
            //    string data;
            //};

            //通用类模板：
            template<class T1, class T2>
            class Animal
            {
            public:
                Animal(T1 a,T2 b)
                {
                    age = a;
                    data = b;
                }
                T1 age;
                T2 data;
            };
            void test()
            {
                Animal dog(10,10);
                Animal<int,int> dog2(10,10);  //注意:类模板不能自动类型推导，因此要显示指定类型。（但我的QT可以进行自动的类型转换，最好还是显示指定）
                cout << dog.age << " " << dog.data << endl;

                Animal cat(4,"lisa");
                Animal<int,string> cat2(4,"lisa");
                cout << cat.age << " " << cat.data << endl;
            }

            int main()
            {
                test();
                return 0;
            }

        5.7.2 类模板作为函数参数
        总结：
            类模板作为函数形参时，该函数需要写成函数模板形式。
        写法有两种：
            1.
                template<class T1>
                void show(T1 &p)
            2.
                template<class T1,class T2>
                void show(Animal<T1,T2> &p)

        例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //通用类模板：
                template<class T1, class T2>
                class Animal
                {
                public:
                    Animal(T1 a,T2 b)
                    {
                        age = a;
                        data = b;
                    }
                    T1 age;
                    T2 data;
                };

                //1.作为形参，参数为：类模板类型。所以为Animal<int,int>
                //2.但问题是：形参的类型为<int,int>,故不能传cat，<int,string>类型。
                //3.因此，当函数的形参作为类模板的时候，尽量将函数写成函数模板的形式。
                //写法一：
                //template<class T1,class T2>
                //void show(Animal<T1,T2> &p)
                //{
                //    cout << p.age <<" "<<p.data <<endl;
                //}
                //写法二：
                template<class T1>
                void show(T1 &p)    //以Animal<int,int> dog2(10,10);调用为例：相当于把整个<int,int>类型，传给了T1。所以
                {
                    cout << p.age <<" "<<p.data <<endl;
                }

                void test()
                {
                    Animal dog(10,10);
                    Animal<int,int> dog2(10,10);  //注意:类模板不能自动类型推导，因此要显示指定类型。（但我的QT可以进行自动的类型转换，最好还是显示指定）
                    cout << dog.age << " " << dog.data << endl;
                    show(dog);

                    Animal cat(4,"lisa");
                    Animal<int,string> cat2(4,"lisa");
                    cout << cat.age << " " << cat.data << endl;
                    show(cat);
                }

                int main()
                {
                    test();
                    return 0;
                }

        5.7.3   类模板派生普通类（类模板遇到继承）
            一个类继承了类模板，则当前的子类应该怎么去写？

        总结：
            * 类模板遇到继承，在继承时，继承的类必须是一个模板类<>
            * 类模板遇到继承，可以将子类写成类模板
        写法：
                template<class T>
                class Base{}；

                template<class T1,class T2>
                class Son2:public Base<T2>
                {
                public:
                    //初始化列表传参。
                    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}
                    T1 x;
                };

        例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                template<class T>
                class Base
                {
                public:
                    Base(T a)
                    {
                        this->a = a;
                    }
                    T a;
                };

                //写法一：
                //2.但问题是这里T写死为int类型了。
                class Son:public Base<int>
                {
                public:
                    //1.用初始化列表构造构造函数：首先构造基类Base<int>,并把a传进去。再x赋值为x1
                    Son(int x1, int a):Base<int>(a),x(x1){}
                    int x;
                };

                //写法二：
                template<class T1,class T2>
                class Son2:public Base<T2>
                {
                public:
                    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}

                    T1 x;
                };

                void test()
                {
                    //3.因此这里只能写<int,int>类型.
                    Son p(10,20);
                    Son2<int,string>(30,"lisa");
                }
                int main()
                {
                    test();
                    return 0;
                }

        5.7.4 类模板的 成员函数的 类内实现 （类模板的类内的成员函数，在类内的话，怎么去实现？）

        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            template <class NameType,class AgeType>
            class Person
            {
            public:
                //成员函数类内实现：
                Person(NameType name,AgeType age)
                {
                    this->mName = name;
                    this->mAge = age;
                }
                void showPerson()
                {
                    cout << "name：" << this->mName << "age: " << this->mAge << endl;
                }
                NameType mName;
                AgeType mAge;
            };
            void test()
            {
                //Person P1("德玛西亚"，18);//类模板不能进行类型自动推导
                Person<string,int>p1("德玛西亚",18);
                p1.showPerson();
            }
            int main()
            {
                test();
                return 0;
            }

        5.7.5 类模板的 成员函数的 类外实现

        总结：
            类模板的成员函数 类外实现，需要把成员函数写成函数模板形式。
        例：

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                template<class T1,class T2>
                class Person
                {
                public:
                    //成员函数类外实现：
                    Person(T1 a,T2 b);
                    void showPerson();

                    T1 a;
                    T2 b;
                };
                //1.类模板的成员函数在类外实现，需要写成函数模板形式。
                //2.又由于Person是模板类，故，不能写为：Person::Person(T1 a,T2 b),而是写成：Person<T1,T2>::Person(T1 a,T2 b)
                template<class T1,class T2>
                Person<T1,T2>::Person(T1 a,T2 b)
                {
                    this->a = a;
                    this->b = b;
                }

                template<class T1,class T2>
                void Person<T1,T2>::showPerson()
                {
                    cout << this->a << " " << this->b << endl;
                }

                void test()
                {
                    Person<int,string>p(10,"lisa");
                    p.showPerson();
                }
                int main()
                {
                    test();
                    return 0;
                }

        5.7.6 类模板的成员函数创建时机。
            （是为了讲清楚：类模板头文件 和 源文件分离的问题）
        总结：
            类模板成员函数的创建时机是在调用时，只要没有调用，编译器就不会创建这个函数，只有声明。


        注意：
            在此记录一下：对于例子的操作步骤，以免复习不会操作：
                1.将代码（一、)取消注释，创建p再调用函数,可以发现不报错，代码可以编译通过
                2.将代码（二、)取消注释，创建p不调用函数,可以发现不报错，代码可以编译通过
                3.在2.的基础上调用p的函数，发现编译后报错。
                4.由上三条以及代码的注释1.可知，类模板的成员函数的创建时机是在调用的时候，没调用时都只是声明。
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            class A
            {
            public:
              void showA() { cout << "showA" << endl ;}

            };

            class B
            {
            public:
              void showB() { cout << "showB" << endl ;}
            };

            //一、类内实现：
            //template<class T>
            //class C
            //{
            //public:

            //    void foo1()
            //    {
            //        obj.showA();
            //    }
            //    void foo2()
            //    {
            //        obj.showB();
            //    }

            //    T obj;//定义一个T类型的obj变量/对象，可以传A/B对象。
            //};

            //二、相当于类内只有声明。此时也能成功，
            template<class T>
            class C
            {
            public:

                void foo1();
            //    {
            //        obj.showA();
            //    }
                void foo2();
            //    {
            //        obj.showB();
            //    }

                T obj;//定义一个T类型的obj变量/对象，可以传A/B对象。
            };


            void test()
            {
                //1.定义P时，传了类型:要么A要么B，那么在C类里面，两个函数理应不能同时存在，因为此时foo2应该会报错（非法访问：A类型调用B的成员函数），但事实却是编译时并没有报错。
                //2.由一（类内实现）和二（类内声明 以及 当只是定义p,没有调用成员函数，编译后都没有报错可知：这两个函数并没有定义。
                //3.当定义p并且调用成员函数的时候，就会报错（foo的定义没找到），
                //4.说明类模板的成员函数的创建时机是在调用的时候。只要没有调用，两个函数是不会创建的。

                //5.也就是说：类模板的成员函数的创建时期是在调用时。如果不调用这个函数的函数，那么就不会创建的，只有函数的声明。
                C<A> p;

                p.foo1();//调用foo1
            }

            int main()
            {
                test();
                return 0;
            }

        5.7.7 类模板头文件 和 源文件分离问题
            类模板的头文件和源文件分离 与 普通文件的分离不太一样。

        总结：
            在分文件时，必须把函数的定义 和 类的声明 写到一个文件当中去。如果把函数定义放在其它.cpp里面，由于每个.cpp都是单独编译的，在编译时会找不到函数定义。
            或者 类模板的成员函数的定义 直接使用内部定义，在类内部完成定义
        注意：
            当.h里面既有类的声明，又有类的定义，这个取名的时候，可能有人取成.hpp。(.cpp和.h的结合体，既有类的声明，又有函数的定义)
        例：
            //Person.h文件
            #pragma once

            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            template<class T1,class T2>
            class Person
            {
            public:
                Person(T1 a,T2 b);
                void show();

                T1 A;
                T2 B;
            };

            //Person.cpp
            #include "Person.h"
            //对Person里面的函数进行外部定义。
            template<class T1,class T2>
            Person<T1,T2>::Person(T1 a,T2 b)
            {
                this->A = a;
                this->B = b;
            }

            template<class T1,class T2>
            void Person<T1,T2>::show()
            {
                cout << A << " " << B << endl;
            }

            //main.c
            #include "Person.h"
            //3.包含这个头文件，相当于把.h拿过来：
            //4.又由于每个.cpp都是单独编译的


            //template<class T1,class T2>
            //class Person
            //{
            //public:
            //    Person(T1 a,T2 b);
            //    void show();

            //    T1 A;
            //    T2 B;
            //};


            int main()
            {
                //1.此时编译，会报错：无法解析的外部符号Person<int,int>,也就是说没有找到函数的定义。
                //2.无法找到是因为：类模板的成员函数是在调用的时候才创建。
                Person<int,int> p(10,20);
                p.show();//5.当编译器编译到这里时，发现它要调用p的构造函数和调用这个show函数,调用的时候就需要创建这个函数
                         //6.但是，当编译器想创建这两个函数的时候发现这两个函数并没有在当前.cpp里面（main.cpp），而是在其它.cpp里面（Person.cpp）。此时编译器想要创建这两个函数就会找不到。
                //7.即：调用构造函数和show函数需要创建这两个函数，但是没有这两个函数的定义，不能被创建。

                //8.解决的办法就是，这个函数的定义需要放到Person.h当中，不能放在.cpp里面。
                //9.类模板的份文件问题：必须把函数的定义和类的声明写到一个文件当中去；更便捷的方法是：类模板的成员函数定义直接使用内部定义，在类里面实现定义。
                return 0;
            }

        5.7.8 类模板碰到友元函数
            友元声明：1. friend void showPerson1<>(Person<T1,T2> &p);   前加friend,并且函数名后加<>，括号里面是 引用方式传模板类。
                    2. 直接在模板类的里面直接声明并定义 友元函数（但这个函数仍然是全局函数）
                       定义方式：friend void showPerson2(Person<T1,T2> &p){}   这种定义的，不需要在函数名后面加<>。进行声明为模板函数。
            总结：
                在代码中，建议使用方法3进行使用。
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;


                //类模板的声明需要将这两行都拿到前面来。
                template<class T1,class T2>
                class Person;

                //5.showPerson1的全局模板函数声明。
                template<class T1,class T2>
                void showPerson1(Person<T1,T2> &p);

                //1.类模板作为函数形参 函数需要写成函数模板
                //方法一、全局模板函数写在 类的上面。
                template<class T1,class T2>
                void showPerson(Person<T1,T2> &p)
                {
                    cout << p.a << " " << p.b <<endl;
                }

                template<class T1,class T2>
                class Person
                {
                    friend void showPerson1<>(Person<T1,T2> &p);    //4.这里声明为友元的时候，由于在前面找不到函数，因此会报错，需要在这前面加上3.的声明。
                    friend void showPerson<>(Person<T1,T2> &p);//2.这只是声明普通的函数为它的友元。
                    //方法三、将函数直接写在类的里面。
                    //注意：这种方法写的函数，不是类的成员函数，实质还是全局函数，因为前面加了一个friend。（定义一个全局函数，并声明为类的友元）
                    friend void showPerson2(Person<T1,T2> &p)//这里是直接定义，不是声明，所以不需要像前面一样在函数名后面加一个<>。
                    {
                        cout << p.a << " " << p.b <<endl;
                    }
                public:
                    Person(T1 a,T2 b)
                    {
                        this->a = a;
                        this->b = b;
                    }
                private:
                    T1 a;
                    T2 b;

                };

                //3.当全局模板函数 在下面
                //方法二、全局模板函数写在类的下面，则需要声明。
                template<class T1,class T2>
                void showPerson1(Person<T1,T2> &p)
                {
                    cout << p.a << " " << p.b <<endl;
                }

                void test()
                {
                    Person<int,string> p(10,"lucy");
                    showPerson(p);  //p是类模板，Person<int,string>这个类型的，类函数的形参
                    showPerson1(p);
                    showPerson2(p);
                }
                int main()
                {
                    test();
                    return 0;
                }

    5.8 类模板的应用
        设计一个数组模板类（MyArray）,完成对不同类型元素的管理,（这个数组存储 任意的 数据类型，当设计的时侯很简单。）
        （写一个数组，数组可以实现存储任意类型，可以动态地增加或删减容量————c里面地动态数组）

        template<class T>
        class Array
        {
        public：构造函数 元素尾插 数组地赋值= 元素的删除。

        private:
            int size;
            int capacity;
            T *ptr;
        }

        例：
            #pragma once
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            template<class T>
            class MyArray
            {
            public:
                //有参构造，explicit：明确，explicit关键字用来修饰 类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显式的方式进行类型转换。
                explicit MyArray(int capacity)  //构造函数 参数传递数组容量的大小。构造对象的时候，用户指定数组的大小
                {
                    this->m_Capacity = capacity;    //容量大小传递到类的成员进行保存
                    this->m_Size = 0;               //元素个数初始化为0。

                    //如果T是对象，那么这个对象必须提供默认的构造函数
                    pAddress = new T[this->m_Capacity]; //new一个容量大小的数组空间
                }

                //拷贝构造：数组间进行赋值的时候，有数组的重新new空间，不能简单的进行值拷贝。而是址拷贝，所以要重写拷贝构造。
                MyArray(const MyArray &arr)
                {
                    this->m_Capacity = arr.m_Capacity;
                    this->m_Size = arr.m_Size;

                    this->pAddress = new T[this->m_Capacity];
                    //注意：这里不能使用memcpy，因为memcpy也是简单的值拷贝。而这里可能是对象的拷贝，所以需要一个一个进行赋值
                    for(int i = 0;i < this->m_Size;i++)
                    {
                        this -> pAddress[i] = arr.pAddress[i];
                    }
                }

                //重载[] 操作符 arr[0]
                //返回[]对应的元素。所以是引用。  MyArray a(10); a[9]。
                T& operator[] (int index)
                {
                    return this->pAddress[index];
                }

                //尾插法：参数：传递的类型 传递的值
                void Push_back(const T &val)
                {
                    //判断数组是否满了，满了就扩容
                    if(this->m_Capacity == this->m_Size)
                    {
                        return ;
                    }
                    //没满就把val值赋值到最后。
                    this -> pAddress[this->m_Size] = val;
                    this->m_Size++;
                }

                //尾删：
                void Pop_back()
                {
                    if(this->m_Size == 0)
                    {
                        return ;
                    }
                    this->m_Size--;
                }

                //获得size.
                int getSize()
                {
                    return this->m_Size;
                }

                //析构函数:数组指针指向NULL，容量和大小为0
                ~MyArray()
                {
                    if(this->pAddress != NULL)
                    {
                        delete[] this -> pAddress;
                        this->pAddress = NULL;
                        this->m_Capacity = 0;
                        this->m_Size = 0;
                    }
                }

            private:
                T * pAddress;   //指向一个堆空间，这个空间存储真正的数据，指向数组的首元素地址。
                int m_Capacity; //数组的容量
                int m_Size;     //元素的个数
            };
*/

/*
    6. c++类型转换
        类型转换(cast) 是将 一种数据类型 转换成 另一种数据类型。
        例如，如果将一个整型值 赋给 一个浮点类型的变量，编译器会暗地里将其转换成浮点类型。

        转换是非常有用的，但是它也会带来一些问题，比如在转换指针时，我们很可能将其转换成一个比它更大的类型,但这可能会破坏其他的数据。

        应该小心类型转换，因为 转换 相当于对编译器说:忘记类型检查，把它看做其他的类型。
        一般情况下，尽量少的去使用类型转换，除非用来解决非常特殊的问题。

        无论什么原因，任何一个程序如果使用很多类型转换都值得怀疑.

        标准 c++提供了一个 显示 的转换的语法，来替代旧的C风格的类型转换。

        使用C风格的强制转换可以把想要的任何东西转换成我们需要的类型。那为什么还需要一个新的 C++类型的强制转换呢?
        新类型的强制转换可以提供更好的控制强制转换过程，允许控制各种不同种类的强制转换。C++风格的强制转换 其他的好处是，它们能更清晰的表明它们要干什么。程序员只要扫一眼这样的代码，就能立即知道一个强制转换的目的。


        6.1 静态转换 （static_cast）（主要用来转 内置的数据类型，如int char 这种数据类型，对于自定义的数据类型，他只能转发生继承关系之间的这个类。没有发生继承关系的类是不能转的）

            用于 类层次结构中 基类(父类) 和 派生类(子类) 之间 指针 或 引用 的转换。
            进行上行转换(把 派生类的指针 或 引用 转换成 基类表示)是安全的;
            进行下行转换(把基类指针或引用转换成派生类表示)时，由于没有动态类型检查，所以是不安全的。
            用于基本数据类型之间的转换，如把int转换成 char，把char 转换成int。这种转换的安全性也要开发人员来保证
        总结：
        静态转换：static_cast<待转换的类型> (待转换的数据)
            * static_cast 可以用来转换基本的内置数据类型：int char double等
            * static_cast不能转换没有发生继承关系之间的类。
            * static_cast可以用来转换发生继承关系的类，但是不保证安全性。
            * static_cast不能用来转换指针。

        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            void test()
            {
                //static_cast 用来转换内置数据类型 和 c语言的强制类型转换相似。
                int a = 1;
                char b = 2;
                double c = 3.14;
                a = static_cast<int> (b);      //编译器如果能转，应当是： a = static_case<int> (b);    //可以认为就是一个模板：<>
                a = static_cast<int> (c);
                c = static_cast<double> (a);
            }

            class A
            {
            public:
                int a;
            };

            //1.在不继承的基础上
            //class B
            //{
            //public:
            //    int b;
            //};

            //4.发生继承关系
            class B:public A
            {
            public:
                int b;
            };

            void test1()
            {
                A *p1 = new A;
                B *p2 = new B;
            //    p1 = p2;                    //2.报错,
            //    p1 = static_cast<A*> (p2);   //3.也会报错，因为不能static_cast不能转换没有发生继承关系之间的类。
                //5.如果两个类之间发生了继承关系，可以进行类型转换。
                p1 = static_cast<A*> (p2);

                //6.此时问题：是否安全？ 如果B的空间大，A空间小，B转A是否安全？=>安全，因为A能访问的空间比较小，B的对象转成A的对象使得能访问的空间变小了。
                //7.而A转B是不安全的，因为A转成B之后，能访问的空间变大，造成越界访问了。
                p2 = static_cast<B*> (p1);

                //8.因此 子（大空间）转父（小空间）， 向上转，是安全的。
                //9.    父（小空间）转子（大空间）， 向下转，是不安全的。
                //10.但注意：static_cast<>进行类型转换的时候，是不会保证转换的安全性的。

            }

            void test2()
            {
                int * p1 = NULL;
                char *p2 = NULL;
            //    p1 = static_cast<int *> (p2);   //11.对于普通的指针static_cast不能转换，只能转普通的内置类型。像指针就转不了。
            //    p2 = static_cast<char *> (p1);
            }

            int main()
            {
                test1();
                return 0;
            }

        6.2 动态转换（dynamic_cast）
            dynamiccast主要用于 层次间的上行转换 和 下行转换；
            在 类层次间 进行 上行转换时，dynamic_cast和static_cast的效果是一样的:
            在进行 下行转换时，dynamic_cast具有 类型检查 的功能，比static_cast更安全;

        总结:
            * 不能用于转换基本的数据类型
            * 可以用于转换发生继承关系之间的类，保证转换是安全的。（子可转父，父不可转子）
            * 如果 发生了多态，子转父 和 父转子 总是安全的。（多态：发生继承，父类有虚函数，子类重写虚函数，然后用父类的指针（不管你是什么类型的指针) 或 引用 指向这个 子类对象里面的虚函数表，他调的虚函数里面保存的函数的地址是动态绑定的，所以是不会越界的，函数地址总是确定的，因此多态总是安全的）
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            void test()
            {
                //static_cast 用来转换内置数据类型 和 c语言的强制类型转换相似。
                int a = 1;
                char b = 2;
                double c = 3.14;
                a = static_cast<int> (b);      //编译器如果能转，应当是： a = static_case<int> (b);    //可以认为就是一个模板：<>
                a = static_cast<int> (c);
                c = static_cast<double> (a);
            }

            class A
            {
            public:
                int a;
            };

            //1.在不继承的基础上
            //class B
            //{
            //public:
            //    int b;
            //};

            //4.发生继承关系
            class B:public A
            {
            public:
                int b;
            };

            //动态转换:dynamic_cast
            void test3()
            {
                //1.动态转换不能转内置的基本数据类型。
                int a = 1;
                char b = 2;
            //    a = dynamic_cast<int> (b);//报错，不能转基本数据类型
            }

            void test4()
            {
                //2.转自定义数据类型
                A * p1 = NULL;
                B *p2 = NULL;

                //3.可以转换的前提: 发生了继承关系，没有继承关系是不能进行转换的。
                //dynamic_cast不能用于没有发生继承关系之间的类转换
                //dynamic_cast可以用于发生继承关系之间的类号转换。
                p1 = dynamic_cast<A *>(p2); //子转父，安全的
            //    p2 = dynamic_cast<B *>(p1); //子转父,不安全，转不了
                //4.因此，若两个继承类之间 发生转换，尽量用 动态转换，保证了安全性，而static_cast不能保证安全性。
            }

        6.3 常量转换 （const_cast）
            该运算符用来修改类型的const属性。（有些需要去const 有些需要加const）
            常量指针 被转化成 非常量指针，并且 仍然指向 原来的对象;
            常量引用 被转换成 非常量引用，并且 仍然指向 原来的对象;

        注意:不能直接对 非指针 和 非引用的 变量 使用const_cast 操作符去 直接移除它的 const。

        总结：
            * const_cast一般用来加const或去const。
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //const转换
            void test()
            {
                const int a = 1;
                int * p1 = NULL;
                const int *p2 = NULL;
                //static_cast只能转基本的数据类型
            //    int *p1 = static_cast<int *> (p2);//转不了


                p1 = const_cast<int *> (p2);         //去const
                p2 = const_cast<const int *> (p1);   //加const

            }

            int main()
            {
                test();
                return 0;
            }

        6.4 重新解释转换（reinterpret_cast）
            这是最不安全的一种转换机制，最有可能出问题。

            主要用于 将一种数据类型 从 一种类型 转换为 另一种类型。
            它可以将一个指针 转换成 一个整数，也可以将一个整数 转换成 一个指针。

        总结：
            reinterpret_cast:
                * 一般用来转换指针， 整数和指针之间都可以转换。
        但注意：
                在转换时要注意数据类型的大小，例如：在64位电脑中，int*是8bytes，int是4bytes。int* 转 int可能会导致数据丢失，int无法容纳指针的位数从而报错（Cast from pointer to smaller type 'int' loses information）
                这里如果实在要使用，就修改成可以使用的合适的整数类型，例如uint ptr_t，这是一个无符号整数类型，足以容纳指针的位数。
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;


            void test()
            {
                int *p1 = NULL;
                char *p2 = NULL;
                //static_cast 不能用来转指针
                //p1 = static_cast<int *>(p2)

                //dynamic_cast动态指针 主要是用于 转换类和类之间的数据类型。

                //const_cast主要用于 加减const
            //    p1 = p2;//报错
                p1 = reinterpret_cast<int *>(p2);
                p2 = reinterpret_cast<char *>(p1);

                int c = 0;
            //    c = p2;//报错

                //Cast from pointer to smaller type 'int' loses information
            //    c = reinterpret_cast<int> (p1);//理应也正确，报错原因是：1.int * 转 int 不安全 可能导致数据丢失 2.若实在需要，则可以使用合适大小的类型，例如：uintptr_t 就是无符号正数类型，足以容纳指针的位数。
                c = reinterpret_cast<uintptr_t> (p1);//修改后正确

                //但，将指针转换为int类型的整数 是一个不安全的操作，并且可能会导致数据丢失。
                //如果 需要以整数形式打印指针的地址，可以使用合适的整数类型，例如uint ptr_t，这是一个无符号整数类型，足以容纳指针的位数。

                p1 = reinterpret_cast<int *>(c);    //
            }

            int main()
            {
                test();
                return 0;
            }

        6.5 总结
            static_cast 一般用于转换内置的基本数据类型 int char double等
            dynamic_cast 一般用来转换 发生继承关系的 自定义的数据类型
            const_cast 一般用来转换 给指针 加减 const
            reinterpret_cast 一般用来转指针。
*/
/*
    7章 c++异常
        7.1 异常基本概念
            Bjarne stroustrup 说:提供异常的 基本目的 就是为了处理上面的问题。基本思想是:让一个函数 在发现了 自己无法处理的错误时 抛出(thrōw)一个异常，然后它的(直接或者间接)调用者能够处理这个问题。也就是《C++ primer》中说的:将问题检测和问题处理相分离。

            一种思想:在所有支持异常处理的编程语言中(例如java)，要认识到的一个思想:在异常处理过程中，由问题检测代码 可以抛出一个对象 给问题处理代码，通过这个对象的类型 和 内容，实际上完成了两个部分的通信，通信的内容是“出现了什么错误”。当然，各种语言对异常的具体实现有着或多或少的区别，但是这个通信的思想是不变的。

            一句话:异常处理就是处理程序中的错误。所谓错误是指在程序运行的过程中发生的一些异常事件(如:除0溢出，数组下标越界，所要读取的文件不存在,空指针，内存不足等等)。

            回顾一下:我们以前编写程序是如何处理异常?
            在C语言的世界中，对错误的处理总是围绕着两种方法:一是使用整型的返回值标识错误;二是使用errno宏(可以简单的理解为一个全局整型变量)去记录错误。当然C++中仍然是可以用这两种方法的。
            这两种方法最大的缺陷就是会出现不一致问题。例如有些函数返回1表示成功，返回0表示出错;而有些函数返回0表示成功，返回非0表示出错。
            还有一个缺点就是函数的返回值只有一个，你通过函数的返回值表示错误代码，那么函数就不能返回其他的值。
            当然，你也可以通过指针或者C++的引用来返回另外的值，但是这样可能会令你的程序略微晦涩难懂。

            c++异常机制相比C语言异常处理的优势?
                函数的返回值可以忽略，但异常不可忽略。如果程序出现异常，但是没有被捕获，程序就会终止，这多少会促使程序员开发出来的程序更健壮一点。而如果使用c语言的error宏或者函数返回值，调用者都有可能忘记检查，
            从而没有对错误进行处理，结果造成程序莫名其面的终止或出现错误的结果。
                整型返回值没有任何语义信息。而异常却包含语义信息，有时你从类名就能够体现出来。
                整型返回值缺乏相关的上下文信息。异常作为一个类，可以拥有自己的成员，这些成员就可以传递足够的信息。
                异常处理可以在调用跳级。这是一个代码编写时的问题:假设在有多个函数的调用栈中出现了某个错误，使用
            整型返回码要求你在每一级函数中都要进行处理。而使用异常处理的栈展开机制，只需要在一处进行处理就可以
            了，不需要每级函数都处理。

        总结：
            异常：出错后将出错问题返回给调用处。
                 c语言的异常处理比较简单，容易出错。c++处理异常不容易出错。

        7.2 异常语法
            7.2.1 异常基本语法
            总结：
                throw
                try{ }catch(type){}
                这三者连着用

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //1.抛出int类型的异常

                //int mydive(int a,int b)
                //{
                //    if(b == 0)
                //        throw 1;//处理异常 抛出异常，即：抛出一个类型。

                //    return a/b;
                //}

                //void test()
                //{
                //    //尝试捕获异常
                //    try
                //    {
                //        mydive(2,0);
                //    }
                //    catch(int)//如果捕获到int类型
                //    {
                //      cout << "捕获了一个 int 类型的异常" << endl;
                //    }
                //}

                //2.抛出char类型的异常
                //int mydive(int a,int b)
                //{
                //    if(b == 0)
                //        throw 'a';//处理异常 抛出异常，即：抛出一个类型。

                //    return a/b;
                //}

                //void test()
                //{
                //    //尝试捕获异常 try和catch必须同时存在，不能少
                //    try
                //    {
                //        mydive(2,0);
                //    }
                //    catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
                //    {
                //      cout << "捕获了一个 char 类型的异常" << endl;
                //    }
                //}

                //int main()
                //{
                //    test();
                //    return 0;
                //}

                //3.抛出异常后再抛
                int mydive(int a,int b)
                {
                    if(b == 0)
                        throw 'a';//处理异常 抛出异常，即：抛出一个类型。

                    return a/b;
                }

                void test()
                {
                    //尝试捕获异常 try和catch必须同时存在，不能少
                    try
                    {
                        mydive(2,0);
                    }
                    catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
                    {
                      throw 'a';
                    }
                }

                int main()
                {
                    try
                    {
                        test();
                    }
                    catch (char)
                    {
                        cout << "捕获了一个 char 类型的异常" << endl;
                    }
                    return 0;
                }

            7.2.2 异常严格类型匹配
                异常机制和函数机制互不干涉，但是捕获方式是通过严格类型匹配
                即：
                    抛出的类型 和 匹配的类型 是严格匹配的，若抛出的类型没有被匹配，程序会终止

                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    int mydive(int a,int b)
                    {
                        string str = "hello";
                        if(b == 0)
                            throw str;//处理异常 抛出异常，即：抛出一个类型。

                        return a/b;
                    }

                    void test()
                    {
                        //尝试捕获异常 try和catch必须同时存在，不能少
                        try
                        {
                            mydive(2,0);
                        }
                        catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
                        {
                            cout << "捕获了一个 char 类型的异常" << endl;

                        }
                        catch(int)
                        {
                            cout << "捕获了一个 int 类型的异常" << endl;
                        }
                        catch(double)
                        {
                            cout << "捕获了一个 double 类型的异常" << endl;
                        }
                        catch(...)  //由于如果匹配不到类型，程序会终止，因此可使用catch(...),表示匹配其它类型的异常
                        {
                            cout << "捕获了一个 其它 类型的异常" << endl;
                        }
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            7.2.3 栈解旋（unwinding）
                异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上构造的所有对象，都会被自动析构。析构的顺序与构造的顺序相反，这一过程称为栈的解旋(unwinding).

                *即：异常被抛出后,从try开始一直到throw期间定义的所有的对象，在throw之后都会被释放。
                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Person
                    {
                    public:
                        Person(string name1)
                        {
                            this->name = name;
                            cout << "构造" << endl;
                        }

                        ~Person()
                        {
                            cout << "析构" << endl;
                        }
                        string name;
                    };

                    void func()
                    {
                        Person p1("Bob");
                        Person p2("lihua");
                        cout << "002" << endl;
                        throw 1;
                    }
                    void test()
                    {
                        try
                        {
                            Person p1("lucy");
                            func();
                        }
                        catch(int)
                        {
                            cout << "002" << endl;  //001 和 002 主要用于分析 析构函数是在什么时候调用的。
                            cout << "捕获了一个 int 类型的异常" << endl;
                        }
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

            7.2.4 异常接口声明
                为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有类型，例如:void func() throw(A,B,C);这个函数func 能够 且 只能抛出类型 A,B,C及其子类型的异常。
                如果在函数声明中没有包含异常接口声明，则此函数可以抛任何类型的异常，例如:void func()
                一个不抛任何类型异常的函数可声明为:void func() throw()
                如果一个函数抛出了它的异常接口声明所不允许抛出的异常,unexcepted函数会被调用，该函数默认行为调用terminate 函数中断程序。
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;
                //可抛出所有类型异常
                void TestFunction1()
                {
                    throw 10;
                }

                //只能抛出 int char char* 类型异常
                void TestFunction2() throw(int,char,char*)
                {
                    string exception = "error";
                    throw exception;
                }

                //不能抛出任何类型异常
                void TestFunction3() throw()
                {
                    throw 10;
                }


                int main()
                {
                    try{
                //        TestFunction1();
                //        TestFunction2();
                //        TestFunction3();
                    }
                    catch(...)
                    {
                        cout << "捕获异常" << endl;
                    }
                    system("pause");

                    return EXIT_SUCCESS;
                }
                //分别在QT、VS、Linux下做测试，QT 和 Linux正确

            7.2.5 异常变量生命周期
                throw的异常是有类型的，可以是数字，字符串，类对象
                throw的异常是有类型的，catch需严格匹配异常类型

            总结：
                抛出对象 尽量用 匿名对象抛出，
                接收也尽量使用引用来接收 这样可以减少创建对象节约空间。

                抛出的匿名对象的生命周期在catch之后。
                创建对象p1再抛出时，抛的是一个匿名对象。创建的对象p1的生命周期是在throw之后，匿名对象的生命周期在catch之后。

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                class Myexecption
                {
                public:
                    Myexecption()
                    {
                        cout << "构造函数" << endl;
                    }

                    ~Myexecption()
                    {
                        cout << "析构函数" << endl;
                    }

                    void error()
                    {
                        cout << "my error" <<endl;
                    }

                };

                void fun()
                {
                //    //抛一个匿名对象
                //    throw Myexecption();    //如果抛一个匿名对象，其生命周期在catch里面

                    Myexecption p1;
                    throw p1;


                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(Myexecption &p) //使用引用接
                    {
                        p.error();
                    }
                }
                int main()
                {
                    test();
                    return 0;
                }

            7.2.6 异常的多态使用
            例：
                //异常的多态实现：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //父类：
                class Myexception
                {
                public:
                    virtual void error() = 0;
                };

                //子类
                class Out_of_range:public Myexception
                {
                public:
                    void error()
                    {
                      cout << "out_of_range" << endl;
                    }
                };

                class Bad_cast:public Myexception
                {
                public:
                    void error()
                    {
                      cout << " Bad_cast" << endl;
                    }
                };

                void fun()
                {
                //    throw Out_of_range();
                    throw Bad_cast();
                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(Myexception &p) //用父类的指针或引用来接
                    {
                        p.error();
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }

        7.3 c++标准异常库
            7.3.1 标准库介绍
                标准库也提供了很多的异常类，他们是通过继承组织起来的。异常类继承层级结构图如下：

                                                range_error
                            runtime_error{      overflow_error
                                                underflow_error

                exception{  bad_alloc
                            bad_exception
                            ios_bass::failure
                            bad_cast
                            bad_typeid

                                                length_error
                            logic_error{        domain_error
                                                out_of_range
                                                invalid_argument

                    <exception> <stdexcept><typeninfo><new><ios>

                每个类所在的头文件在图下方标识出来。
                标准异常类的成员:
                1.在上述继承体系中，每个类都有提供了构造函数、复制构造函数、和赋值操作符重载。
                2.logicerror 类及其子类、runtimeerror 类及其子类，它们的构造函数是接受一个string 类型的形式参数，用于异常信息的描述
                3.所有的异常类都有一个 what()方法，返回 const char*类型(C风格字符串)的值，描述异常信息。

            标准异常类的具体描述：
                异常名               描述
                exception           所有标准异常类的父亲
                bad_alloc           当operator new and operator new[],请求分配内存失败时
                bad_exception       这是个特殊的异常，如果函数的异常抛出列表里声明了 badexception 异常，当函数内部抛出了异
                                    常抛出列表中没有的异常，这是调用的unexpected 函数中若抛出异常，不论什么类型，都会被替
                                    换为badexception类型
                bad_typeid          使用 typeid 操作符，操作一个 NULL 指针，而该指针是带有虚函数的类，这时抛出 bad_typeid 异常
                bad_cast            使用 dynamic_cast 转换引用失败的时候
                ios_base::failure   io 操作过程出现错误
                logic_error         逻辑错误，可以在运行前检测的错误
                runtime_error       运行时错误，仅在运行时才可以检测的错误


            logic_error 的子类:

                length_error        试图生成一个超出该类型最大长度的对象时，例如vector的resize 操作
                domain_error        参数的值域错误，主要用在数学函数中。例如使用一个负值调用只能操作非负数的函数
                outofrange          超出有效范围
                invalid_argument    参数不合适。在标准库中，当利用 string 对象构造 bitset 时，而 string 中的字符不是’0'或'1'的时候，抛出该异常

                ...                  ...

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                //exception
                #include <stdexcept>
                using namespace std;

                void fun()
                {
                //    //抛出越界
                //    throw out_of_range("越界");

                    //抛出段错误
                    throw invalid_argument("段错误");//抛出段错误：段错误就是无效内存访问。
                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(exception &p) //用父类的指针或引用来接
                    {
                        cout << p.what() << endl;   //p.what()打印出错信息。
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }

            7.3.2 编写自己的异常类
                1.标准库中的异常是有限的;
                2.在自己的异常类中，可以添加自己的信息。(标准库中的异常类值允许设置一个用来描述异常的字符串)。

                如何编写自己的异常类？
                ① 建议自己的异常类要继承标准异常类。因为 C++中可以抛出任何类型的异常，所以我们的异常类可以不继承自标准异常，但是这样可能会导致程序混乱，尤其是当我们多人协同开发时。
                ②)当继承标准异常类时，应该重载父类的what函数和虚析构函数。
                ③ 因为栈展开的过程中，要复制异常类型，那么要根据你在类中添加的成员考虑是否提供自己的复制构造函数。

            注意：
                string类里面，有一个的函数：.c_str();这个函数可以将string类转成const char*
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                //exception
                #include <stdexcept>
                using namespace std;

                class Longlongerror:public exception
                {
                public:
                    Longlongerror(string data)
                    {
                        this->data = data;
                    }

                    Longlongerror(char* data)
                    {
                        this->data = data;
                    }

                    const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
                    {
                        return data.c_str();
                    }

                    string data;
                };
                void fun()
                {
                    throw Longlongerror("长长的错误");
                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(exception &p) //用父类的指针或引用来接
                    {
                        cout << p.what() << endl;   //p.what()打印出错信息。
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }


*/




//笔记区
//###################################################################
//代码区
//################################################################
//类
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
//c语言的结构体不能放函数
struct stu
{
    int a;
    int b[5];
};
//c++中可以放函数
struct stu1
{
    int a;
    int b[5];
    void prtint_stu()
    {
          cout<<a<<endl;
    }
};
struct student
{
    //学生的属性 和 数据
    int age;
    int id;
    char name[256];
    //操作属性的叫做 方法 或 行为 -- 函数
    void print()
    {
          cout<<age<<" "<<id<<" "<<name<<endl;
    }
};
void test01()
{
      student obj;
      obj.age = 10;
      obj.id = 20;
      strcpy(obj.name,"lucy");
      obj.print();
}
int main()
{
    test01();
    return 0;
}
*/
//#########################################################################################
// c++ 里面对事物的封装。
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//c++ 中对事物的封装，将属性 和 行为 封装在一起。
//类 将事物抽象成属性和行为，并且 封装在一起。   将struct 改为 class
//struct Person
//{
//    //人的属性
//    int age;
//    char name[128];
//    //人的行为
//    void Person_eat()
//    {
//        cout << name<<"吃饭"<<endl;
//    }
//};

//struct 和 class 的区别：
// 类中所有的成员 访问权限都是私有的（private），只能类内访问，类外无法访问。
// 而结构体中所有的成员，默认都是公有的，类中的所有成员默认是私有的。也可以修改成员访问权限的属性：public:
class Person
{

    //人的属性
public:
    int age;
    char name[128];
    //人的行为
    void Person_eat()
    {
        cout << name<<"吃饭"<<endl;
    }
};

struct Dog
{
    //人的属性
    int age;
    char name[128];
    //人的行为
    void Dog_eat()
    {
        cout << name<<"吃饭"<<endl;
    }
};

void test01()
{
    //通过类 实例化出一个变量，这个变量叫对象
    Person p1 = {10,"bob"};
    p1.Person_eat();

    Dog b1 = {3,"Tom"};
    b1.Dog_eat();
}
int main()
{
    test01();
    return 0;
}
*/
//########################################################################
//类 成员的 权限控制
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


class Person
{
    void show()
    {
        cout << tall <<endl;
        cout << money <<endl;
        cout << Age <<endl;
    }
public:     //公有的，类内 类外 都可访问
    int tall;//多高，可以让外人知道
protected:  //保护的，类外不可访问，类内可以访问。    在继承中：子类可以访问
    int money;//有多少钱，只能儿孙知道
private:    //私有的，类外不可访问，类内可以访问。    子类不可访问
    int Age;  //不想外人知道
};

void test01()
{
    Person p;
    p.tall = 180;
}

int main()
{
    return 0;
}
*/
//#############################################################
//public、private、protected 成员权限控制
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//class Person
//{
//public:
//    int age;
//    char * name;

//};

class Person
{
public: //提供接口
    void set_age(int age1)//类内成员，可以直接访问age
    {
        if(age1>= 0 && age1 <= 150)
        {
            age = age1;
        }
    }
    void set_name(char *name1)
    {
        if(name1 != NULL)
        {
            strcpy(name,name1);
        }
    }
private: //不在私有，而是设置一个可以修改值的接口
    int age;
    char * name;

};

class AccessLevels{
public:
    //对只读属性进行只读访间
    int getReadonly(){ return readOnly;}

    //对读写属性进行读写访问
    void setReadWrite(int val){readWrite = val;}
    int  getReadWrite() {return readWrite;}

    //对只写属性进行只写访问
    void setWriteOnly(int val) {writeOnly = val;}
private:
    int readOnly; //对外只读访问
    int noAccess; //外部不可访问
    int readWrite;//读写访问
    int writeOnly;//只写访问
protected:
    ;
};
void test01()
{
    //将成员变量 设置为公有 的缺陷：类外随时可以无限制地改变成员。
    Person p1;
    p1.age = 200;
    p1.name = (char*)malloc(128);
    strcpy(p1.name,"Bob");
    p1.name = NULL;
}
int main()
{

}
*/
//#######################################################################
//4.1.4 课堂练习
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Person{
    public:
        void person_init(int age1,char *name1)
        {
            age = age1;
            strcpy(name,name1);
        }

        void show_person()
        {
            cout << age <<" "<<name<<endl;
        }

        int get_age()
        {
            return age;
        }

        void set_age(int age1)
        {
            if(age1 >= 0&& age1<= 100)
            {
                age = age1;
            }
        }

        char* get_name()
        {
            return  name;
        }
        void set_name(char* name1)
        {
            strcpy(name,name1);
        }
    private:
        int age;
        char name[128];
};

void test01()
{
    Person p1;
    p1.person_init(20,"Bob");
    p1.show_person();
    p1.set_age(30);
    p1.set_name("Tom");
    p1.show_person();

}
int main()
{
    test01();
    return 0;
}
*/
//#####################################################################
//立方体案例：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Cube
{
public:

    void set_L(int l)
    {
        L = l;
    }
    void set_W(int w)
    {
        W = w;
    }
    void set_H(int h)
    {
        H = h;
    }

    int get_L()
    {
        return L;
    }
    int get_W()
    {
        return W;
    }
    int get_H()
    {
        return H ;
    }

    //求体积
    int get_cube_V()
    {
        return L*W*H;
    }
    //求面积
    int get_cube_S()
    {
        return 2*W*L+2*W*H+2*L*H;
    }
    //判度两个立方体是否相等
    bool compare_cube(Cube & c1)
    {
        return (c1.get_H() == H && c1.get_L()==L &&c1.get_W() == W);
    }
private:
    int L;
    int W;
    int H;
};

bool compare_cube(Cube &a,Cube &b)
{
    return a.get_H() == b.get_H()&& a.get_L() == b.get_L()&&a.get_W()==b.get_W();
}

void test01()
{
    Cube c1;
    c1.set_L(10);
    c1.set_W(20);
    c1.set_H(30);
   cout<< c1.get_cube_S()<<" "<< c1.get_cube_V()<<endl;

   Cube c2;
   c2.set_L(20);
   c2.set_W(20);
   c2.set_H(30);
   if(c1.compare_cube(c2))
   {
       cout<< "两个立方体相等"<<endl;
   }
   else
   {
        cout<< "两个立方体不相等"<<endl;
   }

   if(compare_cube(c1,c2))
   {
       cout<< "两个立方体相等"<<endl;
   }
   else
   {
        cout<< "两个立方体不相等"<<endl;
   }

}


int main()
{
    test01();

    return 0;
}
*/
//#################################################################
//点和圆类，判断距离
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//点类
class Point{
public:
    void setX(int x){mX = x;}
    void setY(int y){mY = y;}

    int getX(){ return mX; }
    int getY(){ return mY; }
private:
    int mX;
    int mY;
};

//圆类
class Circle
{
public:
    void setP(int x,int y){
        mP.setX(x);
        mP.setY(y);
        }
    void setR(int r){mR=r;}
    Point& getP(){return mP;}//返回圆心点时，返回的是别名
    int getR(){return mR;}//返回半径

    //判断点和圆的关系
    void IsPointInCircle(Point& point)//传点的类
    {
        int distance = ((point.getX()-mP.getX()) * (point.getX()-mP.getX())+(point.getY()- mP.getY())*(point.getY()- mP.getY()));
        int radius =mR*mR;
        if(distance< radius){
            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆内!"<< endl;
        }
        else if(distance > radius){
            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆外!"<< endl;
        }
        else
        {
            cout<< "Point("<< point.getX()<<"，"<< point.getY()<<")在圆上!"<< endl;
        }
    }
private:
    Point mP; //圆心
    int mR; //半径
};

void test(){
    //实例化圆对象
    Circle circle;
    circle.setP(20,20);
    circle.setR(5);
    //实例化点对象
    Point point;
    point.setX(25);
    point.setY(20);
    cout<< "("<<circle.getP().getX()<<","<<circle.getP().getY()<< ")" <<"  "<<circle.getR()<<endl;
    circle.IsPointInCircle(point);
}
int main()
{
    test();
    return 0;
}
*/
//###################################################
//构造与析构函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Person{
    public:
        int m_age;
        //string 字符串类，头文件:  #include <string>
        string m_name;//可赋值为 char* 的指针 或者 字符串。

        //构造函数，函数名 与 类名 一致，无返回值，可以有参数，可函数重载。
        Person(int age,string name)
        {
            m_age = age;
            m_name = name;
            cout<<"构造函数！"<<endl;
        }

        //析构函数，函数名 在 类名 前加“ ~ ”，没有返回值，不能有参数，不能发生重载。
        ~Person()
        {
            cout<<"析构函数！"<<endl;
        }
};

void test()
{
    //构造函数是在 实例化对象时创建，即，在内存 开辟空间 时调用。
    //构造函数的传参 类似于 函数传参，就直接：Person p1(30,"lisa")
    Person p1(30,"lisa");

    //p1出作用域时，销毁，而析构函数 就是在 销毁时自动调用。
}

int main()
{
    test();
    return 0;
}
*/
//##################################################
//构造函数的分类
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //无参构造
    Person()
    {
        cout << "无参构造!" << endl;
    }

    //有参构造
    Person(int age,string name)
    {
        cout << "有参构造" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
    //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
    Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"拷贝构造"<<endl;
    }
};

void test()
{
    //注意：使用无参构造时，不能加括号。
    //如果人为提供了有参和无参构造，系统将不在提供默认的无参构造
    //若人为没提供构造函数，则系统默认生成一个空无参构造。
    Person p1;
    Person p2(30,"Lisa");

    Person p3(p2);//调用系统默认提供的拷贝构造：
    //拷贝构造调用时机：旧对象初始化新对象

     cout<<p3.m_age<<"  " << p3.m_name <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//###########################################################
//调用构造函数的方法
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //无参构造
    explicit Person()
    {
        cout << "无参构造!" << endl;
    }

    //有参构造
    explicit Person(int age,string name)
    {
        cout << "有参构造" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
    //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
    //关键字：explicit。作用：用户不能通过隐式法调用构造函数
    explicit Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"拷贝构造"<<endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

void test()
{
    //匿名对象，没有名字，其生命周期在当前行。
    Person(10,"lucy");//调用有参构造创建匿名对象，
    Person();//匿名对象调用无参构造需要加括号
    Person p1(10,"lisa");
    //Person(p1);//错误，匿名对象 不能使用 括号法 调用 拷贝构造。
}

//显示法调用构造函数
void test1()
{
    Person p1 = Person(10,"lucy");//只调用了 一次 有参构造 和 一次 析构函数，即有参构造 是 匿名对象 调用的。  用p1 这个名字去接替 匿名构造 构造出的空间。（没有再创建一个类来调用拷贝构造）
    Person P2 = Person(p1);       //显示法 调用 拷贝构造函数
    Person P3 = Person();         //显示法 调用 无参构造
}

//隐式法 调用 构造函数
//若想 别人不能使用隐式法 来调用你的构造函数，则可在构造函数前 加关键字：explicit，用户不能通过隐式法调用构造函数
void test2()
{
//    Person p1 = {10,"lucy"};      //隐式法 调用    有参构造
//    Person P2 = p1;               //隐式法 调用    拷贝构造
//    Person P3;                    //隐式法 不能调用 无参构造
}
int main()
{
    test1();
    return 0;
}
*/
//#################################################
//拷贝构造函数的调用时机: 旧对象 初始化 新对象
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //无参构造
    explicit Person()
    {
        cout << "无参构造!" << endl;
    }

    //有参构造
    explicit Person(int age,string name)
    {
        cout << "有参构造" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //拷贝构造只是简单的值拷贝。且拷贝构造是常量引用
    //如果自定义了一个拷贝构造，则系统不会再提供默认的拷贝构造。
    //关键字：explicit。作用：用户不能通过隐式法调用构造函数
    Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"拷贝构造"<<endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

//1.旧对象初始化新对象
void test1()
{
    Person p(10,"lili");
    Person p1(p);   //调用拷贝构造
    Person p2 = Person(p);//显示法调用 拷贝构造函数
    Person p3 = p;//隐式法调用拷贝构造，相当于 Person p2 = Person(p);
}

//2.传递的参数是普通对象，函数参数也是普通对象，传递将会调用拷贝构造。
void doBussiness(Person p){}    //Person p = p;

void test2()
{
    Person p(20,"lisa");//有参构造初始化
    doBussiness(p); //拷贝构造，旧对象初始化新对象
}

//3.函数 返回值。返回值局部对象
Person MyBusiness()
{
    Person p(30,"lihua"); //有参构造 初始化局部对象
    cout << "局部p:"<<(int *)&p <<endl;   //输出局部对象的地址
    return p;   //这里返回的时候 应该调用一次拷贝构造，返回一个匿名对象
}

void test3()
{
    // vs release、 qt下没有调用拷贝构造函数
    // vs debug 下调用一次拷贝构造函数
    Person p = MyBusiness();//这里赋值 也应该调用一次拷贝构造。由于编译器有优化，使得直接将p命名给了匿名对象。
    //
    cout << "局部p:"<< (int*) &p << endl; //输出局部对象返回的地址，（课程里两次打印的地址是不同的，因为 函数返回时 是调用 匿名拷贝构造，重新开辟的内存空间）而我的两个地址是一样的。故销毁也只销毁一次，他销毁两次。
}

int main()
{
    test3();
    return 0;
}

*/
//######################################
//浅拷贝
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    int m_age;
    char* m_name;

    Person(int age,char *str)
    {
        cout << "有参构造"<<endl;
        m_age = age;
        m_name = (char*)malloc(strlen(str)+1);
        strcpy(m_name,str);
    }

    void show()
    {
        cout << m_name << " " <<m_age<<endl;
    }

    ~Person()
    {
        cout << "析构"<<endl;
        if(m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
    }
};

void test()
{
    Person p(10,"lihua");
    p.show();
    Person p1(p);//调用默认拷贝构造 进行简单值拷贝，字符串指针指向同一块地址。因此运行到出函数时，两个对象的析构函数分别free同一地址，导致程序错误。
}
int main()
{
    test();
    return 0;
}

*/
//#####################################
//深拷贝
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    int m_age;
    char* m_name;

    Person(int age,char *str)
    {
        cout << "有参构造"<<endl;
        m_age = age;
        m_name = (char*)malloc(strlen(str)+1);
        strcpy(m_name,str);
    }

    Person(const Person &p)
    {
        m_age = p.m_age;
        m_name = (char *)malloc(strlen(p.m_name)+1);
        strcpy(m_name,p.m_name);
    }
    void show()
    {
        cout << m_name << " " <<m_age<<endl;
    }


    ~Person()
    {
        cout << "析构"<<endl;
        if(m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
        }
    }
};

void test()
{
    Person p(10,"lihua");
    p.show();
    Person p1(p);//调用默认拷贝构造 进行简单值拷贝，字符串指针指向同一块地址。因此运行到出函数时，两个对象的析构函数分别free同一地址，导致程序错误。
}
int main()
{
    test();
    return 0;
}
*/
//######################################
//初始化列表
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person{
public:
#if 0
    //传统方式初始化:先在外面 定义 变量，再在这里初始化赋值。相当于下面是定义，这里是初始化
    Person(int a,int b,int c)
    {
        mA = a;
        mB = b;
        mC = c;
    }
#endif
    //初始化列表方式初始化:先 声明 变量，再根据 声明的顺序 进行定义初始化。相当于下面三个只是声明，在这里冒号后面才是 定义 和 初始化。
    //注意：这里定义的顺序，就是冒号后面的顺序。定义的顺序需要同声明的顺序一致。
    Person(int a,int b, int c):mA(a),mB(b),mC(c){}//给构造函数成员赋值的时候，可以把赋值的方式写在函数的后面

    void printperson(){
        cout << "mA: " << mA << endl;
        cout << "mB: " << mB << endl;
        cout << "mC: " << mC << endl;
    }
private:
    int mA;
    int mB;
    int mC;
};

void test()
{
    Person p(2,3,5);
    p.printperson();
}

int main(){
    test();
    return 0;
}
*/
//###########################################
//类对象 作为 成员
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Game
{
  public:
    Game(string name)
    {
        cout << "game 的构造函数" << endl;
        gam_name = name;
    }
    ~Game()
    {
        cout<< "game 的析构"<<endl;
    }
    string gam_name;
};
class Phone
{
public:
    //构造函数：
    Phone(string name)
    {
        cout << "phone 的构造函数" << endl;
        pho_name = name;
    }
    ~Phone()
    {
        cout<< "phone 的析构"<<endl;
    }
    string pho_name;


};
class Person
{
public:
    //由于这么写是先定义三个变量，而定义的类没有无参构造，所以定义会出错。因此要使用 初始化列表来进行初始化

//    Person(string per_name1,string pho_name1,string gam_name1)
//    {
//        per_name = per_name1;
//        phone.pho_name = pho_name1;
//        game.gam_name = gam_name1;
//    }

    Person(string per_name1,string pho_name1,string gam_name1):per_name(per_name1),phone(pho_name1),game(gam_name1){
        cout << "person 的构造函数" << endl;
    }

    void show()
    {
        cout << per_name<<"拿着" <<phone.pho_name<<"玩"<<game.gam_name << endl;
    }

    ~Person()
    {
        cout<< "person 的析构"<<endl;
    }
    string per_name;
    Phone phone; //一个对象作为另一个对象的成员。
    Game game;
};

void test()
{
    Person p1("Bob","诺基亚","原神");
    p1.show();
}
int main()
{
    test();
    return 0;
}

//phone 的构造函数
//game 的构造函数
//person 的构造函数
//Bob拿着诺基亚玩原神
//person 的析构
//game 的析构
//phone 的析构
*/
//#####################################################
//动态申请对象之malloc和free对对象创建的局限验证：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;
class Person
{
public:
    Person()
    {
        cout << "Person 的无参构造" << endl;
    }
    int a;
    ~Person()
    {
        cout << "Person 的析构函数" << endl;
    }
};

void test()//函数调用时 不会调用构造和析构函数
{
    Person *p = (Person *)malloc(sizeof(Person));
    free(p);
}

int main()
{
    test();
    return 0;
}
*/
//#################################
//在c++中动态开辟对象：new的使用
//delete void *导致内存泄露
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person()//无参调用
    {
        cout << "无参构造" << endl;
    }
    Person(int a)//有参调用
    {
        age = a;
        cout << "有参构造" << endl;
    }
    int age;
    ~Person()
    {
        cout << "析构函数" << endl;
    }
};

//new一个数
void test()
{
    int *p = new int;//申请一块sizeof(int)大小的堆空间。并且对这块空间进行初始化。
    cout << *p << endl;//并且对这块空间进行初始化
    *p = 100;
    cout << *p << endl;
    delete p;//释放申请的空间。
}
//new一个对象
void test1()
{
    Person * p = new Person;
    delete p;

}
//new一个有参构造和 对象数组
void test3()
{
    //new时 调用有参构造
    Person * p =new Person(10);
    delete p;
    Person * a =new Person[10];//注意new数组时，不能调用有参构造，只能调用无参构造。
    delete []a;//
}
//new一个数组
void test2()
{
    //new一个数组时返回的是其首元素地址。
    int*p = new int[10];
    for(int i = 0;i<10;i++)
    {
       cout << (p[i] = i+100)<< endl;
    }
    delete []p;//如果这样写只会释放首个元素和首元素地址。后面的不会释放，因此释放数组应写为：delete [] p;
}
void test4()
{
    void* p = new Person;
    delete p;   //p类型是void *所以不会调用析构函数
}
int main()
{
    test3();
    return 0;
}
*/
//#####################################################
//静态成员变量
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
  public:
    int a;       //局部变量是在运行阶段就确定好了内存的地址。
    //静态成员变量不能在类内初始化，只能在类内声明，定义在全局。声明的作用只是限制了静态成员变量的作用域。并且，静态变量是存在静态全局区。
    static int b;//静态成员变量，在编译阶段就分配好了内存。初始化：不能在类内初始化，如：static int b = 10;就会报错，因为他在编译器件就确定好了地址，而每次定义对象的时候就会修改它，是会出错的
};
int b;//这是作用在全局区域下的变量b，不表示为Person类下的成员
int Person::b = 10; //所以应该加一个Person的作用域。

//静态成员变量的实例化使用
void test()
{
    Person p;
    p.b = 100;
    cout << p.b <<endl;
}
//静态成员变量的作用域使用，并与普通成员变量进行对比
void test1()
{
    //这样也是可以的，因为虽然没有定义对象，但由于b在编译阶段就已经分配好了空间，并且初始化的值为10。
    cout << Person::b <<endl;//通过类的作用域来访问类的静态成员函数
    //cout << Person::a <<endl;// 错误，不能访问a.必须实例化一个对象才会有a。
}
//静态成员变量独此一份
void test2()
{
    Person p;
    p.b = 100;
    cout << p.b <<endl; //100
    Person k;
    k.b = 200;
    cout << p.b <<endl; //200 ,因此静态成员变量独此一份。
}

int main()
{
    test2();
    return 0;
}

*/
//#######################################################
//静态成员函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    int a;
    static int b;

    void show()
    {
        cout << a << " " << b <<endl;
    }

    //静态成员函数，可以访问静态成员变量，不能访问 非静态成员变量（普通成员变量）。
    //因为静态成员函数在编译的时候就已经有了，因此，可以用作用域来调用，即：Person::static_show()，此时对象都还没创建，还没有创建a,因此访问不了a
    static void  static_show()
    {
//        cout << a << " " << b <<endl;//a不能访问，
        cout << "静态成员函数！" <<endl;
    }

};

int Person::b = 10;

void test()
{
    Person::static_show();//通过类的作用域访问静态成员函数

    Person p1;
    p1.static_show();//通过对象访问静态成员函数
}

int main()
{
    test();
    return 0;
}
*/
//#########################################################
//const修饰静态成员变量：由于静态成员变量是共享的 且 可以被修改的。  若希望其不可被修改则应加 const修饰
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    int a;

    //静态成员变量不能在类内初始化，只能在类内声明，定义在全局。声明的作用只是限制了静态成员变量的作用域。并且，  静态变量是 存在 静态全局区，是可以被改变的。
    static int b;//静态成员变量，在编译阶段就分配好了内存。初始化：不能在类内初始化，如：static int b = 10;就会报错，因为他在编译器件就确定好了地址，而每次定义对象的时候就会修改它，是会出错的

    const static int c = 1000;// const 修饰的全局变量保存在常量区， 同理，const 修饰的静态成员变量 是保存在 常量区，不可被修改（只读的），在内存也中只有一份。const 修饰的静态成员变量是一个常量，可以在类里面赋值。不用放在类外再实现定义赋值。
    //并且由于他是const 修饰的静态成员变量， 因此在编译的时候也定义好了，静态成员函数可以直接访问。

    void show()
    {
        cout << a << " " << b <<endl;
    }

    //静态成员函数，可以访问静态成员变量，不能访问 非静态成员变量（普通成员变量）。
    //因为静态成员函数在编译的时候就已经有了，因此，可以用作用域来调用，即：Person::static_show()，此时对象都还没创建，还没有创建a,因此访问不了a
    static void  static_show()
    {
//        cout << a << " " << b <<endl;//a不能访问，
        cout << "静态成员函数！" <<endl;
        cout << c << endl;
    }

};

int Person::b = 10;

void test()
{
    cout << Person::c << endl;//可以通过作用域进行访问。

    Person p;
    cout << p.c <<endl;// 也可以通过定义一个对象来访问。

    p.static_show();//静态成员函数 也可以直接调用 const 修饰的静态成员变量。

}

int main()
{
    test();
    return 0;
}
*/
//###################################################
//单例模式：一个类只能创建出一个对象
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Feifei
{
public:
    int age;
    int yanzhi;

    //4.思考方式：由于在外面无法再创建对象，故在里面new一个对象
    //5.但由于它是 成员变量，需要先有对象，才会有这个成员变量。
    //6.但实例化不出对象，故仍然得不到这个变量。因此需要将变量变成静态的，加static进行修饰,让其成为静态成员变量。
    //static Feifei* single;//7.静态成员变量，类内声明，类外定义

    //11.定义一个接口,静态的成员函数(普通的成员函数需要对象调用)
    static Feifei * instance()
    {
        return single;//将single返回，让其只读，不能修改。
    }
private:
    static Feifei *single;

    Feifei()//无参构造私有化。
    {

    }
    Feifei(const Feifei&p)
    {

    }
};
//8.定义静态成员变量，完成单例的实现。但有一个问题:调用拷贝构造仍然可以实现后面的对象构造,因此需要将拷贝构造也进行私有化。
Feifei * Feifei::single= new Feifei;//类外定义

void test()
{
    //1.事先得不到只创建一个对象的类
    //2.故先得一个，一个对象都创建不了的类，即：构造函数私有化。（由于对象的创建需要调用无参构造，如果让他调用不了无参构造，则无法创建对象。）
//    Feifei p;   //3.由于无参构造是私有的，因此都不能创建对象。
//    Feifei p1;//

    // 2.1通过类的作用域实现对single的操作。
//    Feifei::single->age = 30;         //12.由于接口函数的出现，不能再用此方法使用single
//    Feifei::single->yanzhi = 100;

     //9.调用拷贝构造 实例化出 另一个对象,因此,需要将拷贝构造也进行私有化
    //Feifei p1(*Feifei::single);

    //10.还有一个问题，若不小心将single 的地址赋值为 NULL，则再也不能找到其地址，因此也需要将创建私有化
}

void test1()
{
    //13.单例的使用
    Feifei *p = Feifei::instance();//获得唯一指针
    p->age = 30;
    p->yanzhi = 100;

    Feifei *p1 = Feifei::instance();
    cout << p1->age<< " " << p1->yanzhi <<endl;
}

int main()
{
    test1();
    return 0;
}
*/
//####################################################
//类的成员模型初探。
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;


//由此知：只有普通成员变量 才属于这个 类的实例化对象 的一个内存。（给对象申请内存时，仅普通成员变量才会占用对象的空间）
class Person
{
public:
    int a;//普通成员变量
    static int b;//静态成员变量不存在于类实例化的对象中，只是声明在类中。存放在静态全局区。

    //俩函数存放在代码区。
    void show()//普通成员函数，也不存在于类实例化的对象中
    {
        cout << a << " " << b << endl;
    }
    static void show1()//静态成员函数，也不存在于类实例化的对象中
    {
        cout << b << endl;
    }

};

int Person::b = 1;
void test()
{

    //1. 空类的大小是1 不是0（有地址，故有空间大小）
    //2. 再加上 普通成员变量 a 后 为 4字节。
    //3. 再加上 静态成员变量 b 后 为 4字节，可见静态成员变量不属于类
    //4. 再加上 普通成员函数 大小仍为4，可见，new一个对象后，成员函数并不会占用类的这个对象的空间大小
    Person p;
    p.show();
    p.show1();
    cout << sizeof(Person) <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//#####################################################
// this指针
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    int a;
    static int b;

    //由于函数存在于代码区，只有一份，则问题是调这个函数 打印 a的时侯，怎么知道是p还是p1的a?
    //因为，类的成员函数后面 编译器 默认加了一个参数: Person * const this   ; this指针 指向 调用该函数的对象，故，谁调用该函数，函数就获得谁的地址。
    //对象调用成员函数，会将对象的地址传给this指针。
    void show() //Person * const this，编译器默认加了这个类型。(指针常量，this的指向不能改变)
    {
        cout << a << " " << b << endl;          //所以这里就变成了 cout << this->a << " "  << this->b << endl;
    }
    static void show1()
    {
        cout << b << endl;
    }

};

int Person::b = 1;

void test()
{
    Person p1;
    p1.a = 100;

    Person p2;
    p2.a = 1000;

    //show函数存在代码区，仅一份，p1对象调用函数的时候，函数怎么知道是打印p1还是p2的a?
    p1.show();
    p2.show();
}
*/
//########################################################
//this指针的使用
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person(int age,string name) //因为每个成员函数都会有一个this指针，指向调用成员函数的对象的地址。故this指针指向 p的地址。
    {
//        age = age;     //这里两个 age 和 name都是指的形参。不会进行赋值
//        name = name;

        this->age = age;
        this->name = name;
    }
    int age;
    string name;
    void show()
    {
        cout << age << " " << name << endl;
    }

    Person person_add(Person &p1)// 写在类里，作为成员函数，实现相加
    {
        Person p(this->age+p1.age,this->name+p1.name);
        return p;
    }

};

//类外定义作为 全局函数 实现相加
Person person_add(Person &p1,Person &p2)
{
    Person p(p1.age+p2.age,p1.name+p2.name);
    return p;
}

void test()
{
    Person p(10,"lucy");
    p.show();
}
void test1()
{
    Person p1(10,"hello");
    Person p2(20,"world");

    //实现：p3 = p1+p2 30 helloworld

    //方法一、全局函数
    Person p3 = person_add(p1,p2);
    p3.show();

    //方法二、成员函数
    Person p4 = p1.person_add(p2);
    p4.show();

}
int main()
{
    test1();
    return 0;
}
*/
//###################################################################
//const 修饰的成员变量
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person(int age,string name)
    {
        this->age = age;
        this->name = name;
    }
    int age;
    string name;
    void show()
    {
        cout << age << " " << name << endl;
    }

    //Person * const this -----> p1     //因此应改为 常量指针常量：const Person * const this，这样指针指向的的空间内容便不能修改
    //由于Person * const this 被隐藏了，因此const 直接放后面：Person person_add(Person &p1)const
    //成员函数后面加了 const这种函数，称为 常函数。不能通过this指针修改其指向的对象内容。
    Person person_add(Person &p1) const
    {
//        this->age = 100;
        Person p(this->age+p1.age,this->name+p1.name);
        return p;
    }

};

void test()
{
    Person p(10,"lucy");
    p.show();
}

int main()
{
    test();
    return 0;
}
*/
//#########################################################
//全局函数称为类的友元
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Building
{
    friend void print_building(Building &p);// 加friend声明该函数是该类的友元，此时函数就可以访问该类的私有成员了。
public:
    Building(string hall,string bedroom)
    {
        this->bedroom = bedroom;
        this->hall = hall;
    }
    string hall;
private:
    string bedroom;
};

void print_building(Building &p)
{
    cout << p.hall <<" " <<p.bedroom <<endl;//b访问不了私有成员，因此可以使用友元，把这个全局函数声明为这个类的友元，就可以访问私有成员了
}

void test()
{
    Building b1("凌霄殿","闺房");
    print_building(b1);
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
//一个类 成为 另一个类的友元
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Building;//声明

//好朋友类
class Goodgay
{
public:
    Goodgay(string hall,string bedroom);//构造函数，类内声明，类外实现。

    void visit();//可以访问b对象的一个成员函数

    Building *b;
};

//
class Building
{
    friend class Goodgay;               //一个类          成为 另一个类的友元
    friend void Goodgay::visit();       //一个类的成员函数 成为 另一个类的友元
public:
    Building(string hall,string bedroom)
    {
        this->bedroom = bedroom;
        this->hall = hall;
    }
    string hall;
private:
    string bedroom;
};


//注意：这里使用类外声明，以及为何不能写在Building类定义的前面，是因为：这个函数如果类内实现的时候，new一个Building对象是new不出来的。因为上面并没有Building的定义，只有一个声明。
Goodgay::Goodgay(string hall,string bedroom)
{
    //new一个Building对象，放到Goodgay里面的Building指针成员里面
    Goodgay::b = new Building(hall,bedroom);
}

void Goodgay::visit()
{
    cout << b->hall << " " << b->bedroom << endl;//b不能访问类内的私有成员。
}


void test()
{
    Goodgay gd("凌霄殿","闺房");
    gd.visit();
}

int main()
{
    test();
    return 0;
}

*/
//###########################
//4.5 练习1 电视机和遥控友元实现
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

//声明遥控器类
class Remote;

class Television
{
    friend class Remoter;
public:
    enum    //电视机状态
    {
        on,
        off
    };
    enum    //音量从0~100
    {
        MIN_V = 0,
        MAX_V = 100
    };
    enum    //频道从1~255
    {
        MIN_CH = 1,
        MAX_CH = 255
    };

    Television()
    {
        mState = off;
        mVolume = MIN_V;
        mChannel = MIN_CH;
    }

    void power()
    {
        mState = mState ?off:on;
    }

    void volumeUp()
   {
        if(mVolume != MAX_V)
        {
            mVolume++;
        }
        showInfo();
   }

    void volumeDown()
    {
        if(mVolume != MIN_V)
        {
            mVolume--;
        }
        showInfo();
    }

    void channelUp()
    {
        if(mChannel != MAX_CH)
        {
            mChannel++;
        }
        showInfo();
    }

    void channelDown()
    {
        if(mChannel != MIN_CH)
        {
            mChannel--;
        }
        showInfo();
    }

    void showInfo()
    {
        if(mState)
        {
            cout << "status ON, volume " << mVolume << ", channel " << mChannel <<endl;  //输出格式也可以自行修改
        }
    }

private:
    int mState;     //电视状态
    int mVolume;     //声音
    int mChannel;    //频
};

//定义遥控器类
class Remoter
{
private:
   Television *mTv;

public:
   Remoter(Television *tv)
   {
        mTv = tv;
   }
   void power()
   {
        mTv->power();
   }
   void vUp()
   {
        mTv->volumeUp();
   }
   void vDown()
   {
        mTv->volumeDown();
   }
   void chUp()
   {
        mTv->channelUp();
   }
   void chDown()
   {
        mTv->channelDown();
   }

   void setChannel(int ch)
   {
        if(ch >= mTv->MIN_CH && ch <= mTv->MAX_CH)
        {
            mTv->mChannel = ch;
            mTv->showInfo();
        }
   }
};

void test()  //测试函数可以根据自己需求修改
{
    Television *tv = new Television();
    Remoter remoter(tv);
    remoter.power();
    remoter.setChannel(25);
    remoter.vUp();
    remoter.vUp();
    remoter.vUp();
    remoter.chDown();
    remoter.power();
    delete tv;
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//初窥重载
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this ->age = age;
    }

    //方法二：类的成员函数
    Person Person_ADD(Person &p2)
    {
        Person p(this->age+p2.age);
        return p;
    }

    //方法三：成员函数：operator+
    Person operator+ (Person &p2)   //将方法二的函数名 改为 operator+ 即可。
    {
        Person p(this->age+p2.age);
        return p;
    }

    int age;
};

//方法一：全局函数实现类的对象相加。
Person Person_add(Person &p1,Person&p2)
{
    Person p(p1.age+p2.age);
    return p;
}

//方法四、全局函数：operator+
//Person operator+ (Person &p1,Person&p2)
//{
//    Person p(p1.age+p2.age);
//    return p;
//}

void test1()
{
    Person p1(10);
    Person p2(20);
    //要使用p3.age = p1.age + p2.age;这种形式的话，编译器会先去找 方法三 和 方法四这两种重构。
    //方法三、四的调用方式：
    //注意定义了全局的函数 就不能 再有成员函数，会报错
    Person p5 = p1 + p2;    //但若想用此方法，则需在方法二的基础上 将函数名 改为 operator+ ,若有该函数则可以用，若编译器找不到该函数则不能使用此方法。
    Person p6 = p1.operator+(p2);

    //方法一的调用
    Person p3 = Person_add(p1,p2);

    //方法二的调用
    Person p4 = p1.Person_ADD(p2);
}
*/
//############################################################
//重载加号运算符:
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Person
{
public:
    int age;
    Person(int age)
    {
        this->age = age;
    }
    Person operator+ (Person&p2)
    {
        Person p(this->age+p2.age);
        return p;
    }
};

//全局实现
//Person operator+ (Person &p1,Person &p2)
//{
//    Person p(p1.age+p2.age);
//    return p;
//}

void test1()
{
    Person p1(10);
    Person p2(20);

    //会去找 operator+ 的函数,有两种形式：operator+(p1,p2) 和 p1.operator(p2)
    //全局 和 成员函数 不能同时存在，否则会歧义报错。
    Person p3 = p1+p2;

    cout << p3.age << endl;
}

int main()
{
    test1();
    return 0;
}
*/
//###############################################
//运算符重载碰上友元函数,重载左移运算符
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class person
{
    //声明友元，使其能够访问私有成员age.
    friend ostream& operator<<(ostream &cout, person &p);
public:
    person(int age)
    {
        this->age = age;
    }
private:
    int age;
};

ostream& operator<<(ostream &cout, person &p) //cout的类型是：ostream
{
    //注意：如果age是私有的，则该函数输出不了age。因此需要加一个声明 友元。
    cout << p.age;
    //对于返回值的选择（void 还是 ostream& ?）,选择后者，因为要输出endl，即 <<endl;故返回不能为空，因为空不能输出endl,即不能使其 void << endl;
    //因此，返回值选择 ostream 类型的 cout。
    return cout;
}

void test01()
{
    person p1(10);
    cout << p1 <<endl;  //直接输出
    // operator<<(cout,p1) //cout.operator<<(p1)，但对于cout类的 类内重载不太现实，因此选择前者全局函数重载。
}
int main()
{
    test01();
    return 0;
}

*/
//############################################################
//重载自加运算符
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Myint
{
//    friend ostream & operator<<(ostream &cout, Myint &p);
public:
    Myint(int num)//this
    {
        this->num = num;
    }
    Myint& operator++()
    {
        this->num = this->num + 1;
        return *this;
    }
    Myint operator++(int)
    {
        Myint tmp = *this;
        //加加
        this->num = this->num + 1;
        return tmp;

    }
    int num;
};
//前置++，可以使用引用传参，后置++不能使用引用传参
//ostream & operator<<(ostream &cout, Myint &p)
//{
//    cout << p.num;
//    return cout;
//}
ostream & operator<<(ostream &cout, Myint p)
{
    cout << p.num;
    return cout;
}
void  test01()
{
    Myint p1(10);
    cout << p1 << endl;
    ++p1;//operator++(p1)  p1.operator++()
    cout << ++p1 << endl;
    cout << p1++ << endl;//p1.operator++(int)
}
int  main()
{
    test01();

    return 0;
}
*/
//且看另一个例子：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;	//设定名称空间，标准standard

//重载递增运算符
//自定义整型
class MyInte
{
    friend ostream& operator<<(ostream& cout, MyInte myint);
public:
    MyInte()
    {
        m_Num = 0;
    }

    //重载前置++运算符
    MyInte& operator++()
    {
        //先进行++运算
        m_Num++;
        //再将自身进行返回
        return *this;
    }
    //重载后置++运算符
    //void operator++(int)  int 代表占位参数，用以区分前置和后置++
    MyInte operator++(int)
    {
        //先 记录当时结果
        MyInte temp = *this;
        //后 递增
        m_Num++;
        //最后 将记录结果返回
        return temp;
    }
private:
    int m_Num;
};

//重载运算符<<
ostream& operator<<(ostream& cout, MyInte myint)
{
    cout << myint.m_Num;
    return cout;
}


void test01()
{
    MyInte myint;
    cout << ++myint << endl;
    cout << myint << endl;
}

void test02()
{
    MyInte myint;
    cout << myint++ << endl;
    cout << myint << endl;
}
int main()
{
    test01();
    test02();

    system("pause");

    return 0;
}

*/
//###############################################################
//智能指针:指针运算符（*、->）重载
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = age;
    }
    int age;

};

class Smartpoint
{
public:
    Smartpoint(Person *p1)
    {
        this->p = p1;
    }

    Person * operator->()
    {
        return p;
    }

    Person& operator* ()
    {
        return *p;
    }

    ~Smartpoint()
    {
        delete p;
        cout << "Smartpoint 释放 p" << endl;
    }

    Person *p ;
};

void test()
{
    //第一个问题：能否定义一个局部对象，在释放之前如果可以帮助我们释放p ————智能指针
    //已知对象在出作用域被释放的时候会调用析构函数，因此可以在析构函数里面释放该空间。

    Person *p = new Person(10);
    Smartpoint sp(p);

    //上面两行代码也可缩写为：
    Smartpoint ssp(new Person(100));

    cout << p->age <<endl;
    cout << sp->age <<endl; //第二个问题，能否使sp 返回 p:sp -> p  Person* sp.operator->(){return p;}
    cout << (*sp).age <<endl; //第三个问题，能否使*sp指向age  ： sp.operator*()
    //容易忘记释放 p指向的申请对象。
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//重载=运算符
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    {

    }
    Person(int age1,char *name1)
    {
        age = age1;

        //这样写避免了 name1指向的字符串可能被误释放了。
        name = new char[strlen(name)+1];
        strcpy(name,name1);
    }

//    Person & operator=(Person &p1) //this指针指向p2
//    {
//        //做了简单的值拷贝。
//        this->age = p1.age;
//        this->name = p1.name;

//        return *this; //返回值 返回的是p2,使其可以连续调用，如：P3 = p2 = p1;
//    }
    Person & operator=(Person &p1) //重写operator=函数
    {
        //做深拷贝
        this->age = p1.age;
        this->name = new char[strlen(p1.name)+1];
        strcpy(this->name,p1.name);

        return *this;
    }
    ~Person()
    {
        delete []name;
    }

    int age;
    char *name;
};

void test()
{
    Person p1(10,"Bob");
    Person p2;

    //这么写并没有调用构造函数（旧对象 赋值 旧对象）。如果是Person p2 = p1才是调用构造函数（旧对象 初始化 新对象）。
    p2 = p1;//这里之所以没有报错，是因为内置一个 operator= 函数,相当于 p2.operator(p1).
    cout << p2.age << " " << p2.name <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
// 重载 等于 和 不等于（== 、 ！=）
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Person
{
public:
    Person(int age1 ,string name1)
    {
        this->age = age1;
        this->name = name1;
    }

    bool operator==(Person p2)  //p1调用
    {
        return this->age == p2.age && this->name == p2.name;
    }

    bool operator!=(Person p2)  //p1调用
    {
        return this->age != p2.age || this->name != p2.name;
    }

    int age;
    string name;
};

void test()
{
    Person p1(10,"lilu");
    Person p2(10,"lili");
    if(p1 == p2)    //
    {
        cout << "p1 == p2" << endl;
    }
    if(p1 != p2)    //
    {
        cout << "p1 != p2" << endl;
    }
}
int main()
{
    test();
    return 0;
}
*/
//#########################################################
//（）重载，函数对象
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Myadd
{
public:
    int add(int a,int b)
    {
        return a+b;
    }
    int operator()(int x,int y)
    {
        return x+y;
    }
};

void test()
{
    //类 的 普通成员函数不能这么调用，只有静态的成员函数才会有函数，普通成员函数仅在对象创建后才会有。
    Myadd p;
    cout << p.add(3,4) << endl;

    //p() 可以像函数一样调用对象，称为函数对象。
    cout << p(3,4) << endl; //把对象当作函数来用。 p.operator() (3,4)

    cout << Myadd()(3,4) <<endl;//Myadd()(3,4)：Myadd(),类名+括号 表示 匿名对象，再调用operator()函数

}

int main()
{
    test();
    return 0;
}
*/
//########################################################
//不要重载&& 和 ||
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Complex{
public:
    Complex(int flag){
        this->flag = flag;
    }
    Complex& operator+=(Complex& complex){
        this->flag = this->flag + complex.flag;
        return *this;
    }
    bool operator&&(Complex& complex){
        return this->flag && complex.flag;
    }
public:
    int flag;
};
int main()
{
    Complex complex1(0); //flag 0
    Complex complex2(1); //flag 1

    //原来情况，应该从左往右运算，左边为假，则退出运算，结果为假
    //这边却是，先运算（complex1+complex2），导致，complex1的flag变为complex1+c
    //plex2的值， complex1.a = 1
    // 1 && 1
    //complex1.operator&&(complex1.operator+=(complex2))
    if (complex1 && (complex1 += complex2)){
         //complex1.operator+=(complex2)
         cout << "真!" << endl;
    }
    else{
        cout << "假!" << endl;
    }
    return EXIT_SUCCESS;
}
*/
//######################################################
//强化训练——字符串类封装
/*
//MyString.h:

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class MyString
{
    friend ostream& operator<< (ostream &out,MyString &str);
    friend istream& operator>> (istream &in ,MyString &str);
public:
    MyString(const char *);
    MyString(const MyString&);
    ~MyString();

    char& operator[] (int index);//[]重载

    //=重载
    MyString& operator= (const char *str);
    MyString& operator= (const MyString& str);

    //字符串拼接 +重载
    MyString operator+ (const char *str);
    MyString operator+ (const MyString& str);

    //字符串比较
    bool operator== (const char *str);
    bool operator== (const MyString& str);
private:
    char * pString;//指向堆区空间
    int m_Size;    //字符串长度 不算 ‘\0’
};


//MyString.cpp

#include "MyString.h"

//左移运算符
ostream& operator<< (ostream &out,MyString &str)
{
    out << str.pString;
    return out;
}

//右移运算符
istream& operator>> (istream &in,MyString &str)
{
    //先将原有的数据释放
    if(str.pString != NULL)
    {
        delete[] str.pString;
        str.pString = NULL;
    }

    char buf[1024]; //开辟临时的字符串数组，保存用户输入内容。
    in >> buf;

    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString,buf);
    str.m_Size = strlen(buf);

    return in;
}

//构造函数
MyString::MyString(const char * str)
{
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString,str);
    this->m_Size = strlen(str);
}

//拷贝构造
MyString::MyString(const MyString &str)
{
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString,str.pString);
    this->m_Size = str.m_Size;
}

//析构函数
MyString::~MyString()
{
    if(this->pString != NULL)
    {
        delete []this->pString;
        this->pString = NULL;
    }
}

char& MyString::operator[] (int index)  //返回str[index]的引用，便于更改这个值
{
    return this->pString[index];
}

MyString& MyString::operator= (const char * str)    //str = "hello";
{
    if(this->pString != NULL)
    {
        delete []this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str) +1];
    strcpy(this->pString,str);
    this->m_Size = strlen(str);
    return *this;
}

MyString& MyString::operator= (const MyString &str)
{
    if(this->pString != NULL)
    {
        delete []this->pString;
        this->pString = NULL;
    }
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString,str.pString);
    this->m_Size = str.m_Size;
    return *this;
}

MyString MyString::operator+ (const char *str)
{
    int newsize = this->m_Size + strlen(str) + 1;
    char *temp = new char[newsize]; //这里是new一个newsize大小的空间，返回的是char指针的变量
    memset(temp,0,newsize);         //将上面创建的空间对应的内容全部赋值为0；
    strcat(temp,this->pString);
    strcat(temp,str);

    MyString newstring(temp);       //这里是用char指针的变量 创建一个 对象。
    delete []temp;                  //把临时空间删去

    return newstring;               //返回新的对象。
}

MyString MyString::operator+ (const MyString &str)
{
    int newsize = this->m_Size + str.m_Size + 1;
    char *temp = new char[newsize];
    memset(temp,0,newsize);
    strcat(temp,this->pString);
    strcat(temp,str);

    MyString newstring(temp);       //这里是用char指针的变量 创建一个 对象。
    delete []temp;                  //把临时空间删去
    return newstring;
}

bool MyString::operator== (const char *str)
{
    if(strcmp(this->pString,str) == 0 && strlen(str) == this->m_Size)
    {
        return true;
    }

    return false;
}

bool MyString::operator== (const MyString &str)
{
    if(strcmp(this->pString,str.pString) == 0 && str.m_Size == this->m_Size)
    {
        return true;
    }

    return false;
}

//TestMyString.cpp

void test()
{
    MyString str("hello world");

    cout << str << endl;

    //cout << "请输入MyString 类型字符串" << endl;
    //cin >> str;

    //cout << "字符串为：" << str <<endl;

    //测试[]
    cout << "MyString 的第一个字符为：" << str[0] << endl;

    //测试=
    MyString str2 = "^_^";
    MyString str3 = "";
    str3 = "aaa";
    str3 = str2;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;

    //测试+
    MyString str4 = "我爱";
    MyString str5 = "北京";
    MyString str6 = str4 + str5;
    MyString str7 = str6 + "天安门";

    cout << str7 <<endl;

    //测试==
    if(str6 == str7)
    {
        cout << "s6 与 s7相等" << endl;
    }
    else
    {
        cout << "s6 与 s7不等" << endl;
    }
}
*/
//##############################################################
//继承：派生类的定义
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//基类
class Animal
{
public:
    int age;
    void print()
    {
        cout << age <<endl;
    }
};

//继承方式：
//public：不管父类什么权限，到子类，全变成公有。
//private:
class Dog:public Animal
{
public:
    int tail_len;

    //继承，相当于拷贝过来
//    int age;
//    void print()
//    {
//        cout << age <<endl;
//    }
};

void test()
{
    Dog d;
    //d有三个成员:
//    d.age;
//    d.tail_len;
//    d.print();
}
int main()
{

    return 0;
}
*/
//##############################################################
//派生类访问控制
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Base
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

//公有继承方式：基类中是什么权限，继承到 子类中，也是什么权限。
class A:public Base
{
    //公有继承 就是 拷贝
public:
    int d;
    void show()
    {
        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
//        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
        //由此，子类不能访问父类的私有成员。
    }
//    int a;
//protected:
//    int b;
//private:
//    int c;

};


//保护继承：把公有变成保护的，其它不变
class B:protected Base
{
public:
    int d;
    void show()
    {
        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
//        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
    }

//protected:
//    int a;
//protected:
//    int b;
//private:
//    int c;

};

class C:private Base
{

public:
    int d;
    void show()
    {
        //子类的成员函数 访问父类的成员：要看父类继承之前的权限
//        cout << a << b << c << d <<endl;  //仅c（父类私有权限）不能访问
    }

    //私有继承：将父类的成员权限都变成私有的
//private:
//    int a;
//private:
//    int b;
//private:
//    int c;
};

void test()
{
    //公有测试：
    A e;
//    A.a;
//    A.d;

    //保护测试：
    B f;
//    f.d;

    //私有测试：
    C g;
//    g.d


}
int main()
{

    return 0;
}
*/
//########################################################
//继承中的对象模型
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class A
{
public:
    int a;
    int b;
};

class B:public A
{
public:
    int c;
};

class C:public B
{
public:
    int d;
};

void test()
{
    //类似于结构体
    cout << "A size" <<sizeof(A) <<endl;    //8
    cout << "A size" <<sizeof(B) <<endl;    //12
    cout << "A size" <<sizeof(C) <<endl;    //16
}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//对象构造和析构的调用原则
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Base
{
public:
    Base(int age1,string name1)
    {
        this->age = age1;
        this->name = name1;

        cout << "Base,父类的构造函数" << endl;
    }

    ~Base()
    {
        cout << "Base 父类的析构函数" << endl;
    }
    int age;
    string name;
};

//创建子类对象的时候，必须先构建父类对象，需要先调用父类的构造函数。
class Son:public Base
{
public:
    //子类的构造函数：有参构造，创建三个参数。在调用子类的构造函数之前，需要先去调用父类的构造函数，就需要把参数传进去，传参方式如下：
    Son(int id,int age,string name):Base(age,name)
    {
        this->id = id;
        cout << "Son 子类构造函数" << endl;
    }
    ~Son()
    {
        cout << "Son 子类的析构函数" << endl;
    }
    int id;
};

void test()
{
    Son p(12,20,"Bob");
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//继承中
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Base
{
public:
    Base(int a)
    {
        this->a = a;
    }

    void foo()
    {
        cout << "父类的foo函数" << endl;
    }
    int a;
};

class Son:public Base
{
public:
    Son(int a1,int a2):Base(a1)
    {
        this->a = a2;
    }

    void foo()
    {
        cout << "子类的foo函数" << endl;
    }
    int a;
};

void test()
{
    Son p(10,20);
    //如果子类和 父类有重名的成员变量，父类的成员变量会被隐藏。访问的是子类的成员变量。
    //如果子类和 父类有重名的成员变量，父类的成员函数会被隐藏。访问的是子类的成员函数。
    cout << p.a <<endl;//20 ,访问到的是子类的成员。
    p.foo();
}

int main()
{
    test();
    return 0;
}
*/
//##########################################################
//静态成员 在 继承中的特点：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Base
{
public:
    static int getNum()
    {
        return sNum;
    }
    static int getNum(int param)
    {
        return sNum + param;
    }
public:
    static int sNum;
};
int Base::sNum = 10;

class Derived : public Base
{
public:
    static int sNum; //基类静态成员属性将被隐藏
#if 0
    //重定义一个函数，基类中重载的函数被隐藏
    static int getNum(int param1,int param2)
    {
        return sNum + param1 + param2;
    }
#else
    //改变基类函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数
    //父类有两个静态成员函数，子类有一个，
    static void getNum(int param1,int param2)
    {
        cout << sNum + param1 + param2 << endl;
    }
#endif
};
int Derived::sNum = 20;

void test()
{
    Derived p1;
    cout << p1.sNum <<endl;//20,
    //因此，当子类和父类有同名的静态成员变量，父类的静态成员变量会被隐藏，调用的是子类的静态成员变量。

//    p1.getNum();     //不传参数，调用不了，因此，不能调用父类的无参静态成员函数。
//    p1.getNum(10);   //传一个参数，也调用不了，因此，不能调用父类的静态成员函数。
    p1.getNum(10,20);  //传两个参数的才可以调用，因此，只能调用子类的静态成员函数。
//如果子类和父类有同名的静态成员函数，父类中的静态成员函数 都 会被隐藏，

}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//多继承
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class A
{
public:
    int a;
};

class B
{
public:
    int a;
    int b;
};

class C:public A,public B
{
public:
    int c;
};

void test()
{
    C p;
    p.A::a = 10;
    p.B::a = 20;
    p.b = 20;
    p.c = 30;
}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//菱形继承 以及 其存在的问题：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:
    int age;

};

class sheep:virtual public Animal
{
public:
    int id;
};

class cow:virtual public Animal
{
public:
    int num;
};

class Shenshou:public sheep,public cow
{
public:
    int a;
};

void test()
{
    Shenshou p;
    //实际上，我们仅希望Shenshou只继承一个age,
    //实现方法：使用虚继承关键字：virtual
//    p.sheep::age = 100;
//    p.cow::age = 200;

    //虚继承
    p.age = 100;

}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//虚继承的实现原理
//我们需要知道：每个类在内存中是如何存储的，以及加上 virtual关键字后，虚继承的类是如何在内存中存储的。
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:
    int age;

};

class Sheep:virtual public Animal
{
public:
    int id;
};

class Cow:virtual public Animal
{
public:
    int num;
};

class Shenshou:public Sheep,public Cow
{
public:
    int a;
};

void test()
{
    Shenshou p;
    //实际上，我们仅希望Shenshou只继承一个age,
    //实现方法：使用虚继承关键字：virtual
//    p.sheep::age = 100;
//    p.cow::age = 200;

    //虚继承
    p.age = 100;

}

int main()
{
    test();
    return 0;
}

//在开始菜单里的 vs的开发人员命令提示符 下写如下命令:
//若找不到，可打开vscode,再在 工具->命令行->开发者命令提示，再写入如下代码：
//注意，如果涉及盘符的切换，需要加 /d,如： cd /d D:\Qtproject\5_2_cplusplus_lei

//cd D:\Qtproject\5_2_cplusplus_lei
//dir
//cl /d1 reportSingleClassLayoutAnimal main.cpp    //这里指令表示：report Single Class Layout Animal,报告单个类的布局+Animal  在main.cpp文件当中，注意，要编译之后，才会生成Animal的布局。

//动物类的布局：
//class Animal    size(4):
//        +---
// 0      | age
//        +---

//分析：Animal只有4个字节 int类型的 age

//羊类的布局：
//class Sheep     size(12):
//        +---
// 0      | {vbptr}
// 4      | id
//        +---
//        +--- (virtual base Animal)
// 8      | age
//        +---

//Sheep::$vbtable@:
// 0      | 0
// 1      | 8 (Sheepd(Sheep+0)Animal)

//由于继承是虚继承，里面有三个东西：羊继承的age，一个id,此外，里面还有一个vbptr(virtual base ptr 虚基类ptr指针，指针占4个字节，虚基类指针 会指向一张表（虚基类表（vbtable））,虚基类指针开始是不会被初始化的，但当我们调用这个类的构造函数的时候，他会创建一张表，并且把表的地址给到vbptr指针)。
//由（Sheep::$vbtable@:）可知，表里有两个成员，一个是0，一个是8，这里8是指age的偏移量。也就是说，他在虚继承的时候，a虽然继承过来了，但，去访问age的时候并不是直接得到age，而是通过指针得到age的偏移量，然后再访问到age。

//也就是说当定义了 sheep p;
//再去访问(p.age)时，编译器做了许多事情: *（int *）((char*)&p+ *((int *)(*（int *）&p) + 1)) //*(int*)(p的地址+偏移量8)

//即，过程为：首先要找到vbptr指针，即：首先由p的地址(32位编译器)转成(int*)再取*：*（int*）&p   => 这个就是vbptr这个值，注意不是指针，其指向虚基类表。
//我们对这个值的地址转成int *,再加1，即从原来的指向0，变成指向8，再将这个8取出来（解引用*）,至此得到偏移量8: *((int *)((int *)&p) + 1）
//为了得到age的地址，需要在p的地址上加上偏移量： ((char*)&p + *((int *)(*（int *）&p) + 1))
//对得到的地址转成(int *),再解引用,得到age的值： *（int *）((char*)&p + *((int *)(*（int *）&p) + 1))


//牛类的布局：
//class Cow       size(12):
//        +---
// 0      | {vbptr}
// 4      | num
//        +---
//        +--- (virtual base Animal)
// 8      | age
//        +---

//Cow::$vbtable@:
// 0      | 0
// 1      | 8 (Cowd(Cow+0)Animal)


//神兽的布局：
//class Shenshou  size(24):
//        +---
// 0      | +--- (base class Sheep)
// 0      | | {vbptr}
// 4      | | id
//        | +---
// 8      | +--- (base class Cow)
// 8      | | {vbptr}
//12      | | num
//        | +---
//16      | a
//        +---
//        +--- (virtual base Animal)
//20      | age
//        +---

//Shenshou::$vbtable@Sheep@:
// 0      | 0
// 1      | 20 (Shenshoud(Sheep+0)Animal)

//Shenshou::$vbtable@Cow@:
// 0      | 0
// 1      | 12 (Shenshoud(Cow+0)Animal)
//vbi:       class  offset o.vbptr  o.vbte fVtorDisp
//          Animal      20       0       4 0

//**对于神兽有4个成员：继承了sheep的虚基类表和id、继承了cow的虚基类表和num、自己的a 和 只继承了一份的age。
//而这里,在sheep的虚基类表里：age的偏移量是20；在cow的虚基类表里：age的偏移量是12。**



//**vs的开发人员命令提示符窗口内容：**

//D:\Qtproject\5_2_cplusplus_lei>dir
// 驱动器 D 中的卷是 Data
// 卷的序列号是 4D3B-BBAE

// D:\Qtproject\5_2_cplusplus_lei 的目录

//2024/12/20  22:52    <DIR>          .
//2024/12/18  11:55    <DIR>          ..
//2024/12/07  00:18               133 5_2_cplusplus_lei.pro
//2024/12/20  01:28            19,159 5_2_cplusplus_lei.pro.user
//2024/12/07  00:32               732 c_person.c
//2024/12/20  22:52           197,990 main.cpp
//2024/12/20  22:52            76,800 main.exe
//2024/12/20  22:52             2,146 main.obj
//               6 个文件        296,960 字节
//               2 个目录 199,913,979,904 可用字节

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Animal    size(4):
//        +---
// 0      | age
//        +---
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutSheep m
//ain.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Sheep     size(12):
//        +---
// 0      | {vbptr}
// 4      | id
//        +---
//        +--- (virtual base Animal)
// 8      | age
//        +---

//Sheep::$vbtable@:
// 0      | 0
// 1      | 8 (Sheepd(Sheep+0)Animal)
//vbi:       class  offset o.vbptr  o.vbte fVtorDisp
//          Animal       8       0       4 0
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCow main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Cow       size(12):
//        +---
// 0      | {vbptr}
// 4      | num
//        +---
//        +--- (virtual base Animal)
// 8      | age
//        +---

//Cow::$vbtable@:
// 0      | 0
// 1      | 8 (Cowd(Cow+0)Animal)
//vbi:       class  offset o.vbptr  o.vbte fVtorDisp
//          Animal       8       0       4 0
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutShenshou main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Shenshou  size(24):
//        +---
// 0      | +--- (base class Sheep)
// 0      | | {vbptr}
// 4      | | id
//        | +---
// 8      | +--- (base class Cow)
// 8      | | {vbptr}
//12      | | num
//        | +---
//16      | a
//        +---
//        +--- (virtual base Animal)
//20      | age
//        +---

//Shenshou::$vbtable@Sheep@:
// 0      | 0
// 1      | 20 (Shenshoud(Sheep+0)Animal)

//Shenshou::$vbtable@Cow@:
// 0      | 0
// 1      | 12 (Shenshoud(Cow+0)Animal)
//vbi:       class  offset o.vbptr  o.vbte fVtorDisp
//          Animal      20       0       4 0
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>

*/
//####################################################################
//多态的实现
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:

//    void speak()
//    {
//        cout << "动物在说话！" << endl;
//    }

    //6.如果不是上面这种，而是像下面这种，加了virtual关键字的虚函数。
    //7.首先，有虚函数，其次，Dog又继承了这个基类，并且，子类中又重写了这个虚函数。  （重写：函数返回值 函数名 参数值 一致，就叫重写）

    virtual void speak()
    {
        cout << "动物在说话！" << endl;
    }

};

//2.但 如果两个类发生了继承，父类和子类，可以自动转换。
//3.此时 可以用do_work()来调用p2的speak
class Dog:public Animal
{
public:
    void speak()
    {
        cout << "狗在说话！" << endl;
    }

};

//1.这种没有继承的方式，不能用do_work()来调用p2的speak（）。
//class Dog
//{
//public:
//    void speak()
//    {
//        cout << "狗在说话！" << endl;
//    }

//};

//11.再增一个cat类，并继承Animal.
class Cat:public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }

};

//8.最后，用父类的指针 指向 子类的对象，这个时候，打印的就是 "狗在说话"
void do_work(Animal &obj)
{
    obj.speak();  //5.这里就是地址早绑定，//9.在继承了虚函数之后，就是地址晚绑定。
    //10.即：地址早绑定 -> 在基类的函数前面加上virtual关键字 -> 地址晚绑定。
}

//12.在这个程序中，test函数就是接口，一个接口，可以实现多种形态。
void test()
{
    Animal p1;
    do_work(p1);

    Dog p2;
    //4.但注意，这里打印的还是"动物在说话",因为这个地址 早绑定了。在编译器编译的时期就已经绑定了。
    do_work(p2);

    Cat p3;
    do_work(p3);
}
int main()
{
    test();
    return 0;
}
*/
//###################################################################
//多态实现计算器的案例
/*
//没有多态的实现方法：
//但问题是，如果又新增一个乘法，则需要重写改写该类的函数体。
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <string>
//using namespace std;

//开发时，对源码的开发是关闭的，对扩展是开放的。

//class Myclc
//{
//public:
//    int calc(int a,int b,string cmd)
//    {
//        if(cmd == "+")  //string 类型里面重载着一个operator== 函数，所以可以直接比较
//        {
//            return a + b;
//        }
//        else if(cmd == "-")
//        {
//            return a - b;
//        }
//#if 1
//        else if(cmd == "*")
//        {
//            return a * b;
//        }
//#endif  //但问题是，如果又新增一个乘法，则需要重写改写该类的函数体。
//    }
//};

//void test()
//{
//    Myclc p;
//    cout << p.calc(3,4,"+") << endl;
//}

//int main()
//{
//    test();
//    return 0;
//}



//有多态后的实现方法：

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Calc
{
public:
    virtual int Mycalc(int a,int b)
    {
        return 0;
    }

};

class Add:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a + b;
    }
};

class Reduce:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a - b;
    }
};

class Multi:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a * b;
    }
};

int do_work(int a,int b,Calc &p)
{
//    cout << p.Mycalc(a,b) << endl;
    return p.Mycalc(a,b);
}

void test()
{
    Add p1;
    cout << do_work(6,4,p1) << endl;

    Reduce p2;
    cout << do_work(6,2,p2) << endl;

    Multi p3;
    cout << do_work(3,5,p3) << endl;;

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
*/
//#######################################################################
//c++如何实现动态绑定，
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话！" << endl;
    }

};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "狗在说话！" << endl;
    }

};

class Cat:public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }

};

void do_work(Animal &obj)
{
    obj.speak();
}

void test()
{
    Animal p1;
    do_work(p1);

    Dog p2;
    do_work(p2);

    Cat p3;
    do_work(p3);
}
int main()
{
    test();
    return 0;
}

//这里再次使用到vscode,详细操作步骤见前面 虚继承的实现原理.

//D:\c++代码\angle\Myadd_self>cd D:\Qtproject\5_2_cplusplus_lei

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Animal    size(4):
//        +---
// 0      | {vfptr}
//        +---

//Animal::$vftable@:
//        | &Animal_meta
//        |  0
// 0      | &Animal::speak

//Animal::speak this adjustor: 0
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
//main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutDog main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class Dog       size(4):
//        +---
// 0      | +--- (base class Animal)
// 0      | | {vfptr}
//        | +---
//        +---

//Dog::$vftable@:
//        | &Dog_meta
//        |  0
// 0      | &Dog::speak

//Dog::speak this adjustor: 0
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
//main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCat main.cpp
//用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.33.31630 版
//版权所有(C) Microsoft Corporation。保留所有权利。

//main.cpp

//class _s__CatchableType size(28):
//        +---
// 0      | properties
// 4      | pType
// 8      | _PMD thisDisplacement
//20      | sizeOrOffset
//24      | copyFunction
//        +---

//class _s__CatchableTypeArray    size(4):
//        +---
// 0      | nCatchableTypes
// 4      | arrayOfCatchableTypes
//        +---

//class Cat       size(4):
//        +---
// 0      | +--- (base class Animal)
// 0      | | {vfptr}
//        | +---
//        +---

//Cat::$vftable@:
//        | &Cat_meta
//        |  0
// 0      | &Cat::speak

//Cat::speak this adjustor: 0
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
//main.cpp(7609): note: 查看对正在编译的函数 模板 实例化“std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)”的引用
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>


//分析：

//1.当定义一个Dog类的对象的时候，会先构造父类的对象，即：先构造Animal的对象，由于本例中，Animal没有成员变量，只有虚函数，所以多了vfptr(虚函数指针)，该指针指向虚函数表（vftable）。当构造子类的对象的时候，因为会调用构造函数，在调用构造函数时他会 把虚函数的函数入口地址 放到虚函数表（vftable）
//2.因此，此时这个虚函数 就指向 父类的这个 speak函数。
//Animal 的布局：
//class Animal    size(4):
//        +---
// 0      | {vfptr}
//        +---

//Animal::$vftable@:
//        | &Animal_meta
//        |  0
// 0      | &Animal::speak


//3.然后开始构造子类。由于构造子类的时候 继承了 虚函数指针（vfptr）以及虚函数表（vftable）,此时他调用子类的构造函数时，子类的构造函数里面 会去做：1.会重写虚函数，2.把这个子类的这个dog speak函数的函数指针放进继承的 虚数表（vftable)里面，即，把vfptr指针的值替换。
//4.因此，重写实际上就是替换掉 vftable里面的函数的地址。
//5.此时再去调 p.sprak的时候，它里面实际调用的是vfptr指向的这个vftable里面的函数。而该函数在 创建子类的构造函数的时候就已经更改了。

//Dog 的布局：
//class Dog       size(4):
//        +---
// 0      | +--- (base class Animal)
// 0      | | {vfptr}
//        | +---
//        +---

//Dog::$vftable@:
//        | &Dog_meta
//        |  0
// 0      | &Dog::speak



//cat 的布局：
//class _s__CatchableType size(28):
//        +---
// 0      | properties
// 4      | pType
// 8      | _PMD thisDisplacement
//20      | sizeOrOffset
//24      | copyFunction
//        +---

//class _s__CatchableTypeArray    size(4):
//        +---
// 0      | nCatchableTypes
// 4      | arrayOfCatchableTypes
//        +---

//class Cat       size(4):
//        +---
// 0      | +--- (base class Animal)
// 0      | | {vfptr}
//        | +---
//        +---

//Cat::$vftable@:
//        | &Cat_meta
//        |  0
// 0      | &Cat::speak
*/
//#################################################################
//纯虚函数 和 抽象类
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Calc
{
public:
    //1.在之前的计算器类的基础上，在后面加 = 0；使其变成 纯虚函数（ 虚函数 = 0 ）
    //2.纯虚函数作用： 已知在构造父类的时候，vfptr指向了vftable,而vftable里面放了一个 父类的函数的地址，但如果写成纯虚函数的话，代表把这个函数地址赋值为NULL。
    //3.virtual int Mycalc(int a,int b) = 0;这句话赋值为0，代表将vfptr虚函数指针 指向的 虚函数表 里面的 函数入口地址 赋值为NULL。之后子类再去重写时，会把那个虚函数表里面的函数重写更改。

    //4.把 含有纯虚函数的类 称作 抽象类,抽象类不能实例化对象。
    //5.如果子类 继承了 抽象类，则 子类 也是 抽象类
    //6.但如果 继承了 抽象类 的 子类 重写了虚函数。就不再是抽象类。
    virtual int Mycalc(int a,int b) = 0;

//    {
//        return 0;
//    }

};
class Mod:public Calc
{
//    Calc a;//报错，抽象类不能实例化
//    Mod a;//继承了抽象类的子类也是抽象类，不能实例化。

};

void test1()
{

}

class Add:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a + b;
    }
};

class Reduce:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a - b;
    }
};

class Multi:public Calc
{
public:
    int Mycalc(int a,int b)
    {
        return a * b;
    }
};

int do_work(int a,int b,Calc &p)
{
//    cout << p.Mycalc(a,b) << endl;
    return p.Mycalc(a,b);
}

void test()
{
    Add p1;
    cout << do_work(6,4,p1) << endl;

    Reduce p2;
    cout << do_work(6,2,p2) << endl;

    Multi p3;
    cout << do_work(3,5,p3) << endl;;

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
*/
//###################################################################
//虚析构函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }

    virtual ~Animal()
    {
        cout << "动物 析构" << endl;
    }
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "狗在说话" << endl;
    }
    ~Dog()
    {
        cout << "狗 析构" << endl;
    }
};

void dp_work(Animal &obj)
{
    obj.speak();
}

void test()
{
    Animal *p = new Dog;

    p->speak(); //1.因为引用的是dog的对象，所以 打印 狗在说。
    delete p;   //2.因为是父类的指针      所以 析构 是动物析构，所以释放的是基类,子类的对象没有被释放。
    //3.在之前，创建子类对象时；先创父类，再创子类。析构是：先析构子类，再析构父类；但这里由于指针是Animal指针，所以先释放的是父类。
    //4.那么，能不能让其在释放父类之前，先释放子类？ => 只需要在父类的析构函数前面加关键字virtual ,这就是虚析构。
    //虚析构的作用：在调用父类的析构函数之前，会先调用子类的析构函数。
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//纯虚析构函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }

//    virtual ~Animal()   //虚析构
//    {
//        cout << "动物 析构" << endl;
//    }

    //纯虚析构函数就是：没有实现的函数体。
    virtual ~Animal() = 0;
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "狗在说话" << endl;
    }
    ~Dog()
    {
        cout << "狗 析构" << endl;
    }
};

void dp_work(Animal &obj)
{
    obj.speak();
}

void test()
{
    Animal *p = new Dog;

    p->speak();
    delete p;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//重写 重载 重定义
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

#if 0
//交换int型数据
void swap(int & x,int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
//交换char型数据
void swap(char & x,char &y)
{
    char tmp = x;
    x = y;
    y = tmp;
}

void test()
{
    int a = 1;
    int b = 2;
    swap(a,b);
    cout << a <<" " <<b << endl;
}
#endif

//函数模板来实现
template<class T> //定义一个通用模板，模板的通用类型为T。 class 和 typename都是一样的，用哪个都可以。
//下面紧跟函数的定义
void swap_temp(T &a,T&b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

void test1()
{
    char a = 1;
    char b = 2;
    int c = 3;
    int d = 4;
    swap_temp(a,b);//自动类型推导，
//    swap_temp(a,c);//推导类型不一致会出错。
    swap_temp(c,d);
    cout << a <<" " <<b << endl;
    cout << c <<" " <<d << endl;
}

int main()
{
    test1();
    return 0;
}
*/
//########################################################
//用模板实现数组排序
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//函数模板 用于排序
template<class T>
void array_sort(T *p,int n)//传数组首元素地址和数组个数
{
    for(int i = 0;i < n-1;i++)
    {
        for(int j = i+1; j <n ;j++)
        {
            if(p[i]>p[j])
            {
                T temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

template <class T>
void print_array(T *p,int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void test()
{
    int a[10] = {12,55,44,63,84,9,22,11,3,77};
    array_sort(a,sizeof(a)/sizeof(a[0]));
    print_array(a,sizeof(a)/sizeof(a[0]));
}

void test1()
{
    double a[10] = {12.1,1.8,3.2,4.5,7.4,6.3,4.2,9.9,7.6,5.3};
//    array_sort(a,sizeof(a)/sizeof(a[0]));        //自动类型推导
    array_sort<double>(a,sizeof(a)/sizeof(a[0]));  //显示指定类型
    print_array(a,sizeof(a)/sizeof(a[0]));
}
int main()
{
    test1();
    return 0;
}

*/
//###########################################################
//函数模板 和 普通函数区别
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//普通函数
int My_Add(int a,int b)
{
    cout<<"普通函数" <<endl;
    return a + b;
}

//模板
template <class T>
T My_Add(T a,T b)
{
    cout<<"模板函数" <<endl;
    return a + b;
}

void test()
{

}


int main()
{

    int a = 10;
    char b = 20;
    My_Add(a,a);     //直接调用普通函数，不用推导，如果还是想用模板函数，则加 <>,
    My_Add<int>(a,a);//显示指定类型
    My_Add<>(a,a);   //指定自动推导
    My_Add(b,b);     //普通函数类型不匹配，自动调用模板函数

    My_Add(a,b);     //这种类型不相同的，调用的是普通函数，可以实现自动类型转换。char转为int。但如果用模板则会报错
//    My_Add<>(a,b);     //如果用模板则会报错,因为自动推导出的两个类型不一致，函数模板不会做自动类型转换。
    return 0;
}
*/
//###################################################################
//函数模板 和 普通函数在一起调用规则
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//函数模板
template<class T>
T Myplus(T a,T b)
{
    cout << "函数模板" << endl;
    return a + b;
}

//普通函数
int Myplus(int a,int b)
{
    cout << "普通函数" << endl;
    return a + b;
}

//重载函数模板
template <class T>
T Myplus(T a, T b,T c)
{
    cout << "模板函数" << endl;
    return a + b + c;
}

void test()
{
    int a = 10;
    int b = 20;
    char c = 'a';
    char d = 'b';
    //如果函数模板和普通函数都能匹配，c++编译器优先考虑普通函数
    cout << Myplus(a,b) << endl;
    //如果要求必须调用模板，则加<>
    cout << Myplus<>(a,b) << endl;
    //此时普通函数也可以匹配，因为普通函数可以自动类型转换
    //但是此时函数模板能够有更好的匹配
    //如果函数模板可以产生一个更好的匹配，那么选择模板(两个类型都是char，如果是调用普通函数就需要转两次类型，因此匹配模板更好)
    cout << Myplus(c,d) << endl;

}
int main()
{
    test();
    return 0;
}
*/
//#####################################################
//函数模板本质：以 函数模板 和 普通函数区别 的代码为例
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//普通函数
int My_Add(int a,int b)
{
    cout<<"普通函数" <<endl;
    return a + b;
}

//模板
template <class T>
T My_Add(T a,T b)
{
    cout<<"模板函数" <<endl;
    return a + b;
}
//1.第一次编译，对函数模板语法进行编译（编译器从上往下走，走到这里时，对语法进行编译）
//3.展开后的代码如下：注意，展开后也没有template <class T>了。
//int My_Add(int a,int b)
//{
//    cout<<"模板函数" <<endl;
//    return a + b;
//}
//4.如果再一个char类型大的调用，则展开为：展开之后，也要进行第二次编译，
//char My_Add(char a,char b)
//{
//    cout<<"模板函数" <<endl;
//    return a + b;
//}
//5.由上面两个可知，函数模板 的本质就是函数重载。进行了二次编译。

void test()
{
    int a = 10;
    char b = 20;
    My_Add(a,a);        //2.由于a是int类型，在调用的时候，他会对这个模板进行展开（因为编译器推导出a是int类型，则展开时，用int替换T），
    My_Add<int>(a,a);
    My_Add<>(a,a);
    My_Add(b,b);

    My_Add(a,b);
//    My_Add<>(a,b);

}


int main()
{
    test();
    return 0;
}
*/
//####################################################
//模板的局限性：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//1.第一种方法：若是自定义类型的数据类型（但如果是数组结构体是不行的），但如果是自定义数据类型，就可以去修改这个类，修改里面的operator重载函数，从而实现所需功能，
//2.如T是Person,里面有name和age。进行比较和赋值。
//3.对于该自定义的数据类型，那么它是调用operator=函数，或者比较>号，则，去这个类里面去重写一个operator>这样的运算符重载函数 进行重载。
//4.此时就需要自己进行实现函数体。
class Person
{
public:
    Person(string name,int age)
    {
        this -> mName = name;
        this ->mAge = age;
    }
    string mName;
    int mAge;
};

//普通交换函数
//5.例如对于这个交换函数，如果传的Person类型，可能是交换不了的，
//6.除了写operator重载函数外，还可以把函数具体化，
template<class T>
void mySwap(T &a,T &b)
{
    T tmp = a;
    a = b;//这里调用的是operator=函数。
    b = tmp;
}


//第三代具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
//7.例如下面这种，就是具体化。前面加template<> 然后把所有T，换成自定义数据类型。
//8.但函数具体化很少用，因为很麻烦需要注意的地方很多，不如去写一个全局函数进行赋值，或者写一个类内的函数进行赋值。
template<> void mySwap(Person &p1,Person &p2)
{
    string nameTemp;
    int ageTemp;

    nameTemp = p1.mName;
    p1.mName = p2.mName;
    p2.mName = nameTemp;

    ageTemp = p1.mAge;
    p1.mAge = p2.mAge;
    p2.mAge = ageTemp;
}

void test()
{
    Person p1("Tom",10);
    Person p2("Jerry",20);

    cout << "P1 Name = " << p1.mName << "P1 Age = " << p1.mAge <<endl;
    cout << "P2 Name = " << p2.mName << "P2 Age = " << p2.mAge <<endl;
    mySwap(p1,p2);
    cout << "P1 Name = " << p1.mName << "P1 Age = " << p1.mAge <<endl;
    cout << "P2 Name = " << p2.mName << "P2 Age = " << p2.mAge <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//类模板
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//class Animal
//{
//public:
//    int age;
//    int data;
//};

//class Animal_1
//{
//public:
//    int age;
//    string data;
//};

//通用类模板：
template<class T1, class T2>
class Animal
{
public:
    Animal(T1 a,T2 b)
    {
        age = a;
        data = b;
    }
    T1 age;
    T2 data;
};
void test()
{
    Animal dog(10,10);
    Animal<int,int> dog2(10,10);  //注意:类模板不能自动类型推导，因此要显示指定类型。（但我的QT可以进行自动的类型转换，最好还是显示指定）
    cout << dog.age << " " << dog.data << endl;

    Animal cat(4,"lisa");
    Animal<int,string> cat2(4,"lisa");
    cout << cat.age << " " << cat.data << endl;
}

int main()
{
    test();
    return 0;
}
*/
//###########################################################
//类模板作为函数参数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//通用类模板：
template<class T1, class T2>
class Animal
{
public:
    Animal(T1 a,T2 b)
    {
        age = a;
        data = b;
    }
    T1 age;
    T2 data;
};

//1.作为形参，参数为：类模板类型。所以为Animal<int,int>
//2.但问题是：形参的类型为<int,int>,故不能传cat，<int,string>类型。
//3.因此，当函数的形参作为类模板的时候，尽量将函数写成函数模板的形式。
//写法一：
//template<class T1,class T2>
//void show(Animal<T1,T2> &p)
//{
//    cout << p.age <<" "<<p.data <<endl;
//}
//写法二：
template<class T1>
void show(T1 &p)    //以Animal<int,int> dog2(10,10);调用为例：相当于把整个<int,int>类型，传给了T1。所以
{
    cout << p.age <<" "<<p.data <<endl;
}

void test()
{
    Animal dog(10,10);
    Animal<int,int> dog2(10,10);  //注意:类模板不能自动类型推导，因此要显示指定类型。（但我的QT可以进行自动的类型转换，最好还是显示指定）
    cout << dog.age << " " << dog.data << endl;
    show(dog);

    Animal cat(4,"lisa");
    Animal<int,string> cat2(4,"lisa");
    cout << cat.age << " " << cat.data << endl;
    show(cat);
}

int main()
{
    test();
    return 0;
}
*/
//#########################################################
//子类继承了类模板时，子类怎么写？
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T>
class Base
{
public:
    Base(T a)
    {
        this->a = a;
    }
    T a;
};

//写法一：
//2.但问题是这里T写死为int类型了。
class Son:public Base<int>
{
public:
    //1.用初始化列表构造构造函数：首先构造基类Base<int>,并把a传进去。再x赋值为x1
    Son(int x1, int a):Base<int>(a),x(x1){}
    int x;
};

//写法二：
template<class T1,class T2>
class Son2:public Base<T2>
{
public:
    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}

    T1 x;
};

void test()
{
    //3.因此这里只能写<int,int>类型.
    Son p(10,20);
    Son2<int,string>(30,"lisa");
}
int main()
{
    test();
    return 0;
}
*/
//#########################################################
//类模板成员函数的类内实现
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

template <class NameType,class AgeType>
class Person
{
public:
    //成员函数类内实现：
    Person(NameType name,AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name：" << this->mName << "age: " << this->mAge << endl;
    }
    NameType mName;
    AgeType mAge;
};
void test()
{
    //Person P1("德玛西亚"，18);//类模板不能进行类型自动推导
    Person<string,int>p1("德玛西亚",18);
    p1.showPerson();
}
int main()
{
    test();
    return 0;
}
*/
//#########################################################
//类模板成员函数的类外实现
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T1,class T2>
class Person
{
public:
    //成员函数类外实现：
    Person(T1 a,T2 b);
    void showPerson();

    T1 a;
    T2 b;
};
//1.类模板的成员函数在类外实现，需要写成函数模板形式。
//2.又由于Person是模板类，故，不能写为：Person::Person(T1 a,T2 b),而是写成：Person<T1,T2>::Person(T1 a,T2 b)
template<class T1,class T2>
Person<T1,T2>::Person(T1 a,T2 b)
{
    this->a = a;
    this->b = b;
}

template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout << this->a << " " << this->b << endl;
}

void test()
{
    Person<int,string>p(10,"lisa");
    p.showPerson();
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
//类模板的成员函数创建时机。
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class A
{
public:
  void showA() { cout << "showA" << endl ;}

};

class B
{
public:
  void showB() { cout << "showB" << endl ;}
};

//一、类内实现：
//template<class T>
//class C
//{
//public:

//    void foo1()
//    {
//        obj.showA();
//    }
//    void foo2()
//    {
//        obj.showB();
//    }

//    T obj;//定义一个T类型的obj变量/对象，可以传A/B对象。
//};

//二、相当于类内只有声明。此时也能成功，
template<class T>
class C
{
public:

    void foo1();
//    {
//        obj.showA();
//    }
    void foo2();
//    {
//        obj.showB();
//    }

    T obj;//定义一个T类型的obj变量/对象，可以传A/B对象。
};


void test()
{
    //1.定义P时，传了类型:要么A要么B，那么在C类里面，两个函数理应不能同时存在，因为此时foo2应该会报错（非法访问：A类型调用B的成员函数），但事实却是编译时并没有报错。
    //2.由一（类内实现）和二（类内声明 以及 当只是定义p,没有调用成员函数，编译后都没有报错可知：这两个函数并没有定义。
    //3.当定义p并且调用成员函数的时候，就会报错（foo的定义没找到），
    //4.说明类模板的成员函数的创建时机是在调用的时候。只要没有调用，两个函数是不会创建的。

    //5.也就是说：类模板的成员函数的创建时期是在调用时。如果不调用这个函数的函数，那么就不会创建的，只有函数的声明。
    C<A> p;

    p.foo1();//调用foo1
}

int main()
{
    test();
    return 0;
}
*/
//类模板的份文件问题:
/*
//Person.h文件
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T1,class T2>
class Person
{
public:
    Person(T1 a,T2 b);
    void show();

    T1 A;
    T2 B;
};

//Person.cpp
#include "Person.h"
//对Person里面的函数进行外部定义。
template<class T1,class T2>
Person<T1,T2>::Person(T1 a,T2 b)
{
    this->A = a;
    this->B = b;
}

template<class T1,class T2>
void Person<T1,T2>::show()
{
    cout << A << " " << B << endl;
}

//main.c
#include "Person.h"
//3.包含这个头文件，相当于把.h拿过来：
//4.又由于每个.cpp都是单独编译的


//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 a,T2 b);
//    void show();

//    T1 A;
//    T2 B;
//};


int main()
{
    //1.此时编译，会报错：无法解析的外部符号Person<int,int>,也就是说没有找到函数的定义。
    //2.无法找到是因为：类模板的成员函数是在调用的时候才创建。
    Person<int,int> p(10,20);
    p.show();//5.当编译器编译到这里时，发现它要调用p的构造函数和调用这个show函数,调用的时候就需要创建这个函数
             //6.但是，当编译器想创建这两个函数的时候发现这两个函数并没有在当前.cpp里面（main.cpp），而是在其它.cpp里面（Person.cpp）。此时编译器想要创建这两个函数就会找不到。
    //7.即：调用构造函数和show函数需要创建这两个函数，但是没有这两个函数的定义，不能被创建。

    //8.解决的办法就是，这个函数的定义需要放到Person.h当中，不能放在.cpp里面。
    //9.类模板的份文件问题：必须把函数的定义和类的声明写到一个文件当中去；更便捷的方法是：类模板的成员函数定义直接使用内部定义，在类里面实现定义。
    return 0;
}

*/
//类模板遇到友元:
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;


//类模板的声明需要将这两行都拿到前面来。
template<class T1,class T2>
class Person;

//5.showPerson1的全局模板函数声明。
template<class T1,class T2>
void showPerson1(Person<T1,T2> &p);

//1.类模板作为函数形参 函数需要写成函数模板
//方法一、全局模板函数写在 类的上面。
template<class T1,class T2>
void showPerson(Person<T1,T2> &p)
{
    cout << p.a << " " << p.b <<endl;
}

template<class T1,class T2>
class Person
{
    friend void showPerson1<>(Person<T1,T2> &p);    //4.这里声明为友元的时候，由于在前面找不到函数，因此会报错，需要在这前面加上3.的声明。
    friend void showPerson<>(Person<T1,T2> &p);//2.这只是声明普通的函数为它的友元。
    //方法三、将函数直接写在类的里面。
    //注意：这种方法写的函数，不是类的成员函数，实质还是全局函数，因为前面加了一个friend。（定义一个全局函数，并声明为类的友元）
    friend void showPerson2(Person<T1,T2> &p)//这里是直接定义，不是声明，所以不需要像前面一样在函数名后面加一个<>。
    {
        cout << p.a << " " << p.b <<endl;
    }
public:
    Person(T1 a,T2 b)
    {
        this->a = a;
        this->b = b;
    }
private:
    T1 a;
    T2 b;

};

//3.当全局模板函数 在下面
//方法二、全局模板函数写在类的下面，则需要声明。
template<class T1,class T2>
void showPerson1(Person<T1,T2> &p)
{
    cout << p.a << " " << p.b <<endl;
}

void test()
{
    Person<int,string> p(10,"lucy");
    showPerson(p);  //p是类模板，Person<int,string>这个类型的，类函数的形参
    showPerson1(p);
    showPerson2(p);
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
//类模板的应用：实现动态数组的管理
/*
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

template<class T>
class MyArray
{
public:
    //有参构造，explicit：明确，explicit关键字用来修饰 类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换，只能以显式的方式进行类型转换。
    explicit MyArray(int capacity)  //构造函数 参数传递数组容量的大小。构造对象的时候，用户指定数组的大小
    {
        this->m_Capacity = capacity;    //容量大小传递到类的成员进行保存
        this->m_Size = 0;               //元素个数初始化为0。

        //如果T是对象，那么这个对象必须提供默认的构造函数
        pAddress = new T[this->m_Capacity]; //new一个容量大小的数组空间
    }

    //拷贝构造：数组间进行赋值的时候，有数组的重新new空间，不能简单的进行值拷贝。而是址拷贝，所以要重写拷贝构造。
    MyArray(const MyArray &arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[this->m_Capacity];
        //注意：这里不能使用memcpy，因为memcpy也是简单的值拷贝。而这里可能是对象的拷贝，所以需要一个一个进行赋值
        for(int i = 0;i < this->m_Size;i++)
        {
            this -> pAddress[i] = arr.pAddress[i];
        }
    }

    //重载[] 操作符 arr[0]
    //返回[]对应的元素。所以是引用。  MyArray a(10); a[9]。
    T& operator[] (int index)
    {
        return this->pAddress[index];
    }

    //尾插法：参数：传递的类型 传递的值
    void Push_back(const T &val)
    {
        //判断数组是否满了，满了就扩容
        if(this->m_Capacity == this->m_Size)
        {
            return ;
        }
        //没满就把val值赋值到最后。
        this -> pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //尾删：
    void Pop_back()
    {
        if(this->m_Size == 0)
        {
            return ;
        }
        this->m_Size--;
    }

    //获得size.
    int getSize()
    {
        return this->m_Size;
    }

    //析构函数:数组指针指向NULL，容量和大小为0
    ~MyArray()
    {
        if(this->pAddress != NULL)
        {
            delete[] this -> pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }

private:
    T * pAddress;   //指向一个堆空间，这个空间存储真正的数据，指向数组的首元素地址。
    int m_Capacity; //数组的容量
    int m_Size;     //元素的个数
};
*/
//########################################################
//静态转换
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void test()
{
    //static_cast 用来转换内置数据类型 和 c语言的强制类型转换相似。
    int a = 1;
    char b = 2;
    double c = 3.14;
    a = static_cast<int> (b);      //编译器如果能转，应当是： a = static_case<int> (b);    //可以认为就是一个模板：<>
    a = static_cast<int> (c);
    c = static_cast<double> (a);
}

class A
{
public:
    int a;
};

//1.在不继承的基础上
//class B
//{
//public:
//    int b;
//};

//4.发生继承关系
class B:public A
{
public:
    int b;
};

void test1()
{
    A *p1 = new A;
    B *p2 = new B;
//    p1 = p2;                    //2.报错,
//    p1 = static_cast<A*> (p2);   //3.也会报错，因为不能static_cast不能转换没有发生继承关系之间的类。
    //5.如果两个类之间发生了继承关系，可以进行类型转换。
    p1 = static_cast<A*> (p2);

    //6.此时问题：是否安全？ 如果B的空间大，A空间小，B转A是否安全？=>安全，因为A能访问的空间比较小，B的对象转成A的对象使得能访问的空间变小了。
    //7.而A转B是不安全的，因为A转成B之后，能访问的空间变大，造成越界访问了。
    p2 = static_cast<B*> (p1);

    //8.因此 子（大空间）转父（小空间）， 向上转，是安全的。
    //9.    父（小空间）转子（大空间）， 向下转，是不安全的。
    //10.但注意：static_cast<>进行类型转换的时候，是不会保证转换的安全性的。

}

void test2()
{
    int * p1 = NULL;
    char *p2 = NULL;
//    p1 = static_cast<int *> (p2);   //11.对于普通的指针static_cast不能转换，只能转普通的内置类型。像指针就转不了。
//    p2 = static_cast<char *> (p1);
}

int main()
{
    test1();
    return 0;
}
*/
//#############################################################
//动态类型转化
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void test()
{
    //static_cast 用来转换内置数据类型 和 c语言的强制类型转换相似。
    int a = 1;
    char b = 2;
    double c = 3.14;
    a = static_cast<int> (b);      //编译器如果能转，应当是： a = static_case<int> (b);    //可以认为就是一个模板：<>
    a = static_cast<int> (c);
    c = static_cast<double> (a);
}

class A
{
public:
    int a;
};

//1.在不继承的基础上
//class B
//{
//public:
//    int b;
//};

//4.发生继承关系
class B:public A
{
public:
    int b;
};

//动态转换:dynamic_cast
void test3()
{
    //1.动态转换不能转内置的基本数据类型。
    int a = 1;
    char b = 2;
//    a = dynamic_cast<int> (b);//报错，不能转基本数据类型
}

void test4()
{
    //2.转自定义数据类型
    A * p1 = NULL;
    B *p2 = NULL;

    //3.可以转换的前提: 发生了继承关系，没有继承关系是不能进行转换的。
    //dynamic_cast不能用于没有发生继承关系之间的类转换
    //dynamic_cast可以用于发生继承关系之间的类号转换。
    p1 = dynamic_cast<A *>(p2); //子转父，安全的
//    p2 = dynamic_cast<B *>(p1); //子转父,不安全，转不了
    //4.因此，若两个继承类之间 发生转换，尽量用 动态转换，保证了安全性，而static_cast不能保证安全性。
}


int main()
{
    test4();
    return 0;
}
*/
//#############################################################
//常量转换：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//const转换
void test()
{
    const int a = 1;
    int * p1 = NULL;
    const int *p2 = NULL;
    //static_cast只能转基本的数据类型
//    int *p1 = static_cast<int *> (p2);//转不了


    p1 = const_cast<int *> (p2);         //去const
    p2 = const_cast<const int *> (p1);   //加const

}

int main()
{
    test();
    return 0;
}
*/
//################################################################
//reinterpret_cast重新解释转换
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;


void test()
{
    int *p1 = NULL;
    char *p2 = NULL;
    //static_cast 不能用来转指针
    //p1 = static_cast<int *>(p2)

    //dynamic_cast动态指针 主要是用于 转换类和类之间的数据类型。

    //const_cast主要用于 加减const
//    p1 = p2;//报错
    p1 = reinterpret_cast<int *>(p2);
    p2 = reinterpret_cast<char *>(p1);

    int c = 0;
//    c = p2;//报错

    //Cast from pointer to smaller type 'int' loses information
//    c = reinterpret_cast<int> (p1);//理应也正确，报错原因是：1.int * 转 int 不安全 可能导致数据丢失 2.若实在需要，则可以使用合适大小的类型，例如：uintptr_t 就是无符号正数类型，足以容纳指针的位数。
    c = reinterpret_cast<uintptr_t> (p1);//修改后正确

    //但，将指针转换为int类型的整数 是一个不安全的操作，并且可能会导致数据丢失。
    //如果 需要以整数形式打印指针的地址，可以使用合适的整数类型，例如uint ptr_t，这是一个无符号整数类型，足以容纳指针的位数。

    p1 = reinterpret_cast<int *>(c);    //
}

int main()
{
    test();
    return 0;
}
*/
//###############################################################
//c++异常
/*
//在c语言中是怎么反馈异常的?

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

int mydive(int a,int b)
{
    if(b == 0)
        return -1;
    return a/b;
}

void test()
{
    int ret = mydive(2,0);

    //但这种存在一个问题：如果mydive传参为（1，-1），能正确地计算出来是-1，但ret却报错了。
    if(ret == -1)
    {
        cout << "除数为0" <<endl;
    }
    else
    {
        cout << ret <<endl;
    }
}

int main()
{
    test();
    return 0;
}
*/
//c++异常处理
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//1.抛出int类型的异常

//int mydive(int a,int b)
//{
//    if(b == 0)
//        throw 1;//处理异常 抛出异常，即：抛出一个类型。

//    return a/b;
//}

//void test()
//{
//    //尝试捕获异常
//    try
//    {
//        mydive(2,0);
//    }
//    catch(int)//如果捕获到int类型
//    {
//      cout << "捕获了一个 int 类型的异常" << endl;
//    }
//}

//2.抛出char类型的异常
//int mydive(int a,int b)
//{
//    if(b == 0)
//        throw 'a';//处理异常 抛出异常，即：抛出一个类型。

//    return a/b;
//}

//void test()
//{
//    //尝试捕获异常 try和catch必须同时存在，不能少
//    try
//    {
//        mydive(2,0);
//    }
//    catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
//    {
//      cout << "捕获了一个 char 类型的异常" << endl;
//    }
//}

//int main()
//{
//    test();
//    return 0;
//}

//3.抛出异常后再抛
int mydive(int a,int b)
{
    if(b == 0)
        throw 'a';//处理异常 抛出异常，即：抛出一个类型。

    return a/b;
}

void test()
{
    //尝试捕获异常 try和catch必须同时存在，不能少
    try
    {
        mydive(2,0);
    }
    catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
    {
      throw 'a';
    }
}

int main()
{
    try
    {
        test();
    }
    catch (char)
    {
        cout << "捕获了一个 char 类型的异常" << endl;
    }
    return 0;
}
*/
//#########################################################################
//异常类型严格匹配
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

int mydive(int a,int b)
{
    string str = "hello";
    if(b == 0)
        throw str;//处理异常 抛出异常，即：抛出一个类型。

    return a/b;
}

void test()
{
    //尝试捕获异常 try和catch必须同时存在，不能少
    try
    {
        mydive(2,0);
    }
    catch(char)//如果捕获到int类型，如果抛出异常，但没有捕获，程序会终止。（如抛出char 类型异常，但捕获的却是int类型的。）
    {
        cout << "捕获了一个 char 类型的异常" << endl;

    }
    catch(int)
    {
        cout << "捕获了一个 int 类型的异常" << endl;
    }
    catch(double)
    {
        cout << "捕获了一个 double 类型的异常" << endl;
    }
    catch(...)  //由于如果匹配不到类型，程序会终止，因此可使用catch(...),表示匹配其它类型的异常
    {
        cout << "捕获了一个 其它 类型的异常" << endl;
    }
}

int main()
{
    test();
    return 0;
}
*/
//######################################################################
//栈解旋
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name1)
    {
        this->name = name;
        cout << "构造" << endl;
    }

    ~Person()
    {
        cout << "析构" << endl;
    }
    string name;
};

void func()
{
    Person p1("Bob");
    Person p2("lihua");
    cout << "002" << endl;
    throw 1;
}
void test()
{
    try
    {
        Person p1("lucy");
        func();
    }
    catch(int)
    {
        cout << "002" << endl;  //001 和 002 主要用于分析 析构函数是在什么时候调用的。
        cout << "捕获了一个 int 类型的异常" << endl;
    }
}
int main()
{
    test();
    return 0;
}
*/
//##############################################################
//异常接口声明
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
//可抛出所有类型异常
void TestFunction1()
{
    throw 10;
}

//只能抛出 int char char* 类型异常
void TestFunction2() throw(int,char,char*)  //c++17标准不再支持动态异常规范
{
    string exception = "error";
    throw exception;
}

//不能抛出任何类型异常
void TestFunction3() throw()
{
    throw 10;
}


int main()
{
    try{
//        TestFunction1();
//        TestFunction2();
//        TestFunction3();
    }
    catch(...)
    {
        cout << "捕获异常" << endl;
    }
    system("pause");

    return EXIT_SUCCESS;
}
//分别在QT、VS、Linux下做测试，QT 和 Linux正确
*/
//##############################################################
//异常变量的生命周期
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Myexecption
{
public:
    Myexecption()
    {
        cout << "构造函数" << endl;
    }

    ~Myexecption()
    {
        cout << "析构函数" << endl;
    }

    void error()
    {
        cout << "my error" <<endl;
    }

};

void fun()
{
//    //抛一个匿名对象
//    throw Myexecption();    //如果抛一个匿名对象，其生命周期在catch里面

    Myexecption p1;
    throw p1;


}
void test()
{
    try
    {
        fun();
    }
    catch(Myexecption &p) //使用引用接
    {
        p.error();
    }
}
int main()
{
    test();
    return 0;
}
*/
//##############################################################
//异常的多态使用
//异常的多态实现：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//父类：
class Myexception
{
public:
    virtual void error() = 0;
};

//子类
class Out_of_range:public Myexception
{
public:
    void error()
    {
      cout << "out_of_range" << endl;
    }
};

class Bad_cast:public Myexception
{
public:
    void error()
    {
      cout << " Bad_cast" << endl;
    }
};

void fun()
{
//    throw Out_of_range();
    throw Bad_cast();
}
void test()
{
    try
    {
        fun();
    }
    catch(Myexception &p) //用父类的指针或引用来接
    {
        p.error();
    }
}

int main()
{
    test();
    return 0;
}
*/
//为何使用多态实现的原因：
/*

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Myexecption
{
public:
    Myexecption()
    {
        cout << "构造函数" << endl;
    }

    ~Myexecption()
    {
        cout << "析构函数" << endl;
    }

    void error()
    {
        cout << "my error" <<endl;
    }

};

class Myexecption1
{
public:
    Myexecption1()
    {
        cout << "构造函数" << endl;
    }

    ~Myexecption1()
    {
        cout << "析构函数" << endl;
    }

    void error()
    {
        cout << "my error" <<endl;
    }

};

void fun()
{

    Myexecption p1;

    throw Myexecption1();//1.如果抛出另一个对象


}
void test()
{
    try
    {
        fun();
    }
    catch(Myexecption &p) //使用引用接
    {
        p.error();
    }
    catch(Myexecption1 &p) //2.catch就要多写一个，每多一个抛一个类型，就要多写一个catch,我们需要一个接口，实现多种功能————多态
    {
        p.error();
    }
}
int main()
{
    test();
    return 0;
}
*/
//##############################################################
//c++异常库的使用：
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
//exception
#include <stdexcept>
using namespace std;

void fun()
{
//    //抛出越界
//    throw out_of_range("越界");

    //抛出段错误
    throw invalid_argument("段错误");//抛出段错误：段错误就是无效内存访问。
}
void test()
{
    try
    {
        fun();
    }
    catch(exception &p) //用父类的指针或引用来接
    {
        cout << p.what() << endl;   //p.what()打印出错信息。
    }
}

int main()
{
    test();
    return 0;
}
*/
//##############################################################
//自定义异常类
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
//exception
#include <stdexcept>
using namespace std;

class Longlongerror:public exception
{
public:
    Longlongerror(string data)
    {
        this->data = data;
    }

    Longlongerror(char* data)
    {
        this->data = data;
    }

    const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return data.c_str();
    }

    string data;
};
void fun()
{
    throw Longlongerror("长长的错误");
}
void test()
{
    try
    {
        fun();
    }
    catch(exception &p) //用父类的指针或引用来接
    {
        cout << p.what() << endl;   //p.what()打印出错信息。
    }
}

int main()
{
    test();
    return 0;
}
*/

