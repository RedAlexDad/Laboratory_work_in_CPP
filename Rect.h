#pragma once
#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

class Rect
{
private:
    int a;
    int b;
public:
    Rect() { a = NULL; b = NULL; }
    Rect(int _a, int _b) { a = _a; b = _b; }
    ~Rect() {}
    Rect(const Rect& _Rect) { *this = _Rect; }
    Rect(Rect& obj) { a = obj.a; b = obj.b; };

    void set_a(int _year_work);
    void set_b(int _salary);

    int get_a();
    int get_b();

    // Внешняя - дружественная функция
    // Постфиксная операция
    friend Rect& operator--(Rect& OBJ, int VALUE) {
        Rect tmp = OBJ;
        OBJ.a--;
        OBJ.b--;
        return tmp;
    }

    // Префиксная операция
    friend Rect& operator--(Rect& OBJ) {
        --OBJ.a;
        --OBJ.b;
        return OBJ;
    }

    // Оператор умножения
    Rect& operator* (const int value) {
        Rect tmp;
        tmp.a = this->a * value;
        tmp.b = this->b * value;
        return tmp;
    }

    // Оператор сравнения
    bool operator< (Rect OBJ) {
        if (OBJ.a < this->a)
            return true;
        else
            return false;
    }

    // Операция ввода и вывода
    friend ostream& operator<< (ostream& stream, Rect k) {
        stream << "a = " << k.a << ", " << "b = " << k.b << endl;
        return stream;
    }

    friend istream& operator>>(istream& in, Rect& obj) {
        cout << "a: ";
        in >> obj.a;
        cout << "b: ";
        in >> obj.b;
        return in;
    }
};
