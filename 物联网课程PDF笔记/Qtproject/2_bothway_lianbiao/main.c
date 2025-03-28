#include <stdio.h>

//双向链表：两个指针，一个保存上一个节点的地址，另一个保存下一个结点的地址。

typedef struct student
{
    int num;
    int score;
    char name[20];

    struct student *front;//保存上一个结点的地址
    struct student *next;//保存下一个结点的地址。
}STU;

//双向节点的创建和遍历
/*
    1.创建一个节点作为头节点，将两个指针域都保存NULL。
    2.先找到链表的最后一个节点，然后让最后一个结点的指针域保存新插入节点的地址，
      新插入结点的两个指针域，一个保存上一个结点的地址，另一个保存NULL。
*/
void double_link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)        //当第一次加入链表为空时
    {
        *p_head = p_new;//首地址就是新创链表的地址，并让两个指针域赋值为NULL
        p_new->front = NULL;
        p_new->next = NULL;
    }
    else        //第二次及以后加入链表
    {
        while(p_mov->next!=NULL)    //找到原有链表的最后一个节点
        {
            p_mov=p_mov->next;
        }


        p_mov->next=p_new;        //将 原链表的 后指针域 赋值为 新增节点地址
        p_new->front =p_mov;      //新增结点的前指针域赋值为 原链表的末节点地址
        p_new->next = NULL;       //新增节点的后指针域赋值为 NULL。
    }
}

void double_link_print(STU *head)
{
    STU *pb;
    pb=head;    //首地址
    while(pb->next!=NULL)   //从头打印到尾
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->next;
    }
    printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);

    printf("*************************************\n");

    /*
      注意：由于pb在上面的while里进行了赋值，因此运行到此处时，pb已经是最后一个节点的地址了
      因此，简单测试的话，不需要额外再对pb进行赋值末节点地址。
    */

    while(pb!=NULL)         //从尾打印到头
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->front;
    }

}

//双向链表的删除
/*
  若链表为空，则不需要删除节点
  若不为空：
    删除头节点：将 head 赋值为 头结点 后指针域，并将下一个节点的 前指针域赋值为NULL
    删除末节点：将 倒数第二结点 的 后指针域 赋值为 NULL
    删除中间节点：让前一个节点的后指针域 保存当前节点的后指针域，
                让后一个结点的前指针域 保存当前结点的前指针域。

*/
void double_link_delete_num(STU **p_head,int num)
{
    STU *pb,*pf;
    pb = *p_head;
    if(*p_head==NULL)//链表为空，不需要删除
    {
        printf("链表为空，没有您要删除的节点\n");
        return ;
    }

    //寻找要删除的节点位置：要么找到，要么没有
    while((pb->num!=num)&&(pb->next!=NULL))
    {
        pb=pb->next;
    }

    if(pb->num == num)//找到了一个节点的num和num相同，删除pb指向的节点
    {
        if(pb == *p_head)//要删的是头节点
        {
            if((*p_head)->next==NULL)//只有一个节点的情况
            {
                *p_head=pb->next;
            }
            else//有多个节点的情况
            {
                *p_head = pb->next;//main函数中的head指向下个节点
                (*p_head)->front = NULL;
            }
        }
        else//要删的节点是其他节点
        {
            if(pb->next!=NULL)//删除中间节点
            {
                pf=pb->front;//让pf指向找到的节点的前一个节点
                pf->next=pb->next;  //前一个节点的next保存后一个节点的地址
                (pb->next)->front=pf;   //后一个节点的front保存前一个节点的地址
            }
            else//删除尾节点
            {
                pf=pb->front;
                pf->next=NULL;
            }
        }
        free(pb);//释放找到的空间
    }
    else//没找到
    {
        printf("没有找到要删除的节点\n");
    }
}

//双向链表的按顺序插入节点
void double_link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head == NULL)//链表为空，新来的节点就是头节点
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
        return ;
    }

    while((p_new->num >= pb->num)&&(pb=pb->next != NULL))//若大于，且没到达尾部
    {
        pb=pb->next;
    }

    if(p_new->num< pb->num)//找到了一个pb的num比新来的节点的num大，插在pb
    {
        if(pb==*p_head)//找到的节点是头节点，插在头节点的前边
         {   p_new->next=*p_head;
            (*p_head)->front=p_new;
            p_new->front=NULL;
            *p_head=p_new;
        }
        else    //插入节点在中间
        {
            pf=pb->front;//pf指向 找到节点的前一个节点

            p_new->next=pb;
            p_new->front=pf;
            pf->next=p_new;
            pb->front=p_new;
        }
    }
    else//所有pb指向节点的num都比p_new指向的节点的num小，插在最后
    {
        pb->next=p_new;
        p_new->front=pb;
        p_new->next=NULL;
    }
}



int main()
{
    STU *head = NULL,*p_new = NULL;
    int num,i;
    printf("请输入链表初始个数:\n");
    scanf("%d",&num);

    //创建链表
    for(i=0;i<num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//申请一个新节点
        printf("请输入学号、分数、名字:\n");
        //给新节点赋值
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);

        double_link_creat_head(&head,p_new);//将新节点加入链表
    }

    //遍历链表
    double_link_print(head);
#if 0
    printf("请输入您要删除的节点的num\n");
    scanf("%d",&num);
    double_link_delete_num(&head,num);
    double_link_print(head);
#endif

#if 1
    printf("********************************\n");
    while(1)
    {
        p_new=(STU*)malloc(sizeof(STU));//申请一个新节点
        printf("请输入您要插入的节点的num score name\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);
        double_link_insert_num(&head,p_new);
        double_link_print(head);
    }
#endif
    return 0;
}
