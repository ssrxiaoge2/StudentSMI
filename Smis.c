#include<stdio.h>
#include<stdlib.h>
#include"contact.h"
#include<string.h>
#include<errno.h>
void Menu();
int main(void)
{
	system("title ѧ����Ϣ����ϵͳ"); //����cmd���ڱ���
	system("mode con cols=95 lines=25"); //���ڿ�ȸ߶�
	system("color e0"); //����д�� red ������ɫ��
	int input = 0;
	//����
	struct Contact con;
	//��ʼ��
	InitContact(&con);
	do
	{
		Menu();
		printf("��ѡ��\n>>");
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
			printf("\t\t\t\t�ѳɹ��˳�����ϵͳ\n");
			break;
		case RE0:
			RE();
			break;
		default:
			printf("ѡ�����");
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
	printf("\t\t*-------------------��ӭ����ѧ����Ϣ����ϵͳ-------------------*\n");
	printf("\t\t*---------------------�������˹���Ṥ����---------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
	printf("\t\t*----------------------1.����ѧ����Ϣ--------------------------*\n");
	printf("\t\t*----------------------2.ɾ��ѧ����Ϣ--------------------------*\n");
	printf("\t\t*----------------------3.��������ѧ��--------------------------*\n");
	printf("\t\t*----------------------4.ѧ�Ų���ѧ��--------------------------*\n");
	printf("\t\t*----------------------5.�޸�ѧ����Ϣ--------------------------*\n");
	printf("\t\t*----------------------6.��ʾѧ����Ϣ--------------------------*\n");
	printf("\t\t*----------------------7.�洢ѧ����Ϣ--------------------------*\n");
	printf("\t\t*----------------------0.�˳�����ϵͳ--------------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
	printf("\t\t*----------------------8.�����˹����--------------------------*\n");
	printf("\t\t*--------------------------------------------------------------*\n");
}

