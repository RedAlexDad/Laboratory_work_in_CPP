/*
Дано целое число С такое, что |С| < 9. Вывести это число в словесной форме, учитывая его знак.
 */

#include <iostream>

using namespace std;

int main()
{
    // system("chcp 1251 > nul");
    system("chcp 65001");
    cout << "Лабораторная работа № 1\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";

    int value;

    cout << "Введите любое число в диапзоне [-9, 9], т.е |число| < 9" << endl;
    cout << "Введенное число: ";
    cin >> value;

    switch (value) 	{

        case -9: { cout << "Минус девять" << endl; 	break; }
        case -8: { cout << "Минус восемь" << endl; 	break; }
        case -7: { cout << "Минус семь" << endl; 	break; }
        case -6: { cout << "Минус шесть" << endl; 	break; }
        case -5: { cout << "Минус пять" << endl; 	break; }
        case -4: { cout << "Минус четыре" << endl; 	break; }
        case -3: { cout << "Минус три" << endl; 	break; }
        case -2: { cout << "Минус два" << endl; 	break; }
        case -1: { cout << "Минус один" << endl; 	break; }
        case 0: { cout << "Ноль" << endl; 	break; }
        case 1: { cout << "Один" << endl; 	break; }
        case 2: { cout << "Два" << endl; 	break; }
        case 3: { cout << "Три" << endl; 	break; }
        case 4: { cout << "Четыре" << endl; 	break; }
        case 5: { cout << "Пять" << endl; 	break; }
        case 6: { cout << "Шесть" << endl; 	break; }
        case 7: { cout << "Семь" << endl; 	break; }
        case 8: { cout << "Восемь" << endl; 	break; }
        case 9: { cout << "Девять" << endl; 	break; }

        default: {cout << "Вне диапзона!" << endl; break; }
    }

}
