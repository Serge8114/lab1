#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListItem
{
    int number;
    char name[80];
    struct ListItem* next;
};

typedef struct ListItem* List;

void InitList(List* list);//������������� ������
void AddLast(List* head, int value, char* string);//���������� �������� � ����� ������
int IsEmpty(List* list);//�������� ������ �� ������� ���������
int Length(List list);//��������� ����� ������
void InsertFront_number(List* list, int value, int newNumber, char* newName);//������� ����� ����� � number = value
void InsertBack_number(List* list, int value, int newNumber, char* newName);//������� ����� ����� � number = value
void InsertFront_name(List* list, char* string, int newNumber, char* newName);//������� ����� ����� � name = str
void InsertBack_name(List* list, char* string, int newNumber, char* newName);//������� ����� ����� � name = str
void DestroyItem(List* list, struct ListItem* node);//�������� ��������� ���� node �� ������
List GetItem_number(List list, int n);//���������� ���� �� ��������� n � ���� number
List GetItem_name(List list, char* str);//���������� ���� �� ��������� str � ���� name
void PrintList(List list);//����� ������ �� �����
void PrintItem(List list);//����� ������ ������ �������� ������