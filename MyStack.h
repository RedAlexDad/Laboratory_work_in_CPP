#pragma once
#ifndef PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSTACK_H
#define PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSTACK_H

#include <iostream>

using namespace std;

//Шаблонный класс ListNode (узел односвязного списка)
template <class INF, class FRIEND>
//узел списка
class ListNode
{
private:
    //информационная часть узла
    INF d;
    //указатель на следующий узел списка
    ListNode* next;

    //конструктор
    ListNode() { next = NULL; }
    ListNode(int el = 0) { d = el; next = nullptr; }
    ~ListNode() {
        cout << "ДЕСТРУКТОР! ~ListNode" << endl;
    }

    INF get_d() { return d; }
    void set_d(INF D) { d = D; }
    int size() {
        int size = 1;
        ListNode<INF, FRIEND>* n_tmp = next;
        while (n_tmp) {
            n_tmp = n_tmp->get_next();
            size++;
        }
        return size;
    }

    ListNode* get_next() { return next; }
    void set_next(ListNode* NEXT) {
        this->next = NEXT;
    }

    friend FRIEND;
};

//Шаблонный класс MyStack на основе односвязного списка.
template <class INF>
class MyStack
{
    typedef class ListNode <INF, MyStack <INF>> Node;
    Node* top;
public:

    // конструктор
    MyStack() { top = nullptr; }

    //  Конструктор копирования
    MyStack(MyStack& obj) {
        if (!obj.empty()) {
            const int size = obj.size();
            ListNode<INF, MyStack<INF>>* buff = new ListNode<INF, MyStack<INF>>(*obj.top);
            ListNode<INF, MyStack<INF>>* tmp = new ListNode<INF, MyStack<INF>>(buff->get_d());
            for (int i = 0; i < size; i++) {
                // Адрес следующего узла
                tmp->set_next(top);
                top = tmp;

                // Адрес следующего узла буфера
                if (buff->get_next() == nullptr) break;
                buff = new ListNode<INF, MyStack<INF>>(*buff->get_next());
                tmp = new ListNode<INF, MyStack<INF>>(buff->get_d());
            }
            this->sort_ub();
        }
    }

    // Оператор присваивания
    MyStack& operator=(MyStack& stack) {
        // Если стек пустой, тогда возвращает нулевое значение
        if (stack.empty())
            return *this;

        if (this != &stack) {
            this->clear();
            const int size = stack.size();
            ListNode<INF, MyStack<INF>>* buff = new ListNode<INF, MyStack<INF>>(*stack.top);
            ListNode<INF, MyStack<INF>>* tmp = new ListNode<INF, MyStack<INF>>(buff->get_d());
            for (int i = 0; i < size; i++) {
                // Адрес следующего узла
                tmp->set_next(top);
                top = tmp;

                // Адрес следующего узла буфера
                if (buff->get_next() == nullptr) break;
                buff = new ListNode<INF, MyStack<INF>>(*buff->get_next());
                tmp = new ListNode<INF, MyStack<INF>>(buff->get_d());
            }
            this->sort_ub();
        }
        return *this;
    }

    // освободить динамическую память
    ~MyStack() {
        cout << "ДЕСТРУКТОР! ~Stack" << endl;
        if (this == nullptr) return;
        while (this != nullptr) {
            // top - адрес на первый узел
            ListNode<INF, MyStack<INF>>* tmp = top;
            if (tmp != NULL) {
                top = top->get_next();
                // tmp - текущий адрес
                delete tmp;
            }
            else return;
        }
    }

    // стек пустой? Если пустой, то true
    bool empty() {
        if (top == NULL) return true;
        else return false;
    }

    // добавить узел в вершину стека
    void push(INF el) {
        //ListNode<INF, MyStack<INF>>* tmp = new ListNode(el);
        ListNode<INF, MyStack<INF>>* tmp = new ListNode<INF, MyStack<INF>>(el);

        if (top == nullptr) {
            top = tmp;
        }
        else {
            // Адрес следующего узла
            tmp->set_next(top);
            top = tmp;
        }
    }

    // удалить узел из вершины стека
    bool pop() {
        if (top == nullptr) return false;
        else {
            // ListNode<INF>* tmp = top;
            ListNode<INF, INF>* tmp = top;

            top = top->get_next();
            delete tmp;
            return true;
        }
    }

