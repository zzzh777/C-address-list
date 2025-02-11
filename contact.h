#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//初始化全局最大变量
#define MAX 100
#define CAP_MAX 3
#define CAP_ADD 2
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 15
#define MAX_ADDRACT 50

//联系人结构体
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addract[MAX_ADDRACT];
}PeoInfo;
//通讯录结构体-------静态版本
//typedef struct contact
//{
//	PeoInfo data[100];
//	int size;
//}contact;

//通讯录结构体-------动态版本
typedef struct contact
{
	PeoInfo* data;
	int size;
	int capacity;
}contact;

//初始化通讯录
void InitContact(contact* con);
//销毁通讯录
void DestroyContact(contact* con);
//增加联系人
void AddContact(contact* con);
//显示通讯录
void ShowContact(const contact* con);
//删除联系人
void DelContact(contact* con);
//查找联系人
void SearchContact(contact* con);
//修改联系人
void ModifyContact(contact* con);
//联系人排序
void SortContact(contact* con);
