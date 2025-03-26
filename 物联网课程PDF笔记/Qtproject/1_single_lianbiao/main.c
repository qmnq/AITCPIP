#include <stdio.h>
#include <string.h>

typedef struct student
{
    int num;
    int score;
    char name[20];

    struct student *next;
}STU;

//һ����������
/*
1.����һ���ڵ㣺���� �ṹ��ָ�� �� ��ַ������ �ṹ��ָ�� ָ��� �ṹ��ָ�����Ա ��ֵΪ NULL��
2.�����ڶ����ڵ㣬�������ǰһ���ڵ���棺��ǰһ�� �ṹ��ָ���ָ�����Ա �е�NULL ��Ϊ������ �ṹ��ָ���еĵ�ַ�����������Ľṹ���ڲ���ָ�����Ա��ֵΪNULL��
3.ע���ٴδ����ڵ��ʱ��Ҫ�ҵ�֮ǰ��������һ���ڵ㡣
*/
void link_creat_head(STU ** p_head,STU *p_new)
{
    STU *p_mov = *p_head;//ַ���ݣ���ָ�룬�����ַ
    if((*p_head) == NULL)//�ж��׵�ַ�Ƿ�Ϊ�գ��Ƿ���ڽڵ�
    {
        *p_head = p_new;//ͷ�ڵ㱣���½ڵ��ַ
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

//������������
/*
1.�����һ���ڵ�����������÷��ʵ�ָ��ָ���һ���ڵ�ĵ�ַ����������ָ����
2.����ƶ�֮������������ƶ�ָ�롣�Դ����ƣ�ֱ��ָ����ΪNULL.
*/void link_print(STU *head)
{
    STU *p_mov;
    p_mov = head;//�����µĽṹ��ָ�룬���ڱ����׵�ַ����ֹ�ı�head������
    while(p_mov != NULL)
    {
        printf("num=%d score=%d name:%s\n",p_mov->num,p_mov->score,p_mov->name);
        p_mov=p_mov->next;
    }
}

//����������ͷ�
/*
    ����Ĵ��������ڶ���������Ҫ�ֶ��ͷ�
    ������ʱָ��q��q���ڱ���pָ��Ľڵ��ַ��p�ٸ�ֵΪָ����ĵ�ַ��ͬʱ�ͷ�qָ��Ķ����ռ䣬ֱ��pΪNULL��
    ������Ҫ�ͷŽṹ��ָ��ָ��ĵ�ַ��
    �ʺ�����Ҫ��ָ����в�����������������Ҫ ַ���Σ����ָ���ָ����Ƕ���ָ��
*/
void link_free(STU **p_head)
{
    STU *pb = *p_head;//������ʱ�ṹ��ָ�����ڱ��浱ǰָ��ĵ�ַ
    while(*p_head != NULL)
    {
        pb = *p_head;//����µ��׵�ַ
        *p_head = (*p_head)->next;//ָ����һ����ַ

        free(pb);//�ͷſռ�
        pb = NULL;
    }
}


//�������:����ֵ����
/*
    �ȶԱȵ�һ���ڵ���������Ƿ�Ϊ��Ҫ�����ݣ����Ǿ�ֱ�ӷ���
    �����ǣ������������һ���ڵ㣬ֱ�����һ���ڵ㶼û������ƥ�䣬��˵��Ҫ���ҵ����ݲ�����

    ����ֵ���ṹ��ָ�룬����Ҫ�ҵĽṹ��ĵ�ַ
*/
STU * link_search_num(STU *head,int num)
{
    STU *p_mov;//������ʱ�ṹ��ָ�����

    p_mov = head;//�����ʼ�׵�ַ���������ֱ�Ӷ���ʱ�������в����������޸�ԭ��ֵַ

    while(p_mov != NULL)//�жϵ�ǰ�ĵ�ַ�Ƿ�Ϊ�գ����Ƿ񵽴������ĩβ����û��Ϊ�������ѭ����
    {
        if(p_mov->num == num)//��� ָ��ָ��� �ṹ���Աnum ƥ�� ����ֵnum ���ҵ���
        {
            return p_mov;//���ش�ʱ�� �ṹ��ָ�� ��ֵַ
        }
        p_mov = p_mov->next;//��numֵ��ƥ�����������ˣ���movֵ��ֵΪָ�����ַ�����һ�������ƶ�
    }
    return NULL;//������ѭ��֮��δƥ���򷵻�NULL
}


//�������:����ֵ����
/*
    �ȶԱȵ�һ���ڵ���������Ƿ�Ϊ��Ҫ�����ݣ����Ǿ�ֱ�ӷ���
    �����ǣ������������һ���ڵ㣬ֱ�����һ���ڵ㶼û������ƥ�䣬��˵��Ҫ���ҵ����ݲ�����

    ����ֵ���ṹ��ָ�룬����Ҫ�ҵĽṹ��ĵ�ַ
*/
STU * link_search_name(STU *head,char *name)
{
    STU *p_mov;//������ʱ�ṹ��ָ�����

    p_mov = head;//�����ʼ�׵�ַ���������ֱ�Ӷ���ʱ�������в����������޸�ԭ��ֵַ

    while(p_mov != NULL)//�жϵ�ǰ�ĵ�ַ�Ƿ�Ϊ�գ����Ƿ񵽴������ĩβ����û��Ϊ�������ѭ����
    {
        if(strcmp(p_mov->name,name)==0)
        {
            return p_mov;//���ش�ʱ�� �ṹ��ָ�� ��ֵַ
        }
        p_mov = p_mov->next;//��numֵ��ƥ�����������ˣ���movֵ��ֵΪָ�����ַ�����һ�������ƶ�
    }
    return NULL;//������ѭ��֮��δƥ���򷵻�NULL
}

//�����ɾ��:��������num��ɾ��
/*
  1.������Ϊ�գ���ͷ�ڵ�δNULl������Ҫɾ����
  2.������Ϊ�գ�
        1.��ɾ�����ǵ�һ���ڵ㣬�� ���������׵�ַ��ָ�� ��ֵΪ ָ�������һ���ڵ�ĵ�ַ
        2.��ɾ�������м�ڵ㣬�����ҵ���ǰһ���ڵ㣬�� ǰһ���ڵ��ָ���� ��ֵΪ ɾ���ڵ�ָ����ĵ�ַ
            ��3.ɾ������ĩβ�ڵ㣬��������ͬ2��
*/
void link_delete_num(STU **p_head, int num)
{
    //һ������ ���� �� ��ֵ����
    STU *pb,*pf;
    pb = pf = *p_head;//�������׵�ַ����
    if((*p_head) == NULL)
    {
        printf("����Ϊ�գ�û����Ҫɾ���Ľڵ�\n");
        return ;
    }

    //����Ϊ������������
    //����ѭ������
    while(pb->num != num && pb->next != NULL)//ѭ���ң�ֱ��ƥ��num���ߵ�������ĩβ
    {
        pf = pb;//�����pf������Ϊ�����pbǰһ���ڵ�ĵ�ַ�����ں����Ľڵ�ɾ������
        pb = pb->next;
    }

    //����ɾ������
    if(pb->num == num)//����ѭ���壺1. �ҵ�ƥ���num
    {
        if(pb == *p_head)//�� pb�ĵ�ַ Ϊ ������׽ڵ�
        {
            *p_head = pb->next;//�׵�ַ�ͽ�p_head��ֵΪnext��ָ���ֵַ
        }
        else
        {
            pf->next = pb->next;//�����м�ڵ㣬��ǰһ���ṹ���ָ����ֵΪnext��ָ���ֵַ
        }
        free(pb);//�ͷ�pb�ռ�
    }
    else //2.pbָ��NULL��û���ҵ�
    {
        printf("û���ҵ���Ҫɾ���Ľڵ�\n");
    }
}

//�������һ���ڵ�
/*
    ��ԭ���������˳�򣨴�С���󣩲��룬�ҵ����ʵ�λ��
    �����
        1.������û�нڵ㣬���²���ľ��ǵ�һ���ڵ�
        2.���²���ڵ���ֵ��С������Ϊͷ�ڵ�
        3.���²���ڵ���ֵ���м䣬���ҵ�ǰһ���ڵ㣬��pf��ָ����ָ���²���ڵ�ĵ�ַ��ͬʱ�����²����ָ����ֵΪpf�ĵ�ַ
                (4.���²���ڵ���ֵ��ĩβ������ͬ3)
*/
void link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb = pf = *p_head;

    if(*p_head == NULL)//��ͷָ��ΪNULL�������󷵻�
    {
        *p_head = p_new;
        p_new->next = NULL;
        return;
    }

    //ͷ�ڵ㲻ΪNULL
    while((p_new->num >= pb->num)&&(pb->next != NULL))
    {
        pf = pb;
        pb = pb->next;
    }

    //�ҵ�һ��num���µ�num��Ľڵ�
    if(p_new ->num < pb->num)//�²���ڵ� С�� pbָ��Ľڵ�
    {
        if(pb == *p_head)//�ҵ��Ľڵ����ͷ�ڵ㣬������ǰ��
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
    else //û�ҵ����²���ڵ����Ľڵ㣬������ĩβ
    {
        pb->next = p_new;
        p_new->next = NULL;
    }
}

//��������
/*
    1.������Ϊ �� �� ֻ��һ���ڵ� ������Ҫ����
    2.�Ƚ���һ���ڵ���������еĽڵ����ζԱ�������ֻҪ���ڱȵ�һ���ڵ�������С�ģ�����λ�ã�
      ���������µĽڵ������������һ���ڵ���жԱ�
*/
void link_order(STU *head)
{
    STU *pb,*pf,temp;
    pf=head;
    if((head==NULL) ||(head->next ==NULL))
    {
        printf("����Ϊ�ջ�ֻ����һ���ڵ�,��������\n");
        return ;
    }
    while(pf->next != NULL)//��pfָ��Ľڵ�Ϊ��׼�ڵ�,
    {
        pb=pf->next;//pb�ӻ�׼Ԫ�ص��¸�Ԫ�ؿ�ʼ
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

//���������
STU *link_reverse(STU *head)
{
    STU *pf,*pb,*r;
    pf=head; //pf�����׵�ַ
    pb=pf->next; //pbΪ��һ���ڵ�ĵ�ַ

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
    STU *head = NULL;//�ṹ���ַ ��ֵΪ NULL,
    STU *p_new = NULL;//ָ���� ��ֵΪ NULL
    int num,i;
//    printf("hello world\r\n");
    printf("�����������ʼ����:\n");
    scanf("%d",&num);

    //��������
    for(i=0;i< num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//����һ���½ڵ�
        printf("������ѧ�š�����������:\n");
        //���½ڵ㸳ֵ
        scanf("%d %d %s",&p_new->num,&p_new->score,p_new->name);

        /**/
        link_creat_head(&head,p_new);//���½ڵ��������
    }

    //��������
    link_print(head);


#if 0 //��ѧ��
   // int num;
    STU *pb;
    while(1)
    {
        printf("��������Ҫ���ҵ�ѧ��ѧ��\n");
        scanf("%d",&num);
        pb = link_search_num(head,num);

        if(pb != NULL)
        {
            printf("�ҵ��� num = %d  score = %d  name:%s\n",pb->num,pb->score,pb->name);
        }
        else
        {
            printf("û�в��ҵ���Ӧ����Ϣ\n");
        }

    }
#endif

#if 0 //ɾ���ڵ�
    printf("��������Ҫɾ���Ľڵ��ѧ��\n");
    scanf("%d",&num);
    link_delete_num(&head,num);

#endif

#if 0 //����ڵ�
    while(1)
    {
        printf("��������Ҫ����ڵ��num score name\n");
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
//���� �� ɾ �� ��
