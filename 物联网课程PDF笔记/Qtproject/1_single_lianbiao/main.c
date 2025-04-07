#include <stdio.h>
#include <string.h>

typedef struct student
{
    int num;
    int score;
    char name[20];

    struct student *next;
}STU;

//一、创建链表
/*
1.创建一个节点：保存 结构体指针 的 地址，并将 结构体指针 指向的 结构体指针域成员 赋值为 NULL。
2.创建第二个节点，将其放在前一个节点后面：将前一个 结构体指针的指针域成员 中的NULL 改为新增的 结构体指针中的地址，并将新增的结构体内部的指针域成员赋值为NULL。
3.注意再次创建节点的时候，要找到之前链表的最后一个节点。
*/
void link_creat_head(STU ** p_head,STU *p_new)
{
    STU *p_mov = *p_head;//址传递，解指针，保存地址
    if((*p_head) == NULL)//判度首地址是否为空，是否存在节点
    {
        *p_head = p_new;//头节点保存新节点地址
        p_new -> next = NULL;
    }
    else
    {
        while(p_mov ->next != NULL)
        {
            p_mov = p_mov->next;
        }
        p_mov ->next = p_new;
        p_new ->next = NULL;
    }
}

//二、遍历链表
/*
1.输出第一个节点的数据域，再让访问的指针指向后一个节点的地址，即保存其指针域。
2.输出移动之后的数据域，再移动指针。以此类推，直至指针域为NULL.
*/void link_print(STU *head)
{
    STU *p_mov;
    p_mov = head;//定义新的结构体指针，用于保存首地址，防止改变head变量。
    while(p_mov != NULL)
    {
        printf("num=%d score=%d name:%s\n",p_mov->num,p_mov->score,p_mov->name);
        p_mov=p_mov->next;
    }
}

//三、链表的释放
/*
    链表的创建都是在堆区，故需要手动释放
    定义临时指针q，q用于保存p指向的节点地址，p再赋值为指针域的地址，同时释放q指向的堆区空间，直至p为NULL。
    由于需要释放结构体指针指向的地址，
    故函数需要对指针进行操作，函数参数就需要 址传参，因此指针的指针就是二级指针
*/
void link_free(STU **p_head)
{
    STU *pb = *p_head;//定义临时结构体指针用于保存当前指向的地址
    while(*p_head != NULL)
    {
        pb = *p_head;//存放新的首地址
        *p_head = (*p_head)->next;//指向下一个地址

        free(pb);//释放空间
        pb = NULL;
    }
}


//链表查找:按数值查找
/*
    先对比第一个节点的数据域是否为想要的数据，若是就直接返回
    若不是，则继续查找下一个节点，直至最后一个节点都没有数据匹配，则说明要查找的数据不存在

    返回值：结构体指针，返回要找的结构体的地址
*/
STU * link_search_num(STU *head,int num)
{
    STU *p_mov;//定义临时结构体指针变量

    p_mov = head;//保存初始首地址，方便后续直接对临时变量进行操作，而不修改原地址值

    while(p_mov != NULL)//判断当前的地址是否为空，即是否到达链表的末尾，若没有为空则进入循环体
    {
        if(p_mov->num == num)//如果 指针指向的 结构体成员num 匹配 输入值num 则找到了
        {
            return p_mov;//返回此时的 结构体指针 地址值
        }
        p_mov = p_mov->next;//若num值不匹配则运行至此，将mov值赋值为指针域地址，向后一个链表移动
    }
    return NULL;//当所有循环之后未匹配则返回NULL
}


//链表查找:按数值查找
/*
    先对比第一个节点的数据域是否为想要的数据，若是就直接返回
    若不是，则继续查找下一个节点，直至最后一个节点都没有数据匹配，则说明要查找的数据不存在

    返回值：结构体指针，返回要找的结构体的地址
*/
STU * link_search_name(STU *head,char *name)
{
    STU *p_mov;//定义临时结构体指针变量

    p_mov = head;//保存初始首地址，方便后续直接对临时变量进行操作，而不修改原地址值

    while(p_mov != NULL)//判断当前的地址是否为空，即是否到达链表的末尾，若没有为空则进入循环体
    {
        if(strcmp(p_mov->name,name)==0)
        {
            return p_mov;//返回此时的 结构体指针 地址值
        }
        p_mov = p_mov->next;//若num值不匹配则运行至此，将mov值赋值为指针域地址，向后一个链表移动
    }
    return NULL;//当所有循环之后未匹配则返回NULL
}

