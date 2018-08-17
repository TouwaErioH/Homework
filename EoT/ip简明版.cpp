#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=130;

int n,m,tag[520];

struct Trie{
    int count;      //�Ƿ�Ϊ�õ��ʵ����һ���ڵ�
    Trie *fail;     //ʧ��ָ��
    Trie *next[N];

    Trie(){     //���캯����ʼ��
        count=0;
        fail=NULL;
        memset(next,0,sizeof(next));
    }
}*q[5000010];       //���У���������bfs����ʧ��ָ��

char word[520];     //����ĵ���
char str[1000010];  //ģʽ��
int head,tail;      //���е�ͷβָ��



//����Trie
void Insert(char *str,Trie *Root,int id){
    Trie *loc=Root;
    int i=0;
    while(str[i]!='\0'){
        int id=str[i]-31;
        if(loc->next[id]==NULL)
            loc->next[id]=new Trie();
        loc=loc->next[id];
        i++;
    }
    loc->count=id;      //��ʼ��Ϊ0��++��Ϊ1����ʾ��һ�����ʵĽ�β
}


//����ʧ��ָ��
void AC_automation(Trie *Root){
    Root->fail=NULL;
    q[head++]=Root;
    Trie *cur,*tmp;
    while(head!=tail){
        cur=q[tail++];      //�õ�һ���ڵ�
        tmp=NULL;
        for(int i=0;i<N;i++){
            if(cur->next[i]!=NULL){     //����i���ӷǿ�
                if(cur==Root)   //���Լ���ͷ���亢�ӵ�ʧ��ָ��ָ��ͷ
                    cur->next[i]->fail=Root;
                else{   //��ͨ�ڵ�
                    tmp=cur->fail;  //ָ���Լ���ʧ��ָ��
                    while(tmp!=NULL){
                        if(tmp->next[i]!=NULL){     //ʧ��ָ����i����
                            cur->next[i]->fail=tmp->next[i];    //��ǰ�ڵ��i���ӵ�ʧ��ָ��ָ��ʧ��ָ���i���ӣ�Ȼ������
                            break;
                        }
                        tmp=tmp->fail;  //������ʧ��ָ��
                    }
                    if(tmp==NULL)       //��ʧ��ָ��Ϊ��
                        cur->next[i]->fail=Root;    //��ǰ�ڵ��i���ӵ�ʧ��ָ��ָ��ͷ
                }
                q[head++]=cur->next[i]; //��ȥ�Ķ��Ƕ����ʧ��ָ���,�ʴ˹����Ǹ��亢�Ӷ���ʧ��ָ��
            }
        }
    }
}


//ƥ�����
int query(Trie *Root){
    int i=0,cnt=0;
    Trie *loc=Root,*tmp;
    while(str[i]!='\0'){
        int id=str[i]-31;   //���㺢�ӵ�λ��   32��ʼASCII��space
        while(loc->next[id]==NULL && loc!=Root){
            loc=loc->fail;  //��û��i���ӽڵ㣬ͨ��ʧ��ָ��������֮ǰ��ͬ����i���ӵĽڵ�
        }
        loc=loc->next[id];      //ָ����i����
        loc=(loc==NULL)?Root:loc;
        tmp=loc;
        while(tmp!=Root && tmp->count!=0){
            if(tmp->count!=0 && !tag[tmp->count]){  //��Ҫ�Ǹ�����
                cnt++;
                tag[tmp->count]=1;
            }
            tmp=tmp->fail;
        }
        i++;
    }
    return cnt;
}

int main(){

printf("����������N�������������ַ��IP����\n");
       printf("֮��N�зֱ�������Щ��ַ��ip�����Զ���ţ�1-N\n");
    while(scanf("%d",&n)!=0){
        head=tail=0;
        Trie *Root=new Trie();
                getchar();
        for(int i=1;i<=n;i++){
            gets(word);
            Insert(word,Root,i);
        }
        AC_automation(Root);
         printf("����������M�������������ַ��ip����\n");
               printf("֮��M�зֱ�������Щ��ַ��ip��ע�⣬������ͬ�������Զ���ţ�1-M\n");
        scanf("%d",&m);
        int total=0;
        for(int i=1;i<=m;i++){
            memset(tag,0,sizeof(tag));
            scanf("%s",str);
            int flag=query(Root);
            if(flag){
                printf("��������ַ%d�����ں�����",i);
                for(int j=1;j<=n;j++)
                    if(tag[j])
                        printf(" %d",j);
                printf("\n");
                total++;
            }
        }
        printf("total: %d\n",total);
    }
    return 0;
}
