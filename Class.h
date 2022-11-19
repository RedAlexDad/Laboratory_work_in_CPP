#pragma once
#include <iostream>

using namespace std;

// Абстрактный класс
class Space {
protected:
    // Площадь комнаты
    double S;
public:
    virtual int square() = 0;
    virtual void show() = 0;
    ~Space() { cout << "DESTRUCTION. ~Space" << endl; }

};

// Модель комнаты
class Room : public Space {
protected:
    // Длина и ширина комнаты
    double x, y;

    // Площадь комнаты
    double S;

public:
    Room() { x = 0; y = 0; S = square(); }
    Room(double X, double Y) { x = X; y = Y; S = square(); }
    ~Room() { cout << "DESTRUCTION. ~Room" << endl; }

    double get_S() { return S; }
    double get_x() { return x; }
    double get_y() { return y; }

    int square() {
        //cout << "Вызов виртуальной фунции. Room" << endl;
        S = x * y;
        return S;
    }

    void show() {
        cout << endl;
        cout << "Комната: " << endl
             << "Длина и ширина комнаты: " << endl
             << "Длина: " << x << endl
             << "Ширина: " << y << endl;
        //cout << "Площадь: " << S << endl;
    }

    friend ostream& operator<<(ostream& out, Room obj) {
        out << "Длина и ширина комнаты: " << endl
            << "Длина: " << obj.x << endl
            << "Ширина: " << obj.y << endl
            << "Площадь: " << obj.S << endl;
        return out;
    }
};

// Модель квартиры
class Flate : public Room {
protected:
    // Массив объектов класса Room, т.е. массив комнаты
    Room* arr;
    int size;
public:
    Flate() { arr = new Room; size = 0; }

    Flate(Room* ARR, int SIZE) {
        size = SIZE;
        arr = new Room[size];

        for (int i = 0; i < size; i++) {
            arr[i] = ARR[i];
        }
    }

    Flate(double X, double Y) : Room(X, Y) {
        arr = new Room[5];
        size = 1;
        arr[0]= Room(X, Y);
    }
    ~Flate() { cout << "DESTRUCTION. ~Flate" << endl; }

    int square() {
        double sum = 0;
        //cout << "Вызов виртуальной фунции. Flate" << endl;
        for (int i = 0; i < size; i++) {
            sum += arr[i].square();
        }
        return sum;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << endl;
            cout << "Квартира: №" << i + 1<< endl;
            cout << "Длина и ширина комнаты: " << endl
                 << "Длина: " << arr[i].get_x() << endl
                 << "Ширина: " << arr[i].get_y() << endl;
            cout << "Площадь: " << arr[i].get_S() << endl;
        }
    }

    friend ostream& operator<<(ostream& out, Flate& obj) {
        out << "Квартира: " << endl;
        out << "Длина и ширина комнаты: " << endl
            << "Длина: " << obj.arr->get_x() << endl
            << "Ширина: " << obj.arr->get_y() << endl
            << "Площадь: " << obj.arr->get_S() << endl;
        return out;
    }
};
