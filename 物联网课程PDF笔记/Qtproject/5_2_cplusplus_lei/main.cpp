/*
    4����Ͷ���
        4.1��Ͷ���Ļ�������
            4.1.1 c �� c++�� struct����
                c  �� struct ֻ�б���            ��c�����нṹ�岻�ܴ�ź�����Ҳ���� ���� �� ��Ϊ �Ƿ���ģ�
                c++�� struct���б�����Ҳ�к���    ��c++ �нṹ���ǿ��Դ�ź����ģ���  ���� �� ��Ϊ �Ƿ�װ��һ��ģ�

            4.1.2 ��ķ�װ
                4.1.2.1 ��
                ���Ǳ�д�����Ŀ����Ϊ�˽����ʵ�е����⣬����Щ����Ĺ��ɣ������ɸ���������ɣ������ڼ������Ҫ����������⣬����Ҫ������Ҫ���������Ĳ�����:�º�����󵽼���������У�Ҳ�����ó������Ա�ʾ��ʵ�����
                ��ô��������������ó�����������ʾ��ʵ����?��ʵ��������������еĹ��Ծ���ÿ�����ﶼ������������ԣ�һЩ������е���Ϊ��������������ܰ���������Ժ���Ϊ��ʾ��������ô�Ϳ��Գ������������

                ��c�����У����ǿ�����ô��ʾ���������:
                  #include <iostream>
                  using namespace std;
                  //c���ԵĽṹ�岻�ܷź���
                  struct stu
                  {
                      int a;
                      int b[5];
                  }
                  //c++�п��Էź���
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
                      //ѧ�������� �� ����
                      int age;
                      int id;
                      char name[256];
                      //�������ԵĽ��� ���� �� ��Ϊ -- ����

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
                4.1.2.2 c�����б�ʾ����ķ������ڵ�����
                    ���磺 ���Ժ���Ϊ�ֿ����ܵ��£���Ϊ�����˵��á����³����߼�����
                        #include <stdio.h>
                        #include <string.h>
                        //��ʾ��
                        struct Person
                        {
                            int age;
                            char name[128];
                        };

                        void Person_eat(struct Person* p)
                        {
                            printf("%s �ڳԷ�\n",p->name);
                        }

                        //��ʾ��
                        struct Dog
                        {
                            int age;
                            char name[128];
                        };

                        void Dog_eat(struct Dog* p)
                        {
                            printf("%s �ڳ�ʺ\n",p->name);
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

                            //�˵����˹�����Ϊ���������Ժ���Ϊ�ֿ������ܵ�����Ϊ�����˵��á�
                            Dog_eat(&p1);


                        }
                        int main()
                        {
                            test01();
                        }
                4.1.2.3  c++ �� ���������ķ�װ�����ṹ���װ�޷����Ʒ���Ȩ�ޣ�Ĭ��ȫ���������װ���Կ��Ʒ���Ȩ�ޣ�Ĭ��ȫ˽�ܣ�
                        * c++����������Ժ���Ϊ��װ��һ��
                        * ��ͽṹ���һ���������ڣ��� �Գ�Ա ���Խ��з��ʵ�Ȩ�޿��ƣ����ṹ�岻�С�
                        * �� = ���ͣ��������Ϊ�����ԣ�  ��ʵ���������ı�����������
                        * ���еĺ��� ���Է��� �� ������ĳ�Ա��

                ���磺
                    // c++ ���������ķ�װ��
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    using namespace std;

                    //c++ �ж�����ķ�װ�������� �� ��Ϊ ��װ��һ��
                    //�� �������������Ժ���Ϊ������ ��װ��һ��   ��struct ��Ϊ class
                    //struct Person
                    //{
                    //    //�˵�����
                    //    int age;
                    //    char name[128];
                    //    //�˵���Ϊ
                    //    void Person_eat()
                    //    {
                    //        cout << name<<"�Է�"<<endl;
                    //    }
                    //};

                    //struct �� class ������
                    // �������еĳ�Ա ����Ȩ�޶���˽�еģ�private����ֻ�����ڷ��ʣ������޷����ʡ�
                    // ���ṹ�������еĳ�Ա��Ĭ�϶��ǹ��еģ����е����г�ԱĬ����˽�еġ�Ҳ�����޸ĳ�Ա����Ȩ�޵����ԣ�public:
                    class Person
                    {

                        //�˵�����
                    public:
                        int age;
                        char name[128];
                        //�˵���Ϊ
                        void Person_eat()
                        {
                            cout << name<<"�Է�"<<endl;
                        }
                    };

                    struct Dog
                    {
                        //�˵�����
                        int age;
                        char name[128];
                        //�˵���Ϊ
                        void Dog_eat()
                        {
                            cout << name<<"�Է�"<<endl;
                        }
                    };

                    void test01()
                    {
                        //ͨ���� ʵ������һ����������������ж���
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

            4.1.3  ����Ա��������Ϊ private
                1.�ɸ��ӿͻ��˷������ݵ�һ���ԡ�
                    �����Ա�������� public���ͻ���Ψһ�ܹ����ʶ���ķ�������ͨ����Ա������
                    ����������� public Ȩ�޵ĳ�Ա  ���Ǻ������ͻ��ڷ������Աʱֻ��Ĭ�Ϸ��ʺ���������Ҫ���Ƿ��ʵĳ�Ա�費��Ҫ���(),���ʡ�������ɦ��Ū����ʱ�䡣

                        public:     //���еģ����� ���� ���ɷ���
                            int tall;//��ߣ�����������֪��
                        protected:  //�����ģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    �ڼ̳��У�������Է���
                            int money;//�ж���Ǯ��ֻ�ܶ���֪��
                        private:    //˽�еģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    ���಻�ɷ���
                            int Age;  //��������֪��

                2.��ϸ΢���ַ��ʿ��ơ�
                    �������ó�Ա����Ϊ˽��Ȩ�ޡ�
                        ���ó�ԱΪ˽�е��ŵ㣺
                            *�Ա��������÷�Χ�Ŀ��ơ�
                            *���Ը���������ֻ��Ȩ��
                            *���Ը���������ֻдȨ��
                            *���Ը��������ö�дȨ��
                    ʹ�ó�Ա���� ��ʹ�����ǶԱ����Ŀ��ƴ�����Ӿ�ϸ��������������еĳ�Ա����Ϊpublic��ÿ���˶����Զ�д���������������Ϊ private�����ǿ���ʵ�֡���׼���ʡ�����ֻ������"������д����"�����������д��"ֻд���ʡ���

                        class AccessLevels{
                        public:
                            //��ֻ�����Խ���ֻ���ü�
                            int getReadonly(){ return readOnly;}

                            //�Զ�д���Խ��ж�д����
                            void setReadWrite(int val){readWrite = val;}
                            int  getReadWrite() {return readWrite;}

                            //��ֻд���Խ���ֻд����
                            void setWriteOnly(int val) {writeOnly = val;}
                        private:
                            int readOnly; //����ֻ������
                            int noAccess; //�ⲿ���ɷ���
                            int readWrite;//��д����
                            int writeOnly;//ֻд����
                        protected:
                            ;
                        };
            ���磺
                //�� ��Ա�� Ȩ�޿���

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
                public:     //���еģ����� ���� ���ɷ���
                    int tall;//��ߣ�����������֪��
                protected:  //�����ģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    �ڼ̳��У�������Է���
                    int money;//�ж���Ǯ��ֻ�ܶ���֪��
                private:    //˽�еģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    ���಻�ɷ���
                    int Age;  //��������֪��
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

            4.1.4 ��ϰ��
                ���һ��Person�࣬����name �� age ���ԣ��ṩ��ʼ������ Init,���ṩ�� name �� age �Ķ�д������set��get��
                ������ȷ��age ��ֵ����Ч��Χ��0-100����������Χ��ܾ���ֵ�����ṩ����������ֺ�����
        ����
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

        4.2 ������������ư���
            4.2.1 �����������
                ����������ࣨCube),���������������2ab + 2ac +2bc���������a*b*c�����ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
            ������
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

                    //�����
                    int get_cube_V()
                    {
                        return L*W*H;
                    }
                    //�����
                    int get_cube_S()
                    {
                        return 2*W*L+2*W*H+2*L*H;
                    }
                    //�ж������������Ƿ����
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
                       cout<< "�������������"<<endl;
                   }
                   else
                   {
                        cout<< "���������岻���"<<endl;
                   }

                   if(compare_cube(c1,c2))
                   {
                       cout<< "�������������"<<endl;
                   }
                   else
                   {
                        cout<< "���������岻���"<<endl;
                   }

                }


                int main()
                {
                    test01();

                    return 0;
                }
            4.2.2 ���Բ�Ĺ�ϵ
                ���һ��Բ����(AdvCircle)����һ������(Point)��������Բ�Ĺ�ϵ��
                ����Բ������Ϊ x0,y0,�뾶Ϊr���������Ϊ x1, y1:
                    1)����Բ��:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)==r*r
                    2)����Բ��:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)<r*r
                    3)����Բ��:(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)>r*r
            ������
                //���Բ�࣬�жϾ���
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                using namespace std;

                //����
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

                //Բ��
                class Circle
                {
                public:
                    void setP(int x,int y){
                        mP.setX(x);
                        mP.setY(y);
                        }
                    void setR(int r){mR=r;}
                    Point& getP(){return mP;}//����Բ�ĵ�ʱ�����ص��Ǳ���
                    int getR(){return mR;}//���ذ뾶

                    //�жϵ��Բ�Ĺ�ϵ
                    void IsPointInCircle(Point& point)//�������
                    {
                        int distance = ((point.getX()-mP.getX()) * (point.getX()-mP.getX())+(point.getY()- mP.getY())*(point.getY()- mP.getY()));
                        int radius =mR*mR;
                        if(distance< radius){
                            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
                        }
                        else if(distance > radius){
                            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
                        }
                        else
                        {
                            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
                        }
                    }
                private:
                    Point mP; //Բ��
                    int mR; //�뾶
                };

                void test(){
                    //ʵ����Բ����
                    Circle circle;
                    circle.setP(20,20);
                    circle.setR(5);
                    //ʵ���������
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
    4.3 ����Ĺ��������
        4.3.1 ��ʼ�� �� ����
            ��Ʒ����һ����ʼ���ã�Ҳ������Щ��Ʒ�Ա�������ʱ�����һ����������ֵ������ʱ��Խ�ã��������ܶ��ļ����ݣ�������ʹ�ã���Ӧ�����ӵ�����ɾ�����������Լ�����Ϣ���ݡ�
            �ɴˣ����е������������ʱ��Ӧ���и���ʼ״̬����������������ʹ��ʱ��Ӧ��ʱ�����������������һЩ��Ϣ���ݡ�

            ��ô���� c++������˼��Ҳ����Դ����ʵ���Ƕ���ʵ����ĳ���ģ�⣬������˵�������Ǵ��������ʱ��,����Զ���Ӧ����һ����ʼ״̬������������֮ǰӦ�������Լ�������һЩ���ݡ�
            ����ĳ�ʼ��������Ҳ�������ǳ���Ҫ�İ�ȫ���⣬һ��������߱���û�г�ʼ״̬ʱ������ʹ�ú����δ֪��ͬ��,ʹ����һ��������û�м�ʱ����Ҳ�����һ���İ�ȫ���⡣

            c++Ϊ�˸������ṩ��������Ľ�����������캯�� �� �����������������������ᱻ�������Զ����ã���� �����ʼ�� �� �������� ������
            �������Ƿ�ϲ��������ĳ�ʼ�����������Ǳ�����ǿ������Ҫ�������飬��ʹ�㲻�ṩ��ʼ���������������,������Ҳ���������Ĭ�ϵĲ�����ֻ�����Ĭ�ϳ�ʼ�������������κ��£����Ա�д �� ��Ӧ��˳���ṩ��ʼ��������

            Ϊʲô��ʼ�������� �Զ����� ������ �ֶ����� ?��Ȼ�Ǳ����������ô�Զ����û���ã����������Ա�Ծ�����ô�ͻ������©��ʼ����������֡�

        4.3.2 ���캯�� �� ��������
            ���캯�� ��Ҫ���� ��������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ����á�
            �������� ��Ҫ���� ��������ǰ��ϵͳ�Զ����ã�ִ��һЩ��������

            ���캯���﷨:
                ���캯�� ������ �� ������ͬ��û�з���ֵ��������void���������в�����
                ClassName(){}

                ���������﷨��
                ����������������������ǰ��� �� ~ ����ɣ�û�з���ֵ��������void �������в������������ء�
                ~ClassName(){}
        �ܽ᣺
            ���캯����
                * û�з���ֵ
                * ������ �� ���� һ��
                * �в������ҿ����ж��������
                * ���Ժ�������
                * ��������ʱ�����캯���Զ����á�

            ��������
                * û�з���ֵ
                * ������������ǰ �� ��~��
                * û�в���
                * ���ܷ�������
                * ��������ǰ�Զ�����
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>

                using namespace std;

                class Person{
                    public:
                        int m_age;
                        //string �ַ����࣬ͷ�ļ�:  #include <string>
                        string m_name;//�ɸ�ֵΪ char* ��ָ�� ���� �ַ�����

                        //���캯���������� �� ���� һ�£��޷���ֵ�������в������ɺ������ء�
                        Person(int age,string name)
                        {
                            m_age = age;
                            m_name = name;
                            cout<<"���캯����"<<endl;
                        }

                        //���������������� �� ���� ǰ�ӡ� ~ ����û�з���ֵ�������в��������ܷ������ء�
                        ~Person()
                        {
                            cout<<"����������"<<endl;
                        }
                };

                void test()
                {
                    //���캯������ ʵ��������ʱ�������������ڴ� ���ٿռ� ʱ���á�
                    //���캯���Ĵ��� ������ �������Σ���ֱ�ӣ�Person p1(30,"lisa")
                    Person p1(30,"lisa");

                    //p1��������ʱ�����٣����������� ������ ����ʱ�Զ����á�
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.3 ���캯�� �ķ��� �� ����
            ���������ͣ��޲������캯�� �� �вι��캯��
            �����ͷ��ࣺ��ͨ���캯��   �� �������캯�������ƹ��캯����

            �������캯����д��:
                ������const ���� &obj��{}

            ע�⣺���Զ����� ��ͨ���캯�����вλ��޲Σ��������ṩ��ͨ���캯��
                 ���Զ����� �������캯���������ṩĬ�ϵĿ������캯����
                 Ĭ�ϵĿ������죬�Ǽ򵥵�Ĭ�� ֵ������
                 ����������ʱ�����ܵ��ö�Ӧ�Ĺ��캯���������ܴ��������󡣣��������вε�û���޲Σ���p1������������

        ����:
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //�޲ι���
                Person()
                {
                    cout << "�޲ι���!" << endl;
                }

                //�вι���
                Person(int age,string name)
                {
                    cout << "�вι���" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
                //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
                Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"��������"<<endl;
                }
            };

            void test()
            {
                //ע�⣺ʹ���޲ι���ʱ�����ܼ����š�
                //�����Ϊ�ṩ���вκ��޲ι��죬ϵͳ�������ṩĬ�ϵ��޲ι���
                //����Ϊû�ṩ���캯������ϵͳĬ������һ�����޲ι��졣
                Person p1;
                Person p2(30,"Lisa");

                Person p3(p2);//����ϵͳĬ���ṩ�Ŀ������죺
                //�����������ʱ�����ɶ����ʼ���¶���

                 cout<<p3.m_age<<"  " << p3.m_name <<endl;
            }
            int main()
            {
                test();
                return 0;
            }
        4.3.4 �������캯���ĵ���ʱ��
            1.����������ã�
                //��������û�����֣������������ڵ�ǰ�С�
                Person(10,"lucy");//�����вι��촴����������
                Person();//������������޲ι�����Ҫ������
                Person p1(10,"lisa");
                //Person(p1);//������������ ����ʹ�� ���ŷ� ���� �������졣
            2.��ʾ�����ã�
                Person p1 = Person(10,"lucy");//ֻ������ һ�� �вι��� �� һ�� �������������вι��� �� �������� ���õġ�  ��p1 �������ȥ���� �������� ������Ŀռ䡣��û���ٴ���һ���������ÿ������죩
                Person P2 = Person(p1);       //��ʾ�� ���� �������캯��
                Person P3 = Person();         //��ʾ�� ���� �޲ι���
            3.��ʽ�����ã�
                Person p1 = {10,"lucy"};      //��ʽ�� ����    �вι���
                Person P2 = p1;               //��ʽ�� ����    ��������
                Person P3;                    //��ʽ�� ���ܵ��� �޲ι���

            �ؼ��֣�explicit�����ι��캯��������ͨ����ʽ�����ù��캯����

        ���磺
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //�޲ι���
                explicit Person()
                {
                    cout << "�޲ι���!" << endl;
                }

                //�вι���
                explicit Person(int age,string name)
                {
                    cout << "�вι���" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
                //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
                //�ؼ��֣�explicit�����ã��û�����ͨ����ʽ�����ù��캯��
                explicit Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"��������"<<endl;
                }

                ~Person()
                {
                    cout << "��������" << endl;
                }
            };

            void test()
            {
                //��������û�����֣������������ڵ�ǰ�С�
                Person(10,"lucy");//�����вι��촴����������
                Person();//������������޲ι�����Ҫ������
                Person p1(10,"lisa");
                //Person(p1);//������������ ����ʹ�� ���ŷ� ���� �������졣
            }

            //��ʾ�����ù��캯��
            void test1()
            {
                Person p1 = Person(10,"lucy");//ֻ������ һ�� �вι��� �� һ�� �������������вι��� �� �������� ���õġ�  ��p1 �������ȥ���� �������� ������Ŀռ䡣��û���ٴ���һ���������ÿ������죩
                Person P2 = Person(p1);       //��ʾ�� ���� �������캯��
                Person P3 = Person();         //��ʾ�� ���� �޲ι���
            }

            //��ʽ�� ���� ���캯��
            //���� ���˲���ʹ����ʽ�� ��������Ĺ��캯��������ڹ��캯��ǰ �ӹؼ��֣�explicit���û�����ͨ����ʽ�����ù��캯��
            void test2()
            {
            //    Person p1 = {10,"lucy"};      //��ʽ�� ����    �вι���
            //    Person P2 = p1;               //��ʽ�� ����    ��������
            //    Person P3;                    //��ʽ�� ���ܵ��� �޲ι���
            }
            int main()
            {
                test1();
                return 0;
            }

        �������캯���ĵ���ʱ��
            �ܽ᣺��һ��������ɶ��� ��ʼ�� �¶���
            ���ࣺ
                * �ɶ����ʼ���¶���
                * �β�  ��Ϊ����
                * ����ֵ��Ϊ����
        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            using namespace std;

            class Person
            {
            public:
                //�޲ι���
                explicit Person()
                {
                    cout << "�޲ι���!" << endl;
                }

                //�вι���
                explicit Person(int age,string name)
                {
                    cout << "�вι���" <<endl;
                    m_age = age;
                    m_name = name;
                }
                int m_age;
                string m_name;

                //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
                //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
                //�ؼ��֣�explicit�����ã��û�����ͨ����ʽ�����ù��캯��
                Person(const Person &p)//Person p = p2;
                {
                    m_age = p.m_age;
                    m_name = p.m_name;
                    cout<<"��������"<<endl;
                }

                ~Person()
                {
                    cout << "��������" << endl;
                }
            };

            //1.�ɶ����ʼ���¶���
            void test1()
            {
                Person p(10,"lili");
                Person p1(p);   //���ÿ�������
                Person p2 = Person(p);//��ʾ������ �������캯��
                Person p3 = p;//��ʽ�����ÿ������죬�൱�� Person p2 = Person(p);
            }

            //2.���ݵĲ�������ͨ���󣬺�������Ҳ����ͨ���󣬴��ݽ�����ÿ������졣
            void doBussiness(Person p){}    //Person p = p;

            void test2()
            {
                Person p(20,"lisa");//�вι����ʼ��
                doBussiness(p); //�������죬�ɶ����ʼ���¶���
            }

            //3.���� ����ֵ������ֵ�ֲ�����
            Person MyBusiness()
            {
                Person p(30,"lihua"); //�вι��� ��ʼ���ֲ�����
                cout << "�ֲ�p:"<<(int *)&p <<endl;   //����ֲ�����ĵ�ַ
                return p;   //���ﷵ�ص�ʱ�� Ӧ�õ���һ�ο������죬����һ����������
            }

            void test3()
            {
                // vs release�� qt��û�е��ÿ������캯��
                // vs debug �µ���һ�ο������캯��
                Person p = MyBusiness();//���︳ֵ ҲӦ�õ���һ�ο������졣���ڱ��������Ż���ʹ��ֱ�ӽ�p����������������
                //
                cout << "�ֲ�p:"<< (int*) &p << endl; //����ֲ����󷵻صĵ�ַ�����γ������δ�ӡ�ĵ�ַ�ǲ�ͬ�ģ���Ϊ ��������ʱ �ǵ��� �����������죬���¿��ٵ��ڴ�ռ䣩���ҵ�������ַ��һ���ġ�������Ҳֻ����һ�Σ����������Ρ�
            }

            int main()
            {
                test3();
                return 0;
            }

      c++Ĭ�����ӵĺ���
            Ĭ������£�c++����������Ϊ����д��������3������

            1. Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
            2. Ĭ�������������޲Σ�������Ϊ�գ�
            3. Ĭ�Ͽ������캯���������зǾ�̬��Ա���� ��ֵ����
               ����û������˿������캯����         c++�������ṩ�κ�Ĭ�Ϲ��캯��
               ����û���������ͨ���캯�����ǿ�������c++�������ṩ�κ�Ĭ���޲ι��죬�����ṩĬ�Ͽ�������

    4.3.6 ��� �� ǳ����
        4.3.6.1 ǳ����
            �򵥵�ֵ���������ܵ������������ͷ�ͬһ��ռ�
        ����
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
                cout << "�вι���"<<endl;
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
                cout << "����"<<endl;
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
            Person p1(p);//����Ĭ�Ͽ������� ���м�ֵ�������ַ���ָ��ָ��ͬһ���ַ��������е�������ʱ��������������������ֱ�freeͬһ��ַ�����³������
        }
        int main()
        {
            test();
            return 0;
        }

        4.3.6.2 ���
            ���¿����ڴ�ռ����ڴ��
        ����
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
                    cout << "�вι���"<<endl;
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
                    cout << "����"<<endl;
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
                Person p1(p);//����Ĭ�Ͽ������� ���м�ֵ�������ַ���ָ��ָ��ͬһ���ַ��������е�������ʱ��������������������ֱ�freeͬһ��ַ�����³������
            }
            int main()
            {
                test();
                return 0;
            }
*/
/*
    4.3.7 ������� ���� �� ����
        4.3.7.1 ��ʼ���б�
            ���캯�� �� ����������ͬ�����������֣������б�������֮�⣬���г�ʼ���б�
            ��ʼ���б��ʹ�ã�Person(int a,int b, int c):mA(a),mB(b),mC(c){}
                            //�����캯����Ա��ֵ��ʱ�򣬿��԰Ѹ�ֵ�ķ�ʽд�ں����ĺ���
            ע�⣺
                * ��ʼ���б������� �ڵ��ù��캯��ʱ ���� �� ��ʼ�������� ��ʼ����˳�� ��Ҫͬ����һ�¡�
                * ��ͨ�Ĺ��캯�����ȶ��壬�ٸ�ֵ��
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                using namespace std;

                class Person{
                public:
                #if 0
                    //��ͳ��ʽ��ʼ��:�������� ���� ���������������ʼ����ֵ���൱�������Ƕ��壬�����ǳ�ʼ��
                    Person(int a,int b,int c)
                    {
                        mA = a;
                        mB = b;
                        mC = c;
                    }
                #endif
                    //��ʼ���б�ʽ��ʼ��:�� ���� �������ٸ��� ������˳�� ���ж����ʼ�����൱����������ֻ��������������ð�ź������ ���� �� ��ʼ����
                    //ע�⣺���ﶨ���˳�򣬾���ð�ź����˳�򡣶����˳����Ҫͬ������˳��һ�¡�
                    Person(int a,int b, int c):mA(a),mB(b),mC(c){}//�����캯����Ա��ֵ��ʱ�򣬿��԰Ѹ�ֵ�ķ�ʽд�ں����ĺ���

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
        4.3.7.2 ����� ��Ϊ ��Ա
            ������ ��������ݳ�Ա һ�㶼�ǻ������������͡����ǣ����еĳ�Ա Ҳ������ ���󣬽��� �����Ա��
            C++�е�����һ�������ʱ��c++������ ����ȷ������������ �Ӷ���Ĺ��캯����������е��Ӷ��� ��Ĭ�Ϲ���ĺ����������������Զ��������ǡ���������Ӷ���û��Ĭ�ϵĹ������������ָ������ĳ�����캯����ô��?
            ��ô�Ƿ������ ��Ĺ��캯�� ֱ�ӵ��� ��������� ��ɳ�ʼ����?�����������ĳ�Ա������˽�еģ�������û�а취���ʲ���ɳ�ʼ���ġ�
            ����취�ǳ���:����������ù��캯����c++Ϊ���ṩ��ר�ŵ��﷨����  ���캯����ʼ���б�
            �����ù��캯��ʱ�����Ȱ��������Ա���ඨ���е�˳��(�Ͳ����б��˳���޹�)���ε������ǵĹ��캯����
            ����Щ�����ʼ��������ٵ��ñ���ĺ����塣Ҳ����˵��*�ȵ��ö����Ա�Ĺ��캯��*��*�ٵ��ñ���Ĺ��캯��*��
            *���������͹��캯������˳���෴���ȹ��죬��������*

            �ܽ�:
                * �����ж������ʱ,�����˳���� �ȹ���������ٹ�������Ķ���
                * �����ж������ʱ,����ʱ˳���� ���������������������Ķ���
        ��:
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
                    cout << "game �Ĺ��캯��" << endl;
                    gam_name = name;
                }
                ~Game()
                {
                    cout<< "game ������"<<endl;
                }
                string gam_name;
            };
            class Phone
            {
            public:
                //���캯����
                Phone(string name)
                {
                    cout << "phone �Ĺ��캯��" << endl;
                    pho_name = name;
                }
                ~Phone()
                {
                    cout<< "phone ������"<<endl;
                }
                string pho_name;


            };
            class Person
            {
            public:
                //������ôд���ȶ����������������������û���޲ι��죬���Զ����������Ҫʹ�� ��ʼ���б������г�ʼ��

//                Person(string per_name1,string pho_name1,string gam_name1)
//                {
//                    per_name = per_name1;
//                    phone.pho_name = pho_name1;
//                    game.gam_name = gam_name1;
//                }

                Person(string per_name1,string pho_name1,string gam_name1):per_name(per_name1),phone(pho_name1),game(gam_name1){
                    cout << "person �Ĺ��캯��" << endl;
                }

                void show()
                {
                    cout << per_name<<"����" <<phone.pho_name<<"��"<<game.gam_name << endl;
                }

                ~Person()
                {
                    cout<< "person ������"<<endl;
                }
                string per_name;
                Phone phone; //һ��������Ϊ��һ������ĳ�Ա��
                Game game;
            };

            void test()
            {
                Person p1("Bob","ŵ����","ԭ��");
                p1.show();
            }
            int main()
            {
                test();
                return 0;
            }

            //phone �Ĺ��캯��
            //game �Ĺ��캯��
            //person �Ĺ��캯��
            //Bob����ŵ������ԭ��
            //person ������
            //game ������
            //phone ������
            //�ɴ�֪,�ȹ���������ڹ��������,����������������������
*/

/*

    4.3.8 explicit �ؼ���
        c++ �ṩ�˹ؼ��� explicit,��ֹͨ�����캯��������ʽת��������Ϊexplicit�Ĺ��캯����������ʽת����ʹ�á�
        ע�⣺
            explicit �������ι��캯������ֹ��ʽת��
            ����Ե������Ĺ��캯�������߳��˵�һ�������������������Ĭ��ֵ�Ķ�ι��죩���ԡ�
 */

/*
    4.3.9 ��̬���󴴽�
        ����������ʱ������Ҫ��ǰԤ�����鳤�ȣ��ٱ���������Ԥ�����ȵ�����ռ䣬��ʹ������ʱҲ��ռ�̫����㣬�������ܸ�����Ҫ���з���ռ��С�ͺ���
        ���� ��̬ ��Ϊ ��ȷ���ԡ�
        Ϊ�˽���ñ�����⣬�������п��Դ��������ٶ������������Ҫ�󣬵�Ȼc����ṩ�˶�̬�ڴ���䣬Ȼ������Щ������c++�в��ܺܺõ����У���Ϊ�����ܰ�������ɶ���ĳ�ʼ��������

        ������malloc��free�ڴ��������ٿռ��ʱ�� ������ù������������������漰������Ķ�̬����������new��delete��
        ���磺
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
                        cout << "Person ���޲ι���" << endl;
                    }
                    int a;
                    ~Person()
                    {
                        cout << "Person ����������" << endl;
                    }
                };

                void test()//��������ʱ ������ù������������
                {
                    Person *p = (Person *)malloc(sizeof(Person));
                    free(p);
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.9.1 ���󴴽�
            ������һ��c++����ᷢ��������
            1. Ϊ��������ڴ�
            2. ���ù��캯�� ����ʼ�� ���ڴ�

            ��һ��һ����ʵ�֣�������ȷ���ڶ���һ���ܷ�����c++ǿ��������ô������Ϊʹ��δ��ʼ���Ķ����ǳ�������һ����Ҫԭ��

            ���� *p = new ����;
            delete p;

            ���� *p = new ����[n]
            delete []p;

        4.3.9.2 C��̬�����ڴ淽��
            Ϊ��������ʱ��̬�����ڴ棬c�����ı�׼�����ṩ��һЩ������malloc�Լ����ı��� calloc��realloc�ͷ��ڴ��free,��Щ��������Ч�ġ���ԭʼ�ģ���Ҫ����Ա����С��ʹ�á�(Ϊ��ʹ��c�Ķ�̬�ڴ���亯���ڶ��ϴ���һ�����ʵ�������Ǳ�����������)

            ���⣺
                1. ����Ա����ȷ������ĳ��ȡ�
                2. malloc����һ��voidָ�룬c++������void��ֵ�������κ�ָ�룬����ǿת��
                3. malloc���������ڴ�ʧ�ܣ��ʱ����жȷ���ֵ��ȷ���ڴ����ɹ���
                4. �û���ʹ�ö���֮ǰ�����ס������ʼ�������캯��������ʾ���ó�ʼ�������캯�����ɱ��������ã����û��п������ǵ��ó�ʼ��������

                c�Ķ�̬�ڴ���亯��̫���ӣ��������˻������ǲ��ܽ��ܵģ�c++�������Ƽ�ʹ�������new��delete.

        4.3.9.3 new operatoe
            c++�н����̬�ڴ����ķ����ǰѴ���һ����������Ҫ�Ĳ����������һ����Ϊnew��������
            ��new����һ������ʱ�����ͻ��� �� ��Ϊ��������ڴ沢���ù��캯����ɳ�ʼ��
        �÷���
            ���� * p = new ����;
            Person* person = new Person;

        �൱�ڣ�
            Person* person = (Person *)malloc(sizeof(Person));
            if(person == NULL)
            {
                return 0;
            }
            person->Init();//���캯����

            new������ ��ȷ���ڵ��ù��캯����ʼ��֮ǰ�ڴ�����ǳɹ��ģ����Բ�����ʽȷ�������Ƿ�ɹ���
            �������Ƿ����ڶ��ﴴ������Ĺ��̱�ü��ˣ�һ�����ʽ�������õĳ��ȼ��㡢����ת���Ͱ�ȫ��顣�����ڶѴ���һ���������ջ�ﴴ������һ���򵥡�

        4.3.9.4 delete operator
            new ���ʽ�� ������ delete ���ʽ��delete ���ʽ�ȵ�������������Ȼ���ͷ��ڴ档���� new ���ʽ����һ�� ָ������ָ�� һ����delete ��Ҫһ������ĵ�ַ��
            delete ֻ�������� new �����Ķ���

            ���ʹ��һ���� malloc ���� calloc����realoc�����Ķ���ʹ�� delete,�����Ϊ��δ����ġ���Ϊ����� new �� delete ��ʵ�ֻ��ƶ�ʹ����malloc��free,���Ժܿ���û�е��������������ͷ����ڴ档
            �������ɾ���Ķ����ָ�� �� NULL,���������κ��£���˽�����ɾ��ָ���������ָ�븳ֵΪ NULL���������ɾ�����Σ���һЩ����ɾ�����ο��ܻ����ĳЩ���⡣
        4.3.9.5 ��������� new �� delete
            ʹ��new �� delete �ڶ��ϴ������飺

        4.3.9.6 delete void *���ܻ����
            �����һ��void *ָ��ִ��delete�������⽫���ܳ�Ϊһ��������󣬳���ָ��ָ������ݷǳ��򵥣���Ϊ������ִ�������������������´���δ�����������������¿����ڴ����

        4.3.9.7 ʹ��new��delete������ͬ��ʽ
            ����
                Person *p = new Person[10];
                delete []p;

    new��delete��ʹ�ã�����

            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <string>
            #include <stdlib.h>
            using namespace std;

            class Person
            {
            public:
                Person()//�޲ε���
                {
                    cout << "�޲ι���" << endl;
                }
                Person(int a)//�вε���
                {
                    age = a;
                    cout << "�вι���" << endl;
                }
                int age;
                ~Person()
                {
                    cout << "��������" << endl;
                }
            };

            //newһ����
            void test()
            {
                int *p = new int;//����һ��sizeof(int)��С�Ķѿռ䡣���Ҷ����ռ���г�ʼ����
                cout << *p << endl;//���Ҷ����ռ���г�ʼ��
                *p = 100;
                cout << *p << endl;
                delete p;//�ͷ�����Ŀռ䡣
            }
            //newһ������
            void test1()
            {
                Person * p = new Person;
                delete p;

            }
            //newһ���вι���� ��������
            void test3()
            {
                //newʱ �����вι���
                Person * p =new Person(10);
                delete p;
                Person * a =new Person[10];//ע��new����ʱ�����ܵ����вι��죬ֻ�ܵ����޲ι��졣
                delete []a;//
            }
            //newһ������
            void test2()
            {
                //newһ������ʱ���ص�������Ԫ�ص�ַ��
                int*p = new int[10];
                for(int i = 0;i<10;i++)
                {
                   cout << (p[i] = i+100)<< endl;
                }
                delete []p;//�������дֻ���ͷ��׸�Ԫ�غ���Ԫ�ص�ַ������Ĳ����ͷţ�����ͷ�����ӦдΪ��delete [] p;
            }
            void test4()
            {
                void* p = new Person;
                delete p;   //p������void *���Բ��������������
            }
            int main()
            {
                test2();
                return 0;
            }




*/

