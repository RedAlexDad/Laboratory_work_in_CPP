#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_INPUT_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_INPUT_H

#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

/*
* Задание№1

Написать шаблон функции, оторая возвращает количество отрицательных элементов в заданном массиве.
Шаблонный параметр функции - тип данных массива.
Продемонстрировать вызов этой фунции с разными типами параметров int, float, double.
*/

template <class T, int size>
int count_otr_value(T* arr) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) count++;
    }
    return count;
}

template <class T, int size>
void show_arr(T* arr) {
    for (int i = 0; i < size; i++)
        cout << "arr[ " << i << " ] : " << arr[i] << endl;
}


// Задание №2

template <class T>
class Input {
private:
    T min_elem;
    T max_elem;

public:
    Input();

    // input ob("строка_приглашение", мин_значение, макс_значение)
    Input(const char* str, T min_el, T max_el);

    ~Input();

    T get_min_elem();
    T get_max_elem();

    template <class A>
    friend ostream& operator<<(ostream& out, Input<A>& obj);
};

template <class T>
Input<T>::Input() { min_elem = 0; max_elem = 0; }

template <class T>
T Input<T>::get_min_elem() { return min_elem; }

template <class T>
T Input<T>::get_max_elem() { return max_elem; }

template <class T>
Input<T>::Input(const char* str, T min_el, T max_el) {
    cout << "CONSTRUCTION" << endl;
    cout << str << endl;

    bool check = false;
    min_elem = min_el; max_elem = max_el;

    if (min_el != max_el)
        while (check == false) {
            cout << str << endl;

            cout << "Введите минимальное значение. \nМинимальное значение: ";
            cin >> min_el;
            cout << endl;

            cout << "Введите максимальное значение.\nМаксимальное значение: ";
            cin >> max_el;
            cout << endl;

            if (min_el != max_el) {
                cout << "Введенные пользователем не совпадают!" << endl;
            }
            else {
                min_elem = min_el; max_elem = max_el;
                cout << "Введенные пользователем совпадают!" << endl;
                cout << "Минимальное значение: " << min_elem << endl
                     << "Максимальное значение: " << max_elem << endl;
                check = true;
            }
        }
    else {
        min_elem = min_el; max_elem = max_el;
        cout << "Введенные пользователем совпадают!" << endl;
        cout << "Минимальное значение: " << min_elem << endl
             << "Максимальное значение: " << max_elem << endl;
        //cout << ob << endl;
        check = true;
    }

}

template <class T>
Input<T>::~Input() { cout << "DESTRUSTION" << endl; }

template <class T>
ostream& operator<<(ostream& out, Input<T>& obj) {
    out << "Минимальное значение: " << obj.get_min_elem() << endl
        << "Максимальное значение: " << obj.get_max_elem() << endl;

    return out;
}

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_INPUT_H
