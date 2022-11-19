/*
Описать структуру с именем AEROFLOT, содержащую следующие поля:
название пункта назначения рейса; номер рейса; тип самолета.

Написать программу, выполняющую следующие действия:
ввод с клавиатуры данных в массив, состоящий из семи элементов типа AEROFLOT;
записи должны быть упорядочены по возрастанию номера рейса;
вывод на экран номеров рейсов и типов самолетов, вылетающих в пункт назначения,
название которого совпало с названием, введенным с клавиатуры;
если таких рейсов нет, выдать на дисплей соответствующее сообщение.
*/


#include <iostream>
#include <cstring>

using namespace std;

// Структура Аэропорта
struct AEROFLOT
{
    // Имя рейса
    char *name_reis;

    // Номер рейса
    int num_reis;

    // Тип самолета
    char *type_plane;
};

// Пользовательский ввод с клавиатуры данными в массив структуры
void cin_airflot(AEROFLOT* air)
{
    char* buf = new char[1000];
    cout << "Введите имя рейса: ";
    cin >> buf;

    // Выделяем память на заполнение данных
    air->name_reis = new char[strlen(buf)];

    strcpy_s(air->name_reis, strlen(buf) + 1, buf);
    //strcpy(air.name_reis, buf);

    // Освобождение памяти и выделение новой памяти
    delete[] buf;
    buf = new char[1000];

    cout << "Введите номер рейса: ";
    cin >> air->num_reis;

    cout << "Введите тип самолета: ";
    cin >> buf;

    // Выделяем память на заполнение данных
    air->type_plane = new char[strlen(buf)];

    strcpy_s(air->type_plane, strlen(buf) + 1, buf);

    // Освобождаем памяти
    delete[] buf;
}

// Печать структуры
void print_airflot(AEROFLOT air)
{
    cout << "Имя рейса: " << air.name_reis << endl;
    cout << "Номер рейса: " << air.num_reis << endl;
    cout << "Тип самолета: " << air.type_plane << endl;
}

// Проверка на одинаковые названия рейса, введенного пользователем
void check_matches(AEROFLOT* AIRBUS, int size_airflot, int *check_warn)
{
    char* buf = new char[1000];

    cout << "Введите название рейс, которого хотите искать" << endl;
    cin >> buf;

    char* name = new char[strlen(buf) + 1];

    strcpy(name, buf);

    cout << "Имя рейса: " << name << endl << endl;

    delete[] buf;

    for (int i = 0; i < size_airflot; i++)
        if (strcmp(name, AIRBUS[i].name_reis) == 0)
        {
            cout << "Совпадений найдено: " << endl;
            //cout << "Имя рейса: " << AIRBUS[i].name_reis << " и " << AIRBUS[j].name_reis << endl;
            cout << "Имя рейса: " << AIRBUS[i].name_reis << endl;
            cout << "Номер рейса: " << AIRBUS[i].num_reis << endl;
            cout << "Тип самолета: " << AIRBUS[i].type_plane << endl;
            cout << endl << endl;

            // Найдено совпадний, тогда нет ошибок
            *check_warn = 0;
        }

    delete[] name;
}

// Сортировка массива по возрастанию
void sort_airflot(AEROFLOT* air, int size_airflot)
{
    for (int i = 0; i < size_airflot; i++) {
        for (int j = 0; j < size_airflot; j++) {
            if (air[i].num_reis < air[j].num_reis) {
                AEROFLOT tmp = air[i];
                air[i] = air[j];
                air[j] = tmp;
            }
        }
    }
}


int main() {
    // system("chcp 1251 > nul");
    system("chcp 65001");

    cout << "Лабораторная работа № 1\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    const int size_airflot = 3;
    // Создаем и выделяем память
    AEROFLOT *AIRBUS = new AEROFLOT[size_airflot];

    cout << "Введите все данные для аэропорта" << endl;

    for (int i = 0; i < size_airflot; i++) {
        cout << "AIRBUS №" << i + 1 << endl;
        // Пользовательский ввод с клавиатуры данных
        cin_airflot(&AIRBUS[i]);
    }

    // Сортировка номера рейса по возрастанию
    sort_airflot(AIRBUS, size_airflot);


    cout << endl << endl;

    for (int i = 0; i < size_airflot; i++) {
        cout << "AIRBUS №" << i + 1 << endl;
        // Печать на консольное окно
        print_airflot(AIRBUS[i]);
    }

    cout << endl << endl;

    // Проверка, если есть совпадений названий, то 0, иначе 1
    int check_warn = 1;

    check_matches(AIRBUS, size_airflot, &check_warn);

    // Проверка на совпадении названий, введенный пользователем
    if (check_warn == 1)
        cout << "Совпадений не найдено\n" << endl;

    // Освобождаем память
    delete[] AIRBUS;
}
