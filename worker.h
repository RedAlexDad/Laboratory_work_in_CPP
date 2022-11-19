#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_WORKER_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_WORKER_H

#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

class worker
{
private:
    // Дата поступления
    int year_work;
    // Зарплата
    int salary;
    // Фамилия и инициалы
    char FIO[100];
    // Должность
    char post[100];

public:
    // Устанавливает
    worker()
    {
        FIO[0] = '\0';
        post[0] = '\0';
        year_work = 0;
        salary = 0;

        count++;
        if (isPrint)
        {
            cout << "CONSTRUCTION; count: " << count << endl;
        }
    }

    worker(char* _fio, char* _post, int _year_work, int _salary)
    {
        strcpy(FIO, _fio);
        strcpy(post, _post);
        year_work = _year_work;
        salary = _salary;

        count++;
        if (isPrint)
        {
            cout << "CONSTRUCTION; count: " << count << endl;
        }
    }

    worker(const char* _fio, const char* _post, int _year_work, int _salary)
    {
        strcpy(FIO, _fio);
        strcpy(post, _post);
        year_work = _year_work;
        salary = _salary;

        count++;
        if (isPrint)
        {
            cout << "CONSTRUCTION; count: " << count << endl;
        }
    }

    void show() { cout << FIO << '\t' << post << '\t' << year_work << '\t' << salary << endl; };

    void set_year_work(int _year_work);
    void set_salary(int _salary);
    void set_FIO(char* _FIO);
    void set_FIO(const char* _FIO);
    void set_post(char* _post);
    void set_post(const char* _post);

    int get_year_work();
    int get_salary();
    char* get_FIO();
    char* get_post();

    ~worker()
    {
        count--;
        if (isPrint)
            cout << "DECONSTRUCTION; count: " << count << endl;
    }

    worker(const worker& _worker)
    {
        count++;
        if (isPrint)
            cout << "CONSTRUCTION COPY; count: " << count << endl;
        *this = _worker;
    }

    // Разрешение печати значения первой в конструкторах и деструкторе
    /*Серьезность	Код	Описание	Проект	Файл	Строка	Состояние подавления
    Ошибка	LNK2001	неразрешенный внешний символ "public:
    static bool worker::isPrint" (?isPrint@worker@@2_NA).
    LAB_02_Class	C:\Users\Alexey\source\repos\LAB_02_Class\LAB_02_Class.obj	1	*/
    // Решение проблемы - написать bool worker::isPrint = true; перед int main();
    static bool isPrint;

    //Cчетчик созданных объектов класса
    static int count;

    // Дружественная функция
    // Получение стаж года через дружественной функции
    friend int get_year_work_through_friend(worker _worker);
};

// Присваивание значение
void input(worker _WORK, char* _fio, const char* _post, int _year_work, int _salary);

// Присваивание значение константными значениями
void input(worker _WORK, const char* _fio, const char* _post, int _year_work, int _salary);

// Функция, которая возвращает обьект
worker output(worker work);

int fun_get_year_work(worker work);

int fun_get_salary(worker work);

char* fun_get_FIO(worker work);

char* fun_get_post(worker work);

// Функция принятия значения

void fun_set_year_work(worker& work, int year_work);

void fun_set_salary(worker& work, int salary);

void fun_set_FIO(worker& work, char* FIO);

void fun_set_FIO(worker& work, const char* FIO);

void fun_set_post(worker& work, char* post);

void fun_set_post(worker& work, const char* post);

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_WORKER_H
