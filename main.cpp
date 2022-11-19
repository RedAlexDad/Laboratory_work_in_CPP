// Practium.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyVector.h"
#include "MySet.h"
#pragma warning(disable : 4996)

using namespace std;



int main()
{
    system("chcp 65001");


    while (true) {
        system("cls");
        cout << "Введите номер пункта для выполнения заданий:" << endl;
        cout << "№1 Разложение на простые множители целого числа N с применением stack" << endl;
        cout << "№2 Множество, выполняющее несколько операций над множествами" << endl;
        cout << "№0 Выход с программы." << endl;

        int sw;
        cout << "Номер пункта: ";
        cin >> sw;

        switch (sw)
        {
            case 1:
            {
                system("cls");
                cout << "№1 Разложение на простые множители целого числа N с применением stack" << endl;

                cout << "Введите любое целое число для разложения" << endl;
                cout << "Пример, пусть дан число N = 3960" << endl
                     << "Разложили его так (в убывающем порядке):\n\t3960 = 11 * 5 * 3 * 3 * 2 * 2 * 2" << endl
                     << "Разложили его так (в возрастающем порядке):\n\t3960 = 2 * 2 * 2 * 3 * 3 * 5 * 11" << endl;
                cout << endl;

                int value = NULL;
                MyStack<int> obj;
                cout << "Введите любое число для разложения" << endl;
                cout << "Число: ";
                cin >> value;
                cout << endl;

                Multipliers(value, obj);

                MyStack<int> obj1(obj), obj2;
                obj2 = obj;
                cout << "Проверка конструктора копирования и перегрузка присваивания" << endl;
                cout << "obj1(obj): ";
                obj1.print();
                cout << "obj2 = obj: ";
                obj2.print();

                system("pause");
                break;
            } case 2:
            {
                system("cls");
                cout << "№2 Множество, выполняющее несколько операций над множествами" << endl;

                MyVector<string> v("Hello!");
                cout << v << endl;
                cout << endl;


                v.add_element("Привет!");
                v.add_element("Привет!");
                v.add_element("Привет!");
                v.add_element("Привет!");
                v.add_element("Привет!");
                cout << "Вектор v: " << v << endl;
                cout << endl;

                v.add_element("Привет!");
                v.add_element("Привет!");
                v.add_element("Привет!");
                cout << "Вектор v: " << v << endl;
                cout << endl;

                cout << "find: " << v.find("Привет!") << endl;
                cout << endl;

                MyVector<> v1 = v;
                MyVector<> v2(v);

                cout << "Вектор v1: " << v1 << endl;
                cout << "Вектор v2(v): " << v2 << endl;

                for (int i = 0; i < MAX_SIZE; i++)
                    v1.delete_element(0);
                cout << "Вектор v1: " << v1 << endl;

                cout << endl;
                cout << "==============================================================" << endl;
                cout << "Множество типа string" << endl;
                cout << "==============================================================" << endl;
                cout << endl;
                system("pause");

                {
                    MySet<> s("Yes");
                    MySet<> s1, s2;

                    s.add_element("Привет!");
                    s.add_element("No");
                    char* str = (char*)"Hello!";
                    s.add_element(str);
                    cout << s << endl;
                    cout << "Множество s: " << s << endl;
                    //cout << endl;

                    s1.add_element("Cat");
                    s1.add_element("No");
                    s1.add_element("Привет!");
                    cout << "Множество s1: " << s1 << endl;
                    //cout << endl;

                    s2 = s1 - s;
                    cout << "Множество s2 = s1 - s: " << s2 << endl;
                    cout << endl;

                    cout << "Множество s1: " << s1 << endl;
                    cout << "Множество s: " << s << endl;
                    s2 = s - s1;
                    cout << "Множество s2 = s - s1: " << s2 << endl;
                    cout << endl;

                    cout << "Множество s1: " << s1 << endl;
                    cout << "Множество s: " << s << endl;
                    s2 = s1 + s;
                    cout << "Множество s2 = s1 + s: " << s2 << endl;
                    cout << endl;

                    cout << "Множество s1: " << s1 << endl;
                    cout << "Множество s: " << s << endl;
                    s2 = s1 * s;
                    cout << "Множество s2 = s1 * s: " << s2 << endl;
                    cout << endl;

                    cout << "Множество s1: " << s1 << endl;
                    cout << "Множество s: " << s << endl;
                    MySet<> s3 = s2;
                    MySet<> s4(s2);
                    cout << "Множество s3 = s2: " << s3 << endl;
                    cout << "Множество s4(s2): " << s4 << endl;
                    cout << endl;

                    if (s3 == s2)
                        cout << "Множество s3 = s2\n";
                    else
                        cout << "Множество s3 != s2\n";
                    if (s3 == s1)
                        cout << "Множество s3 = s1\n";
                    else
                        cout << "Множество s3 != s1\n";
                    if (s1 == s3)
                        cout << "Множество s1 = s3\n";
                    else
                        cout << "Множество s1 != s3\n";
                    cout << endl;

                    cout << "Множество s2: " << s2 << endl;
                    cout << "Множество s: " << s << endl;
                    s2 += s;
                    cout << "Множество s2 += s (s2 = s2 + s): " << s2 << endl;
                    cout << endl;

                    cout << "Множество s1: " << s1 << endl;
                    cout << "Множество s: " << s << endl;
                    s1 -= s;
                    cout << "Множество s1 -= s (s1 = s1 - s): " << s1 << endl;
                    cout << endl;

                    cout << "Множество s2: " << s2 << endl;
                    cout << "Множество s1: " << s1 << endl;
                    s2 *= s1;
                    cout << "Множество s2 *= s1 (s2 = s2 * s1): " << s2 << endl;
                    cout << endl;
                }

                cout << endl;
                cout << "==============================================================" << endl;
                cout << "Множество типа int" << endl;
                cout << "==============================================================" << endl;
                cout << endl;
                system("pause");

                {
                    MySet<int> i(0);
                    MySet<int> i1, i2;

                    i.add_element(1);
                    i.add_element(3);
                    i.add_element(5);
                    i.add_element(7);
                    cout << "Множество i: " << i << endl;
                    //cout << endl;

                    i1.add_element(0);
                    i1.add_element(2);
                    i1.add_element(4);
                    i1.add_element(5);
                    i1.add_element(6);
                    i1.add_element(8);
                    cout << "Множество i1: " << i1 << endl;
                    //cout << endl;

                    i2 = i1 - i;
                    cout << "Множество i2 = i1 - i: " << i2 << endl;
                    cout << endl;

                    cout << "Множество i1: " << i1 << endl;
                    cout << "Множество i: " << i << endl;
                    i2 = i - i1;
                    cout << "Множество i2 = i - i1: " << i2 << endl;
                    cout << endl;

                    cout << "Множество i1: " << i1 << endl;
                    cout << "Множество i: " << i << endl;
                    i2 = i1 + i;
                    cout << "Множество i2 = i1 + i: " << i2 << endl;
                    i2.sort();
                    cout << "Множество i2 после сортировки: " << i2 << endl;
                    cout << endl;

                    cout << "Множество i1: " << i1 << endl;
                    cout << "Множество i: " << i << endl;
                    i2 = i1 * i;
                    cout << "Множество i2 = i1 * i: " << i2 << endl;
                    cout << endl;

                    cout << "Множество i1: " << i1 << endl;
                    cout << "Множество i: " << i << endl;
                    MySet<int> i3 = i2;
                    MySet<int> i4(i2);
                    cout << "Множество i3 = s2: " << i3 << endl;
                    cout << "Множество i4(i2): " << i4 << endl;
                    cout << endl;

                    if (i3 == i2)
                        cout << "Множество i3 = i2\n";
                    else
                        cout << "Множество i3 != i2\n";
                    if (i3 == i1)
                        cout << "Множество i3 = i1\n";
                    else
                        cout << "Множество i3 != i1\n";
                    if (i1 == i3)
                        cout << "Множество i1 = i3\n";
                    else
                        cout << "Множество i1 != i3\n";
                    cout << endl;

                    cout << "Множество i2: " << i2 << endl;
                    cout << "Множество i: " << i << endl;
                    i2 += i;
                    cout << "Множество i2 += i (i2 = i2 + i): " << i2 << endl;
                    cout << endl;

                    cout << "Множество i1: " << i1 << endl;
                    cout << "Множество i: " << i << endl;
                    i1 -= i;
                    cout << "Множество i1 -= i (i1 = i1 - i): " << i1 << endl;
                    cout << endl;

                    cout << "Множество i2: " << i2 << endl;
                    cout << "Множество i1: " << i1 << endl;
                    i2 *= i1;
                    cout << "Множество i2 *= i1 (i2 = i2 * i1): " << i2 << endl;
                    cout << endl;
                }

                cout << endl;
                cout << "==============================================================" << endl;
                cout << "Множество типа char*" << endl;
                cout << "==============================================================" << endl;
                cout << endl;
                system("pause");

                {
                    MySet<char*> c((char*)"First");
                    MySet<char*> c1, c2;

                    c.add_element((char*)"second");
                    c.add_element((char*)"third");
                    c.add_element((char*)"four");
                    c.add_element((char*)"five");
                    cout << "Множество c: " << c << endl;
                    //cout << endl;

                    c1.add_element((char*)"six");
                    c1.add_element((char*)"eleven");
                    c1.add_element((char*)"five");
                    c1.add_element((char*)"four");
                    c1.add_element((char*)"ten");
                    c1.add_element((char*)"eleven");
                    cout << "Множество c1: " << c1 << endl;
                    //cout << endl;

                    c2 = c1 - c;
                    cout << "Множество c2 = c1 - c: " << c2 << endl;
                    cout << endl;

                    cout << "Множество c1: " << c1 << endl;
                    cout << "Множество c: " << c << endl;
                    c2 = c - c1;
                    cout << "Множество c2 = c - c1: " << c2 << endl;
                    cout << endl;

                    cout << "Множество c1: " << c1 << endl;
                    cout << "Множество c: " << c << endl;
                    c2 = c1 + c;
                    cout << "Множество c2 = c1 + c: " << c2 << endl;
                    cout << endl;

                    cout << "Множество c1: " << c1 << endl;
                    cout << "Множество c: " << c << endl;
                    c2 = c1 * c;
                    cout << "Множество c2 = c1 * c: " << c2 << endl;
                    cout << endl;

                    cout << "Множество c1: " << c1 << endl;
                    cout << "Множество c: " << c << endl;
                    MySet<char*> c3 = c2;
                    MySet<char*> c4(c2);
                    cout << "Множество c3 = s2: " << c3 << endl;
                    cout << "Множество c4(c2): " << c4 << endl;
                    cout << endl;

                    if (c3 == c2)
                        cout << "Множество c3 = c2\n";
                    else
                        cout << "Множество c3 != c2\n";
                    if (c3 == c1)
                        cout << "Множество c3 = c1\n";
                    else
                        cout << "Множество c3 != c1\n";
                    if (c1 == c3)
                        cout << "Множество c1 = c3\n";
                    else
                        cout << "Множество c1 != c3\n";
                    cout << endl;

                    cout << "Множество c2: " << c2 << endl;
                    cout << "Множество c: " << c << endl;
                    c2 += c;
                    cout << "Множество c2 += c (c2 = c2 + c): " << c2 << endl;
                    cout << endl;

                    cout << "Множество c1: " << c1 << endl;
                    cout << "Множество c: " << c << endl;
                    c1 -= c;
                    cout << "Множество c1 -= c (c1 = c1 - c): " << c1 << endl;
                    cout << endl;

                    cout << "Множество c2: " << c2 << endl;
                    cout << "Множество c1: " << c1 << endl;
                    c2 *= c1;
                    cout << "Множество c2 *= c1 (c2 = c2 * c1): " << c2 << endl;
                    cout << endl;
                }

                system("pause");
                break;
            }
            case 0:
            {
                exit(1);
            }
            default:
            {
                cout << "Введенный Вами пункт не существует. Возврат в меню!";
                break;
            }
        }
    }
}
