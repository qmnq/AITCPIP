//1.章 STL概述
/*
    第1章STL概述
    长久以来，软件界一直希望建立一种可重复利用的东西，以及一种得以制造出"可重复运用的东西"的方法,让程序员的心血不止于随时间的迁移，人事异动而烟消云散，从函数(functions)，类别(classes),函数库(function libraries)
    类别库(class libraries)、各种组件，从模块化设计，到面向对象(object oriented)，为的就是复用性的提升。复用性必须建立在某种标准之上。但是在许多环境下，就连软件开发最基本的数据结构(datastructures)和算法(alkgorithm)都未能有一套标准。
    大量程序员被迫从事大量重复的工作，竟然是为了完成前人已经完成而自己手上并未拥有的程序代码，这不仅是人力资源的浪费，也是挫折与痛苦的来源。

    为了建立数据结构和算法的一套标准，并且降低他们之间的耦合关系,以提升各自的独立性、弹性、交互操作性(相互合作性,interoperability),诞生了 STL。

        1.1 STL基本概念
            STL(Standard Template Library,标准模板库)，是惠普实验室开发的一系列软件的统称。
            现在主要出现在c++中，但是在引入c++之前该技术已经存在很长时间了。
            STL 从广义上分为:容器(container)算法(algorithm)迭代器(iterator),容器和算法之间通过选代器进行无缝连接。（算法通过迭代器（指针）操作容器）
            STL几乎所有的代码都采用了 模板类 或者 模板函数,这相比传统的由函数和类组成的库来说提供了更好的代码重用机会。
            STL(Standard Template Library)标准模板库,在我们 c++标准程序库中隶属于 STL 的占到了 80%以上。

        1.2 STL六大组件简介
            STL提供了六大组件，彼此之间可以组合套用，这六大组件分别是:容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器。    (在c中的容器：数组、链表、队列、树等)

            容器:各种数据结构，如 vector（动态数组）、list（链表）、deque（双端插入的数组）、set（树）、map（树）等,用来存放数据，从实现角度来看，STL容器是一种 class templatee。（类模板）

            算法:各种常用的算法，如sort、find、copy、for_each。从实现的角度来看，STL算法是一种 function tempalte（函数模板）

            迭代器:扮演了容器与算法之问的胶合剂,其有五种类型,从实现角度来看,迭代器是一种将 operator*,operator->，operator++,operator--等指针相关操作予以重载的 class template.所有 STL容器都附带有自己专属的迭代器,只有容器的设计者才知道如何遍历自己的元素。原生指针(native pointer)也是一种迭代器。

            仿函数（函数对象）:行为类似函数，可作为算法的某种策略。从实现角度来看，仿函数是一种重载了operator()的 class 或者 class template

            适配器:一种用来 修饰容器 或者 仿函数 或 选代器接口 的东西。

            空问配置器:负责空间的配置 与 管理。从实现角度看，配置器是一个 实现了动态空问配置 、空间管理、空间释放的 class tempalte.

            STL六大组件的交互关系，容器通过空问配置器取得数据存储空问，算法通过选代器存储容器中的内容，仿函数可以协助算法完成不同的策略的变化，适配器可以修饰仿函数。

        总结：
            * 容器：保存数据的空间结构 vector queue deque set map list
            * 算法：特定的求解步骤： sort find for_each 。。。
            * 迭代器: 本质是一个指针
            * 仿函数：函数对象，重载了operator()的类
            * 适配器：用来修饰仿函数的（一般用来扩展参数接口）
            * 空间配置器：负责内存空间的申请 释放 管理 等。

        1.3 STL的优点
            STL是C++的一部分，因此不用额外安装什么，它被内建在你的编译器之内。

            STL 的一个重要特性是将 数据 和 操作 分离。数据 由 容器类别加以管理，操作则由可定制的算法定义。迭代器在两者之间充当“粘合剂",以使算法可以和容器交互运作

            程序员可以不用思考 STL 具体的实现过程，只要能够然练使用STL就 OK了。这样他们就可以把精力放在程序开发的别的方面。
        总结：
            STL具有高可重用性，高性能，高移植性，跨平台的优点。
                高可重用性:STL 中几乎所有的代码都采用了 模板类 和 模版函数 的方式实现,这相比于传统的由函数和类组成的库来说提供了更好的代码重用机会。关于模板的知识，已经给大家介绍了。
                高性能:如 map 可以高效地从十万条记录里面查找出指定的记录，因为map 是采用红黑树的变体实现的。
                高移植性:如在项目A上用 STL 编写的模块，可以直接移植到项目 B上。
*/
//2.章 STL三大组件
/*
    2章. STL三大组件
        2.1 容器：保存数据的（可以认为是数据结构）
            容器，置物之所也。
            研究数据的特定排列方式，以利于 搜索 或 排序 或 其他特殊目的，这一门学科我们称为 数据结构。大学信息类相关专业里面，与编程最有直接关系的学科，首推数据结构与算法。几乎可以说，任何特定的数据结构都是为了实现某种特定的算法。

          * STL容器 就是将运用最广泛的一些 数据结构 实现出来。
                * 常用的数据结构:数组(array),链表(list),tree(树)，栈(stack),队列(queue),集合(set),映射表(map).
                * 根据数据在容器中的排列特性，这些数据分为 序列式容器 和 关联式容器两种。
                    序列式容器（每插入一个数据都有固定的位置 类似数组） 强调 值的排序，序列式容器中的每个元素均有固定的位置，除非用删除或插入的操作改变这个位置。Vector 容器、Deque 容器、List 容器等。
                    关联式容器（位置不固定，可以随便插 类似树） 是 非线性的树结构，更准确的说是 二叉树结构。各元素之间没有严格的物理上的顺序关系，也就是说 元素在容器中并没有保存元素置入容器时的逻辑顺序。关联式容器另一个显著特点是:在值中 选择一个值 作为关键字 key，这个关键字对值起到索引的作用，方便査找。Set/multiset 容器 Map/multimap 容器

            容器可以嵌套容器!

        2.2 算法
            算法，问题之解法也。
            以有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms).

            广义而言，我们所编写的每个程序都是一个算法，其中的每个函数也都是一个算法，毕竟它们都是用来解决或大或小的逻辑问题或数学问题。

            STL收录的算法 经过了数学上的效能分析与证明，是极具复用价值的，包括常用的 排序，查找等。特定的算法往往搭配特定的数据结构，算法与数据结构相辅相成。

          * 算法分为:质变算法和非质变算法。
                质变算法:  是指 运算过程中 会更改区间内的元素的内容。例如拷贝，替换，删除等
                非质变算法:是指 运算过程中 不会更改区间内的元素的内容，例如查找、计数、历、寻找极值等等

          * STL提供了很多的算法，我们只需要调用其库然后使用即可，库(头文件)名称为：algorithm

        2.3 迭代器（当成指针来用，说白了可以理解为这就是一个指针，这种指针又被封装成了一个类，然后这个类就像智能指针一样，指向了某个元素，解压器支持指针++、--）
            迭代器(iterator)是一种抽象的设计概念，现实程序语言中并没有直接对应于这个概念的实物。在<>一书中提供了 23 种设计模式的完整描述，
            其中 iterator模式定义如下:提供一种方法，使之能够 依序寻访 某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。

            迭代器的设计思维-STL的关键所在，STL的中心思想在于将容器(container)和算法(algorithms)分开，彼此独立设计，最后再一贴胶着剂将他们撮合在一起。从技术角度来看，容器和算法的泛型化并不困难，
            c++的 class template 和 function template 可分别达到目标，如果设计出两这个之间的良好的胶着剂，才是大难题。

            迭代器的种类

            输入迭代器       提供对数据的只读访问                                          只读，支持++、==、!=
            输出迭代器       提供对数据的只写访问                                          只写，支持++
            前向迭代器       提供读写操作，并能向前推进选代器                                读写，支持++、==、!=
            双向迭代器       提供读写操作，并能向前和向后操作                                读写，支持++，--，
            随机访问迭代器    提供读写操作，并能以跳跃的方式访问容器的任意数据，是功能最强的迭代器   读写,支持++、--、[n]、-n、<、<=、>、>=

            2.3.1 迭代器指向元素为int类型
                案例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //STL 中的容器 算法 迭代器

                    void test()
                    {

                        //vector：容器，容器一定义就是一个数组，这个数组是动态数组，可以随容量可增可减。
                        //容器可以认为是一个类，以类模板方式去定义，类型由我们给定
                        vector<int> v;//STL 中的标准容器之一：动态数组（用vector这个类定义一个对象v（对象v是一个动态数组），对象的每一个元素的类型为int）

                        //这个类提供了 对这个数组操作的接口，如插入，尾插。
                        //v.push_back() 就是尾插
                        v.push_back(2);//vector 容器提供的插入数据的方法
                        v.push_back(4);
                        v.push_back(5);
                        v.push_back(3);

                        //迭代器

                        //若想要遍历容器v的每一个元素，需要拿到指向首个元素的指针，也就是指向首元素的迭代器。
                        //v.begin()   开始迭代器：获得指向首元素的迭代器
                        //v.end()     结束迭代器：获取指向最后一个元素的下一个元素 的 迭代器（指针））
                        //迭代器的类型： vector<int>::iterator
                        vector<int>::iterator it_start = v.begin(); //vector 容器提供了 begin()方法 返回指向第一个元素的迭代器
                        vector<int>::iterator it_end   = v.end();   //vector 容器提供了   end()方法 返回指向最后一个元素下一个位置的迭代器

                        //通过迭代器遍历
                        for(;it_start != it_end;it_start++)
                        {
                            //对迭代器解引用，取得该空间的内容
                            cout << *it_start << " ";
                        }
                        cout << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            2.3.2 迭代器指向元素为 自定义类型
                案例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
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

                    void print_Person(Person &p)
                    {
                        cout << p.age << endl;
                    }
                    void test()
                    {
                        Person p1(1);
                        Person p2(2);
                        Person p3(3);
                        Person p4(4);

                        vector<Person> v;

                        v.push_back(p1);
                        v.push_back(p2);
                        v.push_back(p3);
                        v.push_back(p4);

                        vector<Person>::iterator it_start = v.begin();
                        vector<Person>::iterator it_end   = v.end();

                        for(;it_start != it_end;it_start++)
                        {
                           print_Person(*it_start);
                        }

                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            2.3.3 迭代器指向的是一个容器
                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    void test()
                    {
                        //1.定义小容器
                        vector<int> v1;
                        vector<int> v2;
                        vector<int> v3;
                        //2.小容器插入数据
                        for(int i = 0;i<3;i++)
                        {
                            v1.push_back(i);
                            v2.push_back(i+10);
                            v3.push_back(i+100);
                        }

                        //容器 嵌套 容器，v是大容器，容器里面是小容器。
                        //3.定义大容器
                        vector< vector<int> > v;

                        //4.大容器插入小容器
                        v.push_back(v1);
                        v.push_back(v2);
                        v.push_back(v3);

                        //it_start 指向的是一个 vector<int> 的小容器 ，*it_start == vector<int>
                        //(*it_start).begin() 指向小容器的首元素。
                        //5.遍历
                        vector<vector<int>>::iterator it_start = v.begin() ;//获得的是容器的首元素地址
                        vector<vector<int>>::iterator it_end   = v.end() ;

                        for(;it_start != it_end;it_start++)
                        {
                            //*it_start 得到小容器
                            vector<int>::iterator itl_start = (*it_start).begin();
                            vector<int>::iterator itl_end   = (*it_start).end();
                            for(;itl_start != itl_end;itl_start++)
                            {
                                cout << *itl_start <<endl;
                            }
                        }
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }
*/
//3.1 string 容器
/*
    3章 常用容器
        3.1 string 容器
            3.1.1 string 容器基本概念
                C风格字符串(以空字符结尾的字符数组)太过复杂 难于掌握,不适合大程序的开发,所以C++标准库定义了一种string类，定义在头文件。

                String和 C风格字符串对比:
                    u char*是一个指针，String 是一个类
                    string 封装了 char，管理这个字符串，是一个char型的容器
                    u string 封装了很多实用的成员方法
                    查找find，拷贝copy，删除delete 替换replace，插入insert
                    u 不用考虑内存释放和越界
                    string管理 char*所分配的内存。每一次string的复制，取值都由 string 类负责维护，不用担心复制越界和取值越界等。算法

            总结：
                string容器是一个类，这个容器中有一个指针，指针维护了一个数组，
                string容器提供了copy、find、insert、replace等功能。

            3.1.2 string容器的常用操作
                3.1.2.1 string 构造函数
                    string();/创建一个空的字符串: string str;
                    string(const string& str);//使用一个string 对象初始化另一个string 对象
                    string(const char*s);//使用字符串s初始化
                    string(int n，char c);//使用n个字符c 初始化 v

                例：string的构造函数：
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <string>
                        #include <stdlib.h>
                        #include <vector>
                        #include <algorithm>
                        using namespace std;

                        void test()
                        {
                            string str;
                            string str1("hello");
                            string str2(str1);
                            string str3(5,'k');

                            cout << str1 << endl;
                            cout << str2 << endl;
                            cout << str3 << endl;
                        }
                        int main()
                        {
                            test();
                            return 0;
                        }



                3.1.2.2 string 基本 赋值 操作
                    string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
                    string& operator=(const string &s);//把字符串s 赋给当前的字符串
                    string& operator=(char c);//字符 赋值给当前的字符串
                    string& assign(const char*s);//把字符串s 赋给当前的字符串
                    string& assign(const char *s,int n);//把字符串s 的前n个字符赋给当前的字符串
                    string& assign(const string &s);//把字符串s赋给当前字符串
                    string& assign(int n，char c);//用n个字符c 赋给当前字符串
                    string& assign(const string &s, int start, int n);//将s 从start开始n个字符 赋值 给字符串

                例：
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <string>
                        #include <stdlib.h>
                        #include <vector>
                        #include <algorithm>
                        using namespace std;

                        //string的基本 赋值 操作
                        void test()
                        {
                            string str("helloworld");
                            string str1("heihei");
                            str = "hehe";               //赋值 char*字符串
                            cout << str << endl;
                            str = str1;                 //赋值 &对象
                            cout << str << endl;
                            str = 'c';                  //赋值 字符
                            cout << str << endl;

                            str.assign("hello");        //方法赋值 字符串
                            cout << str << endl;
                            str.assign("jack",2);       //赋值字符串的两个
                            cout << str << endl;
                            str.assign(str1);           //方法赋值 对象
                            cout << str << endl;
                            str.assign(5,'c');          //赋值 5个c给str
                            cout << str << endl;
                            str.assign("helloworld",0,5);
                            cout << str << endl;

                        //    hehe
                        //    heihei
                        //    c
                        //    hello
                        //    ja
                        //    heihei
                        //    ccccc
                        //    hello
                        }
                        int main()
                        {
                            test();
                            return 0;
                        }

                3.1.2.3 string c存取 字符 操作
                    char& operator[](int n);//通过[]方式取字符
                    char& at(int n);//通过at 方法获取字符
                例：
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <string>
                        #include <stdlib.h>
                        #include <vector>
                        #include <algorithm>
                        using namespace std;
                        void test()
                        {
                            string str("helloworld");
                            cout << str[4] << endl;
                            str[4] = 'c';

                            cout << str.at(4) << endl;
                        }
                        int main()
                        {
                            test();
                            return 0;
                        }

            3.1.2.4 string 拼接操作
                string& operator+=(const string& str);          //重载+=操作符
                string& operator+=(const char*str);             //重载+=操作符
                string& operator+=(const char c);               //重载+=操作符
                string& append(const char*s);                   //把字符串s 连接到当前字符串 结尾
                string& append(const char*s,int n);             //把字符串s的 前n个字符 连接到当前字符串结尾
                string& append(const string &s);                //同operator+=()
                string& append(const string &s,int pos,int n);  //把字符串s 中从 pos 开始的 n 个字符连接到当前字符串结尾
                string& append(int n,char c);                   //在当前字符串结尾添加 n个字符c

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    void test()
                    {
                        string str1("helloworld");
                        string str2("123456");

                        str1 += str2;
                        str1 += "hehe";
                        str1 += 'c';

                        str1.append("world");
                        str1.append("world",3);
                        str1.append(str2);
                        str1.append(str2,1,3);
                        str1.append(5,'c');
                        cout << str1 << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            3.1.2.5 string 查找 和 替换
                int find(const string& str,int pos =0)const;            //査找str 第一次出现位置,从pos 开始査找
                int find(const char*s,int pos=0)const;                  //査找s 第一次出现位置,从pos 开始査找
                int find(const char*s,int pos,int n)const;              //从pos 位置査找s 的前n 个字符第一次位置
                int find(const char c,int pos=0)const;                  //查找字符c 第一次出现位置
                int rfind(const string& str,int pos = npos)const;       //査找str 最后一次位置,从pos 开始查找
                int rfind(const char*s,int pos=npos)const;              //査找s 最后一次出现位置,从pos 开始査找
                int rfind(const char*s,int pos,int n)const;             //从pos 査找s 的前n 个字符最后一次位置
                int rfind(const char c,int pos=日)const;                //査找字符c 最后一次出现位置
                string& replace(int pos,int n,const string& str);      //替换从pos 开始n 个字符为字符出str
                string& replace(int pos,int n,const char*s);           //替换从pos 开始的n 个字符为字符出 s

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <algorithm>
                using namespace std;

                void test()
                {
                    string str("helrloworld");
                    string str1("wor");
                    cout << str.find(str1) << endl;
                    cout << str.find("wor") << endl;
                    cout << str.find("world",0,2) << endl;
                    cout << str.find('o') << endl;

                    cout << str.rfind("rl") << endl;
                    str.replace(2,4,str1);
                    cout << str << endl;

                }
                int main()
                {
                    test();
                    return 0;
                }

            3.1.2.6 string 比较操作

                compare 函数在 > 时 ,返回1，< 时返回 -1，==时返回0。
                比较区分大小写、比较时参考字典顺字，排越前面的越小
                大写的A 比小写的a 小。

                int compare(const string &s)const;  //与字符串s 比较
                int compare(const char *s)const;    //与字符串s 比较
            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    void test()
                    {
                        string str1("hello");
                        string str2("world");
                        int ret = str1.compare(str2);
                        ret = str1.compare("hello");
                        if(ret > 0)
                        {
                            cout << "str大" << endl;
                        }
                        else if(ret < 0)
                        {
                            cout << "str小" << endl; //str1 比 str2小
                        }
                        else
                        {
                            cout << "相等" << endl;
                        }
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            3.1.2.7 string 子串: 获得一个字符串当中的某一段
                string substr(int pos = 0,int n = npos)const;//返回由 pos 开始的n 个字符组成的字符串

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    void test()
                    {
                        string str1("helloworld");
                        string str = str1.substr(4,3);
                        cout << str << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            3.1.2.8 string 插入和 删除操作
                string& insert(int pos, const char* s);     //插入字符串
                string& insert(int pos, const string& str)  //插入字符串
                string& insert(int pos,int n,char c);       //在指定位置插入n个字符
                string& erase(int pos,int n = npos);        //删除从Pos开始的n个字符

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <algorithm>
                using namespace std;

                void test()
                {
                    //第二个位置插入kkk
                    string str("helloworld");
                    string str2("hehe");
                //    str.insert(2,"kkk");

                    //插字符串
                //    str.insert(2,str2);
                //    cout << str << endl;

                    //插字符:位置2插10个r
                //    str.insert(2,10,'r');
                //    cout << str << endl;

                    //删除
                    //从第三个位置，删除3个
                    str.erase(3,3);
                    cout << str << endl;

                }
                int main()
                {
                    test();
                    return 0;
                }

            3.1.2.9 string 和 c-style 字符串转换
                //string 转char*
                string str = "itcast";
                const char* cstr = str.c_str();

                //char*转string
                char*s= "itcast";
                string str(s);

                在c++中存在一个从const char 到string的隐式类型转换，却不存在从一个string 对象到Cstring 的自动类型转换。
                对于string 类型的字符串，可以通过c_str()函数返回string对象对应的C_string.

                通常，程序员在整个程序中 应坚持使用 string 类对象，直到必须将内容转化为char时才将其转换为c_string.
            提示;
                为了修改string 字符串的内容，下标操作符[]和 at 都会返回字符的引用。但当字符串的内存被重新分配之后，可能发生错误.
                例：
                    string s = "abcdefg";
                    char & a = s[2];            //引用传递

                    a = '1';
                    b = '2';

                    cout << s << endl;
                    cout << (int *)s.c_str()  << endl;

                    //但是当s指向新的空间的时候，原来指向的空间会被释放
                    s = "ppppppppppppppppppppppppppp";

                    //此时再对a,b操作，会报错，非法访问
                    //a = '1';
                    //b = '2';

                    cout << s << endl;
                    cout << (int)s.c_str() << endl;

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <algorithm>
                using namespace std;

                void test()
                {
                    string str("hello");
                    str = "world";          //1.可以赋值，调用opreator=(char *)

                    char *s = NULL;
                //    s = str;          //2.不能赋值，因为s是char*，
                    //3.但string里面有c_str()方法，返回的是const char *
                //    str.c_str();    //返回const char *
                    //4.只需要去const即可。
                    s = const_cast<char *> (str.c_str());
                    cout << s <<endl;

                }

                int main()
                {
                    test();
                    return 0;
                }

*/
//3.2 vector 容器
/*
        3.2 vector 容器
            3.2.1 vector 容器基本概念
                vector 的数据安排 以及 操作方式,与 array 非常相似,两者的唯一差别在于空问的运用的灵活性。
                Array 是静态空间,一旦配置了就不能改变，要换大一点或者小一点的空问，虽可以，但一切琐碎得由自己来，首先配置一块新的空间,然后将旧空间的数据搬往新空间，再释放原来的空间。
                Vector是动态空间，随着元素的加入，它的内部机制会自动扩充空间以容纳新元素。因此 vector 的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必害怕空间不足而一开始就要求一个大块头的array了。

              * Vector 的实现技术，关键在于其 对大小的控制 以及 重新配置时的数据移动效率 ，一旦 vector 旧空问满了，如果客户每新增一个元素，vector内部只是扩充一个元素的空间，实为不智，因为所谓的扩充空间(不论多大)，一如刚所说，是"配置新空间·数据移动·释放旧空间"的大工程,时间成本很高，应该加入某种未雨绸缪的考虑，稍后我们便可以看到 vector 的空间配置策略。

                  v.begin()     首地址，指向首元素
                  v.end()       尾地址，指向末元素
                  insert()      插入位置
                  v.rbegin()    尾地址，指向末元素
                  v.rend        首地址，指向首元素
                  v.push_back() 尾插
                  v.pop_back()  尾删

            3.2.2 vector 迭代器
                Vector维护一个线性空间，所以不论元素的型别如何，普通指针都可以作为 vector 的迭代器，因为 vector 迭代器
                所需要的操作行为,如 operator. , operator->, operator++,operator--, operatort+,operator-, operator+=,operator-=，普通指针天生具备。
                vector 支持随机存取,而普通指针正有着这样的能力。所以vector 提供的是随机访问达代器(Random Access Iterators).

                根据上述播述，如果我们写如下的代码:
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <algorithm>
                using namespace std;

                //vector迭代器
                void test()
                {
                    vector<int> v;
                    v.push_back(1);
                    v.push_back(2);
                    v.push_back(3);
                    v.push_back(4);

                    vector<int>::iterator it_start = v.begin();//iterator 迭代器
                    vector<int>::iterator it_end   = v.end();

                    vector<int>::reverse_iterator ri_start = v.rbegin();
                    vector<int>::reverse_iterator ri_end   = v.rend();

                    for(;it_start != it_end;it_start++)
                    {
                        cout << *it_start << " ";
                    }
                    cout << endl;

                    for(;ri_start != ri_end;ri_start++)
                    {
                        cout << *ri_start << " ";
                    }
                    cout << endl;

                }

                //空间配置
                void test1()
                {
                    vector<int> v;
                    for(int i = 0; i< 100;i++)
                    {
                        v.push_back(i);
                        cout << v.capacity() << endl;
                    }
                }
                int main()
                {
                //    test();
                    test1();
                    return 0;
                }

            3.2.3 vector 的数据结构
                Vector 所采用的数据结构非常简单，线性连续空间，它以两个迭代器 Myfirst 和Mylast 分别指向配置得来的连续空间中目前已被使用的范围，并以迭代器 Myend指向整块连续内存空间的尾端。

                为了降低空间配置时的速度成本，vector实际配置的大小可能比客户端需求大一些，以备将来可能的扩充，这便是容量的概念。
                换句话说，一个 vector 的容量永远大于或等于其大小，一旦容量等于大小，便是满载，下次再有新增元素，整个 vector 容器就得另觅居所。

            注意:
                所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。
                因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。这是程序员容易犯的一个错，务必小心。

            3.2.4 vector 常用API 操作
                3.2.4.1 vector 构造函数
                    vector<T> v;//采用模板实现类实现，默认构造函数
                    vector(v.begin()，v.end());//将v[begin()，end())区间中的元素拷贝给本身
                    vector(n，elem);//构造函数将n个elem拷贝给本身
                    vector(const vector &vec);//拷贝构造函数。
                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //vector<T> v;//采用模板实现类实现，默认构造函数
                    //vector(v.begin()，v.end());//将v[begin()，end())区间中的元素拷贝给本身
                    //vector(n，elem);//构造函数将n个elem拷贝给本身
                    //vector(const vector &vec);//拷贝构造函数。

                    void print(int a)
                    {
                        cout << a <<endl;
                    }
                    void test()
                    {
                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(2);
                        v1.push_back(3);
                        v1.push_back(4);


                        vector<int> v2(v1.begin()+1,v1.end());
                        vector<int> v3(4,5);    //存4个5
                        vector<int> v4(v1);

                    //    for_each(v2.begin(),v2.end(),print);    //for_each的头文件是<algorithm>.函数的使用方式如前。
                        for_each(v3.begin(),v3.end(),print);    //5555
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.2 vector 常用赋值操作
                    assign(beg,end);                        //将[beg，end)区间中的数据拷贝赋值给本身
                    assign(n,elem);                         //将n个elem 接贝赋值给本身。
                    vector& operator=(const vector &vec);   //重载等号操作行
                    swap(vec);                              // 将vec 与本身的元素互换。
                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //assign(begin,end);                      //将[beg，end)区间中的数据拷贝赋值给本身
                    //assign(n,elem);                         //将n个elem 接贝赋值给本身。
                    //vector& operator=(const vector &vec);   //重载等号操作行
                    //swap(vec);                              // 将vec 与本身的元素互换。
                    void print(int a)
                    {
                        cout << a <<endl;
                    }

                    void test()
                    {
                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(2);
                        v1.push_back(3);
                        v1.push_back(4);

                        vector<int> v2;
                        v2.push_back(9);
                        v2.push_back(8);
                        v2.push_back(7);
                        v2.push_back(6);
                    //    v2.assign(v1.begin()+1,v1.end());
                    //    v2.assign(10,5);
                    //    v2 = v1;
                        v2.swap(v1);    //这个交换只是把v1和 v2的指针进行了交换。
                        for_each(v1.begin(),v1.end(),print);
                        cout << "-----" <<endl;
                        for_each(v2.begin(),v2.end(),print);
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.3 vector 大小操作
                    size();                                 //返回容器中元素的个数
                    empty();                                //判断容器是否为空
                    resize(int num);                        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短,则未尾超出容器长度的元素被删除。
                    resize(int num,elem);                   //重新指定容器的长度为num，若容器变长，则以elem 值填充新位置。如果容器变短、则未尾超出容器长>度的元素被删除。
                    capacity();                             //容器的容量
                    reserve(int len);                       //容器预留len 个元素长度，预留位置不初始化，无素不可访问。
                例：

                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //size();                                 //返回容器中元素的个数
                    //empty();                                //判断容器是否为空
                    //resize(int num);                        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短,则未尾超出容器长度的元素被删除。
                    //resize(int num,elem);                   //重新指定容器的长度为num，若容器变长，则以elem 值填充新位置。如果容器变短、则未尾超出容器长>度的元素被删除。
                    //capacity();                             //容器的容量
                    //reserve(int len);                       //容器预留len 个元素长度，预留位置不初始化，无素不可访问。

                    void print(int a)
                    {
                        cout << a <<endl;
                    }

                    void test()
                    {
                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(2);
                        v1.push_back(3);
                        v1.push_back(4);
                        v1.push_back(5);

                        cout << v1.size() << endl;          //5
                        cout << v1.capacity() << endl;      //8

                    //    v1.resize(3);     // 1 2 3
                    //    v1.resize(10);      //1 2 3 0 0 0 ...默认变长的填充值为0
                        v1.resize(10,2);    //默认变长的填充值为2

                        for_each(v1.begin(),v1.end(),print);

                        if(!v1.empty())//判断是否为空
                        {
                            cout << "不为空" << endl;
                        }


                        vector<int> v2;
                        //若已知需要 一个确定的大小（如1万），则可以直接选择预留1万的空间，而不是每增加一个元素就重新找匹配的空间存放。
                        v2.reserve(100);    //预设定容量
                        cout << v2.size() << endl;      //0
                        cout << v2.capacity() << endl;  //100，事先给容量扩展到100，
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.4 vector 数据存取操作
                    at(int idx);//返回索引idx 所指的数据，如果idx 越界，抛出out_of_range 异常。
                    operator[];//返回索引idx 所指的数据，越界时，还行直接报错
                    front();//返回容器中第一个数据元素
                    back();//返回容器中最后一个数据元素
                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //at(int idx);//返回索引idx 所指的数据，如果idx 越界，抛出out_of_range 异常。
                    //operator[];//返回索引idx 所指的数据，越界时，还行直接报错
                    //front();//返回容器中第一个数据元素
                    //back();//返回容器中最后一个数据元素
                    void print(int a)
                    {
                        cout << a <<endl;
                    }

                    void test()
                    {
                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(2);
                        v1.push_back(3);
                        v1.push_back(4);
                        v1.push_back(5);

                        cout << v1.at(2) << endl;
                        cout << v1[2] << endl;
                        cout << v1.front() << endl;//返回第一个元素
                        cout << v1.back() << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.5 vector 插入和删除操作
                    insert(const_iterator pos, int count,ele);//迭代器指问位置pos 插入count 个元素ele.
                    push_back(ele);//尾部插入元素ele
                    pop_back();//删除最后一个元素
                    erase(const iterator start, const iterator end);//删除选代器从start 到end 之间的元素
                    erase(const iterator pos);//删除选代器指向的元素
                    cLear();//删除容器中所有元素

                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //insert(const_iterator pos, int count,ele);//迭代器指问位置pos 插入count 个元素ele.
                    //push_back(ele);//尾部插入元素ele
                    //pop_back();//删除最后一个元素
                    //erase(const iterator start, const iterator end);//删除选代器从start 到end 之间的元素
                    //erase(const iterator pos);//删除选代器指向的元素
                    //cLear();//删除容器中所有元亲

                    void print(int a)
                    {
                        cout << a <<endl;
                    }

                    void test()
                    {
                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(2);
                        v1.push_back(3);
                        v1.push_back(4);
                        v1.push_back(5);

                    //    v1.pop_back();//尾删
                        v1.erase(v1.begin()+3,v1.end());

                        v1.insert(v1.begin()+2,3,9);    //在+2位置插入3个9
                        v1.erase(v1.begin()+3);         //删除指定元素
                        for_each(v1.begin(),v1.end(),print);
                        v1.clear(); //删除所有元素
                        for_each(v1.begin(),v1.end(),print);
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.6 vector 案例
                    3.2.4.6.1 使用swap收缩空间

                        vector<int>(v1).swap(v1); //创建匿名的容量对象,并且用v1初始化（v1有几个元素，匿名对象就开辟对于大小的空间），在将该初始化空间同v1交换。

                        例：
                            #define _CRT_SECURE_NO_WARNINGS
                            #include <iostream>
                            #include <string.h>
                            #include <string>
                            #include <stdlib.h>
                            #include <vector>
                            #include <algorithm>
                            using namespace std;

                            void print(int a)
                            {
                                cout << a <<endl;
                            }

                            void test()
                            {
                                vector<int> v1;
                                for(int i=0;i<10000;i++)
                                {
                                    v1.push_back(i);
                                }
                                cout << v1.size() <<" "<< v1.capacity()<< endl;
                                v1.resize(10);//size变成10了，容量不变，会浪费很多1空间
                                cout << v1.size() <<" "<< v1.capacity()<< endl;
                                vector<int>(v1).swap(v1); //创建匿名的容量对象,并且用v1初始化（v1有几个元素，匿名对象就开辟对于大小的空间），在将该初始化空间同v1交换。
                                cout << v1.size() <<" "<< v1.capacity()<< endl;
                            }

                            int main()
                            {
                                test();
                                return 0;
                            }
                    3.2.5.6.2 reservr 预留空间
                        v.reserve(10000);//预留10000容量大小的空间。

                    注意：
                        如果没有预留空间，那么假如从0开始开辟一个10000大小的空间，需要重新开辟多少次？能否预测？
                        例：计算重新开辟空间的次数
                            #define _CRT_SECURE_NO_WARNINGS
                            #include <iostream>
                            #include <string.h>
                            #include <string>
                            #include <stdlib.h>
                            #include <vector>
                            #include <algorithm>
                            using namespace std;

                            void test()
                            {
                                vector<int> v1;
                                int *p = NULL;
                                int count = 0;
                                //由于每一次重新申请空间，首元素地址都会改变，那么只需要计数首元素地址改变的次数即可。
                                for(int i=0;i<10000;i++)
                                {
                                    v1.push_back(i);
                                    if(p != &v1[0])
                                    {
                                        count++;
                                        p = &v1[0];
                                    }
                                }
                                cout << count << endl;
                            }

                            int main()
                            {
                                test();
                                return 0;
                            }

                3.2.4.7 容器的排序
                    bool compare1(Person &p1,Person &p2)
                    {
                    //    return p1.age > p2.age;   //从大到小排序
                        return p1.age < p2.age;     //从小到大排序
                    }

                    sort(v1.begin(),v1.end(),compare);

                例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;
                    void print(int a)
                    {
                        cout << a <<endl;
                    }

                    bool compare(int a,int b)
                    {
                        return a>b;
                    }
                    void test()
                    {

                        vector<int> v1;
                        v1.push_back(1);
                        v1.push_back(3);
                        v1.push_back(2);
                        v1.push_back(5);
                        v1.push_back(4);

                    //    sort(v1.begin(),v1.end());//从小到大排序
                        sort(v1.begin(),v1.end(),compare);//a>b是从大到小排序。a < b是从小到大
                        //algorithm里面得到sort这个函数其实是重载的，还可以填写一个回调函数，
                        for_each(v1.begin(),v1.end(),print);
                    }

                    //如何排序 自定义对象？？
                    class Person
                    {
                    public:
                        Person(int age,string s)
                        {
                            this->age = age;
                            this->name = s;
                        }
                        int age;
                        string name;
                    };

                    void print1(Person &p)
                    {
                        cout << p.age << " " << p.name <<endl;
                    }
                    bool compare1(Person &p1,Person &p2)
                    {
                    //    return p1.age > p2.age;   //从大到小
                        return p1.age < p2.age;
                    }
                    void test1()
                    {
                        vector<Person> v;
                        Person p1(10,"马超");
                        Person p2(40,"黄忠");
                        Person p3(50,"安其拉");
                        Person p4(20,"貂蝉");
                        Person p5(30,"廉颇");

                        v.push_back(p1);
                        v.push_back(p2);
                        v.push_back(p3);
                        v.push_back(p4);
                        v.push_back(p5);
                        for_each(v.begin(),v.end(),print1);

                        //排序：
                        sort(v.begin(),v.end(),compare1);
                        for_each(v.begin(),v.end(),print1);


                    }
                    int main()
                    {
                        test1();
                        return 0;
                    }

*/
//3.3 deque 容器
/*
    3.3 deque 容器
        3.3.1 deque 容器基本概念
            Vector 容器是  单向开口 的 连续内存空间，
            deque 则是一种  双向开口 的 连续线性空间。

            所谓的双向开口，意思是 可以在头尾两端分别做元素的插入和删除操作，
            当然，vector 容器也可以在头尾两端插入元素，但是在其头部操作效率奇差，无法被接受。

            (vector可以尾插和尾删，但没有支持头插和头删的接口。因为他如果要头插 和 头删，就需要把元素往后面挪，效率极低。)
        deque内部：
            push_front() 头插
            pop_front()  头删
            push_back()  尾插
            pop_back()   尾删
            begin()
            end()       两个迭代器
            insert()    插入接口

            deque容器与vector容器最大的差异就是：deque插入时不需要改变其它的元素的一个移动。

          * Deque 容器和vector容器最大的差异，
                一在于 deque 允许使用常数项时间对头端进行元素的插入和删除操作。
                二在于 deque 没有容量的概念，因为它是动态的以分段连续空间组合而成，随时可以增加一段新的空间并链接起来,换句话说，像 vector 那样，”旧空间不足而重新配置一块更大空间，然后复制元素，再释放旧空间"这样的事情在 deque 身上是不会发生的。也因此，deque 没有必须要提供所谓的空间保留（reserve）功能。

          * 虽然 degue 容器也提供了 Random Access lterator,但是它的迭代器并不是普通的指针，其复杂度和 vector 不是一个量级，这当然影响各个运算的层面。
            因此，除非有必要，我们应该尽可能的使用 vector，而不是 deque。

          * 对 deque 进行的排序操作，为了最高效率，可将 deque 先完整的复制到一个 vector 中，对vector 容器进行排序，再复制回deque.

        3.3.2 deque 容器的实现原理
            Deque 容器是 连续的空间，至少逻辑上看来如此，连续现行空间总是令我们联想到array 和 vector,array 无法成长,vector 虽可成长，却只能向尾端成长，而且其成长其实是一个假象，实质上是(1)申请更大空间 (2)原数据复制新空间(3)释放原空间 三步骤，
            如果不是 vector 每次配置新的空间时都留有余裕，其成长假象所带来的代价是非常昂贵的。

            Degue 是由一段一段的定量的连续空间构成。一旦有必要在 deque 前端或者尾端增加新的空间，便配置一段连续定量的空间，串接在 deque的头端或者尾端。
            Deque 最大的工作就是维护这些分段连续的内存空间的整体性的假象，并提供随机存取的接口，避开了重新配置空间，复制，释放的轮回，代价就是复杂的选代器架构。

            既然 deque 是分段连续内存空间，那么就必须有中央控制，维持整体连续的假象，数据结构的设计及迭代器的前进 后退操作颇为繁琐。

          * Deque 代码的实现 远比vector或list 都多得多。Deque 采取一块所谓的 map(注意，不是 STL的 map 容器)作为主控，这里所谓的 map 是一小块连续的内存空间,其中每一个元素(此处成为一个结点)都是一个指针，指向另一段连续性内存空间，称作缓冲区。
          * 缓冲区 才是 deque 的存储空间的主体。

              中控器               缓冲区
                        ->                 ele ele ele
             0x01

        节点  0x02     ->       ele ele ele ele ele ele

             0x03       ->      ele ele ele


             （中控器中保存的就是一段一段的地址，本质上deque容器存储的就是一个个指针，数据存储在 指针指向的 缓冲区里面）

        3.3.3 deque 常用API
            3.3.3.1 deque 构造函数
                deque<T> deqT; //默认构造形式
                deque(beg,end); //构造函数将[beg,end)区间中的元素拷贝给本身。
                deque(n，elem);//构造函将n 个elem 拷贝给本身,
                deque(const deque &deq);//拷贝构造函数。

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                //deque<T> deqT; //默认构造形式
                //deque(beg,end); //构造函数将[beg,end)区间中的元素拷贝给本身。
                //deque(n，elem);//构造函将n 个elem 拷贝给本身,
                //deque(const deque &deq);//拷贝构造函数。
                void print(int a)//打印的是什么类型，就传什么类型参数
                {
                    cout << a << endl;
                }
                void test()
                {
                    deque<int> d1;  //默认构造
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    deque<int> d2(d1); //用d1来初始化d2
                    deque<int> d3(d1.begin(),d1.end()); //用d1的开始到结束初始化d3
                    deque<int> d4(10,8);                //10个8

                    for_each(d4.begin(),d4.end(),print);
                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.2 deque容器的赋值操作
                assign(beg，end);                    //将[beg，end)区间中的数据拷贝赋值给本身。
                assign(n,elem);                     //将n个elem 拷贝赋值给本身。
                deque& operator=(const deque &deq); //重载等号操作符
                swap(deq);                          // 将deq与本身的元素互换
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void test()
                {
                    deque<int> d1;  //默认构造
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                //    deque<int> d2;
                //    d2.assign(d1.begin(),d1.end());
                //    d2.assign(5,3);
                //    d2 = d1;
                //    d2.swap(d1);
                }

                int main()
                {
                    test();
                    return 0;
                }
            3.3.3.3 deque 大小操作
                deque.size();       //返回容器中元素的个数
                deque.empty();      //判断容器是否为空
                deque.resize(num);  //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短,则未尾超出容器长度的元素被删除。
                deque.resize(num,elem);//重新指定容器的长度为num,若容器变长,则以elem 值填充新位置,如果容器变短、则未尾超出容器长度的元素被删除。

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//打印的是什么类型，就传什么类型参数
                {
                    cout << a << endl;
                }

                void test()
                {
                    deque<int> d1;  //默认构造
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    cout<< d1.size() <<endl;    //deque只有大小，没有容量的说法。
                    if(!d1.empty())
                    {
                        cout << "不为空" << endl;
                    }
                    d1.resize(5);
                    cout<< d1.size() <<endl;
                    d1.resize(7,2);
                    cout<< d1.size() <<endl;

                    for_each(d1.begin(),d1.end(),print);
                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.4 deque 双端插入和删除操作
                push_back(elem);    //在容器尾部添加一个数据
                push_front(elem);   //在容器头部插入一个数据
                pop_back();         //删除容器最后一个数据
                pop_front();        //删除容器第一个数据

            例：
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <deque>
                    #include <algorithm>
                    using namespace std;

                    void print(int a)//打印的是什么类型，就传什么类型参数
                    {
                        cout << a << endl;
                    }

                    void test()
                    {
                        deque<int> d1;
                        //头插
                        d1.push_back(1);
                        d1.push_back(2);
                        d1.push_back(3);
                        //尾插
                        d1.push_front(4);
                        d1.push_front(5);
                        d1.push_front(6);
                        for_each(d1.begin(),d1.end(),print);

                        //尾删
                        d1.pop_back();
                        //头删
                        d1.pop_front();

                        for_each(d1.begin(),d1.end(),print);

                    }

            3.3.3.5 deque 数据存取
                at(idx);//返回索引idx 所指的数据，如果idx 越界，抛出out_of_range。
                operator[];//返回索引idx 所指的数据，如果idx 越界，不抛出异常，直接出错。
                front();//返回第一个数据。
                back();//返回最后一个数

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//打印的是什么类型，就传什么类型参数
                {
                    cout << a << endl;
                }

                void test()
                {
                    deque<int> d1;
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    cout << d1.at(2) << endl;
                    d1[2] = 10;
                    cout << d1.front() << endl;
                    cout << d1.back() << endl;

                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.6 deque 插入操作
                insert(pos,elem);//在pos 位置插入一个elem 元素的拷贝，返回新数据的位置,
                insert(pos,n,elem);//在pos 位置插入n个elem 数据，无返回值。
                insert(pos,beg,end);//在pos 位置插入[beg,end)区间的数据，无返回值。

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//打印的是什么类型，就传什么类型参数
                {
                    cout << a << endl;
                }

                void test()
                {
                    deque<int> d1;
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    cout << d1.at(2) << endl;

                    d1.insert(d1.begin()+1,10); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)
                    d1.insert(d1.begin()+1,3,2); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)
                    d1.insert(d1.begin()+1,10); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)

                    for_each(d1.begin(),d1.end(),print);

                    deque<int> d2;
                    d2.insert(d2.begin(),d1.begin(),d1.begin());
                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.7 deque 删除操作
                clear();//移除容器的所有数据
                erase(beg,end);//刷除[beg,end)区间的数据，返回下一个数据的位置
                erase(pos);//删除pos 位置的数据，返回下一个数据的位置

            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//打印的是什么类型，就传什么类型参数
                {
                    cout << a << endl;
                }
                void test()
                {
                    deque<int> d1;

                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);
                    d1.push_back(4);
                    d1.push_back(5);
                    d1.push_back(6);

                    //尾删
                    d1.pop_back();
                    //头删
                    d1.pop_front();
                    //全删
                    d1.clear();
                    //删区间
                    d1.erase(d1.begin()+2,d1.end());
                    //删某一个
                    d1.erase(d1.begin()+2);
                    for_each(d1.begin(),d1.end(),print);
                }

                int main()
                {
                    test();
                    return 0;
                }
            3.3.3.8 案例(作业)
                有5名选手:选手ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
                1.创建五名选手，放到vector中
                2.遍历vector 容器，取出来每一个选手，执行for 循环，可以把10 个评分打分存到deque 容器中
                3.sort 算法对 deque 容器中分数排序,pop_back pop_front 去除最高和最低分
                4.deque 容器遍历一遍，累加分数，累加分数/d.size()
                5.person.score=平均分
            例：
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                //1.定义一个选手类
                class Player
                {
                public:
                    //无参构造
                    Player(){}
                    //有参构造
                    Player(string name,double score)
                    {
                        this->name = name;
                        this->score= score;
                    }
                    string name;
                    double score;
                };

                void print_player(vector<Player> &v)
                {
                    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
                    {
                        cout << it->name << " " << it->score << endl;
                    }
                }

                void start_play(vector<Player> &v)      //v是容器
                {
                    srand((unsigned int)time(NULL));//生成随机数，赋值时间种。

                    //创建 临时deque容器，便于操作
                    deque<int> d;

                    //v是容器,it是容器指针(迭代器)，it的指向是 Player,所以it访问Player成员时，应当是使用->。
                    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
                    {
                        //得到一个deque容器，把生成的10个随机数装进deque容器。
                        for(int i = 0;i < 10;i++)
                        {
                            d.push_back(60+rand()%41);
                        }

                        //对deque容器进行操作，去除最高和最低分
                        sort(d.begin(),d.end());//小->大
                        d.pop_back();   //尾删
                        d.pop_front();  //首删

                        int sum = 0;

                //        for(int i = 0;i<d.size();i++)
                //        {
                //            sum += d[i];
                //        }
                        //遍历deque容器，并求总和
                        for(deque<int>::iterator it1 = d.begin();it1 != d.end();it1++)
                        {
                            sum += *it1;
                        }
                        //求平均
                        int aver = sum / d.size();
                        //将平均值赋值到： it迭代器 指向的  Player对象里面的score成员变量
                        //注意：v是容器,it是容器指针(迭代器)，it的指向是 Player,所以it访问Player成员时，应当是使用->。
                        it->score = aver;
                        d.clear();
                    }
                }

                void Init_Player(vector<Player> &v)
                {
                    string str = "ABCDE";
                    for(int i = 0;i < 5;i++)
                    {
                        string strname(1,str[i]);   //strname = 'A' 0 'B' 0
                        Player tmp(strname,0);  //创建一个对象，传名字 传初始化值0
                        v.push_back(tmp);       //把对象放到容器内
                    }
                }

                int main()
                {
                    //2.定义一个vector容器v用来存取选手
                    vector<Player> v;
                    //3.初始化选手：给选手名字分数赋值。,参数为容器引用
                    Init_Player(v);
                    //遍历打印
                    print_player(v);
                    //开始比赛，
                    start_play(v);
                    print_player(v);
                    return 0;
                }
*/
//4章 算法
/*
    4.1 函数对象
        重载函数调用操作符的类，其 对象 常称为 函数对象(functionobject)，
            即: 它们是行为类似函数的对象，也叫仿函数(functor),其实就是重载“()"操作符，使得类对象可以像函数那样调用。
    注意:
        1.函数对象(仿函数)是一个类，不是一个函数。
        2.函数对象(仿函数)重载了"()"操作符 使得它可以像函数一样调用。

    分类:假定某个类有一个重载的 operator()，而且重载的 operator()要求获取一个参数，我们就将这个类称为"一元仿函数”(unaryfunctor);
        相反，如果重载的 operator()要求获取两个参数，就将这个类称为“二元仿函数”(binany functor)

        函数对象的作用主要是什么?
        STL提供的算法往往都有两个版本，其中一个版本表现出最常用的某种运算。
        另一版本 则允许用户通过template 参数的形式来指定所要采取的策略。

    例：

            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            #include <stdlib.h>
            #include <vector>
            #include <deque>
            #include <algorithm>
            using namespace std;

            //函数对象
            class Myadd
            {
            public:
                int operator() (int a,int b)
                {
                    return a+b;
                }
            };

            void print(int a)
            {
                cout << a << endl;
            }

            class Print
            {
            public:
                void operator()(int a)
                {
                    cout << a << endl;
                }
            };

            bool compare(int a,int b)
            {
                return a > b;
            }

            class Compare
            {
            public:
                bool operator()(int a, int b)
                {
                    return a > b ;
                }
            };


            //函数对象在容器里面怎么使用？
            void test1()
            {
                vector<int> v;
                v.push_back(1);
                v.push_back(3);
                v.push_back(2);
                v.push_back(5);

                //排序传函数
                sort(v.begin(),v.end(),compare);
                //排序传对象
                sort(v.begin(),v.end(),Compare());

                //传函数
                for_each(v.begin(),v.end(),print);

                //这里传的必须是匿名对象Print()。
                for_each(v.begin(),v.end(),Print());//传匿名对象Print(),
            //    //这里实质上是：
            //    void For_each unchecked( InIt _First, InIt _Last,Fnl& _Func)
            //    {
            //        for(;_First != Last; ++First)
            //            _Func (* First);      //由于重载了operator() 函数，因此，他直接引用调用我们的匿名对象然后使用重载的(),把参数直接传进来。
            //    }

            }
            void test()
            {
                Myadd p;
                cout << p(2, 3) << endl;
                cout << Myadd()(4, 5) << endl;
            }
            int main()
            {
                test1();
                return 0;
            }

    4.2 谓词
        谓词 是指 普通函数 或 重载的 operator() 返回值是 bool类型的函数对象(仿函数)。
        如果 operator 接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。
    例：

        #define _CRT_SECURE_NO_WARNINGS
        #include <iostream>
        #include <string.h>
        #include <string>
        #include <stdlib.h>
        #include <vector>
        #include <deque>
        #include <algorithm>
        using namespace std;

        class Print
        {
        public:
            void operator()(int a)  //类内重载一元谓词
            {
                cout << a << endl;
            }
        };

        class Compare
        {
        public:
            bool operator()(int a, int b)   //类内重载二元谓词
            {
                return a > b ;
            }
        };
        bool greater2(int a)    //普通函数 一元谓词
        {
            return a > 2;
        }
        void test()
        {
            vector<int> v;
            v.push_back(1);
            v.push_back(3);
            v.push_back(2);
            v.push_back(5);

            vector<int>::iterator it = find_if(v.begin(),v.end(),greater2);
            if(it != v.end())
            {
                cout << *it << endl;
            }
        //    //排序传对象
        //    sort(v.begin(),v.end(),Compare());
        //    //这里传的必须是匿名对象Print()。
        //    for_each(v.begin(),v.end(),Print());//传匿名对象Print(),

        }
        int main()
        {
            test();
            return 0;
        }

    4.3 内建函数对象
        STL内建(自带)了一些函数对象。
            分为:算数类函数对象,关系运算类函数对象，逻辑运算类仿函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以产生无名的临时对象来履行函数功能。
            使用内建的数对象，需要引入头文件 #include <functional>。

        6个算数类函数对象,除了negate是一元运算，其他都是二元运算。
            template<class T>T plus<T>              //加法仿函数
            template<class T>T minus<T>             //减法仿函数
            template<class T>T multiplies<T>        //乘法仿函数
            template<class T>T divides<T>           //除法仿函数
            template<class T>T modulus<T>           //取模仿函数
            template<class T>T negate<T>            //取反仿函数

        6个关系运算类函数对象,每一种都是二元运算。
            template<class T> bool equal_to<T>      //等于
            template<class T> bool not_equal_to<T>  //不等于
            template<class T> bool greater<T>       //大于
            template<class T> bool greater_equal<T> //大于等于
            template<class T> bool less<T>          //小于
            template<class T> bool less_equal<T>    //小子等于

        逻辑运算类运算函数,not为一元运算，其余为二元运算。
            template<class T> bool logical_and<T>   //逻辑与
            template<class T> bool logical_or<T>    //逻辑或
            template<class T> bool logical_not<T>   //逻辑非

        内建函数对象举例:

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                #include <functional>
                using namespace std;

                //negate<int> p; 实质：
                //template<class T>
                //class negate
                //{
                //public:
                //    T operator() (T a)
                //    {
                //        return a的反函数
                //    }
                //}

                void test()
                {
                    //取反
                    negate<int> p;  //定义一个函数对象p
                    cout << p(5) << endl;
                    cout << negate<int>() (5) << endl;

                    //加法
                    cout << plus<int>() (4,5) << endl;

                    vector<int> v;
                    v.push_back(1);
                    v.push_back(3);
                    v.push_back(2);
                    v.push_back(5);
                    //大于排序
                    sort(v.begin(),v.end(),greater<int>());
                    //小于排序
                    sort(v.begin(),v.end(),less<int>());

                }

                int main()
                {
                    test();
                    return 0;
                }

    4.4 适配器
        用来适配参数，扩展参数接口，一般结合仿函数一起使用。
        4.4.1 函数对象适配器

            详情见代码编写步骤的注释
        例：
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            #include <stdlib.h>
            #include <vector>
            #include <deque>
            #include <algorithm>
            #include <functional>
            using namespace std;

            void print(int a) { cout << a << endl; }
            //class Print
            //{
            //public:
            //    void operator() (int a)
            //    {
            //        cout << a << endl;
            //    }
            //};

            //1.现在，想让for_each在打印的时候，传一个a和 num到对象函数里面,则需要将传给num的值与Print()这个匿名对象进行绑定。
            //3.继承，继承又分为一元继承和二元继承。由于operator有两个参数，因此是二元继承。

            //4.一元继承：unary_function<参数1，返回值类型>
            //5.二元继承：public binary_function<参数1,参数2,返回值类型>


            class Print:public binary_function<int,int,void>
            {
            public:
                //6. 在operator()() 后面加const。
                void operator() (int a,int num)const
                {
                    cout << a<< " " << num << endl;
                    cout << a + num << endl;
                }
            };
            void test()
            {
                vector<int> v;
                v.push_back(1);
                v.push_back(2);
                v.push_back(3);
                v.push_back(4);

                for_each(v.begin(),v.end(),print);
                //2.方法一、绑定参数 bind2nd    这种方法 200传给的num
            //    for_each(v.begin(),v.end(),bind2nd(Print(),200));

                //7.方法二、绑定参数 bind1st    这种方法 200传给的a
                for_each(v.begin(),v.end(),bind1st(Print(),200));
            }

            int main()
            {
                test();
                return 0;
            }

*/

