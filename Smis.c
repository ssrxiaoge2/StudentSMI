#include<stdio.h>
#include<stdlib.h>
#include"contact.h"
#include<string.h>
#include<errno.h>
void Menu();
int main(void)
{
	system("title 学生信息管理系统"); //设置cmd窗口标题
	system("mode con cols=95 lines=25"); //窗口宽度高度
	system("color e0"); //可以写成 red 调出颜色组
	int input = 0;
	//创建
	struct Contact con;
	//初始化
	InitContact(&con);
	do
	{
		Menu();
		printf("请选择\n>>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH_1:
			SearchContact(&con);
			break;
		case SEARCH_2:
			SearchContact_2(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			system("cls");
			SaveContact(&con);
			DestroyContact(&con);
			printf("\t\t\t\t已成功退出管理系统\n");
			break;
		case RE0:
			RE();
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);
	return 0;
}
void Menu()
{
	system("date /T");
	system("TIME /T");
	printf("\n");
	printf("\t\t****************************************************************\n");
	printf("\t\t*-------------------欢迎访问学生信息管理系统-------------------*\n");
	printf("\t\t*---------------------制作：岱斯特尼工作室---------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
	printf("\t\t*----------------------1.新增学生信息--------------------------*\n");
	printf("\t\t*----------------------2.删除学生信息--------------------------*\n");
	printf("\t\t*----------------------3.姓名查找学生--------------------------*\n");
	printf("\t\t*----------------------4.学号查找学生--------------------------*\n");
	printf("\t\t*----------------------5.修改学生信息--------------------------*\n");
	printf("\t\t*----------------------6.显示学生信息--------------------------*\n");
	printf("\t\t*----------------------7.存储学生信息--------------------------*\n");
	printf("\t\t*----------------------0.退出管理系统--------------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
	printf("\t\t*----------------------8.关于岱斯特尼--------------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
}

