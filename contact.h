#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//��ʼ��ȫ��������
#define MAX 100
#define CAP_MAX 3
#define CAP_ADD 2
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 15
#define MAX_ADDRACT 50

//��ϵ�˽ṹ��
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addract[MAX_ADDRACT];
}PeoInfo;
//ͨѶ¼�ṹ��-------��̬�汾
//typedef struct contact
//{
//	PeoInfo data[100];
//	int size;
//}contact;

//ͨѶ¼�ṹ��-------��̬�汾
typedef struct contact
{
	PeoInfo* data;
	int size;
	int capacity;
}contact;

//��ʼ��ͨѶ¼
void InitContact(contact* con);
//����ͨѶ¼
void DestroyContact(contact* con);
//������ϵ��
void AddContact(contact* con);
//��ʾͨѶ¼
void ShowContact(const contact* con);
//ɾ����ϵ��
void DelContact(contact* con);
//������ϵ��
void SearchContact(contact* con);
//�޸���ϵ��
void ModifyContact(contact* con);
//��ϵ������
void SortContact(contact* con);
