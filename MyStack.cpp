#include "MyStack.h"
#include <iostream>

using namespace std;

void Multipliers(int n, MyStack<int>& stack) {
    int div = 2;
    const int value = n;

    if (n > 1) {
        while (n > 1) {
            while (n % div == 0) {
                n = n / div;
                stack.push(div);
            }
            if (div == 2) div++;
            else div = div + 2;
        }
    }
    else {
        stack.push(n);
    }

    cout << value << " = ";
    stack.print();

    // Сортировка в возрастающем порядке
    stack.sort_vos();

    cout << value << " = ";
    stack.print();
    cout << endl;
}
