// LAB_02_Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
Для реализации пункта 5 в класс включить две статические переменные,
первая - счетчик созданных объектов класса,
вторая - разрешение печати значения первой в конструкторах и деструкторе.
В конструкторы и деструктор добавьте вывод на экран значения счетчика объектов,
если вторая статическая переменная имеет значение True.
Значение счетчика по окончании выполнения пункта 5 программы должно быть равно нулю.
Для проверки весь код пункта заключите в блок,
а после этого блока в программе поставьте паузу.

- Создайте автоматический объект с инициализацией всех членов-данных.
	Выведите его данные на экран.
- Опишите простую функцию, которая принимает объект в качестве параметра по значению.
Вызовите для созданного объекта эту функцию.

- Опишите простую функцию, которая возвращает объект в качестве параметра.
Вызовите эту функцию и выведите данные возвращенного
	объекта на экран в главной программе.

- Создайте динамический объект с инициализацией всех членов-данных.
Выведите его данные на экран.
- Создайте статический массив объектов.

Освободите динамическую память в конце программы.
Описание класса поместить в заголовочный файл проекта.


Вариант 4.
Worker: Фамилия и инициалы, Должность, Год поступления на работу, Зарплата.
Создать массив объектов. Вывести:
а) список работников, стаж работы которых на данном предприятии
	превышает заданное число лет;
б) список работников, зарплата которых больше заданной;
в) список работников, занимающих заданную должность.

*/

#include <iostream>
#include "worker.h"
//#pragma warning(disable : 4997)

using namespace std;

// Устанавливает счетчик конструктора и деконструктора 0
int worker::count = 0;
bool worker::isPrint = true;



