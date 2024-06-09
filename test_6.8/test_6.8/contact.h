#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3
#define INC_SZ 2

//类型的声明:人的信息：名字、年龄、性别、电话、地址
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录
typedef struct Contact
{
	PeoInfo* data;//存放人的信息              //需要改为指针
	int count;//记录当前通讯录中实际人的个数
	int capacity;//当前通讯录的容量
}Contact;

int InitContact(Contact* pc);
void DestoryContact(Contact* pc);

void AddContact(Contact* pc);
void ShowContact(const Contact* pc);
void DelContact(Contact* pc);
void SearchContact(Contact* pc);
void ModifyContact(Contact* pc);
void SortContact(Contact* pc);