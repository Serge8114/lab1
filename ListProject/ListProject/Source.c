#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "list.h"


int main()
{
    setlocale(LC_ALL, "RUS");

    List mylist;
    InitList(&mylist);

    //Проверка на наличие элементов
    puts(IsEmpty(&mylist) ? "Список пустой" : "Список имеет элементы");
    puts("");

    //Добавление элементов в конец списка
    puts("Добавление элементов в конец списка");
    AddLast(&mylist, 1, "Андрей");
    AddLast(&mylist, 2, "Иван");
    AddLast(&mylist, 7, "Дмитрий");
    PrintList(mylist);
    puts("");

    //Добавление элементов после элемента с указанным числом
    puts("Добавление элементов после элемента с указанным числом");
    InsertBack_number(&mylist, 1, 10, "Михаил");
    InsertBack_number(&mylist, 2, 30, "Мария");
    InsertBack_number(&mylist, 6, 19, "Екатерина");
    PrintList(mylist);
    puts("");

    //Добавление элементов перед элементом с указанным числом
    puts("Добавление элементов перед элементом с указанным числом");
    InsertFront_number(&mylist, 1, 8, "Данил");
    InsertFront_number(&mylist, 10, 29, "Владислав");
    InsertFront_number(&mylist, 18, 10, "Константин");
    PrintList(mylist);
    puts("");

    //Добавление элементов после элемента с указанной строкой
    puts("Добавление элементов после элемента с указанной строкой");
    InsertFront_name(&mylist, "Иван", 11, "Ольга");
    InsertFront_name(&mylist, "Владислав", 13, "Станислав");
    InsertFront_name(&mylist, "Игнат", 12, "Анастасия");
    PrintList(mylist);
    puts("");

    //Добавление элементов после элемента с указанной строкой
    puts("Добавление элементов после элемента с указанной строкой");
    InsertBack_name(&mylist, "Андрей", 25, "Юлия");
    InsertBack_name(&mylist, "Виктория", 26, "Никита");
    InsertBack_name(&mylist, "Невероятный", 27, "Максим");
    PrintList(mylist);
    puts("");

    //Получение элементов по указанному числу
    puts("Получение элементов по указанному числу");
    PrintItem(GetItem_number(mylist, 1));
    PrintItem(GetItem_number(mylist, 10));
    PrintItem(GetItem_number(mylist, 5));
    PrintItem(GetItem_number(mylist, 13));
    PrintItem(GetItem_number(mylist, 29));
    puts("");
    
    //Получение элементов по указанной строке
    puts("Получение элементов по указанной строке");
    PrintItem(GetItem_name(mylist, "Нереальный"));
    PrintItem(GetItem_name(mylist, "Дмитрий"));
    PrintItem(GetItem_name(mylist, "Иван"));
    PrintItem(GetItem_name(mylist, "Мария"));
    PrintItem(GetItem_name(mylist, "Ольга"));
    puts("");

    //Удаление элементов
    puts("Удаление элементов");
    DestroyItem(&mylist, GetItem_number(mylist, 1));
    DestroyItem(&mylist, GetItem_number(mylist, 2));
    DestroyItem(&mylist, GetItem_number(mylist, 15));
    DestroyItem(&mylist, GetItem_number(mylist, 29));
    DestroyItem(&mylist, GetItem_number(mylist, 10));
    DestroyItem(&mylist, GetItem_number(mylist, 11));
    PrintList(mylist);
    puts("");

    //Проверка на наличие элементов
    puts(IsEmpty(&mylist) ? "Список пустой" : "Список имеет элементы");
}