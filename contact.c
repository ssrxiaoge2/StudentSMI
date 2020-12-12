#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* ps)
{
//	memset(ps->data, 0, sizeof(ps->data));
//	ps->size = 0;//����ͨѶ¼���ֻ�����Ԫ��
	ps->data = (struct popleinfo*)malloc(DEFAULT_SZ * sizeof(struct peopleinfo));
	if (ps->data == NULL)
	{
		return ;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);

}
void CheckCapacity(struct Contact* ps);
void LoadContact(Contact* ps)
{
	peopleinfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(peopleinfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;

}
void CheckCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct peopleinfo* ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(peopleinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}

	}

}
void AddContact(struct Contact* ps)

{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	CheckCapacity(ps);
	printf("������ѧ��\n>>");
	scanf("%d", &(ps->data[ps->size].num));
	printf("����������\n>>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������\n>>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�\n>>");
	scanf("%s", ps->data[ps->size].sex);
	printf("��������ѧ�ɼ�\n>>");
	scanf("%d", &(ps->data[ps->size].tele));
	printf("������Ӣ��ɼ�\n>>");
	scanf("%d", &(ps->data[ps->size].addr));
	printf("������C���Գɼ�\n>>");
	scanf("%d", &(ps->data[ps->size].Cscoal));

	ps->size++;
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");

	/*if (ps->size == MAX)
	{
		printf("ѧ����Ϣ�������޷���������");
	}
	else
	{
		printf("������ѧ��\n>>");
		scanf("%d", &(ps->data[ps->size].num));
		printf("����������\n>>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������\n>>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�\n>>");
		scanf("%s", ps->data[ps->size].sex);
		printf("��������ѧ�ɼ�\n>>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������Ӣ��ɼ�\n>>");
		scanf("%s", ps->data[ps->size].addr);
		printf("������C���Գɼ�\n>>");
		scanf("%d", &(ps->data[ps->size].Cscoal));

		ps->size++;
		printf("��ӳɹ�\n");
		system("pause");
		system("cls");
	}*/
}
void ShowContact(const struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n\n");
	if (ps->size == 0)
	{
		printf("\t\t\t\tϵͳ��ʾ�����κ�ѧ����Ϣ\n\n");
	}
	else
	{
		int i = 0;
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "ѧ��", "����", "����", "�Ա�", "��ѧ�ɼ�", "Ӣ��ɼ�", "C���Գɼ�");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10d \t%-10s \t%-4d \t%-5s \t%-8d \t%-6d \t\t%-6d\n",
				ps->data[i].num,
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex, 
				ps->data[i].tele, 
				ps->data[i].addr,
				ps->data[i].Cscoal
			);
		}
	}
	system("pause");
	system("cls");


}
static int FindByNum(const struct Contact* ps, int num)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i].num == num)
		{
			return i;
		}

	}
	return -1;//�Ҳ��������

}




static int FindByName(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}

	}
	return -1;//�Ҳ��������

}
void DelContact(struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	char name[MAX_NAME]; 
	printf("������Ҫɾ����ѧ����Ϣ��ѧ��������\n>>");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ��������ֵ�Ԫ���±�
	//�Ҳ������� -1
	int pos = FindByName(ps,name);
	//2.ɾ��
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");

	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];

		}
		ps->size--;
		printf("ɾ���ɹ�\n");

	}
	system("pause");
	system("cls");
}
void SearchContact(const struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	char name[MAX_NAME];
	printf("������Ҫ����Ҫ�����˵�������\n>>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");

	}
	else
	{
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "ѧ��", "����", "����", "�Ա�", "��ѧ�ɼ�", "Ӣ��ɼ�","C���Գɼ�");
		printf("%-10d \t%-10s \t%-4d \t%-5s \t%-8d \t%-6d \t\t%-6d\n",
			ps->data[pos].num,
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr,
			ps->data[pos].Cscoal
		
		);

	}
	system("pause");
	system("cls");
}
void ModifyContact(struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ�ѧ��������\n>>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else
	{
		printf("������ѧ��\n>>");
		scanf("%d", &(ps->data[pos].num));
		printf("����������\n>>");
		scanf("%s", ps->data[pos].name);
		printf("����������\n>>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�\n>>");
		scanf("%s", ps->data[pos].sex);
		printf("��������ѧ�ɼ�\n>>");
		scanf("%d", &(ps->data[pos].tele));
		printf("������Ӣ��ɼ�\n>>");
		scanf("%d", &(ps->data[pos].addr));
		printf("������C���Գɼ�\n>>");
		scanf("%d", &(ps->data[pos].Cscoal));

		printf("�޸����\n");
	}
	system("pause");
	system("cls");

}
void SearchContact_2(struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	int num;
	printf("������Ҫ����Ҫ�����˵�ѧ�ţ�\n>>");
	scanf("%d", &num);
	int pos = FindByNum(ps, num);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");

	}
	else
	{
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "ѧ��", "����", "����", "�Ա�", "��ѧ�ɼ�", "Ӣ��ɼ�", "C���Գɼ�");
		printf("%-10d \t%-10s \t%-4d \t%-5s \t%-8d \t%-6d \t\t%-6d\n",
			ps->data[pos].num,
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr,
			ps->data[pos].Cscoal

		);

	}
	system("pause");
	system("cls");


}
void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(peopleinfo), 1, pfWrite);

	}

	fclose(pfWrite);
	pfWrite = NULL;
	system("cls");
	printf("����ɹ�\n");
	system("pause");
	system("cls");
}
void RE()
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\t����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t���˹����ʼ����2020��11��2�գ���Ҫ�������ϵͳ��������Ϸ�������������� ��\n");
	printf("\t��Ŀǰ����������Сǿ��leader���������ɣ������ܼࣩ�����������⽻�����ˣ��ͩ�\n");
	printf("\t�����������ٷ��������İ�����������Ա��ɡ�                                ��\n");
	printf("\t����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	system("pause");
	system("cls");
}
