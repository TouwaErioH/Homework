#include <stdio.h>
#include <stdlib.h>
struct BOOK{
char bookname[30];
char writer[20];
double price;
int amount;
};
#define MAX 2
int main()
{
   struct BOOK books[MAX] ;
   int n=0;
   while(n!=MAX)
   {
       printf("�����%d���������\n",n+1);
       scanf("%s",books[n].bookname);
       printf("�����%d���������\n",n+1);
       scanf("%s",books[n].writer);
       printf("�����%d����ļ۸�\n",n+1);
       scanf("%lf",&books[n].price);
       printf("�����%d���������\n",n+1);
       scanf("%d",&books[n].amount);
       n++;
   }
   FILE *fp;
   fp=fopen("C:\\Users\\lenovo\\Desktop\\book.dat","w") ;
   if(fp==NULL)
   {
   printf("File open error\n");
   exit(1);
   }
   n=0;
   while(n!=MAX)
   {
       fprintf(fp,"%s\n%s\n%lf\n%d\n",books[n].bookname,books[n].writer,books[n].price,books[n].amount);
       n++;
   }
   fclose(fp);
    return 0;
}
