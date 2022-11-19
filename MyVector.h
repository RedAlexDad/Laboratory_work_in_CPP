//файл MyVector.h - описание класса MyVector
#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYVECTOR_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYVECTOR_H

#include <iostream>
#include <string>
using namespace std;
// Отключение предупреждении о потери данных при преобразовании с double на int (строка 27 и 31)
#pragma warning(disable : 4244)

/*
Пометка:
Чтобы описать специализированный класс, нужно сначала описать (пример)

// .h - файл

template <typename T> class S {
	void test();
};

// Определение "общей" реализации
template <typename T> void S::test() {
	...
}

// Явная специализация для 'S<int>' - здесь только объявление
template <> void S<int>::test();

// .cpp - файл

// А здесь - определение
template <> void S<int>::test()  {
	...
}
*/

const int MAX_SIZE = 5;

template<class T = string>
class MyVector
{
protected:
    // размер вектора
    int maxsize;
    // количество элементов в векторе;
    int size;
    // указатель, содержащий адрес динамического массива элементов (строк).
    T* pdata;

private:
    // изменение размера вектора maxsize при его переполнении или освобождении места (private);
    void resize();

public:
    // Конструктор без параметров
    MyVector();

    // Конструктор с параметрами
    MyVector(T el);

    // Конструктор копирования
    MyVector(MyVector<T>& v);

    // Деструктор
    ~MyVector();

    // Вставка элемента в конец вектора
    void add_element(const T el);

    // Удаление элемента из произвольного места;
    void delete_element(int number);

    // Для возврата элемента вектора (доступ по индексу);
    T operator[](int i);

    // Сортировка
    void sort();

    // Обмен местами
    void swap(int i, int j);

    // Получение размера элемента вектора
    int Size() { return size; }

    // Получение размера вектора
    int Maxsize() { return maxsize; }

    // Возвращает индекс элемента или –1, если элемент не найден
    int find(T el);

    // Определение длин чисел
    int length(T el) {
        int count = 0;
        while (el) {
            el /= 10;
            count++;
        }
        return count;
    }

    // Перегруженная операция присваивания и конструктор копирования
    MyVector<T>& operator=(MyVector<T> v);

    //friend ostream& operator<<(ostream& out, MyVector<T>& v);

    friend ostream& operator<<(ostream& out, MyVector<T>& v) {
        for (int i = 0; i < v.size; i++) {
            out << v.pdata[i] << " ";
        }
        return out;
    }
};

//================================================================================================

// ОБЩИЕ (Для любых типов переменных)

//================================================================================================


template<class T>
MyVector<T>::MyVector() {
    pdata = new T[MAX_SIZE]();
    maxsize = MAX_SIZE;
    size = 0;
}

template<class T>
MyVector<T>::MyVector(T el) {
    pdata = new T[MAX_SIZE]();
    pdata[0] = el;

    size = 1;
    maxsize = MAX_SIZE;
}

template<class T>
MyVector<T>::MyVector(MyVector<T>& v) {
    if (v.size != 0) {
        pdata = new T[v.maxsize];
        for (int i = 0; i < v.size; i++) {
            pdata[i] = v.pdata[i];
        }
    }
    else pdata = NULL;

    size = v.size;
    maxsize = v.maxsize;
}

template<class T>
MyVector<T>::~MyVector() {
    //cout << "DESTRUCTION! ~MyVector<T>" << endl;
    delete[] pdata;

    size = NULL;
    maxsize = NULL;
}

template<class T>
void MyVector<T>::add_element(T el) {
    while (true)
        if (maxsize > size + 1) {
            if (size == 0) {
                pdata[0] = el;
                size++;
                return;
            }
            pdata[size] = el;
            size++;
            break;
        }
        else {
            resize();
        }
}

template<class T>
void MyVector<T>::resize() {
    while (true) {
        // Увеличиваем в полтора раза
        if (maxsize <= size + 1) {
            maxsize *= 1.5;

            T* buff = new T[maxsize]();

            for (int i = 0; i < size; i++) {
                buff[i] = pdata[i];
            }
            delete[] pdata;
            pdata = buff;

            /*cout << "resize +: " << endl;
            for (int i = 0; i < size; i++)
                cout << "#: " << i << "\t" << buff[i] << endl;*/

            break;
        }
            // Уменьшаем в полтора раза
        else if (maxsize / 2 >= size) {
            maxsize /= 1.5;

            T* buff = new T[maxsize]();

            for (int i = 0; i < size; i++) {
                buff[i] = pdata[i];
            }
            delete[] pdata;
            pdata = buff;

            /*cout << "resize -: " << endl;
            for (int i = 0; i < size; i++)
                cout << "#: " << i << "\t" << buff[i] << endl;*/

            break;
        }
        else if (maxsize > size) {
            break;
        }
    }
};

template<class T>
void MyVector<T>::delete_element(int number) {
    while (true)
        if (maxsize / 2 < size) {
            // Устанавливаем новый размер буфера
            int j = 0;

            for (int i = 0; i < size; i++) {
                if (i != number) {
                    pdata[j] = pdata[i];;
                    j++;
                }
            }

            size--;
            break;
        }
        else
            resize();
}

template<class T>
T MyVector<T>::operator[](int i) {
    return pdata[i];
};

template<class T>
int MyVector<T>::find(T el) {
    for (int i = 0; i < size; i++) {
        if (pdata[i] == el)
            return i;
    }
    return -1;
};

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> v) {
    if (this != &v) {
        if (v.size != 0) {
            pdata = new T [v.size];
            for (int i = 0; i < v.size; i++) {
                pdata[i] = v.pdata[i];
            }
        }
        size = v.size;
        maxsize = v.maxsize;
    }
    return *this;
}

template<class T>
void MyVector<T>::sort() {
    int size_word = NULL;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++) {
            if (length(pdata[j]) > length(pdata[j + 1]) ? size_word = length(pdata[j + 1]) : size_word = length(pdata[j]));
            for (int k = 0; k < size_word; k++) {
                if (pdata[j] > pdata[j + 1]) {
                    swap(j, j + 1);
                    break;
                }
                else break;
            }
        }
}

template<class T>
void MyVector<T>::swap(int i, int j) {
    T tmp(NULL);
    tmp = pdata[i];
    pdata[i] = pdata[j];
    pdata[j] = tmp;
}


//================================================================================================

// CHAR*

//================================================================================================

template<>
MyVector<char*>::MyVector();

template<>
MyVector<char*>::MyVector(char* el);

template<>
MyVector<char*>::~MyVector();

template<>
MyVector<char*>::MyVector(MyVector<char*>& v);

template<>
void MyVector<char*>::add_element(char* el);

template<>
void MyVector<char*>::delete_element(int number);

template<>
int MyVector<char*>::find(char* el);

template<>
void MyVector<char*>::sort();

template<>
void MyVector<char*>::resize();

//================================================================================================

// ОСОБЫЕ СЛУЧАИ

//================================================================================================

template<>
void MyVector<string>::sort();

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYVECTOR_H
