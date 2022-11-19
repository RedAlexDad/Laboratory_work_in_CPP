#include "MySet.h"
#include <iostream>
#include <cstring>

using namespace std;

template<>
MySet<char*>& MySet<char*>::operator=(MySet<char*> v) {
    if (this != &v) {
        if (v.size != 0) {
            pdata = new char* [v.size];
            for (int i = 0; i < v.size; i++) {
                pdata[i] = new char[strlen(v.pdata[i]) + 1];
                strcpy_s(pdata[i], strlen(v.pdata[i]) + 1, v.pdata[i]);
            }
        }
        size = v.size;
        maxsize = v.maxsize;
    }
    return *this;
}

template<>
MySet<char*>::MySet(const MySet<char*>& v) {
    if (v.size != 0) {
        pdata = new char* [v.size];
        for (int i = 0; i < v.size; i++) {
            pdata[i] = new char[strlen(v.pdata[i]) + 1];
            strcpy_s(pdata[i], strlen(v.pdata[i]) + 1, v.pdata[i]);
        }
    }
    size = v.size;
    maxsize = v.maxsize;
}
