//1.�� STL����
/*
    ��1��STL����
    ���������������һֱϣ������һ�ֿ��ظ����õĶ������Լ�һ�ֵ��������"���ظ����õĶ���"�ķ���,�ó���Ա����Ѫ��ֹ����ʱ���Ǩ�ƣ������춯��������ɢ���Ӻ���(functions)�����(classes),������(function libraries)
    ����(class libraries)�������������ģ�黯��ƣ����������(object oriented)��Ϊ�ľ��Ǹ����Ե������������Ա��뽨����ĳ�ֱ�׼֮�ϡ���������໷���£����������������������ݽṹ(datastructures)���㷨(alkgorithm)��δ����һ�ױ�׼��
    ��������Ա���ȴ��´����ظ��Ĺ�������Ȼ��Ϊ�����ǰ���Ѿ���ɶ��Լ����ϲ�δӵ�еĳ�����룬�ⲻ����������Դ���˷ѣ�Ҳ�Ǵ�����ʹ�����Դ��

    Ϊ�˽������ݽṹ���㷨��һ�ױ�׼�����ҽ�������֮�����Ϲ�ϵ,���������ԵĶ����ԡ����ԡ�����������(�໥������,interoperability),������ STL��

        1.1 STL��������
            STL(Standard Template Library,��׼ģ���)���ǻ���ʵ���ҿ�����һϵ�������ͳ�ơ�
            ������Ҫ������c++�У�����������c++֮ǰ�ü����Ѿ����ںܳ�ʱ���ˡ�
            STL �ӹ����Ϸ�Ϊ:����(container)�㷨(algorithm)������(iterator),�������㷨֮��ͨ��ѡ���������޷����ӡ����㷨ͨ����������ָ�룩����������
            STL�������еĴ��붼������ ģ���� ���� ģ�庯��,����ȴ�ͳ���ɺ���������ɵĿ���˵�ṩ�˸��õĴ������û��ᡣ
            STL(Standard Template Library)��׼ģ���,������ c++��׼������������� STL ��ռ���� 80%���ϡ�

        1.2 STL����������
            STL�ṩ������������˴�֮�����������ã�����������ֱ���:�������㷨�����������º�����������(�����)���ռ���������    (��c�е����������顢�������С�����)

            ����:�������ݽṹ���� vector����̬���飩��list��������deque��˫�˲�������飩��set��������map��������,����������ݣ���ʵ�ֽǶ�������STL������һ�� class templatee������ģ�壩

            �㷨:���ֳ��õ��㷨����sort��find��copy��for_each����ʵ�ֵĽǶ�������STL�㷨��һ�� function tempalte������ģ�壩

            ������:�������������㷨֮�ʵĽ��ϼ�,������������,��ʵ�ֽǶ�����,��������һ�ֽ� operator*,operator->��operator++,operator--��ָ����ز����������ص� class template.���� STL�������������Լ�ר���ĵ�����,ֻ������������߲�֪����α����Լ���Ԫ�ء�ԭ��ָ��(native pointer)Ҳ��һ�ֵ�������

            �º�������������:��Ϊ���ƺ���������Ϊ�㷨��ĳ�ֲ��ԡ���ʵ�ֽǶ��������º�����һ��������operator()�� class ���� class template

            ������:һ������ �������� ���� �º��� �� ѡ�����ӿ� �Ķ�����

            ����������:����ռ������ �� ������ʵ�ֽǶȿ�����������һ�� ʵ���˶�̬�������� ���ռ�����ռ��ͷŵ� class tempalte.

            STL��������Ľ�����ϵ������ͨ������������ȡ�����ݴ洢���ʣ��㷨ͨ��ѡ�����洢�����е����ݣ��º�������Э���㷨��ɲ�ͬ�Ĳ��Եı仯���������������ηº�����

        �ܽ᣺
            * �������������ݵĿռ�ṹ vector queue deque set map list
            * �㷨���ض�����ⲽ�裺 sort find for_each ������
            * ������: ������һ��ָ��
            * �º�������������������operator()����
            * ���������������ηº����ģ�һ��������չ�����ӿڣ�
            * �ռ��������������ڴ�ռ������ �ͷ� ���� �ȡ�

        1.3 STL���ŵ�
            STL��C++��һ���֣���˲��ö��ⰲװʲô�������ڽ�����ı�����֮�ڡ�

            STL ��һ����Ҫ�����ǽ� ���� �� ���� ���롣���� �� ���������Թ����������ɿɶ��Ƶ��㷨���塣������������֮��䵱��ճ�ϼ�",��ʹ�㷨���Ժ�������������

            ����Ա���Բ���˼�� STL �����ʵ�ֹ��̣�ֻҪ�ܹ�Ȼ��ʹ��STL�� OK�ˡ��������ǾͿ��԰Ѿ������ڳ��򿪷��ı�ķ��档
        �ܽ᣺
            STL���и߿������ԣ������ܣ�����ֲ�ԣ���ƽ̨���ŵ㡣
                �߿�������:STL �м������еĴ��붼������ ģ���� �� ģ�溯�� �ķ�ʽʵ��,������ڴ�ͳ���ɺ���������ɵĿ���˵�ṩ�˸��õĴ������û��ᡣ����ģ���֪ʶ���Ѿ�����ҽ����ˡ�
                ������:�� map ���Ը�Ч�ش�ʮ������¼������ҳ�ָ���ļ�¼����Ϊmap �ǲ��ú�����ı���ʵ�ֵġ�
                ����ֲ��:������ĿA���� STL ��д��ģ�飬����ֱ����ֲ����Ŀ B�ϡ�
*/
//2.�� STL�������
/*
    2��. STL�������
        2.1 �������������ݵģ�������Ϊ�����ݽṹ��
            ����������֮��Ҳ��
            �о����ݵ��ض����з�ʽ�������� ���� �� ���� �� ��������Ŀ�ģ���һ��ѧ�����ǳ�Ϊ ���ݽṹ����ѧ��Ϣ�����רҵ���棬��������ֱ�ӹ�ϵ��ѧ�ƣ��������ݽṹ���㷨����������˵���κ��ض������ݽṹ����Ϊ��ʵ��ĳ���ض����㷨��

          * STL���� ���ǽ�������㷺��һЩ ���ݽṹ ʵ�ֳ�����
                * ���õ����ݽṹ:����(array),����(list),tree(��)��ջ(stack),����(queue),����(set),ӳ���(map).
                * ���������������е��������ԣ���Щ���ݷ�Ϊ ����ʽ���� �� ����ʽ�������֡�
                    ����ʽ������ÿ����һ�����ݶ��й̶���λ�� �������飩 ǿ�� ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ�ã�������ɾ�������Ĳ����ı����λ�á�Vector ������Deque ������List �����ȡ�
                    ����ʽ������λ�ò��̶����������� �������� �� �����Ե����ṹ����׼ȷ��˵�� �������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ��Ҳ����˵ Ԫ���������в�û�б���Ԫ����������ʱ���߼�˳�򡣹���ʽ������һ�������ص���:��ֵ�� ѡ��һ��ֵ ��Ϊ�ؼ��� key������ؼ��ֶ�ֵ�����������ã�������ҡ�Set/multiset ���� Map/multimap ����

            ��������Ƕ������!

        2.2 �㷨
            �㷨������֮�ⷨҲ��
            �����޵Ĳ��裬����߼�����ѧ�ϵ����⣬��һ��ѧ�����ǽ����㷨(Algorithms).

            ������ԣ���������д��ÿ��������һ���㷨�����е�ÿ������Ҳ����һ���㷨���Ͼ����Ƕ��������������С���߼��������ѧ���⡣

            STL��¼���㷨 ��������ѧ�ϵ�Ч�ܷ�����֤�����Ǽ��߸��ü�ֵ�ģ��������õ� ���򣬲��ҵȡ��ض����㷨���������ض������ݽṹ���㷨�����ݽṹ�ศ��ɡ�

          * �㷨��Ϊ:�ʱ��㷨�ͷ��ʱ��㷨��
                �ʱ��㷨:  ��ָ ��������� ����������ڵ�Ԫ�ص����ݡ����翽�����滻��ɾ����
                ���ʱ��㷨:��ָ ��������� ������������ڵ�Ԫ�ص����ݣ�������ҡ�����������Ѱ�Ҽ�ֵ�ȵ�

          * STL�ṩ�˺ܶ���㷨������ֻ��Ҫ�������Ȼ��ʹ�ü��ɣ���(ͷ�ļ�)����Ϊ��algorithm

        2.3 ������������ָ�����ã�˵���˿������Ϊ�����һ��ָ�룬����ָ���ֱ���װ����һ���࣬Ȼ��������������ָ��һ����ָ����ĳ��Ԫ�أ���ѹ��֧��ָ��++��--��
            ������(iterator)��һ�ֳ������Ƹ����ʵ���������в�û��ֱ�Ӷ�Ӧ����������ʵ���<>һ�����ṩ�� 23 �����ģʽ������������
            ���� iteratorģʽ��������:�ṩһ�ַ�����ʹ֮�ܹ� ����Ѱ�� ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ��

            �����������˼ά-STL�Ĺؼ����ڣ�STL������˼�����ڽ�����(container)���㷨(algorithms)�ֿ����˴˶�����ƣ������һ�����ż������Ǵ����һ�𡣴Ӽ����Ƕ��������������㷨�ķ��ͻ��������ѣ�
            c++�� class template �� function template �ɷֱ�ﵽĿ�꣬�����Ƴ������֮������õĽ��ż������Ǵ����⡣

            ������������

            ���������       �ṩ�����ݵ�ֻ������                                          ֻ����֧��++��==��!=
            ���������       �ṩ�����ݵ�ֻд����                                          ֻд��֧��++
            ǰ�������       �ṩ��д������������ǰ�ƽ�ѡ����                                ��д��֧��++��==��!=
            ˫�������       �ṩ��д������������ǰ��������                                ��д��֧��++��--��
            ������ʵ�����    �ṩ��д��������������Ծ�ķ�ʽ�����������������ݣ��ǹ�����ǿ�ĵ�����   ��д,֧��++��--��[n]��-n��<��<=��>��>=

            2.3.1 ������ָ��Ԫ��Ϊint����
                ������
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //STL �е����� �㷨 ������

                    void test()
                    {

                        //vector������������һ�������һ�����飬��������Ƕ�̬���飬���������������ɼ���
                        //����������Ϊ��һ���࣬����ģ�巽ʽȥ���壬���������Ǹ���
                        vector<int> v;//STL �еı�׼����֮һ����̬���飨��vector����ඨ��һ������v������v��һ����̬���飩�������ÿһ��Ԫ�ص�����Ϊint��

                        //������ṩ�� �������������Ľӿڣ�����룬β�塣
                        //v.push_back() ����β��
                        v.push_back(2);//vector �����ṩ�Ĳ������ݵķ���
                        v.push_back(4);
                        v.push_back(5);
                        v.push_back(3);

                        //������

                        //����Ҫ��������v��ÿһ��Ԫ�أ���Ҫ�õ�ָ���׸�Ԫ�ص�ָ�룬Ҳ����ָ����Ԫ�صĵ�������
                        //v.begin()   ��ʼ�����������ָ����Ԫ�صĵ�����
                        //v.end()     ��������������ȡָ�����һ��Ԫ�ص���һ��Ԫ�� �� ��������ָ�룩��
                        //�����������ͣ� vector<int>::iterator
                        vector<int>::iterator it_start = v.begin(); //vector �����ṩ�� begin()���� ����ָ���һ��Ԫ�صĵ�����
                        vector<int>::iterator it_end   = v.end();   //vector �����ṩ��   end()���� ����ָ�����һ��Ԫ����һ��λ�õĵ�����

                        //ͨ������������
                        for(;it_start != it_end;it_start++)
                        {
                            //�Ե����������ã�ȡ�øÿռ������
                            cout << *it_start << " ";
                        }
                        cout << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            2.3.2 ������ָ��Ԫ��Ϊ �Զ�������
                ������
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

            2.3.3 ������ָ�����һ������
                ����
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
                        //1.����С����
                        vector<int> v1;
                        vector<int> v2;
                        vector<int> v3;
                        //2.С������������
                        for(int i = 0;i<3;i++)
                        {
                            v1.push_back(i);
                            v2.push_back(i+10);
                            v3.push_back(i+100);
                        }

                        //���� Ƕ�� ������v�Ǵ�����������������С������
                        //3.���������
                        vector< vector<int> > v;

                        //4.����������С����
                        v.push_back(v1);
                        v.push_back(v2);
                        v.push_back(v3);

                        //it_start ָ�����һ�� vector<int> ��С���� ��*it_start == vector<int>
                        //(*it_start).begin() ָ��С��������Ԫ�ء�
                        //5.����
                        vector<vector<int>>::iterator it_start = v.begin() ;//��õ�����������Ԫ�ص�ַ
                        vector<vector<int>>::iterator it_end   = v.end() ;

                        for(;it_start != it_end;it_start++)
                        {
                            //*it_start �õ�С����
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
//3.1 string ����
/*
    3�� ��������
        3.1 string ����
            3.1.1 string ������������
                C����ַ���(�Կ��ַ���β���ַ�����)̫������ ��������,���ʺϴ����Ŀ���,����C++��׼�ⶨ����һ��string�࣬������ͷ�ļ���

                String�� C����ַ����Ա�:
                    u char*��һ��ָ�룬String ��һ����
                    string ��װ�� char����������ַ�������һ��char�͵�����
                    u string ��װ�˺ܶ�ʵ�õĳ�Ա����
                    ����find������copy��ɾ��delete �滻replace������insert
                    u ���ÿ����ڴ��ͷź�Խ��
                    string���� char*��������ڴ档ÿһ��string�ĸ��ƣ�ȡֵ���� string �ฺ��ά�������õ��ĸ���Խ���ȡֵԽ��ȡ��㷨

            �ܽ᣺
                string������һ���࣬�����������һ��ָ�룬ָ��ά����һ�����飬
                string�����ṩ��copy��find��insert��replace�ȹ��ܡ�

            3.1.2 string�����ĳ��ò���
                3.1.2.1 string ���캯��
                    string();/����һ���յ��ַ���: string str;
                    string(const string& str);//ʹ��һ��string �����ʼ����һ��string ����
                    string(const char*s);//ʹ���ַ���s��ʼ��
                    string(int n��char c);//ʹ��n���ַ�c ��ʼ�� v

                ����string�Ĺ��캯����
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



                3.1.2.2 string ���� ��ֵ ����
                    string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
                    string& operator=(const string &s);//���ַ���s ������ǰ���ַ���
                    string& operator=(char c);//�ַ� ��ֵ����ǰ���ַ���
                    string& assign(const char*s);//���ַ���s ������ǰ���ַ���
                    string& assign(const char *s,int n);//���ַ���s ��ǰn���ַ�������ǰ���ַ���
                    string& assign(const string &s);//���ַ���s������ǰ�ַ���
                    string& assign(int n��char c);//��n���ַ�c ������ǰ�ַ���
                    string& assign(const string &s, int start, int n);//��s ��start��ʼn���ַ� ��ֵ ���ַ���

                ����
                        #define _CRT_SECURE_NO_WARNINGS
                        #include <iostream>
                        #include <string.h>
                        #include <string>
                        #include <stdlib.h>
                        #include <vector>
                        #include <algorithm>
                        using namespace std;

                        //string�Ļ��� ��ֵ ����
                        void test()
                        {
                            string str("helloworld");
                            string str1("heihei");
                            str = "hehe";               //��ֵ char*�ַ���
                            cout << str << endl;
                            str = str1;                 //��ֵ &����
                            cout << str << endl;
                            str = 'c';                  //��ֵ �ַ�
                            cout << str << endl;

                            str.assign("hello");        //������ֵ �ַ���
                            cout << str << endl;
                            str.assign("jack",2);       //��ֵ�ַ���������
                            cout << str << endl;
                            str.assign(str1);           //������ֵ ����
                            cout << str << endl;
                            str.assign(5,'c');          //��ֵ 5��c��str
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

                3.1.2.3 string c��ȡ �ַ� ����
                    char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
                    char& at(int n);//ͨ��at ������ȡ�ַ�
                ����
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

            3.1.2.4 string ƴ�Ӳ���
                string& operator+=(const string& str);          //����+=������
                string& operator+=(const char*str);             //����+=������
                string& operator+=(const char c);               //����+=������
                string& append(const char*s);                   //���ַ���s ���ӵ���ǰ�ַ��� ��β
                string& append(const char*s,int n);             //���ַ���s�� ǰn���ַ� ���ӵ���ǰ�ַ�����β
                string& append(const string &s);                //ͬoperator+=()
                string& append(const string &s,int pos,int n);  //���ַ���s �д� pos ��ʼ�� n ���ַ����ӵ���ǰ�ַ�����β
                string& append(int n,char c);                   //�ڵ�ǰ�ַ�����β��� n���ַ�c

            ����
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

            3.1.2.5 string ���� �� �滻
                int find(const string& str,int pos =0)const;            //����str ��һ�γ���λ��,��pos ��ʼ����
                int find(const char*s,int pos=0)const;                  //����s ��һ�γ���λ��,��pos ��ʼ����
                int find(const char*s,int pos,int n)const;              //��pos λ�Ö���s ��ǰn ���ַ���һ��λ��
                int find(const char c,int pos=0)const;                  //�����ַ�c ��һ�γ���λ��
                int rfind(const string& str,int pos = npos)const;       //����str ���һ��λ��,��pos ��ʼ����
                int rfind(const char*s,int pos=npos)const;              //����s ���һ�γ���λ��,��pos ��ʼ����
                int rfind(const char*s,int pos,int n)const;             //��pos ����s ��ǰn ���ַ����һ��λ��
                int rfind(const char c,int pos=��)const;                //�����ַ�c ���һ�γ���λ��
                string& replace(int pos,int n,const string& str);      //�滻��pos ��ʼn ���ַ�Ϊ�ַ���str
                string& replace(int pos,int n,const char*s);           //�滻��pos ��ʼ��n ���ַ�Ϊ�ַ��� s

            ����
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

            3.1.2.6 string �Ƚϲ���

                compare ������ > ʱ ,����1��< ʱ���� -1��==ʱ����0��
                �Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳�֣���Խǰ���ԽС
                ��д��A ��Сд��a С��

                int compare(const string &s)const;  //���ַ���s �Ƚ�
                int compare(const char *s)const;    //���ַ���s �Ƚ�
            ����
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
                            cout << "str��" << endl;
                        }
                        else if(ret < 0)
                        {
                            cout << "strС" << endl; //str1 �� str2С
                        }
                        else
                        {
                            cout << "���" << endl;
                        }
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            3.1.2.7 string �Ӵ�: ���һ���ַ������е�ĳһ��
                string substr(int pos = 0,int n = npos)const;//������ pos ��ʼ��n ���ַ���ɵ��ַ���

            ����
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

            3.1.2.8 string ����� ɾ������
                string& insert(int pos, const char* s);     //�����ַ���
                string& insert(int pos, const string& str)  //�����ַ���
                string& insert(int pos,int n,char c);       //��ָ��λ�ò���n���ַ�
                string& erase(int pos,int n = npos);        //ɾ����Pos��ʼ��n���ַ�

            ����
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
                    //�ڶ���λ�ò���kkk
                    string str("helloworld");
                    string str2("hehe");
                //    str.insert(2,"kkk");

                    //���ַ���
                //    str.insert(2,str2);
                //    cout << str << endl;

                    //���ַ�:λ��2��10��r
                //    str.insert(2,10,'r');
                //    cout << str << endl;

                    //ɾ��
                    //�ӵ�����λ�ã�ɾ��3��
                    str.erase(3,3);
                    cout << str << endl;

                }
                int main()
                {
                    test();
                    return 0;
                }

            3.1.2.9 string �� c-style �ַ���ת��
                //string תchar*
                string str = "itcast";
                const char* cstr = str.c_str();

                //char*תstring
                char*s= "itcast";
                string str(s);

                ��c++�д���һ����const char ��string����ʽ����ת����ȴ�����ڴ�һ��string ����Cstring ���Զ�����ת����
                ����string ���͵��ַ���������ͨ��c_str()��������string�����Ӧ��C_string.

                ͨ��������Ա������������ Ӧ���ʹ�� string �����ֱ�����뽫����ת��Ϊcharʱ�Ž���ת��Ϊc_string.
            ��ʾ;
                Ϊ���޸�string �ַ��������ݣ��±������[]�� at ���᷵���ַ������á������ַ������ڴ汻���·���֮�󣬿��ܷ�������.
                ����
                    string s = "abcdefg";
                    char & a = s[2];            //���ô���

                    a = '1';
                    b = '2';

                    cout << s << endl;
                    cout << (int *)s.c_str()  << endl;

                    //���ǵ�sָ���µĿռ��ʱ��ԭ��ָ��Ŀռ�ᱻ�ͷ�
                    s = "ppppppppppppppppppppppppppp";

                    //��ʱ�ٶ�a,b�������ᱨ���Ƿ�����
                    //a = '1';
                    //b = '2';

                    cout << s << endl;
                    cout << (int)s.c_str() << endl;

            ����
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
                    str = "world";          //1.���Ը�ֵ������opreator=(char *)

                    char *s = NULL;
                //    s = str;          //2.���ܸ�ֵ����Ϊs��char*��
                    //3.��string������c_str()���������ص���const char *
                //    str.c_str();    //����const char *
                    //4.ֻ��Ҫȥconst���ɡ�
                    s = const_cast<char *> (str.c_str());
                    cout << s <<endl;

                }

                int main()
                {
                    test();
                    return 0;
                }

*/
//3.2 vector ����
/*
        3.2 vector ����
            3.2.1 vector ������������
                vector �����ݰ��� �Լ� ������ʽ,�� array �ǳ�����,���ߵ�Ψһ������ڿ��ʵ����õ�����ԡ�
                Array �Ǿ�̬�ռ�,һ�������˾Ͳ��ܸı䣬Ҫ����һ�����Сһ��Ŀ��ʣ�����ԣ���һ����������Լ�������������һ���µĿռ�,Ȼ�󽫾ɿռ�����ݰ����¿ռ䣬���ͷ�ԭ���Ŀռ䡣
                Vector�Ƕ�̬�ռ䣬����Ԫ�صļ��룬�����ڲ����ƻ��Զ�����ռ���������Ԫ�ء���� vector �����ö����ڴ�ĺ������������õ�������кܴ�İ�����������Ҳ���غ��¿ռ䲻���һ��ʼ��Ҫ��һ�����ͷ��array�ˡ�

              * Vector ��ʵ�ּ������ؼ������� �Դ�С�Ŀ��� �Լ� ��������ʱ�������ƶ�Ч�� ��һ�� vector �ɿ������ˣ�����ͻ�ÿ����һ��Ԫ�أ�vector�ڲ�ֻ������һ��Ԫ�صĿռ䣬ʵΪ���ǣ���Ϊ��ν������ռ�(���۶��)��һ�����˵����"�����¿ռ䡤�����ƶ����ͷžɿռ�"�Ĵ󹤳�,ʱ��ɱ��ܸߣ�Ӧ�ü���ĳ��δ����ѵĿ��ǣ��Ժ����Ǳ���Կ��� vector �Ŀռ����ò��ԡ�

                  v.begin()     �׵�ַ��ָ����Ԫ��
                  v.end()       β��ַ��ָ��ĩԪ��
                  insert()      ����λ��
                  v.rbegin()    β��ַ��ָ��ĩԪ��
                  v.rend        �׵�ַ��ָ����Ԫ��
                  v.push_back() β��
                  v.pop_back()  βɾ

            3.2.2 vector ������
                Vectorά��һ�����Կռ䣬���Բ���Ԫ�ص��ͱ���Σ���ָͨ�붼������Ϊ vector �ĵ���������Ϊ vector ������
                ����Ҫ�Ĳ�����Ϊ,�� operator. , operator->, operator++,operator--, operatort+,operator-, operator+=,operator-=����ָͨ�������߱���
                vector ֧�������ȡ,����ָͨ������������������������vector �ṩ����������ʴ����(Random Access Iterators).

                ���������������������д���µĴ���:
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <algorithm>
                using namespace std;

                //vector������
                void test()
                {
                    vector<int> v;
                    v.push_back(1);
                    v.push_back(2);
                    v.push_back(3);
                    v.push_back(4);

                    vector<int>::iterator it_start = v.begin();//iterator ������
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

                //�ռ�����
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

            3.2.3 vector �����ݽṹ
                Vector �����õ����ݽṹ�ǳ��򵥣����������ռ䣬�������������� Myfirst ��Mylast �ֱ�ָ�����õ����������ռ���Ŀǰ�ѱ�ʹ�õķ�Χ�����Ե����� Myendָ�����������ڴ�ռ��β�ˡ�

                Ϊ�˽��Ϳռ�����ʱ���ٶȳɱ���vectorʵ�����õĴ�С���ܱȿͻ��������һЩ���Ա��������ܵ����䣬����������ĸ��
                ���仰˵��һ�� vector ��������Զ���ڻ�������С��һ���������ڴ�С���������أ��´���������Ԫ�أ����� vector �����͵����پ�����

            ע��:
                ��ν��̬���Ӵ�С����������ԭ�ռ�֮�������¿ռ�(��Ϊ�޷���֤ԭ�ռ�֮�����п����õĿռ�)������һ�������ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬���ͷ�ԭ�ռ䡣
                ��ˣ���vector���κβ�����һ������ռ���������ã�ָ��ԭvector�����е������Ͷ�ʧЧ�ˡ����ǳ���Ա���׷���һ�������С�ġ�

            3.2.4 vector ����API ����
                3.2.4.1 vector ���캯��
                    vector<T> v;//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
                    vector(v.begin()��v.end());//��v[begin()��end())�����е�Ԫ�ؿ���������
                    vector(n��elem);//���캯����n��elem����������
                    vector(const vector &vec);//�������캯����
                ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //vector<T> v;//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
                    //vector(v.begin()��v.end());//��v[begin()��end())�����е�Ԫ�ؿ���������
                    //vector(n��elem);//���캯����n��elem����������
                    //vector(const vector &vec);//�������캯����

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
                        vector<int> v3(4,5);    //��4��5
                        vector<int> v4(v1);

                    //    for_each(v2.begin(),v2.end(),print);    //for_each��ͷ�ļ���<algorithm>.������ʹ�÷�ʽ��ǰ��
                        for_each(v3.begin(),v3.end(),print);    //5555
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.2 vector ���ø�ֵ����
                    assign(beg,end);                        //��[beg��end)�����е����ݿ�����ֵ������
                    assign(n,elem);                         //��n��elem �ӱ���ֵ������
                    vector& operator=(const vector &vec);   //���صȺŲ�����
                    swap(vec);                              // ��vec �뱾���Ԫ�ػ�����
                ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //assign(begin,end);                      //��[beg��end)�����е����ݿ�����ֵ������
                    //assign(n,elem);                         //��n��elem �ӱ���ֵ������
                    //vector& operator=(const vector &vec);   //���صȺŲ�����
                    //swap(vec);                              // ��vec �뱾���Ԫ�ػ�����
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
                        v2.swap(v1);    //�������ֻ�ǰ�v1�� v2��ָ������˽�����
                        for_each(v1.begin(),v1.end(),print);
                        cout << "-----" <<endl;
                        for_each(v2.begin(),v2.end(),print);
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.3 vector ��С����
                    size();                                 //����������Ԫ�صĸ���
                    empty();                                //�ж������Ƿ�Ϊ��
                    resize(int num);                        //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�����������,��δβ�����������ȵ�Ԫ�ر�ɾ����
                    resize(int num,elem);                   //����ָ�������ĳ���Ϊnum���������䳤������elem ֵ�����λ�á����������̡���δβ����������>�ȵ�Ԫ�ر�ɾ����
                    capacity();                             //����������
                    reserve(int len);                       //����Ԥ��len ��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ�������ز��ɷ��ʡ�
                ����

                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //size();                                 //����������Ԫ�صĸ���
                    //empty();                                //�ж������Ƿ�Ϊ��
                    //resize(int num);                        //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�����������,��δβ�����������ȵ�Ԫ�ر�ɾ����
                    //resize(int num,elem);                   //����ָ�������ĳ���Ϊnum���������䳤������elem ֵ�����λ�á����������̡���δβ����������>�ȵ�Ԫ�ر�ɾ����
                    //capacity();                             //����������
                    //reserve(int len);                       //����Ԥ��len ��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ�������ز��ɷ��ʡ�

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
                    //    v1.resize(10);      //1 2 3 0 0 0 ...Ĭ�ϱ䳤�����ֵΪ0
                        v1.resize(10,2);    //Ĭ�ϱ䳤�����ֵΪ2

                        for_each(v1.begin(),v1.end(),print);

                        if(!v1.empty())//�ж��Ƿ�Ϊ��
                        {
                            cout << "��Ϊ��" << endl;
                        }


                        vector<int> v2;
                        //����֪��Ҫ һ��ȷ���Ĵ�С����1�򣩣������ֱ��ѡ��Ԥ��1��Ŀռ䣬������ÿ����һ��Ԫ�ؾ�������ƥ��Ŀռ��š�
                        v2.reserve(100);    //Ԥ�趨����
                        cout << v2.size() << endl;      //0
                        cout << v2.capacity() << endl;  //100�����ȸ�������չ��100��
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.4 vector ���ݴ�ȡ����
                    at(int idx);//��������idx ��ָ�����ݣ����idx Խ�磬�׳�out_of_range �쳣��
                    operator[];//��������idx ��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
                    front();//���������е�һ������Ԫ��
                    back();//�������������һ������Ԫ��
                ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //at(int idx);//��������idx ��ָ�����ݣ����idx Խ�磬�׳�out_of_range �쳣��
                    //operator[];//��������idx ��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
                    //front();//���������е�һ������Ԫ��
                    //back();//�������������һ������Ԫ��
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
                        cout << v1.front() << endl;//���ص�һ��Ԫ��
                        cout << v1.back() << endl;
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.5 vector �����ɾ������
                    insert(const_iterator pos, int count,ele);//������ָ��λ��pos ����count ��Ԫ��ele.
                    push_back(ele);//β������Ԫ��ele
                    pop_back();//ɾ�����һ��Ԫ��
                    erase(const iterator start, const iterator end);//ɾ��ѡ������start ��end ֮���Ԫ��
                    erase(const iterator pos);//ɾ��ѡ����ָ���Ԫ��
                    cLear();//ɾ������������Ԫ��

                ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <algorithm>
                    using namespace std;

                    //insert(const_iterator pos, int count,ele);//������ָ��λ��pos ����count ��Ԫ��ele.
                    //push_back(ele);//β������Ԫ��ele
                    //pop_back();//ɾ�����һ��Ԫ��
                    //erase(const iterator start, const iterator end);//ɾ��ѡ������start ��end ֮���Ԫ��
                    //erase(const iterator pos);//ɾ��ѡ����ָ���Ԫ��
                    //cLear();//ɾ������������Ԫ��

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

                    //    v1.pop_back();//βɾ
                        v1.erase(v1.begin()+3,v1.end());

                        v1.insert(v1.begin()+2,3,9);    //��+2λ�ò���3��9
                        v1.erase(v1.begin()+3);         //ɾ��ָ��Ԫ��
                        for_each(v1.begin(),v1.end(),print);
                        v1.clear(); //ɾ������Ԫ��
                        for_each(v1.begin(),v1.end(),print);
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

                3.2.4.6 vector ����
                    3.2.4.6.1 ʹ��swap�����ռ�

                        vector<int>(v1).swap(v1); //������������������,������v1��ʼ����v1�м���Ԫ�أ���������Ϳ��ٶ��ڴ�С�Ŀռ䣩���ڽ��ó�ʼ���ռ�ͬv1������

                        ����
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
                                v1.resize(10);//size���10�ˣ��������䣬���˷Ѻܶ�1�ռ�
                                cout << v1.size() <<" "<< v1.capacity()<< endl;
                                vector<int>(v1).swap(v1); //������������������,������v1��ʼ����v1�м���Ԫ�أ���������Ϳ��ٶ��ڴ�С�Ŀռ䣩���ڽ��ó�ʼ���ռ�ͬv1������
                                cout << v1.size() <<" "<< v1.capacity()<< endl;
                            }

                            int main()
                            {
                                test();
                                return 0;
                            }
                    3.2.5.6.2 reservr Ԥ���ռ�
                        v.reserve(10000);//Ԥ��10000������С�Ŀռ䡣

                    ע�⣺
                        ���û��Ԥ���ռ䣬��ô�����0��ʼ����һ��10000��С�Ŀռ䣬��Ҫ���¿��ٶ��ٴΣ��ܷ�Ԥ�⣿
                        �����������¿��ٿռ�Ĵ���
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
                                //����ÿһ����������ռ䣬��Ԫ�ص�ַ����ı䣬��ôֻ��Ҫ������Ԫ�ص�ַ�ı�Ĵ������ɡ�
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

                3.2.4.7 ����������
                    bool compare1(Person &p1,Person &p2)
                    {
                    //    return p1.age > p2.age;   //�Ӵ�С����
                        return p1.age < p2.age;     //��С��������
                    }

                    sort(v1.begin(),v1.end(),compare);

                ����
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

                    //    sort(v1.begin(),v1.end());//��С��������
                        sort(v1.begin(),v1.end(),compare);//a>b�ǴӴ�С����a < b�Ǵ�С����
                        //algorithm����õ�sort���������ʵ�����صģ���������дһ���ص�������
                        for_each(v1.begin(),v1.end(),print);
                    }

                    //������� �Զ�����󣿣�
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
                    //    return p1.age > p2.age;   //�Ӵ�С
                        return p1.age < p2.age;
                    }
                    void test1()
                    {
                        vector<Person> v;
                        Person p1(10,"��");
                        Person p2(40,"����");
                        Person p3(50,"������");
                        Person p4(20,"����");
                        Person p5(30,"����");

                        v.push_back(p1);
                        v.push_back(p2);
                        v.push_back(p3);
                        v.push_back(p4);
                        v.push_back(p5);
                        for_each(v.begin(),v.end(),print1);

                        //����
                        sort(v.begin(),v.end(),compare1);
                        for_each(v.begin(),v.end(),print1);


                    }
                    int main()
                    {
                        test1();
                        return 0;
                    }

*/
//3.3 deque ����
/*
    3.3 deque ����
        3.3.1 deque ������������
            Vector ������  ���򿪿� �� �����ڴ�ռ䣬
            deque ����һ��  ˫�򿪿� �� �������Կռ䡣

            ��ν��˫�򿪿ڣ���˼�� ������ͷβ���˷ֱ���Ԫ�صĲ����ɾ��������
            ��Ȼ��vector ����Ҳ������ͷβ���˲���Ԫ�أ���������ͷ������Ч�����޷������ܡ�

            (vector����β���βɾ����û��֧��ͷ���ͷɾ�Ľӿڡ���Ϊ�����Ҫͷ�� �� ͷɾ������Ҫ��Ԫ��������Ų��Ч�ʼ��͡�)
        deque�ڲ���
            push_front() ͷ��
            pop_front()  ͷɾ
            push_back()  β��
            pop_back()   βɾ
            begin()
            end()       ����������
            insert()    ����ӿ�

            deque������vector�������Ĳ�����ǣ�deque����ʱ����Ҫ�ı�������Ԫ�ص�һ���ƶ���

          * Deque ������vector�������Ĳ��죬
                һ���� deque ����ʹ�ó�����ʱ���ͷ�˽���Ԫ�صĲ����ɾ��������
                ������ deque û�������ĸ����Ϊ���Ƕ�̬���Էֶ������ռ���϶��ɣ���ʱ��������һ���µĿռ䲢��������,���仰˵���� vector ���������ɿռ䲻�����������һ�����ռ䣬Ȼ����Ԫ�أ����ͷžɿռ�"������������ deque �����ǲ��ᷢ���ġ�Ҳ��ˣ�deque û�б���Ҫ�ṩ��ν�Ŀռ䱣����reserve�����ܡ�

          * ��Ȼ degue ����Ҳ�ṩ�� Random Access lterator,�������ĵ�������������ͨ��ָ�룬�临�ӶȺ� vector ����һ���������⵱ȻӰ���������Ĳ��档
            ��ˣ������б�Ҫ������Ӧ�þ����ܵ�ʹ�� vector�������� deque��

          * �� deque ���е����������Ϊ�����Ч�ʣ��ɽ� deque �������ĸ��Ƶ�һ�� vector �У���vector �������������ٸ��ƻ�deque.

        3.3.2 deque ������ʵ��ԭ��
            Deque ������ �����Ŀռ䣬�����߼��Ͽ�����ˣ��������пռ��������������뵽array �� vector,array �޷��ɳ�,vector ��ɳɳ���ȴֻ����β�˳ɳ���������ɳ���ʵ��һ������ʵ������(1)�������ռ� (2)ԭ���ݸ����¿ռ�(3)�ͷ�ԭ�ռ� �����裬
            ������� vector ÿ�������µĿռ�ʱ��������ԣ����ɳ������������Ĵ����Ƿǳ�����ġ�

            Degue ����һ��һ�εĶ����������ռ乹�ɡ�һ���б�Ҫ�� deque ǰ�˻���β�������µĿռ䣬������һ�����������Ŀռ䣬������ deque��ͷ�˻���β�ˡ�
            Deque ���Ĺ�������ά����Щ�ֶ��������ڴ�ռ�������Եļ��󣬲��ṩ�����ȡ�Ľӿڣ��ܿ����������ÿռ䣬���ƣ��ͷŵ��ֻأ����۾��Ǹ��ӵ�ѡ�����ܹ���

            ��Ȼ deque �Ƿֶ������ڴ�ռ䣬��ô�ͱ�����������ƣ�ά�����������ļ������ݽṹ����Ƽ���������ǰ�� ���˲�����Ϊ������

          * Deque �����ʵ�� Զ��vector��list ����öࡣDeque ��ȡһ����ν�� map(ע�⣬���� STL�� map ����)��Ϊ���أ�������ν�� map ��һС���������ڴ�ռ�,����ÿһ��Ԫ��(�˴���Ϊһ�����)����һ��ָ�룬ָ����һ���������ڴ�ռ䣬������������
          * ������ ���� deque �Ĵ洢�ռ�����塣

              �п���               ������
                        ->                 ele ele ele
             0x01

        �ڵ�  0x02     ->       ele ele ele ele ele ele

             0x03       ->      ele ele ele


             ���п����б���ľ���һ��һ�εĵ�ַ��������deque�����洢�ľ���һ����ָ�룬���ݴ洢�� ָ��ָ��� ���������棩

        3.3.3 deque ����API
            3.3.3.1 deque ���캯��
                deque<T> deqT; //Ĭ�Ϲ�����ʽ
                deque(beg,end); //���캯����[beg,end)�����е�Ԫ�ؿ���������
                deque(n��elem);//���캯��n ��elem ����������,
                deque(const deque &deq);//�������캯����

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                //deque<T> deqT; //Ĭ�Ϲ�����ʽ
                //deque(beg,end); //���캯����[beg,end)�����е�Ԫ�ؿ���������
                //deque(n��elem);//���캯��n ��elem ����������,
                //deque(const deque &deq);//�������캯����
                void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
                {
                    cout << a << endl;
                }
                void test()
                {
                    deque<int> d1;  //Ĭ�Ϲ���
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    deque<int> d2(d1); //��d1����ʼ��d2
                    deque<int> d3(d1.begin(),d1.end()); //��d1�Ŀ�ʼ��������ʼ��d3
                    deque<int> d4(10,8);                //10��8

                    for_each(d4.begin(),d4.end(),print);
                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.2 deque�����ĸ�ֵ����
                assign(beg��end);                    //��[beg��end)�����е����ݿ�����ֵ������
                assign(n,elem);                     //��n��elem ������ֵ������
                deque& operator=(const deque &deq); //���صȺŲ�����
                swap(deq);                          // ��deq�뱾���Ԫ�ػ���
            ����
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
                    deque<int> d1;  //Ĭ�Ϲ���
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
            3.3.3.3 deque ��С����
                deque.size();       //����������Ԫ�صĸ���
                deque.empty();      //�ж������Ƿ�Ϊ��
                deque.resize(num);  //����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á�����������,��δβ�����������ȵ�Ԫ�ر�ɾ����
                deque.resize(num,elem);//����ָ�������ĳ���Ϊnum,�������䳤,����elem ֵ�����λ��,���������̡���δβ�����������ȵ�Ԫ�ر�ɾ����

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
                {
                    cout << a << endl;
                }

                void test()
                {
                    deque<int> d1;  //Ĭ�Ϲ���
                    d1.push_back(1);
                    d1.push_back(2);
                    d1.push_back(3);

                    cout<< d1.size() <<endl;    //dequeֻ�д�С��û��������˵����
                    if(!d1.empty())
                    {
                        cout << "��Ϊ��" << endl;
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

            3.3.3.4 deque ˫�˲����ɾ������
                push_back(elem);    //������β�����һ������
                push_front(elem);   //������ͷ������һ������
                pop_back();         //ɾ���������һ������
                pop_front();        //ɾ��������һ������

            ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    #include <vector>
                    #include <deque>
                    #include <algorithm>
                    using namespace std;

                    void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
                    {
                        cout << a << endl;
                    }

                    void test()
                    {
                        deque<int> d1;
                        //ͷ��
                        d1.push_back(1);
                        d1.push_back(2);
                        d1.push_back(3);
                        //β��
                        d1.push_front(4);
                        d1.push_front(5);
                        d1.push_front(6);
                        for_each(d1.begin(),d1.end(),print);

                        //βɾ
                        d1.pop_back();
                        //ͷɾ
                        d1.pop_front();

                        for_each(d1.begin(),d1.end(),print);

                    }

            3.3.3.5 deque ���ݴ�ȡ
                at(idx);//��������idx ��ָ�����ݣ����idx Խ�磬�׳�out_of_range��
                operator[];//��������idx ��ָ�����ݣ����idx Խ�磬���׳��쳣��ֱ�ӳ���
                front();//���ص�һ�����ݡ�
                back();//�������һ����

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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

            3.3.3.6 deque �������
                insert(pos,elem);//��pos λ�ò���һ��elem Ԫ�صĿ��������������ݵ�λ��,
                insert(pos,n,elem);//��pos λ�ò���n��elem ���ݣ��޷���ֵ��
                insert(pos,beg,end);//��pos λ�ò���[beg,end)��������ݣ��޷���ֵ��

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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

                    d1.insert(d1.begin()+1,10); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)
                    d1.insert(d1.begin()+1,3,2); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)
                    d1.insert(d1.begin()+1,10); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)

                    for_each(d1.begin(),d1.end(),print);

                    deque<int> d2;
                    d2.insert(d2.begin(),d1.begin(),d1.begin());
                }

                int main()
                {
                    test();
                    return 0;
                }

            3.3.3.7 deque ɾ������
                clear();//�Ƴ���������������
                erase(beg,end);//ˢ��[beg,end)��������ݣ�������һ�����ݵ�λ��
                erase(pos);//ɾ��pos λ�õ����ݣ�������һ�����ݵ�λ��

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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

                    //βɾ
                    d1.pop_back();
                    //ͷɾ
                    d1.pop_front();
                    //ȫɾ
                    d1.clear();
                    //ɾ����
                    d1.erase(d1.begin()+2,d1.end());
                    //ɾĳһ��
                    d1.erase(d1.begin()+2);
                    for_each(d1.begin(),d1.end(),print);
                }

                int main()
                {
                    test();
                    return 0;
                }
            3.3.3.8 ����(��ҵ)
                ��5��ѡ��:ѡ��ABCDE��10 ����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
                1.��������ѡ�֣��ŵ�vector��
                2.����vector ������ȡ����ÿһ��ѡ�֣�ִ��for ѭ�������԰�10 �����ִ�ִ浽deque ������
                3.sort �㷨�� deque �����з�������,pop_back pop_front ȥ����ߺ���ͷ�
                4.deque ��������һ�飬�ۼӷ������ۼӷ���/d.size()
                5.person.score=ƽ����
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                #include <vector>
                #include <deque>
                #include <algorithm>
                using namespace std;

                //1.����һ��ѡ����
                class Player
                {
                public:
                    //�޲ι���
                    Player(){}
                    //�вι���
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

                void start_play(vector<Player> &v)      //v������
                {
                    srand((unsigned int)time(NULL));//�������������ֵʱ���֡�

                    //���� ��ʱdeque���������ڲ���
                    deque<int> d;

                    //v������,it������ָ��(������)��it��ָ���� Player,����it����Player��Աʱ��Ӧ����ʹ��->��
                    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
                    {
                        //�õ�һ��deque�����������ɵ�10�������װ��deque������
                        for(int i = 0;i < 10;i++)
                        {
                            d.push_back(60+rand()%41);
                        }

                        //��deque�������в�����ȥ����ߺ���ͷ�
                        sort(d.begin(),d.end());//С->��
                        d.pop_back();   //βɾ
                        d.pop_front();  //��ɾ

                        int sum = 0;

                //        for(int i = 0;i<d.size();i++)
                //        {
                //            sum += d[i];
                //        }
                        //����deque�����������ܺ�
                        for(deque<int>::iterator it1 = d.begin();it1 != d.end();it1++)
                        {
                            sum += *it1;
                        }
                        //��ƽ��
                        int aver = sum / d.size();
                        //��ƽ��ֵ��ֵ���� it������ ָ���  Player���������score��Ա����
                        //ע�⣺v������,it������ָ��(������)��it��ָ���� Player,����it����Player��Աʱ��Ӧ����ʹ��->��
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
                        Player tmp(strname,0);  //����һ�����󣬴����� ����ʼ��ֵ0
                        v.push_back(tmp);       //�Ѷ���ŵ�������
                    }
                }

                int main()
                {
                    //2.����һ��vector����v������ȡѡ��
                    vector<Player> v;
                    //3.��ʼ��ѡ�֣���ѡ�����ַ�����ֵ��,����Ϊ��������
                    Init_Player(v);
                    //������ӡ
                    print_player(v);
                    //��ʼ������
                    start_play(v);
                    print_player(v);
                    return 0;
                }
*/
//4�� �㷨
/*
    4.1 ��������
        ���غ������ò��������࣬�� ���� ����Ϊ ��������(functionobject)��
            ��: ��������Ϊ���ƺ����Ķ���Ҳ�зº���(functor),��ʵ�������ء�()"��������ʹ���������������������á�
    ע��:
        1.��������(�º���)��һ���࣬����һ��������
        2.��������(�º���)������"()"������ ʹ������������һ�����á�

    ����:�ٶ�ĳ������һ�����ص� operator()���������ص� operator()Ҫ���ȡһ�����������Ǿͽ�������Ϊ"һԪ�º�����(unaryfunctor);
        �෴��������ص� operator()Ҫ���ȡ�����������ͽ�������Ϊ����Ԫ�º�����(binany functor)

        ���������������Ҫ��ʲô?
        STL�ṩ���㷨�������������汾������һ���汾���ֳ���õ�ĳ�����㡣
        ��һ�汾 �������û�ͨ��template ��������ʽ��ָ����Ҫ��ȡ�Ĳ��ԡ�

    ����

            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            #include <stdlib.h>
            #include <vector>
            #include <deque>
            #include <algorithm>
            using namespace std;

            //��������
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


            //��������������������ôʹ�ã�
            void test1()
            {
                vector<int> v;
                v.push_back(1);
                v.push_back(3);
                v.push_back(2);
                v.push_back(5);

                //���򴫺���
                sort(v.begin(),v.end(),compare);
                //���򴫶���
                sort(v.begin(),v.end(),Compare());

                //������
                for_each(v.begin(),v.end(),print);

                //���ﴫ�ı�������������Print()��
                for_each(v.begin(),v.end(),Print());//����������Print(),
            //    //����ʵ�����ǣ�
            //    void For_each unchecked( InIt _First, InIt _Last,Fnl& _Func)
            //    {
            //        for(;_First != Last; ++First)
            //            _Func (* First);      //����������operator() ��������ˣ���ֱ�����õ������ǵ���������Ȼ��ʹ�����ص�(),�Ѳ���ֱ�Ӵ�������
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

    4.2 ν��
        ν�� ��ָ ��ͨ���� �� ���ص� operator() ����ֵ�� bool���͵ĺ�������(�º���)��
        ��� operator ����һ����������ô����һԪν��,�������������������ô������Ԫν�ʣ�ν�ʿ���Ϊһ���ж�ʽ��
    ����

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
            void operator()(int a)  //��������һԪν��
            {
                cout << a << endl;
            }
        };

        class Compare
        {
        public:
            bool operator()(int a, int b)   //�������ض�Ԫν��
            {
                return a > b ;
            }
        };
        bool greater2(int a)    //��ͨ���� һԪν��
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
        //    //���򴫶���
        //    sort(v.begin(),v.end(),Compare());
        //    //���ﴫ�ı�������������Print()��
        //    for_each(v.begin(),v.end(),Print());//����������Print(),

        }
        int main()
        {
            test();
            return 0;
        }

    4.3 �ڽ���������
        STL�ڽ�(�Դ�)��һЩ��������
            ��Ϊ:�����ຯ������,��ϵ�����ຯ�������߼�������º�������Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ����Ȼ���ǻ����Բ�����������ʱ���������к������ܡ�
            ʹ���ڽ�����������Ҫ����ͷ�ļ� #include <functional>��

        6�������ຯ������,����negate��һԪ���㣬�������Ƕ�Ԫ���㡣
            template<class T>T plus<T>              //�ӷ��º���
            template<class T>T minus<T>             //�����º���
            template<class T>T multiplies<T>        //�˷��º���
            template<class T>T divides<T>           //�����º���
            template<class T>T modulus<T>           //ȡģ�º���
            template<class T>T negate<T>            //ȡ���º���

        6����ϵ�����ຯ������,ÿһ�ֶ��Ƕ�Ԫ���㡣
            template<class T> bool equal_to<T>      //����
            template<class T> bool not_equal_to<T>  //������
            template<class T> bool greater<T>       //����
            template<class T> bool greater_equal<T> //���ڵ���
            template<class T> bool less<T>          //С��
            template<class T> bool less_equal<T>    //С�ӵ���

        �߼����������㺯��,notΪһԪ���㣬����Ϊ��Ԫ���㡣
            template<class T> bool logical_and<T>   //�߼���
            template<class T> bool logical_or<T>    //�߼���
            template<class T> bool logical_not<T>   //�߼���

        �ڽ������������:

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

                //negate<int> p; ʵ�ʣ�
                //template<class T>
                //class negate
                //{
                //public:
                //    T operator() (T a)
                //    {
                //        return a�ķ�����
                //    }
                //}

                void test()
                {
                    //ȡ��
                    negate<int> p;  //����һ����������p
                    cout << p(5) << endl;
                    cout << negate<int>() (5) << endl;

                    //�ӷ�
                    cout << plus<int>() (4,5) << endl;

                    vector<int> v;
                    v.push_back(1);
                    v.push_back(3);
                    v.push_back(2);
                    v.push_back(5);
                    //��������
                    sort(v.begin(),v.end(),greater<int>());
                    //С������
                    sort(v.begin(),v.end(),less<int>());

                }

                int main()
                {
                    test();
                    return 0;
                }

    4.4 ������
        ���������������չ�����ӿڣ�һ���Ϸº���һ��ʹ�á�
        4.4.1 ��������������

            ����������д�����ע��
        ����
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

            //1.���ڣ�����for_each�ڴ�ӡ��ʱ�򣬴�һ��a�� num������������,����Ҫ������num��ֵ��Print()�������������а󶨡�
            //3.�̳У��̳��ַ�ΪһԪ�̳кͶ�Ԫ�̳С�����operator����������������Ƕ�Ԫ�̳С�

            //4.һԪ�̳У�unary_function<����1������ֵ����>
            //5.��Ԫ�̳У�public binary_function<����1,����2,����ֵ����>


            class Print:public binary_function<int,int,void>
            {
            public:
                //6. ��operator()() �����const��
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
                //2.����һ���󶨲��� bind2nd    ���ַ��� 200������num
            //    for_each(v.begin(),v.end(),bind2nd(Print(),200));

                //7.���������󶨲��� bind1st    ���ַ��� 200������a
                for_each(v.begin(),v.end(),bind1st(Print(),200));
            }

            int main()
            {
                test();
                return 0;
            }

*/

