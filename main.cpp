// RK_31.05.2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Class.h"

using namespace std;

int main()
{
    system("chcp 1251 >> null");

    cout << "ТЕСТ: " << endl;
    Flate obj(2, 4);
    cout << obj << endl;
    cout << "Площадь: " << obj.square() << endl;
    cout << endl;

    cout << "Создание объекта абстрактного класса: " << endl << endl;
    Space** base_obj = new Space*[4];

    base_obj[0] = new Room(1, 2);

    Room* first = new Room[3];
    first[0] = {1, 2};
    first[1] = {2, 3};
    first[2] = {4, 5};

    base_obj[1] = new Flate(first, 3);

    base_obj[2] = new Room(4, 5);

    Room* second = new Room[5];
    second[0] = { 6, 7 };
    second[1] = { 8, 9 };
    second[2] = { 10, 11 };
    second[3] = { 12, 13 };
    second[4] = { 14, 15 };

    base_obj[3] = new Flate(second, 5);

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        cout << endl;
        base_obj[i]->show();
        cout << endl;
        cout << "Площадь: " << base_obj[i]->square() << endl;
        // Сумма всех площадей
        sum = sum + base_obj[i]->square();
    }
    cout << "Сумма всех площадей: " << sum << endl;

    // Прерывает цикл
    bool check = false;

    // Освобождение памяти
    while (check == false) {
        for (int i = 0; i < 4; i++) {
            delete base_obj[i];
            cout << endl;
        }
        check = true;
    }

}
