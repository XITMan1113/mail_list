/*通讯录*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<getch.h>
#include<string.h>

//#define NUM 50  //人数
//#define NAMEL 20  //名字的长度
//#define PHONEL 12 //电话的长度

enum number{NUM=50,NAMEL=20,PHONEL=12};

typedef struct people
{
	char name[NAMEL];//姓名
	char phone_number[PHONEL];//电话号码
	char sex;//性别
	int class;//查看此位置是否有人
}People;

People p[NUM];

void menu(void);//显示菜单页面

void addpeople(void);//添加联系人

void initialize(void);//初始化联系人

void delete_people(void);//删除联系人

void modify_people(void);//修改联系人

void find_people(void);//查找联系人

void show_people(void);//显示所有联系人

void anykey_continue(void);//按任意键继续

int main()
{
	initialize();//初始化联系人
	system("clear");
	while(true)
	{
		menu();
		switch(getch())
		{
			case '1':addpeople();//添加联系人
			break;
			case '2':delete_people();//删除联系人
			break;
			case '3':modify_people();//修改联系人
			break;
			case '4':find_people();//查找联系人
			break;
			case '5':show_people();//显示联系人
			break;
			case '0':{
				printf("欢迎下次使用!!");
				exit(0);//退出系统
				}
			break;
			default:{
				printf("输入有误!!请重新输入!!\n");
				anykey_continue();
				}
			break;
		}
		system("clear");
	}
}

void menu(void)//显示菜单页面
{
	printf("--------------------------\n");
	printf("|       通讯录1.0v       |\n");
	printf("|                        |\n");
	printf("|      1.添加联系人      |\n");
	printf("|                        |\n");
	printf("|      2.删除联系人      |\n");
	printf("|                        |\n");
	printf("|      3.修改联系人      |\n");
	printf("|                        |\n");
	printf("|      4.查找联系人      |\n");
	printf("|                        |\n");
	printf("|      5.显示联系人      |\n");
	printf("|                        |\n");
	printf("|       0.退出系统       |\n");
	printf("--------------------------\n");
}

void addpeople(void)//添加联系人
{
	//判断通讯录是否存满
	for(int i=0;i<NUM;i++)
	{
		if(0==p[i].class)
		{
			break;
		}
		if(i==NUM-1)
		{
			printf("开通ｖｉｐ即可存储更多联系人!!!\n");
			anykey_continue();
			return;
		}
	}
	printf("请输入联系人姓名:\n");
	//将信息存入空位
	for(int i=0;i<NUM;i++)
	{
		if(p[i].class==0)
		{
			scanf("%s",p[i].name);
			printf("请输入联系人电话:\n");
			scanf("%s",p[i].phone_number);
			printf("请输入联系人性别:(b or g)\n");
			scanf(" %c",&p[i].sex);
			p[i].class=1;
			printf("\n添加成功!!!\n");
			anykey_continue();
			return;
		}
	}
}

void delete_people(void)//删除联系人
{
	char name[NAMEL];
	printf("请输入要删除的联系人的姓名:\n");
	scanf("%s",name);
	//遍历查找
	for(int i=0;i<NUM;i++)
	{
		if(strcmp(p[i].name,name)==0)
		{
			p[i].class=0;
			printf("删除成功!!\n");
			anykey_continue();
			return;
		}
	}
	printf("未查找到该联系人！！！\n");
	anykey_continue();
	return;
}

void modify_people(void)//修改联系人
{
	char name[NAMEL];
	printf("请输入要修改的联系人的姓名:\n");
	scanf("%s",name);
	//遍历查找
	for(int i=0;i<NUM;i++)
	{
		if(strcmp(p[i].name,name)==0)
		{
			printf("请输入修改后联系人姓名:\n");
			scanf("%s",p[i].name);
			printf("请输入修改后联系人电话:\n");
			scanf("%s",p[i].phone_number);
			printf("请输入修改后联系人性别:(b or g)\n");
			scanf(" %c",&p[i].sex);
			printf("\n修改成功!!!\n");
			anykey_continue();
			return;
		}
	}
	printf("未查找到该联系人！！！\n");
	anykey_continue();
	return;
}

void find_people(void)//查找联系人
{
	int choose=0;
	char name[NAMEL];
	char phone[PHONEL];
	printf("1.通过姓名查找\n");
	printf("2.通过电话查找\n");
	scanf("%d",&choose);
	//通过姓名查找
	if(choose==1)
	{
		int f=0;
		printf("请输入要查找的联系人的姓名:\n");
		scanf("%s",name);
		for(int i=0;i<NUM;i++)
		{
			if(strstr(p[i].name,name)!=NULL)
			{
				printf("联系人信息如下：\n%s %s %c\n",p[i].name,p[i].phone_number,p[i].sex);
				f=1;
			}
		}
		if(f==0)
		{
			printf("未找到提供的联系人信息!!\n");
			anykey_continue();
			return;
		}
		anykey_continue();
		return;
	}
	//通过电话查找
	else if(choose==2)
	{
		int f=0;
		printf("请输入要查找的联系人的电话:\n");
		scanf("%s",phone);
		for(int i=0;i<NUM;i++)
		{
			if(strstr(p[i].phone_number,phone)!=NULL)
			{
				printf("姓名：%s 电话：%s 性别：%c\n",p[i].name,p[i].phone_number,p[i].sex);
				f=1;
			}
		}
		if(f==0)
		{
			printf("未找到提供的联系人信息!!\n");
			anykey_continue();
			return;
		}
		anykey_continue();
		return;
	}
	else
	{
		printf("你的输入有误!!!!");
		return;
	}
}

void show_people(void)//显示所有联系人
{
	printf("所有的联系人信息如下:\n");
	for(int i=0;i<NUM;i++)
	{
		if(p[i].class)
		{
			printf("姓名：%s 电话：%s 性别：%c\n",p[i].name,p[i].phone_number,p[i].sex);
		}
	}
	anykey_continue();
	return;
}

void initialize(void)//初始化联系人
{
	//将所有位置为空
	for(int i=0;i<NUM;i++)
	{
		p[i].class=0;
	}
}

void anykey_continue(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	printf("请按任意键继续...");
	getch();
}