//�ʼ���
//############################################################################
//������

//�������ĳ���ʹ�ã�
//������ָ��Ԫ��Ϊint����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//STL �е����� �㷨 ������

void test()
{

    //vector������������һ�������һ�����飬��������Ƕ�̬���飬���������������ɼ���
    //����������Ϊ��һ���࣬����ģ�巽ʽȥ���壬���������Ǹ���
    vector<int> v;//STL �еı�׼����֮һ����̬���飨��vector����ඨ��һ������v������v��һ����̬���飩�������ÿһ��Ԫ�ص�����Ϊint��

    //������ṩ�� �������������Ľӿڣ�����룬β�塣
    //v.push_back() ����β��
    v.push_back(2);//vector �����ṩ�Ĳ������ݵķ���
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);

    //������

    //����Ҫ��������v��ÿһ��Ԫ�أ���Ҫ�õ�ָ���׸�Ԫ�ص�ָ�룬Ҳ����ָ����Ԫ�صĵ�������
    //v.begin()   ��ʼ�����������ָ����Ԫ�صĵ�����
    //v.end()     ��������������ȡָ�����һ��Ԫ�ص���һ��Ԫ�� �� ��������ָ�룩��
    //�����������ͣ� vector<int>::iterator
    vector<int>::iterator it_start = v.begin(); //vector �����ṩ�� begin()���� ����ָ���һ��Ԫ�صĵ�����
    vector<int>::iterator it_end   = v.end();   //vector �����ṩ��   end()���� ����ָ�����һ��Ԫ����һ��λ�õĵ�����

    //ͨ������������
    for(;it_start != it_end;it_start++)
    {
        //�Ե����������ã�ȡ�øÿռ������
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
//������ָ��Ԫ��Ϊ �Զ�������
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
//������ָ�����һ������
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
    //1.����С����
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    //2.С������������
    for(int i = 0;i<3;i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+100);
    }

    //���� Ƕ�� ������v�Ǵ�����������������С������
    //3.���������
    vector< vector<int> > v;

    //4.����������С����
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //it_start ָ�����һ�� vector<int> ��С���� ��*it_start == vector<int>
    //(*it_start).begin() ָ��С��������Ԫ�ء�
    //5.����
    vector<vector<int>>::iterator it_start = v.begin() ;//��õ�����������Ԫ�ص�ַ
    vector<vector<int>>::iterator it_end   = v.end() ;

    for(;it_start != it_end;it_start++)
    {
        //*it_start �õ�С����
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
//string�����Ĺ��캯��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//string�Ļ��� ��ֵ ����
void test()
{
    string str("helloworld");
    string str1("heihei");
    str = "hehe";               //��ֵ char*�ַ���
    cout << str << endl;
    str = str1;                 //��ֵ &����
    cout << str << endl;
    str = 'c';                  //��ֵ �ַ�
    cout << str << endl;

    str.assign("hello");        //������ֵ �ַ���
    cout << str << endl;
    str.assign("jack",2);       //��ֵ�ַ���������
    cout << str << endl;
    str.assign(str1);           //������ֵ ����
    cout << str << endl;
    str.assign(5,'c');          //��ֵ 5��c��str
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
//string c��ȡ�ַ�����
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
//string ��ƴ��
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
//string ���� �� �滻
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
//string �Ƚϲ���
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
        cout << "str��" << endl;
    }
    else if(ret < 0)
    {
        cout << "strС" << endl; //str1 �� str2С
    }
    else
    {
        cout << "���" << endl;
    }
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//string ���ִ�
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
//string �Ĳ����ɾ��
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
    //�ڶ���λ�ò���kkk
    string str("helloworld");
    string str2("hehe");
//    str.insert(2,"kkk");

    //���ַ���
//    str.insert(2,str2);
//    cout << str << endl;

    //���ַ�:λ��2��10��r
//    str.insert(2,10,'r');
//    cout << str << endl;

    //ɾ��
    //�ӵ�����λ�ã�ɾ��3��
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
//string �� c-style �ַ���ת��
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
    str = "world";          //1.���Ը�ֵ������opreator=(char *)

    char *s = NULL;
//    s = str;          //2.���ܸ�ֵ����Ϊs��char*��
    //3.��string������c_str()���������ص���const char *
//    str.c_str();    //����const char *
    //4.ֻ��Ҫȥconst���ɡ�
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
//vector �����ĵ�����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//vector������
void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it_start = v.begin();//iterator ������
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

//�ռ�����
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
//vector �Ĺ��캯��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//vector<T> v;//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//vector(v.begin()��v.end());//��v[begin()��end())�����е�Ԫ�ؿ���������
//vector(n��elem);//���캯����n��elem����������
//vector(const vector &vec);//�������캯����

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

    //����
    vector<int> v2(v1.begin()+1,v1.end());
    vector<int> v3(4,5);    //��4��5
    vector<int> v4(v1);

//    for_each(v2.begin(),v2.end(),print);    //for_each��ͷ�ļ���<algorithm>.������ʹ�÷�ʽ��ǰ��
    for_each(v3.begin(),v3.end(),print);    //5555
}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector �ĳ��ø�ֵ����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//assign(begin,end);                      //��[beg��end)�����е����ݿ�����ֵ������
//assign(n,elem);                         //��n��elem �ӱ���ֵ������
//vector& operator=(const vector &vec);   //���صȺŲ�����
//swap(vec);                              // ��vec �뱾���Ԫ�ػ�����
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
    v2.swap(v1);    //�������ֻ�ǰ�v1�� v2��ָ������˽�����
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
//vector �Ĵ�С����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//size();                                 //����������Ԫ�صĸ���
//empty();                                //�ж������Ƿ�Ϊ��
//resize(int num);                        //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�����������,��δβ�����������ȵ�Ԫ�ر�ɾ����
//resize(int num,elem);                   //����ָ�������ĳ���Ϊnum���������䳤������elem ֵ�����λ�á����������̡���δβ����������>�ȵ�Ԫ�ر�ɾ����
//capacity();                             //����������
//reserve(int len);                       //����Ԥ��len ��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ�������ز��ɷ��ʡ�

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
//    v1.resize(10);      //1 2 3 0 0 0 ...Ĭ�ϱ䳤�����ֵΪ0
    v1.resize(10,2);    //Ĭ�ϱ䳤�����ֵΪ2

    for_each(v1.begin(),v1.end(),print);

    if(!v1.empty())//�ж��Ƿ�Ϊ��
    {
        cout << "��Ϊ��" << endl;
    }


    vector<int> v2;
    //����֪��Ҫ һ��ȷ���Ĵ�С����1�򣩣������ֱ��ѡ��Ԥ��1��Ŀռ䣬������ÿ����һ��Ԫ�ؾ�������ƥ��Ŀռ��š�
    v2.reserve(100);    //Ԥ�趨����
    cout << v2.size() << endl;      //0
    cout << v2.capacity() << endl;  //100�����ȸ�������չ��100��
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector ���ݴ�ȡ����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//at(int idx);//��������idx ��ָ�����ݣ����idx Խ�磬�׳�out_of_range �쳣��
//operator[];//��������idx ��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
//front();//���������е�һ������Ԫ��
//back();//�������������һ������Ԫ��
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
    cout << v1.front() << endl;//���ص�һ��Ԫ��
    cout << v1.back() << endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector �����ɾ��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//insert(const_iterator pos, int count,ele);//������ָ��λ��pos ����count ��Ԫ��ele.