    //считать информацию из вершины стека
    INF top_inf() { return top->get_d(); }

    Node* get_next() { return top->get_next(); }

    void clear() {
        if (this == nullptr) return;
        while (this != nullptr) {
            // top - адрес на первый узел
            ListNode<INF, MyStack<INF>>* tmp = top;
            if (tmp != nullptr) {
                top = top->get_next();
                // tmp - текущий адрес
                delete tmp;
            }
            else return;
        }
    }

    // Печать
    void print() {
        ListNode<INF, MyStack<INF>>* tmp = top;

        if (top == nullptr) return;

        while (tmp) {
            cout << tmp->get_d();
            tmp = tmp->get_next();
            if (tmp != NULL)
                cout << " * ";
        }
        cout << endl;
    }

    // Определение размеров
    int size() {
        // создаем буфер для восстановления
        ListNode<INF, MyStack<INF>>* buff = top;
        int size = 1;

        if (top == nullptr) return 0;
        while (top->get_next() != nullptr) {
            // check - адрес на первый узел
            ListNode<INF, MyStack<INF>>* tmp = top;
            top = top->get_next();
            size++;
        }
        top = buff;
        return size;
    }

    // Сортировка в возрастающем порядке
    void sort_vos() {
        if (top == nullptr) return;

        // создаем буфер для восстановления
        ListNode<INF, MyStack<INF>>* buff = top;

        int size = top->size();
        INF* arr = new INF[size];

        ListNode<INF, MyStack<INF>>* tmp = top;
        for (int i = 0; i < size; i++) {
            arr[i] = tmp->get_d();
            //cout << "arr [ " << i << " ] = " << arr[i] << endl;
            tmp = tmp->get_next();
        }
        cout << endl;

        // Сортируем по возрастанию
        INF arr_tmp = NULL;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - 1; j++)
                if (arr[j] < arr[j + 1]) {
                    arr_tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = arr_tmp;
                }

        /*cout << "Проверка после сортировки" << endl;
        for (int i = 0; i < size; i++)
            cout << "arr [ " << i << " ] = " << arr[i] << endl;
        cout << endl;*/

        ListNode<INF, MyStack<INF>>* null_stack = nullptr;
        for (int i = 0; i < size; i++) {
            ListNode<INF, MyStack<INF>>* new_stack = new ListNode<INF, MyStack<INF>>(arr[i]);
            if (null_stack == nullptr) {
                null_stack = new_stack;
            }
            else {
                // Адрес следующего узла
                new_stack->set_next(null_stack);
                null_stack = new_stack;
            }
        }

        // Присвоим новый отсортированный стек в текущий стек
        top = null_stack;
    }

    // Сортировка в убывающем порядке
    void sort_ub() {
        if (top == nullptr) return;

        // создаем буфер для восстановления
        ListNode<INF, MyStack<INF>>* buff = top;

        int size = top->size();
        INF* arr = new INF[size];

        ListNode<INF, MyStack<INF>>* tmp = top;
        for (int i = 0; i < size; i++) {
            arr[i] = tmp->get_d();
            //cout << "arr [ " << i << " ] = " << arr[i] << endl;
            tmp = tmp->get_next();
        }
        cout << endl;

        // Сортируем по возрастанию
        INF arr_tmp = NULL;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    arr_tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = arr_tmp;
                }

        /*cout << "Проверка после сортировки" << endl;
        for (int i = 0; i < size; i++)
            cout << "arr [ " << i << " ] = " << arr[i] << endl;
        cout << endl;*/

        ListNode<INF, MyStack<INF>>* null_stack = nullptr;
        for (int i = 0; i < size; i++) {
            ListNode<INF, MyStack<INF>>* new_stack = new ListNode<INF, MyStack<INF>>(arr[i]);
            if (null_stack == nullptr) {
                null_stack = new_stack;
            }
            else {
                // Адрес следующего узла
                new_stack->set_next(null_stack);
                null_stack = new_stack;
            }
        }

        // Присвоим новый отсортированный стек в текущий стек
        top = null_stack;
    }
};

void Multipliers(int n, MyStack<int>& stack);

#endif //PROGRAMMING_ON_CLASS_AND_TEMPLATE_MYSTACK_H
