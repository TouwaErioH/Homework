#include <stdio.h>
#include <stdlib.h>
struct node{
int number;
struct node *next;
};
struct node* creat();
struct node* concatenate(struct node* pp1,struct node* pp2);
void print(struct node* pp3);

int main()
{
    printf("������һ������\n");
 struct node *p1=creat();
    printf("�����ڶ�������\n");
 struct node *p2=creat();
struct node *p3=concatenate(p1,p2);
 printf("������ϲ��������\n");
 print(p3);
 system("pause");
 return 0;
}

struct node* creat()
{
struct node *head,*New,*tail;
head=NULL;
int n=0;
printf("����������-1Ϊ������־\n");
 scanf("%d",&n);
while(n!=-1)
{
    New=(struct node*)malloc(sizeof(struct node));
    New->number=n;
    New->next=NULL;
    if(head==NULL)
        head=New;
    else
        tail->next=New;
    tail=New;
    scanf("%d",&n);
}
fflush(stdin);
return head;
}

struct node* concatenate(struct node* pp1,struct node* pp2)
{
    struct node *New;
    New=pp1;
    while(New->next!=NULL)
        New=New->next;
        New->next=pp2;
        return pp1;
}

void print(struct node* pp3)
{
    struct node *New=pp3;
    while(New->next!=NULL)
    {
        printf("%d\n",New->number);
        New=New->next;
    }
    printf("%d\n",New->number);
}