/*
  4.3.10 ��̬��Ա
    ���� �����У����ĳ�Ա��������Ա�����ͳ�Ա����������Щ��Ա�����ùؼ���static����Ϊ��̬�ģ���Ϊ��̬��Ա��
    ��������ഴ���˶��ٸ����󣬾�̬��Աֻ��һ������������������������������Ķ�����

    4.3.10.1 ��̬��Ա����
        ��һ�����У�����һ����Ա ��������Ϊstatic �����ֳ�Ա��Ϊ ��̬��Ա������
        ע�⣺
            1. ��̬��Ա���� �� һ������ݳ�Ա ��ͬ�����۽����˶��ٸ����󣬶�ֻ��һ����̬���ݵĿ�������̬��Ա����������ĳ���࣬���ж�����
            2. ��̬���������� ����׶ξͷ���ռ䣬����û�д���ʱ�����Ѿ�����ռ䡣
            3. ��̬��Ա���������� ���� �������� ���� ���塣
            4. ��̬���ݳ�Ա ������ĳ��������Ϊ�������ռ��� ������ ��̬��Ա��ռ�ռ䡣
            5. ��̬���ݳ�Ա ����ͨ�� ���� �� ������ �����á�

           �ܽ᣺
            * ��̬��Ա�������ڴ���ֻ��һ�ݣ����������һ����̬����
            * ��̬��Ա���������������������ⶨ��
            * ��̬��Ա��������ͨ����������������ʣ�
            * ��̬��Ա����������ͨ��ʵ������Ķ��������ʡ�

            ����
                //��̬��Ա����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Person
                {
                  public:
                    int a;       //�ֲ������������н׶ξ�ȷ�������ڴ�ĵ�ַ��
                    //��̬��Ա�������������ڳ�ʼ����ֻ��������������������ȫ�֡�����������ֻ�������˾�̬��Ա�����������򡣲��ң���̬�����Ǵ��ھ�̬ȫ������
                    static int b;//��̬��Ա�������ڱ���׶ξͷ�������ڴ档��ʼ�������������ڳ�ʼ�����磺static int b = 10;�ͻᱨ����Ϊ���ڱ���������ȷ�����˵�ַ����ÿ�ζ�������ʱ��ͻ��޸������ǻ�����
                };
                int b;//����������ȫ�������µı���b������ʾΪPerson���µĳ�Ա
                int Person::b = 10; //����Ӧ�ü�һ��Person��������

                //��̬��Ա������ʵ����ʹ��
                void test()
                {
                    Person p;
                    p.b = 100;
                    cout << p.b <<endl;
                }
                //��̬��Ա������������ʹ�ã�������ͨ��Ա�������жԱ�
                void test1()
                {
                    //����Ҳ�ǿ��Եģ���Ϊ��Ȼû�ж�����󣬵�����b�ڱ���׶ξ��Ѿ�������˿ռ䣬���ҳ�ʼ����ֵΪ10��
                    cout << Person::b <<endl;//ͨ�������������������ľ�̬��Ա����
                    //cout << Person::a <<endl;// ���󣬲��ܷ���a.����ʵ����һ������Ż���a��
                }
                //��̬��Ա��������һ��
                void test2()
                {
                    Person p;
                    p.b = 100;
                    cout << p.b <<endl; //100
                    Person k;
                    k.b = 200;
                    cout << p.b <<endl; //200 ,��˾�̬��Ա��������һ�ݡ�
                }

                int main()
                {
                    test2();
                    return 0;
                }

        4.3.10.2 ��̬��Ա����
            ���ඨ���У�ǰ����static���εĳ�Ա���� ��Ϊ ��̬��Ա��������̬��Ա����ʹ�÷�ʽ�;�̬����һ����ͬ���ڶ�
            ��û�д���ǰ������ͨ���������á���̬��Ա������ҪΪ�˷��ʾ�̬���������ǣ����ܷ�����ͨ��Ա������
            ��̬��Ա���������壬��������Ϣ�������ݹ�ͨ�������ڹ���̬���ݳ�Ա����ɶԾ�̬���ݳ�Ա�ķ�װ��

        ע�⣺
            ��̬��Ա������ʹ�ú;�̬��Ա����һ��: ��ͨ�������� �� �������
            ��̬��Ա����Ҳ�з���Ȩ��
            ��ͨ��Ա���� �ɷ��� ��̬��Ա������Ҳ���Է��ʷǾ�̬��Ա����
            ��̬��Ա���� ֻ�� ���ʾ�̬���������ܷ��� ��ͨ��Ա����
        ����
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

                    //��̬��Ա���������Է��ʾ�̬��Ա���������ܷ��� �Ǿ�̬��Ա��������ͨ��Ա��������
                    //��Ϊ��̬��Ա�����ڱ����ʱ����Ѿ����ˣ���ˣ������������������ã�����Person::static_show()����ʱ���󶼻�û��������û�д���a,��˷��ʲ���a
                    static void  static_show()
                    {
                //        cout << a << " " << b <<endl;//a���ܷ��ʣ�
                        cout << "��̬��Ա������" <<endl;
                    }

                };

                int Person::b = 10;

                void test()
                {
                    Person::static_show();//ͨ�������������ʾ�̬��Ա����

                    Person p1;
                    p1.static_show();//ͨ��������ʾ�̬��Ա����
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.3.10.3 const���εľ�̬��Ա����
            ���һ����ĳ�Ա����Ҫʵ�ֹ�����Ҫʵ�ֲ��ɸı䣬����ʹ�� static const ���Σ����徲̬ const ���ݳ�Աʱ����������ڲ���ʼ����

        �ܽ᣺
            * const ���εľ�̬��Ա���� ������ ����������ֻ���ģ����ڴ���ֻ��һ��
            * const ���εľ�̬��Ա���� ���������ڶ��壬�� ��ʼ�����뾲̬��Ա�����ǲ�ͬ�ģ��������������ⶨ�壩
            * const ���εľ�̬��Ա���� ����ͨ�������������з���
            * const ���εľ�̬��Ա���� ����ͨ��������ʡ�
            * ��̬��Ա���� ���Է��� const ���εľ�̬��Ա������������ʱ����̬��Ա�����Լ����ڣ�

        ����

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

                    //��̬��Ա�������������ڳ�ʼ����ֻ��������������������ȫ�֡�����������ֻ�������˾�̬��Ա�����������򡣲��ң�  ��̬������ ���� ��̬ȫ�������ǿ��Ա��ı�ġ�
                    static int b;//��̬��Ա�������ڱ���׶ξͷ�������ڴ档��ʼ�������������ڳ�ʼ�����磺static int b = 10;�ͻᱨ����Ϊ���ڱ���������ȷ�����˵�ַ����ÿ�ζ�������ʱ��ͻ��޸������ǻ�����

                    const static int c = 1000;// const ���ε�ȫ�ֱ��������ڳ������� ͬ��const ���εľ�̬��Ա���� �Ǳ����� �����������ɱ��޸ģ�ֻ���ģ������ڴ�Ҳ��ֻ��һ�ݡ�const ���εľ�̬��Ա������һ�������������������渳ֵ�����÷���������ʵ�ֶ��帳ֵ��
                    //������������const ���εľ�̬��Ա������ ����ڱ����ʱ��Ҳ������ˣ���̬��Ա��������ֱ�ӷ��ʡ�

                    void show()
                    {
                        cout << a << " " << b <<endl;
                    }

                    //��̬��Ա���������Է��ʾ�̬��Ա���������ܷ��� �Ǿ�̬��Ա��������ͨ��Ա��������
                    //��Ϊ��̬��Ա�����ڱ����ʱ����Ѿ����ˣ���ˣ������������������ã�����Person::static_show()����ʱ���󶼻�û��������û�д���a,��˷��ʲ���a
                    static void  static_show()
                    {
                //        cout << a << " " << b <<endl;//a���ܷ��ʣ�
                        cout << "��̬��Ա������" <<endl;
                        cout << c << endl;
                    }

                };

                int Person::b = 10;

                void test()
                {
                    cout << Person::c << endl;//����ͨ����������з��ʡ�

                    Person p;
                    cout << p.c <<endl;// Ҳ����ͨ������һ�����������ʡ�

                    p.static_show();//��̬��Ա���� Ҳ����ֱ�ӵ��� const ���εľ�̬��Ա������

                }

                int main()
                {
                    test();
                    return 0;
                }
        4.3.10.4 ��̬��Աʵ�� ����ģʽ:��һ����ֻ�ܴ�����һ������
            ������ϯ��λ��ֻ��һ�������Ե�������������������Խ�ʡ��Դ

            ����ģʽ ��һ�ֳ��õ�������ģʽ������Ľṹ��ֻ����һ������Ϊ�����������ࡣͨ������ģʽ ���Ա�֤ϵͳ��һ����ֻ��һ��ʵ�������ң���ʵ�����������ʣ��Ӷ������ʵ�������Ŀ��Ʋ���Լϵͳ��Դ
            ���ϣ����ϵͳ��ĳ����Ķ���ֻ�ܴ���һ��������ģʽ����õĽ��������


            Singleton(����):�ڵ�������ڲ�ʵ��ֻ����һ��ʵ����ͬʱ���ṩһ����̬�� getinstance()�����������ÿͻ����Է�������Ψһʵ��;
            Ϊ�˷�ֹ���ⲿ����ʵ���������� Ĭ�Ϲ��캯�� �� �������캯�� ���Ϊ˽��;
            �� ������ �ڲ�������һ�� singleton ���͵ľ�̬������Ϊ�ⲿ�����Ψһʵ����

            �õ���ģʽ��ģ�⹫˾Ա��ʹ�ô�ӡ����������ӡ�����Դ�ӡԱ��Ҫ��������ݣ����ҿ����ۻ���ӡ��ʹ�ô�����

        �ܽ᣺���� ��ʵ�� 4���裺 ��3˽�У�1�ӿڣ�
             1. ˽�л� ���캯��
             2. ˽�л� ��������
             3. ˽�л� ��̬��Աָ�����ָ��new������Ψһ�Ķ���(�ⲿ����)��
             4. ���徲̬��Ա�����ӿڣ��ṩ���Ψһ����ĵ�ַ�ľ�̬�ӿڡ�

        ����
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

                    //4.˼����ʽ�������������޷��ٴ������󣬹�������newһ������
                    //5.���������� ��Ա��������Ҫ���ж��󣬲Ż��������Ա������
                    //6.��ʵ�����������󣬹���Ȼ�ò�����������������Ҫ��������ɾ�̬�ģ���static��������,�����Ϊ��̬��Ա������
                    //static Feifei* single;//7.��̬��Ա�������������������ⶨ��

                    //11.����һ���ӿ�,��̬�ĳ�Ա����(��ͨ�ĳ�Ա������Ҫ�������)
                    static Feifei * instance()
                    {
                        return single;//��single���أ�����ֻ���������޸ġ�
                    }
                private:
                    static Feifei *single;

                    Feifei()//�޲ι���˽�л���
                    {

                    }
                    Feifei(const Feifei&p)
                    {

                    }
                };
                //8.���徲̬��Ա��������ɵ�����ʵ�֡�����һ������:���ÿ���������Ȼ����ʵ�ֺ���Ķ�����,�����Ҫ����������Ҳ����˽�л���
                Feifei * Feifei::single= new Feifei;//���ⶨ��

                void test()
                {
                    //1.���ȵò���ֻ����һ���������
                    //2.���ȵ�һ����һ�����󶼴������˵��࣬�������캯��˽�л��������ڶ���Ĵ�����Ҫ�����޲ι��죬����������ò����޲ι��죬���޷��������󡣣�
                //    Feifei p;   //3.�����޲ι�����˽�еģ���˶����ܴ�������
                //    Feifei p1;//

                    // 2.1ͨ�����������ʵ�ֶ�single�Ĳ�����
                //    Feifei::single->age = 30;         //12.���ڽӿں����ĳ��֣��������ô˷���ʹ��single
                //    Feifei::single->yanzhi = 100;

                     //9.���ÿ������� ʵ������ ��һ������,���,��Ҫ����������Ҳ����˽�л�
                    //Feifei p1(*Feifei::single);

                    //10.����һ�����⣬����С�Ľ�single �ĵ�ַ��ֵΪ NULL������Ҳ�����ҵ����ַ�����Ҳ��Ҫ������˽�л�
                }

                void test1()
                {
                    //13.������ʹ��
                    Feifei *p = Feifei::instance();//���Ψһָ��
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
    4.4 c++�������ģ�ͳ�̽
        4.4.1 ��Ա���� �� ���� �Ĵ���
            ���������� ��Щ�����ͺ����Ǵ����ڶ�������ģ�    ��Щ�����ֲ����������棿ֻ�ǽ�����������������档�����羲̬��Ա�������Ǵ��ھ�̬ȫ�����ģ���
            ��c�����У����ֿ��������ģ�Ҳ����˵�����Ա���û��֧��"����"��"����"֮��Ĺ��������ǰ����ֳ��򷽷���Ϊ�������Ե�"����һ�顰�ֲ��ڸ����Թ���Ϊ�����ĺ����С����㷨���������Ǵ�����ǹ�ͬ���ⲿ���ݡ�

            c++ʵ���ˡ���װ������ô����(��Ա����)�Ͳ���(��Ա����)��ʲô������?
            "����"�͡��������ݵĲ���(����)"�Ƿֿ��洢�ġ�

            c++�еķǾ�̬���ݳ�Աֱ���ں���������У�����c structһ����
            ��Ա����(member function)��Ȼ�ں��� class ����֮�ڣ�ȴ�������ڶ����С�
            ÿһ����������Ա����(non-inline member function)ֻ�ᵮ��һ�ݺ���ʵ��.

        �ܽ᣺�����������ڴ�ʱ������ͨ��Ա�����Ż�ռ�ö���Ŀռ䡣
            * ������Ա ��ͨ��Ա���� ռ�� ����ռ��С
            * ������Ա ��̬��Ա���� ��ռ�� ����ռ��С
            * ������Ա ��ͨ��Ա���� ��ռ�� ����ռ��С
            * ������Ա ��̬��Ա���� ��ռ�� ����ռ��С

        ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;


                //�ɴ�֪��ֻ����ͨ��Ա���� ��������� ���ʵ�������� ��һ���ڴ档�������������ڴ�ʱ������ͨ��Ա�����Ż�ռ�ö���Ŀռ䣩
                class Person
                {
                public:
                    int a;//��ͨ��Ա����
                    static int b;//��̬��Ա��������������ʵ�����Ķ����У�ֻ�����������С�����ھ�̬ȫ������

                    //����������ڴ�������
                    void show()//��ͨ��Ա������Ҳ����������ʵ�����Ķ�����
                    {
                        cout << a << " " << b << endl;
                    }
                    static void show1()//��̬��Ա������Ҳ����������ʵ�����Ķ�����
                    {
                        cout << b << endl;
                    }

                };

                int Person::b = 1;
                void test()
                {

                    //1. ����Ĵ�С��1 ����0���е�ַ�����пռ��С��
                    //2. �ټ��� ��ͨ��Ա���� a �� Ϊ 4�ֽڡ�
                    //3. �ټ��� ��̬��Ա���� b �� Ϊ 4�ֽڣ��ɼ���̬��Ա������������
                    //4. �ټ��� ��ͨ��Ա���� ��С��Ϊ4���ɼ���newһ������󣬳�Ա����������ռ������������Ŀռ��С
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
        4.4.2 this ָ��
            4.4.2.1 thisָ��Ĺ���ԭ��
                ͨ����������֪����c++�� ���� �� ���� Ҳ�Ƿֿ��洢������ÿһ����������Ա����(non-inline member function)ֻ�ᵮ��һ�ݺ���ʵ����Ҳ����˵���ͬ���͵Ķ���Ṳ��һ����롣
                ��ô������:��һ���������������ĸ���������Լ�����?

                c++ͨ���ṩ����Ķ���ָ�룬this ָ�룬����������⡣this ָ��ָ�򱻵��õĳ�Ա���������Ķ���
                c++�涨��this ָ���������ڶ����Ա�����ڵ�һ��ָ�롣��һ�����󱻴���������ÿһ����Ա����������һ��ϵͳ�Զ����ɵ�����ָ��this�����Ա����������ĵ�ַ��Ҳ����˵��Ȼ����û��д��this ָ�룬�������ڱ����ʱ��Ҳ�ǻ���ϵġ�
                ��� this Ҳ��Ϊ��ָ�򱾶����ָ��"��this ָ�벢���Ƕ����һ���֣�����Ӱ�� sizeof(����)�Ľ����

                this ָ����C++ʵ����װ��һ�ֻ��ƣ���������͸ö�����õĳ�Ա����������һ�����ⲿ������ÿһ������ӵ���Լ��ĺ�����Ա��һ������£�����дthis,������ϵͳ����Ĭ�����á�this ָ����Զָ��ǰ����
                ��Ա����ͨ�� this ָ�뼴��֪�����������Ǹ���������ݡ�This ָ����һ������ָ��,��������ÿ����ķǾ�̬��Ա�����С�Thisָ�����趨�壬ֱ��ʹ�ü��ɡ�

            ע��:��̬��Ա���� �ڲ� û��thisָ�룬��̬��Ա���� ���ܲ��� �Ǿ�̬��Ա������
                c++����������ͨ��Ա��������һ���ڲ�����

            �ܽ᣺
                * ��ĳ�Ա����Ĭ�ϱ�����������thisָ�룬���thisָ��ָ����øó�Ա�����Ķ��󡣣�Person * const this��

            ����
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

                        //���ں��������ڴ�������ֻ��һ�ݣ��������ǵ�������� ��ӡ a��ʱ���ô֪����p����p1��a?
                        //��Ϊ����ĳ�Ա�������� ������ Ĭ�ϼ���һ������: Person * const this   ; thisָ�� ָ�� ���øú����Ķ��󣬹ʣ�˭���øú����������ͻ��˭�ĵ�ַ��
                        //������ó�Ա�������Ὣ����ĵ�ַ����thisָ�롣
                        void show() //Person * const this��������Ĭ�ϼ���������͡�(ָ�볣����this��ָ���ܸı�)
                        {
                            cout << a << " " << b << endl;          //��������ͱ���� cout << this->a << " "  << this->b << endl;
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

                        //show�������ڴ���������һ�ݣ�p1������ú�����ʱ�򣬺�����ô֪���Ǵ�ӡp1����p2��a?
                        p1.show();
                        p2.show();
                    }

            4.4.2.2 this ָ���ʹ��
                �� �β� �� ��Ա���� ͬ�� ʱ������thisָ��������
                ����ķǾ�̬��Ա�����з��ض���������ʹ�� return *this.
            ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Person
                    {
                    public:
                        Person(int age,string name) //��Ϊÿ����Ա����������һ��thisָ�룬ָ����ó�Ա�����Ķ���ĵ�ַ����thisָ��ָ�� p�ĵ�ַ��
                        {
                    //        age = age;     //�������� age �� name����ָ���βΡ�������и�ֵ
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

                        Person person_add(Person &p1)// д�������Ϊ��Ա������ʵ�����
                        {
                            Person p(this->age+p1.age,this->name+p1.name);
                            return p;
                        }

                    };

                    //���ⶨ����Ϊ ȫ�ֺ��� ʵ�����
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

                        //ʵ�֣�p3 = p1+p2 30 helloworld

                        //����һ��ȫ�ֺ���
                        Person p3 = person_add(p1,p2);
                        p3.show();

                        //����������Ա����
                        Person p4 = p1.person_add(p2);
                        p4.show();

                    }
                    int main()
                    {
                        test1();
                        return 0;
                    }

            4.4.2.3 const ���εĳ�Ա����
                ���ڳ�Ա���� ��thisָ������Ϊ�� Person * const this�����this�����ַ���ܸı䣬����ָ������ݿ��Ըı䣬��this->age = 200;����ܻᵼ���������⡣

            �ܽ᣺
                * �ڳ�Ա����������� const,����һ����������
                * ���const ���ε���thisָ�룬ʹ���Ϊ ����ָ�볣��: const Person * const this
                * ������ ����ͨ�� thisָ���޸���ָ��ռ�����ݡ�

            ���ӣ�
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

                        //Person * const this -----> p1     //���Ӧ��Ϊ ����ָ�볣����const Person * const this������ָ��ָ��ĵĿռ����ݱ㲻���޸�
                        //����Person * const this �������ˣ����const ֱ�ӷź��棺Person person_add(Person &p1)const
                        //��Ա����������� const���ֺ�������Ϊ ������������ͨ��thisָ���޸���ָ��Ķ������ݡ�
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
    4.5 ��Ԫ�����뵽4.3.1��
        �� ����Ҫ�ص�֮һ���������أ� �� ���˽�г�Ա �޷��� ����ⲿ(������֮��)���ʡ�
        ���ǣ���ʱ����Ҫ ������ⲿ ���� ���˽�г�Ա����ô��?
        ���������ʹ����Ԫ��������Ԫ�ĺ�����һ����Ȩ������c++���������Ȩ��������˽�г�Ա����һ�����ʵ������Ҳ���Ժܺõ����:
        ������ļң��п�����������ң���ô��Ŀ�����Public�ģ��������Ŀ��˶����Խ�ȥ���������������˽�еġ�Ҳ����˵ֻ�����ܽ�ȥ�������ء���Ҳ����������Ĺ��ۺû��ѽ�ȥ��
        ��ũ ���԰� һ��ȫ�ֺ�����ĳ�����еĳ�Ա���������������� ����Ϊ��Ԫ��

        * �������ȫ�ֺ��� �� һ����ĳ�Ա���� ���� ��һ�����˽�г�Ա��ֻ��Ҫ���� ��Ԫ ���ɡ�
        4.5.1 ��Ԫ�﷨
            friend �ؼ���ֻ������������
            �����ࡢ���Ա������ȫ�ֺ�����������Ϊ��Ԫ
            ��Ԫ����������ĳ�Ա������thisָ��
            ��Ԫ�����ɷ��ʶ��������Ա���ԣ�����˽������

            4.5.1.1 ȫ�ֺ�����Ϊ�����Ԫ��

                ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <string>
                    #include <stdlib.h>
                    using namespace std;

                    class Building
                    {
                        friend void print_building(Building &p);// ��friend�����ú����Ǹ������Ԫ����ʱ�����Ϳ��Է��ʸ����˽�г�Ա�ˡ�
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
                        cout << p.hall <<" " <<p.bedroom <<endl;//b���ʲ���˽�г�Ա����˿���ʹ����Ԫ�������ȫ�ֺ�������Ϊ��������Ԫ���Ϳ��Է���˽�г�Ա��
                    }

                    void test()
                    {
                        Building b1("������","�뷿");
                        print_building(b1);
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

            4.5.1.2 һ���� ��Ϊ ��һ�������Ԫ �Լ� ��ĳ�Ա���� ��Ϊ ��һ�������Ԫ
            ����

                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                class Building;//����

                //��������
                class Goodgay
                {
                public:
                    Goodgay(string hall,string bedroom);//���캯������������������ʵ�֡�

                    void visit();//���Է���b�����һ����Ա����

                    Building *b;
                };

                //
                class Building
                {
                    friend class Goodgay;               //һ����          ��Ϊ ��һ�������Ԫ
                    friend void Goodgay::visit();       //һ����ĳ�Ա���� ��Ϊ ��һ�������Ԫ
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


                //ע�⣺����ʹ�������������Լ�Ϊ�β���д��Building�ඨ���ǰ�棬����Ϊ����������������ʵ�ֵ�ʱ��newһ��Building������new�������ġ���Ϊ���沢û��Building�Ķ��壬ֻ��һ��������
                Goodgay::Goodgay(string hall,string bedroom)
                {
                    //newһ��Building���󣬷ŵ�Goodgay�����Buildingָ���Ա����
                    Goodgay::b = new Building(hall,bedroom);
                }

                void Goodgay::visit()
                {
                    cout << b->hall << " " << b->bedroom << endl;//b���ܷ������ڵ�˽�г�Ա��
                }


                void test()
                {
                    Goodgay gd("������","�뷿");
                    gd.visit();
                }

                int main()
                {
                    test();
                    return 0;
                }


        4.5.2 ������ϰ
            1.��д���ӻ��࣬�п����͹ػ�״̬����������Ƶ�����ṩ���������ķ�����Ƶ�������ķ��������ڵ��ӻ�ֻ����һ����Ƶ��������ָ��Ƶ��������ң���࣬ң�������ӵ�е��ӻ����еĹ��ܣ������Ӹ��������̨�Ĺ��ܡ�
            ��ʾ��ң����������ӻ������Ԫ��
        ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <string>
                #include <stdlib.h>
                using namespace std;

                //����ң������
                class Remote;

                class Television
                {
                    friend class Remoter;
                public:
                    enum    //���ӻ�״̬
                    {
                        on,
                        off
                    };
                    enum    //������0~100
                    {
                        MIN_V = 0,
                        MAX_V = 100
                    };
                    enum    //Ƶ����1~255
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
                            cout << "status ON, volume " << mVolume << ", channel " << mChannel <<endl;  //�����ʽҲ���������޸�
                        }
                    }

                private:
                    int mState;     //����״̬
                    int mVolume;     //����
                    int mChannel;    //Ƶ
                };

                //����ң������
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

                void test()  //���Ժ������Ը����Լ������޸�
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

            2.ǿ��ѵ�����������װ��
            MyArray.h��

                #ifndef MYARRAY_H
                #define MYARRAY_H

                class MyArray {
                public:
                    //�޲ι��캯�����û�û��ָ�����������ʼ��Ϊ100
                    MyArray();
                    //�вι��캯�����û�ָ��������ʼ��
                    explicit MyArray(int capacity);
                    //�û������ӿ�
                    //����λ�����Ԫ��
                    void SetData(int pos, int val);
                    //���ָ��λ������
                    int GetData(int pos);
                    //β�巨
                    void PushBack(int val);
                    //��ó���
                    int GetLength();
                    //�����������ͷ�����ռ�
                    ~MyArray();
                private:
                    int mCapacity; //����һ�������ɶ��ٸ�Ԫ��
                    int mSize; //��ǰ�ж��ٸ�Ԫ��
                    int* pAdress; //ָ��洢���ݵĿռ�
                };

                #endif

            Myarray.cpp:

                #include"myarray.h"

                //�޲ι��죬Ĭ��ָ������������С
                MyArray::MyArray() {
                    this->mCapacity = 100;
                    this->mSize = 0;
                    //�ڶѿ��ٿռ�
                    this->pAdress = new int[this->mCapacity];
                }
                //�вι��캯�����û�ָ��������ʼ��
                MyArray::MyArray(int capacity) {
                    this->mCapacity = capacity;
                    this->mSize = 0;
                    //�ڶѿ��ٿռ�
                    this->pAdress = new int[capacity];
                }
                //����λ�����Ԫ��
                void MyArray::SetData(int pos, int val)
                {
                    if (pos < 0 || pos > mCapacity - 1) {
                        return;
                    }
                    pAdress[pos] = val;
                }
                //���ָ��λ������
                int MyArray::GetData(int pos) {
                    return pAdress[pos];
                }
                //β�巨
                void MyArray::PushBack(int val) {
                    if (mSize >= mCapacity) {
                        return;
                    }
                    this->pAdress[mSize] = val;
                    this->mSize++;
                }
                //��ó���
                int MyArray::GetLength() {
                    return this->mSize;
                }
                //�����������ͷ�����ռ�
                MyArray::~MyArray() {
                    if (this->pAdress != nullptr) {
                        delete[] this->pAdress;
                    }
                }


         TestMyArray.cpp��

                #include "MyArray. h"

                void test(){

                    //��������
                    MyArray myarray(50);
                    //�����в���Ԫ��
                    for (int i =0; i< 50; i++){
                        //β�巨
                        myarray.PushBack(i);
                        //myarray.setData(i,i);
                    }
                    //��ӡ������Ԫ��

                    for(int i=0;i< myarray.GetLength(); i++){
                        cout << myarray.GetData(i)<<" ";
                    }
                    cout << endl;
                }

*/

