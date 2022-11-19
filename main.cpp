// LAB_05_cin_cout.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

/*
Вариант 4
Тип / название функции:		double /Произведение (Mult)
Класс пользователя/ номер для чтения:	Bus (Номер маршрута, фамилия водителя) / 1
Тип и имя манипулятора без параметров (д.т.):	 ddd: установка oct и showbase
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "header.h"
#include <cstring>

#pragma warning(disable : 4996)
using namespace std;

int main()
{
    system("chcp 65001");
    cout << "Лабораторная работа № 5\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    cout << "№1.	2.1.3.	Выполнить операции ввода и вывода для переменных стандартных типов" << endl;
    cout << "№2.	2.1.4.	Выполнить операции ввода и вывода с помощью методов get, getline, put, write" << endl;
    cout << "№3.	2.1.5.	Продемонстрировать использование методов форматирования вывода в поток" << endl;
    cout << "№4.	2.1.6.	Продемонстрировать использование манипуляторов для потоковых объектов." << endl;
    cout << "№5.	2.1.7.	Продемонстрировать использование пользовательского манипулятора. " << endl;
    cout << "№6.	2.1.8.	Продемонстрировать вызов функций в потоках ввода и вывода и проектах. " << endl;
    cout << "№7.	2.1.9.	Вывод и вывод объектов пользовательских классов в стандартных потоках." << endl;
    cout << "№8.	2.1.10.	Работа с текстовым файлом" << endl;
    cout << "№9.	2.1.11.	Работа с бинарным файлом" << endl;
    cout << "№0.	Выход с программы" << endl;

    int sw;

    cout << "Введите номер пункт: ";
    cin >> sw;


    switch (sw)
    {
        case 1:
        {
            system("cls");
            cout << "№1.	2.1.3.	Выполнить операции ввода и вывода для переменных стандартных типов" << endl;

            int iVal;
            double dVal;
            bool bVal;
            char sMas[100];


            cout << "Введите любое целое число iVal: ";
            cin >> iVal;
            cout << "Было ведено значение iVal: " << iVal << endl << endl;


            cout << "Введите любое вещественное число dVal: ";
            cin >> dVal;
            cout << "Было ведено значение dVal: " << dVal << endl << endl;


            cout << "Введите 1 или 0 для логического типа bVal: ";
            cin >> bVal;
            cout << "Было ведено значение bVal: " << bVal << ", " << boolalpha << " \"" << bVal << "\"" << endl << endl;


            cout << "Введите любую строку sMas: ";
            cin >> sMas;
            cout << "Было ведено значение sMas: " << sMas << endl << endl;

            // Описываем указатель на целую переменную iVal;
            int *pInt = &iVal;

            // Присвоим значение 5
            iVal = 5;

            // Вывод на КО
            cout << "(адрес) iVal = " << &iVal << endl;
            cout << "(значение) iVal = " << iVal << endl;
            cout << "(адрес) pInt = " << pInt << endl;
            cout << "(значение) pInt = " << *pInt << endl;

            // Вводим значения через указатели
            cout << "Введите любое целое число pInt: ";
            cin >> *pInt;

            /*
            Здесь можно заметить, что адрес переменной iVal и pInt совпадает, следовательно значение, которое
            пользователь вводит, передает на адрес переменной через указатели, т.е. на переменную iVal*/

            // Вывод на КО
            cout << "(адрес) iVal = " << &iVal << endl;
            cout << "(значение) iVal = " << iVal << endl;
            cout << "(адрес) pInt = " << pInt << endl;
            cout << "(значение) pInt = " << *pInt << endl;


            break;
        }

        case 2:
        {
            system("cls");
            cout << "№2.	2.1.4.	Выполнить операции ввода и вывода с помощью методов get, getline, put, write" << endl;

            /*
            *
            Основные методы классов потокового вывода следующие:

                put – помещает в тот выходной поток, для которого она вызвана, символ,
                использованный в качестве фактического парамет¬ра;
                    cout.put('*'); // вывод звездочки

                write – имеет два параметра - указатель array на учас¬ток памяти,
                из которого выполняется вывод, и целое значение n,
                определяющее количество выводимых из этого участка символов (байт);
                    char Str1[]= "Печать write";
                    cout.write(Str1, strlen(Str1));

            Основные методы классов потокового ввода следующие:

                get – ввод символа и строки:
                    cin.get(c); // При вводе символа в буфере остается символ конца строки!!
                    cin.get( line, 25 );

                getline – ввод строки по завершающему символу (‘t’)
                    cin.getline( line, 100, 't' );

                read – ввод строки по счетчику (Count)
                    cin.read(&line[0], Count); //Указатель на первый элемент


            Основные методы форматирования вывода следующие:
                setf – установить (и сбросить – 2-й параметр) режим и флаг форматирования
                    cout.setf( ios_base::hex,ios_base::basefield); // вывод в шестнадцатеричном формате
                    cout.setf(ios_base::oct, ios_base::basefield);    // вывод в восьмеричном формате

                unsetf – сбросить режим и флаг форматирования
                    cout.unsetf( ios_base::hex ); // отменить вывод в шестнадцатеричном формате

                width – установить ширину вывода переменной
                    cout.width(20); // ширина вывода 20

                precision – установить точность вывода вещественных чисел (дробная часть)
                    cout.precision(3); // установить дробную часть в 3 знака, включая точку

                fill – установить символ для заполнения свободных позиций.
                    cout.fill('*'); // символ заполнения '*'


            */

            int iVal;
            double dVal;
            bool bVal;
            char sMas[200] = {"Мы на паре разбираемся тему \"Потоковый ввод вывод и для стандартных объектов CIN и COUT и файлов\""};

            // вывод звездочки
            cout.put('*');

            cout << endl;

            cout.write(sMas, strlen(sMas));

            cout << endl;

            cin.ignore();
            cin.getline(sMas, 100);
            cout.write(sMas, strlen(sMas));

            cout << endl;

            char one_bukva;

            //cin.ignore();
            cin.get(one_bukva);
            cout.put(one_bukva);

            cout << endl;

            break;
        }

        case 3:
        {
            system("cls");
            cout << "№3.	2.1.5.	Продемонстрировать использование методов форматирования вывода в поток" << endl;

            /*
            Основные стандартные манипуляторы:

            setw – устанавливает ширину поля вывода (аналогично методу width);
                 cout << setw(30) << sMas << endl; //Строка sMas выводиться в поле шириной 30 позиций

            setfill – устанавливает символ заполнения (аналогично методу fill);
               cout << " sMas =  " << setw(30) << setfill('!') << sMas << " sMas " <<endl;

            setprecision – устанавливает точность вывода (аналогично методу precision);
               cout << setprecision(3) << f << endl;

            setbase(int n)  – устанавливает основание (n) системы счисления. Значениями параметра n могут быть: 0, 8, 10 или 16;
               cout << setbase(8) << iVal << endl;

            hex – вывод в шестнадцатеричном виде (аналогично методу setf);
               cout <<"hex iVal =  " << hex << iVal << endl;

            oct – вывод в восьмеричном виде (аналогично методу setf);
               cout <<"oct iVal =  " << oct << iVal << endl;

            dec – вывод в десятичном виде (аналогично методу setf);
               cout <<"dec iVal =  " << dec << iVal << endl ;

            fixed – устанавливает вывод с фиксированной точкой (аналогично методу setf);
               cout << fixed << f << endl;

            showbase– устанавливает вывод признака системы счисления (аналогично методу setf);
               cout << "Для hex - " << showbase << hex << i << endl;

            left– устанавливает форматирование влево (аналогично методу setf);
               cout << left << setw(30) << setfill('!') << sMas << "sMas после left в потоке" <<endl;

            right– устанавливает форматирование вправо (аналогично методу setf);
             cout << right << setw(30) << setfill('!') << sMas << "sMas после right в потоке" <<endl;

            endl – переводит строку при выводе (аналогично выводу ‘\n’);
              cout << endl << endl << endl;

            scientific– устанавливает научный формат вывода чисел (аналогично методу setf);
              cout << " f = 5.2111 "<< scientific << f << endl;

            boolalpha – устанавливает вывод логических переменных (аналогично методу setf);
               cout << boolalpha << b << endl; // получим true или false
            */

            int iVal;
            double dVal;
            bool bVal;
            char sMas[100];

            cout << "Введите любое целое число iVal: ";
            cin >> iVal;
            cout << "Введено: " << iVal << endl << endl;


            cout << "Введите любое вещественное число dVal: ";
            cin >> dVal;
            cout << "Введено: " << dVal << endl << endl;


            cout << "До precision dVal:\t" << cout.precision() << '\n';
            cout.precision(2);
            cout << "После cout.precision(2) dVal:\t\t" << cout.precision() << '\n';
            // Научный формат
            cout.setf(ios_base::scientific, ios_base::floatfield);
            cout << "Научный формат dVal:\t" << dVal << '\n';
            // Формат с фиксированной точкой
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << "Формат с фиксированной точкой dVal:\t\t" << dVal << '\n';
            cout.precision(8);
            cout << "После cout.precision(8) dVal:\t\t" << cout.precision() << '\n';
            // Научный формат
            cout.setf(ios_base::scientific, ios_base::floatfield);
            cout << "Научный формат dVal:\t" << dVal << '\n';
            // Восстановление точности по умолчанию
            cout.precision(6);
            cout << "Восстановление точности по умолчанию dVal:\t" << cout.precision() << '\n';
            cout << endl << endl;

            cout << "Введите 1 или 0 для логического типа bVal: ";
            cin >> bVal;
            cout << "Введено: " << bVal << ", " << boolalpha << " \"" << bVal << "\"" << endl << endl;


            cout << "Введите любую строку sMas: ";
            cin >> sMas;
            cout << "Введено: " << sMas << endl << endl;


            // fill - манипулятор заполнителя, символ которого передаётся в одинарных кавычках
            cout.fill('.');

            // Изменение ширины поля вывода
            cout << setw(30) << sMas << endl;

            // Прижать к левой границе
            cout << setw(30) << left << sMas << endl;

            // Прижать к правой границе
            cout << setw(30) << right << sMas << endl;

            // Прижать к правой границе
            cout << setw(30) << internal << sMas << endl;

            // Сбрасываем настройку
            cout.fill(' ');

            int value = 15;
            cout << "value (десятичная) = " << value << endl;

            cout.unsetf(ios::dec);
            cout.setf(ios::oct);
            cout << "value (восьмеричная) = " << value << endl;

            cout.unsetf(ios::oct);
            cout.setf(ios::hex);
            cout << "value (шестн.ричная) = " << value << endl;

            // Сброс, по умолчанию, десятичная
            cout.unsetf(ios::hex);
            cout.setf(ios::dec);
            cout << "value (десятичная) = " << value << endl;


            break;
        }

        case 4:
        {
            system("cls");
            cout << "№4.	2.1.6.	Продемонстрировать использование манипуляторов для потоковых объектов." << endl;

            int iVal;
            double dVal;
            bool bVal;
            char sMas[100];

            cout << "Введите любое целое число iVal: ";
            cin >> iVal;
            cout << "Введено: " << iVal << endl << endl;

            cout << "iVal (десятичная) = " << iVal << endl;

            cout.unsetf(ios::dec);
            cout.setf(ios::oct);
            cout << "iVal (восьмеричная) = " << iVal << endl;

            cout.unsetf(ios::oct);
            cout.setf(ios::hex);
            cout << "iVal (шестн.ричная) = " << iVal << endl;

            // Сброс, по умолчанию, десятичная
            cout.unsetf(ios::hex);
            cout.setf(ios::dec);
            cout << "iVal (десятичная) = " << iVal << endl;


            cout << "setbase(16) для " << iVal << " = " << setbase(16) << iVal << endl;
            cout << "setbase(10) для " << iVal << " = " << setbase(10) << iVal << endl;
            cout << "setbase(8) для " << iVal << " = " << setbase(8) << iVal << endl;

            cout << "Для hex - " << hex << showbase << iVal << endl;

            cout << "Введите любое вещественное число dVal: ";
            cin >> dVal;
            cout << "Введено: " << dVal << endl << endl;


            cout << "dVal =  " << dVal << scientific << dVal << endl;



            break;
        }

        case 5:
        {
            system("cls");
            cout << "№5.	2.1.7.	Продемонстрировать использование пользовательского манипулятора. " << endl;

            // Чтобы найти восьмеричную систему счисления, нужно сначала сделать значение целочисленным типом
            int value = 15;

            cout << "Стандарт: " << value << endl;
            cout << "Измененено: " << ddd << value << endl;

            break;
        }

        case 6:
        {
            system("cls");
            cout << "№6.	2.1.8.	Продемонстрировать вызов функций в потоках ввода и вывода и проектах. " << endl;

            cout << Mult() << endl;

            extern int iSecond;

            cout << "iSecond  = " << iSecond << endl;


            break;
        }

        case 7:
        {
            system("cls");
            cout << "№7.	2.1.9.	Вывод и вывод объектов пользовательских классов в стандартных потоках." << endl;

            Bus Moscow[] = {
                    { "Ignatev C. V.", 100 },
                    { "Svidirov C. K.", 365,  },
                    { "Ivanov M. M.", 111,  },
                    { "Aphanasev V. M.", 300,  },
                    { "Brezhnev L. I.", 123,  }
            };

            for (int i = 0; i < 5; i++)
                Moscow[i].show();

            break;
        }

        case 8:
        {
            system("cls");
            cout << "№8.	2.1.10.	Работа с текстовым файлом" << endl;

            Bus Moscow[] = {
                    { "Ignatev C. V.", 100 },
                    { "Svidirov C. K.", 365,  },
                    { "Ivanov M. M.", 111,  },
                    { "Aphanasev V. M.", 300,  },
                    { "Brezhnev L. I.", 123,  }
            };

            int size = sizeof(Moscow) / sizeof(Bus);

            // СОЗДАНИЕ НОВОГО ФАЙЛА
            fstream DB;
            writeTextFile(DB, Moscow, size);

            // ЧТЕНИЕ И РАСПЕЧАТКА ФАЙЛА
            readTextFile(DB);

            // ИЗМЕНЕНИЕ И РАСПЕЧАТКА ФАЙЛА.
            addTextFile(DB, Moscow);
            readTextFile(DB);

            break;
        }

        case 9:
        {
            system("cls");
            cout << "№9.	2.1.11.	Работа с бинарным файлом" << endl;

            Bus MoscowB[] = {
                    { "Ignatev C. V.", 100 },
                    { "Svidirov C. K.", 365,  },
                    { "Ivanov M. M.", 111,  },
                    { "Aphanasev V. M.", 300,  },
                    { "Brezhnev L. I.", 123,  }
            };

            int size = sizeof(MoscowB) / sizeof(Bus);

            // СОЗДАНИЕ НОВОГО ФАЙЛА
            fstream DB;
            writeTextFile(DB, MoscowB, size);

            // ЧТЕНИЕ И РАСПЕЧАТКА ФАЙЛА
            readBinFile(DB, "MoscowB.bin");
            cout << endl;

            // ИЗМЕНЕНИЕ И РАСПЕЧАТКА ФАЙЛА
            addBinFile(DB, *MoscowB);
            readBinFile(DB, "MoscowB.bin");
            cout << endl;

            // ЧТЕНИЕ ЗАПИСИ ПО НОМЕРУ
            int number;
            cout << "Введите номер записи: ";
            cin >> number;

            readBinFile_N(DB, number);
            cout << endl;

            // СОЗДАНИЕ НОВОГО ФАЙЛА
            fstream DB2;
            createNewFile(DB2);
            cout << "Сортировка по четной записи" << endl;
            readBinFile(DB2, "LR2.bin");


            break;
        }


        case 0:
        {
            cout << "Выход с программы" << endl;
            system("pause");
            break;
        }

        default:
        {
            cout << "Ошибка! Неизвестная команда!" << endl;
            system("pause");
            break;
        }

    }
}
