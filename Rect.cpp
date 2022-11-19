#include "Rect.h"
#include <iostream>

void Rect::set_a(int _a) { a = _a; }

void Rect::set_b(int _b) { b = _b; }

int Rect::get_a() { return a; }

int Rect::get_b() { return b; }

// перегрузка методом префиксного декремента, описание вне класса;
Rect& Rect:: operator-- () {
    --a;
    return *this;
}


//перегрузка методом постфиксного декремента, описание вне класса;
Rect Rect:: operator--(int) {
    Rect tmp = *this;
    a--;
    return tmp;
}

// перегрузка методом операции(объект1 - объект2), описание вне класса;
Rect& Rect:: operator- (const Rect& X) {
    Rect T;
    T.a = this->a - X.a;
    return T;
}
