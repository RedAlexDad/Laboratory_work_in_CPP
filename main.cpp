// LAB_04_Overload_operation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
4.1.Создать и русифицировать консольный проект в VS.
Последовательность действий для создания консольного проекта в VS описана
в методических указаниях к ЛР № 1 для данного курса (ПКШ).
Русификация ввода и вывода информации в проекте для консольного режима выполняется на основе приемов,
также показанных в методических указаниях к ЛР №1.

4.2. Варианты для выполнения заданий ЛР
До начала выполнения ЛР необходимо познакомиться с таблицей вариантов для студентов
(см. ниже) и выполнять задание следующих пунктов в соответствии со своим вариантом.

4.3. Внутренняя одноместная перегрузка операций
ПЕРЕГРУЗКА ОДНОМЕСТНАЯ. Описать простой класс по варианту (в заголовочном файле проекта).
Переменные класса должны быть закрытыми. В этом классе (например, Point и т.д.)
перегрузить одноместные операции: “++” и “--” (методом класса).
Продемонстрировать в главной программе использование этих операций.
Операция “++” описывается внутри класса, а операция “--” описывается
вне класса (как в примере). Вывести результаты и сохранить их в отчете по ЛР.

4.4. Внутренняя двуместная перегрузка операций
ПЕРЕГРУЗКА ДВУМЕСТНАЯ. В этом классе (например, Point и т.д.) перегрузить двуместные
операции: “+” и “-”. Продемонстрировать в главной программе использование этих операций.
Операция “-” описывается внутри класса, а операция “+” описывается вне класса.
Вывести результаты и сохранить их в отчете по ЛР.

4.5. Внешняя одноместная перегрузка операций
ДРУЖЕСТВЕННАЯ ОДНОМЕСТНАЯ. Создать новый класс, построенный на основе класса
предыдущего класса путем копирования и переименования класса (Например - Point1 и т.д.).
Перегрузить одноместную операцию “-” (одноместный минус) с помощью дружественной функции.
Продемонстрировать в главной программе ее применение. Вывести результаты и сохранить их в отчете по ЛР.

4.6. Внешняя двуместная перегрузка операций
ДРУЖЕСТВЕННАЯ ДВУМЕСТНАЯ. В этом классе (Point1 и т.д.) выполнить внешнюю
перегрузку двуместной операции умножения на константу (“*”).
Например, изменение размера геометрической фигуры.
Продемонстрировать в главной программе применение этой операции.
Результаты вывести.  Вывести результаты и сохранить их в отчете по ЛР.

4.7. Перегрузка операций потокового ввода и вывода
ПЕРЕГРУЗКА ВВОДА И ВЫВОДА. Для собственного класса произвести перегрузку
операций потокового ввода-вывода. Класс взять из предыдущего пункта задания.
Продемонстрировать использование операций в главной программе.
Вывести результаты и сохранить их в отчете по ЛР.

4.8. Перегрузка операций индексирования
ПЕРЕГРУЗКА ИНДЕКСИРОВАНИЯ. Для класса Mas (см. пример в теоретической части ЛР)
произвести перегрузку операции индексирования. В цикле заполнить массив и его распечатать.
Продемонстрировать использование операций в главной программе.
Вывести результаты и сохранить их в отчете по ЛР.

4.9. Перегрузка операций сравнения
ПЕРЕГРУЗКА СРАВНЕНИЯ. Для своего класса по варианту (Point1 и т.д )
произвести перегрузку  операции сравнения (“==”).
Продемонстрировать использование операций в главной программе.
Вывести результаты и сохранить их в отчете по ЛР.

4.10. Перегруженная операция присваивания и конструктор копирования
Перегрузить операции присваивания, потокового ввода-вывода, конструктор копирования.
Продемонстрировать в главной программе использование этих перегрузок.
Вывести результаты и сохранить их в отчете по ЛР.

*/

#include <iostream>
#include "Rect.h"

#pragma warning(disable : 4996)

using namespace std;

int Rect::count_check = 0;
bool Rect::count_check_bool = false;

int main()
{
    system("chcp 65001");

    cout << "Лабораторная работа № 4\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    // Содание объекта
    Rect obj, obj1;

    // Присваивание значений
    obj.set_a(1);
    obj.set_b(-2);

    // Вывод на КО
    cout << obj << endl;

    // Постфиксная операция
    //obj++;
    cout << "Постфиксная операция: " << obj++ << endl;
    cout << "Печать после постфиксной операции: " << obj << endl;
    // Префиксная операция
    //++obj;
    cout << "Префиксная операция: " << ++obj << endl;
    cout << "Печать после префиксной операции: " << obj << endl;
    // Пост-декремент
    //obj--;
    cout << "Пост-декремент: " << obj-- << endl;
    // Пре-декремент
    //--obj;
    cout << "Пре-декремент: " << --obj << endl;

    // Копирования
    obj1 = obj;
    cout << "Копирования: " << obj1 << endl;

    // Сложение
    obj.set_a(5);
    cout << "Данные перед операций: сложение и вычитание: " << obj << endl;
    cout << "Сложение: " << obj1 + obj << endl;
    // Вычитание
    cout << "Вычитание: " << obj1 - obj << endl;

    // Умножение
    cout << "Умножение: " << obj * obj1 << endl;

    // Выичсление площади
    cout << "Печать: " << obj << endl;
    cout << "Вычисление площади прямоугольника: " << obj.get_a() * obj.get_b() << endl;
    cout << "Сравнение площади прямоугольника: " << endl;
    cout << "Печать obj: " << obj << endl;
    cout << "Печать obj1: " << obj1 << endl;

    // Сравнение
    if (obj < obj1)
        cout << "У obj больше" << endl;
    else
        cout << "У obj1 больше" << endl;

    // перегрузка дружественной функцией операции (объект*const);
    cout << obj * 10 << endl;

    // Перегрузка дружественной функцией операции(-объект);
    // Т.е изменение знака на противоположный
    cout << obj << endl;
    cout << -obj << endl;


    // Перегрузка индексирования
    int ARRAY[] = { 10, 11, 12, 13, 14, 15 };
    Mas NewARRAY(ARRAY, sizeof(ARRAY) / sizeof(int));
    cout << "NewMas[4] = " << NewARRAY[4] << endl;
    NewARRAY[4] = 10;
    cout << "NewMas[4] = " << NewARRAY[4] << endl;
}