//链表的删除:根据数据num来删除
/*
  1.若链表为空，（头节点未NULl）则不需要删除，
  2.若链表不为空：
        1.若删除的是第一个节点，则将 保存链表首地址的指针 赋值为 指针域的下一个节点的地址
        2.若删除的是中间节点，则先找到其前一个节点，将 前一个节点的指针域 赋值为 删除节点指针域的地址
            （3.删除的是末尾节点，操作流程同2）
*/
void link_delete_num(STU **p_head, int num)
{
    //一、数据 保存 与 赋值调用
    STU *pb,*pf;
    pb = pf = *p_head;//将链表首地址保存
    if((*p_head) == NULL)
    {
        printf("链表为空，没有您要删除的节点\n");
        return ;
    }

    //若不为空则运行至此
    //二、循环查找
    while(pb->num != num && pb->next != NULL)//循环找，直到匹配num或者到达链表末尾
    {
        pf = pb;//在这里，pf的作用为：存放pb前一个节点的地址，便于后续的节点删除操作
        pb = pb->next;
    }

    //三、删除链表
    if(pb->num == num)//跳出循环体：1. 找到匹配的num
    {
        if(pb == *p_head)//若 pb的地址 为 链表的首节点
        {
            *p_head = pb->next;//首地址就将p_head赋值为next的指针地址值
        }
        else
        {
            pf->next = pb->next;//若是中间节点，则将前一个结构体的指针域赋值为next的指针地址值
        }
        free(pb);//释放pb空间
    }
    else //2.pb指向NULL，没有找到
    {
        printf("没有找到您要删除的节点\n");
    }
}

//链表插入一个节点
/*
    按原本的链表的顺序（从小到大）插入，找到合适的位置
    情况：
        1.若链表没有节点，则新插入的就是第一个节点
        2.若新插入节点数值最小，则作为头节点
        3.若新插入节点数值在中间，则找到前一个节点，将pf的指针域指向新插入节点的地址，同时，将新插入的指针域赋值为pf的地址
                (4.若新插入节点数值在末尾，操作同3)
*/
void link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb = pf = *p_head;

    if(*p_head == NULL)//若头指针为NULL，则插入后返回
    {
        *p_head = p_new;
        p_new->next = NULL;
        return;
    }

    //头节点不为NULL
    while((p_new->num >= pb->num)&&(pb->next != NULL))
    {
        pf = pb;
        pb = pb->next;
    }

    //找到一个num比新的num大的节点
    if(p_new ->num < pb->num)//新插入节点 小于 pb指向的节点
    {
        if(pb == *p_head)//找到的节点就是头节点，插在最前面
        {
            p_new ->next = *p_head;
            *p_head = p_new;
        }
        else
        {
            pf->next = p_new;
            p_new ->next =pb;
        }
    }
    else //没找到比新插入节点更大的节点，插在最末尾
    {
        pb->next = p_new;
        p_new->next = NULL;
    }
}

//链表排序
/*
    1.若链表为 空 或 只有一个节点 ，不需要排序
    2.先将第一个节点与后面所有的节点依次对比数据域，只要存在比第一个节点数据域小的，交换位置，
      交换后，拿新的节点的数据域与下一个节点进行对比
*/
void link_order(STU *head)
{
    STU *pb,*pf,temp;
    pf=head;
    if((head==NULL) ||(head->next ==NULL))
    {
        printf("链表为空或只存在一个节点,不用排序\n");
        return ;
    }
    while(pf->next != NULL)//以pf指向的节点为基准节点,
    {
        pb=pf->next;//pb从基准元素的下个元素开始
        while(pb!=NULL)
        {
            if(pf->num > pb->num)
            {
                temp=*pb;
                *pb=*pf;
                *pf=temp;

                temp.next=pb->next;
                pb->next=pf->next;
                pf->next=temp.next;
            }
            pb = pb->next;
        }
        pf= pf->next;
    }
}

//链表的逆序
STU *link_reverse(STU *head)
{
    STU *pf,*pb,*r;
    pf=head; //pf保存首地址
    pb=pf->next; //pb为下一个节点的地址

    while(pb!=NULL)
    {
        r=pb->next;

        pb->next=pf;
        pf=pb;
        pb=r;
    }
    head->next=NULL;
    head=pf;
    return head;
}

int main()
{
    STU *head = NULL;//结构体地址 赋值为 NULL,
    STU *p_new = NULL;//指针域 赋值为 NULL
    int num,i;
//    printf("hello world\r\n");
    printf("请输入链表初始个数:\n");
    scanf("%d",&num);

    //创建链表
    for(i=0;i< num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//申请一个新节点
        printf("请输入学号、分数、名字:\n");
        //给新节点赋值
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);

        /**/
        link_creat_head(&head,p_new);//将新节点加入链表
    }

    //遍历链表
    link_print(head);


#if 0 //查学号
   // int num;
    STU *pb;
    while(1)
    {
        printf("请输入您要查找的学生学号\n");
        scanf("%d",&num);
        pb = link_search_num(head,num);

        if(pb != NULL)
        {
            printf("找到了 num = %d  score = %d  name:%s\n",pb->num,pb->score,pb->name);
        }
        else
        {
            printf("没有查找到对应的信息\n");
        }

    }
#endif

#if 0 //删除节点
    printf("请输入您要删除的节点的学号\n");
    scanf("%d",&num);
    link_delete_num(&head,num);

#endif

#if 0 //插入节点
    while(1)
    {
        printf("请输入您要插入节点的num score name\n");
        p_new=(STU*)malloc(sizeof(STU));
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);
        link_insert_num(&head,p_new);
        link_print(head);
    }

#endif
    link_print(head);

    link_free(&head);

    return 0;
}
//创建 增 删 查 改
