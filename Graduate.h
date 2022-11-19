#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_GRADUATE_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_GRADUATE_H

#include <cstring>
#include <iostream>

using namespace std;
class Date {
private:
    int day, month, year;

public:
    // №1 КОНСТРУКТОРЫ

// Без параметров
    Date() { day = 0; month = 0; year = 0; }

    // С параметрами
    Date(int DAY, int MONTH, int YEAR) {
        day = DAY; month = MONTH; year = YEAR;
    }

    // №1 И ДЕСТРУКТОРЫ
    ~Date() {
        cout << "ДЕСТРУКТОР! ~Date" << endl;
        //delete &this->day, &this->month, &this->year;
    }

    // №2 Конструктор копирования
    Date(const Date& OBJ) { day = OBJ.day; month = OBJ.month; year = OBJ.year; }

    // №4 Перегрузка оператора присваивания
    Date& operator=(const Date& OBJ) {
        if (this != &OBJ) {
            day = OBJ.day; month = OBJ.month; year = OBJ.year;
        }
        return *this;
    }

    // №5 Перегрукза оператора вывода в консоль
    friend ostream& operator<<(ostream& out_stream, Date& OBJ) {
        out_stream << "День: " << OBJ.day << "Месяц: " << OBJ.month << "Год: " << OBJ.year << endl;
        return out_stream;
    }

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }

    void set_day(int DAY) { day = DAY; }
    void set_month(int MONTH) { month = MONTH; }
    void set_year(int YEAR) { year = YEAR; }
};


class Graduate {
private:
    char* name;
    int rating;
    Date* birthday;


public:
    // №1 КОНСТРУКТОРЫ

    // №1 КОНСТРУКТОРЫ Без параметров
    Graduate() {
        name = new char[1];
        strcpy_s(name, 1, "");
        rating = 0;
    }

    // №1 КОНСТРУКТОРЫ С параметрами
    Graduate(char* NAME, int RAT) {
        delete[] name;
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);

        rating = RAT;
    }

    // №1 КОНСТРУКТОРЫ С параметрами
    Graduate(const char* NAME, int RAT) {
        //delete[] name;
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);

        rating = RAT;
    }

    // №1 КОНСТРУКТОРЫ С параметрами
    Graduate(char* NAME, int RAT, int DAY, int MONTH, int YEAR) {
        delete[] name;
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);

        rating = RAT;

        birthday = new Date[1];
        birthday->set_day(DAY);
        birthday->set_month(MONTH);
        birthday->set_year(YEAR);

        //cout << birthday;
    }

    // №1 КОНСТРУКТОРЫ С параметрами
    Graduate(const char* NAME, int RAT, int DAY, int MONTH, int YEAR) {
        //delete[] name;
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);

        rating = RAT;

        //Date tmp(DAY, MONTH, YEAR);
        //cout << tmp;=
        birthday = new Date[1];
        birthday->set_day(DAY);
        birthday->set_month(MONTH);
        birthday->set_year(YEAR);

        //cout << birthday;
    }

    // №1 И ДЕСТРУКТОРЫ
    ~Graduate() {
        //cout << "ДЕСТРУКТОР! ~Graduate" << endl;
        delete[] name;
        delete[] birthday;
    }

    // №2 Конструктор копирования
    Graduate(const Graduate& OBJ) {
        name = new char[strlen(OBJ.name) + 1];
        strcpy_s(name, strlen(OBJ.name) + 1, OBJ.name);
        rating = OBJ.rating;
        *birthday = *OBJ.birthday;
    }

    // №3 Метод setName изменения поля name объекта
    void setName(char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }

    // №3 Метод setName изменения поля name объекта
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy_s(name, strlen(newName) + 1, newName);
    }

    // №4 Перегрузка оператора присваивания
    Graduate& operator=(const Graduate& OBJ) {
        if (this != &OBJ) {
            name = new char[strlen(OBJ.name) + 1];
            strcpy_s(name, strlen(OBJ.name) + 1, OBJ.name);
            rating = OBJ.rating;
            birthday = OBJ.birthday;
        }
        return *this;
    }

    // №5 Перегрукза оператора вывода в консоль
    friend ostream& operator<<(ostream& out_stream, Graduate& OBJ) {
        out_stream << "Имя: " << OBJ.name << "; " << "Рейтинг: " << OBJ.rating << endl
                   << "День рождения: " << endl
                   << "День: " << OBJ.birthday->get_day() << " " << "Месяц: " << OBJ.birthday->get_month() << " "
                   << "Год: " << OBJ.birthday->get_year() << endl;
        return out_stream;
    }

    // №6 Перегрузка оператора += (увеличение рейтинга на заданную констату)
    friend Graduate& operator+=(Graduate& OBJ, int value) {
        OBJ.rating = OBJ.rating + value;
        return OBJ;
    }
};

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_GRADUATE_H
