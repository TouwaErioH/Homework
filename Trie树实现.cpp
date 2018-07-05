#include <iostream>
#include <string.h>
using namespace std;

struct Trie{    //�ֵ�������
    Trie* next[130];
    int flag;
    Trie()    //���캯����ʼ��
    {
        int i;
        for(i=0;i<130;i++){
            next[i] = NULL;
        }
        flag=0;
    }
};
Trie root;
void Insert(char word[])    //���ַ���word���뵽�ֵ�����
{
    Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //����word��ÿһ���ַ�
        if(p->next[word[i]-31]==NULL)    //������ַ�û�ж�Ӧ�Ľڵ�
            p->next[word[i]-31] = new Trie;    //����һ��
        p = p->next[word[i]-31];
    }
    p->flag=1;
}
int Find(char word[])    //�������ַ���wordΪǰ׺�ĵ��ʵ�����
{
    Trie *p = &root;
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
