#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//ʵ��һ��ͨѶ¼
//�˵���Ϣ�����֡����䡢�Ա𡢵绰����ַ
//���100���˵���Ϣ
//����ɾ���顢����ϵ��
//����
//��ʾ��ϵ��
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
//��̬�汾
//ͨѶ¼Ĭ���ܴ��3���˵���Ϣ
//����ռ䲻���������ӿռ䣬ÿ������2���˵Ŀռ�
int main()
{
	int input = 0;

	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);
	return 0;
}