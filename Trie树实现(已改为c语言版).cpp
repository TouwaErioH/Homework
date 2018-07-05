#include <stdio.h>
#include <stdlib.h>
struct Trie{    //�ֵ�������
    struct Trie* next[130];
    int flag=0;
};
struct Trie *creat()
{
	struct Trie *branch;
	branch=(struct Trie *)malloc(sizeof(struct Trie));
	for(int i=0;i<130;i++){
            branch->next[i] = NULL;
        }
	return branch;
}
struct Trie root;
void Insert(char word[])    //���ַ���word���뵽�ֵ�����
{
    struct Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //����word��ÿһ���ַ�
        if(p->next[word[i]-31]==NULL)    //������ַ�û�ж�Ӧ�Ľڵ�
            p->next[word[i]-31] = creat();    //����һ��
        p = p->next[word[i]-31];
    }
    p->flag=1;
}
int Find(char word[])    //�������ַ���wordΪǰ׺�ĵ��ʵ�����
{
    struct Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //���ֵ����ҵ��õ��ʵĽ�βλ��
        if(p->next[word[i]-31]==NULL)
            return 0;
        p = p->next[word[i]-31];
    }
    if(p->flag==1)
    return 1;
    return 0;
}

int main()
{
    char word[30];
    for(int i=0;i<130;i++){
            root.next[i] = NULL;
        }
    printf("�����������һ��һ����������9ʱֹͣ\n");
    scanf("%s",word);
    while(word[0]!='9')
        {Insert(word);
            scanf("%s",word);
        }
   printf("�����������ַ��һ��һ��,������9ʱֹͣ\n");
       scanf("%s",word);
        while(word[0]!='9')
{
 if(Find(word))
printf("%s�ں�������\n",word);
scanf("%s",word);
}
    return 0;
}
