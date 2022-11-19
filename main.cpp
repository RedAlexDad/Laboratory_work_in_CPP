/*
Написать программу, в которой тестируется пользовательская функция.
 В программе перегрузить данную функцию для указателей на переменные и для ссылок. Варианты функций см. в таблице:

1.	Сформировать динамический одномерный массив, заполнить его случайными числами и вывести на печать.
2.	Выполнить указанное в варианте задание и вывести полученный массив на печать.
3.	Сформировать динамический двумерный массив, заполнить его случайными числами и вывести на печать.
4.	Выполнить указанное в варианте задание и вывести полученный массив на печать.

№	Процедура
4	Удалить элемент равный среднему арифметическому элементов массива.

*/


#include <iostream>
#include <cmath>

using namespace std;

double discarding_value(double& value)
{
    // Проверка на округление, если округляется в большую сторону, т.е 1,5 = 2
    // То положительный, иначе отрицательный
    double check = value - round(value);

    if (check > 0)
        return value = value - round(value);
    else
        return value = value - int(value);
}

double discarding_value(double* value)
{
    // Проверка на округление, если округляется в большую сторону, т.е 1,5 = 2
    // То положительный, иначе отрицательный
    double check = *value - round(*value);

    if (check > 0)
        return *value = *value - round(*value);
    else
        return *value = *value - int(*value);
}

void func_create_array(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % 50;
        cout << mas[i] << ' ';
    }
    cout << endl << endl;
}

void func_create_array(int** matr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matr[i][j] = rand() % 50;
            cout << matr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;
}

void find_arifm_delete(int* mas, int size)
{
    int sum = 0;

    // Находит среднее арифметическое число
    for (int i = 0; i < size; i++)
        sum += mas[i];

    double arifm_mas = sum / size;
    cout << "Среднее арифметическое число: " << arifm_mas << endl;

    // Временный массив
    int* buf = new int[size];
    int k = 0;

    // Сохраняет все значения отличаемое от среднего арифметического значения
    for (int i = 0; i < size; i++) {
        if (arifm_mas != mas[i]) {
            buf[k] = mas[i];
            k++;
        }
    }

    // Передаем размер массива в size
    size = k;

    // Освобождаем, и опять выделяем память с другим размером
    delete[] mas;
    mas = new int[size];

    for (int i = 0; i < k; i++)
        mas[i] = buf[i];

    // Освобождаем памяти
    delete[] buf;

    for (int i = 0; i < size; i++)
        cout << mas[i] << ' ';

    cout << endl << endl;

    delete[] mas;
}

void find_arifm_delete(int** matr, int row, int col)
{
    int sum = 0, k = 0;

    // Находит среднее арифметическое число
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sum += matr[i][j];

    double arifm_mas = sum / (row * col);
    cout << "Среднее арифметическое число: " << arifm_mas << endl;

    // Временный массив
    int* buf = new int[row*col];

    // Сохраняет все значения отличаемое от среднего арифметического значения
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arifm_mas != matr[i][j]) {
                buf[k] = matr[i][j];
                k++;
            }
        }
    }

    // Передаем размер массива в size
    int mas_size = k;

    int* mas = new int[mas_size];

    for (int i = 0; i < mas_size; i++) {
        // Перезапись поэлементно
        mas[i] = buf[i];
        cout << mas[i] << ' ';
    }

    // Освобождаем памяти
    delete[] buf;
    delete[] mas;
    delete[] matr;

    cout << endl << endl;
}


int main() {
    // system("chcp 1251 > nul");
    system("chcp 65001");
    srand(time(NULL));

    cout << "Лабораторная работа № 1\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";
    cout << "Выберите номер пункта для выполнения задач: \n";
    cout << "1. Индивидуальное задание №1\n";
    cout << "2. Индивидуальное задание №2\n";
    cout << "0. Выход с программы\n";
    cout << "Работа программы:\n\n";

    int sw;
    cin >> sw;

    switch (sw)
    {
        case 1:
        {
            // Индивидуальное задание №1.
            /* Написать программу, в которой тестируется пользовательская функция.
            В программе перегрузить данную функцию для указателей на переменные и для ссылок.
            Варианты функций см. в таблице:*/

            /*Отбрасывает от вещественного числа его целую часть.*/
            cout << "1. Индивидуальное задание №1\n";

            double value_double;

            cout << "Примечание: Знак для десятичных дробей следует поставить точкой\n";
            cout << "Введите любое вещественное (double) число: ";
            cin >> value_double;
            cout << discarding_value(value_double) << endl;

            cin.ignore();

            cout << "Введите любое вещественное (double) число: ";
            cin >> value_double;
            cout << discarding_value(&value_double) << endl;

            system("pause");
            break;
        }
        case 2:
        {
            // Индивидуальное задание №2.
            /* Написать программу, в которой тестируется пользовательская функция.
            В программе перегрузить данную функцию для указателей на переменные и для ссылок.
            Варианты функций см. в таблице:
            Сформировать динамический одномерный массив, заполнить его случайными числами и вывести на печать
            Выполнить указаннеое в варианте задание и вывести полученный массив на печать
            Сформировать динамический двумерный массив, заполнить его случайными числами и вывести на печать
            Выполнить указанное в варианте задание и вывести полученный массив на печать*/

            /* Удалить элемент равный среднему арифметическому элементов массива*/
            cout << "2. Индивидуальное задание №2\n";

            // Одномерный массив

            int size = 10;
            int* mas = new int[size];

            // Для одномерного массива
            func_create_array(mas, size);

            // Находит среднее арифметическое число
            find_arifm_delete(mas, size);

            // Двумерный массив

            const int row = 3;
            const int col = 3;

            int** matr = new int*[row];
            for (int i = 0; i < row; i++)
                matr[i] = new int[col];

            // Для двумерного массива (матрица)
            func_create_array(matr, row, col);

            // Находит среднее арифметическое число
            find_arifm_delete(matr, row, col);

            system("pause");
            break;
        }
        default:
        {
            cout << "Не существует такого пункта. Выход с программы\n";
            system("exit");
            system("pause");
            break;
        }
        case 0:
        {
            cout << "Выход с программы\n";
            system("exit");
            system("pause");
            break;
        }
    }
}