/*
    4.6 ���������
        4.6.1 ��������ػ�������
            ��������أ����Ƕ����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ���������͡�

            ���������(operator overloading)ֻ��һ��"�﷨�ϵķ���",Ҳ������ֻ����һ�ֺ������õķ�ʽ��

            �� c++��,���Զ���һ���������������������ֶ������һ����ͨ�ĺ�������,ֻ�Ǻ����������ɹؼ���operator����������������ɡ������˶����������κ���������һ��Ҳ��һ���������������������ʵ���ģʽʱ���ͻ�������������

            �﷨:
                �������ص�����������庯����ֻ�Ǹú����������� operator @, �����@�����˱����ص�������������Ĳ����в�������ȡ�����������ء�
                    �������һԪ(һ������)�Ļ��Ƕ�Ԫ(��������);
                    �����������Ϊ ȫ�ֺ��� (����һԪ��һ�����������ڶ�Ԫ����������) ���� ��Ա���� (����һԪû�в��������ڶ�Ԫ��һ����������������ʱ����Ķ��� ���� �������)

            [��������]
                ��Щ�˺�����������������ء���ȷʵ��һ����Ȥ�Ĺ��ߡ�����Ӧ��ע�⣬��������һ���﷨�ϵķ��������������һ�ֺ������õķ�ʽ��������Ƕ�������ֻ������ʹ�漰��Ĵ������д�������Ǹ��׶�ʱ(���ס��������Ļ��������д��������)���������������������������������͸������������ã����׶��ķ�ʽ��

                ������������أ�����һ�������ķ�Ӧ�ǿֻ�:ͻȻ֮�䣬C������ĺ����ò�ͬѰ���ˣ�һ�ж����ˣ�����C����Ĺ��ܶ�Ҫ�ı�!������ˣ��������õ��������͵ı��ʽ�ĵ�������ǲ����ܸı�ġ�(���������� int�������ݵ�+�ţ�

        �ܽ�:��������أ����Ǹ����������һ���µ����塣

            �����ֻ���������õ��������ͣ�         �����Զ�����������ͣ���������
            int a = 3;                          Person a;
            int b = 2;                          Person b;
            int c = a+b;                        Person c = a+b;

            ���Կ��������������

        ��1��
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

                    //����������ĳ�Ա����
                    Person Person_ADD(Person &p2)
                    {
                        Person p(this->age+p2.age);
                        return p;
                    }

                    //����������Ա������operator+
                    Person operator+ (Person &p2)   //���������ĺ����� ��Ϊ operator+ ���ɡ�
                    {
                        Person p(this->age+p2.age);
                        return p;
                    }

                    int age;
                };

                //����һ��ȫ�ֺ���ʵ����Ķ�����ӡ�
                Person Person_add(Person &p1,Person&p2)
                {
                    Person p(p1.age+p2.age);
                    return p;
                }

                //�����ġ�ȫ�ֺ�����operator+
                //Person operator+ (Person &p1,Person&p2)
                //{
                //    Person p(p1.age+p2.age);
                //    return p;
                //}

                void test1()
                {
                    Person p1(10);
                    Person p2(20);
                    //Ҫʹ��p3.age = p1.age + p2.age;������ʽ�Ļ�������������ȥ�� ������ �� �������������ع���
                    //���������ĵĵ��÷�ʽ��
                    //ע�ⶨ����ȫ�ֵĺ��� �Ͳ��� ���г�Ա�������ᱨ��
                    Person p5 = p1 + p2;    //�������ô˷����������ڷ������Ļ����� �������� ��Ϊ operator+ ,���иú���������ã����������Ҳ����ú�������ʹ�ô˷�����
                    Person p6 = p1.operator+(p2);

                    //����һ�ĵ���
                    Person p3 = Person_add(p1,p2);

                    //�������ĵ���
                    Person p4 = p1.Person_ADD(p2);
                }

            ��2��
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

                //ȫ��ʵ��
                //Person operator+ (Person &p1,Person &p2)
                //{
                //    Person p(p1.age+p2.age);
                //    return p;
                //}

                void test1()
                {
                    Person p1(10);
                    Person p2(20);

                    //��ȥ�� operator+ �ĺ���,��������ʽ��operator+(p1,p2) �� p1.operator(p2)
                    //ȫ�� �� ��Ա���� ����ͬʱ���ڣ���������屨��
                    Person p3 = p1+p2;

                    cout << p3.age << endl;
                }

                int main()
                {
                    test1();
                    return 0;
                }

        4.6.2 ���������������Ԫ����
            ��Ԫ������һ��ȫ�ֺ���������������д��ȫ�ֺ������ƣ�ֻ����Ԫ�������Է���ĳ��˽�����ݡ�
            ������ �������Ʋ������� << ��,ʹ�� cout �����������

        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            class person
            {
                //������Ԫ��ʹ���ܹ�����˽�г�Աage.
                friend ostream& operator<<(ostream &cout, person &p);
            public:
                person(int age)
                {
                    this->age = age;
                }
            private:
                int age;
            };

            ostream& operator<<(ostream &cout, person &p) //cout�������ǣ�ostream
            {
                //ע�⣺���age��˽�еģ���ú����������age�������Ҫ��һ������ ��Ԫ��
                cout << p.age;
                //���ڷ���ֵ��ѡ��void ���� ostream& ?��,ѡ����ߣ���ΪҪ���endl���� <<endl;�ʷ��ز���Ϊ�գ���Ϊ�ղ������endl,������ʹ�� void << endl;
                //��ˣ�����ֵѡ�� ostream ���͵� cout��
                return cout;
            }

            void test01()
            {
                person p1(10);
                cout << p1 <<endl;  //ֱ�����
                // operator<<(cout,p1) //cout.operator<<(p1)��������cout��� �������ز�̫��ʵ�����ѡ��ǰ��ȫ�ֺ������ء�
            }
            int main()
            {
                test01();
                return 0;
            }

        4.6.3 �����ص������
            ����C�����е���������������أ��������������ʹ��ʱ�൱�����Ƶġ�
            �ر��ǲ���ʹ��C�е�ǰû������������(������**����)���ܸı���������ȼ������ܸı�������Ĳ���������
            ���������������壬����������Щ��Ϊ����������� ֻ����� ������ ����Ԣ���⡣

            �����صĲ�������
                +       -       *       /       %       ^       &       |       ~
                !       =       <       >       +=      -=      *=      /=      %
                ^=      &=      |=      <<      >>      >>=     <<=     ==      !=
                <=      >=      &&      ||      ++      --      ->*     ��       ->
                []      ()      new     delete  new[]   delete[]

            �������ص������
                .       ::      .*      ?:      sizeof

        4.6.4 �����Լ��Լ������
            ++a  a++    --a  a--

        ���ڴ��룺��������
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
                        //�Ӽ�
                        this->num = this->num + 1;
                        return tmp;

                    }
                    int num;
                };
                //ǰ��++������ʹ�����ô��Σ�����++����ʹ�����ô���
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

        ����̽����c++������������صĵڶ��������⣨�����++������������ã�������https://blog.csdn.net/weixin_41054491/article/details/135579799
            �ô����漰��++�����������<<��������ص�����ʹ�á�

        ֵ����������⣺�����������<<�����У�Ϊʲô�ڶ�����������ʹ��&���ã�ʹ������ʱ�ᱨ��

            ��Ҫע�����ֵ���:
            ��1����ǰ��++�����������<<������������õĹ����У�<<��������صڶ�����ʹ�����ò��ᱨ��
            ��2���ں���++�����������<<������������õĹ����У�<<��������صڶ�����ʹ�����ûᱨ��

                ��1��ǰ��++��������أ����غ������ص�ֵ���������ͣ���MyInteger���еı�����������������Ѵ��ڵĶ���

                ��2������++��������أ����غ������ص�ֵ��ֵ���ͣ���MyInteger���е�һ����ʱ������������ں���++��������غ���������ϼ���ʧ��

                ��3����ǰ��++�������<<������������ù��̣�����ڶ�����ʹ��&��û�����⣬������Ϊ&����Ķ��󲻻���ʧ��

                ��4���ں���++�������<<������������ù��̣�����ڶ�����ʹ��&�������⣬������Ϊ&����Ķ������ʧ�������֮ǰ�Ѿ���ʧ�ˣ���Ҳ��������κζ��������Իᱨ��
            ��֮��
                ����ǰ��++ �� operator++���� ���ص��Ƿ��ض������ã�
                ��  ����++ ��operator++��int�����ص��� ��ʱ����temp,
                ���<<�����أ����ǰ��++��ʱ�򣬵ڶ����������������ã������ ����++��ʱ�򣬲��������á�

        4.6.5 ָ���������*��->������
            ����ָ�룺
            �ܽ᣺���Ǿ���newһ�����������ͷţ���������ʹ������ָ����ά��
            ��ʵ����һ���ֲ����󣬸þֲ�����ά����new�����Ķ���ĵ�ַ���ھֲ�������������������æ�ͷ�new�����Ķ���

            ������ָ������������ -> �� * ʹ����ָ�����ָͨ��һ��ʹ�á�

        ����
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
                        cout << "Smartpoint �ͷ� p" << endl;
                    }

                    Person *p ;
                };

                void test()
                {
                    //��һ�����⣺�ܷ���һ���ֲ��������ͷ�֮ǰ������԰��������ͷ�p ������������ָ��
                    //��֪�����ڳ��������ͷŵ�ʱ������������������˿������������������ͷŸÿռ䡣

                    Person *p = new Person(10);
                    Smartpoint sp(p);

                    //�������д���Ҳ����дΪ��
                    Smartpoint ssp(new Person(100));

                    cout << p->age <<endl;
                    cout << sp->age <<endl; //�ڶ������⣬�ܷ�ʹsp ���� p:sp -> p  Person* sp.operator->(){return p;}
                    cout << (*sp).age <<endl; //���������⣬�ܷ�ʹ*spָ��age  �� sp.operator*()
                    //���������ͷ� pָ����������
                }

                int main()
                {
                    test();
                    return 0;
                }

        4.6.6 ��ֵ��=�����������
            ��ֵ����ѧ���׻�������Ϊ"="�ڱ�����������������������Խ��и�ֵ������Ҳ�����𿽱����캯���ĵ��á�

        �ܽ᣺������Ĭ�ϸ�ÿһ���������4��������
                                * Ĭ���޲ι���
                                * Ĭ��ֵ��������
                                * Ĭ����������
                                * Ĭ�ϵ�operator=()����
            ����
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

                            //����д������ name1ָ����ַ������ܱ����ͷ��ˡ�
                            name = new char[strlen(name)+1];
                            strcpy(name,name1);
                        }

                    //    Person & operator=(Person &p1) //thisָ��ָ��p2
                    //    {
                    //        //���˼򵥵�ֵ������
                    //        this->age = p1.age;
                    //        this->name = p1.name;

                    //        return *this; //����ֵ ���ص���p2,ʹ������������ã��磺P3 = p2 = p1;
                    //    }
                        Person & operator=(Person &p1) //��дoperator=����
                        {
                            //�����
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

                        //��ôд��û�е��ù��캯�����ɶ��� ��ֵ �ɶ��󣩡������Person p2 = p1���ǵ��ù��캯�����ɶ��� ��ʼ�� �¶��󣩡�
                        p2 = p1;//����֮����û�б�������Ϊ����һ�� operator= ����,�൱�� p2.operator(p1).
                        cout << p2.age << " " << p2.name <<endl;
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

        4.6.7 ���� �� �����ڣ�== �� ��=�����������
            ��ֱ�����أ�û��ǰ����������ơ���
                bool operator==(Person p2)  //p1����
                {
                    return this->age == p2.age && this->name == p2.name;
                }

                bool operator!=(Person p2)  //p1����
                {
                    return this->age != p2.age || this->name != p2.name;
                }
        ����
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

                    bool operator==(Person p2)  //p1����
                    {
                        return this->age == p2.age && this->name == p2.name;
                    }

                    bool operator!=(Person p2)  //p1����
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

        4.6.8 �������÷���() ����
            һ�����������ˣ������࣬��ô����ඨ������Ķ����������һ��ʹ�ã��������ǵ�����operator()������
            ����
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
                    //�� �� ��ͨ��Ա����������ô���ã�ֻ�о�̬�ĳ�Ա�����Ż��к�������ͨ��Ա�������ڶ��󴴽���Ż��С�
                    Myadd p;
                    cout << p.add(3,4) << endl;

                    //p() ��������һ�����ö��󣬳�Ϊ��������
                    cout << p(3,4) << endl; //�Ѷ������������á� p.operator() (3,4)

                    cout << Myadd()(3,4) <<endl;//Myadd()(3,4)��Myadd(),����+���� ��ʾ ���������ٵ���operator()����

                }

                int main()
                {
                    test();
                    return 0;
                }

        4.6.9   �������� && �� ||
                �������߼����������أ������������ء�

                �������� operator&& �� operator|| ��ԭ���ǣ��޷��������������ʵ�����ò��������������塣˵�ø�����һЩ�����ð汾 �汾����֮������:���ð汾�� &&�� || ���ȼ�����ߵı��ʽ���������ȫ�ܹ��������������������ұߵı��ʽ��,
                �����ܹ���֤����Ҫ�����Ƕ��Ѿ�ϰ�����ַ���������ˡ�

                ����˵������������ʵ����һ����ʽ�ĺ������ö��������ں������������ں���ִ��֮ǰ�����в���������ֵ��

            ����
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

                        //ԭ�������Ӧ�ô����������㣬���Ϊ�٣����˳����㣬���Ϊ��
                        //���ȴ�ǣ������㣨complex1+complex2�������£�complex1��flag��Ϊcomplex1+c
                        //plex2��ֵ�� complex1.a = 1
                        // 1 && 1
                        //complex1.operator&&(complex1.operator+=(complex2))

                        if (complex1 && (complex1 += complex2)){
                             //complex1.operator+=(complex2)
                             cout << "��!" << endl;
                        }
                        else{
                            cout << "��!" << endl;
                        }
                        return EXIT_SUCCESS;
                    }

        4.6.10  ���������ܽ�
            =��[],()��-> ������ֻ��ͨ����Ա������������
            << �� >> ֻ��ͨ��ȫ�ֺ��������Ԫ������������
            ��Ҫ����&&��||����������Ϊ�޷�ʵ�ֶ�·����

        4.6.10 ǿ��ѵ�������ַ������װ

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

                    char& operator[] (int index);//[]����

                    //=����
                    MyString& operator= (const char *str);
                    MyString& operator= (const MyString& str);

                    //�ַ���ƴ�� +����
                    MyString operator+ (const char *str);
                    MyString operator+ (const MyString& str);

                    //�ַ����Ƚ�
                    bool operator== (const char *str);
                    bool operator== (const MyString& str);
                private:
                    char * pString;//ָ������ռ�
                    int m_Size;    //�ַ������� ���� ��\0��
                };


        //MyString.cpp

                #include "MyString.h"

                //���������
                ostream& operator<< (ostream &out,MyString &str)
                {
                    out << str.pString;
                    return out;
                }

                //���������
                istream& operator>> (istream &in,MyString &str)
                {
                    //�Ƚ�ԭ�е������ͷ�
                    if(str.pString != NULL)
                    {
                        delete[] str.pString;
                        str.pString = NULL;
                    }

                    char buf[1024]; //������ʱ���ַ������飬�����û��������ݡ�
                    in >> buf;

                    str.pString = new char[strlen(buf) + 1];
                    strcpy(str.pString,buf);
                    str.m_Size = strlen(buf);

                    return in;
                }

                //���캯��
                MyString::MyString(const char * str)
                {
                    this->pString = new char[strlen(str) + 1];
                    strcpy(this->pString,str);
                    this->m_Size = strlen(str);
                }

                //��������
                MyString::MyString(const MyString &str)
                {
                    this->pString = new char[strlen(str.pString) + 1];
                    strcpy(this->pString,str.pString);
                    this->m_Size = str.m_Size;
                }

                //��������
                MyString::~MyString()
                {
                    if(this->pString != NULL)
                    {
                        delete []this->pString;
                        this->pString = NULL;
                    }
                }

                char& MyString::operator[] (int index)  //����str[index]�����ã����ڸ������ֵ
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
                    char *temp = new char[newsize]; //������newһ��newsize��С�Ŀռ䣬���ص���charָ��ı���
                    memset(temp,0,newsize);         //�����洴���Ŀռ��Ӧ������ȫ����ֵΪ0��
                    strcat(temp,this->pString);
                    strcat(temp,str);

                    MyString newstring(temp);       //��������charָ��ı��� ����һ�� ����
                    delete []temp;                  //����ʱ�ռ�ɾȥ

                    return newstring;               //�����µĶ���
                }

                MyString MyString::operator+ (const MyString &str)
                {
                    int newsize = this->m_Size + str.m_Size + 1;
                    char *temp = new char[newsize];
                    memset(temp,0,newsize);
                    strcat(temp,this->pString);
                    strcat(temp,str);

                    MyString newstring(temp);       //��������charָ��ı��� ����һ�� ����
                    delete []temp;                  //����ʱ�ռ�ɾȥ
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

                    //cout << "������MyString �����ַ���" << endl;
                    //cin >> str;

                    //cout << "�ַ���Ϊ��" << str <<endl;

                    //����[]
                    cout << "MyString �ĵ�һ���ַ�Ϊ��" << str[0] << endl;

                    //����=
                    MyString str2 = "^_^";
                    MyString str3 = "";
                    str3 = "aaa";
                    str3 = str2;
                    cout << "str2 = " << str2 << endl;
                    cout << "str3 = " << str3 << endl;

                    //����+
                    MyString str4 = "�Ұ�";
                    MyString str5 = "����";
                    MyString str6 = str4 + str5;
                    MyString str7 = str6 + "�찲��";

                    cout << str7 <<endl;

                    //����==
                    if(str6 == str7)
                    {
                        cout << "s6 �� s7���" << endl;
                    }
                    else
                    {
                        cout << "s6 �� s7����" << endl;
                    }
                }

        4.6.11 ��¼������������ȼ�
                һ��15�����ȼ���ͬc����һ�¡�
*/
/*
    4.7.1 �̳и���
        4.7.1.1 Ϊ����Ҫ�̳�
            A �̳� B������A��B�Ķ�������������

            //person(����)��                               //employee��ְ������
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

            ��ֱ�Ӷ���employee�࣬�����ظ���Ƚ����ء�

        �ܽ᣺
            һ����̳���һ���࣬�������оͿ����ٶ���һЩ��Ա��

        4.7.1.2 �̳л�������
            c++����Ҫ�������Ǵ������ã�ͨ���̳л��ƿ������ü��е����������������µ��������ͣ��µ��಻��ӵ�о���ĳ�Ա����ӵ���¶���ĳ�Ա��

            һ�� B�� �̳��� A�࣬��ƴ� ��A ���� ��B�������Ļ�����A ��Ϊ ����(����)����B ��Ϊ ������(����)
            �������еĳ�Ա���������󲿷�:
                һ�����Ǵӻ���̳й����ģ�һ�������Լ����ӵĳ�Ա��
                �ӻ���̳й����ı����乲�ԣ��������ĳ�Ա����������ԡ�

        4.7.1.3 �����ඨ��
            �����ඨ���ʽ��
                class �����������̳з�ʽ ������
                {
                    //���������������ݳ�Ա�ͳ�Ա����
                }
            ���ּ̳з�ʽ��
                public�����м̳�
                private��˽�м̳�
                protected�������̳�
            �Ӽ̳�Դ�Ϸ��ࣺ
                ���̳У�ָÿ��������ֱֻ�Ӽ̳���һ�����������
                ��̳У�ָ�������������һ��������ļ̳й�ϵ����̳е�������ֱ�Ӽ̳��˲�ֹһ�������������
            ����
                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    //����
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

                        //�̳У��൱�ڿ�������
                    //    int age;
                    //    void print()
                    //    {
                    //        cout << age <<endl;
                    //    }
                    };

                    void test()
                    {
                        Dog d;
                        //d��������Ա:
                    //    d.age;
                    //    d.tail_len;
                    //    d.print();
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }
        4.7.2   ��������ʿ���
            ������̳л��࣬������ӵ�л�����ȫ������ �� ��Ա���������˹��������֮��ĳ�Ա�������������������У��̳еĳ�Ա����һ����ֱ�ӷ��ʣ���ͬ�ļ̳з�ʽ�ᵼ�²�ͬ�ķ���Ȩ�ޡ�

            ������ķ���Ȩ�޹������£�
                ����������                   ˽��������               ����������
            ��������  ������Ȩ��         ��������  ������Ȩ��       ��������  ������Ȩ��
            ˽��      ���ܷ���           ˽��      ���ܷ���       ˽��       ���ܷ���
            ����      ����              ����      ˽��          ����       ����
            ����      ����              ����      ˽��          ����       ����

        ����
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

                //���м̳з�ʽ����������ʲôȨ�ޣ��̳е� �����У�Ҳ��ʲôȨ�ޡ�
                class A:public Base
                {
                    //���м̳� ���� ����
                public:
                    int d;
                    void show()
                    {
                        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
                //        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
                        //�ɴˣ����಻�ܷ��ʸ����˽�г�Ա��
                    }
                //    int a;
                //protected:
                //    int b;
                //private:
                //    int c;

                };


                //�����̳У��ѹ��б�ɱ����ģ���������
                class B:protected Base
                {
                public:
                    int d;
                    void show()
                    {
                        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
                //        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
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
                        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
                //        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
                    }

                    //˽�м̳У�������ĳ�ԱȨ�޶����˽�е�
                //private:
                //    int a;
                //private:
                //    int b;
                //private:
                //    int c;
                };

                void test()
                {
                    //���в��ԣ�
                    A e;
                //    A.a;
                //    A.d;

                    //�������ԣ�
                    B f;
                //    f.d;

                    //˽�в��ԣ�
                    C g;
                //    g.d


                }
                int main()
                {

                    return 0;
                }

        4.7.3  �̳��еĹ��������
            4.7.3.1 �̳��еĶ���ģ��
                ��c++���������ڲ��������Ϊ�ṹ�壬�������ɸ����Ա���������³�Ա���ɡ�

            ����
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
                        //�����ڽṹ��
                        cout << "A size" <<sizeof(A) <<endl;    //8
                        cout << "A size" <<sizeof(B) <<endl;    //12
                        cout << "A size" <<sizeof(C) <<endl;    //16
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.3.2 ������������ĵ���ԭ��
            �ܽ᣺
            �̳��еĹ����������
                * ��������ڴ���ʱ�����ȵ��ø���Ĺ��캯�������๹�캯��ִ����Ϻ󣬲Ż��������Ĺ��캯��
                * �����๹�캯���в���ʱ����Ҫ�������ʼ���б������б�����ʾ���ø��๹�캯��
                * ������������˳��͹��캯���෴
            ����
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

                            cout << "Base,����Ĺ��캯��" << endl;
                        }

                        ~Base()
                        {
                            cout << "Base �������������" << endl;
                        }
                        int age;
                        string name;
                    };

                    //������������ʱ�򣬱����ȹ������������Ҫ�ȵ��ø���Ĺ��캯����
                    class Son:public Base
                    {
                    public:
                        //����Ĺ��캯�����вι��죬���������������ڵ�������Ĺ��캯��֮ǰ����Ҫ��ȥ���ø���Ĺ��캯��������Ҫ�Ѳ�������ȥ�����η�ʽ���£�
                        Son(int id,int age,string name):Base(age,name)
                        {
                            this->id = id;
                            cout << "Son ���๹�캯��" << endl;
                        }
                        ~Son()
                        {
                            cout << "Son �������������" << endl;
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

            4.7.4 �̳���ͬ����Ա�Ĵ�����
                �������Ա �� �����Ա ͬ��ʱ��������Ȼ�Ӹ���̳�ͬ����Ա
                �������г�Ա�͸���ͬ��������������ԱĬ�Ϸ�������ĳ�Ա���������򣬾ͽ�ԭ��
                ������ͨ��������:: ����ͬ����Ա���֣�����������ʹ�û����ͬ����Ա����ʾʹ�������޶�����

            �ܽ᣺
                ������� �� ���� ��ͬ���ĳ�Ա�������Ա�����������̳�ʱ������ĳ�Ա�����ͳ�Ա�����ᱻ���ء�
            ����
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
                            cout << "�����foo����" << endl;
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
                            cout << "�����foo����" << endl;
                        }
                        int a;
                    };

                    void test()
                    {
                        Son p(10,20);
                        //�������� �����������ĳ�Ա����������ĳ�Ա�����ᱻ���ء����ʵ�������ĳ�Ա������
                        //�������� �����������ĳ�Ա����������ĳ�Ա�����ᱻ���ء����ʵ�������ĳ�Ա������
                        cout << p.a <<endl;//20 ,���ʵ���������ĳ�Ա��
                        p.foo();
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.5 ���Զ��̳еĺ���


                �������еĺ��������Զ��ӻ���̳е��������С����캯�����������������������Ĵ����������������������������ֻ֪�������ǵ��ض���εĶ�����ʲô��Ҳ����˵���캯���������������ܱ�ά�У�����Ϊÿһ���ض���������ֱ𴴽���
                ���� operator= Ҳ���ܱ��̳У���Ϊ��������ƹ��캯������Ϊ��Ҳ����˵��������֪�������=�ұߵĶ�����γ�ʼ��=��ߵĶ�������г�Ա���������������ζ�Ŷ�����������Ȼ��Ч��
                �ڼ̳еĹ����У����û�д�����Щ���������������Զ��������ǡ�

            �ܽ᣺
                �����̳�ʱ�����಻��̳и���Ĺ��캯������������ �� operator=������

            4.7.6 �̳��еľ�̬��Ա����
                ��̬��Ա���� �� �Ǿ�̬��Ա�����Ĺ�ͬ�㣺
                    1. ���Ƕ����Ա��̳е���������
                    2. �����¶���һ����̬��Ա�����������ڻ����е��������غ������ᱻ���ء�
                    3. �����Ǹı�����е�һ�����������ԣ�����ʹ�øú������Ļ���汾���ᱻ���ء�
            �ܽ᣺
                �����̳�ʱ������͸�����ͬ���ľ�̬��Ա���� �� ��̬��Ա�����������еľ�̬��Ա���� �� ��̬��Ա���� ���ᱻ���ء�

            ����
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
                        static int sNum; //���ྲ̬��Ա���Խ�������
                    #if 0
                        //�ض���һ�����������������صĺ���������
                        static int getNum(int param1,int param2)
                        {
                            return sNum + param1 + param2;
                        }
                    #else
                        //�ı���ຯ����ĳ������������ֵ���߲����������������ػ������صĺ���
                        //������������̬��Ա������������һ����
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
                        //��ˣ�������͸�����ͬ���ľ�̬��Ա����������ľ�̬��Ա�����ᱻ���أ����õ�������ľ�̬��Ա������

                    //    p1.getNum();     //�������������ò��ˣ���ˣ����ܵ��ø�����޲ξ�̬��Ա������
                    //    p1.getNum(10);   //��һ��������Ҳ���ò��ˣ���ˣ����ܵ��ø���ľ�̬��Ա������
                        p1.getNum(10,20);  //�����������Ĳſ��Ե��ã���ˣ�ֻ�ܵ�������ľ�̬��Ա������
                    //�������͸�����ͬ���ľ�̬��Ա�����������еľ�̬��Ա���� �� �ᱻ���أ�

                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            4.7.7 ��̳�
                4.7.7.1 ��̳и��
                    ���ǿ��Դ�һ����̳У�����Ҳ���� ͬʱ�� �����̳У�����Ƕ�̳С�
                    ���ǣ����ڶ�̳�ʱ�ǳ�������ģ��Ӷ����̳п��ܻ���Ϊ������������ͬ�����½϶�����塣

                ����
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

                4.7.7.2  ���μ̳� �� ��̳�
                    ���������� �̳� ͬһ������ ������ ĳ���� ͬʱ�̳����������࣬���ּ̳б���Ϊ���μ̳У�����ʯ�ͼ̳С�
                ����
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
                            //ʵ���ϣ����ǽ�ϣ��Shenshouֻ�̳�һ��age,
                            //ʵ�ַ�����ʹ����̳йؼ��֣�virtual
                        //    p.sheep::age = 100;
                        //    p.cow::age = 200;

                            //��̳�
                            p.age = 100;

                        }

                        int main()
                        {
                            test();
                            return 0;
                        }

                4.7.7.3 ��̳�ʵ��ԭ��
                    ��ϴ��룬ע�� �Լ� �ʼǽ�ͼ������
            �ܽ᣺
                ��Ҫ��Ҫ֪������̳ж���һ��vbptrָ�� ��ָ�� ������(vbtable).
                           ��̳У��̳������ࣩ�����������ָ�룬

                ���ս����1.ageֻ��һ��
                        2.�������������ptrָ��(vbptr)
                        3.��������������
                        4.������ָ��������� ���� ���������Ĺ��캯����ʱ��ȥ��ʼ���ġ�
            ����
            ���룺
                    //������Ҫ֪����ÿ�������ڴ�������δ洢�ģ��Լ����� virtual�ؼ��ֺ���̳е�����������ڴ��д洢�ġ�
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
                        //ʵ���ϣ����ǽ�ϣ��Shenshouֻ�̳�һ��age,
                        //ʵ�ַ�����ʹ����̳йؼ��֣�virtual
                    //    p.sheep::age = 100;
                    //    p.cow::age = 200;

                        //��̳�
                        p.age = 100;

                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            ������
                    //�ڿ�ʼ�˵���� vs�Ŀ�����Ա������ʾ�� ��д��������:      ���Ҳ������ɴ�vscode,���� ����->������->������������ʾ����д�����´��룺
                    //cd D:\Qtproject\5_2_cplusplus_lei
                    //dir
                    //cl /d1 reportSingleClassLayoutAnimal main.cpp    //����ָ���ʾ��report Single Class Layout Animal,���浥������ʾAnimal��main.cpp�ļ����У�ע�⣬Ҫ����֮�󣬲Ż�����Animal�Ĳ��֡�

                    //������Ĳ��֣�
                    //class Animal    size(4):
                    //        +---
                    // 0      | age
                    //        +---

                    //������Animalֻ��4���ֽ� int���͵� age

                    //����Ĳ��֣�
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

                    //���ڼ̳�����̳У�������������������̳е�age��һ��id,���⣬���滹��һ��vbptr(virtual base ptr �����ptrָ�룬ָ��ռ4���ֽڣ������ָ�� ��ָ��һ�ű�������vbtable����,�����ָ�뿪ʼ�ǲ��ᱻ��ʼ���ģ��������ǵ��������Ĺ��캯����ʱ�����ᴴ��һ�ű����Ұѱ�ĵ�ַ����vbptrָ��)��
                    //�ɣ�Sheep::$vbtable@:����֪��������������Ա��һ����0��һ����8������8��ָage��ƫ������Ҳ����˵��������̳е�ʱ��a��Ȼ�̳й����ˣ�����ȥ����age��ʱ�򲢲���ֱ�ӵõ�age������ͨ��ָ��õ�age��ƫ������Ȼ���ٷ��ʵ�age��

                    //Ҳ����˵�������� sheep p;
                    //��ȥ����(p.age)ʱ�������������������: *��int *��((char*)&p+ *((int *)(*��int *��&p) + 1)) //*(int*)(p�ĵ�ַ+ƫ����8)

                    //��������Ϊ������Ҫ�ҵ�vbptrָ�룬����������p�ĵ�ַ(32λ������)ת��(int*)��ȡ*��*��int*��&p   => �������vbptr���ֵ��ע�ⲻ��ָ�룬��ָ��������
                    //���Ƕ����ֵ�ĵ�ַת��int *,�ټ�1������ԭ����ָ��0�����ָ��8���ٽ����8ȡ������������*��,���˵õ�ƫ����8: *((int *)((int *)&p) + 1��
                    //Ϊ�˵õ�age�ĵ�ַ����Ҫ��p�ĵ�ַ�ϼ���ƫ������ ((char*)&p + *((int *)(*��int *��&p) + 1))
                    //�Եõ��ĵ�ַת��(int *),�ٽ�����,�õ�age��ֵ�� *��int *��((char*)&p + *((int *)(*��int *��&p) + 1))


                    //ţ��Ĳ��֣�
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


                    //���޵Ĳ��֣�
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

                    //����������4����Ա���̳���sheep���������id���̳���cow���������num���Լ���a �� ֻ�̳���һ�ݵ�age��
                    //������,��sheep���������age��ƫ������20����cow���������age��ƫ������12��



            vs�Ŀ�����Ա������ʾ���������ݣ�

                    //D:\Qtproject\5_2_cplusplus_lei>dir
                    // ������ D �еľ��� Data
                    // ������к��� 4D3B-BBAE

                    // D:\Qtproject\5_2_cplusplus_lei ��Ŀ¼

                    //2024/12/20  22:52    <DIR>          .
                    //2024/12/18  11:55    <DIR>          ..
                    //2024/12/07  00:18               133 5_2_cplusplus_lei.pro
                    //2024/12/20  01:28            19,159 5_2_cplusplus_lei.pro.user
                    //2024/12/07  00:32               732 c_person.c
                    //2024/12/20  22:52           197,990 main.cpp
                    //2024/12/20  22:52            76,800 main.exe
                    //2024/12/20  22:52             2,146 main.obj
                    //               6 ���ļ�        296,960 �ֽ�
                    //               2 ��Ŀ¼ 199,913,979,904 �����ֽ�

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
    4.8 ��̬����һ�ֽӿڣ�������̬��
        ��̬ �� ������������������� ���ݳ��� �� �̳�֮��ĵ���������������
        ��̬��(polymorphism) �ṩ �ӿ� �� ����ʵ�� ֮�����һ����룬�Ӷ���"what"��"how"���뿪������̬�Ը����˴���Ŀɶ��Ժ���֯�ԣ�ͬʱҲʹ�����ĳ�����п���չ�ԣ���Ŀ�������������ʱ�ڿ�����չ�����ҵ���Ŀ����Ҫ���µĹ���ʱҲ����չ��

    ��̬��Ϊ:��̬��̬ �� ��̬��̬
        c++֧��  ����ʱ��̬(��̬��̬) �� ����ʱ��̬(��̬��̬)����������� �� �������� ���� ����ʱ��̬���� ��������麯�� ʵ�� ����ʱ��̬��

        ��̬��̬ �� ��̬��̬��������� ������ַ �� ���(��̬����) ���� ���(��̬����)��

        ��������ĵ��ã��ڱ���׶ξͿ���ȷ�������ĵ��õ�ַ�����������룬���Ǿ�̬��̬(����ʱ��̬)������˵��ַ����󶨵ġ�
        ����������ĵ��õ�ַ ���ܱ��� �����ڱ����ڼ�ȷ������ ��Ҫ������ʱ���ܾ��� ,����������(��̬��̬,����ʱ��̬)��

        ���磺ͬһ�ֺ���ʵ�ֶ��ֹ��ܣ�foo(int);            ����������һ�� ��̬��̬������ʱ�ھ�����˵�ַ�İ󶨡�
                                foo(int ,int);
                                foo(int,char,short);

    �ܽ᣺��̬���� һ�ֽӿڣ�������̬
        ��Ϊ
            ��̬��̬���ڱ���ʱ����ַ��󶨣���̬���ࣩ
            ��̬��̬��������ʱ����ȷ����Ҫ���õĵ�ַ������̬���ࣩ

        ������̬���Ĵ��������������Ĵ��������֮�󣬾Ϳ���ʵ��һ���ӿڶ�����̬��
            * ���������麯��������virtual�ĺ�������
            * ������뷢���̳У��̳л��ࡣ
            * ���������д�麯��������д�������ķ���ֵ �������� �������� һ�£���������д����
            * �����ָ������ã�ָ������Ķ��� ���ڱ������У������ָ�����������Ϊ�����β���ʹ�õġ���

        ע�⣺�ڱ������У���û�м�virtual�ؼ��֣�����̳к󣬺�������ʱ �� ��ַ���(����ʱ�ھ�����˵�ַ�İ�)��������virtual���ǵ�ַ���(����ʱ�Ű󶨵�ַ)��
        ����

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
                //        cout << "������˵����" << endl;
                //    }

                    //6.��������������֣��������������֣�����virtual�ؼ��ֵ��麯����
                    //7.���ȣ����麯������Σ�Dog�ּ̳���������࣬���ң�����������д������麯����  ����д����������ֵ ������ ����ֵ һ�£��ͽ���д��

                    virtual void speak()
                    {
                        cout << "������˵����" << endl;
                    }

                };

                //2.�� ��������෢���˼̳У���������࣬�����Զ�ת����
                //3.��ʱ ������do_work()������p2��speak
                class Dog:public Animal
                {
                public:
                    void speak()
                    {
                        cout << "����˵����" << endl;
                    }

                };

                //1.����û�м̳еķ�ʽ��������do_work()������p2��speak������
                //class Dog
                //{
                //public:
                //    void speak()
                //    {
                //        cout << "����˵����" << endl;
                //    }

                //};

                //11.����һ��cat�࣬���̳�Animal.
                class Cat:public Animal
                {
                public:
                    void speak()
                    {
                        cout << "è��˵��" << endl;
                    }

                };

                //8.����ø����ָ�� ָ�� ����Ķ������ʱ�򣬴�ӡ�ľ��� "����˵��"
                void do_work(Animal &obj)
                {
                    obj.speak();  //5.������ǵ�ַ��󶨣�//9.�ڼ̳����麯��֮�󣬾��ǵ�ַ��󶨡�
                    //10.������ַ��� -> �ڻ���ĺ���ǰ�����virtual�ؼ��� -> ��ַ��󶨡�
                }

                //12.����������У�test�������ǽӿڣ�һ���ӿڣ�����ʵ�ֶ�����̬��
                void test()
                {
                    Animal p1;
                    do_work(p1);

                    Dog p2;
                    //4.��ע�⣬�����ӡ�Ļ���"������˵��",��Ϊ�����ַ ����ˡ��ڱ����������ʱ�ھ��Ѿ����ˡ�
                    do_work(p2);

                    Cat p3;
                    do_work(p3);
                }
                int main()
                {
                    test();
                    return 0;
                }

        4.8.2 ���� ��̬ʵ�ּ���������
            ����

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

        4.8.3 c++���ʵ�ֶ�̬��
            ��̬��ʲôʱ����?
            ���еĹ��������ɱ�������Ļ����ɡ������Ǹ���ͨ������һ�� virtual ���������߱�����Ҫ���ж�̬�󶨣���ô�������ͻ���ݶ�̬�󶨻�����ʵ�����ǵ�Ҫ�󣬲�����ִ����󶨡�

            ����:C++�Ķ�̬�����������ô����?
            ���ȣ����ǿ��� ��������δ����麯�������������������ǵ��������麯����ʱ�򣬱������ᴴ��һ���麯����,
            ���麯���ĺ�����ڵ�ַ�ŵ��麯�����У����� ������ ��������һ��ָ�룬
            ���ָ����� vpointer(��д vptr)����ע������������̳��е�vbptr(virtual base ptr �����ptrָ�룩
            ���ָ����ָ�������麯�����ڶ�̬���õ�ʱ�򣬸���vptr ָ�룬�ҵ��麯������ʵ�ֶ�̬�󶨡�

            ��֤�����е���ָ�롣
    ע�⣺
        �麯�����������ӵ�ָ����vpointer(��д vptr)��ע������������ �̳��е�vbptr(virtual base ptr �����ptrָ�룩

        ����
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
                            cout << "������˵����" << endl;
                        }

                    };

                    class Dog:public Animal
                    {
                    public:
                        void speak()
                        {
                            cout << "����˵����" << endl;
                        }

                    };

                    class Cat:public Animal
                    {
                    public:
                        void speak()
                        {
                            cout << "è��˵��" << endl;
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

                    //�����ٴ�ʹ�õ�vscode,��ϸ���������ǰ�� ��̳е�ʵ��ԭ��.
            �������ݣ�
                    //D:\c++����\angle\Myadd_self>cd D:\Qtproject\5_2_cplusplus_lei

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
                    //main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutDog main.cpp
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
                    //main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCat main.cpp
                    //���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
                    //��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
                    //C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
                    //main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
                    //Microsoft (R) Incremental Linker Version 14.33.31630.0
                    //Copyright (C) Microsoft Corporation.  All rights reserved.

                    ///out:main.exe
                    //main.obj

                    //D:\Qtproject\5_2_cplusplus_lei>


             ������

                //1.������һ��Dog��Ķ����ʱ�򣬻��ȹ��츸��Ķ��󣬼����ȹ���Animal�Ķ������ڱ����У�Animalû�г�Ա������ֻ���麯�������Զ���vfptr(�麯��ָ��)����ָ��ָ���麯����vftable��������������Ķ����ʱ����Ϊ����ù��캯�����ڵ��ù��캯��ʱ���� ���麯���ĺ�����ڵ�ַ �ŵ��麯����vftable��
                //2.��ˣ���ʱ����麯�� ��ָ�� �������� speak������
                    //Animal �Ĳ��֣�
                    //class Animal    size(4):
                    //        +---
                    // 0      | {vfptr}
                    //        +---

                    //Animal::$vftable@:
                    //        | &Animal_meta
                    //        |  0
                    // 0      | &Animal::speak


                //3.Ȼ��ʼ�������ࡣ���ڹ��������ʱ�� �̳��� �麯��ָ�루vfptr���Լ��麯����vftable��,��ʱ����������Ĺ��캯��ʱ������Ĺ��캯������ ��ȥ����1.����д�麯����2.�������������dog speak�����ĺ���ָ��Ž��̳е� ������vftable)���棬������vfptrָ���ֵ�滻��
                //4.��ˣ���дʵ���Ͼ����滻�� vftable����ĺ����ĵ�ַ��
                //5.��ʱ��ȥ�� p.sprak��ʱ��������ʵ�ʵ��õ���vfptrָ������vftable����ĺ��������ú����� ��������Ĺ��캯����ʱ����Ѿ������ˡ�

                    //Dog �Ĳ��֣�
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



                    //cat �Ĳ��֣�
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

        4.8.4   ������� �� ���麯����pure virtuaal function��
            �����ʱ������ϣ��  ���� ������Ϊ ��������� һ���ӿڡ�
            �����˵������Ի��������������ת����ʹ�����Ľӿڣ�����ϣ���û�ʵ�ʵĴ���һ������Ķ���
            ͬʱ����һ�����麯�� ����ӿ��з��ó�Աԭ����������һ��Ҫ�ṩһ�ο��ܶ����������������Ĵ��롣
            ������㣬�����ڻ����м�������һ�����麯��(pure virtual function),ʹ�û����Ϊ������(abstract class).

              ���麯��ʹ�ùؽ��� virtual�������������� =0�������ͼȥʵ����һ�������࣬�����������ֹ���ֲ�����

              ���̳�һ���������ʱ�򣬱���ʵ�����еĴ��麯���������ɳ�������������Ҳ��һ�������ࡣ
              Virtual void fun()=0;���߱������� vtable ��Ϊ��������һ��λ�ã���������ض�λ�ò��ŵ�ַ��
            ���������ӿ�Ŀ����Ϊ�˽����๫���Ĳ����������������ͨ��һ�������ӿ�������һ���࣬����������ӿڲ�
            ��Ҫ����(���߲���Ҫ��ȫʵ��)�����Դ���һ��������,

            Ҫ�㣺
                1.��֮ǰ�ļ�������Ļ����ϣ��ں���� = 0��ʹ���� ���麯���� �麯�� = 0 ��
                2.���麯�����ã� ��֪�ڹ��츸���ʱ��vfptrָ����vftable,��vftable�������һ�� ����ĺ����ĵ�ַ�������д�ɴ��麯���Ļ�����������������ַ��ֵΪNULL��
                3.virtual int Mycalc(int a,int b) = 0;��仰��ֵΪ0������vfptr�麯��ָ�� ָ��� �麯���� ����� ������ڵ�ַ ��ֵΪNULL��֮��������ȥ��дʱ������Ǹ��麯��������ĺ�����д���ġ�

                4.�� ���д��麯������ ���� ������,�����಻��ʵ��������
                5.������� �̳��� �����࣬�� ���� Ҳ�� ������
                6.����� �̳��� ������ �� ���� ��д���麯�����Ͳ����ǳ����ࡣ

            �ܽ᣺
                ���麯�������麯�� ��ֵΪ 0��ʵ���ǽ��麯����ĺ�����ڵ�ַ��ֵΪNULL��
                ������ һ����������д��麯������ô��������һ�������࣬
                �̳��˳����������Ҳ�ǳ����ࡣ���������д���麯���������಻���ǳ����ࡣ
                �����಻��ʵ��������


            ����

                    #define _CRT_SECURE_NO_WARNINGS
                    #include <iostream>
                    #include <string.h>
                    #include <stdlib.h>
                    #include <string>
                    using namespace std;

                    class Calc
                    {
                    public:
                        //1.��֮ǰ�ļ�������Ļ����ϣ��ں���� = 0��ʹ���� ���麯���� �麯�� = 0 ��
                        //2.���麯�����ã� ��֪�ڹ��츸���ʱ��vfptrָ����vftable,��vftable�������һ�� ����ĺ����ĵ�ַ�������д�ɴ��麯���Ļ�����������������ַ��ֵΪNULL��
                        //3.virtual int Mycalc(int a,int b) = 0;��仰��ֵΪ0������vfptr�麯��ָ�� ָ��� �麯���� ����� ������ڵ�ַ ��ֵΪNULL��֮��������ȥ��дʱ������Ǹ��麯��������ĺ�����д���ġ�

                        //4.�� ���д��麯������ ���� ������,�����಻��ʵ��������
                        //5.������� �̳��� �����࣬�� ���� Ҳ�� ������
                        //6.����� �̳��� ������ �� ���� ��д���麯�����Ͳ����ǳ����ࡣ
                        virtual int Mycalc(int a,int b) = 0;

                    //    {
                    //        return 0;
                    //    }

                    };
                    class Mod:public Calc
                    {
                    //    Calc a;//���������಻��ʵ����
                    //    Mod a;//�̳��˳����������Ҳ�ǳ����࣬����ʵ������

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

            4.8.5 ���麯�� �� ��̳�
                ��̳д�����һЩ���飬���ǽӿڼ̳п���˵һ�ֺ�������������ˡ�
                ����������������Զ���֧�ֶ�̳У����Ǿ������������������Զ�֧�ֽӿڵĸ��

                c++��û�нӿڵĸ���,���ǿ���ͨ�����麯��ʵ�ֽӿڡ�

                �ӿ�����ֻ�к���ԭ�Ͷ��壬û���κ����ݶ��塣

                ���ؼ̳нӿڲ�����������Ժ͸��������⡣�ӿ���ֻ��һ�����������������ǹ���ʵ�֣�������Ҫ���ݹ���˵�����幦��ʵ�֡�
            ע��:�������������⣬�����������Ǵ��麯����

            4.8.6  ����������
                4.8.6.1 ��������������
                    ������������Ϊ�˽�������ָ��ָ����������󣬲��û����ָ��ɾ�����������

                �ܽ᣺
                    �����������ã��ڵ��ø������������֮ǰ�����ȵ������������������
                ����

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
                                cout << "������˵��" << endl;
                            }

                            virtual ~Animal()
                            {
                                cout << "���� ����" << endl;
                            }
                        };

                        class Dog:public Animal
                        {
                        public:
                            void speak()
                            {
                                cout << "����˵��" << endl;
                            }
                            ~Dog()
                            {
                                cout << "�� ����" << endl;
                            }
                        };

                        void dp_work(Animal &obj)
                        {
                            obj.speak();
                        }

                        void test()
                        {
                            Animal *p = new Dog;

                            p->speak(); //1.��Ϊ���õ���dog�Ķ������� ��ӡ ����˵��
                            delete p;   //2.��Ϊ�Ǹ����ָ��      ���� ���� �Ƕ��������������ͷŵ��ǻ���,����Ķ���û�б��ͷš�
                            //3.��֮ǰ�������������ʱ���ȴ����࣬�ٴ����ࡣ�����ǣ����������࣬���������ࣻ����������ָ����Animalָ�룬�������ͷŵ��Ǹ��ࡣ
                            //4.��ô���ܲ����������ͷŸ���֮ǰ�����ͷ����ࣿ => ֻ��Ҫ�ڸ������������ǰ��ӹؼ���virtual ,�������������
                            //5.�����������ã��ڵ��ø������������֮ǰ�����ȵ������������������
                        }

                        int main()
                        {
                            test();
                            return 0;
                        }
            4.8.6.2 ������������
                ��������������c++���ǺϷ��ģ�������ʹ�õ�ʱ����һ�����������:����Ϊ�������������ṩһ�������塣
                ��ô������:����������������ṩ�������ˣ�����ô���ܳ�����������������?
                �������������ͷǴ���������֮��Ψһ�Ĳ�֮ͬ���� �ڴ�����������ʹ�û����ǳ����࣬���ܴ�������Ķ���

            �ܽ᣺
                �������������������麯����Ϊ0��û�к����塣
            ����
                class Animal
                {
                public:
                    virtual void speak()
                    {
                        cout << "������˵��" << endl;
                    }

                //    virtual ~Animal()   //������
                //    {
                //        cout << "���� ����" << endl;
                //    }

                    //���������������ǣ�û��ʵ�ֵĺ����塣
                    virtual ~Animal() = 0;
                };
        4.8.7 ��д ���� �ض���
            ����(ͬһ�������ͬ������)
                1. ͬһ��������
                2.��������������˳�򣬲������Ͳ�ͬ
                3.�ͺ�������ֵ��û�й�ϵ
                4.const Ҳ������Ϊ�������� //���磺���ڲ������Σ����������Ǵ���������do(const Teacher& t){} do(Teacher& t)

            �ض���(����)
                5.�����̳�
                6.����(������)���¶��常��(����)��ͬ����Ա(��irtual����)
            ��д(����)
                7.�м̳�
                8.����(������)��д����(����)��virtual����
                9.��������ֵ���������֣���������������ͻ����е��麯��һ��

            �ܽ᣺
                ���أ�
                    * ͬһ������
                    * ��������ͬ
                    * �����ĸ�����˳�����Ͳ�һ��
                    * constҲ����Ϊ��������
                �ض���
                    * �����̳�
                    * ����͸�����ͬ���ı����ͺ�����������ͬ���ı����ͺ����ᱻ����
                ��д
                    * ���������麯��
                    * �����˼̳�
                    * ������д���麯���� ����ֵ  ������  ���� һ�£������岻һ�¡�

*/

