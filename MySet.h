//файл MySet.h - описание класса MySet
#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSET_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSET_H

#include <iostream>
#include <string>
#include "MyVector.h"

using namespace std;

template <typename T = string>
class MySet :public MyVector<T>
{
private:
    // Перегрузка оператора присваивания
    //using MyVector<T>::operator=;

public:
    MySet() : MyVector<T>() {
        //cout << "CONSTRUCTION" << endl;
    };

    MySet(T el) : MyVector<T>(el){
        //cout << "CONSTRUCTION" << endl;
    };

    friend ostream& operator<<(ostream& out, MySet<T>& s) {
        if (s.size != 0) {
            out << "{ ";
            for (int i = 0; i < s.size; i++) {
                out << s.pdata[i] << "; ";
            }
            out << "}";
        }
        else
            out << "Отсутствует" << endl;
        return out;
    }

    // A = {1, 4, 5, 6}; B = {1, 2, 3, 4};
    // {1, 4, 5, 6} + {1, 2, 3, 4} => {1, 2, 3, 4, 5, 6}
    friend MySet<T> operator+(MySet<T>& s1, MySet<T>& s2) {
        MySet<T> buff;

        // Объединим все элементы в одно множество
        for (int i = 0; i < s1.size; i++) {
            buff.add_element(s1.pdata[i]);
        }
        for (int i = 0; i < s2.size; i++) {
            buff.add_element(s2.pdata[i]);
        }

        return buff;
    }

    // A = {1, 4, 5, 6}; B = {1, 2, 3, 4};
    // {1, 4, 5, 6} - {1, 2, 3, 4} => {5, 6} (size = 4; size = 4)
    // {1, 4, 5, 6} - {1, 2, 3, 4, 5, 7} => {5, 6} (size = 4; size = 6)
    friend MySet<T> operator-(MySet<T>& s1, MySet<T>& s2) {
        MySet<T> buff;

        for (int i = 0; i < s1.size; i++) {
            buff.MyVector<T>::add_element(s1.pdata[i]);
        }

        for (int i = 0; i < s1.size; i++) {
            // Если совпался элемент с массива s2 с массивом buff, т.е. с массивом s1
            if (buff.is_element(s2.pdata[i])) {
                buff.delete_elemet(s2.pdata[i]);
            }
        }
        return buff;
    }

    // {1, 4, 5, 6} * {1, 2, 3, 4} => {1, 4}
    friend MySet<T> operator*(MySet<T>& s1, MySet<T>& s2) {
        MySet<T> buff;

        for (int i = 0; i < s2.size; i++) {
            if (s1.is_element(s2.pdata[i])) {
                buff.MyVector<T>::add_element(s2.pdata[i]);
            }
        }

        return buff;
    }


    // Перегрузка оператора присваивания
    MySet<T>& operator=(MySet<T> v);

    // №2 Конструктор копирования
    MySet(const MySet<T>& v);

    // Если совпадало, то true
    bool operator==(MySet<T>& s) {
        if (this->size == s.size && this->maxsize == s.maxsize) {
            for (int i = 0; i < this->size; i++)
                if (this->pdata[i] != s.pdata[i]) return false;

            return true;
        }
        return false;
    }

    MySet<T>& operator+=(MySet<T>& s) {
        *this = *this + s;
        return *this;
    }

    MySet<T>& operator-=(MySet<T>& s) {
        *this = *this - s;
        return *this;
    }

    MySet<T>& operator*=(MySet<T>& s) {
        *this = *this * s;
        return *this;
    }

    // Добавление строки в множество, если её там ещё нет.
    void add_element(T el) {
        if (!is_element(el))
            this->MyVector<T>::add_element(el);
    };

    // Удаление элемента из множества, если он там есть.
    void delete_elemet(T el) {
        if (MyVector<T>::find(el) != -1) {
            this->MyVector<T>::delete_element(MyVector<T>::find(el));
        }
        else cout << "Данный элемент: [ " << el << " ] не существует" << endl;
    }

    // Метод доступа, который даёт true, если строка-параметр есть в множестве, иначе даёт false.
    bool is_element(T el) {
        for (int i = 0; i < this->size; i++) {
            if (i == MyVector<T>::find(el))
                //if (this->pdata[i] == el)
                return true;
        }
        return false;
    };

};

template<class T>
MySet<T>& MySet<T>::operator=(MySet<T> v) {
    if (this != &v) {
        if (v.size != 0) {
            this->pdata = new T[v.size];
            for (int i = 0; i < v.size; i++) {
                this->pdata[i] = v.pdata[i];
            }
        }
        this->size = v.size;
        this->maxsize = v.maxsize;
    }
    return *this;
}

template<class T>
MySet<T>::MySet(const MySet<T>& v) {
    if (v.size != 0) {
        this->pdata = new T[v.size];
        for (int i = 0; i < v.size; i++) {
            this->pdata[i] = v.pdata[i];
        }
    }
    this->size = v.size;
    this->maxsize = v.maxsize;
}

template<>
MySet<char*>& MySet<char*>::operator=(MySet<char*> v);

template<>
MySet<char*>::MySet(const MySet<char*>& v);

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSET_H
