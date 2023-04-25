#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int mainMenu();
int searchMenu();
void S_initial(struct studentManagement* sM,int capacity);
void S_entry(struct studentManagement* pthis);
void S_look(struct studentManagement* pthis);
void S_search(struct studentManagement* pthis);
void S_sort(struct studentManagement* pthis);
struct Student
{
	long long number;
	char name[20];
	double Chinese;
	double Math;
	double English;
	double average;
};
struct studentManagement
{
	struct Student* data;
	int capacity;
	int size;
};
int main()
{
	struct studentManagement* sM;
	S_initial(&sM,100);
	int op;
	while (true)
	{
		system("cls");
		switch (mainMenu())
		{
		case 1:
			S_entry(&sM);
			break;
		case 2:
			S_search(&sM);
			break;
		case 3:
			S_sort(&sM);
			break;
		case 4:
			S_look(&sM);
			break;
		case 0:
			exit(-1);
			break;
		}
		system("pause");
	}

	return 0;
}
int mainMenu()
{
	
	printf("*******************\n");
	printf("    1信息录入      \n");
	printf("    2信息查询      \n");  
	printf("    3信息排序      \n");
	printf("    4查看录入      \n");
	printf("    0退出          \n");
	printf("*******************\n");
	printf("select:            \n");
	int option;
	scanf("%d", &option);
	return option;
}
int searchMenu()
{
	int option;
	printf("*******************\n");
	printf("    1按学号查询    \n");
	printf("    2按不及格查询  \n");
	printf("    0返回主菜单    \n");
	printf("select:            \n");
	scanf("%d", &option);
	return option;
}
int sortMenu()
{
	int option;
	printf("*******************\n");
	printf("    1按总成绩排序  \n");
	printf("    0返回主菜单    \n");
	printf("select:            \n");
	scanf("%d", &option);
	return option;
}
void S_initial(struct studentManagement* pthis,int capacity)
{
	pthis->capacity = capacity;
	pthis->size = 0;
	pthis->data = malloc(sizeof(struct Student) * capacity);
	memset(pthis->data, 0, sizeof(struct Student));
}
void S_entry(struct studentManagement* pthis)
{
	printf("学号 姓名 语文 数学 英语\n");
	struct Student stu;
	scanf("%lld %s %lf %lf %lf", &stu.number,stu.name,&stu.Chinese,&stu.Math,&stu.English);
	stu.average = (stu.Chinese + stu.Math + stu.English) / 3;
	pthis->data[pthis->size] = stu;
	pthis->size++;
}
void S_look(struct studentManagement* pthis)
{
	printf("学号 姓名 语文 数学 英语\n");
	for (int i = 0; i < pthis->size; i++)
	{  
		printf("%lld %s %.2lf %.2lf %.2lf\n", pthis->data[i].number,pthis->data[i].name, pthis->data[i].Chinese, pthis->data[i].Math, pthis->data[i].English);
	}
}
void S_search(struct studentManagement* pthis)
{
	bool isDone = true;
	long long int Snum;
	while (isDone)
	{
		
		switch (searchMenu())
		{
		case 1:
			printf("输入学号：\n");
			scanf("%lld",&Snum);
			 for (int i = 0; i <pthis->size; i++)
			 {
				 if (pthis->data[i].number == Snum)
				 {
					 printf("学号 姓名 语文 数学 英语\n");
					 printf("%lld %s %.2lf %.2lf %.2lf\n", pthis->data[i].number, pthis->data->name, pthis->data->Chinese, pthis->data->Math, pthis->data->English);
				 }
			 }
			break;
		case 2:
			printf("学号 姓名 语文 数学 英语\n");
			for (int i = 0; i < pthis->size; i++)
			{
				if (pthis->data[i].Chinese < 60 || pthis->data[i].Math < 60 || pthis->data[i].English < 60)
					printf("%lld %s %.2lf %.2lf %.2lf\n", pthis->data[i].number, pthis->data->name, pthis->data->Chinese, pthis->data->Math, pthis->data->English);
			}
			break;
		case 0:
			isDone = false;
			break;
		}

	}
}
void S_sort(struct studentManagement* pthis)
{
	bool isDone = true;
	while (isDone)
	{
		switch (sortMenu())
		{
		case 1:
			for (int i = 0; i < pthis->size - 1; i++)
			{
				for (int k = 0; k < pthis->size - i - 1; k++)
				{
					if (pthis->data[k].average > pthis->data[k+1].average)
					{
						struct Student t = pthis->data[k];
						pthis->data[k] = pthis->data[k + 1];
						pthis->data[k + 1] = t;
					}
				}
			}
			printf("学号 姓名 语文 数学 英语\n");
			for (int i = 0; i < pthis->size; i++)
			{
				
				printf("%lld %s %.2lf %.2lf %.2lf\n", pthis->data[i].number, pthis->data[i].name, pthis->data[i].Chinese, pthis->data[i].Math, pthis->data[i].English);
			}
			
			break;
		case 0:
			isDone = false;
			break;
		}
	}
	
}