/*
 *
5 c++ ģ��
    ����Ҫ�ļ��������Ͳ�������

    5.1 ģ���������Ҫ���ڼ��ٴ�����ظ��ʣ�
        c++�ṩ�˺���ģ��(functiontemplate.)��ν����ģ�壬ʵ������ ����һ��ͨ�ú������� �������� �� �β����� �������ƶ�����һ�� ��������� ������

    ����
        ����һ������ fun() ����β���Ҫ����ͬ�Ĳ������ͣ���int char short void* ��
        ��֮ǰ����� ���ص� ��д�������֣���Ҫд�ܶ�Ľ��޸����βεĺ����壬�����ظ���̫�ߡ����ģ��������Ͳ�ָ������ͨ�����������棬�ڵ���ʱ�ɵ��ô���ʵ����ָ������ʵ���������Ƶ����β����͡�

        ���ͨ�ú����ͳ�Ϊ����ģ�塣���Ǻ�������ͬ�ĺ��������������ģ�����,���ض�����������ֻ����ģ���ж���һ�μ��ɡ�
        �ڵ��ú���ʱϵͳ�����ʵ�ε�������ȡ��ģ���е��������ͣ��Ӷ�ʵ�ֲ�ͬ�����Ĺ��ܡ�

        c++�ṩ����ģ�����:
            ����ģ�壨���Ͳ����������βε����Ͳ�ָ������ͨ�����������棬�ڵ���ʱ�������������ʵ�Ƶ����β����͡�
            ��ģ��
                ���� - ���Ͳ��������ֳƲ���ģ��
        �ܽ�:
            ģ�� �� ���� �� �� Ҫ����� �������� ������������Ϊ �����Ķ�̬�ԣ���Ϊ������
            ģ�� ���ڱ�� �߼��ṹ��ͬ���� ��������Ԫ������ ��ͬ�� ���ݶ����

    5.2 ����ģ��
        5.2.1 ʲô�Ǻ���ģ�壿
            //����һ��ͨ��ģ�壬ģ���ͨ������ΪT�� class �� typename����һ���ģ����ĸ������ԡ�
            template<class T>
            //������������Ķ���
            void swap_temp(T &a,T&b)
            {
                T tmp = a;
                a = b;
                b = tmp;
            }
        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            #if 0
            //����int������
            void swap(int & x,int &y)
            {
                int tmp = x;
                x = y;
                y = tmp;
            }
            //����char������
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

            //����ģ����ʵ��
            template<class T> //����һ��ͨ��ģ�壬ģ���ͨ������ΪT�� class �� typename����һ���ģ����ĸ������ԡ�
            //������������Ķ���
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
                swap_temp(a,b);//�Զ������Ƶ���
            //    swap_temp(a,c);//�Ƶ����Ͳ�һ�»����
                swap_temp(c,d);
                cout << a <<" " <<b << endl;
                cout << c <<" " <<d << endl;
            }

            int main()
            {
                test1();
                return 0;
            }

        5.2.2 ������ϰ
            ʹ�� ����ģ��ʵ�ֶ�char �� int ���������������

        ע�⣺
            ����ģ����� �Զ��Ƶ� Ҳ���� ��ʾָ�����͡���Ϊ�Ƶ���Ƚ��鷳
            template<class T>
            void swap_temp(T &a,T &b){}
            swap_temp(a,b);      //�Զ������Ƶ���
            swap_temp<char>(a,b);//��ʾָ�����͡�
        ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //����ģ�� ��������
                template<class T>
                void array_sort(T *p,int n)//��������Ԫ�ص�ַ���������
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
                //    array_sort(a,sizeof(a)/sizeof(a[0]));        //�Զ������Ƶ�
                    array_sort<double>(a,sizeof(a)/sizeof(a[0]));  //��ʾָ������
                    print_array(a,sizeof(a)/sizeof(a[0]));
                }
                int main()
                {
                    test1();
                    return 0;
                }

    5.3 ����ģ�����ͨ��������
        ����ģ�岻�����Զ�����ת��
        ��ͨ�����ܹ��Զ���������ת��

    �ܽ᣺
        ��ͨ���������Զ���������ת��
        ����ģ�岻���Զ���������ת��
    ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //��ͨ����
            int My_Add(int a,int b)
            {
                cout<<"��ͨ����" <<endl;
                return a + b;
            }

            //ģ��
            template <class T>
            T My_Add(T a,T b)
            {
                cout<<"ģ�庯��" <<endl;
                return a + b;
            }

            void test()
            {

            }


            int main()
            {

                int a = 10;
                char b = 20;
                My_Add(a,a);     //ֱ�ӵ�����ͨ�����������Ƶ��������������ģ�庯������� <>,
                My_Add<int>(a,a);//��ʾָ������
                My_Add<>(a,a);   //ָ���Զ��Ƶ�
                My_Add(b,b);     //��ͨ�������Ͳ�ƥ�䣬�Զ�����ģ�庯��

                My_Add(a,b);     //�������Ͳ���ͬ�ģ����õ�����ͨ����������ʵ���Զ�����ת����charתΪint���������ģ����ᱨ��
            //    My_Add<>(a,b);     //�����ģ����ᱨ��,��Ϊ�Զ��Ƶ������������Ͳ�һ�£�����ģ�岻�����Զ�����ת����
                return 0;
            }

    5.4 ����ģ�� �� ��ͨ������һ����ù���
        c++���������ȿ�����ͨ����

        ���ʵ��Ҫ�ú���ģ�壬����ͨ����ģ��ʵ���б���﷨�޶�������ֻ��ͨ��ģ��ƥ�䣬����<>ָ������ģ��

        ����ģ�� ������ ��ͨ���� �������Ա� ����

        �������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��

    �ܽ᣺
        * c++���������ȿ�����ͨ����
        * ����ͨ���� <> ,�޶�������ֻ�ܵ���ģ�����ƥ��
        * ����ģ���������ͨ��������������
        * ����ģ������и��õ�ƥ�䣬����ʹ�ú���ģ��

    ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //����ģ��
            template<class T>
            T Myplus(T a,T b)
            {
                cout << "����ģ��" << endl;
                return a + b;
            }

            //��ͨ����
            int Myplus(int a,int b)
            {
                cout << "��ͨ����" << endl;
                return a + b;
            }

            //���غ���ģ��
            template <class T>
            T Myplus(T a, T b,T c)
            {
                cout << "ģ�庯��" << endl;
                return a + b + c;
            }

            void test()
            {
                int a = 10;
                int b = 20;
                char c = 'a';
                char d = 'b';
                //�������ģ�����ͨ��������ƥ�䣬c++���������ȿ�����ͨ����
                cout << Myplus(a,b) << endl;
                //���Ҫ��������ģ�壬���<>
                cout << Myplus<>(a,b) << endl;
                //��ʱ��ͨ����Ҳ����ƥ�䣬��Ϊ��ͨ���������Զ�����ת��
                //���Ǵ�ʱ����ģ���ܹ��и��õ�ƥ��
                //�������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��(�������Ͷ���char������ǵ�����ͨ��������Ҫת�������ͣ����ƥ��ģ�����)
                cout << Myplus(c,d) << endl;

            }
            int main()
            {
                test();
                return 0;
            }

    5.5 ģ���������
        ˼��:Ϊʲô����ģ����Ժ���ͨ��������һ�� c++�����������ʵ�ֺ���ģ����Ƶģ�

        5.5.1 �������
            hello.cpp�����Ǹ߼�c���Գ������ֳ������ڱ��˶�������Ϊ����ϵͳ������hello.c����ÿһ��c��䶼����ת��Ϊ�ͼ��Ļ���ָ�Ȼ����Щ����ָ�����ɿ�ִ��Ŀ���ļ���ʽ�����Զ�������ʽ�洢�ڴ����С�
            Ԥ����Pre-processing��-> ���루Compiling��->��ࣨAssembling��->���ӣ�Linking��

            hello.i                 hello.s             hello.o             hello.exe

hello.c     Ԥ������       =��       ������        =��     �����       =��      ������


            hello.c����Ԥ������������չ�������ɵ��ļ�hello.i
            hello.i���������������ļ�����ɻ�����ԣ������ļ�Ϊhello.s
            hello.s��������������ļ������Ŀ���ļ�hello.o��win��Ϊhello.obj��
            hello.o���������������ļ�����ɿ�ִ���ļ�

        5.5.2 ģ��ʵ�ֻ���(����ģ��ı���)
            ����ģ����ƽ��ۣ�
                ������ �����ǰ� ����ģ�� ����� �ܹ������κ����͵ĺ���
                ���ǣ�����ģ�� ͨ�� ������ �Ͳ�����ͬ�ĺ���
                ��������Ժ���ģ����� ���α��룬�������ĵط���ģ����뱾����б��룬�ڵ��õĵط��Բ����滻��� ������б��롣

            �ܽ᣺
                ����ģ��ı��� ���� ���ж��α��롣
                    ��һ�ζԺ���ģ����б��룺��ģ����뱾����б���
                    �ڶ����ں������ô����Ժ���ģ��չ�������ж��α��롣���Բ����滻��Ĵ�����б���

                �������ʵ�ʾ���Ϊ�˽���궨���޷������ͼ���ȱ�ݣ���һ�α����Ǽ��ģ���Ƿ����﷨���󣬵ڶ��α������ڵ��ú�����ʱ��Ϊ���õ����Ӧ���͵ĺ��������ٴν��б��롣
                ���ݱ������Ժ���ģ��Ķ��α����֪������ģ�岢����һ��ʵ�ʴ��ڵĺ��������ǲ���ʵ�ʺ�����ģ�壬������ʹ�ò������е��ã��������ڶ��α����Ż����һ�������ĺ�����0

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //��ͨ����
                int My_Add(int a,int b)
                {
                    cout<<"��ͨ����" <<endl;
                    return a + b;
                }

                //ģ��
                template <class T>
                T My_Add(T a,T b)
                {
                    cout<<"ģ�庯��" <<endl;
                    return a + b;
                }
                //1.��һ�α��룬�Ժ���ģ���﷨���б��루���������������ߣ��ߵ�����ʱ�����﷨���б��룩
                //3.չ����Ĵ������£�ע�⣬չ����Ҳû��template <class T>�ˡ�
                //int My_Add(int a,int b)
                //{
                //    cout<<"ģ�庯��" <<endl;
                //    return a + b;
                //}
                //4.�����һ��char���ʹ�ĵ��ã���չ��Ϊ��չ��֮��ҲҪ���еڶ��α��룬
                //char My_Add(char a,char b)
                //{
                //    cout<<"ģ�庯��" <<endl;
                //    return a + b;
                //}
                //5.������������֪������ģ�� �ı��ʾ��� ���ж��α��롣

                void test()
                {
                    int a = 10;
                    char b = 20;
                    My_Add(a,a);        //2.����a��int���ͣ��ڵ��õ�ʱ����������ģ�����չ������Ϊ�������Ƶ���a��int���ͣ���չ��ʱ����int�滻T����
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

    5.6 ģ��ľ�����
        �����ԣ����T���Զ������ͣ��ṹ�壬���飬��ַ����ȣ���ܿ����޷�������������ǲ�ϣ���Ĳ����������ڱȴ�С��ʱ����Ҫʵ�ֱȴ�С������Ҫʹ��operator��������>��= �ȡ�

        ����û��ģ�庯��
        template<class T>
        void f(T a,T b){...}

        �������ʵ��ʱ�����˸�ֵ����a = b,����TΪ���飬���ּ���Ͳ������ˡ�
        ͬ���������������Ϊ�ж����if(a>b),��T����ǽṹ�壬�ü���Ҳ����������������Ǵ�������飬������Ϊ��ַ��������Ƚϵ��ǵ�ַ������Ҳ����������ϣ���Ĳ�����

        ��֮����д��ģ�庯���ܿ����޷�����ĳЩ���ͣ���һ���棬��ʱ��ͨ�û���������ģ��� c++�﷨��������������Ϊ�˽���������⣬�����ṩģ������أ�Ϊ��Щ�ض��������ṩ���廯��ģ�塣

    ��ϰ��
        ������ ��4���Դ�������operator=�������޲ι��졢�������졢����������
    ע��:
        �������廯��ʽ�����������廯�����ã�������ʶ���ɣ����ں�����ǰ��� template<>,��������T�滻���Զ����������͡�
        template<> void mySwap(Person &p1,Person &p2)
    ����  ��
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //1.��һ�ַ����������Զ������͵��������ͣ������������ṹ���ǲ��еģ�����������Զ����������ͣ��Ϳ���ȥ�޸�����࣬�޸������operator���غ������Ӷ�ʵ�����蹦�ܣ�
            //2.��T��Person,������name��age�����бȽϺ͸�ֵ��
            //3.���ڸ��Զ�����������ͣ���ô���ǵ���operator=���������߱Ƚ�>�ţ���ȥ���������ȥ��дһ��operator>��������������غ��� �������ء�
            //4.��ʱ����Ҫ�Լ�����ʵ�ֺ����塣
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

            //��ͨ��������
            //5.���������������������������Person���ͣ������ǽ������˵ģ�
            //6.����дoperator���غ����⣬�����԰Ѻ������廯��
            template<class T>
            void mySwap(T &a,T &b)
            {
                T tmp = a;
                a = b;//������õ���operator=������
                b = tmp;
            }


            //���������廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
            //���廯�����ڳ���ģ��
            //7.�����������֣����Ǿ��廯��ǰ���template<> Ȼ�������T�������Զ����������͡�
            //8.���������廯�����ã���Ϊ���鷳��Ҫע��ĵط��ܶ࣬����ȥдһ��ȫ�ֺ������и�ֵ������дһ�����ڵĺ������и�ֵ��
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

    5.7 ��ģ��
        5.7.1 ��ģ��Ļ�������
            ��ģ�� �� ����ģ��Ķ����ʹ�����ơ���ʱ�������������࣬�书������ͬ�ģ��������������Ͳ�ͬ��
            ��ģ������ʵ�����������ݵ����Ͳ�������
        ����
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

            //ͨ����ģ�壺
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
                Animal<int,int> dog2(10,10);  //ע��:��ģ�岻���Զ������Ƶ������Ҫ��ʾָ�����͡������ҵ�QT���Խ����Զ�������ת������û�����ʾָ����
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

        5.7.2 ��ģ����Ϊ��������
        �ܽ᣺
            ��ģ����Ϊ�����β�ʱ���ú�����Ҫд�ɺ���ģ����ʽ��
        д�������֣�
            1.
                template<class T1>
                void show(T1 &p)
            2.
                template<class T1,class T2>
                void show(Animal<T1,T2> &p)

        ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //ͨ����ģ�壺
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

                //1.��Ϊ�βΣ�����Ϊ����ģ�����͡�����ΪAnimal<int,int>
                //2.�������ǣ��βε�����Ϊ<int,int>,�ʲ��ܴ�cat��<int,string>���͡�
                //3.��ˣ����������β���Ϊ��ģ���ʱ�򣬾���������д�ɺ���ģ�����ʽ��
                //д��һ��
                //template<class T1,class T2>
                //void show(Animal<T1,T2> &p)
                //{
                //    cout << p.age <<" "<<p.data <<endl;
                //}
                //д������
                template<class T1>
                void show(T1 &p)    //��Animal<int,int> dog2(10,10);����Ϊ�����൱�ڰ�����<int,int>���ͣ�������T1������
                {
                    cout << p.age <<" "<<p.data <<endl;
                }

                void test()
                {
                    Animal dog(10,10);
                    Animal<int,int> dog2(10,10);  //ע��:��ģ�岻���Զ������Ƶ������Ҫ��ʾָ�����͡������ҵ�QT���Խ����Զ�������ת������û�����ʾָ����
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

        5.7.3   ��ģ��������ͨ�ࣨ��ģ�������̳У�
            һ����̳�����ģ�壬��ǰ������Ӧ����ôȥд��

        �ܽ᣺
            * ��ģ�������̳У��ڼ̳�ʱ���̳е��������һ��ģ����<>
            * ��ģ�������̳У����Խ�����д����ģ��
        д����
                template<class T>
                class Base{}��

                template<class T1,class T2>
                class Son2:public Base<T2>
                {
                public:
                    //��ʼ���б��Ρ�
                    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}
                    T1 x;
                };

        ����

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

                //д��һ��
                //2.������������Tд��Ϊint�����ˡ�
                class Son:public Base<int>
                {
                public:
                    //1.�ó�ʼ���б��칹�캯�������ȹ������Base<int>,����a����ȥ����x��ֵΪx1
                    Son(int x1, int a):Base<int>(a),x(x1){}
                    int x;
                };

                //д������
                template<class T1,class T2>
                class Son2:public Base<T2>
                {
                public:
                    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}

                    T1 x;
                };

                void test()
                {
                    //3.�������ֻ��д<int,int>����.
                    Son p(10,20);
                    Son2<int,string>(30,"lisa");
                }
                int main()
                {
                    test();
                    return 0;
                }

        5.7.4 ��ģ��� ��Ա������ ����ʵ�� ����ģ������ڵĳ�Ա�����������ڵĻ�����ôȥʵ�֣���

        ����
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
                //��Ա��������ʵ�֣�
                Person(NameType name,AgeType age)
                {
                    this->mName = name;
                    this->mAge = age;
                }
                void showPerson()
                {
                    cout << "name��" << this->mName << "age: " << this->mAge << endl;
                }
                NameType mName;
                AgeType mAge;
            };
            void test()
            {
                //Person P1("��������"��18);//��ģ�岻�ܽ��������Զ��Ƶ�
                Person<string,int>p1("��������",18);
                p1.showPerson();
            }
            int main()
            {
                test();
                return 0;
            }

        5.7.5 ��ģ��� ��Ա������ ����ʵ��

        �ܽ᣺
            ��ģ��ĳ�Ա���� ����ʵ�֣���Ҫ�ѳ�Ա����д�ɺ���ģ����ʽ��
        ����

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
                    //��Ա��������ʵ�֣�
                    Person(T1 a,T2 b);
                    void showPerson();

                    T1 a;
                    T2 b;
                };
                //1.��ģ��ĳ�Ա����������ʵ�֣���Ҫд�ɺ���ģ����ʽ��
                //2.������Person��ģ���࣬�ʣ�����дΪ��Person::Person(T1 a,T2 b),����д�ɣ�Person<T1,T2>::Person(T1 a,T2 b)
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

        5.7.6 ��ģ��ĳ�Ա��������ʱ����
            ����Ϊ�˽��������ģ��ͷ�ļ� �� Դ�ļ���������⣩
        �ܽ᣺
            ��ģ���Ա�����Ĵ���ʱ�����ڵ���ʱ��ֻҪû�е��ã��������Ͳ��ᴴ�����������ֻ��������


        ע�⣺
            �ڴ˼�¼һ�£��������ӵĲ������裬���⸴ϰ���������
                1.�����루һ��)ȡ��ע�ͣ�����p�ٵ��ú���,���Է��ֲ�����������Ա���ͨ��
                2.�����루����)ȡ��ע�ͣ�����p�����ú���,���Է��ֲ�����������Ա���ͨ��
                3.��2.�Ļ����ϵ���p�ĺ��������ֱ���󱨴�
                4.���������Լ������ע��1.��֪����ģ��ĳ�Ա�����Ĵ���ʱ�����ڵ��õ�ʱ��û����ʱ��ֻ��������
        ����
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

            //һ������ʵ�֣�
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

            //    T obj;//����һ��T���͵�obj����/���󣬿��Դ�A/B����
            //};

            //�����൱������ֻ����������ʱҲ�ܳɹ���
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

                T obj;//����һ��T���͵�obj����/���󣬿��Դ�A/B����
            };


            void test()
            {
                //1.����Pʱ����������:ҪôAҪôB����ô��C�����棬����������Ӧ����ͬʱ���ڣ���Ϊ��ʱfoo2Ӧ�ûᱨ���Ƿ����ʣ�A���͵���B�ĳ�Ա������������ʵȴ�Ǳ���ʱ��û�б���
                //2.��һ������ʵ�֣��Ͷ����������� �Լ� ��ֻ�Ƕ���p,û�е��ó�Ա�����������û�б����֪��������������û�ж��塣
                //3.������p���ҵ��ó�Ա������ʱ�򣬾ͻᱨ��foo�Ķ���û�ҵ�����
                //4.˵����ģ��ĳ�Ա�����Ĵ���ʱ�����ڵ��õ�ʱ��ֻҪû�е��ã����������ǲ��ᴴ���ġ�

                //5.Ҳ����˵����ģ��ĳ�Ա�����Ĵ���ʱ�����ڵ���ʱ�������������������ĺ�������ô�Ͳ��ᴴ���ģ�ֻ�к�����������
                C<A> p;

                p.foo1();//����foo1
            }

            int main()
            {
                test();
                return 0;
            }

        5.7.7 ��ģ��ͷ�ļ� �� Դ�ļ���������
            ��ģ���ͷ�ļ���Դ�ļ����� �� ��ͨ�ļ��ķ��벻̫һ����

        �ܽ᣺
            �ڷ��ļ�ʱ������Ѻ����Ķ��� �� ������� д��һ���ļ�����ȥ������Ѻ��������������.cpp���棬����ÿ��.cpp���ǵ�������ģ��ڱ���ʱ���Ҳ����������塣
            ���� ��ģ��ĳ�Ա�����Ķ��� ֱ��ʹ���ڲ����壬�����ڲ���ɶ���
        ע�⣺
            ��.h����������������������Ķ��壬���ȡ����ʱ�򣬿�������ȡ��.hpp��(.cpp��.h�Ľ���壬����������������к����Ķ���)
        ����
            //Person.h�ļ�
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
            //��Person����ĺ��������ⲿ���塣
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
            //3.�������ͷ�ļ����൱�ڰ�.h�ù�����
            //4.������ÿ��.cpp���ǵ��������


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
                //1.��ʱ���룬�ᱨ���޷��������ⲿ����Person<int,int>,Ҳ����˵û���ҵ������Ķ��塣
                //2.�޷��ҵ�����Ϊ����ģ��ĳ�Ա�������ڵ��õ�ʱ��Ŵ�����
                Person<int,int> p(10,20);
                p.show();//5.�����������뵽����ʱ��������Ҫ����p�Ĺ��캯���͵������show����,���õ�ʱ�����Ҫ�����������
                         //6.���ǣ����������봴��������������ʱ����������������û���ڵ�ǰ.cpp���棨main.cpp��������������.cpp���棨Person.cpp������ʱ��������Ҫ���������������ͻ��Ҳ�����
                //7.�������ù��캯����show������Ҫ��������������������û�������������Ķ��壬���ܱ�������

                //8.����İ취���ǣ���������Ķ�����Ҫ�ŵ�Person.h���У����ܷ���.cpp���档
                //9.��ģ��ķ��ļ����⣺����Ѻ����Ķ�����������д��һ���ļ�����ȥ������ݵķ����ǣ���ģ��ĳ�Ա��������ֱ��ʹ���ڲ����壬��������ʵ�ֶ��塣
                return 0;
            }

        5.7.8 ��ģ��������Ԫ����
            ��Ԫ������1. friend void showPerson1<>(Person<T1,T2> &p);   ǰ��friend,���Һ��������<>������������ ���÷�ʽ��ģ���ࡣ
                    2. ֱ����ģ���������ֱ������������ ��Ԫ�����������������Ȼ��ȫ�ֺ�����
                       ���巽ʽ��friend void showPerson2(Person<T1,T2> &p){}   ���ֶ���ģ�����Ҫ�ں����������<>����������Ϊģ�庯����
            �ܽ᣺
                �ڴ����У�����ʹ�÷���3����ʹ�á�
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;


                //��ģ���������Ҫ�������ж��õ�ǰ������
                template<class T1,class T2>
                class Person;

                //5.showPerson1��ȫ��ģ�庯��������
                template<class T1,class T2>
                void showPerson1(Person<T1,T2> &p);

                //1.��ģ����Ϊ�����β� ������Ҫд�ɺ���ģ��
                //����һ��ȫ��ģ�庯��д�� ������档
                template<class T1,class T2>
                void showPerson(Person<T1,T2> &p)
                {
                    cout << p.a << " " << p.b <<endl;
                }

                template<class T1,class T2>
                class Person
                {
                    friend void showPerson1<>(Person<T1,T2> &p);    //4.��������Ϊ��Ԫ��ʱ��������ǰ���Ҳ�����������˻ᱨ����Ҫ����ǰ�����3.��������
                    friend void showPerson<>(Person<T1,T2> &p);//2.��ֻ��������ͨ�ĺ���Ϊ������Ԫ��
                    //��������������ֱ��д��������档
                    //ע�⣺���ַ���д�ĺ�����������ĳ�Ա������ʵ�ʻ���ȫ�ֺ�������Ϊǰ�����һ��friend��������һ��ȫ�ֺ�����������Ϊ�����Ԫ��
                    friend void showPerson2(Person<T1,T2> &p)//������ֱ�Ӷ��壬�������������Բ���Ҫ��ǰ��һ���ں����������һ��<>��
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

                //3.��ȫ��ģ�庯�� ������
                //��������ȫ��ģ�庯��д��������棬����Ҫ������
                template<class T1,class T2>
                void showPerson1(Person<T1,T2> &p)
                {
                    cout << p.a << " " << p.b <<endl;
                }

                void test()
                {
                    Person<int,string> p(10,"lucy");
                    showPerson(p);  //p����ģ�壬Person<int,string>������͵ģ��ຯ�����β�
                    showPerson1(p);
                    showPerson2(p);
                }
                int main()
                {
                    test();
                    return 0;
                }

    5.8 ��ģ���Ӧ��
        ���һ������ģ���ࣨMyArray��,��ɶԲ�ͬ����Ԫ�صĹ���,���������洢 ����� �������ͣ�����Ƶ�ʱ��ܼ򵥡���
        ��дһ�����飬�������ʵ�ִ洢�������ͣ����Զ�̬�����ӻ�ɾ��������������c����ض�̬���飩

        template<class T>
        class Array
        {
        public�����캯�� Ԫ��β�� ����ظ�ֵ= Ԫ�ص�ɾ����

        private:
            int size;
            int capacity;
            T *ptr;
        }

        ����
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
                //�вι��죬explicit����ȷ��explicit�ؼ����������� ��Ĺ��캯���������εĹ��캯�����࣬���ܷ�����Ӧ����ʽ����ת����ֻ������ʽ�ķ�ʽ��������ת����
                explicit MyArray(int capacity)  //���캯�� �����������������Ĵ�С����������ʱ���û�ָ������Ĵ�С
                {
                    this->m_Capacity = capacity;    //������С���ݵ���ĳ�Ա���б���
                    this->m_Size = 0;               //Ԫ�ظ�����ʼ��Ϊ0��

                    //���T�Ƕ�����ô�����������ṩĬ�ϵĹ��캯��
                    pAddress = new T[this->m_Capacity]; //newһ��������С������ռ�
                }

                //�������죺�������и�ֵ��ʱ�������������new�ռ䣬���ܼ򵥵Ľ���ֵ����������ַ����������Ҫ��д�������졣
                MyArray(const MyArray &arr)
                {
                    this->m_Capacity = arr.m_Capacity;
                    this->m_Size = arr.m_Size;

                    this->pAddress = new T[this->m_Capacity];
                    //ע�⣺���ﲻ��ʹ��memcpy����ΪmemcpyҲ�Ǽ򵥵�ֵ����������������Ƕ���Ŀ�����������Ҫһ��һ�����и�ֵ
                    for(int i = 0;i < this->m_Size;i++)
                    {
                        this -> pAddress[i] = arr.pAddress[i];
                    }
                }

                //����[] ������ arr[0]
                //����[]��Ӧ��Ԫ�ء����������á�  MyArray a(10); a[9]��
                T& operator[] (int index)
                {
                    return this->pAddress[index];
                }

                //β�巨�����������ݵ����� ���ݵ�ֵ
                void Push_back(const T &val)
                {
                    //�ж������Ƿ����ˣ����˾�����
                    if(this->m_Capacity == this->m_Size)
                    {
                        return ;
                    }
                    //û���Ͱ�valֵ��ֵ�����
                    this -> pAddress[this->m_Size] = val;
                    this->m_Size++;
                }

                //βɾ��
                void Pop_back()
                {
                    if(this->m_Size == 0)
                    {
                        return ;
                    }
                    this->m_Size--;
                }

                //���size.
                int getSize()
                {
                    return this->m_Size;
                }

                //��������:����ָ��ָ��NULL�������ʹ�СΪ0
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
                T * pAddress;   //ָ��һ���ѿռ䣬����ռ�洢���������ݣ�ָ���������Ԫ�ص�ַ��
                int m_Capacity; //���������
                int m_Size;     //Ԫ�صĸ���
            };
*/