//push_back(ele);//β������Ԫ��ele
//pop_back();//ɾ�����һ��Ԫ��
//erase(const iterator start, const iterator end);//ɾ��ѡ������start ��end ֮���Ԫ��
//erase(const iterator pos);//ɾ��ѡ����ָ���Ԫ��
//cLear();//ɾ������������Ԫ��

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

//    v1.pop_back();//βɾ
    v1.erase(v1.begin()+3,v1.end());

    v1.insert(v1.begin()+2,3,9);    //��+2λ�ò���3��9
    v1.erase(v1.begin()+3);         //ɾ��ָ��Ԫ��
    for_each(v1.begin(),v1.end(),print);
    v1.clear(); //ɾ������Ԫ��
    for_each(v1.begin(),v1.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//swap �����ռ�
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
    v1.resize(10);//size���10�ˣ��������䣬���˷Ѻܶ�1�ռ�
    cout << v1.size() <<" "<< v1.capacity()<< endl;
    vector<int>(v1).swap(v1); //������������������,������v1��ʼ����v1�м���Ԫ�أ���������Ϳ��ٶ��ڴ�С�Ŀռ䣩���ڽ��ó�ʼ���ռ�ͬv1������
    cout << v1.size() <<" "<< v1.capacity()<< endl;
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//vector Ԥ�⿪�ٴ���
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
    //����ÿһ����������ռ䣬��Ԫ�ص�ַ����ı䣬��ôֻ��Ҫ������Ԫ�ص�ַ�ı�Ĵ������ɡ�
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
//vector ����
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

//    sort(v1.begin(),v1.end());//��С��������
    sort(v1.begin(),v1.end(),compare);//a>b�ǴӴ�С����a < b�Ǵ�С����
    //algorithm����õ�sort���������ʵ�����صģ���������дһ���ص�������
    for_each(v1.begin(),v1.end(),print);
}

