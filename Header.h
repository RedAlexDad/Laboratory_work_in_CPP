#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;

// Работа с текстовым файлом и удаление всех пробел
void writeTextFile_delete_all_space(fstream& DB, string str);

// Работа с текстовым файлом и удаление некоторых пробелов
void writeTextFile_delete_some_space(fstream& DB, string str);

// Распечатка вектора
void print_vector(vector<int> vec, int size);

// Удвоение вектора
vector<int> vector_doubling(vector<int> vec, int size);


class Complex {
private:
    // Действительные числа
    double real_numbers;
    // Мнимые числа
    double imaginary;

public:

    Complex() { real_numbers = 0; imaginary = 0; }
    Complex(double REAL_NUMBER, double IMAGINARY) { real_numbers = REAL_NUMBER; imaginary = IMAGINARY; }
    //~Complex() { cout << "ДЕСТРУКТОР!" << endl; }

    /*
    -1.2 + i * 6.3
    4.1 + i * 0.7
    2.9 + i * 7.0
    */
    // Сложение комплексных чисел между объектами
    Complex& operator+(const Complex& obj) {
        Complex tmp;
        tmp.real_numbers = this->real_numbers + obj.real_numbers;
        tmp.imaginary = this->imaginary + obj.imaginary;
        return tmp;
    }

    // Сложение комплексных чисел с числом
    friend Complex& operator+(Complex& obj, const double value) {
        Complex tmp;
        tmp.real_numbers = obj.real_numbers + value;
        tmp.imaginary = obj.imaginary + value;
        return tmp;
    }

    /*
    Распечатать вектор в виде:
            -1.2 + i * 6.3
    */
    friend ostream& operator<<(ostream& out, Complex& obj) {
        if (obj.imaginary >= 0)
            out << obj.real_numbers << " + i * " << obj.imaginary << endl;
        else
            out << obj.real_numbers << " - i * " << abs(obj.imaginary) << endl;

        return out;
    }

};
