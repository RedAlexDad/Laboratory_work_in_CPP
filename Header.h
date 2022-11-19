#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


// double / Произведение (Mult)
// ddd: установка oct и showbase

ostream& ddd(ostream& s);

double Mult();


class Bus {
private:
    char FIO_drive[100];
    int number;

public:
    Bus() {
        number = 0;

        //FIO_drive = new char[1];
        strcpy_s(FIO_drive, 1, "");
    }
    Bus(char* FIO, int num) {
        delete[] &FIO_drive;

        number = num;
        strcpy_s(FIO_drive, strlen(FIO) + 1, FIO);
    }
    Bus(const char* FIO, int num) {
        number = num;

        //FIO_drive = new char[strlen(FIO) + 1];
        strcpy_s(FIO_drive, strlen(FIO) + 1, FIO);
    }

    ~Bus(){}


    void show() { cout << "Номер: " << number << ", ФИО водителя: " << FIO_drive << endl; }

    void set_num(int num) { number = num; }
    void set_FIO(char* FIO) { strcpy_s(FIO_drive, strlen(FIO) + 1, FIO); }

    int get_num() { return number; }
    char* get_FIO() { return FIO_drive; }

    friend ifstream& operator>>(ifstream& fin, Bus& obj) {
        fin >> obj.FIO_drive;
        fin >> obj.number;
        return fin;
    }

    friend ofstream& operator<<(ofstream& out, const Bus& obj) {
        out << "ФИО водителя: " << obj.FIO_drive << ";" << '\t' << "номер: " << obj.number << endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, const Bus& obj) {
        out << "ФИО водителя: " << obj.FIO_drive << ";" << '\t' << "номер: " << obj.number << endl;
        return out;
    }

};

// Работа с текстовым файлом

void writeTextFile(fstream& DB, Bus* Class_BUS, int size);

void readTextFile(fstream& DB);

void addTextFile(fstream&, Bus*);

// Работа с бинарным файлом

void writeBinFile(fstream&, Bus*, int);

void readBinFile(fstream& DB, const char* FileName);

void addBinFile(fstream&, Bus&);

void readBinFile_N(fstream&, int);

void createNewFile(fstream& DB);


int size_file(const char* FileName);
