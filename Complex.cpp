#include "Complex.h"

#include <iostream>
using namespace std;

//3.	Метод изменения значений переменных - членов объекта.
void Complex::set_double_number(double _double_number) { double_number = _double_number; }

void Complex::set_imaginary_numbers(double _imaginary_numbers) { imaginary_numbers = _imaginary_numbers; }

double Complex::get_double_number() { return double_number; }

double Complex::get_imaginary_numbers() { return imaginary_numbers; }

double get_double_number_through_friend(Complex _double_number)
{
    return _double_number.double_number;
}

