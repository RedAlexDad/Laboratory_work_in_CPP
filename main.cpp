// LAB_06_Template.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#include <string.h>

// #pragma warning(disable : 4996)

using namespace std;

//Для всех любых параметров
template <class T>
void find_short_string_fun(T* arr, int size) {
    cout << "Вызов функции специализации с незивестным типом" << endl;
    char* tmp = nullptr;
    int tmp1 = NULL, tmp2 = NULL;
    for (int i = 0; i < size - 1; i++) {
        tmp1 = strlen(arr[i]);
        tmp2 = strlen(arr[i + 1]);

        if (tmp1 < tmp2)
            tmp = arr[i];
    }
    cout << "Самая короткая строка: " << tmp << endl;
}

// Шаблон функции с специализациями
// Примечание, чтобы работала специализация, её нужно написать в основном заголовочном файле,
// т.е. где присутствует главная функция, int / void main() {...}
//

//Для string
template <>
void find_short_string_fun <string>(string* arr, int size) {
    cout << "Вызов функции специализации с типом string" << endl;
    string tmp;
    int tmp1 = NULL, tmp2 = NULL;
    for (int i = 0; i < size - 1; i++) {
        tmp1 = arr[i].size();
        tmp2 = arr[i + 1].size();

        if (tmp1 < tmp2)
            tmp = arr[i];
    }
    cout << "Самая короткая строка: " << tmp << endl;
}

//Для char
template <>
void find_short_string_fun <char>(char* arr, int size) {
    //template <> void find_short_string_fun <string>(string* arr, int size) {
    char* tmp = nullptr;
    int tmp1 = NULL, tmp2 = NULL;
    for (int i = 0; i < size - 1; i++) {
        cout << "arr[ " << i << " ] : " << arr[i] << endl;
        cout << "arr[ " << i + 1 << " ] : " << arr[i+1] << endl;
        cout << "&arr[ " << i << " ] : " << &arr[i] << endl;
        cout << "&arr[ " << i + 1 << " ] : " << &arr[i+1] << endl;
        tmp1 = strlen(&arr[i]);
        tmp2 = strlen(&arr[i + 1]);

        if (tmp1 < tmp2)
            tmp = &arr[i];
    }
    cout << "Самая короткая строка: " << tmp << endl;
}

