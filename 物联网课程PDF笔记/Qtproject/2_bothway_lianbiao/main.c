#include <stdio.h>

//˫����������ָ�룬һ��������һ���ڵ�ĵ�ַ����һ��������һ�����ĵ�ַ��

typedef struct student
{
    int num;
    int score;
    char name[20];

    struct student *front;//������һ�����ĵ�ַ
    struct student *next;//������һ�����ĵ�ַ��
}STU;

//˫��ڵ�Ĵ����ͱ���
/*
    1.����һ���ڵ���Ϊͷ�ڵ㣬������ָ���򶼱���NULL��
    2.���ҵ���������һ���ڵ㣬Ȼ�������һ������ָ���򱣴��²���ڵ�ĵ�ַ��
      �²����������ָ����һ��������һ�����ĵ�ַ����һ������NULL��
*/
void double_link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)        //����һ�μ�������Ϊ��ʱ
    {
        *p_head = p_new;//�׵�ַ�����´�����ĵ�ַ����������ָ����ֵΪNULL
        p_new->front = NULL;
        p_new->next = NULL;
    }
    else        //�ڶ��μ��Ժ��������
    {
        while(p_mov->next!=NULL)    //�ҵ�ԭ����������һ���ڵ�
        {
            p_mov=p_mov->next;
        }


        p_mov->next=p_new;        //�� ԭ����� ��ָ���� ��ֵΪ �����ڵ��ַ
        p_new->front =p_mov;      //��������ǰָ����ֵΪ ԭ�����ĩ�ڵ��ַ
        p_new->next = NULL;       //�����ڵ�ĺ�ָ����ֵΪ NULL��
    }
}

void double_link_print(STU *head)
{
    STU *pb;
    pb=head;    //�׵�ַ
    while(pb->next!=NULL)   //��ͷ��ӡ��β
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->next;
    }
    printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);

    printf("*************************************\n");

    /*
      ע�⣺����pb�������while������˸�ֵ��������е��˴�ʱ��pb�Ѿ������һ���ڵ�ĵ�ַ��
      ��ˣ��򵥲��ԵĻ�������Ҫ�����ٶ�pb���и�ֵĩ�ڵ��ַ��
    */

    while(pb!=NULL)         //��β��ӡ��ͷ
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->front;
    }

}

//˫�������ɾ��
/*
  ������Ϊ�գ�����Ҫɾ���ڵ�
  ����Ϊ�գ�
    ɾ��ͷ�ڵ㣺�� head ��ֵΪ ͷ��� ��ָ���򣬲�����һ���ڵ�� ǰָ����ֵΪNULL
    ɾ��ĩ�ڵ㣺�� �����ڶ���� �� ��ָ���� ��ֵΪ NULL
    ɾ���м�ڵ㣺��ǰһ���ڵ�ĺ�ָ���� ���浱ǰ�ڵ�ĺ�ָ����
                �ú�һ������ǰָ���� ���浱ǰ����ǰָ����

*/
void double_link_delete_num(STU **p_head,int num)
{
    STU *pb,*pf;
    pb = *p_head;
    if(*p_head==NULL)//����Ϊ�գ�����Ҫɾ��
    {
        printf("����Ϊ�գ�û����Ҫɾ���Ľڵ�\n");
        return ;
    }

    //Ѱ��Ҫɾ���Ľڵ�λ�ã�Ҫô�ҵ���Ҫôû��
    while((pb->num!=num)&&(pb->next!=NULL))
    {
        pb=pb->next;
    }

    if(pb->num == num)//�ҵ���һ���ڵ��num��num��ͬ��ɾ��pbָ��Ľڵ�
    {
        if(pb == *p_head)//Ҫɾ����ͷ�ڵ�
        {
            if((*p_head)->next==NULL)//ֻ��һ���ڵ�����
            {
                *p_head=pb->next;
            }
            else//�ж���ڵ�����
            {
                *p_head = pb->next;//main�����е�headָ���¸��ڵ�
                (*p_head)->front = NULL;
            }
        }
        else//Ҫɾ�Ľڵ��������ڵ�
        {
            if(pb->next!=NULL)//ɾ���м�ڵ�
            {
                pf=pb->front;//��pfָ���ҵ��Ľڵ��ǰһ���ڵ�
                pf->next=pb->next;  //ǰһ���ڵ��next�����һ���ڵ�ĵ�ַ
                (pb->next)->front=pf;   //��һ���ڵ��front����ǰһ���ڵ�ĵ�ַ
            }
            else//ɾ��β�ڵ�
            {
                pf=pb->front;
                pf->next=NULL;
            }
        }
        free(pb);//�ͷ��ҵ��Ŀռ�
    }
    else//û�ҵ�
    {
        printf("û���ҵ�Ҫɾ���Ľڵ�\n");
    }
}

//˫������İ�˳�����ڵ�
void double_link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head == NULL)//����Ϊ�գ������Ľڵ����ͷ�ڵ�
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
        return ;
    }

    while((p_new->num >= pb->num)&&(pb=pb->next != NULL))//�����ڣ���û����β��
    {
        pb=pb->next;
    }

    if(p_new->num< pb->num)//�ҵ���һ��pb��num�������Ľڵ��num�󣬲���pb
    {
        if(pb==*p_head)//�ҵ��Ľڵ���ͷ�ڵ㣬����ͷ�ڵ��ǰ��
         {   p_new->next=*p_head;
            (*p_head)->front=p_new;
            p_new->front=NULL;
            *p_head=p_new;
        }
        else    //����ڵ����м�
        {
            pf=pb->front;//pfָ�� �ҵ��ڵ��ǰһ���ڵ�

            p_new->next=pb;
            p_new->front=pf;
            pf->next=p_new;
            pb->front=p_new;
        }
    }
    else//����pbָ��ڵ��num����p_newָ��Ľڵ��numС���������
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
    printf("�����������ʼ����:\n");
    scanf("%d",&num);

    //��������
    for(i=0;i<num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//����һ���½ڵ�
        printf("������ѧ�š�����������:\n");
        //���½ڵ㸳ֵ
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);

        double_link_creat_head(&head,p_new);//���½ڵ��������
    }

    //��������
    double_link_print(head);
#if 0
    printf("��������Ҫɾ���Ľڵ��num\n");
    scanf("%d",&num);
    double_link_delete_num(&head,num);
    double_link_print(head);
#endif

#if 1
    printf("********************************\n");
    while(1)
    {
        p_new=(STU*)malloc(sizeof(STU));//����һ���½ڵ�
        printf("��������Ҫ����Ľڵ��num score name\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);
        double_link_insert_num(&head,p_new);
        double_link_print(head);
    }
#endif
    return 0;
}
