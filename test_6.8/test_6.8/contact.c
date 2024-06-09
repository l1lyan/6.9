#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	//memset(pc->data, 0, sizeof(pc->data));
	pc->data = (PeoInfo*)calloc(3, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	return 0;
}

void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc = NULL;
}

void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	//����
	CheckCapacity(pc);
	printf("������������>");
	scanf("%s", pc->data[pc->count].name);
	printf("���������䣺>");
	scanf("%d", &pc->data[pc->count].age);//ȡ��ַ��
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->count].tele);
	printf("������סַ��>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].age, pc->data[i].sex,
			pc->data[i].tele, pc->data[i].addr);
	}
}

int FindName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	
	return -1;
}
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	char name[MAX_NAME];
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڴ���\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڴ���\n");
		return;
	}
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "סַ");
	printf("%20s\t%5d\t%5s\t%12s\t%30s\n", pc->data[pos].name,
		pc->data[pos].age, pc->data[pos].sex,
		pc->data[pos].tele, pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (pos == -1)
	{
		printf("ͨѶ¼�в����ڴ���\n");
		return;
	}
	printf("������������>");
	scanf("%s", pc->data[pos].name);
	printf("���������䣺>");
	scanf("%d", &pc->data[pos].age);//ȡ��ַ��
	printf("�������Ա�>");
	scanf("%s", pc->data[pos].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pos].tele);
	printf("������סַ��>");
	scanf("%s", pc->data[pos].addr);
}
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ�\n");
}