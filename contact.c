#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//静态版本初始化
//void InitContact(contact* con)
//{
//	assert(con);
//	con->size = 0;
//	memset(con->data, 0, sizeof(con->data));
//}

void check(contact* con)
{
	if (con->capacity == con->size)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(con->data, (con->capacity + CAP_ADD) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("增容失败\n");
		}
		else
		{
			con->data = ptr;
			con->capacity += CAP_ADD;
			printf("增加成功\n");
		}
	}
}
//动态版本初始化
void LoadContact(contact* con)
{
	assert(con);
	//创建
	FILE* pRead = fopen("contact.txt", "rb");
	if (pRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//开始读取
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pRead) == 1)
	{
		check(con);
		con->data[con->size] = tmp;
		con->size++;
	}
	

	fclose(pRead);
	pRead = NULL;
}
void InitContact(contact* con)
{
	assert(con);
	con->size = 0;
	con->data = (PeoInfo*)calloc(CAP_MAX, sizeof(PeoInfo));
	if (con->data == NULL)
	{
		printf("初始化失败\n");
	}
	con->capacity = CAP_MAX;
	LoadContact(con);
}
//销毁
void DestroyContact(contact* con)
{
	assert(con);
	free(con->data);
	con->data = NULL;
}
//静态版本增加
//void AddContact(contact* con)
//{
//	assert(con);
//	//判断通讯录是否已满
//	if (con->size == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	else
//	{
//		printf("请输入名字：\n");
//		scanf("%s", con->data[con->size].name);
//		printf("请输入年龄：\n");
//		scanf("%d", &(con->data[con->size].age));//age是变量，需要取地址
//		printf("请输入性别：\n");
//		scanf("%s", con->data[con->size].sex);
//		printf("请输入电话：\n");
//		scanf("%s", con->data[con->size].tel);
//		printf("请输入地址：\n");
//		scanf("%s", con->data[con->size].addract);
//	}
//	con->size++;
//	printf("添加成功\n");
//
//}
//动态版本增加

void AddContact(contact* con)
{
	assert(con);
	//增容
	check(con);

	printf("请输入名字：\n");
	scanf("%s", con->data[con->size].name);
	printf("请输入年龄：\n");
	scanf("%d", &(con->data[con->size].age));//age是变量，需要取地址
	printf("请输入性别：\n");
	scanf("%s", con->data[con->size].sex);
	printf("请输入电话：\n");
	scanf("%s", con->data[con->size].tel);
	printf("请输入地址：\n");
	scanf("%s", con->data[con->size].addract);
	con->size++;
	printf("添加成功\n");

}
//显示
void ShowContact(contact* con)
{
	assert(con);
	int i = 0;
	printf("%-20s\t%-3s\t%-6s\t%-13s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < con->size; i++)
	{
		printf("%-20s\t%-3d\t%-6s\t%-13s\t%-30s\n", con -> data[i].name
			,con->data[i].age
			,con->data[i].sex
			,con->data[i].tel
			,con->data[i].addract);
	}
}

static int FindContact(contact* con, char name[])
{
	assert(con);
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if(strcmp(con->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//删除
void DelContact(contact* con)
{
	
	char name[MAX_NAME] = { 0 };
	int i = 0;
	assert(con);
	if (con->size == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	printf("请输入要删除的名字：\n");
	scanf("%s",name);
	int ret = FindContact(con,name);
	if (ret == -1)
	{
		printf("没找到，无法删除\n");
		return;
	}
	for (i = ret; i < con->size - 1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->size--;
	printf("删除成功\n");
}
//按名字查找

void SearchContact(contact* con)
{
	assert(con);
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的名字：\n");
	scanf("%s", name);
	int pos = FindContact(con, name);
	if (pos == -1)
	{
		printf("没找到\n");
		return;
	}
	else
	{
		printf("%-20s\t%-3s\t%-6s\t%-13s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-3d\t%-6s\t%-13s\t%-30s\n", con->data[pos].name
			, con->data[pos].age
			, con->data[pos].sex
			, con->data[pos].tel
			, con->data[pos].addract);
	}
}
//修改联系人
void ModifyContact(contact* con)
{
	assert(con);
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的名字：\n");
	scanf("%s", name);
	int pos = FindContact(con, name);
	if (pos == -1)
	{
		printf("不存在\n");
		return;
	}
	//修改
		printf("请输入名字：\n");
		scanf("%s", con->data[pos].name);
		printf("请输入年龄：\n");
		scanf("%d", &(con->data[pos].age));//age是变量，需要取地址
		printf("请输入性别：\n");
		scanf("%s", con->data[pos].sex);
		printf("请输入电话：\n");
		scanf("%s", con->data[pos].tel);
		printf("请输入地址：\n");
		scanf("%s", con->data[pos].addract);
		printf("修改成功\n");
}
//联系人排序---名字
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
int cmp_sex(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex);
}
int cmp_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}
void SortContact(contact* con)
{
	assert(con);
	printf("请选择排序方式：1.名字排序，2.性别排序，3.年龄排序\n");
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		//按名字排序
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_name);
		printf("排序成功\n");
		break;
	case 2:
		//按性别排序
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_sex);
		printf("排序成功\n");
		break;
	case 3:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_age);
		printf("排序成功\n");
		break;
	default:
		break;
	}	
}
//保存通讯录
void SaveContact(const contact* con)
{
	assert(con);
	//创建文件
	FILE* pWrite = fopen("contact.txt", "wb");
	if (pWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//二进制写入
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		fwrite(con->data + i, sizeof(PeoInfo), 1, pWrite);
	}
	//关闭
	fclose(pWrite);
	pWrite = NULL;
}