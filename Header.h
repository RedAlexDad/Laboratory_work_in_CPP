#pragma once
#include <iostream>
#include <cstring>

// #pragma warning(disable : 4996)

using namespace std;

// Макросы
#define SQUARE (x) ((x) * (x))
#define PI 3.1416
#define AREA_CIRCLE(r) (PI * (r) * (r))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX3(x, y, z) (MAX(x, y) > (z)) ? MAX((x), (y)) : z
#define SUM_MAS(sum, mas, size)\
	for (int i = 0; i < size; i++) \
		sum += mas[i]; \

#define SWAPI(a, b) int tmp_i = a; a = b; b = tmp_i;
#define SWAPD(a, b) double tmp_d = a; a = b; b = tmp_d;

// Вид и название макроса: Сумма трех

#define SUM3(a, b, c) ((a) + (b) + (c))

#define RAZM 10;


template <typename T>
void SWAP(T& first, T& second) {
    T tmp = first;
    first = second;
    second = tmp;
}

template <class T, int size>
T min_mas_fun(T* arr) {
    int min_i = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[min_i])
            min_i = i;

    return arr[min_i];
}

template <class T>
T summa3_fun(T x, T y, T z) {
    return (x + y + z);
}


template <class T = char>
int length_string_fun(T* str) {
    int count = 0;
    while (str[count] != '\0') count++;
    return count;
}

// Шаблон класса с внутренними методами с одним параметром
// Line - линия (коэффициенты уравнения y = b + k*x)
template <class T>
class Line
{
private:
    T y, b, k, x;

public:
    Line() { y = 0; b = 0; k = 0; x = 0; }
    Line(T B, T K, T X) { y = B + K * X; b = B, k = K, x = X; }
    ~Line() {}

    T getY() { return y; }
    void show() {
        cout << "b = " << b << "; k = " << k << "; x = " << x << endl; }

    friend ostream& operator<<(ostream& out, Line& obj) {
        //out << obj.name << ' '
        out << "y = b + k * x" << endl <<
            "y = " << obj.getY() << " = " << obj.b << " + " << obj.k << " * " << obj.x << endl;
        return out;
    }
};

// Шаблон класса с внутренними методами с двумя параметрами
template <class T, typename COLOR = int>
class Line_color
{
private:
    T y, b, k, x;
    // 0 - RED, 1 - GREEN, 2 - BLUE;
    COLOR color;

public:
    Line_color() { y = 0; b = 0; k = 0; x = 0; }
    Line_color(T B, T K, T X, COLOR col) { y = B + K * X; b = B, k = K, x = X; color = col;  }
    ~Line_color() {}

    T getY() { return y; }
    void show() {
        cout << "b = " << b << "; k = " << k << "; x = " << x << "; Цвет закраски: " << switch_color(color) << endl;
    }

    friend ostream& operator<<(ostream& out, Line_color& obj) {
        //out << obj.name << ' '
        out << "y = b + k * x" << endl <<
            "y = " << obj.getY() << " = " << obj.b << " + " << obj.k << " * " << obj.x << endl <<
            "Цвет закраски: " << obj.switch_color(obj.color) << endl;
        return out;
    }

    const char* switch_color(COLOR color) {
        switch (color) {
            case 0: return "красный"; break;
            case 1: return "зеленый"; break;
            case 2: return "синий"; break;
            default: return "Ошибка! Неверное кодовое наименование!"; break;
        }
    }
};

// Шаблон класса с внешним описанием методов и двумя параметрами
template <class T, typename COLOR = int>
class Line_color_out
{
private:
    T y, b, k, x;
    // 0 - RED, 1 - GREEN, 2 - BLUE;
    COLOR color;

public:
    Line_color_out();
    Line_color_out(T B, T K, T X, COLOR col);

    T getB();
    T getK();
    T getX();
    T getY();
    int getColor() { return color; }

    void show();

    const char* switch_color(COLOR color);
};

// extern template Line_color_out<int>;

template <class T>
ostream& operator <<(ostream& out, Line_color_out<T>& obj) {
    out << "y = b + k * x" << endl <<
        "y = " << obj.getY() << " = " << obj.getB() << " + " << obj.getK() << " * " << obj.getX() << endl
        << "Цвет закраски: " << obj.switch_color(obj.getColor()) << endl;
    return out;
}

// Описание нового класса на основе шаблона класса
class derived: public Line_color_out<double, int> {
private:
    double y;
    string color;

public:
    derived(double b, double k, double x, string col) :
            Line_color_out(b, k, x, FillColor(col)) {
        y = b + k * x;
        color = col;
    }

    ~derived(){}

    int FillColor(string color) {
        if ("красный" == color)
            return 0;
        else if ("зеленый" == color)
            return 1;
        else if ("синий" == color)
            return 2;
        else return NULL;
    }
};


// Описание нового шаблона класса на основе шаблона класса
template <typename T = double>
class derived_with_template : public Line_color_out<T, int> {
private:
    T y;
    string color;

public:
    derived_with_template(T b, T k, T x, string col) :
            Line_color_out<T, int>(b, k, x, FillColor(col)) {
        y = b + k * x;
        color = col;
    }
    ~derived_with_template() {}

    int FillColor(string color) {
        if ("красный" == color)
            return 0;
        else if ("зеленый" == color)
            return 1;
        else if ("синий" == color)
            return 2;
        else return NULL;
    }
};