#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(struct Contact* ps)
{
//	memset(ps->data, 0, sizeof(ps->data));
//	ps->size = 0;//设置通讯录最初只有零个元素
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
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
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
	printf("请输入学号\n>>");
	scanf("%d", &(ps->data[ps->size].num));
	printf("请输入名字\n>>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄\n>>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别\n>>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入数学成绩\n>>");
	scanf("%d", &(ps->data[ps->size].tele));
	printf("请输入英语成绩\n>>");
	scanf("%d", &(ps->data[ps->size].addr));
	printf("请输入C语言成绩\n>>");
	scanf("%d", &(ps->data[ps->size].Cscoal));

	ps->size++;
	printf("添加成功\n");
	system("pause");
	system("cls");

	/*if (ps->size == MAX)
	{
		printf("学生信息已满，无法继续增加");
	}
	else
	{
		printf("请输入学号\n>>");
		scanf("%d", &(ps->data[ps->size].num));
		printf("请输入名字\n>>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄\n>>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别\n>>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入数学成绩\n>>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入英语成绩\n>>");
		scanf("%s", ps->data[ps->size].addr);
		printf("请输入C语言成绩\n>>");
		scanf("%d", &(ps->data[ps->size].Cscoal));

		ps->size++;
		printf("添加成功\n");
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
		printf("\t\t\t\t系统提示：无任何学生信息\n\n");
	}
	else
	{
		int i = 0;
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "学号", "名字", "年龄", "性别", "数学成绩", "英语成绩", "C语言成绩");
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
	return -1;//找不到的情况

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
	return -1;//找不到的情况

}
void DelContact(struct Contact* ps)
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\n");
	char name[MAX_NAME]; 
	printf("请输入要删除的学生信息的学生姓名：\n>>");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	//找到返回名字的元素下标
	//找不到返回 -1
	int pos = FindByName(ps,name);
	//2.删除
	if (pos == -1)
	{
		printf("要删除的人不存在\n");

	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];

		}
		ps->size--;
		printf("删除成功\n");

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
	printf("请输入要输入要查找人的姓名：\n>>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");

	}
	else
	{
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "学号", "名字", "年龄", "性别", "数学成绩", "英语成绩","C语言成绩");
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
	printf("请输入要修改的学生姓名：\n>>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		printf("请输入学号\n>>");
		scanf("%d", &(ps->data[pos].num));
		printf("请输入名字\n>>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄\n>>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别\n>>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入数学成绩\n>>");
		scanf("%d", &(ps->data[pos].tele));
		printf("请输入英语成绩\n>>");
		scanf("%d", &(ps->data[pos].addr));
		printf("请输入C语言成绩\n>>");
		scanf("%d", &(ps->data[pos].Cscoal));

		printf("修改完成\n");
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
	printf("请输入要输入要查找人的学号：\n>>");
	scanf("%d", &num);
	int pos = FindByNum(ps, num);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");

	}
	else
	{
		printf("%-10s \t%-10s \t%-4s \t%-5s \t%-6s \t%-6s \t%-6s\n", "学号", "名字", "年龄", "性别", "数学成绩", "英语成绩", "C语言成绩");
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
	//写通讯录的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(peopleinfo), 1, pfWrite);

	}

	fclose(pfWrite);
	pfWrite = NULL;
	system("cls");
	printf("保存成功\n");
	system("pause");
	system("cls");
}
void RE()
{
	system("cls");
	system("date /T");
	system("TIME /T");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃岱斯特尼始创于2020年11月2日，主要负责管理系统开发，游戏制作与软件外包。 ┃\n");
	printf("\t┃目前工作室由孙小强（leader）、孙晓松（技术总监）、王阁轩（外交负责人）和┃\n");
	printf("\t┃赵泮基、荣繁博、闫心傲三名技术成员组成。                                ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("pause");
	system("cls");
}
