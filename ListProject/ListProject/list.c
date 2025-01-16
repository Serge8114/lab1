#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Инициализация списка
void InitList(List* list)
{
    *list = NULL;
}

//Добавление элемента в конец списка
void AddLast(List* head, int value, char* string)
{
    List new_node = malloc(sizeof(struct ListItem));
    new_node->number = value;
    strncpy(new_node->name, string, 80);

    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        List current = *head;
        while (current->next != *head)
            current = current->next;

        current->next = new_node;
        new_node->next = *head;
    }
}

//Проверка списка на наличие элементов
int IsEmpty(List* list)
{
    return *list == NULL;
}

//Получение длины списка
int Length(List list)
{
    if (!list)
        return 0;

    int count = 1;
    List current = list->next;
    while (current != list)
    {
        count++;
        current = current->next;
    }
    return count;
}

//Вставка перед узлом с number = value
void InsertFront_number(List* list, int value, int newNumber, char* newName)
{
    if (*list == NULL)
        return;

    List current = *list;
    List prev = NULL;
    do
    {
        if (current->number == value)
        {
            List new_item = malloc(sizeof(struct ListItem));
            new_item->number = newNumber;
            strncpy(new_item->name, newName, 80);

            if (current == *list) // Вставка перед первым узлом
            {
                new_item->next = *list;

                // Найти последний узел
                List last = *list;
                while (last->next != *list)
                    last = last->next;

                last->next = new_item;
                *list = new_item;
            }
            else
            {
                new_item->next = current;
                prev->next = new_item;
            }
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *list);
}

//Вставка после узла с number = value
void InsertBack_number(List* list, int value, int newNumber, char* newName)
{
    if (*list == NULL)
        return;

    List current = *list;
    do
    {
        if (current->number == value)
        {
            List new_item = malloc(sizeof(struct ListItem));
            new_item->number = newNumber;
            strncpy(new_item->name, newName, 80);

            new_item->next = current->next;
            current->next = new_item;

            return;
        }
        current = current->next;
    } while (current != *list);
}

//Вставка перед узлом с name = str
void InsertFront_name(List* list, char* string, int newNumber, char* newName)
{
    if (*list == NULL)
        return;

    List current = *list;
    List prev = NULL;
    do
    {
        if (strcmp(current->name, string) == 0)
        {
            List new_item = malloc(sizeof(struct ListItem));
            new_item->number = newNumber;
            strncpy(new_item->name, newName, 80);

            if (current == *list)
            {
                new_item->next = *list;

                List last = *list;
                while (last->next != *list)
                    last = last->next;

                last->next = new_item;
                *list = new_item;
            }
            else
            {
                new_item->next = current;
                prev->next = new_item;
            }
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *list);
}

//Вставка после узла с name = str
void InsertBack_name(List* list, char* string, int newNumber, char* newName)
{
    if (*list == NULL)
        return;

    List current = *list;
    do
    {
        if (strcmp(current->name, string) == 0)
        {
            List new_item = malloc(sizeof(struct ListItem));
            new_item->number = newNumber;
            strncpy(new_item->name, newName, 80);

            new_item->next = current->next;
            current->next = new_item;

            return;
        }
        current = current->next;
    } while (current != *list);
}

//Удаление заданного узла node из списка
void DestroyItem(List* list, struct ListItem* node)
{
    if (*list == NULL || node == NULL)
        return;

    List current = *list;
    List prev = NULL;
    do
    {
        if (current == node)
        {
            if (current == *list && current->next == *list)
            {
                *list = NULL;
            }
            else
            {
                if (current == *list)
                {
                    List last = *list;
                    while (last->next != *list)
                        last = last->next;

                    *list = current->next;
                    last->next = *list;
                }
                else
                {
                    prev->next = current->next;
                }
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *list);
}

//Нахождение узла со значением n в поле number
List GetItem_number(List list, int n)
{
    if (!list)
        return NULL;

    List current = list;

    do
    {
        if (current->number == n)
            return current;

        current = current->next;
    } while (current != list);

    return NULL;
}

//Нахождение узла со значением str в поле name
List GetItem_name(List list, char* str)
{
    if (!list)
        return NULL;

    List current = list;
    do
    {
        if (strcmp(current->name, str) == 0)
            return current;

        current = current->next;
    } while (current != list);

    return NULL;
}

//Вывод списка на экран
void PrintList(List list)
{
    if (!list)
    {
        printf("Список пуст.\n");
        return;
    }

    printf("Список содержит %d элементов:\n", Length(list));
    List current = list;
    do
    {
        printf("Число: %d, Строка: %s\n", current->number, current->name);
        current = current->next;
    } while (current != list);
}

//Вывод только одного элемента списка
void PrintItem(List list)
{
    if (list != NULL)
        printf("Число: %d, Строка: %s\n", list->number, list->name);
}