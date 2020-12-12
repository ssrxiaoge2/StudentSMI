#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000

#define DEFAULT_SZ 30
#define MAX_NAME 20
#define MAX_SEX 5
//#define MAX_TELE 5
//#define MAX_ADDR 5

enum Option   //枚举，增强程序可读性
{
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH_1,//姓名查找
	SEARCH_2,//学号查找
	MODIFY,
	SHOW,
	SAVE,
	RE0,
};

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
typedef struct peopleinfo
{
	int num;
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	//char tele[MAX_TELE];
	int tele;
	int addr;
	//char addr[MAX_ADDR];
	int Cscoal;
}peopleinfo;
//通讯录类型
typedef struct Contact
{
	struct peopleinfo *data;//存放一个信息
	int size;//记录当前已经有的元素个数
	int capacity;
}Contact;

//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SearchContact_2(struct Contact* ps);
void SaveContact(Contact* ps);
void DestroyContact(Contact* ps);
void LoadContact(Contact* ps);
void RE();