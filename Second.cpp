#include "Header.h"
#include <iostream>
#include <cstring>

// #pragma warning (disable : 4996)
using namespace std;

template class Line_color_out<int>;
template class Line_color_out<float>;
template class Line_color_out<double>;
template class Line_color_out<long>;


template <class T, typename COLOR>
Line_color_out<T, COLOR>::Line_color_out() { y = 0; b = 0; k = 0; x = 0; }

template <class T, typename COLOR>
Line_color_out<T, COLOR>::Line_color_out(T B, T K, T X, COLOR col) { y = B + K * X; b = B, k = K, x = X; color = col; }

template <class T, typename COLOR>
void Line_color_out<T, COLOR>::show() {
    cout << "b = " << b << "; k = " << k << "; x = " << x << "; Цвет закраски: " << switch_color(color) << endl;
}

template <class T, typename COLOR>
T Line_color_out<T, COLOR>::getB() { return b; }

template <class T, typename COLOR>
T Line_color_out<T, COLOR>::getK() { return k; }

template <class T, typename COLOR>
T Line_color_out<T, COLOR>::getX() { return x; }

template <class T, typename COLOR>
T Line_color_out<T, COLOR>::getY() { return y; }

template <class T, typename COLOR>
const char* Line_color_out<T, COLOR>::switch_color(COLOR color) {
    switch (color) {
        case 0: return "красный"; break;
        case 1: return "зеленый"; break;
        case 2: return "синий"; break;
        default: return "Ошибка! Неверное кодовое наименование!"; break;
    }
}

