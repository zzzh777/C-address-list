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
	contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			//������ϵ��
			AddContact(&con);
			break;
		case 2:
			//ɾ����ϵ��
			DelContact(&con);
			break;
		case 3:
			//������ϵ��
			SearchContact(&con);
			break;
		case 4:
			//�޸���ϵ��
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			//��ϵ������
			SortContact(&con);
			break;
		case 0:
			DestroyContact(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (i);
	return 0;
}