/*
    6. c++����ת��
        ����ת��(cast) �ǽ� һ���������� ת���� ��һ���������͡�
        ���磬�����һ������ֵ ���� һ���������͵ı������������ᰵ���ｫ��ת���ɸ������͡�

        ת���Ƿǳ����õģ�������Ҳ�����һЩ���⣬������ת��ָ��ʱ�����Ǻܿ��ܽ���ת����һ���������������,������ܻ��ƻ����������ݡ�

        Ӧ��С������ת������Ϊ ת�� �൱�ڶԱ�����˵:�������ͼ�飬�����������������͡�
        һ������£������ٵ�ȥʹ������ת����������������ǳ���������⡣

        ����ʲôԭ���κ�һ���������ʹ�úܶ�����ת����ֵ�û���.

        ��׼ c++�ṩ��һ�� ��ʾ ��ת�����﷨��������ɵ�C��������ת����

        ʹ��C����ǿ��ת�����԰���Ҫ���κζ���ת����������Ҫ�����͡���Ϊʲô����Ҫһ���µ� C++���͵�ǿ��ת����?
        �����͵�ǿ��ת�������ṩ���õĿ���ǿ��ת�����̣�������Ƹ��ֲ�ͬ�����ǿ��ת����C++����ǿ��ת�� �����ĺô��ǣ������ܸ������ı�������Ҫ��ʲô������ԱֻҪɨһ�������Ĵ��룬��������֪��һ��ǿ��ת����Ŀ�ġ�


        6.1 ��̬ת�� ��static_cast������Ҫ����ת ���õ��������ͣ���int char �����������ͣ������Զ�����������ͣ���ֻ��ת�����̳й�ϵ֮�������ࡣû�з����̳й�ϵ�����ǲ���ת�ģ�

            ���� ���νṹ�� ����(����) �� ������(����) ֮�� ָ�� �� ���� ��ת����
            ��������ת��(�� �������ָ�� �� ���� ת���� �����ʾ)�ǰ�ȫ��;
            ��������ת��(�ѻ���ָ�������ת�����������ʾ)ʱ������û�ж�̬���ͼ�飬�����ǲ���ȫ�ġ�
            ���ڻ�����������֮���ת�������intת���� char����char ת����int������ת���İ�ȫ��ҲҪ������Ա����֤
        �ܽ᣺
        ��̬ת����static_cast<��ת��������> (��ת��������)
            * static_cast ��������ת�������������������ͣ�int char double��
            * static_cast����ת��û�з����̳й�ϵ֮����ࡣ
            * static_cast��������ת�������̳й�ϵ���࣬���ǲ���֤��ȫ�ԡ�
            * static_cast��������ת��ָ�롣

        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            void test()
            {
                //static_cast ����ת�������������� �� c���Ե�ǿ������ת�����ơ�
                int a = 1;
                char b = 2;
                double c = 3.14;
                a = static_cast<int> (b);      //�����������ת��Ӧ���ǣ� a = static_case<int> (b);    //������Ϊ����һ��ģ�壺<>
                a = static_cast<int> (c);
                c = static_cast<double> (a);
            }

            class A
            {
            public:
                int a;
            };

            //1.�ڲ��̳еĻ�����
            //class B
            //{
            //public:
            //    int b;
            //};

            //4.�����̳й�ϵ
            class B:public A
            {
            public:
                int b;
            };

            void test1()
            {
                A *p1 = new A;
                B *p2 = new B;
            //    p1 = p2;                    //2.����,
            //    p1 = static_cast<A*> (p2);   //3.Ҳ�ᱨ����Ϊ����static_cast����ת��û�з����̳й�ϵ֮����ࡣ
                //5.���������֮�䷢���˼̳й�ϵ�����Խ�������ת����
                p1 = static_cast<A*> (p2);

                //6.��ʱ���⣺�Ƿ�ȫ�� ���B�Ŀռ��A�ռ�С��BתA�Ƿ�ȫ��=>��ȫ����ΪA�ܷ��ʵĿռ�Ƚ�С��B�Ķ���ת��A�Ķ���ʹ���ܷ��ʵĿռ��С�ˡ�
                //7.��AתB�ǲ���ȫ�ģ���ΪAת��B֮���ܷ��ʵĿռ������Խ������ˡ�
                p2 = static_cast<B*> (p1);

                //8.��� �ӣ���ռ䣩ת����С�ռ䣩�� ����ת���ǰ�ȫ�ġ�
                //9.    ����С�ռ䣩ת�ӣ���ռ䣩�� ����ת���ǲ���ȫ�ġ�
                //10.��ע�⣺static_cast<>��������ת����ʱ���ǲ��ᱣ֤ת���İ�ȫ�Եġ�

            }

            void test2()
            {
                int * p1 = NULL;
                char *p2 = NULL;
            //    p1 = static_cast<int *> (p2);   //11.������ͨ��ָ��static_cast����ת����ֻ��ת��ͨ���������͡���ָ���ת���ˡ�
            //    p2 = static_cast<char *> (p1);
            }

            int main()
            {
                test1();
                return 0;
            }

        6.2 ��̬ת����dynamic_cast��
            dynamiccast��Ҫ���� ��μ������ת�� �� ����ת����
            �� ���μ� ���� ����ת��ʱ��dynamic_cast��static_cast��Ч����һ����:
            �ڽ��� ����ת��ʱ��dynamic_cast���� ���ͼ�� �Ĺ��ܣ���static_cast����ȫ;

        �ܽ�:
            * ��������ת����������������
            * ��������ת�������̳й�ϵ֮����࣬��֤ת���ǰ�ȫ�ġ����ӿ�ת����������ת�ӣ�
            * ��� �����˶�̬����ת�� �� ��ת�� ���ǰ�ȫ�ġ�����̬�������̳У��������麯����������д�麯����Ȼ���ø����ָ�루��������ʲô���͵�ָ��) �� ���� ָ����� �������������麯�����������麯�����汣��ĺ����ĵ�ַ�Ƕ�̬�󶨵ģ������ǲ���Խ��ģ�������ַ����ȷ���ģ���˶�̬���ǰ�ȫ�ģ�
        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            void test()
            {
                //static_cast ����ת�������������� �� c���Ե�ǿ������ת�����ơ�
                int a = 1;
                char b = 2;
                double c = 3.14;
                a = static_cast<int> (b);      //�����������ת��Ӧ���ǣ� a = static_case<int> (b);    //������Ϊ����һ��ģ�壺<>
                a = static_cast<int> (c);
                c = static_cast<double> (a);
            }

            class A
            {
            public:
                int a;
            };

            //1.�ڲ��̳еĻ�����
            //class B
            //{
            //public:
            //    int b;
            //};

            //4.�����̳й�ϵ
            class B:public A
            {
            public:
                int b;
            };

            //��̬ת��:dynamic_cast
            void test3()
            {
                //1.��̬ת������ת���õĻ����������͡�
                int a = 1;
                char b = 2;
            //    a = dynamic_cast<int> (b);//��������ת������������
            }

            void test4()
            {
                //2.ת�Զ�����������
                A * p1 = NULL;
                B *p2 = NULL;

                //3.����ת����ǰ��: �����˼̳й�ϵ��û�м̳й�ϵ�ǲ��ܽ���ת���ġ�
                //dynamic_cast��������û�з����̳й�ϵ֮�����ת��
                //dynamic_cast�������ڷ����̳й�ϵ֮������ת����
                p1 = dynamic_cast<A *>(p2); //��ת������ȫ��
            //    p2 = dynamic_cast<B *>(p1); //��ת��,����ȫ��ת����
                //4.��ˣ��������̳���֮�� ����ת���������� ��̬ת������֤�˰�ȫ�ԣ���static_cast���ܱ�֤��ȫ�ԡ�
            }

        6.3 ����ת�� ��const_cast��
            ������������޸����͵�const���ԡ�����Щ��Ҫȥconst ��Щ��Ҫ��const��
            ����ָ�� ��ת���� �ǳ���ָ�룬���� ��Ȼָ�� ԭ���Ķ���;
            �������� ��ת���� �ǳ������ã����� ��Ȼָ�� ԭ���Ķ���;

        ע��:����ֱ�Ӷ� ��ָ�� �� �����õ� ���� ʹ��const_cast ������ȥ ֱ���Ƴ����� const��

        �ܽ᣺
            * const_castһ��������const��ȥconst��
        ����
            #define _CRT_SECURE_NO_WARNINGS
            #include <iostream>
            #include <string.h>
            #include <stdlib.h>
            #include <string>
            using namespace std;

            //constת��
            void test()
            {
                const int a = 1;
                int * p1 = NULL;
                const int *p2 = NULL;
                //static_castֻ��ת��������������
            //    int *p1 = static_cast<int *> (p2);//ת����


                p1 = const_cast<int *> (p2);         //ȥconst
                p2 = const_cast<const int *> (p1);   //��const

            }

            int main()
            {
                test();
                return 0;
            }

        6.4 ���½���ת����reinterpret_cast��
            �������ȫ��һ��ת�����ƣ����п��ܳ����⡣

            ��Ҫ���� ��һ���������� �� һ������ ת��Ϊ ��һ�����͡�
            �����Խ�һ��ָ�� ת���� һ��������Ҳ���Խ�һ������ ת���� һ��ָ�롣

        �ܽ᣺
            reinterpret_cast:
                * һ������ת��ָ�룬 ������ָ��֮�䶼����ת����
        ��ע�⣺
                ��ת��ʱҪע���������͵Ĵ�С�����磺��64λ�����У�int*��8bytes��int��4bytes��int* ת int���ܻᵼ�����ݶ�ʧ��int�޷�����ָ���λ���Ӷ�����Cast from pointer to smaller type 'int' loses information��
                �������ʵ��Ҫʹ�ã����޸ĳɿ���ʹ�õĺ��ʵ��������ͣ�����uint ptr_t������һ���޷����������ͣ���������ָ���λ����
        ����
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
                //static_cast ��������תָ��
                //p1 = static_cast<int *>(p2)

                //dynamic_cast��ָ̬�� ��Ҫ������ ת�������֮����������͡�

                //const_cast��Ҫ���� �Ӽ�const
            //    p1 = p2;//����
                p1 = reinterpret_cast<int *>(p2);
                p2 = reinterpret_cast<char *>(p1);

                int c = 0;
            //    c = p2;//����

                //Cast from pointer to smaller type 'int' loses information
            //    c = reinterpret_cast<int> (p1);//��ӦҲ��ȷ������ԭ���ǣ�1.int * ת int ����ȫ ���ܵ������ݶ�ʧ 2.��ʵ����Ҫ�������ʹ�ú��ʴ�С�����ͣ����磺uintptr_t �����޷����������ͣ���������ָ���λ����
                c = reinterpret_cast<uintptr_t> (p1);//�޸ĺ���ȷ

                //������ָ��ת��Ϊint���͵����� ��һ������ȫ�Ĳ��������ҿ��ܻᵼ�����ݶ�ʧ��
                //��� ��Ҫ��������ʽ��ӡָ��ĵ�ַ������ʹ�ú��ʵ��������ͣ�����uint ptr_t������һ���޷����������ͣ���������ָ���λ����

                p1 = reinterpret_cast<int *>(c);    //
            }

            int main()
            {
                test();
                return 0;
            }

        6.5 �ܽ�
            static_cast һ������ת�����õĻ����������� int char double��
            dynamic_cast һ������ת�� �����̳й�ϵ�� �Զ������������
            const_cast һ������ת�� ��ָ�� �Ӽ� const
            reinterpret_cast һ������תָ�롣
*/
/*
    7�� c++�쳣
        7.1 �쳣��������
            Bjarne stroustrup ˵:�ṩ�쳣�� ����Ŀ�� ����Ϊ�˴�����������⡣����˼����:��һ������ �ڷ����� �Լ��޷�����Ĵ���ʱ �׳�(thr��w)һ���쳣��Ȼ������(ֱ�ӻ��߼��)�������ܹ�����������⡣Ҳ���ǡ�C++ primer����˵��:������������⴦������롣

            һ��˼��:������֧���쳣����ı��������(����java)��Ҫ��ʶ����һ��˼��:���쳣��������У������������ �����׳�һ������ �����⴦����룬ͨ�������������� �� ���ݣ�ʵ����������������ֵ�ͨ�ţ�ͨ�ŵ������ǡ�������ʲô���󡱡���Ȼ���������Զ��쳣�ľ���ʵ�����Ż����ٵ����𣬵������ͨ�ŵ�˼���ǲ���ġ�

            һ�仰:�쳣������Ǵ�������еĴ�����ν������ָ�ڳ������еĹ����з�����һЩ�쳣�¼�(��:��0����������±�Խ�磬��Ҫ��ȡ���ļ�������,��ָ�룬�ڴ治��ȵ�)��

            �ع�һ��:������ǰ��д��������δ����쳣?
            ��C���Ե������У��Դ���Ĵ�������Χ�������ַ���:һ��ʹ�����͵ķ���ֵ��ʶ����;����ʹ��errno��(���Լ򵥵����Ϊһ��ȫ�����ͱ���)ȥ��¼���󡣵�ȻC++����Ȼ�ǿ����������ַ����ġ�
            �����ַ�������ȱ�ݾ��ǻ���ֲ�һ�����⡣������Щ��������1��ʾ�ɹ�������0��ʾ����;����Щ��������0��ʾ�ɹ������ط�0��ʾ����
            ����һ��ȱ����Ǻ����ķ���ֵֻ��һ������ͨ�������ķ���ֵ��ʾ������룬��ô�����Ͳ��ܷ���������ֵ��
            ��Ȼ����Ҳ����ͨ��ָ�����C++�����������������ֵ�������������ܻ�����ĳ�����΢��ɬ�Ѷ���

            c++�쳣�������C�����쳣���������?
                �����ķ���ֵ���Ժ��ԣ����쳣���ɺ��ԡ������������쳣������û�б����񣬳���ͻ���ֹ������ٻ��ʹ����Ա���������ĳ������׳һ�㡣�����ʹ��c���Ե�error����ߺ�������ֵ�������߶��п������Ǽ�飬
            �Ӷ�û�жԴ�����д��������ɳ���Ī���������ֹ����ִ���Ľ����
                ���ͷ���ֵû���κ�������Ϣ�����쳣ȴ����������Ϣ����ʱ����������ܹ����ֳ�����
                ���ͷ���ֵȱ����ص���������Ϣ���쳣��Ϊһ���࣬����ӵ���Լ��ĳ�Ա����Щ��Ա�Ϳ��Դ����㹻����Ϣ��
                �쳣��������ڵ�������������һ�������дʱ������:�������ж�������ĵ���ջ�г�����ĳ������ʹ��
            ���ͷ�����Ҫ������ÿһ�������ж�Ҫ���д�����ʹ���쳣�����ջչ�����ƣ�ֻ��Ҫ��һ�����д���Ϳ���
            �ˣ�����Ҫÿ������������

        �ܽ᣺
            �쳣������󽫳������ⷵ�ظ����ô���
                 c���Ե��쳣����Ƚϼ򵥣����׳���c++�����쳣�����׳���

        7.2 �쳣�﷨
            7.2.1 �쳣�����﷨
            �ܽ᣺
                throw
                try{ }catch(type){}
                ������������

            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //1.�׳�int���͵��쳣

                //int mydive(int a,int b)
                //{
                //    if(b == 0)
                //        throw 1;//�����쳣 �׳��쳣�������׳�һ�����͡�

                //    return a/b;
                //}

                //void test()
                //{
                //    //���Բ����쳣
                //    try
                //    {
                //        mydive(2,0);
                //    }
                //    catch(int)//�������int����
                //    {
                //      cout << "������һ�� int ���͵��쳣" << endl;
                //    }
                //}

                //2.�׳�char���͵��쳣
                //int mydive(int a,int b)
                //{
                //    if(b == 0)
                //        throw 'a';//�����쳣 �׳��쳣�������׳�һ�����͡�

                //    return a/b;
                //}

                //void test()
                //{
                //    //���Բ����쳣 try��catch����ͬʱ���ڣ�������
                //    try
                //    {
                //        mydive(2,0);
                //    }
                //    catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
                //    {
                //      cout << "������һ�� char ���͵��쳣" << endl;
                //    }
                //}

                //int main()
                //{
                //    test();
                //    return 0;
                //}

                //3.�׳��쳣������
                int mydive(int a,int b)
                {
                    if(b == 0)
                        throw 'a';//�����쳣 �׳��쳣�������׳�һ�����͡�

                    return a/b;
                }

                void test()
                {
                    //���Բ����쳣 try��catch����ͬʱ���ڣ�������
                    try
                    {
                        mydive(2,0);
                    }
                    catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
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
                        cout << "������һ�� char ���͵��쳣" << endl;
                    }
                    return 0;
                }

            7.2.2 �쳣�ϸ�����ƥ��
                �쳣���ƺͺ������ƻ������棬���ǲ���ʽ��ͨ���ϸ�����ƥ��
                ����
                    �׳������� �� ƥ������� ���ϸ�ƥ��ģ����׳�������û�б�ƥ�䣬�������ֹ

                ����
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
                            throw str;//�����쳣 �׳��쳣�������׳�һ�����͡�

                        return a/b;
                    }

                    void test()
                    {
                        //���Բ����쳣 try��catch����ͬʱ���ڣ�������
                        try
                        {
                            mydive(2,0);
                        }
                        catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
                        {
                            cout << "������һ�� char ���͵��쳣" << endl;

                        }
                        catch(int)
                        {
                            cout << "������һ�� int ���͵��쳣" << endl;
                        }
                        catch(double)
                        {
                            cout << "������һ�� double ���͵��쳣" << endl;
                        }
                        catch(...)  //�������ƥ�䲻�����ͣ��������ֹ����˿�ʹ��catch(...),��ʾƥ���������͵��쳣
                        {
                            cout << "������һ�� ���� ���͵��쳣" << endl;
                        }
                    }

                    int main()
                    {
                        test();
                        return 0;
                    }

            7.2.3 ջ������unwinding��
                �쳣���׳��󣬴ӽ���try���𣬵��쳣������ǰ�����ڼ���ջ�Ϲ�������ж��󣬶��ᱻ�Զ�������������˳���빹���˳���෴����һ���̳�Ϊջ�Ľ���(unwinding).

                *�����쳣���׳���,��try��ʼһֱ��throw�ڼ䶨������еĶ�����throw֮�󶼻ᱻ�ͷš�
                ����
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
                            cout << "����" << endl;
                        }

                        ~Person()
                        {
                            cout << "����" << endl;
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
                            cout << "002" << endl;  //001 �� 002 ��Ҫ���ڷ��� ������������ʲôʱ����õġ�
                            cout << "������һ�� int ���͵��쳣" << endl;
                        }
                    }
                    int main()
                    {
                        test();
                        return 0;
                    }

            7.2.4 �쳣�ӿ�����
                Ϊ�˼�ǿ����Ŀɶ��ԣ������ں����������г������׳��쳣���������ͣ�����:void func() throw(A,B,C);�������func �ܹ� �� ֻ���׳����� A,B,C���������͵��쳣��
                ����ں���������û�а����쳣�ӿ���������˺����������κ����͵��쳣������:void func()
                һ�������κ������쳣�ĺ���������Ϊ:void func() throw()
                ���һ�������׳��������쳣�ӿ��������������׳����쳣,unexcepted�����ᱻ���ã��ú���Ĭ����Ϊ����terminate �����жϳ���
            ����
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;
                //���׳����������쳣
                void TestFunction1()
                {
                    throw 10;
                }

                //ֻ���׳� int char char* �����쳣
                void TestFunction2() throw(int,char,char*)
                {
                    string exception = "error";
                    throw exception;
                }

                //�����׳��κ������쳣
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
                        cout << "�����쳣" << endl;
                    }
                    system("pause");

                    return EXIT_SUCCESS;
                }
                //�ֱ���QT��VS��Linux�������ԣ�QT �� Linux��ȷ

            7.2.5 �쳣������������
                throw���쳣�������͵ģ����������֣��ַ����������
                throw���쳣�������͵ģ�catch���ϸ�ƥ���쳣����

            �ܽ᣺
                �׳����� ������ ���������׳���
                ����Ҳ����ʹ������������ �������Լ��ٴ��������Լ�ռ䡣

                �׳����������������������catch֮��
                ��������p1���׳�ʱ���׵���һ���������󡣴����Ķ���p1��������������throw֮���������������������catch֮��

            ����
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
                        cout << "���캯��" << endl;
                    }

                    ~Myexecption()
                    {
                        cout << "��������" << endl;
                    }

                    void error()
                    {
                        cout << "my error" <<endl;
                    }

                };

                void fun()
                {
                //    //��һ����������
                //    throw Myexecption();    //�����һ����������������������catch����

                    Myexecption p1;
                    throw p1;


                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(Myexecption &p) //ʹ�����ý�
                    {
                        p.error();
                    }
                }
                int main()
                {
                    test();
                    return 0;
                }

            7.2.6 �쳣�Ķ�̬ʹ��
            ����
                //�쳣�Ķ�̬ʵ�֣�
                #define _CRT_SECURE_NO_WARNINGS
                #include <iostream>
                #include <string.h>
                #include <stdlib.h>
                #include <string>
                using namespace std;

                //���ࣺ
                class Myexception
                {
                public:
                    virtual void error() = 0;
                };

                //����
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
                    catch(Myexception &p) //�ø����ָ�����������
                    {
                        p.error();
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }

        7.3 c++��׼�쳣��
            7.3.1 ��׼�����
                ��׼��Ҳ�ṩ�˺ܶ���쳣�࣬������ͨ���̳���֯�����ġ��쳣��̳в㼶�ṹͼ���£�

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

                ÿ�������ڵ�ͷ�ļ���ͼ�·���ʶ������
                ��׼�쳣��ĳ�Ա:
                1.�������̳���ϵ�У�ÿ���඼���ṩ�˹��캯�������ƹ��캯�����͸�ֵ���������ء�
                2.logicerror �༰�����ࡢruntimeerror �༰�����࣬���ǵĹ��캯���ǽ���һ��string ���͵���ʽ�����������쳣��Ϣ������
                3.���е��쳣�඼��һ�� what()���������� const char*����(C����ַ���)��ֵ�������쳣��Ϣ��

            ��׼�쳣��ľ���������
                �쳣��               ����
                exception           ���б�׼�쳣��ĸ���
                bad_alloc           ��operator new and operator new[],��������ڴ�ʧ��ʱ
                bad_exception       ���Ǹ�������쳣������������쳣�׳��б��������� badexception �쳣���������ڲ��׳�����
                                    ���׳��б���û�е��쳣�����ǵ��õ�unexpected ���������׳��쳣������ʲô���ͣ����ᱻ��
                                    ��Ϊbadexception����
                bad_typeid          ʹ�� typeid ������������һ�� NULL ָ�룬����ָ���Ǵ����麯�����࣬��ʱ�׳� bad_typeid �쳣
                bad_cast            ʹ�� dynamic_cast ת������ʧ�ܵ�ʱ��
                ios_base::failure   io �������̳��ִ���
                logic_error         �߼����󣬿���������ǰ���Ĵ���
                runtime_error       ����ʱ���󣬽�������ʱ�ſ��Լ��Ĵ���


            logic_error ������:

                length_error        ��ͼ����һ��������������󳤶ȵĶ���ʱ������vector��resize ����
                domain_error        ������ֵ�������Ҫ������ѧ�����С�����ʹ��һ����ֵ����ֻ�ܲ����Ǹ����ĺ���
                outofrange          ������Ч��Χ
                invalid_argument    ���������ʡ��ڱ�׼���У������� string ������ bitset ʱ���� string �е��ַ����ǡ�0'��'1'��ʱ���׳����쳣

                ...                  ...

            ����
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
                //    //�׳�Խ��
                //    throw out_of_range("Խ��");

                    //�׳��δ���
                    throw invalid_argument("�δ���");//�׳��δ��󣺶δ��������Ч�ڴ���ʡ�
                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(exception &p) //�ø����ָ�����������
                    {
                        cout << p.what() << endl;   //p.what()��ӡ������Ϣ��
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }

            7.3.2 ��д�Լ����쳣��
                1.��׼���е��쳣�����޵�;
                2.���Լ����쳣���У���������Լ�����Ϣ��(��׼���е��쳣��ֵ��������һ�����������쳣���ַ���)��

                ��α�д�Լ����쳣�ࣿ
                �� �����Լ����쳣��Ҫ�̳б�׼�쳣�ࡣ��Ϊ C++�п����׳��κ����͵��쳣���������ǵ��쳣����Բ��̳��Ա�׼�쳣�������������ܻᵼ�³�����ң������ǵ����Ƕ���Эͬ����ʱ��
                ��)���̳б�׼�쳣��ʱ��Ӧ�����ظ����what������������������
                �� ��Ϊջչ���Ĺ����У�Ҫ�����쳣���ͣ���ôҪ��������������ӵĳ�Ա�����Ƿ��ṩ�Լ��ĸ��ƹ��캯����

            ע�⣺
                string�����棬��һ���ĺ�����.c_str();����������Խ�string��ת��const char*
            ����
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
                    throw Longlongerror("�����Ĵ���");
                }
                void test()
                {
                    try
                    {
                        fun();
                    }
                    catch(exception &p) //�ø����ָ�����������
                    {
                        cout << p.what() << endl;   //p.what()��ӡ������Ϣ��
                    }
                }

                int main()
                {
                    test();
                    return 0;
                }


*/




