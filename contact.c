#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void InitContact(contact* con)
{
	con->size = 0;
	memset(con->data, 0, sizeof(con->data));
}
void AddContact(contact* con)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (con->size == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	else
	{
		printf("���������֣�\n");
		scanf("%s", con->data[con->size].name);
		printf("���������䣺\n");
		scanf("%d", &(con->data[con->size].age));//age�Ǳ�������Ҫȡ��ַ
		printf("�������Ա�\n");
		scanf("%s", con->data[con->size].sex);
		printf("������绰��\n");
		scanf("%s", con->data[con->size].tel);
		printf("�������ַ��\n");
		scanf("%s", con->data[con->size].addract);
	}
	con->size++;
	printf("��ӳɹ�\n");

}
void ShowContact(contact* con)
{
	int i = 0;
	printf("%-20s\t%-3s\t%-6s\t%-13s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < con->size; i++)
	{
		printf("%-20s\t%-3d\t%-6s\t%-13s\t%-30s\n", con -> data[i].name
			,con->data[i].age
			,con->data[i].sex
			,con->data[i].tel
			,con->data[i].addract);
	}
}