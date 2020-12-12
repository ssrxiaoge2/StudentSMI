#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000

#define DEFAULT_SZ 30
#define MAX_NAME 20
#define MAX_SEX 5
//#define MAX_TELE 5
//#define MAX_ADDR 5

enum Option   //ö�٣���ǿ����ɶ���
{
	EXIT,//0
	ADD,//1
	DEL,
	SEARCH_1,//��������
	SEARCH_2,//ѧ�Ų���
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
//ͨѶ¼����
typedef struct Contact
{
	struct peopleinfo *data;//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;
}Contact;

//��������
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