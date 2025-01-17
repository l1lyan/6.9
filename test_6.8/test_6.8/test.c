#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//实现一个通讯录
//人的信息：名字、年龄、性别、电话、地址
//存放100个人的信息
//增、删、查、改联系人
//排序
//显示联系人
enum
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};
void menu()
{
	printf("****************************\n");
	printf("*****1.add     2.del   *****\n");
	printf("*****3.search  4.modify*****\n");
	printf("*****5.show    6.sort  *****\n");
	printf("*****0.exit            *****\n");
	printf("****************************\n");
}
//动态版本
//通讯录默认能存放3个人的信息
//如果空间不够，就增加空间，每次增加2个人的空间
int main()
{
	int input = 0;

	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);
	return 0;
}