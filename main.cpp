// RK_13.05.22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graduate.h"
#pragma warning(disable : 4996)

using namespace std;

int main()
{
    system("chcp 65001");

    cout << "Выпускники:" << endl;
    Graduate FN1[5];

    FN1[0] = { "Иванов В.В.", 5, 4, 6, 2005 };
    FN1[1] = { "Игнатьев А.И.", 4, 2, 6, 1997 };
    FN1[2] = { "Свидиров И.И.", 3, 1, 7, 1998 };
    FN1[3] = { "Дмитреев А.И.", 4, 4, 6, 1985 };
    FN1[4] = { "Тестов Т.Г.", 3, 7, 3, 2012 };

    //FN1[0] = { "TEST", 1, 4, 6, 6 };
    //cout << FN1[0] << endl;


    for (int i = 0; i < 5; i++) {
        cout << FN1[i] << endl;
    }

    // Изменение имена
    cout << "Был (Изменение имена): " << endl;
    cout << FN1[0] << endl;
    FN1[0].setName("Интернетов А.А.");
    cout << "Стало (Изменение имена): " << endl;
    cout << FN1[0] << endl;

    cout << "Был (РЕЙТИНГ): " << endl;
    cout << FN1[0] << endl;
    // Увеличение рейтинга
    FN1[0] += 3;
    cout << "Стало: " << endl << FN1[0] << endl;

}