//�ʼ���
//###################################################################
//������
//################################################################
//��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
//c���ԵĽṹ�岻�ܷź���
struct stu
{
    int a;
    int b[5];
};
//c++�п��Էź���
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
    //ѧ�������� �� ����
    int age;
    int id;
    char name[256];
    //�������ԵĽ��� ���� �� ��Ϊ -- ����
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
// c++ ���������ķ�װ��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//c++ �ж�����ķ�װ�������� �� ��Ϊ ��װ��һ��
//�� �������������Ժ���Ϊ������ ��װ��һ��   ��struct ��Ϊ class
//struct Person
//{
//    //�˵�����
//    int age;
//    char name[128];
//    //�˵���Ϊ
//    void Person_eat()
//    {
//        cout << name<<"�Է�"<<endl;
//    }
//};

//struct �� class ������
// �������еĳ�Ա ����Ȩ�޶���˽�еģ�private����ֻ�����ڷ��ʣ������޷����ʡ�
// ���ṹ�������еĳ�Ա��Ĭ�϶��ǹ��еģ����е����г�ԱĬ����˽�еġ�Ҳ�����޸ĳ�Ա����Ȩ�޵����ԣ�public:
class Person
{

    //�˵�����
public:
    int age;
    char name[128];
    //�˵���Ϊ
    void Person_eat()
    {
        cout << name<<"�Է�"<<endl;
    }
};

struct Dog
{
    //�˵�����
    int age;
    char name[128];
    //�˵���Ϊ
    void Dog_eat()
    {
        cout << name<<"�Է�"<<endl;
    }
};

void test01()
{
    //ͨ���� ʵ������һ����������������ж���
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
//�� ��Ա�� Ȩ�޿���
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
public:     //���еģ����� ���� ���ɷ���
    int tall;//��ߣ�����������֪��
protected:  //�����ģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    �ڼ̳��У�������Է���
    int money;//�ж���Ǯ��ֻ�ܶ���֪��
private:    //˽�еģ����ⲻ�ɷ��ʣ����ڿ��Է��ʡ�    ���಻�ɷ���
    int Age;  //��������֪��
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
//public��private��protected ��ԱȨ�޿���
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
public: //�ṩ�ӿ�
    void set_age(int age1)//���ڳ�Ա������ֱ�ӷ���age
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
private: //����˽�У���������һ�������޸�ֵ�Ľӿ�
    int age;
    char * name;

};

class AccessLevels{
public:
    //��ֻ�����Խ���ֻ���ü�
    int getReadonly(){ return readOnly;}

    //�Զ�д���Խ��ж�д����
    void setReadWrite(int val){readWrite = val;}
    int  getReadWrite() {return readWrite;}

    //��ֻд���Խ���ֻд����
    void setWriteOnly(int val) {writeOnly = val;}
private:
    int readOnly; //����ֻ������
    int noAccess; //�ⲿ���ɷ���
    int readWrite;//��д����
    int writeOnly;//ֻд����
protected:
    ;
};
void test01()
{
    //����Ա���� ����Ϊ���� ��ȱ�ݣ�������ʱ���������Ƶظı��Ա��
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
//4.1.4 ������ϰ
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
//�����尸����
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

    //�����
    int get_cube_V()
    {
        return L*W*H;
    }
    //�����
    int get_cube_S()
    {
        return 2*W*L+2*W*H+2*L*H;
    }
    //�ж������������Ƿ����
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
       cout<< "�������������"<<endl;
   }
   else
   {
        cout<< "���������岻���"<<endl;
   }

   if(compare_cube(c1,c2))
   {
       cout<< "�������������"<<endl;
   }
   else
   {
        cout<< "���������岻���"<<endl;
   }

}


int main()
{
    test01();

    return 0;
}
*/
//#################################################################
//���Բ�࣬�жϾ���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//����
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

//Բ��
class Circle
{
public:
    void setP(int x,int y){
        mP.setX(x);
        mP.setY(y);
        }
    void setR(int r){mR=r;}
    Point& getP(){return mP;}//����Բ�ĵ�ʱ�����ص��Ǳ���
    int getR(){return mR;}//���ذ뾶

    //�жϵ��Բ�Ĺ�ϵ
    void IsPointInCircle(Point& point)//�������
    {
        int distance = ((point.getX()-mP.getX()) * (point.getX()-mP.getX())+(point.getY()- mP.getY())*(point.getY()- mP.getY()));
        int radius =mR*mR;
        if(distance< radius){
            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
        }
        else if(distance > radius){
            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
        }
        else
        {
            cout<< "Point("<< point.getX()<<"��"<< point.getY()<<")��Բ��!"<< endl;
        }
    }
private:
    Point mP; //Բ��
    int mR; //�뾶
};

void test(){
    //ʵ����Բ����
    Circle circle;
    circle.setP(20,20);
    circle.setR(5);
    //ʵ���������
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
//��������������
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Person{
    public:
        int m_age;
        //string �ַ����࣬ͷ�ļ�:  #include <string>
        string m_name;//�ɸ�ֵΪ char* ��ָ�� ���� �ַ�����

        //���캯���������� �� ���� һ�£��޷���ֵ�������в������ɺ������ء�
        Person(int age,string name)
        {
            m_age = age;
            m_name = name;
            cout<<"���캯����"<<endl;
        }

        //���������������� �� ���� ǰ�ӡ� ~ ����û�з���ֵ�������в��������ܷ������ء�
        ~Person()
        {
            cout<<"����������"<<endl;
        }
};

void test()
{
    //���캯������ ʵ��������ʱ�������������ڴ� ���ٿռ� ʱ���á�
    //���캯���Ĵ��� ������ �������Σ���ֱ�ӣ�Person p1(30,"lisa")
    Person p1(30,"lisa");

    //p1��������ʱ�����٣����������� ������ ����ʱ�Զ����á�
}

int main()
{
    test();
    return 0;
}
*/
//##################################################
//���캯���ķ���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //�޲ι���
    Person()
    {
        cout << "�޲ι���!" << endl;
    }

    //�вι���
    Person(int age,string name)
    {
        cout << "�вι���" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
    //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
    Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"��������"<<endl;
    }
};

void test()
{
    //ע�⣺ʹ���޲ι���ʱ�����ܼ����š�
    //�����Ϊ�ṩ���вκ��޲ι��죬ϵͳ�������ṩĬ�ϵ��޲ι���
    //����Ϊû�ṩ���캯������ϵͳĬ������һ�����޲ι��졣
    Person p1;
    Person p2(30,"Lisa");

    Person p3(p2);//����ϵͳĬ���ṩ�Ŀ������죺
    //�����������ʱ�����ɶ����ʼ���¶���

     cout<<p3.m_age<<"  " << p3.m_name <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//###########################################################
//���ù��캯���ķ���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //�޲ι���
    explicit Person()
    {
        cout << "�޲ι���!" << endl;
    }

    //�вι���
    explicit Person(int age,string name)
    {
        cout << "�вι���" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
    //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
    //�ؼ��֣�explicit�����ã��û�����ͨ����ʽ�����ù��캯��
    explicit Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"��������"<<endl;
    }

    ~Person()
    {
        cout << "��������" << endl;
    }
};

void test()
{
    //��������û�����֣������������ڵ�ǰ�С�
    Person(10,"lucy");//�����вι��촴����������
    Person();//������������޲ι�����Ҫ������
    Person p1(10,"lisa");
    //Person(p1);//������������ ����ʹ�� ���ŷ� ���� �������졣
}

//��ʾ�����ù��캯��
void test1()
{
    Person p1 = Person(10,"lucy");//ֻ������ һ�� �вι��� �� һ�� �������������вι��� �� �������� ���õġ�  ��p1 �������ȥ���� �������� ������Ŀռ䡣��û���ٴ���һ���������ÿ������죩
    Person P2 = Person(p1);       //��ʾ�� ���� �������캯��
    Person P3 = Person();         //��ʾ�� ���� �޲ι���
}

//��ʽ�� ���� ���캯��
//���� ���˲���ʹ����ʽ�� ��������Ĺ��캯��������ڹ��캯��ǰ �ӹؼ��֣�explicit���û�����ͨ����ʽ�����ù��캯��
void test2()
{
//    Person p1 = {10,"lucy"};      //��ʽ�� ����    �вι���
//    Person P2 = p1;               //��ʽ�� ����    ��������
//    Person P3;                    //��ʽ�� ���ܵ��� �޲ι���
}
int main()
{
    test1();
    return 0;
}
*/
//#################################################
//�������캯���ĵ���ʱ��: �ɶ��� ��ʼ�� �¶���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person
{
public:
    //�޲ι���
    explicit Person()
    {
        cout << "�޲ι���!" << endl;
    }

    //�вι���
    explicit Person(int age,string name)
    {
        cout << "�вι���" <<endl;
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;

    //��������ֻ�Ǽ򵥵�ֵ�������ҿ��������ǳ�������
    //����Զ�����һ���������죬��ϵͳ�������ṩĬ�ϵĿ������졣
    //�ؼ��֣�explicit�����ã��û�����ͨ����ʽ�����ù��캯��
    Person(const Person &p)//Person p = p2;
    {
        m_age = p.m_age;
        m_name = p.m_name;
        cout<<"��������"<<endl;
    }

    ~Person()
    {
        cout << "��������" << endl;
    }
};

//1.�ɶ����ʼ���¶���
void test1()
{
    Person p(10,"lili");
    Person p1(p);   //���ÿ�������
    Person p2 = Person(p);//��ʾ������ �������캯��
    Person p3 = p;//��ʽ�����ÿ������죬�൱�� Person p2 = Person(p);
}

//2.���ݵĲ�������ͨ���󣬺�������Ҳ����ͨ���󣬴��ݽ�����ÿ������졣
void doBussiness(Person p){}    //Person p = p;

void test2()
{
    Person p(20,"lisa");//�вι����ʼ��
    doBussiness(p); //�������죬�ɶ����ʼ���¶���
}

//3.���� ����ֵ������ֵ�ֲ�����
Person MyBusiness()
{
    Person p(30,"lihua"); //�вι��� ��ʼ���ֲ�����
    cout << "�ֲ�p:"<<(int *)&p <<endl;   //����ֲ�����ĵ�ַ
    return p;   //���ﷵ�ص�ʱ�� Ӧ�õ���һ�ο������죬����һ����������
}

void test3()
{
    // vs release�� qt��û�е��ÿ������캯��
    // vs debug �µ���һ�ο������캯��
    Person p = MyBusiness();//���︳ֵ ҲӦ�õ���һ�ο������졣���ڱ��������Ż���ʹ��ֱ�ӽ�p����������������
    //
    cout << "�ֲ�p:"<< (int*) &p << endl; //����ֲ����󷵻صĵ�ַ�����γ������δ�ӡ�ĵ�ַ�ǲ�ͬ�ģ���Ϊ ��������ʱ �ǵ��� �����������죬���¿��ٵ��ڴ�ռ䣩���ҵ�������ַ��һ���ġ�������Ҳֻ����һ�Σ����������Ρ�
}

int main()
{
    test3();
    return 0;
}

*/
//######################################
//ǳ����
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
        cout << "�вι���"<<endl;
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
        cout << "����"<<endl;
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
    Person p1(p);//����Ĭ�Ͽ������� ���м�ֵ�������ַ���ָ��ָ��ͬһ���ַ��������е�������ʱ��������������������ֱ�freeͬһ��ַ�����³������
}
int main()
{
    test();
    return 0;
}

*/
//#####################################
//���
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
        cout << "�вι���"<<endl;
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
        cout << "����"<<endl;
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
    Person p1(p);//����Ĭ�Ͽ������� ���м�ֵ�������ַ���ָ��ָ��ͬһ���ַ��������е�������ʱ��������������������ֱ�freeͬһ��ַ�����³������
}
int main()
{
    test();
    return 0;
}
*/
//######################################
//��ʼ���б�
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person{
public:
#if 0
    //��ͳ��ʽ��ʼ��:�������� ���� ���������������ʼ����ֵ���൱�������Ƕ��壬�����ǳ�ʼ��
    Person(int a,int b,int c)
    {
        mA = a;
        mB = b;
        mC = c;
    }
#endif
    //��ʼ���б�ʽ��ʼ��:�� ���� �������ٸ��� ������˳�� ���ж����ʼ�����൱����������ֻ��������������ð�ź������ ���� �� ��ʼ����
    //ע�⣺���ﶨ���˳�򣬾���ð�ź����˳�򡣶����˳����Ҫͬ������˳��һ�¡�
    Person(int a,int b, int c):mA(a),mB(b),mC(c){}//�����캯����Ա��ֵ��ʱ�򣬿��԰Ѹ�ֵ�ķ�ʽд�ں����ĺ���

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
//����� ��Ϊ ��Ա
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
        cout << "game �Ĺ��캯��" << endl;
        gam_name = name;
    }
    ~Game()
    {
        cout<< "game ������"<<endl;
    }
    string gam_name;
};
class Phone
{
public:
    //���캯����
    Phone(string name)
    {
        cout << "phone �Ĺ��캯��" << endl;
        pho_name = name;
    }
    ~Phone()
    {
        cout<< "phone ������"<<endl;
    }
    string pho_name;


};
class Person
{
public:
    //������ôд���ȶ����������������������û���޲ι��죬���Զ����������Ҫʹ�� ��ʼ���б������г�ʼ��

//    Person(string per_name1,string pho_name1,string gam_name1)
//    {
//        per_name = per_name1;
//        phone.pho_name = pho_name1;
//        game.gam_name = gam_name1;
//    }

    Person(string per_name1,string pho_name1,string gam_name1):per_name(per_name1),phone(pho_name1),game(gam_name1){
        cout << "person �Ĺ��캯��" << endl;
    }

    void show()
    {
        cout << per_name<<"����" <<phone.pho_name<<"��"<<game.gam_name << endl;
    }

    ~Person()
    {
        cout<< "person ������"<<endl;
    }
    string per_name;
    Phone phone; //һ��������Ϊ��һ������ĳ�Ա��
    Game game;
};

void test()
{
    Person p1("Bob","ŵ����","ԭ��");
    p1.show();
}
int main()
{
    test();
    return 0;
}

//phone �Ĺ��캯��
//game �Ĺ��캯��
//person �Ĺ��캯��
//Bob����ŵ������ԭ��
//person ������
//game ������
//phone ������
*/
//#####################################################
//��̬�������֮malloc��free�Զ��󴴽��ľ�����֤��
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
        cout << "Person ���޲ι���" << endl;
    }
    int a;
    ~Person()
    {
        cout << "Person ����������" << endl;
    }
};

void test()//��������ʱ ������ù������������
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
//��c++�ж�̬���ٶ���new��ʹ��
//delete void *�����ڴ�й¶
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
    Person()//�޲ε���
    {
        cout << "�޲ι���" << endl;
    }
    Person(int a)//�вε���
    {
        age = a;
        cout << "�вι���" << endl;
    }
    int age;
    ~Person()
    {
        cout << "��������" << endl;
    }
};

//newһ����
void test()
{
    int *p = new int;//����һ��sizeof(int)��С�Ķѿռ䡣���Ҷ����ռ���г�ʼ����
    cout << *p << endl;//���Ҷ����ռ���г�ʼ��
    *p = 100;
    cout << *p << endl;
    delete p;//�ͷ�����Ŀռ䡣
}
//newһ������
void test1()
{
    Person * p = new Person;
    delete p;

}
//newһ���вι���� ��������
void test3()
{
    //newʱ �����вι���
    Person * p =new Person(10);
    delete p;
    Person * a =new Person[10];//ע��new����ʱ�����ܵ����вι��죬ֻ�ܵ����޲ι��졣
    delete []a;//
}
//newһ������
void test2()
{
    //newһ������ʱ���ص�������Ԫ�ص�ַ��
    int*p = new int[10];
    for(int i = 0;i<10;i++)
    {
       cout << (p[i] = i+100)<< endl;
    }
    delete []p;//�������дֻ���ͷ��׸�Ԫ�غ���Ԫ�ص�ַ������Ĳ����ͷţ�����ͷ�����ӦдΪ��delete [] p;
}
void test4()
{
    void* p = new Person;
    delete p;   //p������void *���Բ��������������
}
int main()
{
    test3();
    return 0;
}
*/
//#####################################################
//��̬��Ա����
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
    int a;       //�ֲ������������н׶ξ�ȷ�������ڴ�ĵ�ַ��
    //��̬��Ա�������������ڳ�ʼ����ֻ��������������������ȫ�֡�����������ֻ�������˾�̬��Ա�����������򡣲��ң���̬�����Ǵ��ھ�̬ȫ������
    static int b;//��̬��Ա�������ڱ���׶ξͷ�������ڴ档��ʼ�������������ڳ�ʼ�����磺static int b = 10;�ͻᱨ����Ϊ���ڱ���������ȷ�����˵�ַ����ÿ�ζ�������ʱ��ͻ��޸������ǻ�����
};
int b;//����������ȫ�������µı���b������ʾΪPerson���µĳ�Ա
int Person::b = 10; //����Ӧ�ü�һ��Person��������

//��̬��Ա������ʵ����ʹ��
void test()
{
    Person p;
    p.b = 100;
    cout << p.b <<endl;
}
//��̬��Ա������������ʹ�ã�������ͨ��Ա�������жԱ�
void test1()
{
    //����Ҳ�ǿ��Եģ���Ϊ��Ȼû�ж�����󣬵�����b�ڱ���׶ξ��Ѿ�������˿ռ䣬���ҳ�ʼ����ֵΪ10��
    cout << Person::b <<endl;//ͨ�������������������ľ�̬��Ա����
    //cout << Person::a <<endl;// ���󣬲��ܷ���a.����ʵ����һ������Ż���a��
}
//��̬��Ա��������һ��
void test2()
{
    Person p;
    p.b = 100;
    cout << p.b <<endl; //100
    Person k;
    k.b = 200;
    cout << p.b <<endl; //200 ,��˾�̬��Ա��������һ�ݡ�
}

int main()
{
    test2();
    return 0;
}

*/
//#######################################################
//��̬��Ա����
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

    //��̬��Ա���������Է��ʾ�̬��Ա���������ܷ��� �Ǿ�̬��Ա��������ͨ��Ա��������
    //��Ϊ��̬��Ա�����ڱ����ʱ����Ѿ����ˣ���ˣ������������������ã�����Person::static_show()����ʱ���󶼻�û��������û�д���a,��˷��ʲ���a
    static void  static_show()
    {
//        cout << a << " " << b <<endl;//a���ܷ��ʣ�
        cout << "��̬��Ա������" <<endl;
    }

};

int Person::b = 10;

void test()
{
    Person::static_show();//ͨ�������������ʾ�̬��Ա����

    Person p1;
    p1.static_show();//ͨ��������ʾ�̬��Ա����
}

int main()
{
    test();
    return 0;
}
*/
//#########################################################
//const���ξ�̬��Ա���������ھ�̬��Ա�����ǹ���� �� ���Ա��޸ĵġ�  ��ϣ���䲻�ɱ��޸���Ӧ�� const����
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

    //��̬��Ա�������������ڳ�ʼ����ֻ��������������������ȫ�֡�����������ֻ�������˾�̬��Ա�����������򡣲��ң�  ��̬������ ���� ��̬ȫ�������ǿ��Ա��ı�ġ�
    static int b;//��̬��Ա�������ڱ���׶ξͷ�������ڴ档��ʼ�������������ڳ�ʼ�����磺static int b = 10;�ͻᱨ����Ϊ���ڱ���������ȷ�����˵�ַ����ÿ�ζ�������ʱ��ͻ��޸������ǻ�����

    const static int c = 1000;// const ���ε�ȫ�ֱ��������ڳ������� ͬ��const ���εľ�̬��Ա���� �Ǳ����� �����������ɱ��޸ģ�ֻ���ģ������ڴ�Ҳ��ֻ��һ�ݡ�const ���εľ�̬��Ա������һ�������������������渳ֵ�����÷���������ʵ�ֶ��帳ֵ��
    //������������const ���εľ�̬��Ա������ ����ڱ����ʱ��Ҳ������ˣ���̬��Ա��������ֱ�ӷ��ʡ�

    void show()
    {
        cout << a << " " << b <<endl;
    }

    //��̬��Ա���������Է��ʾ�̬��Ա���������ܷ��� �Ǿ�̬��Ա��������ͨ��Ա��������
    //��Ϊ��̬��Ա�����ڱ����ʱ����Ѿ����ˣ���ˣ������������������ã�����Person::static_show()����ʱ���󶼻�û��������û�д���a,��˷��ʲ���a
    static void  static_show()
    {
//        cout << a << " " << b <<endl;//a���ܷ��ʣ�
        cout << "��̬��Ա������" <<endl;
        cout << c << endl;
    }

};

int Person::b = 10;

void test()
{
    cout << Person::c << endl;//����ͨ����������з��ʡ�

    Person p;
    cout << p.c <<endl;// Ҳ����ͨ������һ�����������ʡ�

    p.static_show();//��̬��Ա���� Ҳ����ֱ�ӵ��� const ���εľ�̬��Ա������

}

int main()
{
    test();
    return 0;
}
*/
//###################################################
//����ģʽ��һ����ֻ�ܴ�����һ������
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

    //4.˼����ʽ�������������޷��ٴ������󣬹�������newһ������
    //5.���������� ��Ա��������Ҫ���ж��󣬲Ż��������Ա������
    //6.��ʵ�����������󣬹���Ȼ�ò�����������������Ҫ��������ɾ�̬�ģ���static��������,�����Ϊ��̬��Ա������
    //static Feifei* single;//7.��̬��Ա�������������������ⶨ��

    //11.����һ���ӿ�,��̬�ĳ�Ա����(��ͨ�ĳ�Ա������Ҫ�������)
    static Feifei * instance()
    {
        return single;//��single���أ�����ֻ���������޸ġ�
    }
