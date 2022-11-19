#include "MyVector.h"
#include <iostream>
#include <cstring>
//using namespace std;
// Отключение предупреждении о потери данных при преобразовании с double на int (строка 27 и 31)
//#pragma warning(disable : 4244)

// CHAR*

template<>
MyVector<char*>::MyVector() {
    pdata = new char* [MAX_SIZE]();
    maxsize = MAX_SIZE;
    size = 0;
}

template<>
MyVector<char*>::MyVector(char* el) {
    pdata = new char*[MAX_SIZE];
    pdata[0] = new char[strlen(el) + 1];
    strcpy_s(pdata[0], strlen(el) + 1, el);

    size = 1;
    maxsize = MAX_SIZE;
};

template<>
MyVector<char*>::~MyVector() {
    //cout << "DESTRUCTION! ~MyVector<char*>" << endl;
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            delete[] pdata[i];
        }
    }
    else {
        delete pdata;
    }

    size = NULL;
    maxsize = NULL;
}

template<>
MyVector<char*>::MyVector(MyVector<char*>& v) {
    if (v.size != 0) {
        pdata = new char* [v.size];
        for (int i = 0; i < v.size; i++) {
            pdata[i] = new char[strlen(v.pdata[i]) + 1];
            strcpy_s(pdata[i], strlen(v.pdata[i]) + 1, v.pdata[i]);
        }
    }
    else pdata = NULL;

    size = v.size;
    maxsize = v.maxsize;
}

template<>
void MyVector<char*>::add_element(char* el) {
    while (true)
        if (maxsize > size + 1) {
            if (size == 0) {
                pdata[0] = new char[strlen(el) + 1];
                strcpy_s(pdata[0], strlen(el) + 1, el);
                size++;
                return;
            }
            pdata[size] = new char[strlen(el) + 1];
            strcpy_s(pdata[size], strlen(el) + 1, el);
            size++;
            break;
        }
        else {
            resize();
        }
};

template<>
void MyVector<char*>::delete_element(int number) {
    while (true)
        if (maxsize / 2 < size) {
            // Устанавливаем новый размер буфера
            char** buff = new char* [maxsize];
            int j = 0;

            for (int i = 0; i < size; i++) {
                if (i != number) {
                    buff[j] = new char[strlen(pdata[i]) + 1];
                    strcpy_s(buff[j], strlen(pdata[i]) + 1, pdata[i]);
                    j++;
                }
            }
            // Присвоим все новые значения в текущий массив слов
            pdata = buff;

            size--;
            break;
        }
        else
            resize();
}

template<>
int MyVector<char*>::find(char* el) {
    for (int i = 0; i < size; i++) {
        if (!strcmp(pdata[i], el))
            return i;
    }
    return -1;
};

template<>
void MyVector<char*>::sort() {
    int size_word = NULL;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++) {
            if (strlen(pdata[j]) > strlen(pdata[j + 1]) ? size_word = strlen(pdata[j + 1]) : size_word = strlen(pdata[j]));
            for (int k = 0; k < size_word; k++) {
                if (pdata[j][k] > pdata[j + 1][k]) {
                    swap(j, j + 1);
                    break;
                }
                else break;
            }
        }
}

template<>
void MyVector<char*>::resize() {
    while (true) {
        // Увеличиваем в полтора раза
        if (maxsize <= size + 1) {
            maxsize *= 1.5;

            char** buff = new char*[maxsize]();

            for (int i = 0; i < size; i++) {
                buff[i] = new char[strlen(pdata[i]) + 1];
                strcpy_s(buff[i], strlen(pdata[i]) + 1, pdata[i]);
                //buff[i] = pdata[i];
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

            char** buff = new char* [maxsize]();

            for (int i = 0; i < size; i++) {
                buff[i] = new char[strlen(pdata[i]) + 1];
                strcpy_s(buff[i], strlen(pdata[i]) + 1, pdata[i]);
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

//================================================================================================

// ОСОБЫЕ СЛУЧАИ

//================================================================================================

template<>
void MyVector<string>::sort() {
    int size_word = NULL;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++) {
            if (pdata[j].size() > pdata[j + 1].size() ? size_word = pdata[j + 1].size() : size_word = pdata[j].size());
            for (int k = 0; k < size_word; k++) {
                if (pdata[j][k] > pdata[j + 1][k]) {
                    swap(j, j + 1);
                    break;
                }
                else break;
            }
        }
}
