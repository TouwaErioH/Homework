#include <stdio.h>
#include <stdlib.h>
int LineCount(char *name);
#define MAX 50
int main()
{
    char name[MAX];
    printf("�����ļ���������·����\n");
    scanf("%s",name);
    int d=0;
    d=LineCount(name);
    printf("�ļ�����%d�С�\n",d);
    system("pause");
    return 0;
}

int LineCount(char *name)
{
    FILE *fp=fopen(name,"r");
    if(fp==NULL)
    {
        printf("File open error��");
        exit(1);
    }
    int n=0;
    char c;
   while(!feof(fp))
    {
        c=fgetc(fp);
        if(c=='\n')//�����������û���ûس����������0��
            n++;
    }
    fclose(fp);
    return n;
}

