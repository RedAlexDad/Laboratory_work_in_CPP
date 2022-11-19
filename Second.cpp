#include <iostream>
#include "header.h"
#include <fstream>
#include <iomanip>
#include <io.h>

using namespace std;

ostream& ddd(ostream& s) {
    return s << oct << showbase;
}

double Mult() {
    double pi = 3.145546;
    return pi;
}

int iSecond = 15;


void writeTextFile(fstream& DB, Bus* Class_BUS, int size) {

    DB.open("Moscow.txt", ios_base::out);
    if (!DB)
        cout << "Файл открыть невозможно\n";

    // Цикл записи файла
    for (int i = 0; i < size; i++)
        // Запись в файл
        DB << Class_BUS[i].get_num() << '\t' << Class_BUS[i].get_FIO() << endl;

    DB.clear();
    // Закрытие файла
    DB.close();
}

void readTextFile(fstream& DB) {
    Bus bus_buff;

    DB.open("Moscow.txt", ios_base::in);

    if (!DB.is_open()) {
        cout << "Файл открыть невозможно\n";
    }
    else {
        char buff[100];
        while (!DB.eof()) {
            DB.getline(buff, 100);
            cout << buff << endl;
        }
    }
    DB.clear();
    DB.close(); // Закрытие файла
}


void addTextFile(fstream& DB, Bus* NEW_BUS) {
    Bus NEW_Moscow[] = {
            { "Ivanov C. V.", 122 },
            { "Smirnov C. K.", 565,  },
            { "Kalashnikov M. M.", 987,  },
            { "Noutbukin V. M.", 256,  },
            { "Mishin L. I.", 133,  }
    };

    DB.open("Moscow.txt", ios_base::out);
    if (!DB)
        cout << "Файл открыть невозможно\n";

    int size = sizeof(NEW_Moscow) / sizeof(Bus);

    // Цикл записи файла
    for (int i = 0; i < size; i++)
        // Запись в файл
        DB << NEW_Moscow[i].get_num() << '\t' << NEW_Moscow[i].get_FIO() << endl;

    NEW_BUS = NEW_Moscow;

    DB.clear();
    // Закрытие файла
    DB.close();
}


void writeBinFile(fstream& DB, Bus* MoscowB, int size) {
    DB.open("MoscowB.bin", ios_base::out | ios_base::binary);
    // Цикл записи файла
    for (int i = 0; i < size; i++)
        DB.write((const char*)&MoscowB[i], sizeof(Bus)); // Запись в файл
    DB.close(); // Закрытие файла
    DB.clear(); // Сброс предыдущих флагов для объекта DB
}

void readBinFile(fstream& DB, const char* FileName) {
    DB.open(FileName, ios_base::in | ios_base::binary);
    Bus BBsf;
    // Цикл чтения файла и распечатка
    while (!DB.eof() && !DB.fail()) {
        DB.read((char*)&BBsf, sizeof(Bus)); // Чтение из файла
        if (!DB.eof())
            cout << BBsf;
    };
    DB.close(); // Закрытие файла
    DB.clear(); // Сброс предыдущих флагов для объекта DB
}

void addBinFile(fstream& DB, Bus& MoscowB) {
    Bus NEW_Moscow[] = {
            { "Ivanov C. V.", 122 },
            { "Smirnov C. K.", 565,  },
            { "Kalashnikov M. M.", 987,  },
            { "Noutbukin V. M.", 256,  },
            { "Mishin L. I.", 133,  }
    };
    int size = sizeof(NEW_Moscow) / sizeof(Bus);

    MoscowB = *NEW_Moscow;

    DB.open("MoscowB.bin", ios_base::out | ios_base::binary);
    // Цикл записи файла
    for (int i = 0; i < size; i++)
        DB.write((const char*)&NEW_Moscow[i], sizeof(Bus)); // Запись в файл
    DB.close(); // Закрытие файла
    DB.clear(); // Сброс предыдущих флагов для объекта DB
}

void readBinFile_N(fstream& DB, int number) {
    DB.open("MoscowB.bin", ios_base::in);
    Bus BBsf;

    if ((number <= size_file("MoscowB.bin")) && (number >= 0)) {
        DB.seekg(sizeof(Bus) * (number - 1), ios_base::beg);
        DB.read((char*)&BBsf, sizeof(Bus));
        cout << BBsf;
    }
    else {
        cout << "Ошибка! Нет такого пункта!" << endl;
    }
    DB.close(); // Закрытие файла
    DB.clear();
}

void createNewFile(fstream& DB2) {
    fstream DB;
    DB.open("MoscowB.bin", ios_base::in | ios_base::binary);
    DB2.open("LR2.bin", ios_base::out | ios_base::binary);

    int size = size_file("MoscowB.bin");

    // Размер массиива для четных записей
    int chet_value = (size / 2) + 1;

    // Размер массиива для нечетных записей
    //int nechet_value = size / 2;

    Bus BBsf;
    Bus* new_bus = new Bus[chet_value];
    //Bus new_bus;
    int i = 1, count = 0;

    // Цикл чтения файла и распечатка
    while (!DB.eof() && !DB.fail()) {
        DB.read((char*)&BBsf, sizeof(Bus)); // Чтение из файла
        if (!DB.eof()) {
            if ((i == 1) || (i % 2 == 1)) {
                new_bus[count] = BBsf;
                //cout << BBsf;
                //cout << new_bus[i];
                count++;
                //cout << new_bus[i];
            }
            i++;
        }
    };

    for (int i = 0; i < chet_value; i++) {
        DB2.write((const char*)&new_bus[i], sizeof(Bus)); // Запись в файл
    }

    DB.close(); // Закрытие файла
    DB.clear(); // Сброс предыдущих флагов для объекта DB

    DB2.close(); // Закрытие файла
    DB2.clear(); // Сброс предыдущих флагов для объекта DB
}

int size_file(const char* FileName) {
    int begin, end;

    ifstream myfile(FileName);

    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();

    myfile.close();

    int size = (end - begin) / sizeof(Bus);
    //cout << "size: " << size << endl;

    return size;
}
