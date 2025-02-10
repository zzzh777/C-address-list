#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void InitContact(contact* con)
{
	con->size = 0;
	memset(con->data, 0, sizeof(con->data));
}
void AddContact(contact* con)
{
	//判断通讯录是否已满
	if (con->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	else
	{
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
	}
	con->size++;
	printf("添加成功\n");

}
void ShowContact(contact* con)
{
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