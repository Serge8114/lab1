#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//������������� ������
void InitList(List* list)
{
    *list = NULL;
}

//���������� �������� � ����� ������
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

//�������� ������ �� ������� ���������
int IsEmpty(List* list)
{
    return *list == NULL;
}

//��������� ����� ������
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

//������� ����� ����� � number = value
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

            if (current == *list) // ������� ����� ������ �����
            {
                new_item->next = *list;

                // ����� ��������� ����
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

//������� ����� ���� � number = value
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

//������� ����� ����� � name = str
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

//������� ����� ���� � name = str
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

//�������� ��������� ���� node �� ������
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

//���������� ���� �� ��������� n � ���� number
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

//���������� ���� �� ��������� str � ���� name
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

//����� ������ �� �����
void PrintList(List list)
{
    if (!list)
    {
        printf("������ ����.\n");
        return;
    }

    printf("������ �������� %d ���������:\n", Length(list));
    List current = list;
    do
    {
        printf("�����: %d, ������: %s\n", current->number, current->name);
        current = current->next;
    } while (current != list);
}

//����� ������ ������ �������� ������
void PrintItem(List list)
{
    if (list != NULL)
        printf("�����: %d, ������: %s\n", list->number, list->name);
}