//笔记区
//############################################################################
//代码区

//迭代器的初次使用：
//迭代器指向元素为int类型
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//STL 中的容器 算法 迭代器

void test()
{

    //vector：容器，容器一定义就是一个数组，这个数组是动态数组，可以随容量可增可减。
    //容器可以认为是一个类，以类模板方式去定义，类型由我们给定
    vector<int> v;//STL 中的标准容器之一：动态数组（用vector这个类定义一个对象v（对象v是一个动态数组），对象的每一个元素的类型为int）

    //这个类提供了 对这个数组操作的接口，如插入，尾插。
    //v.push_back() 就是尾插
    v.push_back(2);//vector 容器提供的插入数据的方法
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);

    //迭代器

    //若想要遍历容器v的每一个元素，需要拿到指向首个元素的指针，也就是指向首元素的迭代器。
    //v.begin()   开始迭代器：获得指向首元素的迭代器
    //v.end()     结束迭代器：获取指向最后一个元素的下一个元素 的 迭代器（指针））
    //迭代器的类型： vector<int>::iterator
    vector<int>::iterator it_start = v.begin(); //vector 容器提供了 begin()方法 返回指向第一个元素的迭代器
    vector<int>::iterator it_end   = v.end();   //vector 容器提供了   end()方法 返回指向最后一个元素下一个位置的迭代器

    //通过迭代器遍历
    for(;it_start != it_end;it_start++)
    {
        //对迭代器解引用，取得该空间的内容
        cout << *it_start << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//迭代器指向元素为 自定义类型
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
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

void print_Person(Person &p)
{
    cout << p.age << endl;
}
void test()
{
    Person p1(1);
    Person p2(2);
    Person p3(3);
    Person p4(4);

    vector<Person> v;

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it_start = v.begin();
    vector<Person>::iterator it_end   = v.end();

    for(;it_start != it_end;it_start++)
    {
       print_Person(*it_start);
    }

}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//迭代器指向的是一个容器
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    //1.定义小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    //2.小容器插入数据
    for(int i = 0;i<3;i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+100);
    }

    //容器 嵌套 容器，v是大容器，容器里面是小容器。
    //3.定义大容器
    vector< vector<int> > v;

    //4.大容器插入小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //it_start 指向的是一个 vector<int> 的小容器 ，*it_start == vector<int>
    //(*it_start).begin() 指向小容器的首元素。
    //5.遍历
    vector<vector<int>>::iterator it_start = v.begin() ;//获得的是容器的首元素地址
    vector<vector<int>>::iterator it_end   = v.end() ;

    for(;it_start != it_end;it_start++)
    {
        //*it_start 得到小容器
        vector<int>::iterator itl_start = (*it_start).begin();
        vector<int>::iterator itl_end   = (*it_start).end();
        for(;itl_start != itl_end;itl_start++)
        {
            cout << *itl_start <<endl;
        }
    }
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string容器的构造函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//string的基本 赋值 操作
void test()
{
    string str("helloworld");
    string str1("heihei");
    str = "hehe";               //赋值 char*字符串
    cout << str << endl;
    str = str1;                 //赋值 &对象
    cout << str << endl;
    str = 'c';                  //赋值 字符
    cout << str << endl;

    str.assign("hello");        //方法赋值 字符串
    cout << str << endl;
    str.assign("jack",2);       //赋值字符串的两个
    cout << str << endl;
    str.assign(str1);           //方法赋值 对象
    cout << str << endl;
    str.assign(5,'c');          //赋值 5个c给str
    cout << str << endl;
    str.assign("helloworld",0,5);
    cout << str << endl;

//    hehe
//    heihei
//    c
//    hello
//    ja
//    heihei
//    ccccc
//    hello
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string c存取字符操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
void test()
{
    string str("helloworld");
    cout << str[4] << endl;
    str[4] = 'c';

    cout << str.at(4) << endl;
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 的拼接
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    string str1("helloworld");
    string str2("123456");

    str1 += str2;
    str1 += "hehe";
    str1 += 'c';

    str1.append("world");
    str1.append("world",3);
    str1.append(str2);
    str1.append(str2,1,3);
    str1.append(5,'c');
    cout << str1 << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 查找 和 替换
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    string str("helrloworld");
    string str1("wor");
    cout << str.find(str1) << endl;
    cout << str.find("wor") << endl;
    cout << str.find("world",0,2) << endl;
    cout << str.find('o') << endl;

    cout << str.rfind("rl") << endl;
    str.replace(2,4,str1);
    cout << str << endl;

}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 比较操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    string str1("hello");
    string str2("world");
    int ret = str1.compare(str2);
    ret = str1.compare("hello");
    if(ret > 0)
    {
        cout << "str大" << endl;
    }
    else if(ret < 0)
    {
        cout << "str小" << endl; //str1 比 str2小
    }
    else
    {
        cout << "相等" << endl;
    }
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 的字串
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    string str1("helloworld");
    string str = str1.substr(4,3);
    cout << str << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 的插入和删除
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    //第二个位置插入kkk
    string str("helloworld");
    string str2("hehe");
//    str.insert(2,"kkk");

    //插字符串
//    str.insert(2,str2);
//    cout << str << endl;

    //插字符:位置2插10个r
//    str.insert(2,10,'r');
//    cout << str << endl;

    //删除
    //从第三个位置，删除3个
    str.erase(3,3);
    cout << str << endl;

}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string 和 c-style 字符串转换
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    string str("hello");
    str = "world";          //1.可以赋值，调用opreator=(char *)

    char *s = NULL;
