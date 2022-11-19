#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_PRODUCT_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_PRODUCT_H

#pragma once

#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

using namespace std;

/*
Вариант 4.

Product: Наименование – char*, Единицы измерений – char*, Количество – int:
а) создать объект класса, с заданными значениями;
на основе этого объекта создать новый объект, у которого обнулить количество;
вывести на экран оба объекта;

б) создать объект, значения данных задает пользователь;
используя функцию, сравнить количество с заданном пользователем и
если количество продукта меньше, то сообщить об этом.

в) пользователь задает значения; вызывается функция,
которая возвращает объект с заданными пользователем данными;
распечатать объект.

*/



class Product
{
private:
    // Наименование
    char* designation;
    // Единицы измерения
    char* units;
    // Количество
    int count;

    static int check_count;
    static bool check_count_bool;
    /*
    К такому классу можно привести пример - продукт питания (Потребительская корзина).
    Пусть наименование будут:
        хлебные продукты, картофель, мясопродукты, молоко и молокопродукты и т .д
    Пусть единицы измерения будет:
        килограмм, штук (яйцо) и т.д.
    Пусть количество будут:
        Для трудоспособных населения - 126 кг картофеля за год, и т.д.

    */
public:
    // Объект класса, с заданными нулевыми значениями;
    Product() {
        designation = new char[1];
        strcpy_s(designation, 1, "");

        units = new char[1];
        strcpy_s(units, 1, "");

        count = 0;

        check_count++;
        if (check_count_bool)
            cout << "CONSTRUCTION; count: " << check_count << endl;
    }

    // Объект, значения данных задает пользователь;
    Product(const char* _designation, const char* _units, int _count) {

        designation = new char[strlen(_designation) + 1];
        strcpy_s(designation, strlen(_designation) + 1, _designation);

        units = new char[strlen(_units) + 1];
        strcpy_s(units, strlen(_units) + 1, _units);

        count = _count;

        check_count++;
        if (check_count_bool)
            cout << "CONSTRUCTION; count: " << check_count << endl;
    }

    // конструктор копирования
    Product(const Product& obj) {
        // копирование данных из одного объекта в другой
        designation = new char[strlen(obj.designation) + 1];
        strcpy_s(designation, strlen(obj.designation) + 1, obj.designation);

        units = new char[strlen(obj.units) + 1];
        strcpy_s(units, strlen(obj.units) + 1, obj.units);

        count = obj.count;

        check_count++;
        if (check_count_bool)
            cout << "CONSTRUCTION; count: " << check_count << endl;
    }

    void show() { cout << designation << "\t" << units << "\t" << count << endl; };

    // перегрузка оператора присваивания
    Product& operator=(const Product& obj)
    {
        if (this != &obj)
        {
            delete[] designation;
            delete[] units;

            designation = new char[strlen(obj.designation) + 1];
            strcpy_s(designation, strlen(obj.designation) + 1, obj.designation);

            units = new char[strlen(obj.units) + 1];
            strcpy_s(units, strlen(obj.units) + 1, obj.units);

            count = obj.count;
        }
        return *this;
    }

    // Деструктор, в котором освобождается память
    ~Product() {
        //cout << "DELETE" << endl;
        //this->show();

        delete[] designation;
        delete[] units;

        check_count--;
        if (check_count_bool)
            cout << "DESTRUCTION; count: " << check_count << endl;
    }

    void set_designation(char* _designation);
    void set_designation(const char* _designation);
    void set_units(char* _units);
    void set_units(const char* _units);
    void set_count(int _count);

    char* get_designation();
    char* get_units();
    int get_count();
};

void check_comparison(Product FT, Product SC);


// Функция, которая возвращает объект
Product fun_set_full(char* designation, char* units, int count);

Product fun_set_full(const char* designation, const char* units, int count);

char* fun_get_designation(Product& PR);

char* fun_get_units(Product PR);

int fun_get_count(Product PR);

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_PRODUCT_H
