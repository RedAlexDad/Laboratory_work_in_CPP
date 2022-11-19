#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#pragma warning(disable : 4996)

using namespace std;
/*
Написать программу моделирования работы автобусного парка.
Сведения о каждом автобусе содержат: номер автобуса, фамилию и инициалы
водителя, номер маршрута. База хранится в текстовом файле, его размер может быть
произвольным.

Программа должна обеспечивать выбор с помощью меню и выполнение следующих
функций:

- начальное формирование данных о всех автобусах в парке в виде
списка;

- имитация выезда автобуса из парка: вводится номер автобуса;
программа удаляет данные об этом автобусе из списка автобусов,
находящихся в парке, и записывает эти данные в список автобусов,
находящихся на маршруте;

- имитация въезда автобуса в парк: вводится номер автобуса;
программа удаляет данные об этом автобусе из списка автобусов,
находящихся на маршруте, и записывает эти данные в список
автобусов, находящихся в парке;

- вывод сведений об автобусах, находящихся в парке, и об автобусах,
находящихся на маршруте.

Для представления необходимых списков использовать класс list.
*/

// Проверка на правильность заполнения данных

bool check_cin_number_bus(string str);

bool check_cin_FIODRIVER(string str);

// Функция, выводящаяся подсказку по правильности оформлении
void support_build_text();

class BUS {
private:
    // Номер автобуса, пример АА 559 70.
    // INFO (Первые две символы - русские алфавитные буквы, далее,
    // три цифры - любые современные арабские цифры, от 0 до 9, далее,
    // две произвольные цифры - номер региона)
    string number_bus;
    // Фамилия и инициалы водителя, пример, Игнатьев В.В.
    string FIODRIVER;
    // Номер маршрута, 440
    int route_number;
    // Автобус где находится? В парке или на маршруте
    // Если в парке, то 0, если на маршруте, то 1
    int status;

    // Идентификатор класса, чтобы легче работать с определенным объектом
    int id;
    static int count;

public:
    BUS();
    BUS(int NUMBER_BUS, string FIO, int ROUTNUM, int WHERE);
    //~BUS() { cout << "DESTRUCTION! ~BUS" << endl; }

    // Функция, возвращающаяся определенные значения
    string get_number_bus();
    string get_FIODRIVER();
    int get_status();
    int get_route_number();
    int get_id();

    // Функция, принимающаяся определенные значения
    void set_number_bus(string num);
    void set_FIODRIVER(string FIO);
    void set_status(int WHERE);
    void set_route_number(int route);
    void set_id(int ID);

    // Поток вывода в консольном окне
    friend ostream& operator<<(ostream& output, BUS& obj);

    // Поток ввода пользователем
    friend istream& operator>>(istream& input, BUS& obj);

};


// Печатает все данные
void print(vector<BUS> bus);

// Печатает только данные, в которых содержатся автобусы, находящихся в парке
void print_also_park(vector<BUS> bus);

// Печатает только данные, в которых содержатся автобусы, находящихся на маршруте
void print_also_route(vector<BUS> bus);

// Работа с текстовым файлом

void writeTextFile(fstream& DB, vector<BUS> Class_BUS);

void readTextFile(fstream& DB);

// Чтение и изменение объекта класса
void read_and_add_into_class_TextFile(fstream& DB, vector<BUS>& newBUS, int& size);

// Определение и удаление номер текущего автобуса с автобусного парка и добавление в список маршрутов
void delete_number_bus(vector<BUS>& bus, string number);

// Определение и добавление номер текущего автобуса на автобусный парк в списке автобусного парка
void add_number_bus(vector<BUS>& bus, string number);

// Проверяет, пустой ли класс?
bool check_class(vector<BUS> bus);

// Выявляет размер файла
int size_file(fstream& DB);

// Функция, предлагающаяся распечатать все данные
void offer_for_printing(vector<BUS> bus);

// Функция, требующая повторно ввести
void cin_number_request(string& number);

// Проверка на существующего номера
bool check_cin_number(vector<BUS> bus, string number, int& id);

// Нахождение по id объекта и изменение
void check_edit_class_number_bus(vector<BUS>& bus, string str, int& id);

// Проверка на присуствии совпадающих номеров в базе данных
bool check_number_bus(vector<BUS> DB, BUS bus);