int main()
{
    system("chcp 65001");
    cout << "Лабораторная работа № 6\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    cout << "№1.	2.1.3.	Макрокоманды и переменные этапа компиляции" << endl;
    cout << "№2.	2.1.4.	Шаблоны функции Swap" << endl;
    cout << "№3.	2.1.5.	Шаблон функции с несколькими параметрами (по варианту)" << endl;
    cout << "№4.	2.1.6.	Специализация шаблона функции" << endl;
    cout << "№5.	2.1.7.	Шаблон класса с внутренними методами с одним параметром" << endl;
    cout << "№6.	2.1.8.	Шаблон класса с внутренними методами с двумя параметрами" << endl;
    cout << "№7.	2.1.9.	Шаблон класса с внешним описанием методов и двумя параметрами" << endl;
    cout << "№8.	2.1.10.	Описание нового класса на основе шаблона класса" << endl;
    cout << "№9.	2.1.11.	Описание нового шаблона класса на основе шаблона класса" << endl;
    cout << "№10.	2.1.12.	Задание нового типа на основе шаблона (typedef)" << endl;
    cout << "№0.	Выход с программы" << endl;

    int sw;

    cout << "Введите номер пункт: ";
    cin >> sw;

    switch (sw)
    {

        case 1: {
            system("cls");
            cout << "№1.	2.1.3.	Макрокоманды и переменные этапа компиляции" << endl;

            int mas[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            //int RAZM = sizeof(mas) / sizeof(int);

            int sum = 0;
            //SUM_MAS(sum, mas, RAZM);
            int size = RAZM;
            for (int i = 0; i < size; i++)
                sum += mas[i];

            cout << "Сумма всех элементов массивы: " << sum << endl;

            int x, y;
            x = 10;
            y = 20;

            cout << "До SWAP" << endl;
            cout << "x = " << x << "; y = " << y << endl;
            SWAPI(x, y);
            cout << "После SWAP" << endl;
            cout << "x = " << x << "; y = " << y << endl;

            int a, b, c;
            a = 1; b = 2; c = 3;
            cout << "a = " << a << "; b = " << b << "; c = " << c << ";" << endl;
            cout << "Сумма трех элементов (через макрос): " << SUM3(a, b, c) << endl << endl;

            break;
        }
        case 2: {
            system("cls");
            cout << "№2.	2.1.4.	Шаблоны функции Swap" << endl;

            int x, y;
            x = 10;
            y = 20;


            cout << "Целый тип (указатель):" << endl;
            cout << "До SWAP" << endl;
            cout << "x = " << x << "; y = " << y << endl;
            SWAP<int>(x, y);
            cout << "После SWAP" << endl;
            cout << "x = " << x << "; y = " << y << endl;


            double z, d;
            z = 3.1416;
            d = 1.474;


            cout << "Вещественный тип (указатель):" << endl;
            cout << "До SWAP" << endl;
            cout << "z = " << z << "; d = " << d << endl;
            SWAP<double>(z, d);
            cout << "После SWAP" << endl;
            cout << "z = " << z << "; d = " << d << endl;


            break;
        }
        case 3: {
            system("cls");
            cout << "№3.	2.1.5.	Шаблон функции с несколькими параметрами (по варианту)" << endl;


            /*
            Сумма int = 15
            Сумма float =  19.6
            Сумма double =  15.6
            */

            int mas_i[10] = { 1, 2, 3, 4, 0, 6, 7, 8, 9, 10 };

            cout << "Минимальный элемент массива(целочисленный тип): " << min_mas_fun<int, 10>(mas_i) << endl;

            float mas_f[10] = { 2.23, 3.52, 4.16, 5.77, 9.3, 8.9, 7.97, 6.78, 3.12, 1.77 };

            cout << "Минимальный элемент массива(вещественный тип): " << min_mas_fun<float, 10>(mas_f) << endl;


            double mas_d[10] = { 1.123, 2.756, 3.1416, 4.3777, 0.13, 6.199, 7.889, 8.1678, 9.431, 10.13677 };

            cout << "Минимальный элемент массива(вещественный тип): " << min_mas_fun<double, 10>(mas_d) << endl;

            break;
        }
        case 4: {
            system("cls");
            cout << "№4.	2.1.6.	Специализация шаблона функции" << endl;

            // string (самая короткая строка)
            string PlanetsS[] = {"Меркурий", "Венера", "Земля", "Марс", "Юпитер", "Сатурн", "Уран", "Нептун"};
            char PlanetsC[][20] = {"Меркурий", "Венера", "Земля", "Марс", "Юпитер", "Сатурн", "Уран", "Нептун"};


            cout << "Строка: " << endl;
            for (int i = 0; i < 8; i++)
                cout << PlanetsS[i] << ' ';
            cout << endl << endl;

            cout << "Короткая строка: " << endl;
            // Вызов функции спецализации с известным типом
            find_short_string_fun<string>(PlanetsS, 8);
            // Вызов функции специализации с неизвестным типом
            find_short_string_fun(PlanetsC, 8);

            break;
        }
        case 5: {
            system("cls");
            cout << "№5.	2.1.7.	Шаблон класса с внутренними методами с одним параметром" << endl << endl;


            Line<int> AI(1, 2, 3);
            AI.show();
            cout << "Функция y: " << AI.getY() << endl << endl;
            cout << AI << endl;

            Line<double> AD(1.123456, 2.87654, 3.1416);
            AD.show();
            cout << "Функция y: " << AD.getY() << endl << endl;
            cout << AD << endl;

            Line<float> AF(9.556, 6.2354, 5.6);
            AF.show();
            cout << "Функция y: " << AF.getY() << endl << endl;
            cout << AF << endl;

            break;
        }
        case 6: {
            system("cls");
            cout << "№6.	2.1.8.	Шаблон класса с внутренними методами с двумя параметрами" << endl << endl;

            Line_color<int> AI(1, 2, 3, 0);
            //AI.show();
            cout << "Функция y: " << AI.getY() << endl << endl;
            cout << AI << endl;

            Line_color<double> AD(1.123456, 2.87654, 3.1416, 2);
            //AD.show();
            cout << "Функция y: " << AD.getY() << endl << endl;
            cout << AD << endl;

            Line_color<float> AF(9.556, 6.2354, 5.6, 1);
            //AF.show();
            cout << "Функция y: " << AF.getY() << endl << endl;
            cout << AF << endl;

            break;
        }
        case 7: {
            system("cls");
            cout << "№7.	2.1.9.	Шаблон класса с внешним описанием методов и двумя параметрами" << endl;

            Line_color_out<long> AL(49235756, 821231235, 568216473, 0);
            //AL.show();
            cout << "Функция y: " << AL.getY() << endl << endl;
            cout << AL << endl;

            break;
        }
        case 8: {
            system("cls");
            cout << "№8.	2.1.10.	Описание нового класса на основе шаблона класса" << endl;

            //Line_color_out<int> A1(1, 2, 3, 1);
            //Line_color_out<double> A2(1.867, 2.1, 3.78, 1);
            //A1.show();
            //A2.show();
            derived A1_d(1.423, 324.2, 543.14, "красный");
            cout << A1_d << endl;

            //int color = A1_d.FillColor("зеленый");

            break;
        }
        case 9: {
            system("cls");
            cout << "№9.	2.1.11.	Описание нового шаблона класса на основе шаблона класса" << endl;

            derived_with_template<double> A1_d_template(3.423, 424.2, 243.14, "красный");
            cout << A1_d_template << endl;

            derived_with_template<float> A2_f_template(1.423, 324.2, 543.14, "зеленый");
            cout << A2_f_template << endl;

            derived_with_template<int> A3_d_template(4, 9, 2, "синий");
            cout << A3_d_template << endl;

            break;
        }
        case 10: {
            system("cls");
            cout << "№10.	2.1.12.	Задание нового типа на основе шаблона (typedef)" << endl;

            typedef Line_color_out<int> CCO_INT;
            CCO_INT A1I(1, 4, 7, 0);
            //A1I.show();
            cout << A1I << endl;

            break;
        }
        case 0:
        {
            cout << "Выход с программы" << endl;
            system("pause");
            break;
        }
        default:
        {
            cout << "Ошибка! Неизвестная команда!" << endl;
            system("pause");
            break;
        }
    }

}
