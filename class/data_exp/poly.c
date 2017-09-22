/* ***********************************************
Author :111qqz
Created Time :2015年12月10日 星期四 15时35分21秒
File Name :poly.c
************************************************ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
    int xishu;
    int power;
    struct list *next;
}list;

list* creat()
{
    list* head=(list*)malloc(sizeof(list));
    if(head==NULL)
    {
        printf("malloc head node failed\n");
        exit(-1);
    }
    head->xishu=0;
    head->power=0;
    head->next=NULL;
    int count;
    printf("please input the count of the list:");
    scanf("%d",&count);
    printf("please input %d xiang,with the power increase\n",count);
    while(count<=0)
    {
        printf("the input is invalid,please input the count of the list again:");
        scanf("%d",&count);
    }
    while(count>0)
    {
        list *newnode=(list*)malloc(sizeof(list));
        if(newnode==NULL)
        {
            printf("malloc newnode failed\n");
            exit(-1);
        }
        printf("please input xishu:");
        scanf("%d",&newnode->xishu);
        printf("please input power:");
        scanf("%d",&newnode->power);
        newnode->next=head->next;
        head->next=newnode;
        --count;
    }
    return head;
}

void print(const list* lst)
{
    if(lst==NULL)
        printf("the list is not exist\n");
    if(lst->next!=NULL)
    {
        list *p=lst->next;
        while(p!=NULL)
        {
            if(p->power!=0&&p->xishu!=1&&p->power!=1)
                printf("%dX^%d",p->xishu,p->power);
            else if(p->power!=0&&p->xishu!=1&&p->power==1)
                printf("%dX",p->xishu);
            else if(p->power!=0&&p->xishu==1&&p->power!=1)
                printf("X^%d",p->power);
            else if(p->power==1&&p->xishu==1)
                printf("X");
            else
                printf("%d",p->xishu);
            p=p->next;
            if(p!=NULL)
                printf("+");
        }
        printf("\n");
    }

}

void list_free(list *a)
{
    if(a==NULL)
        return ;
    list *pa=a->next;
    while(pa!=NULL)
    {
        list *tmp=pa;
        pa=pa->next;
        free(tmp);
        tmp=NULL;
    }
    free(a);
    a=NULL;
}

list *list_copy(const list *src)
{
    if(src==NULL)
    {
        printf("the list is not exist\n");
        exit(-1);
    }
    const list *p=src->next;
    list* head=(list*)malloc(sizeof(list));
    if(head==NULL)
    {
        printf("malloc head node failed\n");
        exit(-1);
    }
    head->xishu=0;
    head->power=0;
    head->next=NULL;
    list* place=head;
    while(p!=NULL)
    {
        list *newnode=(list*)malloc(sizeof(list));
        if(newnode==NULL)
        {
            printf("malloc newnode failed\n");
            exit(-1);
        }
        newnode->xishu=p->xishu;
        newnode->power=p->power;

        newnode->next=place->next;
        place->next=newnode;
        place=place->next;
        p=p->next;
    }
    return head;
}

list* list_add_one(const list *a,int xishu,int power)
{
    if(a==NULL)
    {
        printf("list is null\n");
        exit(-1);
    }
    list *head=list_copy(a);
    list *p=head->next;
    list *pre=head;
    list *newnode=(list*)malloc(sizeof(list));
    if(newnode==NULL)
    {
        printf("malloc newnode failed\n");
        exit(-1);
    }
    newnode->xishu=xishu;
    newnode->power=power;
    if(head->next==NULL)
    {
        newnode->next=head->next;
        head->next=newnode;
        return head;
    }

    while(p!=NULL)
    {
        if(p->power>power)
        {
            p=p->next;
            pre=pre->next;
        }
        else if(p->power==power)
        {
            p->xishu+=xishu;
            return head;
        }
        else
        {
            newnode->next=pre->next;
            pre->next=newnode;
            return head;
        }
    }
    if(p==NULL)
    {
        newnode->next=pre->next;
        pre->next=newnode;
    }
    return head;
}





list* list_add(const list *a,const list *b)
{
    if(a==NULL&&b==NULL)
    {
        printf("duoxiangshi NULL\n");
        exit(-1);
    }
    if(a==NULL&&b!=NULL)
        return list_copy(b);
    if(a!=NULL&&b==NULL)
        return list_copy(a);
    const list *pa=a->next;
    const list *pb=b->next;

    list *head=list_copy(a);

    while(pb!=NULL)
    {
        head=list_add_one(head,pb->xishu,pb->power);
        pb=pb->next;
    }
    return head;
}


list* list_multiple_one(const list* a,int xishu,int power)
{
    if(a==NULL)
    {
        printf("the list is not exist\n");
        exit(-1);
    }
    if(a->next==NULL)
    {
        printf("the list donot have data\n");
        exit(-1);
    }
    list *head=list_copy(a);
    list *p=head->next;
    while(p!=NULL)
    {
        p->xishu*=xishu;
        p->power+=power;
        p=p->next;
    }
    return head;
}


list* list_multiple(const list *a,const list *b)
{
    const list *pa=a->next;
    const list *pb=b->next;
    if(pa==NULL||pb==NULL)
    {
        printf("duoxiangshi NULL\n");
        exit(-1);
    }
    list *tmp=NULL;
    list *result=NULL;
    while(pa!=NULL)
    {
        tmp=list_multiple_one(b,pa->xishu,pa->power);
        result=list_add(result,tmp);
        pa=pa->next;
    }

    return result;
}

int main()
{
    list *a=creat();
    list *b=creat();
    printf("a=");
    print(a);
    printf("b=");
    print(b);
    printf("a+b=");
    print(list_add(a,b));
    printf("a*b=");
    print(list_multiple(a,b));
    list_free(a);
    list_free(b);
    return 0;
}










