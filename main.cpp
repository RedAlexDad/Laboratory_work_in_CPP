// LAB_03_overload_operation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

#include <iostream>
#include <istream>
#include <fstream>
#include <cstring>
#include "Product.h"

#pragma warning(disable : 4996)

using namespace std;

int Product:: check_count = 0;
// Переключать здесь true - false, чтобы увидеть комментарий конструкторов и деструкторов
bool Product::check_count_bool = false;

int main() {
    // system("chcp 1251 > nul");
    system("chcp 65001");
    cout << "Лабораторная работа № 3\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    cout << "Электроприборы товары" << endl;

    // Электроприборы товары
    // a)
    Product* Electrical_appliances_goods = new Product[2];

    Electrical_appliances_goods[0].show();
    Electrical_appliances_goods[0] = {"Телефон", "штук", 4};
    Electrical_appliances_goods[0].show();

    // на основе этого объекта создать новый объект, у которого обнулить количество;
    Product OBJ;
    Product New_obj(OBJ);

    // Печать нового объекта
    cout << "New_obj: ";
    New_obj.show();

    // б)
    char* buff_char = new char[1000];
    char* buff_char1 = new char[1000];
    cout << "Введите наименование, единицы измерения и количество для электроприборов товаров" << endl;
    cout << "Наименование: ";
    cin >> buff_char;

    cout << "Единицы измерения: ";
    cin >> buff_char1;

    int* buff_int = new int;
    cout << "Количество: ";
    cin >> *buff_int;

    // Вызов функции, которая возвращает объект
    Electrical_appliances_goods[1] = fun_set_full(buff_char, buff_char1, *buff_int);

    // Освобождение памяти
    delete[] buff_char;
    delete[] buff_char1;
    delete buff_int;

    Electrical_appliances_goods[1].show();

    // Сравниваем, у какого наименования больше
    check_comparison(Electrical_appliances_goods[1], Electrical_appliances_goods[0]);

    // Освобождаем памяти
    delete[] Electrical_appliances_goods;

    // в)

    Product* Electrical_appliances_goods_1 = new Product[10];

    Electrical_appliances_goods_1[0] = { "Кнопка", "штук", 150 };
    Electrical_appliances_goods_1[1] = { "Моноблок", "штук", 2 };
    Electrical_appliances_goods_1[2] = { "Телевизор", "штук", 5 };
    Electrical_appliances_goods_1[3] = { "Чайник", "штук", 10 };
    Electrical_appliances_goods_1[4] = { "Клавиатура", "штук", 4 };
    Electrical_appliances_goods_1[5] = { "Мышь", "штук", 8 };
    Electrical_appliances_goods_1[6] = { "Ноутбук", "штук", 4 };
    Electrical_appliances_goods_1[7] = { "Флэш-накопитель", "штук", 30 };
    Electrical_appliances_goods_1[8] = { "Зарядное устройство", "штук", 100 };
    Electrical_appliances_goods_1[9] = { "Батарейка", "штук", 500 };

    for (int i = 0; i < 10; i++)
        Electrical_appliances_goods_1[i].show();

    cout << endl << endl;

    char* buff = new char[100];

    cout << "Введите наименование, чтобы найти: ";
    cin >> buff;

    char* find_designation = new char[strlen(buff) + 1];
    strcpy_s(find_designation, strlen(buff) + 1, buff);
    delete[] buff;
    // Сообщение о предупреждении о отсутствии наименований
    bool check_warn = true;

    for (int i = 0; i < 10; i++) {
        if (strcmp(find_designation, fun_get_designation(Electrical_appliances_goods_1[i])) == 0) {
            Electrical_appliances_goods_1[i].show();
            check_warn = false;
        }
    }

    if (check_warn)
        cout << "Введенное наименование не найдено" << endl;


    delete[] find_designation;
    delete[] Electrical_appliances_goods_1;

    system("pause");
}
