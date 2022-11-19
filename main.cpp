// LAB_07_Virtual_function.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

// Счетчик для идентификатора
int Abstract::count = 0;

int main()
{

    system("chcp 65001");
    cout << "Лабораторная работа № 7\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    cout << "№1.	2.1.2.	Проверка описания объекта абстрактного класса" << endl;
    cout << "№2.	2.1.3.	Проверка созданных классов – описание объектов" << endl;
    cout << "№3.	2.1.4.	Проверка вызова функции через объекты" << endl;
    cout << "№4.	2.1.5.	Проверка вызова функции через указатель на объект" << endl;
    cout << "№5.	2.1.6.	Проверка виртуального вызова функции " << endl;
    cout << "№6.	2.1.7.	Создать динамический массив указателей на абстрактный базовый класс" << endl;
    cout << "№7.	2.1.8.	Распечатка массива объектов с помощью виртуального вызова" << endl;
    cout << "№8.	2.1.9.	Виртуальные деструкторы " << endl;
    cout << "№9.	2.1.10.	Виртуальные классы(по своему варианту)" << endl;
    cout << "№0.	Выход с программы" << endl;

    int sw;

    cout << "Введите номер пункт: ";
    cin >> sw;

    switch (sw)
    {
        case 1: {
            system("cls");
            /*ПРОВЕРКА ОБЪЕКТОВ АБСТРАКТНОГО КЛАССА.
            Проверить в главной программе описание объектов для абстрактного класса. */
            cout << "№1.	2.1.2.	Проверка описания объекта абстрактного класса" << endl;
            cout << "Проверяем вызова абстрактнного класса для всех классов" << endl;

            // a = (3, 2); b = (10, 2); c = (6, 7);
            cout << "Координат" << endl;
            coordinate C1(3, 2, 10, 2, 6, 7);
            //cout << C1 << endl;
            C1.show();
            cout << endl;


            cout << "Линии" << endl;
            // Координаты отрезка и выводит длину отрезка
            segment S1(7, 0, 3, 5, 4, -5);
            //cout << S1 << endl;
            S1.show();
            cout << endl;

            cout << "Линии" << endl;
            // Длина отрезка
            segment S2(4, 3, 5);
            //cout << S2 << endl;
            S2.show();
            cout << endl;

            cout << "Площадь треугольника" << endl;
            // Площадь треугольника
            triangle T1(4, 5, 4);
            //cout << T1 << endl;
            T1.show();
            cout << endl;

            triangle T2(4, 5, 4, 6,1,6);
            //cout << T1 << endl;
            T2.show();
            cout << endl;

            break;
        }
        case 2: {
            system("cls");
            cout << "№2.	2.1.3.	Проверка созданных классов – описание объектов" << endl;

            // Создадим объект абстрактного класса
            Abstract* pointer_ABS = nullptr;

            // a = (3, 2); b = (10, 2); c = (6, 7);
            coordinate C1(3, 2, 10, 2, 6, 7);
            // Длина отрезка
            segment S1(4, 3, 5);
            // Площадь треугольника
            triangle T1(4, 5, 4);

            break;
        }
        case 3: {
            system("cls");
            cout << "№3.	2.1.4.	Проверка вызова функции через объекты" << endl;

            // a = (3, 2); b = (10, 2); c = (6, 7);
            coordinate C1(3, 2, 10, 2, 6, 7);
            // Длина отрезка
            segment S1(4, 3, 5);
            // Площадь треугольника
            triangle T1(4, 5, 4);

            C1.show();
            S1.show();
            T1.show();

            break;
        }
        case 4: {
            system("cls");
            cout << "№4.	2.1.5.	Проверка вызова функции через указатель на объект" << endl;

            // a = (3, 2); b = (10, 2); c = (6, 7);
            coordinate C1(3, 2, 10, 2, 6, 7);
            // Длина отрезка
            segment S1(4, 3, 5);
            // Площадь треугольника
            triangle T1(4, 5, 4);

            C1.show();
            S1.show();
            T1.show();

            coordinate* pointer_C1 = &C1;
            segment* pointer_S1 = &S1;
            triangle* pointer_T1 = &T1;


            // Проверка объекта класса через указателя
            pointer_C1->show();

            pointer_S1->show();

            pointer_T1->show();

            break;
        }
        case 5: {
            system("cls");
            cout << "№5.	2.1.6.	Проверка виртуального вызова функции " << endl;

            // Создадим объект абстрактного класса
            Abstract* pointer_ABS = nullptr;

            // a = (3, 2); b = (10, 2); c = (6, 7);
            coordinate C1(3, 2, 10, 2, 6, 7);
            // Длина отрезка
            segment S1(4, 3, 5);
            // Площадь треугольника
            triangle T1(4, 5, 4);

            C1.show();
            S1.show();
            T1.show();

            coordinate* pointer_C1 = &C1;
            segment* pointer_S1 = &S1;
            triangle* pointer_T1 = &T1;


            // Проверка объекта класса через указателя
            pointer_C1->show();

            pointer_S1->show();

            pointer_T1->show();

            // Проверка абстрактного класса через указателя
            pointer_ABS = &C1;
            pointer_ABS->show();

            pointer_ABS = &S1;
            pointer_ABS->show();

            pointer_ABS = &T1;
            pointer_ABS->show();

            break;
        }
        case 6: {
            system("cls");
            cout << "№6.	2.1.7.	Создать динамический массив указателей на абстрактный базовый класс" << endl;

            // Создание массива абстрактного класса
            Abstract** Abstr = new Abstract*[6];

            Abstr[0] = new coordinate(1,2,3,4,5,6);
            Abstr[1] = new segment(9,8,7,6,5,4);
            Abstr[2] = new triangle(4,5,6);

            Abstr[3] = new coordinate(9,7,6,5,4,3);
            Abstr[4] = new segment(1,2,3,4,5,6);
            Abstr[5] = new triangle(6,8,9);

            delete[] Abstr;

            break;
        }
        case 7: {
            system("cls");
            cout << "№7.	2.1.8.	Распечатка массива объектов с помощью виртуального вызова" << endl;

            // Создание массива абстрактного класса
            Abstract** Abstr = new Abstract * [6];

            Abstr[0] = new coordinate(1, 2, 3, 4, 5, 6);
            Abstr[1] = new segment(9, 8, 7, 6, 5, 4);
            Abstr[2] = new triangle(4, 5, 6);

            Abstr[3] = new coordinate(9, 7, 6, 5, 4, 3);
            Abstr[4] = new segment(1, 2, 3, 4, 5, 6);
            Abstr[5] = new triangle(6, 8, 9);

            for (int i = 0; i < 6; i++) {
                Abstr[i]->show();
                cout << endl;
            }

            delete[] Abstr;

            break;
        }
        case 8: {
            system("cls");
            cout << "№8.	2.1.9.	Виртуальные деструкторы " << endl;

            // Создание массива абстрактного класса
            Abstract** Abstr = new Abstract * [6];

            Abstr[0] = new coordinate(1, 2, 3, 4, 5, 6);
            Abstr[1] = new segment(9, 8, 7, 6, 5, 4);
            Abstr[2] = new triangle(4, 5, 6);

            Abstr[3] = new coordinate(9, 7, 6, 5, 4, 3);
            Abstr[4] = new segment(1, 2, 3, 4, 5, 6);
            Abstr[5] = new triangle(6, 8, 9);

            for (int i = 0; i < 6; i++) {
                Abstr[i]->show();
                cout << endl;
            }

            // Прерывает цикл
            bool check = false;

            while (check == false) {
                for (int i = 0; i < 6; i++) {
                    delete Abstr[i];
                    cout << endl;
                }
                check = true;
            }

            break;
        }
        case 9: {
            system("cls");
            cout << "№9.	2.1.10.	Виртуальные классы(по своему варианту)" << endl;

            // ПЕРЕДЕЛАТЬ ЭТОТ ПУНКТ
            // A,F,C,D
            // A - Общие алфавиты, F - Французские алфавиты, C - Латинские алфавиты, D - Древнегреческие алфавиты
            A** ALPHAVIT = new A* [5];

            ALPHAVIT[0] = new A('A');
            ALPHAVIT[1] = new F('V','E'); // ɛ
            ALPHAVIT[2] = new C('E','Y'); // ī
            ALPHAVIT[3] = new D('U','I', 'H', 'M'); // δ
            ALPHAVIT[4] = new D('P','O', 'Q', 'J'); // γ

            for (int i = 0; i < 5; i++) {
                ALPHAVIT[i]->show();
            }

            D ALPHAVIT_D('Q','W','E','R');

            // A F C D

            cout << "ALPHAVIT_D.get_alphavit() = " << ALPHAVIT_D.get_alphavit() << endl;//Обращение к полю а класса (А3)как обычно в классе D3
            cout << endl;
            cout << "ALPHAVIT_D.A::get_alphavit() = " << ALPHAVIT_D.A::get_alphavit() << endl;  // Через класс  A прямо
            cout << "ALPHAVIT_D.F::get_alphavit() = " << ALPHAVIT_D.F::get_alphavit() << endl;  // Через класс  F прямо
            cout << "ALPHAVIT_D.C::get_alphavit() = " << ALPHAVIT_D.C::get_alphavit() << endl;  // Через класс  C прямо
            cout << "ALPHAVIT_D.D::get_alphavit()= "  << ALPHAVIT_D.D::get_alphavit() << endl;  // Через класс  D прямо
            cout << endl;
            cout << "ALPHAVIT_D.get_franc_al() = " << ALPHAVIT_D.get_franc_al() << endl;
            cout << "ALPHAVIT_D.get_latin_al() = " << ALPHAVIT_D.get_latin_al() << endl;
            cout << "ALPHAVIT_D.get_old_grec_al() = " << ALPHAVIT_D.get_old_grec_al() << endl;


            delete[] ALPHAVIT;

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
