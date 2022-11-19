// RK_25032022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include "Rect.h"
#pragma warning(disable : 4996)

using namespace std;

int main()
{
    system("chcp 65001");

    cout << "Пункт №2" << endl;

    Rect T1(1, 1);

    // Перегрузка 1-ой арифмеичской операции
    cout << "T1: " << T1 << endl;
    //T1--;
    cout << "T1: " << T1-- << endl;
    //--T1;
    cout << "T1: " << --T1 << endl;


    // Перегрузка 2-ой арифмеичской операции
    Rect T2(2, 2);
    cout << "T2: " << T2 << endl;
    cout << "T2 * 10: " << T2 * 10 << endl;


    // Перегрузка операции сравнения
    // S1 = 10; S2 = 20;
    // 20 > 10 -> S2 > S1;
    Rect T3(10, 1), T31(4, 5);
    cout << "T3: " << T3 << endl;
    cout << "T31: " << T31 << endl;

    if (T3 < T31)
        cout << "T31 больше\n" << endl;
    else
        cout << "T3 больше\n" << endl;

    // Перегрузка операции потокового ввода и вывода
    Rect T4;

    cout << "Введите значения для Т4" << endl;
    cin >> T4;
    cout << T4;

    system("pause");

}