int main() {
    // system("chcp 1251 > nul");
    system("chcp 65001");
    cout << "Лабораторная работа № 2\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    int sw;

    // Для выхода программы
    bool sw_program = true;
    worker::isPrint = true;
    cout << endl;

    while (sw_program) {
        cout << "1. Показать все записи;" << endl;
        cout << "2. Пункт а) список работников, стаж работы которых на данном предприятии превышает заданное число лет;" << endl;
        cout << "3. Пункт б) список работников, зарплата которых больше заданной;" << endl;
        cout << "4. Пункт в) список работников, занимающих заданную должность." << endl;
        cout << "5. Проверка создания и удаления объектов " << endl;
        cout << "0. Выход с программы " << endl;

        cout << "Ваш выбор: ";
        cin >> sw;

        // Создание и инициализация массива
        int size = 5;
        worker* Russpace = new worker[size];
        Russpace[0] = { "Иванов И.И", "Бухгалтер", 2000, 23000 };
        Russpace[1] = { "Малахов В.В", "Дизайнер", 2009, 25000 };
        Russpace[2] = { "Перевощиков Н.Д", "Конструктор", 2005, 28000 };
        Russpace[3] = { "Клеша Е.С", "Сборщик", 2012, 31000 };
        Russpace[4] = { "Смирнов Д.С", "Строитель", 2010, 32000 };

        switch (sw)
        {
            case 1:
            {
                system("cls");
                cout << "1. Показать все записи;" << endl;
                worker::isPrint = false;
                cout << endl;

                for (int i = 0; i < size; i++)
                    Russpace[i].show();
                cout << endl;


                system("pause");
                break;
            }

            case 2:
            {
                system("cls");
                cout << "Пункт а) список работников, стаж работы которых на данном предприятии превышает заданное число лет;" << endl;

                worker::isPrint = true;

                input(Russpace[0], "Папин А.В", "Программист", 2001, 30000);
                cout << endl;

                for (int i = 0; i < size; i++)
                    Russpace[i].show();
                cout << endl;

                // Проверка и определение стажа рабочего
                // Год поступления
                int year_receipt;
                // Проверка ошибки, если нет, то 0, иначе 1
                int check_warn = 0;

                // Ставим ограничения по дату, т.е не позволяем пользователю ввести год меньше 1950 и более 2030
                while (check_warn == 0) {
                    cout << "Введите год для выявления стажа сотрудника" << endl;
                    cout << "Введенная дата (год): ";
                    cin >> year_receipt;
                    cout << endl;
                    if ((year_receipt > 1950) && (year_receipt < 2030))
                        check_warn = 1;
                    else
                        cout << "Ошибка! Ввведите разумную дату, т.е не раньше 1950 и не позже 2030" << endl;
                }

                // Здесь хранятся все информация вычета год поступления и значения введенного пользователем
                int* data_year_receipt = new int[size];

                for (int i = 0; i < size; i++)
                {
                    // Получение данные год поступления работы через дружественной функции
                    data_year_receipt[i] = get_year_work_through_friend(Russpace[i]) - year_receipt;

                    if (data_year_receipt[i] < 0) {
                        cout << "ФИО: " << Russpace[i].get_FIO() << endl;
                        cout << "Стаж: " << abs(data_year_receipt[i]) << endl;
                    }
                    else if (data_year_receipt[i] > 0) {
                        cout << "ФИО: " << Russpace[i].get_FIO() << endl;
                        cout << "Поступит через " << data_year_receipt[i] << " лет" << endl;
                    }
                    else if (data_year_receipt[i] == 0) {
                        cout << "ФИО: " << Russpace[i].get_FIO() << endl;
                        cout << "Поступит в текущем году / работает на данный момент" << endl;
                    }
                    cout << endl;
                }
                cout << endl;


                delete[] data_year_receipt;

                system("pause");
                break;
            }

            case 3:
            {
                system("cls");
                cout << "Пункт б) список работников, зарплата которых больше заданной;" << endl;

                // Если не найдена введенная зарплата, тогда 1, иначе 0
                int check_warn = 1;
                worker::isPrint = true;

                for (int i = 0; i < size; i++)
                    Russpace[i].show();
                cout << endl;

                // Проверка и определение стажа рабочего
                // Размер зарплаты
                int size_salary;


                cout << "Введите размер зарплаты сотрудника: ";
                cin >> size_salary;
                cout << endl;

                for (int i = 0; i < size; i++)
                {
                    if (fun_get_salary(Russpace[i]) > size_salary) {
                        cout << "ФИО: " << fun_get_FIO(Russpace[i]) << endl;
                        cout << "Размер зарплаты: " << fun_get_salary(Russpace[i]) << endl;
                        check_warn = 0;
                    }
                    cout << endl;
                }
                cout << endl;

                if (check_warn == 1)
                    cout << "Не найдена должность" << endl << endl;

                system("pause");
                break;
            }

            case 4:
            {
                system("cls");
                cout << "Пункт в) список работников, занимающих заданную должность." << endl;

                // Если не найдена должность, тогда 1, иначе 0
                int check_warn = 1;
                worker::isPrint = true;
                cout << endl;

                for (int i = 0; i < size; i++)
                    Russpace[i].show();
                cout << endl;

                // Проверка и определение стажа рабочего
                // Размер зарплаты
                char* buf = new char[1000];

                cout << "Введите должность сотрудника, которого хотите найти: ";
                cin >> buf;
                cout << endl;

                char* name_post_find = new char[strlen(buf) + 1];
                strcpy(name_post_find, buf);

                for (int i = 0; i < size; i++)
                {
                    if (strcmp(Russpace[i].get_post(), name_post_find) == 0) {
                        Russpace[i].show();
                        check_warn = 0;
                    }
                    //cout << endl;
                }
                cout << endl;

                if (check_warn == 1)
                    cout << "Не найдена должность" << endl << endl;

                // Освобождение памяти
                delete[] buf;
                delete[] name_post_find;

                system("pause");
                break;
            }

            case 5:
            {
                {
                    cout << "Проверка создания и удаления объекта" << endl;

                    worker::isPrint = true;

                    // Выведите его данные на экран.
                    for (int i = 0; i < size; i++)
                        Russpace[i].show();
                    cout << endl;

                    // Опишите простую функцию, которая принимает объект в качестве параметра по значению.
                    input(Russpace[0], "Прокофьев А.В.", "Старший менеджер по продажам", 1990, 175000);

                    // Выведите его данные на экран.
                    Russpace[0].show();
                    cout << endl;

                    // Опишите простую функцию, которая возвращает объект в качестве параметра.
                    Russpace[1] = output(Russpace[0]);

                    // Выведите его данные на экран.
                    Russpace[1].show();
                    cout << endl;

                    // Или возвращает значения по частями вызыванной функции
                    cout << "ФИО: " << fun_get_year_work(Russpace[0]) << endl;
                    cout << "Должность: " << fun_get_post(Russpace[0]) << endl;
                    cout << "Год поступления: " << fun_get_year_work(Russpace[0]) << endl;
                    cout << "Размер зарплаты: " << fun_get_salary(Russpace[0]) << endl;
                    cout << endl;

                    // Создайте динамический объект с инициализацией всех членов - данных.
                    worker* Russpace_din = new worker("Кузнецов А.С.", "Менеджемент", 2002, 135000);

                    // Освобождение памяти
                    delete Russpace_din;

                    // Создайте статический массив объектов.
                    worker SeverStal_array[10];
                }

                system("pause");
                break;
            }

            case 0:
            {
                cout << "Выход с программы" << endl;
                sw_program = false;
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

        // Освобождение памяти
        delete[] Russpace;

        //system("pause");
        system("cls");
    }


}