//    s = str;          //2.不能赋值，因为s是char*，
    //3.但string里面有c_str()方法，返回的是const char *
//    str.c_str();    //返回const char *
    //4.只需要去const即可。
    s = const_cast<char *> (str.c_str());
    cout << s <<endl;

}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 容器的迭代器
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//vector迭代器
void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it_start = v.begin();//iterator 迭代器
    vector<int>::iterator it_end   = v.end();

    vector<int>::reverse_iterator ri_start = v.rbegin();
    vector<int>::reverse_iterator ri_end   = v.rend();

    for(;it_start != it_end;it_start++)
    {
        cout << *it_start << " ";
    }
    cout << endl;

    for(;ri_start != ri_end;ri_start++)
    {
        cout << *ri_start << " ";
    }
    cout << endl;

}

//空间配置
void test1()
{
    vector<int> v;
    for(int i = 0; i< 100;i++)
    {
        v.push_back(i);
        cout << v.capacity() << endl;
    }
}
int main()
{
//    test();
    test1();
    return 0;
}
*/
//#######################################################
//vector 的构造函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//vector<T> v;//采用模板实现类实现，默认构造函数
//vector(v.begin()，v.end());//将v[begin()，end())区间中的元素拷贝给本身
//vector(n，elem);//构造函数将n个elem拷贝给本身
//vector(const vector &vec);//拷贝构造函数。

