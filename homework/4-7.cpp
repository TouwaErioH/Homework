// xiti4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	printf("顺序输入序号与数量计算总值，输入0停止计算\n");
	float total = 0,y=1,z=1;
	int x = 1;
	while (x != 0 )
	{
		scanf_s("%d", &x);
		if (x == 0)
			break;
		
		scanf_s("%f", &y);
		switch (x)
		{
		case 1: z = y * 2.98; break;
		case 2: z = y * 4.50; break;
		case 3:z = y * 9.98; break;
		case 4:	z = y * 4.49; break;
		case 5:z = y * 6.87; break;
		}
		
		total = total + z;
		printf("%.2f\n", total);
	}
	printf("%.2f\n", total);
		system("pause");
	return 0;
}

