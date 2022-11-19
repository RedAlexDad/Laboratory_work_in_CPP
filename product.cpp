#include <iostream>
#include <cstring>
#include "Product.h"

#pragma warning(disable : 4996)

using namespace std;

void Product::set_designation(char* _designation)
{
    delete[] designation;

    designation = new char[strlen(_designation) + 1];
    strcpy_s(designation, strlen(_designation) + 1, _designation);
}

void Product::set_designation(const char* _designation)
{
    delete[] designation;

    designation = new char[strlen(_designation) + 1];
    strcpy_s(designation, strlen(_designation) + 1, _designation);
}

void Product::set_units(char* _units)
{
    delete[] units;

    units = new char[strlen(_units) + 1];
    strcpy_s(units, strlen(_units) + 1, _units);
}

void Product::set_units(const char* _units)
{
    delete[] units;

    units = new char[strlen(_units) + 1];
    strcpy_s(units, strlen(_units) + 1, _units);
}

void Product::set_count(int _count)
{
    count = _count;
}

char* Product::get_designation() { return designation; }

char* Product::get_units() { return units; }

int Product::get_count() { return count; }

// Функция для сравнения, у кого больше количеств
void check_comparison(Product FT, Product SC) {
    if (FT.get_count() > SC.get_count())
        cout << "У " << FT.get_designation() << " больше на "
             << FT.get_count() - SC.get_count()
             << " " << FT.get_units();
    else if (FT.get_count() < SC.get_count())
        cout << "У " << SC.get_designation() << " больше на "
             << SC.get_count() - FT.get_count()
             << " " << SC.get_units();
    else if (FT.get_count() == SC.get_count())
        cout << "У них количество совпадают" << endl;

    cout << endl << endl;
}


// Функция, которая возвращает объект
Product fun_set_full(char* designation, char* units, int count)
{
    Product tmp;
    tmp.set_designation(designation);
    tmp.set_units(units);
    tmp.set_count(count);
    return tmp;
}

Product fun_set_full(const char* designation, const char* units, int count)
{
    Product tmp;
    tmp.set_designation(designation);
    tmp.set_units(units);
    tmp.set_count(count);
    return tmp;
}

char* fun_get_designation(Product& PR) {
    return PR.get_designation();
}

char* fun_get_units(Product PR) {
    return PR.get_units();
}

int fun_get_count(Product PR) {
    return PR.get_count();
}
