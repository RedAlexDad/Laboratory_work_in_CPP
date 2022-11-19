#include "Header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Удаление всех пробел
void writeTextFile_delete_all_space(fstream& DB, string str) {
    string str_buff;

    DB.open("STRING.txt", ios_base::out);
    if (!DB)
        cout << "Файл открыть невозможно\n";

    // Цикл записи файла
    for (int i = 0; i < str.size(); i++) {
        // Запись в файл
        if (str[i] != ' ') {
            str_buff += str[i];
        }
    }
    DB << str_buff << endl;
    cout << "Результат:" << endl << str_buff << endl;

    DB.clear();
    // Закрытие файла
    DB.close();
}


// Работа с текстовым файлом и удаление некоторых пробелов

void writeTextFile_delete_some_space(fstream& DB, string str) {
    // Удаление некотрых пробелов за исключением пробел, который находится между слов
    string str_buff;

    DB.open("STRING.txt", ios_base::out);
    if (!DB)
        cout << "Файл открыть невозможно\n";


    // Проверяет наличие пробела, если есть несколько пробелов между слов, то true
    bool check_str = false;

    // Цикл записи файла
    for (int i = 0; i < str.size(); i++) {
        // Запись в файл
        if (str[i] != ' ') {
            str_buff += str[i];
            check_str = false;
        }
        else if (str[i] == ' ' && check_str == false) {
            str_buff += ' ';
            check_str = true;
        }
    }

    DB << str_buff << endl;
    cout << "Результат:" << endl << str_buff << endl;

    DB.clear();
    // Закрытие файла
    DB.close();
}

// Распечатка вектора
void print_vector(vector<int> vec, int size) {
    for (int i = 0; i < size; i++) {
        cout << "v [ " << i << " ] : " << vec[i] << endl;
    }
    cout << endl;
}

// Удвоение вектора
vector<int> vector_doubling(vector<int> vec, int size) {
    for (int i = 0; i < size; i++) {
        vec[i] = vec[i] * 2;
    }

    return vec;
}
