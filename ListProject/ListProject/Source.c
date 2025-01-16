#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "list.h"


int main()
{
    setlocale(LC_ALL, "RUS");

    List mylist;
    InitList(&mylist);

    //�������� �� ������� ���������
    puts(IsEmpty(&mylist) ? "������ ������" : "������ ����� ��������");
    puts("");

    //���������� ��������� � ����� ������
    puts("���������� ��������� � ����� ������");
    AddLast(&mylist, 1, "������");
    AddLast(&mylist, 2, "����");
    AddLast(&mylist, 7, "�������");
    PrintList(mylist);
    puts("");

    //���������� ��������� ����� �������� � ��������� ������
    puts("���������� ��������� ����� �������� � ��������� ������");
    InsertBack_number(&mylist, 1, 10, "������");
    InsertBack_number(&mylist, 2, 30, "�����");
    InsertBack_number(&mylist, 6, 19, "���������");
    PrintList(mylist);
    puts("");

    //���������� ��������� ����� ��������� � ��������� ������
    puts("���������� ��������� ����� ��������� � ��������� ������");
    InsertFront_number(&mylist, 1, 8, "�����");
    InsertFront_number(&mylist, 10, 29, "���������");
    InsertFront_number(&mylist, 18, 10, "����������");
    PrintList(mylist);
    puts("");

    //���������� ��������� ����� �������� � ��������� �������
    puts("���������� ��������� ����� �������� � ��������� �������");
    InsertFront_name(&mylist, "����", 11, "�����");
    InsertFront_name(&mylist, "���������", 13, "���������");
    InsertFront_name(&mylist, "�����", 12, "���������");
    PrintList(mylist);
    puts("");

    //���������� ��������� ����� �������� � ��������� �������
    puts("���������� ��������� ����� �������� � ��������� �������");
    InsertBack_name(&mylist, "������", 25, "����");
    InsertBack_name(&mylist, "��������", 26, "������");
    InsertBack_name(&mylist, "�����������", 27, "������");
    PrintList(mylist);
    puts("");

    //��������� ��������� �� ���������� �����
    puts("��������� ��������� �� ���������� �����");
    PrintItem(GetItem_number(mylist, 1));
    PrintItem(GetItem_number(mylist, 10));
    PrintItem(GetItem_number(mylist, 5));
    PrintItem(GetItem_number(mylist, 13));
    PrintItem(GetItem_number(mylist, 29));
    puts("");
    
    //��������� ��������� �� ��������� ������
    puts("��������� ��������� �� ��������� ������");
    PrintItem(GetItem_name(mylist, "����������"));
    PrintItem(GetItem_name(mylist, "�������"));
    PrintItem(GetItem_name(mylist, "����"));
    PrintItem(GetItem_name(mylist, "�����"));
    PrintItem(GetItem_name(mylist, "�����"));
    puts("");

    //�������� ���������
    puts("�������� ���������");
    DestroyItem(&mylist, GetItem_number(mylist, 1));
    DestroyItem(&mylist, GetItem_number(mylist, 2));
    DestroyItem(&mylist, GetItem_number(mylist, 15));
    DestroyItem(&mylist, GetItem_number(mylist, 29));
    DestroyItem(&mylist, GetItem_number(mylist, 10));
    DestroyItem(&mylist, GetItem_number(mylist, 11));
    PrintList(mylist);
    puts("");

    //�������� �� ������� ���������
    puts(IsEmpty(&mylist) ? "������ ������" : "������ ����� ��������");
}