private:
    static Feifei *single;

    Feifei()//�޲ι���˽�л���
    {

    }
    Feifei(const Feifei&p)
    {

    }
};
//8.���徲̬��Ա��������ɵ�����ʵ�֡�����һ������:���ÿ���������Ȼ����ʵ�ֺ���Ķ�����,�����Ҫ����������Ҳ����˽�л���
Feifei * Feifei::single= new Feifei;//���ⶨ��

void test()
{
    //1.���ȵò���ֻ����һ���������
    //2.���ȵ�һ����һ�����󶼴������˵��࣬�������캯��˽�л��������ڶ���Ĵ�����Ҫ�����޲ι��죬����������ò����޲ι��죬���޷��������󡣣�
//    Feifei p;   //3.�����޲ι�����˽�еģ���˶����ܴ�������
//    Feifei p1;//

    // 2.1ͨ�����������ʵ�ֶ�single�Ĳ�����
//    Feifei::single->age = 30;         //12.���ڽӿں����ĳ��֣��������ô˷���ʹ��single
//    Feifei::single->yanzhi = 100;

     //9.���ÿ������� ʵ������ ��һ������,���,��Ҫ����������Ҳ����˽�л�
    //Feifei p1(*Feifei::single);

    //10.����һ�����⣬����С�Ľ�single �ĵ�ַ��ֵΪ NULL������Ҳ�����ҵ����ַ�����Ҳ��Ҫ������˽�л�
}

void test1()
{
    //13.������ʹ��
    Feifei *p = Feifei::instance();//���Ψһָ��
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
//��ĳ�Աģ�ͳ�̽��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;


//�ɴ�֪��ֻ����ͨ��Ա���� ��������� ���ʵ�������� ��һ���ڴ档�������������ڴ�ʱ������ͨ��Ա�����Ż�ռ�ö���Ŀռ䣩
class Person
{
public:
    int a;//��ͨ��Ա����
    static int b;//��̬��Ա��������������ʵ�����Ķ����У�ֻ�����������С�����ھ�̬ȫ������

    //����������ڴ�������
    void show()//��ͨ��Ա������Ҳ����������ʵ�����Ķ�����
    {
        cout << a << " " << b << endl;
    }
    static void show1()//��̬��Ա������Ҳ����������ʵ�����Ķ�����
    {
        cout << b << endl;
    }

};

int Person::b = 1;
void test()
{

    //1. ����Ĵ�С��1 ����0���е�ַ�����пռ��С��
    //2. �ټ��� ��ͨ��Ա���� a �� Ϊ 4�ֽڡ�
    //3. �ټ��� ��̬��Ա���� b �� Ϊ 4�ֽڣ��ɼ���̬��Ա������������
    //4. �ټ��� ��ͨ��Ա���� ��С��Ϊ4���ɼ���newһ������󣬳�Ա����������ռ������������Ŀռ��С
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
// thisָ��
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

    //���ں��������ڴ�������ֻ��һ�ݣ��������ǵ�������� ��ӡ a��ʱ���ô֪����p����p1��a?
    //��Ϊ����ĳ�Ա�������� ������ Ĭ�ϼ���һ������: Person * const this   ; thisָ�� ָ�� ���øú����Ķ��󣬹ʣ�˭���øú����������ͻ��˭�ĵ�ַ��
    //������ó�Ա�������Ὣ����ĵ�ַ����thisָ�롣
    void show() //Person * const this��������Ĭ�ϼ���������͡�(ָ�볣����this��ָ���ܸı�)
    {
        cout << a << " " << b << endl;          //��������ͱ���� cout << this->a << " "  << this->b << endl;
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

    //show�������ڴ���������һ�ݣ�p1������ú�����ʱ�򣬺�����ô֪���Ǵ�ӡp1����p2��a?
    p1.show();
    p2.show();
}
*/
//########################################################
//thisָ���ʹ��
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
    Person(int age,string name) //��Ϊÿ����Ա����������һ��thisָ�룬ָ����ó�Ա�����Ķ���ĵ�ַ����thisָ��ָ�� p�ĵ�ַ��
    {
//        age = age;     //�������� age �� name����ָ���βΡ�������и�ֵ
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

    Person person_add(Person &p1)// д�������Ϊ��Ա������ʵ�����
    {
        Person p(this->age+p1.age,this->name+p1.name);
        return p;
    }

};

//���ⶨ����Ϊ ȫ�ֺ��� ʵ�����
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

    //ʵ�֣�p3 = p1+p2 30 helloworld

    //����һ��ȫ�ֺ���
    Person p3 = person_add(p1,p2);
    p3.show();

    //����������Ա����
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
//const ���εĳ�Ա����
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

    //Person * const this -----> p1     //���Ӧ��Ϊ ����ָ�볣����const Person * const this������ָ��ָ��ĵĿռ����ݱ㲻���޸�
    //����Person * const this �������ˣ����const ֱ�ӷź��棺Person person_add(Person &p1)const
    //��Ա����������� const���ֺ�������Ϊ ������������ͨ��thisָ���޸���ָ��Ķ������ݡ�
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
//ȫ�ֺ�����Ϊ�����Ԫ
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Building
{
    friend void print_building(Building &p);// ��friend�����ú����Ǹ������Ԫ����ʱ�����Ϳ��Է��ʸ����˽�г�Ա�ˡ�
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
    cout << p.hall <<" " <<p.bedroom <<endl;//b���ʲ���˽�г�Ա����˿���ʹ����Ԫ�������ȫ�ֺ�������Ϊ��������Ԫ���Ϳ��Է���˽�г�Ա��
}

void test()
{
    Building b1("������","�뷿");
    print_building(b1);
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
//һ���� ��Ϊ ��һ�������Ԫ
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Building;//����

//��������
class Goodgay
{
public:
    Goodgay(string hall,string bedroom);//���캯������������������ʵ�֡�

    void visit();//���Է���b�����һ����Ա����

    Building *b;
};

//
class Building
{
    friend class Goodgay;               //һ����          ��Ϊ ��һ�������Ԫ
    friend void Goodgay::visit();       //һ����ĳ�Ա���� ��Ϊ ��һ�������Ԫ
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


//ע�⣺����ʹ�������������Լ�Ϊ�β���д��Building�ඨ���ǰ�棬����Ϊ����������������ʵ�ֵ�ʱ��newһ��Building������new�������ġ���Ϊ���沢û��Building�Ķ��壬ֻ��һ��������
Goodgay::Goodgay(string hall,string bedroom)
{
    //newһ��Building���󣬷ŵ�Goodgay�����Buildingָ���Ա����
    Goodgay::b = new Building(hall,bedroom);
}

void Goodgay::visit()
{
    cout << b->hall << " " << b->bedroom << endl;//b���ܷ������ڵ�˽�г�Ա��
}


void test()
{
    Goodgay gd("������","�뷿");
    gd.visit();
}

int main()
{
    test();
    return 0;
}

*/
//###########################
//4.5 ��ϰ1 ���ӻ���ң����Ԫʵ��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

//����ң������
class Remote;

class Television
{
    friend class Remoter;
public:
    enum    //���ӻ�״̬
    {
        on,
        off
    };
    enum    //������0~100
    {
        MIN_V = 0,
        MAX_V = 100
    };
    enum    //Ƶ����1~255
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
            cout << "status ON, volume " << mVolume << ", channel " << mChannel <<endl;  //�����ʽҲ���������޸�
        }
    }

private:
    int mState;     //����״̬
    int mVolume;     //����
    int mChannel;    //Ƶ
};

//����ң������
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

void test()  //���Ժ������Ը����Լ������޸�
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
//��������
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

    //����������ĳ�Ա����
    Person Person_ADD(Person &p2)
    {
        Person p(this->age+p2.age);
        return p;
    }

    //����������Ա������operator+
    Person operator+ (Person &p2)   //���������ĺ����� ��Ϊ operator+ ���ɡ�
    {
        Person p(this->age+p2.age);
        return p;
    }

    int age;
};

//����һ��ȫ�ֺ���ʵ����Ķ�����ӡ�
Person Person_add(Person &p1,Person&p2)
{
    Person p(p1.age+p2.age);
    return p;
}

//�����ġ�ȫ�ֺ�����operator+
//Person operator+ (Person &p1,Person&p2)
//{
//    Person p(p1.age+p2.age);
//    return p;
//}

void test1()
{
    Person p1(10);
    Person p2(20);
    //Ҫʹ��p3.age = p1.age + p2.age;������ʽ�Ļ�������������ȥ�� ������ �� �������������ع���
    //���������ĵĵ��÷�ʽ��
    //ע�ⶨ����ȫ�ֵĺ��� �Ͳ��� ���г�Ա�������ᱨ��
    Person p5 = p1 + p2;    //�������ô˷����������ڷ������Ļ����� �������� ��Ϊ operator+ ,���иú���������ã����������Ҳ����ú�������ʹ�ô˷�����
    Person p6 = p1.operator+(p2);

    //����һ�ĵ���
    Person p3 = Person_add(p1,p2);

    //�������ĵ���
    Person p4 = p1.Person_ADD(p2);
}
*/
//############################################################
//���ؼӺ������:
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

//ȫ��ʵ��
//Person operator+ (Person &p1,Person &p2)
//{
//    Person p(p1.age+p2.age);
//    return p;
//}

void test1()
{
    Person p1(10);
    Person p2(20);

    //��ȥ�� operator+ �ĺ���,��������ʽ��operator+(p1,p2) �� p1.operator(p2)
    //ȫ�� �� ��Ա���� ����ͬʱ���ڣ���������屨��
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
//���������������Ԫ����,�������������
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

class person
{
    //������Ԫ��ʹ���ܹ�����˽�г�Աage.
    friend ostream& operator<<(ostream &cout, person &p);
public:
    person(int age)
    {
        this->age = age;
    }
private:
    int age;
};

ostream& operator<<(ostream &cout, person &p) //cout�������ǣ�ostream
{
    //ע�⣺���age��˽�еģ���ú����������age�������Ҫ��һ������ ��Ԫ��
    cout << p.age;
    //���ڷ���ֵ��ѡ��void ���� ostream& ?��,ѡ����ߣ���ΪҪ���endl���� <<endl;�ʷ��ز���Ϊ�գ���Ϊ�ղ������endl,������ʹ�� void << endl;
    //��ˣ�����ֵѡ�� ostream ���͵� cout��
    return cout;
}

void test01()
{
    person p1(10);
    cout << p1 <<endl;  //ֱ�����
    // operator<<(cout,p1) //cout.operator<<(p1)��������cout��� �������ز�̫��ʵ�����ѡ��ǰ��ȫ�ֺ������ء�
}
int main()
{
    test01();
    return 0;
}

*/
//############################################################
//�����Լ������
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
        //�Ӽ�
        this->num = this->num + 1;
        return tmp;

    }
    int num;
};
//ǰ��++������ʹ�����ô��Σ�����++����ʹ�����ô���
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
//�ҿ���һ�����ӣ�
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;	//�趨���ƿռ䣬��׼standard

//���ص��������
//�Զ�������
class MyInte
{
    friend ostream& operator<<(ostream& cout, MyInte myint);
public:
    MyInte()
    {
        m_Num = 0;
    }

    //����ǰ��++�����
    MyInte& operator++()
    {
        //�Ƚ���++����
        m_Num++;
        //�ٽ�������з���
        return *this;
    }
    //���غ���++�����
    //void operator++(int)  int ����ռλ��������������ǰ�úͺ���++
    MyInte operator++(int)
    {
        //�� ��¼��ʱ���
        MyInte temp = *this;
        //�� ����
        m_Num++;
        //��� ����¼�������
        return temp;
    }
private:
    int m_Num;
};

//���������<<
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
//����ָ��:ָ���������*��->������
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
        cout << "Smartpoint �ͷ� p" << endl;
    }

    Person *p ;
};

void test()
{
    //��һ�����⣺�ܷ���һ���ֲ��������ͷ�֮ǰ������԰��������ͷ�p ������������ָ��
    //��֪�����ڳ��������ͷŵ�ʱ������������������˿������������������ͷŸÿռ䡣

    Person *p = new Person(10);
    Smartpoint sp(p);

    //�������д���Ҳ����дΪ��
    Smartpoint ssp(new Person(100));

    cout << p->age <<endl;
    cout << sp->age <<endl; //�ڶ������⣬�ܷ�ʹsp ���� p:sp -> p  Person* sp.operator->(){return p;}
    cout << (*sp).age <<endl; //���������⣬�ܷ�ʹ*spָ��age  �� sp.operator*()
    //���������ͷ� pָ����������
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//����=�����
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

        //����д������ name1ָ����ַ������ܱ����ͷ��ˡ�
        name = new char[strlen(name)+1];
        strcpy(name,name1);
    }

//    Person & operator=(Person &p1) //thisָ��ָ��p2
//    {
//        //���˼򵥵�ֵ������
//        this->age = p1.age;
//        this->name = p1.name;

//        return *this; //����ֵ ���ص���p2,ʹ������������ã��磺P3 = p2 = p1;
//    }
    Person & operator=(Person &p1) //��дoperator=����
    {
        //�����
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

    //��ôд��û�е��ù��캯�����ɶ��� ��ֵ �ɶ��󣩡������Person p2 = p1���ǵ��ù��캯�����ɶ��� ��ʼ�� �¶��󣩡�
    p2 = p1;//����֮����û�б�������Ϊ����һ�� operator= ����,�൱�� p2.operator(p1).
    cout << p2.age << " " << p2.name <<endl;
}
int main()
{
    test();
    return 0;
}
*/
//######################################################
// ���� ���� �� �����ڣ�== �� ��=��
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

    bool operator==(Person p2)  //p1����
    {
        return this->age == p2.age && this->name == p2.name;
    }

    bool operator!=(Person p2)  //p1����
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
//�������أ���������
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
    //�� �� ��ͨ��Ա����������ô���ã�ֻ�о�̬�ĳ�Ա�����Ż��к�������ͨ��Ա�������ڶ��󴴽���Ż��С�
    Myadd p;
    cout << p.add(3,4) << endl;

    //p() ��������һ�����ö��󣬳�Ϊ��������
    cout << p(3,4) << endl; //�Ѷ������������á� p.operator() (3,4)

    cout << Myadd()(3,4) <<endl;//Myadd()(3,4)��Myadd(),����+���� ��ʾ ���������ٵ���operator()����

}

int main()
{
    test();
    return 0;
}
*/
//########################################################
//��Ҫ����&& �� ||
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

    //ԭ�������Ӧ�ô����������㣬���Ϊ�٣����˳����㣬���Ϊ��
    //���ȴ�ǣ������㣨complex1+complex2�������£�complex1��flag��Ϊcomplex1+c
    //plex2��ֵ�� complex1.a = 1
    // 1 && 1
    //complex1.operator&&(complex1.operator+=(complex2))
    if (complex1 && (complex1 += complex2)){
         //complex1.operator+=(complex2)
         cout << "��!" << endl;
    }
    else{
        cout << "��!" << endl;
    }
    return EXIT_SUCCESS;
}
*/
//######################################################
//ǿ��ѵ�������ַ������װ
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

    char& operator[] (int index);//[]����

    //=����
    MyString& operator= (const char *str);
    MyString& operator= (const MyString& str);

    //�ַ���ƴ�� +����
    MyString operator+ (const char *str);
    MyString operator+ (const MyString& str);

    //�ַ����Ƚ�
    bool operator== (const char *str);
    bool operator== (const MyString& str);
private:
    char * pString;//ָ������ռ�
    int m_Size;    //�ַ������� ���� ��\0��
};


//MyString.cpp

#include "MyString.h"

//���������
ostream& operator<< (ostream &out,MyString &str)
{
    out << str.pString;
    return out;
}

//���������
istream& operator>> (istream &in,MyString &str)
{
    //�Ƚ�ԭ�е������ͷ�
    if(str.pString != NULL)
    {
        delete[] str.pString;
        str.pString = NULL;
    }

    char buf[1024]; //������ʱ���ַ������飬�����û��������ݡ�
    in >> buf;

    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString,buf);
    str.m_Size = strlen(buf);

    return in;
}

//���캯��
MyString::MyString(const char * str)
{
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString,str);
    this->m_Size = strlen(str);
}

//��������
MyString::MyString(const MyString &str)
{
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString,str.pString);
    this->m_Size = str.m_Size;
}

//��������
MyString::~MyString()
{
    if(this->pString != NULL)
    {
        delete []this->pString;
        this->pString = NULL;
    }
}

char& MyString::operator[] (int index)  //����str[index]�����ã����ڸ������ֵ
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
    char *temp = new char[newsize]; //������newһ��newsize��С�Ŀռ䣬���ص���charָ��ı���
    memset(temp,0,newsize);         //�����洴���Ŀռ��Ӧ������ȫ����ֵΪ0��
    strcat(temp,this->pString);
    strcat(temp,str);

    MyString newstring(temp);       //��������charָ��ı��� ����һ�� ����
    delete []temp;                  //����ʱ�ռ�ɾȥ

    return newstring;               //�����µĶ���
}

MyString MyString::operator+ (const MyString &str)
{
    int newsize = this->m_Size + str.m_Size + 1;
    char *temp = new char[newsize];
    memset(temp,0,newsize);
    strcat(temp,this->pString);
    strcat(temp,str);

    MyString newstring(temp);       //��������charָ��ı��� ����һ�� ����
    delete []temp;                  //����ʱ�ռ�ɾȥ
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

    //cout << "������MyString �����ַ���" << endl;
    //cin >> str;

    //cout << "�ַ���Ϊ��" << str <<endl;

    //����[]
    cout << "MyString �ĵ�һ���ַ�Ϊ��" << str[0] << endl;

    //����=
    MyString str2 = "^_^";
    MyString str3 = "";
    str3 = "aaa";
    str3 = str2;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;

    //����+
    MyString str4 = "�Ұ�";
    MyString str5 = "����";
    MyString str6 = str4 + str5;
    MyString str7 = str6 + "�찲��";

    cout << str7 <<endl;

    //����==
    if(str6 == str7)
    {
        cout << "s6 �� s7���" << endl;
    }
    else
    {
        cout << "s6 �� s7����" << endl;
    }
}
*/
//##############################################################
//�̳У�������Ķ���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//����
class Animal
{
public:
    int age;
    void print()
    {
        cout << age <<endl;
    }
};

//�̳з�ʽ��
//public�����ܸ���ʲôȨ�ޣ������࣬ȫ��ɹ��С�
//private:
class Dog:public Animal
{
public:
    int tail_len;

    //�̳У��൱�ڿ�������
//    int age;
//    void print()
//    {
//        cout << age <<endl;
//    }
};

void test()
{
    Dog d;
    //d��������Ա:
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
//��������ʿ���
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

//���м̳з�ʽ����������ʲôȨ�ޣ��̳е� �����У�Ҳ��ʲôȨ�ޡ�
class A:public Base
{
    //���м̳� ���� ����
public:
    int d;
    void show()
    {
        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
//        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
        //�ɴˣ����಻�ܷ��ʸ����˽�г�Ա��
    }
//    int a;
//protected:
//    int b;
//private:
//    int c;

};


//�����̳У��ѹ��б�ɱ����ģ���������
class B:protected Base
{
public:
    int d;
    void show()
    {
        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
//        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
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
        //����ĳ�Ա���� ���ʸ���ĳ�Ա��Ҫ������̳�֮ǰ��Ȩ��
//        cout << a << b << c << d <<endl;  //��c������˽��Ȩ�ޣ����ܷ���
    }

    //˽�м̳У�������ĳ�ԱȨ�޶����˽�е�
//private:
//    int a;
//private:
//    int b;
//private:
//    int c;
};

void test()
{
    //���в��ԣ�
    A e;
//    A.a;
//    A.d;

    //�������ԣ�
    B f;
//    f.d;

    //˽�в��ԣ�
    C g;
//    g.d


}
int main()
{

    return 0;
}
*/
//########################################################
//�̳��еĶ���ģ��
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
    //�����ڽṹ��
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
//������������ĵ���ԭ��
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

        cout << "Base,����Ĺ��캯��" << endl;
    }

    ~Base()
    {
        cout << "Base �������������" << endl;
    }
    int age;
    string name;
};

//������������ʱ�򣬱����ȹ������������Ҫ�ȵ��ø���Ĺ��캯����
class Son:public Base
{
public:
    //����Ĺ��캯�����вι��죬���������������ڵ�������Ĺ��캯��֮ǰ����Ҫ��ȥ���ø���Ĺ��캯��������Ҫ�Ѳ�������ȥ�����η�ʽ���£�
    Son(int id,int age,string name):Base(age,name)
    {
        this->id = id;
        cout << "Son ���๹�캯��" << endl;
    }
    ~Son()
    {
        cout << "Son �������������" << endl;
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
//�̳���
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
        cout << "�����foo����" << endl;
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
        cout << "�����foo����" << endl;
    }
    int a;
};

void test()
{
    Son p(10,20);
    //�������� �����������ĳ�Ա����������ĳ�Ա�����ᱻ���ء����ʵ�������ĳ�Ա������
    //�������� �����������ĳ�Ա����������ĳ�Ա�����ᱻ���ء����ʵ�������ĳ�Ա������
    cout << p.a <<endl;//20 ,���ʵ���������ĳ�Ա��
    p.foo();
}

int main()
{
    test();
    return 0;
}
*/
//##########################################################
//��̬��Ա �� �̳��е��ص㣺
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
    static int sNum; //���ྲ̬��Ա���Խ�������
#if 0
    //�ض���һ�����������������صĺ���������
    static int getNum(int param1,int param2)
    {
        return sNum + param1 + param2;
    }
#else
    //�ı���ຯ����ĳ������������ֵ���߲����������������ػ������صĺ���
    //������������̬��Ա������������һ����
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
    //��ˣ�������͸�����ͬ���ľ�̬��Ա����������ľ�̬��Ա�����ᱻ���أ����õ�������ľ�̬��Ա������

//    p1.getNum();     //�������������ò��ˣ���ˣ����ܵ��ø�����޲ξ�̬��Ա������
//    p1.getNum(10);   //��һ��������Ҳ���ò��ˣ���ˣ����ܵ��ø���ľ�̬��Ա������
    p1.getNum(10,20);  //�����������Ĳſ��Ե��ã���ˣ�ֻ�ܵ�������ľ�̬��Ա������
//�������͸�����ͬ���ľ�̬��Ա�����������еľ�̬��Ա���� �� �ᱻ���أ�

}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//��̳�
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
//���μ̳� �Լ� ����ڵ����⣺
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
    //ʵ���ϣ����ǽ�ϣ��Shenshouֻ�̳�һ��age,
    //ʵ�ַ�����ʹ����̳йؼ��֣�virtual
//    p.sheep::age = 100;
//    p.cow::age = 200;

    //��̳�
    p.age = 100;

}

int main()
{
    test();
    return 0;
}
*/
//############################################################
//��̳е�ʵ��ԭ��
//������Ҫ֪����ÿ�������ڴ�������δ洢�ģ��Լ����� virtual�ؼ��ֺ���̳е�����������ڴ��д洢�ġ�
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
    //ʵ���ϣ����ǽ�ϣ��Shenshouֻ�̳�һ��age,
    //ʵ�ַ�����ʹ����̳йؼ��֣�virtual
//    p.sheep::age = 100;
//    p.cow::age = 200;

    //��̳�
    p.age = 100;

}

int main()
{
    test();
    return 0;
}

//�ڿ�ʼ�˵���� vs�Ŀ�����Ա������ʾ�� ��д��������:
//���Ҳ������ɴ�vscode,���� ����->������->������������ʾ����д�����´��룺
//ע�⣬����漰�̷����л�����Ҫ�� /d,�磺 cd /d D:\Qtproject\5_2_cplusplus_lei

//cd D:\Qtproject\5_2_cplusplus_lei
//dir
//cl /d1 reportSingleClassLayoutAnimal main.cpp    //����ָ���ʾ��report Single Class Layout Animal,���浥����Ĳ���+Animal  ��main.cpp�ļ����У�ע�⣬Ҫ����֮�󣬲Ż�����Animal�Ĳ��֡�

//������Ĳ��֣�
//class Animal    size(4):
//        +---
// 0      | age
//        +---

//������Animalֻ��4���ֽ� int���͵� age

//����Ĳ��֣�
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

//���ڼ̳�����̳У�������������������̳е�age��һ��id,���⣬���滹��һ��vbptr(virtual base ptr �����ptrָ�룬ָ��ռ4���ֽڣ������ָ�� ��ָ��һ�ű�������vbtable����,�����ָ�뿪ʼ�ǲ��ᱻ��ʼ���ģ��������ǵ��������Ĺ��캯����ʱ�����ᴴ��һ�ű����Ұѱ�ĵ�ַ����vbptrָ��)��
//�ɣ�Sheep::$vbtable@:����֪��������������Ա��һ����0��һ����8������8��ָage��ƫ������Ҳ����˵��������̳е�ʱ��a��Ȼ�̳й����ˣ�����ȥ����age��ʱ�򲢲���ֱ�ӵõ�age������ͨ��ָ��õ�age��ƫ������Ȼ���ٷ��ʵ�age��

//Ҳ����˵�������� sheep p;
//��ȥ����(p.age)ʱ�������������������: *��int *��((char*)&p+ *((int *)(*��int *��&p) + 1)) //*(int*)(p�ĵ�ַ+ƫ����8)

//��������Ϊ������Ҫ�ҵ�vbptrָ�룬����������p�ĵ�ַ(32λ������)ת��(int*)��ȡ*��*��int*��&p   => �������vbptr���ֵ��ע�ⲻ��ָ�룬��ָ��������
//���Ƕ����ֵ�ĵ�ַת��int *,�ټ�1������ԭ����ָ��0�����ָ��8���ٽ����8ȡ������������*��,���˵õ�ƫ����8: *((int *)((int *)&p) + 1��
//Ϊ�˵õ�age�ĵ�ַ����Ҫ��p�ĵ�ַ�ϼ���ƫ������ ((char*)&p + *((int *)(*��int *��&p) + 1))
//�Եõ��ĵ�ַת��(int *),�ٽ�����,�õ�age��ֵ�� *��int *��((char*)&p + *((int *)(*��int *��&p) + 1))


//ţ��Ĳ��֣�
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


//���޵Ĳ��֣�
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

//**����������4����Ա���̳���sheep���������id���̳���cow���������num���Լ���a �� ֻ�̳���һ�ݵ�age��
//������,��sheep���������age��ƫ������20����cow���������age��ƫ������12��**



//**vs�Ŀ�����Ա������ʾ���������ݣ�**

//D:\Qtproject\5_2_cplusplus_lei>dir
// ������ D �еľ��� Data
// ������к��� 4D3B-BBAE

// D:\Qtproject\5_2_cplusplus_lei ��Ŀ¼

//2024/12/20  22:52    <DIR>          .
//2024/12/18  11:55    <DIR>          ..
//2024/12/07  00:18               133 5_2_cplusplus_lei.pro
//2024/12/20  01:28            19,159 5_2_cplusplus_lei.pro.user
//2024/12/07  00:32               732 c_person.c
//2024/12/20  22:52           197,990 main.cpp
//2024/12/20  22:52            76,800 main.exe
//2024/12/20  22:52             2,146 main.obj
//               6 ���ļ�        296,960 �ֽ�
//               2 ��Ŀ¼ 199,913,979,904 �����ֽ�

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//��̬��ʵ��
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
//        cout << "������˵����" << endl;
//    }

    //6.��������������֣��������������֣�����virtual�ؼ��ֵ��麯����
    //7.���ȣ����麯������Σ�Dog�ּ̳���������࣬���ң�����������д������麯����  ����д����������ֵ ������ ����ֵ һ�£��ͽ���д��

    virtual void speak()
    {
        cout << "������˵����" << endl;
    }

};

//2.�� ��������෢���˼̳У���������࣬�����Զ�ת����
//3.��ʱ ������do_work()������p2��speak
class Dog:public Animal
{
public:
    void speak()
    {
        cout << "����˵����" << endl;
    }

};

//1.����û�м̳еķ�ʽ��������do_work()������p2��speak������
//class Dog
//{
//public:
//    void speak()
//    {
//        cout << "����˵����" << endl;
//    }

//};

//11.����һ��cat�࣬���̳�Animal.
class Cat:public Animal
{
public:
    void speak()
    {
        cout << "è��˵��" << endl;
    }

};

//8.����ø����ָ�� ָ�� ����Ķ������ʱ�򣬴�ӡ�ľ��� "����˵��"
void do_work(Animal &obj)
{
    obj.speak();  //5.������ǵ�ַ��󶨣�//9.�ڼ̳����麯��֮�󣬾��ǵ�ַ��󶨡�
    //10.������ַ��� -> �ڻ���ĺ���ǰ�����virtual�ؼ��� -> ��ַ��󶨡�
}

