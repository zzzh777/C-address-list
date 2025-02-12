#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

//��̬�汾��ʼ��
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
			printf("����ʧ��\n");
		}
		else
		{
			con->data = ptr;
			con->capacity += CAP_ADD;
			printf("���ӳɹ�\n");
		}
	}
}
//��̬�汾��ʼ��
void LoadContact(contact* con)
{
	assert(con);
	//����
	FILE* pRead = fopen("contact.txt", "rb");
	if (pRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//��ʼ��ȡ
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
		printf("��ʼ��ʧ��\n");
	}
	con->capacity = CAP_MAX;
	LoadContact(con);
}
//����
void DestroyContact(contact* con)
{
	assert(con);
	free(con->data);
	con->data = NULL;
}
//��̬�汾����
//void AddContact(contact* con)
//{
//	assert(con);
//	//�ж�ͨѶ¼�Ƿ�����
//	if (con->size == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	else
//	{
//		printf("���������֣�\n");
//		scanf("%s", con->data[con->size].name);
//		printf("���������䣺\n");
//		scanf("%d", &(con->data[con->size].age));//age�Ǳ�������Ҫȡ��ַ
//		printf("�������Ա�\n");
//		scanf("%s", con->data[con->size].sex);
//		printf("������绰��\n");
//		scanf("%s", con->data[con->size].tel);
//		printf("�������ַ��\n");
//		scanf("%s", con->data[con->size].addract);
//	}
//	con->size++;
//	printf("��ӳɹ�\n");
//
//}
//��̬�汾����

void AddContact(contact* con)
{
	assert(con);
	//����
	check(con);

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
	con->size++;
	printf("��ӳɹ�\n");

}
//��ʾ
void ShowContact(contact* con)
{
	assert(con);
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
//ɾ��
void DelContact(contact* con)
{
	
	char name[MAX_NAME] = { 0 };
	int i = 0;
	assert(con);
	if (con->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ�������֣�\n");
	scanf("%s",name);
	int ret = FindContact(con,name);
	if (ret == -1)
	{
		printf("û�ҵ����޷�ɾ��\n");
		return;
	}
	for (i = ret; i < con->size - 1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->size--;
	printf("ɾ���ɹ�\n");
}
//�����ֲ���

void SearchContact(contact* con)
{
	assert(con);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ����֣�\n");
	scanf("%s", name);
	int pos = FindContact(con, name);
	if (pos == -1)
	{
		printf("û�ҵ�\n");
		return;
	}
	else
	{
		printf("%-20s\t%-3s\t%-6s\t%-13s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-3d\t%-6s\t%-13s\t%-30s\n", con->data[pos].name
			, con->data[pos].age
			, con->data[pos].sex
			, con->data[pos].tel
			, con->data[pos].addract);
	}
}
//�޸���ϵ��
void ModifyContact(contact* con)
{
	assert(con);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ����֣�\n");
	scanf("%s", name);
	int pos = FindContact(con, name);
	if (pos == -1)
	{
		printf("������\n");
		return;
	}
	//�޸�
		printf("���������֣�\n");
		scanf("%s", con->data[pos].name);
		printf("���������䣺\n");
		scanf("%d", &(con->data[pos].age));//age�Ǳ�������Ҫȡ��ַ
		printf("�������Ա�\n");
		scanf("%s", con->data[pos].sex);
		printf("������绰��\n");
		scanf("%s", con->data[pos].tel);
		printf("�������ַ��\n");
		scanf("%s", con->data[pos].addract);
		printf("�޸ĳɹ�\n");
}
//��ϵ������---����
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
	printf("��ѡ������ʽ��1.��������2.�Ա�����3.��������\n");
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		//����������
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_name);
		printf("����ɹ�\n");
		break;
	case 2:
		//���Ա�����
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_sex);
		printf("����ɹ�\n");
		break;
	case 3:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_age);
		printf("����ɹ�\n");
		break;
	default:
		break;
	}	
}
//����ͨѶ¼
void SaveContact(const contact* con)
{
	assert(con);
	//�����ļ�
	FILE* pWrite = fopen("contact.txt", "wb");
	if (pWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//������д��
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		fwrite(con->data + i, sizeof(PeoInfo), 1, pWrite);
	}
	//�ر�
	fclose(pWrite);
	pWrite = NULL;
}