#pragma once
#include <iostream>
#include <cmath>
using namespace std;



// Проверка абстрактного класса
class Abstract {
private:
    int identificator;
    static int count;

public:
    Abstract() { identificator = count++; };
    virtual ~Abstract() { cout << "ДЕСТРУКТОР! ~Abstract" << endl; }
    virtual void show() = 0;
    int get_identificator() { return identificator; }
};

// Координат
class coordinate : public Abstract {
protected:
    double x1, y1, x2, y2, x3, y3;

public:
    coordinate() { x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0; }

    coordinate(double ac, double cb, double ab) {

    }

    coordinate(double X1, double Y1, double X2, double Y2, double X3, double Y3) {
        x1 = X1, y1 = Y1, x2 = X2, y2 = Y2, x3 = X3, y3 = Y3;
    }

    ~coordinate() { cout << "ДЕСТРУКТОР! ~coordinate" << endl; }

    void show(){
        cout << "Идентификатор класса: " << get_identificator() << endl;
        cout << "Координаты: " << endl
             << "x1 = " << x1 << " ; y1 = " << y1 << endl
             << "x2 = " << x2 << " ; y2 = " << y2 << endl
             << "x3 = " << x3 << " ; y3 = " << y3 << endl;}

    friend ostream& operator<<(ostream& out, coordinate obj) {
        out << "Координаты: " << endl
            << "x1 = " << obj.x1 << " ; y1 = " << obj.y1 << endl
            << "x2 = " << obj.x2 << " ; y2 = " << obj.y2 << endl
            << "x3 = " << obj.x3 << " ; y3 = " << obj.y3 << endl;
        return out;
    }
};

// Длина отрезка
class segment : public coordinate {
protected:
    // Координаты отрезка 3
    double acX, cbX, abX, acY, cbY, abY;
    // Длина отрезка 3
    double ac, ab, cb;

public:
    segment(){
        // Определение длин векторов
        acX = 0; cbX = 0; abX = 0;
        acY = 0; cbY = 0; abY = 0;

        // Определение длин векторов
        ac = 0;
        ab = 0;
        cb = 0;
    }

    segment(double x1, double y1, double x2, double y2, double x3, double y3)
            : coordinate(x1, y1, x2, y2, x3, y3) {

        // Определение точек векторов
        acX = x3 - x1; cbX = x3 - x2; abX = x2 - x1;
        acY = y3 - y1; cbY = y3 - y2; abY = y2 - y1;

        // Определение длин векторов
        ac = sqrt(acX * acX + acY * acY);
        ab = sqrt(abX * abX + abY * abY);
        cb = sqrt(cbX * cbX + cbY * cbY);
    }

    segment(double AC, double CB, double AB) {
        ac = AC; ab = AB; cb = CB;

        // Определение длин векторов
        acX = 0; cbX = 0; abX = 0;
        acY = 0; cbY = 0; abY = 0;
    }

    ~segment() { cout << "ДЕСТРУКТОР! ~segment" << endl; }

    void show() {
        cout << "Идентификатор класса: " << get_identificator() << endl;
        cout << "Координаты вектора: " << endl
             << "AC { " << acX << ", " << acY << " }; " << endl
             << "AB { " << abX << ", " << abY << " }; " << endl
             << "CB { " << cbX << ", " << cbY << " }; " << endl
             << "Длина отрезки: " << endl
             << "|AC| = " << ac << endl
             << "|AB| = " << ab << endl
             << "|CB| = " << cb << endl;
    }

    friend ostream& operator<<(ostream& out, segment obj) {
        if (obj.abX != NULL) {
            out << "Координаты вектора: " << endl
                << "AC { " << obj.acX << ", " << obj.acY << " }; " << endl
                << "AB { " << obj.abX << ", " << obj.abY << " }; " << endl
                << "CB { " << obj.cbX << ", " << obj.cbY << " }; " << endl
                << "Длина отрезки: " << endl
                << "|AC| = " << obj.ac << endl
                << "|AB| = " << obj.ab << endl
                << "|CB| = " << obj.cb << endl;
        }
        else {
            out << "Длина отрезки: " << endl
                << "|AC| = " << obj.ac << endl
                << "|AB| = " << obj.ab << endl
                << "|CB| = " << obj.cb << endl;
        }
        return out;
    }
};