//12.����������У�test�������ǽӿڣ�һ���ӿڣ�����ʵ�ֶ�����̬��
void test()
{
    Animal p1;
    do_work(p1);

    Dog p2;
    //4.��ע�⣬�����ӡ�Ļ���"������˵��",��Ϊ�����ַ ����ˡ��ڱ����������ʱ�ھ��Ѿ����ˡ�
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
//��̬ʵ�ּ������İ���
/*
//û�ж�̬��ʵ�ַ�����
//�������ǣ����������һ���˷�������Ҫ��д��д����ĺ����塣
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <string>
//using namespace std;

//����ʱ����Դ��Ŀ����ǹرյģ�����չ�ǿ��ŵġ�

//class Myclc
//{
//public:
//    int calc(int a,int b,string cmd)
//    {
//        if(cmd == "+")  //string ��������������һ��operator== ���������Կ���ֱ�ӱȽ�
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
//#endif  //�������ǣ����������һ���˷�������Ҫ��д��д����ĺ����塣
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



//�ж�̬���ʵ�ַ�����

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
//c++���ʵ�ֶ�̬�󶨣�
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
        cout << "������˵����" << endl;
    }

};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "����˵����" << endl;
    }

};

class Cat:public Animal
{
public:
    void speak()
    {
        cout << "è��˵��" << endl;
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

//�����ٴ�ʹ�õ�vscode,��ϸ���������ǰ�� ��̳е�ʵ��ԭ��.

//D:\c++����\angle\Myadd_self>cd D:\Qtproject\5_2_cplusplus_lei

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutAnimal main.cpp
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
//main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutDog main.cpp
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
//main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>cl /d1 reportSingleClassLayoutCat main.cpp
//���� x86 �� Microsoft (R) C/C++ �Ż������� 19.33.31630 ��
//��Ȩ����(C) Microsoft Corporation����������Ȩ����

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
//C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.33.31629\include\ostream(774): warning C4530:  ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ�� /EHsc
//main.cpp(7609): note: �鿴�����ڱ���ĺ��� ģ�� ʵ������std::basic_ostream<char,std::char_traits<char>> &std::operator <<<std::char_traits<char>>(std::basic_ostream<char,std::char_traits<char>> &,const char *)��������
//Microsoft (R) Incremental Linker Version 14.33.31630.0
//Copyright (C) Microsoft Corporation.  All rights reserved.

///out:main.exe
//main.obj

//D:\Qtproject\5_2_cplusplus_lei>


//������

//1.������һ��Dog��Ķ����ʱ�򣬻��ȹ��츸��Ķ��󣬼����ȹ���Animal�Ķ������ڱ����У�Animalû�г�Ա������ֻ���麯�������Զ���vfptr(�麯��ָ��)����ָ��ָ���麯����vftable��������������Ķ����ʱ����Ϊ����ù��캯�����ڵ��ù��캯��ʱ���� ���麯���ĺ�����ڵ�ַ �ŵ��麯����vftable��
//2.��ˣ���ʱ����麯�� ��ָ�� �������� speak������
//Animal �Ĳ��֣�
//class Animal    size(4):
//        +---
// 0      | {vfptr}
//        +---

//Animal::$vftable@:
//        | &Animal_meta
//        |  0
// 0      | &Animal::speak


//3.Ȼ��ʼ�������ࡣ���ڹ��������ʱ�� �̳��� �麯��ָ�루vfptr���Լ��麯����vftable��,��ʱ����������Ĺ��캯��ʱ������Ĺ��캯������ ��ȥ����1.����д�麯����2.�������������dog speak�����ĺ���ָ��Ž��̳е� ������vftable)���棬������vfptrָ���ֵ�滻��
//4.��ˣ���дʵ���Ͼ����滻�� vftable����ĺ����ĵ�ַ��
//5.��ʱ��ȥ�� p.sprak��ʱ��������ʵ�ʵ��õ���vfptrָ������vftable����ĺ��������ú����� ��������Ĺ��캯����ʱ����Ѿ������ˡ�

//Dog �Ĳ��֣�
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



//cat �Ĳ��֣�
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
//���麯�� �� ������
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
    //1.��֮ǰ�ļ�������Ļ����ϣ��ں���� = 0��ʹ���� ���麯���� �麯�� = 0 ��
    //2.���麯�����ã� ��֪�ڹ��츸���ʱ��vfptrָ����vftable,��vftable�������һ�� ����ĺ����ĵ�ַ�������д�ɴ��麯���Ļ�����������������ַ��ֵΪNULL��
    //3.virtual int Mycalc(int a,int b) = 0;��仰��ֵΪ0������vfptr�麯��ָ�� ָ��� �麯���� ����� ������ڵ�ַ ��ֵΪNULL��֮��������ȥ��дʱ������Ǹ��麯��������ĺ�����д���ġ�

    //4.�� ���д��麯������ ���� ������,�����಻��ʵ��������
    //5.������� �̳��� �����࣬�� ���� Ҳ�� ������
    //6.����� �̳��� ������ �� ���� ��д���麯�����Ͳ����ǳ����ࡣ
    virtual int Mycalc(int a,int b) = 0;

//    {
//        return 0;
//    }

};
class Mod:public Calc
{
//    Calc a;//���������಻��ʵ����
//    Mod a;//�̳��˳����������Ҳ�ǳ����࣬����ʵ������

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
//����������
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
        cout << "������˵��" << endl;
    }

    virtual ~Animal()
    {
        cout << "���� ����" << endl;
    }
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "����˵��" << endl;
    }
    ~Dog()
    {
        cout << "�� ����" << endl;
    }
};

void dp_work(Animal &obj)
{
    obj.speak();
}

void test()
{
    Animal *p = new Dog;

    p->speak(); //1.��Ϊ���õ���dog�Ķ������� ��ӡ ����˵��
    delete p;   //2.��Ϊ�Ǹ����ָ��      ���� ���� �Ƕ��������������ͷŵ��ǻ���,����Ķ���û�б��ͷš�
    //3.��֮ǰ�������������ʱ���ȴ����࣬�ٴ����ࡣ�����ǣ����������࣬���������ࣻ����������ָ����Animalָ�룬�������ͷŵ��Ǹ��ࡣ
    //4.��ô���ܲ����������ͷŸ���֮ǰ�����ͷ����ࣿ => ֻ��Ҫ�ڸ������������ǰ��ӹؼ���virtual ,�������������
    //�����������ã��ڵ��ø������������֮ǰ�����ȵ������������������
}

int main()
{
    test();
    return 0;
}
*/
//#############################################################
//������������
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
        cout << "������˵��" << endl;
    }

//    virtual ~Animal()   //������
//    {
//        cout << "���� ����" << endl;
//    }

    //���������������ǣ�û��ʵ�ֵĺ����塣
    virtual ~Animal() = 0;
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "����˵��" << endl;
    }
    ~Dog()
    {
        cout << "�� ����" << endl;
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
//��д ���� �ض���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

#if 0
//����int������
void swap(int & x,int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
//����char������
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

//����ģ����ʵ��
template<class T> //����һ��ͨ��ģ�壬ģ���ͨ������ΪT�� class �� typename����һ���ģ����ĸ������ԡ�
//������������Ķ���
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
    swap_temp(a,b);//�Զ������Ƶ���
//    swap_temp(a,c);//�Ƶ����Ͳ�һ�»����
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
//��ģ��ʵ����������
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//����ģ�� ��������
template<class T>
void array_sort(T *p,int n)//��������Ԫ�ص�ַ���������
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
//    array_sort(a,sizeof(a)/sizeof(a[0]));        //�Զ������Ƶ�
    array_sort<double>(a,sizeof(a)/sizeof(a[0]));  //��ʾָ������
    print_array(a,sizeof(a)/sizeof(a[0]));
}
int main()
{
    test1();
    return 0;
}

*/
//###########################################################
//����ģ�� �� ��ͨ��������
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//��ͨ����
int My_Add(int a,int b)
{
    cout<<"��ͨ����" <<endl;
    return a + b;
}

//ģ��
template <class T>
T My_Add(T a,T b)
{
    cout<<"ģ�庯��" <<endl;
    return a + b;
}

void test()
{

}


int main()
{

    int a = 10;
    char b = 20;
    My_Add(a,a);     //ֱ�ӵ�����ͨ�����������Ƶ��������������ģ�庯������� <>,
    My_Add<int>(a,a);//��ʾָ������
    My_Add<>(a,a);   //ָ���Զ��Ƶ�
    My_Add(b,b);     //��ͨ�������Ͳ�ƥ�䣬�Զ�����ģ�庯��

    My_Add(a,b);     //�������Ͳ���ͬ�ģ����õ�����ͨ����������ʵ���Զ�����ת����charתΪint���������ģ����ᱨ��
//    My_Add<>(a,b);     //�����ģ����ᱨ��,��Ϊ�Զ��Ƶ������������Ͳ�һ�£�����ģ�岻�����Զ�����ת����
    return 0;
}
*/
//###################################################################
//����ģ�� �� ��ͨ������һ����ù���
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//����ģ��
template<class T>
T Myplus(T a,T b)
{
    cout << "����ģ��" << endl;
    return a + b;
}

//��ͨ����
int Myplus(int a,int b)
{
    cout << "��ͨ����" << endl;
    return a + b;
}

//���غ���ģ��
template <class T>
T Myplus(T a, T b,T c)
{
    cout << "ģ�庯��" << endl;
    return a + b + c;
}

void test()
{
    int a = 10;
    int b = 20;
    char c = 'a';
    char d = 'b';
    //�������ģ�����ͨ��������ƥ�䣬c++���������ȿ�����ͨ����
    cout << Myplus(a,b) << endl;
    //���Ҫ��������ģ�壬���<>
    cout << Myplus<>(a,b) << endl;
    //��ʱ��ͨ����Ҳ����ƥ�䣬��Ϊ��ͨ���������Զ�����ת��
    //���Ǵ�ʱ����ģ���ܹ��и��õ�ƥ��
    //�������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��(�������Ͷ���char������ǵ�����ͨ��������Ҫת�������ͣ����ƥ��ģ�����)
    cout << Myplus(c,d) << endl;

}
int main()
{
    test();
    return 0;
}
*/
//#####################################################
//����ģ�屾�ʣ��� ����ģ�� �� ��ͨ�������� �Ĵ���Ϊ��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//��ͨ����
int My_Add(int a,int b)
{
    cout<<"��ͨ����" <<endl;
    return a + b;
}

//ģ��
template <class T>
T My_Add(T a,T b)
{
    cout<<"ģ�庯��" <<endl;
    return a + b;
}
//1.��һ�α��룬�Ժ���ģ���﷨���б��루���������������ߣ��ߵ�����ʱ�����﷨���б��룩
//3.չ����Ĵ������£�ע�⣬չ����Ҳû��template <class T>�ˡ�
//int My_Add(int a,int b)
//{
//    cout<<"ģ�庯��" <<endl;
//    return a + b;
//}
//4.�����һ��char���ʹ�ĵ��ã���չ��Ϊ��չ��֮��ҲҪ���еڶ��α��룬
//char My_Add(char a,char b)
//{
//    cout<<"ģ�庯��" <<endl;
//    return a + b;
//}
//5.������������֪������ģ�� �ı��ʾ��Ǻ������ء������˶��α��롣

void test()
{
    int a = 10;
    char b = 20;
    My_Add(a,a);        //2.����a��int���ͣ��ڵ��õ�ʱ����������ģ�����չ������Ϊ�������Ƶ���a��int���ͣ���չ��ʱ����int�滻T����
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
//ģ��ľ����ԣ�
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//1.��һ�ַ����������Զ������͵��������ͣ������������ṹ���ǲ��еģ�����������Զ����������ͣ��Ϳ���ȥ�޸�����࣬�޸������operator���غ������Ӷ�ʵ�����蹦�ܣ�
//2.��T��Person,������name��age�����бȽϺ͸�ֵ��
//3.���ڸ��Զ�����������ͣ���ô���ǵ���operator=���������߱Ƚ�>�ţ���ȥ���������ȥ��дһ��operator>��������������غ��� �������ء�
//4.��ʱ����Ҫ�Լ�����ʵ�ֺ����塣
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

//��ͨ��������
//5.���������������������������Person���ͣ������ǽ������˵ģ�
//6.����дoperator���غ����⣬�����԰Ѻ������廯��
template<class T>
void mySwap(T &a,T &b)
{
    T tmp = a;
    a = b;//������õ���operator=������
    b = tmp;
}


//���������廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
//7.�����������֣����Ǿ��廯��ǰ���template<> Ȼ�������T�������Զ����������͡�
//8.���������廯�����ã���Ϊ���鷳��Ҫע��ĵط��ܶ࣬����ȥдһ��ȫ�ֺ������и�ֵ������дһ�����ڵĺ������и�ֵ��
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
//��ģ��
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

//ͨ����ģ�壺
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
    Animal<int,int> dog2(10,10);  //ע��:��ģ�岻���Զ������Ƶ������Ҫ��ʾָ�����͡������ҵ�QT���Խ����Զ�������ת������û�����ʾָ����
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
//��ģ����Ϊ��������
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//ͨ����ģ�壺
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

//1.��Ϊ�βΣ�����Ϊ����ģ�����͡�����ΪAnimal<int,int>
//2.�������ǣ��βε�����Ϊ<int,int>,�ʲ��ܴ�cat��<int,string>���͡�
//3.��ˣ����������β���Ϊ��ģ���ʱ�򣬾���������д�ɺ���ģ�����ʽ��
//д��һ��
//template<class T1,class T2>
//void show(Animal<T1,T2> &p)
//{
//    cout << p.age <<" "<<p.data <<endl;
//}
//д������
template<class T1>
void show(T1 &p)    //��Animal<int,int> dog2(10,10);����Ϊ�����൱�ڰ�����<int,int>���ͣ�������T1������
{
    cout << p.age <<" "<<p.data <<endl;
}

void test()
{
    Animal dog(10,10);
    Animal<int,int> dog2(10,10);  //ע��:��ģ�岻���Զ������Ƶ������Ҫ��ʾָ�����͡������ҵ�QT���Խ����Զ�������ת������û�����ʾָ����
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
//����̳�����ģ��ʱ��������ôд��
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

//д��һ��
//2.������������Tд��Ϊint�����ˡ�
class Son:public Base<int>
{
public:
    //1.�ó�ʼ���б��칹�캯�������ȹ������Base<int>,����a����ȥ����x��ֵΪx1
    Son(int x1, int a):Base<int>(a),x(x1){}
    int x;
};

//д������
template<class T1,class T2>
class Son2:public Base<T2>
{
public:
    Son2(T1 x1,T2 a):Base<T2>(a),x(x1){}

    T1 x;
};

void test()
{
    //3.�������ֻ��д<int,int>����.
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
//��ģ���Ա����������ʵ��
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
    //��Ա��������ʵ�֣�
    Person(NameType name,AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name��" << this->mName << "age: " << this->mAge << endl;
    }
    NameType mName;
    AgeType mAge;
};
void test()
{
    //Person P1("��������"��18);//��ģ�岻�ܽ��������Զ��Ƶ�
    Person<string,int>p1("��������",18);
    p1.showPerson();
}
int main()
{
    test();
    return 0;
}
*/
//#########################################################
//��ģ���Ա����������ʵ��
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
    //��Ա��������ʵ�֣�
    Person(T1 a,T2 b);
    void showPerson();

    T1 a;
    T2 b;
};
//1.��ģ��ĳ�Ա����������ʵ�֣���Ҫд�ɺ���ģ����ʽ��
//2.������Person��ģ���࣬�ʣ�����дΪ��Person::Person(T1 a,T2 b),����д�ɣ�Person<T1,T2>::Person(T1 a,T2 b)
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
//��ģ��ĳ�Ա��������ʱ����
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

//һ������ʵ�֣�
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

//    T obj;//����һ��T���͵�obj����/���󣬿��Դ�A/B����
//};

//�����൱������ֻ����������ʱҲ�ܳɹ���
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

    T obj;//����һ��T���͵�obj����/���󣬿��Դ�A/B����
};


void test()
{
    //1.����Pʱ����������:ҪôAҪôB����ô��C�����棬����������Ӧ����ͬʱ���ڣ���Ϊ��ʱfoo2Ӧ�ûᱨ���Ƿ����ʣ�A���͵���B�ĳ�Ա������������ʵȴ�Ǳ���ʱ��û�б���
    //2.��һ������ʵ�֣��Ͷ����������� �Լ� ��ֻ�Ƕ���p,û�е��ó�Ա�����������û�б����֪��������������û�ж��塣
    //3.������p���ҵ��ó�Ա������ʱ�򣬾ͻᱨ��foo�Ķ���û�ҵ�����
    //4.˵����ģ��ĳ�Ա�����Ĵ���ʱ�����ڵ��õ�ʱ��ֻҪû�е��ã����������ǲ��ᴴ���ġ�

    //5.Ҳ����˵����ģ��ĳ�Ա�����Ĵ���ʱ�����ڵ���ʱ�������������������ĺ�������ô�Ͳ��ᴴ���ģ�ֻ�к�����������
    C<A> p;

    p.foo1();//����foo1
}

int main()
{
    test();
    return 0;
}
*/
//��ģ��ķ��ļ�����:
/*
//Person.h�ļ�
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
//��Person����ĺ��������ⲿ���塣
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
//3.�������ͷ�ļ����൱�ڰ�.h�ù�����
//4.������ÿ��.cpp���ǵ��������


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
    //1.��ʱ���룬�ᱨ���޷��������ⲿ����Person<int,int>,Ҳ����˵û���ҵ������Ķ��塣
    //2.�޷��ҵ�����Ϊ����ģ��ĳ�Ա�������ڵ��õ�ʱ��Ŵ�����
    Person<int,int> p(10,20);
    p.show();//5.�����������뵽����ʱ��������Ҫ����p�Ĺ��캯���͵������show����,���õ�ʱ�����Ҫ�����������
             //6.���ǣ����������봴��������������ʱ����������������û���ڵ�ǰ.cpp���棨main.cpp��������������.cpp���棨Person.cpp������ʱ��������Ҫ���������������ͻ��Ҳ�����
    //7.�������ù��캯����show������Ҫ��������������������û�������������Ķ��壬���ܱ�������

    //8.����İ취���ǣ���������Ķ�����Ҫ�ŵ�Person.h���У����ܷ���.cpp���档
    //9.��ģ��ķ��ļ����⣺����Ѻ����Ķ�����������д��һ���ļ�����ȥ������ݵķ����ǣ���ģ��ĳ�Ա��������ֱ��ʹ���ڲ����壬��������ʵ�ֶ��塣
    return 0;
}

*/
//��ģ��������Ԫ:
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;


//��ģ���������Ҫ�������ж��õ�ǰ������
template<class T1,class T2>
class Person;

//5.showPerson1��ȫ��ģ�庯��������
template<class T1,class T2>
void showPerson1(Person<T1,T2> &p);

//1.��ģ����Ϊ�����β� ������Ҫд�ɺ���ģ��
//����һ��ȫ��ģ�庯��д�� ������档
template<class T1,class T2>
void showPerson(Person<T1,T2> &p)
{
    cout << p.a << " " << p.b <<endl;
}

template<class T1,class T2>
class Person
{
    friend void showPerson1<>(Person<T1,T2> &p);    //4.��������Ϊ��Ԫ��ʱ��������ǰ���Ҳ�����������˻ᱨ����Ҫ����ǰ�����3.��������
    friend void showPerson<>(Person<T1,T2> &p);//2.��ֻ��������ͨ�ĺ���Ϊ������Ԫ��
    //��������������ֱ��д��������档
    //ע�⣺���ַ���д�ĺ�����������ĳ�Ա������ʵ�ʻ���ȫ�ֺ�������Ϊǰ�����һ��friend��������һ��ȫ�ֺ�����������Ϊ�����Ԫ��
    friend void showPerson2(Person<T1,T2> &p)//������ֱ�Ӷ��壬�������������Բ���Ҫ��ǰ��һ���ں����������һ��<>��
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

//3.��ȫ��ģ�庯�� ������
//��������ȫ��ģ�庯��д��������棬����Ҫ������
template<class T1,class T2>
void showPerson1(Person<T1,T2> &p)
{
    cout << p.a << " " << p.b <<endl;
}

void test()
{
    Person<int,string> p(10,"lucy");
    showPerson(p);  //p����ģ�壬Person<int,string>������͵ģ��ຯ�����β�
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
//��ģ���Ӧ�ã�ʵ�ֶ�̬����Ĺ���
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
    //�вι��죬explicit����ȷ��explicit�ؼ����������� ��Ĺ��캯���������εĹ��캯�����࣬���ܷ�����Ӧ����ʽ����ת����ֻ������ʽ�ķ�ʽ��������ת����
    explicit MyArray(int capacity)  //���캯�� �����������������Ĵ�С����������ʱ���û�ָ������Ĵ�С
    {
        this->m_Capacity = capacity;    //������С���ݵ���ĳ�Ա���б���
        this->m_Size = 0;               //Ԫ�ظ�����ʼ��Ϊ0��

        //���T�Ƕ�����ô�����������ṩĬ�ϵĹ��캯��
        pAddress = new T[this->m_Capacity]; //newһ��������С������ռ�
    }

    //�������죺�������и�ֵ��ʱ�������������new�ռ䣬���ܼ򵥵Ľ���ֵ����������ַ����������Ҫ��д�������졣
    MyArray(const MyArray &arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[this->m_Capacity];
        //ע�⣺���ﲻ��ʹ��memcpy����ΪmemcpyҲ�Ǽ򵥵�ֵ����������������Ƕ���Ŀ�����������Ҫһ��һ�����и�ֵ
        for(int i = 0;i < this->m_Size;i++)
        {
            this -> pAddress[i] = arr.pAddress[i];
        }
    }

    //����[] ������ arr[0]
    //����[]��Ӧ��Ԫ�ء����������á�  MyArray a(10); a[9]��
    T& operator[] (int index)
    {
        return this->pAddress[index];
    }

    //β�巨�����������ݵ����� ���ݵ�ֵ
    void Push_back(const T &val)
    {
        //�ж������Ƿ����ˣ����˾�����
        if(this->m_Capacity == this->m_Size)
        {
            return ;
        }
        //û���Ͱ�valֵ��ֵ�����
        this -> pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //βɾ��
    void Pop_back()
    {
        if(this->m_Size == 0)
        {
            return ;
        }
        this->m_Size--;
    }

    //���size.
    int getSize()
    {
        return this->m_Size;
    }

    //��������:����ָ��ָ��NULL�������ʹ�СΪ0
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
    T * pAddress;   //ָ��һ���ѿռ䣬����ռ�洢���������ݣ�ָ���������Ԫ�ص�ַ��
    int m_Capacity; //���������
    int m_Size;     //Ԫ�صĸ���
};
*/
//########################################################
//��̬ת��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void test()
{
    //static_cast ����ת�������������� �� c���Ե�ǿ������ת�����ơ�
    int a = 1;
    char b = 2;
    double c = 3.14;
    a = static_cast<int> (b);      //�����������ת��Ӧ���ǣ� a = static_case<int> (b);    //������Ϊ����һ��ģ�壺<>
    a = static_cast<int> (c);
    c = static_cast<double> (a);
}

class A
{
public:
    int a;
};

//1.�ڲ��̳еĻ�����
//class B
//{
//public:
//    int b;
//};

//4.�����̳й�ϵ
class B:public A
{
public:
    int b;
};

void test1()
{
    A *p1 = new A;
    B *p2 = new B;
//    p1 = p2;                    //2.����,
//    p1 = static_cast<A*> (p2);   //3.Ҳ�ᱨ����Ϊ����static_cast����ת��û�з����̳й�ϵ֮����ࡣ
    //5.���������֮�䷢���˼̳й�ϵ�����Խ�������ת����
    p1 = static_cast<A*> (p2);

    //6.��ʱ���⣺�Ƿ�ȫ�� ���B�Ŀռ��A�ռ�С��BתA�Ƿ�ȫ��=>��ȫ����ΪA�ܷ��ʵĿռ�Ƚ�С��B�Ķ���ת��A�Ķ���ʹ���ܷ��ʵĿռ��С�ˡ�
    //7.��AתB�ǲ���ȫ�ģ���ΪAת��B֮���ܷ��ʵĿռ������Խ������ˡ�
    p2 = static_cast<B*> (p1);

    //8.��� �ӣ���ռ䣩ת����С�ռ䣩�� ����ת���ǰ�ȫ�ġ�
    //9.    ����С�ռ䣩ת�ӣ���ռ䣩�� ����ת���ǲ���ȫ�ġ�
    //10.��ע�⣺static_cast<>��������ת����ʱ���ǲ��ᱣ֤ת���İ�ȫ�Եġ�

}

void test2()
{
    int * p1 = NULL;
    char *p2 = NULL;
//    p1 = static_cast<int *> (p2);   //11.������ͨ��ָ��static_cast����ת����ֻ��ת��ͨ���������͡���ָ���ת���ˡ�
//    p2 = static_cast<char *> (p1);
}

int main()
{
    test1();
    return 0;
}
*/
//#############################################################
//��̬����ת��
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

void test()
{
    //static_cast ����ת�������������� �� c���Ե�ǿ������ת�����ơ�
    int a = 1;
    char b = 2;
    double c = 3.14;
    a = static_cast<int> (b);      //�����������ת��Ӧ���ǣ� a = static_case<int> (b);    //������Ϊ����һ��ģ�壺<>
    a = static_cast<int> (c);
    c = static_cast<double> (a);
}

class A
{
public:
    int a;
};

//1.�ڲ��̳еĻ�����
//class B
//{
//public:
//    int b;
//};

//4.�����̳й�ϵ
class B:public A
{
public:
    int b;
};

//��̬ת��:dynamic_cast
void test3()
{
    //1.��̬ת������ת���õĻ����������͡�
    int a = 1;
    char b = 2;
//    a = dynamic_cast<int> (b);//��������ת������������
}

void test4()
{
    //2.ת�Զ�����������
    A * p1 = NULL;
    B *p2 = NULL;

    //3.����ת����ǰ��: �����˼̳й�ϵ��û�м̳й�ϵ�ǲ��ܽ���ת���ġ�
    //dynamic_cast��������û�з����̳й�ϵ֮�����ת��
    //dynamic_cast�������ڷ����̳й�ϵ֮������ת����
    p1 = dynamic_cast<A *>(p2); //��ת������ȫ��
//    p2 = dynamic_cast<B *>(p1); //��ת��,����ȫ��ת����
    //4.��ˣ��������̳���֮�� ����ת���������� ��̬ת������֤�˰�ȫ�ԣ���static_cast���ܱ�֤��ȫ�ԡ�
}


int main()
{
    test4();
    return 0;
}
*/
//#############################################################
//����ת����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//constת��
void test()
{
    const int a = 1;
    int * p1 = NULL;
    const int *p2 = NULL;
    //static_castֻ��ת��������������
//    int *p1 = static_cast<int *> (p2);//ת����


    p1 = const_cast<int *> (p2);         //ȥconst
    p2 = const_cast<const int *> (p1);   //��const

}

int main()
{
    test();
    return 0;
}
*/
//################################################################
//reinterpret_cast���½���ת��
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
    //static_cast ��������תָ��
    //p1 = static_cast<int *>(p2)

    //dynamic_cast��ָ̬�� ��Ҫ������ ת�������֮����������͡�

    //const_cast��Ҫ���� �Ӽ�const
//    p1 = p2;//����
    p1 = reinterpret_cast<int *>(p2);
    p2 = reinterpret_cast<char *>(p1);

    int c = 0;
//    c = p2;//����

    //Cast from pointer to smaller type 'int' loses information
//    c = reinterpret_cast<int> (p1);//��ӦҲ��ȷ������ԭ���ǣ�1.int * ת int ����ȫ ���ܵ������ݶ�ʧ 2.��ʵ����Ҫ�������ʹ�ú��ʴ�С�����ͣ����磺uintptr_t �����޷����������ͣ���������ָ���λ����
    c = reinterpret_cast<uintptr_t> (p1);//�޸ĺ���ȷ

    //������ָ��ת��Ϊint���͵����� ��һ������ȫ�Ĳ��������ҿ��ܻᵼ�����ݶ�ʧ��
    //��� ��Ҫ��������ʽ��ӡָ��ĵ�ַ������ʹ�ú��ʵ��������ͣ�����uint ptr_t������һ���޷����������ͣ���������ָ���λ����

    p1 = reinterpret_cast<int *>(c);    //
}

int main()
{
    test();
    return 0;
}
*/
//###############################################################
//c++�쳣
/*
//��c����������ô�����쳣��?

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

    //�����ִ���һ�����⣺���mydive����Ϊ��1��-1��������ȷ�ؼ��������-1����retȴ�����ˡ�
    if(ret == -1)
    {
        cout << "����Ϊ0" <<endl;
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
//c++�쳣����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//1.�׳�int���͵��쳣

//int mydive(int a,int b)
//{
//    if(b == 0)
//        throw 1;//�����쳣 �׳��쳣�������׳�һ�����͡�

//    return a/b;
//}

//void test()
//{
//    //���Բ����쳣
//    try
//    {
//        mydive(2,0);
//    }
//    catch(int)//�������int����
//    {
//      cout << "������һ�� int ���͵��쳣" << endl;
//    }
//}

//2.�׳�char���͵��쳣
//int mydive(int a,int b)
//{
//    if(b == 0)
//        throw 'a';//�����쳣 �׳��쳣�������׳�һ�����͡�

//    return a/b;
//}

//void test()
//{
//    //���Բ����쳣 try��catch����ͬʱ���ڣ�������
//    try
//    {
//        mydive(2,0);
//    }
//    catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
//    {
//      cout << "������һ�� char ���͵��쳣" << endl;
//    }
//}

//int main()
//{
//    test();
//    return 0;
//}

//3.�׳��쳣������
int mydive(int a,int b)
{
    if(b == 0)
        throw 'a';//�����쳣 �׳��쳣�������׳�һ�����͡�

    return a/b;
}

void test()
{
    //���Բ����쳣 try��catch����ͬʱ���ڣ�������
    try
    {
        mydive(2,0);
    }
    catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
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
        cout << "������һ�� char ���͵��쳣" << endl;
    }
    return 0;
}
*/
//#########################################################################
//�쳣�����ϸ�ƥ��
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
        throw str;//�����쳣 �׳��쳣�������׳�һ�����͡�

    return a/b;
}

void test()
{
    //���Բ����쳣 try��catch����ͬʱ���ڣ�������
    try
    {
        mydive(2,0);
    }
    catch(char)//�������int���ͣ�����׳��쳣����û�в��񣬳������ֹ�������׳�char �����쳣���������ȴ��int���͵ġ���
    {
        cout << "������һ�� char ���͵��쳣" << endl;

    }
    catch(int)
    {
        cout << "������һ�� int ���͵��쳣" << endl;
    }
    catch(double)
    {
        cout << "������һ�� double ���͵��쳣" << endl;
    }
    catch(...)  //�������ƥ�䲻�����ͣ��������ֹ����˿�ʹ��catch(...),��ʾƥ���������͵��쳣
    {
        cout << "������һ�� ���� ���͵��쳣" << endl;
    }
}

int main()
{
    test();
    return 0;
}
*/
//######################################################################
//ջ����
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
        cout << "����" << endl;
    }

    ~Person()
    {
        cout << "����" << endl;
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
        cout << "002" << endl;  //001 �� 002 ��Ҫ���ڷ��� ������������ʲôʱ����õġ�
        cout << "������һ�� int ���͵��쳣" << endl;
    }
}
int main()
{
    test();
    return 0;
}
*/
//##############################################################
//�쳣�ӿ�����
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
//���׳����������쳣
void TestFunction1()
{
    throw 10;
}

//ֻ���׳� int char char* �����쳣
void TestFunction2() throw(int,char,char*)  //c++17��׼����֧�ֶ�̬�쳣�淶
{
    string exception = "error";
    throw exception;
}

//�����׳��κ������쳣
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
        cout << "�����쳣" << endl;
    }
    system("pause");

    return EXIT_SUCCESS;
}
//�ֱ���QT��VS��Linux�������ԣ�QT �� Linux��ȷ
*/
//##############################################################
//�쳣��������������
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
        cout << "���캯��" << endl;
    }

    ~Myexecption()
    {
        cout << "��������" << endl;
    }

    void error()
    {
        cout << "my error" <<endl;
    }

};

void fun()
{
//    //��һ����������
//    throw Myexecption();    //�����һ����������������������catch����

    Myexecption p1;
    throw p1;


}
void test()
{
    try
    {
        fun();
    }
    catch(Myexecption &p) //ʹ�����ý�
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
//�쳣�Ķ�̬ʹ��
//�쳣�Ķ�̬ʵ�֣�
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;

//���ࣺ
class Myexception
{
public:
    virtual void error() = 0;
};

//����
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
    catch(Myexception &p) //�ø����ָ�����������
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
//Ϊ��ʹ�ö�̬ʵ�ֵ�ԭ��
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
        cout << "���캯��" << endl;
    }

    ~Myexecption()
    {
        cout << "��������" << endl;
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
        cout << "���캯��" << endl;
    }

    ~Myexecption1()
    {
        cout << "��������" << endl;
    }

    void error()
    {
        cout << "my error" <<endl;
    }

};

void fun()
{

    Myexecption p1;

    throw Myexecption1();//1.����׳���һ������


}
void test()
{
    try
    {
        fun();
    }
    catch(Myexecption &p) //ʹ�����ý�
    {
        p.error();
    }
    catch(Myexecption1 &p) //2.catch��Ҫ��дһ����ÿ��һ����һ�����ͣ���Ҫ��дһ��catch,������Ҫһ���ӿڣ�ʵ�ֶ��ֹ��ܡ���������̬
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
//c++�쳣���ʹ�ã�
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
//    //�׳�Խ��
//    throw out_of_range("Խ��");

    //�׳��δ���
    throw invalid_argument("�δ���");//�׳��δ��󣺶δ��������Ч�ڴ���ʡ�
}
void test()
{
    try
    {
        fun();
    }
    catch(exception &p) //�ø����ָ�����������
    {
        cout << p.what() << endl;   //p.what()��ӡ������Ϣ��
    }
}

int main()
{
    test();
    return 0;
}
*/
//##############################################################
//�Զ����쳣��
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
    throw Longlongerror("�����Ĵ���");
}
void test()
{
    try
    {
        fun();
    }
    catch(exception &p) //�ø����ָ�����������
    {
        cout << p.what() << endl;   //p.what()��ӡ������Ϣ��
    }
}

int main()
{
    test();
    return 0;
}
*/