void print(int a)
{
    cout << a <<endl;
}
void test()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    //构造
    vector<int> v2(v1.begin()+1,v1.end());
    vector<int> v3(4,5);    //存4个5
    vector<int> v4(v1);

//    for_each(v2.begin(),v2.end(),print);    //for_each的头文件是<algorithm>.函数的使用方式如前。
    for_each(v3.begin(),v3.end(),print);    //5555
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 的常用赋值操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//assign(begin,end);                      //将[beg，end)区间中的数据拷贝赋值给本身
//assign(n,elem);                         //将n个elem 接贝赋值给本身。
//vector& operator=(const vector &vec);   //重载等号操作行
//swap(vec);                              // 将vec 与本身的元素互换。
void print(int a)
{
    cout << a <<endl;
}

void test()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2;
    v2.push_back(9);
    v2.push_back(8);
    v2.push_back(7);
    v2.push_back(6);
//    v2.assign(v1.begin()+1,v1.end());
//    v2.assign(10,5);
//    v2 = v1;
    v2.swap(v1);    //这个交换只是把v1和 v2的指针进行了交换。
    for_each(v1.begin(),v1.end(),print);
    cout << "-----" <<endl;
    for_each(v2.begin(),v2.end(),print);
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 的大小操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//size();                                 //返回容器中元素的个数
//empty();                                //判断容器是否为空
//resize(int num);                        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短,则未尾超出容器长度的元素被删除。
//resize(int num,elem);                   //重新指定容器的长度为num，若容器变长，则以elem 值填充新位置。如果容器变短、则未尾超出容器长>度的元素被删除。
//capacity();                             //容器的容量
//reserve(int len);                       //容器预留len 个元素长度，预留位置不初始化，无素不可访问。