//������� �Զ�����󣿣�
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
//    return p1.age > p2.age;   //�Ӵ�С
    return p1.age < p2.age;
}
void test1()
{
    vector<Person> v;
    Person p1(10,"��");
    Person p2(40,"����");
    Person p3(50,"������");
    Person p4(20,"����");
    Person p5(30,"����");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for_each(v.begin(),v.end(),print1);

    //����
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
//deque����api
//deque�����Ĺ��캯��
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

//deque<T> deqT; //Ĭ�Ϲ�����ʽ
//deque(beg,end); //���캯����[beg,end)�����е�Ԫ�ؿ���������
//deque(n��elem);//���캯��n ��elem ����������,
//deque(const deque &deq);//�������캯����
void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
{
    cout << a << endl;
}
void test()
{
    deque<int> d1;  //Ĭ�Ϲ���
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    deque<int> d2(d1); //��d1����ʼ��d2
    deque<int> d3(d1.begin(),d1.end()); //��d1�Ŀ�ʼ��������ʼ��d3
    deque<int> d4(10,8);                //10��8

    for_each(d4.begin(),d4.end(),print);
}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//deque�����ĸ�ֵ����
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
    deque<int> d1;  //Ĭ�Ϲ���
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
//deque�����Ĵ�С����
/*
//deque.size();       //����������Ԫ�صĸ���
//deque.empty();      //�ж������Ƿ�Ϊ��
//deque.resize(num);  //����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á�����������,��δβ�����������ȵ�Ԫ�ر�ɾ����
//deque.resize(num,elem);//����ָ�������ĳ���Ϊnum,�������䳤,����elem ֵ�����λ��,���������̡���δβ�����������ȵ�Ԫ�ر�ɾ����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
{
    cout << a << endl;
}

void test()
{
    deque<int> d1;  //Ĭ�Ϲ���
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);

    cout<< d1.size() <<endl;    //dequeֻ�д�С��û��������˵����
    if(!d1.empty())
    {
        cout << "��Ϊ��" << endl;
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
//deque������˫��ɾ������
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

void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
{
    cout << a << endl;
}

//push_back(elem);    //������β�����һ������
//push_front(elem);   //������ͷ������һ������
//pop_back();         //ɾ���������һ������
//pop_front();        //ɾ��������һ������

void test()
{
    deque<int> d1;
    //ͷ��
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    //β��
    d1.push_front(4);
    d1.push_front(5);
    d1.push_front(6);
    for_each(d1.begin(),d1.end(),print);

    //βɾ
    d1.pop_back();
    //ͷɾ
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
//deque�����Ĵ�ȡ����
/*

//at(idx);//��������idx ��ָ�����ݣ����idx Խ�磬�׳�out_of_range��
//operator[];//��������idx ��ָ�����ݣ����idx Խ�磬���׳��쳣��ֱ�ӳ���
//front();//���ص�һ�����ݡ�
//back();//�������һ����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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
//deque�����Ĳ������
/*
//insert(pos,elem);//��pos λ�ò���һ��elem Ԫ�صĿ��������������ݵ�λ��,pos�Ǵ�һ��������
//insert(pos,n,elem);//��pos λ�ò���n��elem ���ݣ��޷���ֵ��
//insert(pos,beg,end);//��pos λ�ò���[beg,end)��������ݣ��޷���ֵ��

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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

    d1.insert(d1.begin()+1,10); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)
    d1.insert(d1.begin()+1,3,2); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)
    d1.insert(d1.begin()+1,10); // ��Ҫ���� ������//insert(iterator __position, const value_type& __x)

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
//deque������ɾ��
/*
//clear();//�Ƴ���������������
//erase(beg,end);//ˢ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//erase(pos);//ɾ��pos λ�õ����ݣ�������һ�����ݵ�λ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void print(int a)//��ӡ����ʲô���ͣ��ʹ�ʲô���Ͳ���
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

    //βɾ
    d1.pop_back();
    //ͷɾ
    d1.pop_front();
    //ȫɾ
    d1.clear();
    //ɾ����
    d1.erase(d1.begin()+2,d1.end());
    //ɾĳһ��
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
//����:ѡ��ABCDE��10 ����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
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

//1.����һ��ѡ����
class Player
{
public:
    //�޲ι���
    Player(){}
    //�вι���
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

void start_play(vector<Player> &v)      //v������
{
    srand((unsigned int)time(NULL));//�������������ֵʱ���֡�

    //���� ��ʱdeque���������ڲ���
    deque<int> d;

    //v������,it������ָ��(������)��it��ָ���� Player,����it����Player��Աʱ��Ӧ����ʹ��->��
    for(vector<Player>::iterator it = v.begin();it != v.end();it++)
    {
        //�õ�һ��deque�����������ɵ�10�������װ��deque������
        for(int i = 0;i < 10;i++)
        {
            d.push_back(60+rand()%41);
        }

        //��deque�������в�����ȥ����ߺ���ͷ�
        sort(d.begin(),d.end());//С->��
        d.pop_back();   //βɾ
        d.pop_front();  //��ɾ

        int sum = 0;

//        for(int i = 0;i<d.size();i++)
//        {
//            sum += d[i];
//        }
        //����deque�����������ܺ�
        for(deque<int>::iterator it1 = d.begin();it1 != d.end();it1++)
        {
            sum += *it1;
        }
        //��ƽ��
        int aver = sum / d.size();
        //��ƽ��ֵ��ֵ���� it������ ָ���  Player���������score��Ա����
        //ע�⣺v������,it������ָ��(������)��it��ָ���� Player,����it����Player��Աʱ��Ӧ����ʹ��->��
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
        Player tmp(strname,0);  //����һ�����󣬴����� ����ʼ��ֵ0
        v.push_back(tmp);       //�Ѷ���ŵ�������
    }
}

int main()
{
    //2.����һ��vector����v������ȡѡ��
    vector<Player> v;
    //3.��ʼ��ѡ�֣���ѡ�����ַ�����ֵ��,����Ϊ��������
    Init_Player(v);
    //������ӡ
    print_player(v);
    //��ʼ������
    start_play(v);
    print_player(v);
    return 0;
}
*/
//#######################################################
//deque������ɾ��
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

//��������
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


//��������������������ôʹ�ã�
void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    //���򴫺���
    sort(v.begin(),v.end(),compare);
    //���򴫶���
    sort(v.begin(),v.end(),Compare());

    //������
    for_each(v.begin(),v.end(),print);

    //���ﴫ�ı�������������Print()��
    for_each(v.begin(),v.end(),Print());//����������Print(),
//    //����ʵ�����ǣ�
//    void For_each unchecked( InIt _First, InIt _Last,Fnl& _Func)
//    {
//        for(;_First != Last; ++First)
//            _Func (* First);      //����������operator() ��������ˣ���ֱ�����õ������ǵ���������Ȼ��ʹ�����ص�(),�Ѳ���ֱ�Ӵ�������
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
//ν��
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
    void operator()(int a)  //��������һԪν��
    {
        cout << a << endl;
    }
};

