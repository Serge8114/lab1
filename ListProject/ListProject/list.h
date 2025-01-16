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

void InitList(List* list);//Инициализация списка
void AddLast(List* head, int value, char* string);//Добавление элемента в конец списка
int IsEmpty(List* list);//Проверка списка на наличие элементов
int Length(List list);//Получение длины списка
void InsertFront_number(List* list, int value, int newNumber, char* newName);//Вставка перед узлом с number = value
void InsertBack_number(List* list, int value, int newNumber, char* newName);//Вставка после узлом с number = value
void InsertFront_name(List* list, char* string, int newNumber, char* newName);//Вставка перед узлом с name = str
void InsertBack_name(List* list, char* string, int newNumber, char* newName);//Вставка после узлом с name = str
void DestroyItem(List* list, struct ListItem* node);//Удаление заданного узла node из списка
List GetItem_number(List list, int n);//Нахождение узла со значением n в поле number
List GetItem_name(List list, char* str);//Нахождение узла со значением str в поле name
void PrintList(List list);//Вывод списка на экран
void PrintItem(List list);//Вывод только одного элемента списка