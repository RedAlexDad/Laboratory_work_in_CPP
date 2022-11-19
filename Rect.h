#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_RECT_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_RECT_H

#pragma once
#include <iostream>

using namespace std;

class Rect
{
private:
    double a;
    double b;

public:
    static int count_check;
    static bool count_check_bool;

    Rect() {
        a = 0;
        b = 0;

        count_check++;
        if (count_check_bool == true)
            cout << "CONSTRUCTION; count: " << count_check << endl;
    }
    Rect(double a, double b) {
        a = 0;
        b = 0;

        count_check++;
        if (count_check_bool == true)
            cout << "CONSTRUCTION; count: " << count_check << endl;
    }

    ~Rect() {
        count_check--;
        if (count_check_bool == true)
            cout << "DESTRUCTION; count: " << count_check << endl;
    }

    //  Конструктор копирования
    Rect(Rect& obj) { a = obj.a; b = obj.b; };

    void set_a(int _year_work);
    void set_b(int _salary);

    int get_a();
    int get_b();



    // ПЕРЕГРУЗКА ОДНОМЕСТНАЯ

    // Префиксная операция
    // перегрузка методом префиксного инкремента, описание в классе;
    Rect& operator++ () {
        ++a;
        return *this;
    }

    // перегрузка методом префиксного декремента, описание вне класса;
    Rect& operator-- ();

    // Постфиксная операция
    // перегрузка методом постфиксного инкремента, описание в классе;
    Rect operator++ (int) {
        Rect tmp = *this;
        a++;
        return tmp;
    }

    //перегрузка методом постфиксного декремента, описание вне класса;
    Rect operator-- (int);

    // ПЕРЕГРУЗКА ДВУМЕСТНАЯ

    // перегрузка методом операции (объект1+объект2), описание в классе;
    Rect& operator+ (const Rect& X) {
        Rect T;
        T.a = this->a + X.a;
        return T;
    }


    // перегрузка методом операции(объект1 - объект2), описание вне класса;
    Rect& operator- (const Rect& X);


    // ДРУЖЕСТВЕННАЯ ОДНОМЕСТНАЯ
    friend bool operator==(Rect& First, Rect& Second) {
        if (Second.a == First.a && Second.b == First.b) return true;
        return false;
    }


    // Префиксная операция
    //friend Rect operator++ (Rect& First) {
    //	++First.a;
    //	return First;
    //}

    //friend Rect operator-- (Rect& First) {
    //	--First.a;
    //	return First;
    //}

    // Постфиксная операция
    //friend Rect operator++ (Rect& First, int) {
    //	Rect tmp = First;
    //	First.a = First.a + 1;
    //	return tmp;
    //}
    //
    //friend Rect operator-- (Rect& First, int) {
    //	Rect tmp = First;
    //	First.a = First.a - 1;
    //	return tmp;
    //}

    // ДРУЖЕСТВЕННАЯ ДВУМЕСТНАЯ

    //friend Rect operator+ (Rect& First, Rect& Second) {

    //	Rect TMP;
    //	TMP.a = First.a + Second.a;
    //	TMP.b = First.b + Second.b;
    //	return TMP;
    //}

    // Перегрузка дружественной функцией операции(-объект);
    // Т.е изменение знака на противоположный
    friend Rect operator- (Rect& First) {
        First.a = -First.a;
        First.b = -First.b;
        return First;
    }

    // перегрузка дружественной функцией операции (объект*const);
    friend Rect operator*(Rect& First, const int value) {
        Rect tmp;
        tmp.a = First.a * value;
        tmp.b = First.b * value;
        return tmp;
    }

    friend Rect operator*(Rect& First, Rect& Second) {
        Rect tmp;
        tmp.a = First.a * Second.a;
        tmp.b = First.b * Second.b;
        return tmp;
    }

    // ПЕРЕГРУЗКА ВВОДА И ВЫВОДА

    friend ostream& operator<< (ostream& stream, const Rect& k) {
        stream << k.a << "; " << k.b << endl;

        return stream;
    }


    friend istream& operator>>(istream& stream, Rect& obj) {
        cout << "\nre: ";
        stream >> obj.a;
        cout << "im: ";
        stream >> obj.b;
        return stream;
    }

    // ПЕРЕГРУЗКА СРАВНЕНИЯ

    bool operator< (Rect OBJ) {
        int obj_a, obj_b;
        // Вычисление площади у первого объекта
        obj_a = this->a * this->b;
        // Вычисление площади у второго объекта
        obj_b = OBJ.a * OBJ.b;

        if (obj_a < obj_b)
            return true;
        else
            return false;
    }

    // Перегруженная операция присваивания и конструктор копирования
    Rect& operator= (Rect obj) {
        a = obj.a;
        b = obj.b;
        return *this;
    };
};



class Mas
{
private:
    int* arr;
    int size_arr;

public:

    Mas(int* pMas, int SIZE)
    {
        delete[] arr;
        arr = new int[SIZE];
        size_arr = SIZE;

        for (int i = 0; i < SIZE; i++)
            arr[i] = pMas[i];
    }

    // ПЕРЕГРУЗКА ИНДЕКСИРОВАНИЯ
    int& operator[] (int k) { return arr[k]; };

};

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_RECT_H