void print(int a)
{
    cout << a <<endl;
}

void test()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << v1.size() << endl;          //5
    cout << v1.capacity() << endl;      //8

//    v1.resize(3);     // 1 2 3
//    v1.resize(10);      //1 2 3 0 0 0 ...默认变长的填充值为0
    v1.resize(10,2);    //默认变长的填充值为2

    for_each(v1.begin(),v1.end(),print);

    if(!v1.empty())//判断是否为空
    {
        cout << "不为空" << endl;
    }


    vector<int> v2;
    //若已知需要 一个确定的大小（如1万），则可以直接选择预留1万的空间，而不是每增加一个元素就重新找匹配的空间存放。
    v2.reserve(100);    //预设定容量
    cout << v2.size() << endl;      //0
    cout << v2.capacity() << endl;  //100，事先给容量扩展到100，
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 数据存取操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//at(int idx);//返回索引idx 所指的数据，如果idx 越界，抛出out_of_range 异常。
//operator[];//返回索引idx 所指的数据，越界时，还行直接报错
//front();//返回容器中第一个数据元素
//back();//返回容器中最后一个数据元素
void print(int a)
{
    cout << a <<endl;
}

void test()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << v1.at(2) << endl;
    cout << v1[2] << endl;
    cout << v1.front() << endl;//返回第一个元素
    cout << v1.back() << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 插入和删除
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//insert(const_iterator pos, int count,ele);//迭代器指问位置pos 插入count 个元素ele.
//push_back(ele);//尾部插入元素ele
//pop_back();//删除最后一个元素
//erase(const iterator start, const iterator end);//删除选代器从start 到end 之间的元素
//erase(const iterator pos);//删除选代器指向的元素
//cLear();//删除容器中所有元亲

