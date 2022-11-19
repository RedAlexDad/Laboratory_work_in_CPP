#pragma once

#include <iostream>
using namespace std;

class Complex
{
private:
    // Вещественное число
    double double_number;

    // Мнимые числа
    double imaginary_numbers;

public:
    //1.	Конструктор без параметров, в котором в переменные-члены
    //		создаваемого объекта записывается 0.
    Complex()
    {
        double_number = 0;
        imaginary_numbers = 0;
    }

    //2.	Конструктор с двумя параметрами.
    Complex(double _double_number, double _imaginary_numbers)
    {
        double_number = _double_number;
        imaginary_numbers = _imaginary_numbers;
    }

    //3.	Метод изменения значений переменных - членов объекта.
    void set_double_number(double _double_number);
    void set_imaginary_numbers(double _imaginary_numbers);

    double get_double_number();
    double get_imaginary_numbers();

    //4.	Метод вывода на экран значений переменных -
    //		членов объекта в виде ” - 5.4 + 3.9i”.
    void show()
    {
        if (imaginary_numbers >= 0)
            cout << double_number << " + " << imaginary_numbers << "i" << endl;
        else
            cout << double_number << " - " << abs(imaginary_numbers) << "i" << endl;

        cout << endl;
    };

    friend double get_double_number_through_friend(Complex _double_number);
};