class Compare
{
public:
    bool operator()(int a, int b)   //�������ض�Ԫν��
    {
        return a > b ;
    }
};
bool greater2(int a)    //��ͨ���� һԪν��
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
//    //���򴫶���
//    sort(v.begin(),v.end(),Compare());
//    //���ﴫ�ı�������������Print()��
//    for_each(v.begin(),v.end(),Print());//����������Print(),

}
int main()
{
    test();
    return 0;
}
*/
//#######################################################
//�ڽ���������
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

//negate<int> p; ʵ�ʣ�
//template<class T>
//class negate
//{
//public:
//    T operator() (T a)
//    {
//        return a�ķ�����
//    }
//}

void test()
{
    //ȡ��
    negate<int> p;  //����һ����������p
    cout << p(5) << endl;
    cout << negate<int>() (5) << endl;

    //�ӷ�
    cout << plus<int>() (4,5) << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    //��������
    sort(v.begin(),v.end(),greater<int>());
    //С������
    sort(v.begin(),v.end(),less<int>());

}

int main()
{
    test();
    return 0;
}
*/
//#######################################################
//��������������
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

//1.���ڣ�����for_each�ڴ�ӡ��ʱ�򣬴�һ��a�� num������������,����Ҫ������num��ֵ��Print()�������������а󶨡�
//3.�̳У��̳��ַ�ΪһԪ�̳кͶ�Ԫ�̳С�����operator����������������Ƕ�Ԫ�̳С�

//4.һԪ�̳У�unary_function<����1������ֵ����>
//5.�̳У�public binary_function<����1,����2,����ֵ����>


class Print:public binary_function<int,int,void>
{
public:
    //6. ��operator()() �����const��
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
    //2.����һ���󶨲��� bind2nd    ���ַ��� 200������num
//    for_each(v.begin(),v.end(),bind2nd(Print(),200));

    //7.���������󶨲��� bind1st    ���ַ��� 200������a
    for_each(v.begin(),v.end(),bind1st(Print(),200));
}

int main()
{
    test();
    return 0;
}
*/