void print(int a)
{
    cout << a <<endl;
}

void test()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

//    v1.pop_back();//尾删
    v1.erase(v1.begin()+3,v1.end());

    v1.insert(v1.begin()+2,3,9);    //在+2位置插入3个9
    v1.erase(v1.begin()+3);         //删除指定元素
    for_each(v1.begin(),v1.end(),print);
    v1.clear(); //删除所有元素
    for_each(v1.begin(),v1.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//swap 收缩空间
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void print(int a)
{
    cout << a <<endl;
}

void test()
{
    vector<int> v1;
    for(int i=0;i<10000;i++)
    {
        v1.push_back(i);
    }
    cout << v1.size() <<" "<< v1.capacity()<< endl;
    v1.resize(10);//size变成10了，容量不变，会浪费很多1空间
    cout << v1.size() <<" "<< v1.capacity()<< endl;
    vector<int>(v1).swap(v1); //创建匿名的容量对象,并且用v1初始化（v1有几个元素，匿名对象就开辟对于大小的空间），在将该初始化空间同v1交换。
    cout << v1.size() <<" "<< v1.capacity()<< endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 预测开辟次数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    vector<int> v1;
    int *p = NULL;
    int count = 0;
    //由于每一次重新申请空间，首元素地址都会改变，那么只需要计数首元素地址改变的次数即可。
    for(int i=0;i<10000;i++)
    {
        v1.push_back(i);
        if(p != &v1[0])
        {
            count++;
            p = &v1[0];
        }
    }
    cout << count << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector 排序
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
void print(int a)
{
    cout << a <<endl;
}

bool compare(int a,int b)
{
    return a>b;
}
void test()
{

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(4);

//    sort(v1.begin(),v1.end());//从小到大排序
    sort(v1.begin(),v1.end(),compare);//a>b是从大到小排序。a < b是从小到大
    //algorithm里面得到sort这个函数其实是重载的，还可以填写一个回调函数，
    for_each(v1.begin(),v1.end(),print);
}

//如何排序 自定义对象？？
class Person
{
public:
    Person(int age,string s)
    {
        this->age = age;
        this->name = s;
    }
    int age;
    string name;
};

void print1(Person &p)
{
    cout << p.age << " " << p.name <<endl;
}
bool compare1(Person &p1,Person &p2)
{
//    return p1.age > p2.age;   //从大到小
    return p1.age < p2.age;
}
void test1()
{
    vector<Person> v;
    Person p1(10,"马超");
    Person p2(40,"黄忠");
    Person p3(50,"安其拉");
    Person p4(20,"貂蝉");
    Person p5(30,"廉颇");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for_each(v.begin(),v.end(),print1);

    //排序：
    sort(v.begin(),v.end(),compare1);
    for_each(v.begin(),v.end(),print1);


}
int main()
{
    test1();
    return 0;
}
*/
//#######################################################
//deque容器api
//deque容器的构造函数
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//deque<T> deqT; //默认构造形式
//deque(beg,end); //构造函数将[beg,end)区间中的元素拷贝给本身。
//deque(n，elem);//构造函将n 个elem 拷贝给本身,
//deque(const deque &deq);//拷贝构造函数。
void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}
void test()
{
    deque<int> d1;  //默认构造
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    deque<int> d2(d1); //用d1来初始化d2
    deque<int> d3(d1.begin(),d1.end()); //用d1的开始到结束初始化d3
    deque<int> d4(10,8);                //10个8

    for_each(d4.begin(),d4.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的赋值操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void test()
{
    deque<int> d1;  //默认构造
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

//    deque<int> d2;
//    d2.assign(d1.begin(),d1.end());
//    d2.assign(5,3);
//    d2 = d1;
//    d2.swap(d1);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的大小操作
/*
//deque.size();       //返回容器中元素的个数
//deque.empty();      //判断容器是否为空
//deque.resize(num);  //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短,则未尾超出容器长度的元素被删除。
//deque.resize(num,elem);//重新指定容器的长度为num,若容器变长,则以elem 值填充新位置,如果容器变短、则未尾超出容器长度的元素被删除。

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}

void test()
{
    deque<int> d1;  //默认构造
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    cout<< d1.size() <<endl;    //deque只有大小，没有容量的说法。
    if(!d1.empty())
    {
        cout << "不为空" << endl;
    }
    d1.resize(5);
    cout<< d1.size() <<endl;
    d1.resize(7,2);
    cout<< d1.size() <<endl;

    for_each(d1.begin(),d1.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的双端删除操作
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}

//push_back(elem);    //在容器尾部添加一个数据
//push_front(elem);   //在容器头部插入一个数据
//pop_back();         //删除容器最后一个数据
//pop_front();        //删除容器第一个数据

void test()
{
    deque<int> d1;
    //头插
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    //尾插
    d1.push_front(4);
    d1.push_front(5);
    d1.push_front(6);
    for_each(d1.begin(),d1.end(),print);

    //尾删
    d1.pop_back();
    //头删
    d1.pop_front();

    for_each(d1.begin(),d1.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的存取操作
/*

//at(idx);//返回索引idx 所指的数据，如果idx 越界，抛出out_of_range。
//operator[];//返回索引idx 所指的数据，如果idx 越界，不抛出异常，直接出错。
//front();//返回第一个数据。
//back();//返回最后一个数

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}

void test()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    cout << d1.at(2) << endl;
    d1[2] = 10;
    cout << d1.front() << endl;
    cout << d1.back() << endl;

}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的插入操作
/*
//insert(pos,elem);//在pos 位置插入一个elem 元素的拷贝，返回新数据的位置,pos是传一个迭代器
//insert(pos,n,elem);//在pos 位置插入n个elem 数据，无返回值。
//insert(pos,beg,end);//在pos 位置插入[beg,end)区间的数据，无返回值。

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}

void test()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    cout << d1.at(2) << endl;

    d1.insert(d1.begin()+1,10); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)
    d1.insert(d1.begin()+1,3,2); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)
    d1.insert(d1.begin()+1,10); // 需要的是 迭代器//insert(iterator __position, const value_type& __x)

    for_each(d1.begin(),d1.end(),print);

    deque<int> d2;
    d2.insert(d2.begin(),d1.begin(),d1.begin());
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque容器的删除
/*
//clear();//移除容器的所有数据
//erase(beg,end);//刷除[beg,end)区间的数据，返回下一个数据的位置
//erase(pos);//删除pos 位置的数据，返回下一个数据的位置
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//打印的是什么类型，就传什么类型参数
{
    cout << a << endl;
}
void test()
{
    deque<int> d1;

    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(4);
    d1.push_back(5);
    d1.push_back(6);

    //尾删
    d1.pop_back();
    //头删
    d1.pop_front();
    //全删
    d1.clear();
    //删区间
    d1.erase(d1.begin()+2,d1.end());
    //删某一个
    d1.erase(d1.begin()+2);
    for_each(d1.begin(),d1.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//案例:选手ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//1.定义一个选手类
class Player
{
public:
    //无参构造
    Player(){}
    //有参构造
    Player(string name,double score)
    {
        this->name = name;
        this->score= score;
    }
    string name;
    double score;
};

void print_player(vector<Player> &v)
{
    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
    {
        cout << it->name << " " << it->score << endl;
    }
}

void start_play(vector<Player> &v)      //v是容器
{
    srand((unsigned int)time(NULL));//生成随机数，赋值时间种。

    //创建 临时deque容器，便于操作
    deque<int> d;

    //v是容器,it是容器指针(迭代器)，it的指向是 Player,所以it访问Player成员时，应当是使用->。
    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
    {
        //得到一个deque容器，把生成的10个随机数装进deque容器。
        for(int i = 0;i < 10;i++)
        {
            d.push_back(60+rand()%41);
        }

        //对deque容器进行操作，去除最高和最低分
        sort(d.begin(),d.end());//小->大
        d.pop_back();   //尾删
        d.pop_front();  //首删

        int sum = 0;

//        for(int i = 0;i<d.size();i++)
//        {
//            sum += d[i];
//        }
        //遍历deque容器，并求总和
        for(deque<int>::iterator it1 = d.begin();it1 != d.end();it1++)
        {
            sum += *it1;
        }
        //求平均
        int aver = sum / d.size();
        //将平均值赋值到： it迭代器 指向的  Player对象里面的score成员变量
        //注意：v是容器,it是容器指针(迭代器)，it的指向是 Player,所以it访问Player成员时，应当是使用->。
        it->score = aver;
        d.clear();
    }
}

void Init_Player(vector<Player> &v)
{
    string str = "ABCDE";
    for(int i = 0;i < 5;i++)
    {
        string strname(1,str[i]);   //strname = 'A' 0 'B' 0
        Player tmp(strname,0);  //创建一个对象，传名字 传初始化值0
        v.push_back(tmp);       //把对象放到容器内
    }
}

int main()
{
    //2.定义一个vector容器v用来存取选手
    vector<Player> v;
    //3.初始化选手：给选手名字分数赋值。,参数为容器引用
    Init_Player(v);
    //遍历打印
    print_player(v);
    //开始比赛，
    start_play(v);
    print_player(v);
    return 0;
}
*/
//#######################################################
//deque容器的删除
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//函数对象
class Myadd
{
public:
    int operator() (int a,int b)
    {
        return a+b;
    }
};

void print(int a)
{
    cout << a << endl;
}

class Print
{
public:
    void operator()(int a)
    {
        cout << a << endl;
    }
};

bool compare(int a,int b)
{
    return a > b;
}

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b ;
    }
};


//函数对象在容器里面怎么使用？
void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    //排序传函数
    sort(v.begin(),v.end(),compare);
    //排序传对象
    sort(v.begin(),v.end(),Compare());

    //传函数
    for_each(v.begin(),v.end(),print);

    //这里传的必须是匿名对象Print()。
    for_each(v.begin(),v.end(),Print());//传匿名对象Print(),
//    //这里实质上是：
//    void For_each unchecked( InIt _First, InIt _Last,Fnl& _Func)
//    {
//        for(;_First != Last; ++First)
//            _Func (* First);      //由于重载了operator() 函数，因此，他直接引用调用我们的匿名对象然后使用重载的(),把参数直接传进来。
//    }

}
void test()
{
    Myadd p;
    cout << p(2, 3) << endl;
    cout << Myadd()(4, 5) << endl;
}
int main()
{
    test1();
    return 0;
}
*/
//#######################################################
//谓词
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Print
{
public:
    void operator()(int a)  //类内重载一元谓词
    {
        cout << a << endl;
    }
};

class Compare
{
public:
    bool operator()(int a, int b)   //类内重载二元谓词
    {
        return a > b ;
    }
};
bool greater2(int a)    //普通函数 一元谓词
{
    return a > 2;
}
void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    vector<int>::iterator it = find_if(v.begin(),v.end(),greater2);
    if(it != v.end())
    {
        cout << *it << endl;
    }
//    //排序传对象
//    sort(v.begin(),v.end(),Compare());
//    //这里传的必须是匿名对象Print()。
//    for_each(v.begin(),v.end(),Print());//传匿名对象Print(),

}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//内建函数对象
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;