class triangle : public segment {
protected:
    double square;

public:
    triangle(){
        // по формуле Герона
        double p = (ab + ac + cb) / 2;
        square = sqrt(p * (p - ab) * (p - ac) * (p - cb));
    }
    triangle(double AB, double AC, double CB) : segment(AC, CB, AB) {
        ab = AB; ac = AC; cb = CB;
        // по формуле Герона
        double p = (AB + AC + CB) / 2;
        square = sqrt(p * (p - AB) * (p - AC) * (p - CB));
    }

    triangle(double x1, double y1, double x2, double y2, double x3, double y3)
            : segment(x1, y1, x2, y2, x3, y3) {

        // Определение точек векторов
        acX = x3 - x1; cbX = x3 - x2; abX = x2 - x1;
        acY = y3 - y1; cbY = y3 - y2; abY = y2 - y1;

        // Определение длин векторов
        ac = sqrt(acX * acX + acY * acY);
        ab = sqrt(abX * abX + abY * abY);
        cb = sqrt(cbX * cbX + cbY * cbY);

        double p = (ab + ac + cb) / 2;
        square = sqrt(p * (p - ab) * (p - ac) * (p - cb));
    }

    triangle(double SQUARE) { square = SQUARE; }
    ~triangle() { cout << "ДЕСТРУКТОР! ~triangle" << endl; }

    void show() {
        cout << "Идентификатор класса: " << get_identificator() << endl;
        cout << "Площадь равностороннего треугольника: " << square << endl;
    }

    friend ostream& operator<<(ostream& out, triangle obj) {
        //segment(obj.ac, obj.cb, obj.ab);
        out << "Длина отрезки: " << endl
            << "|AC| = " << obj.ac << endl
            << "|AB| = " << obj.ab << endl
            << "|CB| = " << obj.cb << endl
            << "Площадь равностороннего треугольника: " << obj.square << endl;
        return out;
    }
};


class A {
protected:
    // Общий алфавит
    char alphavit;
public:
    A() { alphavit = NULL; }
    A(char BUKVA) { alphavit = BUKVA; }
    //A(const char BUKVA) { alphavit = BUKVA; }
    virtual ~A() { cout << "ДЕСТРУКТОР! ~A" << endl; }

    char get_alphavit() { return alphavit; }

    virtual void show() { cout << "Буква общих алфавит: " << alphavit << endl; }
};

class F : public virtual A {
protected:
    // Французские алфавиты
    char franc_al;
public:
    F() : A() { franc_al = NULL; }
    F(char BUKVA, char NEW_BUKVA) : A(BUKVA) { franc_al = NEW_BUKVA; }
    //F(const char BUKVA) : A(BUKVA) { franc_al = BUKVA; }
    virtual ~F() { cout << "ДЕСТРУКТОР! ~F" << endl; }

    char get_franc_al() { return franc_al; }

    virtual void show() { cout << "Анлгийские алфавиты: " << franc_al << endl; }
};

class C : public virtual A {
protected:
    // Латинские алфавиты
    char latin_al;
public:
    C() : A() { latin_al = NULL; }
    C(char BUKVA, char NEW_BUKVA) : A(BUKVA) { latin_al = NEW_BUKVA; }
    //C(const char BUKVA) : A(BUKVA) { latin_al = BUKVA; }
    virtual ~C() { cout << "ДЕСТРУКТОР! ~C" << endl; }

    char get_latin_al() { return latin_al; }

    virtual void show() { cout << "Латинские алфавиты: " << latin_al << endl; }
};

class D : public F, public C {
protected:
    // Древнегреческие алфавиты
    char old_grec_al;
public:
    D() : F(), C() { old_grec_al = NULL; }
    D(char BUKVA0, char BUKVA1, char BUKVA2, char BUKVA3) : A(BUKVA0), F(BUKVA0, BUKVA1), C(BUKVA0, BUKVA2)
    { old_grec_al = BUKVA3; }
    //D(const char BUKVA) : A(BUKVA) { old_grec_al = BUKVA; }
    virtual ~D() { cout << "ДЕСТРУКТОР! ~D" << endl; }

    char get_old_grec_al() { return old_grec_al; }

    virtual void show() { cout << "Древнегреческие алфавиты: " << old_grec_al << endl; }
};
