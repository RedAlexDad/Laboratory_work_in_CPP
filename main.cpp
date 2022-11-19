// RK_Template_17.05.2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Input.h"
#pragma warning(disable : 4996)

using namespace std;

int main()
{
    system("chcp 65001");

    // Задание №1
    const int size = 5;

    int arr_int[size] = { 1, -5, 6, -1, 5 };
    show_arr<int, size>(arr_int);
    cout << "Количество отрицательных чисел: " << count_otr_value<int, size>(arr_int) << endl;

    double arr_double[size] = { 1.13, -123.5, -6.87, -8.2341, 7.35 };
    show_arr<double, size>(arr_double);
    cout << "Количество отрицательных чисел: " << count_otr_value<double, size>(arr_double) << endl;

    float arr_float[size] = { 1.15, -5.123, 26.88, 1.12, 5.771 };
    show_arr<float, size>(arr_float);
    cout << "Количество отрицательных чисел: " << count_otr_value<float, size>(arr_float) << endl;

    // Задание №2

    Input<int> ob();

    char str[] = {"Строка_приглашение целочисленного типа"};
    Input<int> ob1(str, 0, 1);
    cout << ob1 << endl;

    Input<double> ob2("Строка_приглашение double типа", 3.1416, 3.654);
    cout << ob2 << endl;

    Input<float> ob3("Строка_приглашение float типа", 543.12, 16.3);
    cout << ob2 << endl;

}