//negate<int> p; 实质：
//template<class T>
//class negate
//{
//public:
//    T operator() (T a)
//    {
//        return a的反函数
//    }
//}

void test()
{
    //取反
    negate<int> p;  //定义一个函数对象p
    cout << p(5) << endl;
    cout << negate<int>() (5) << endl;

    //加法
    cout << plus<int>() (4,5) << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    //大于排序
    sort(v.begin(),v.end(),greater<int>());
    //小于排序
    sort(v.begin(),v.end(),less<int>());

}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//函数对象适配器
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;

void print(int a) { cout << a << endl; }
//class Print
//{
//public:
//    void operator() (int a)
//    {
//        cout << a << endl;
//    }
//};

//1.现在，想让for_each在打印的时候，传一个a和 num到对象函数里面,则需要将传给num的值与Print()这个匿名对象进行绑定。
//3.继承，继承又分为一元继承和二元继承。由于operator有两个参数，因此是二元继承。

//4.一元继承：unary_function<参数1，返回值类型>
//5.继承：public binary_function<参数1,参数2,返回值类型>


class Print:public binary_function<int,int,void>
{
public:
    //6. 在operator()() 后面加const。
    void operator() (int a,int num)const
    {
        cout << a<< " " << num << endl;
        cout << a + num << endl;
    }
};
void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for_each(v.begin(),v.end(),print);
    //2.方法一、绑定参数 bind2nd    这种方法 200传给的num
//    for_each(v.begin(),v.end(),bind2nd(Print(),200));

    //7.方法二、绑定参数 bind1st    这种方法 200传给的a
    for_each(v.begin(),v.end(),bind1st(Print(),200));
}

int main()
{
    test();
    return 0;
}
*/









