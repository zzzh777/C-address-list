#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void menu()
{
	printf("*************************************\n");
	printf("**** 1.ADD    ******** 2.DEL    *****\n");
	printf("**** 3.SEARCH ******** 4.MODIFY *****\n");
	printf("**** 5.SHOW   ******** 6.SORT   *****\n");
	printf("************** 0.EXIT ***************\n");
	printf("*************************************\n");

}
int main()
{
	int i = 0;
	contact con;//通讯录
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			//增加联系人
			AddContact(&con);
			break;
		case 2:
			//删除联系人
			DelContact(&con);
			break;
		case 3:
			//查找联系人
			SearchContact(&con);
			break;
		case 4:
			//修改联系人
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			//联系人排序
			SortContact(&con);
			break;
		case 0:
			DestroyContact(&con);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (i);
	return 0;
}