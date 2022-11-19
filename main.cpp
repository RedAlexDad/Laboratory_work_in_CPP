// DZ_04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Class.h"
#include <locale>
// #pragma warning(disable : 4996)

using namespace std;

int BUS::count = 0;

int main()
{
    system("chcp 65001");
    // setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Домашнее задание:\n Моделирование работы автобусного парка\n Папин А.В., ИУ5Ц-41Б \n Вариант № 4\n\n";
    system("pause");
    // Размер объекта класса
    int size = NULL;
    // Сигнал предупреждения о отсутствии содержимого файла
    bool warning = true;
    bool check = true;

    //BUS *Moscow = new BUS[size];
    // Список автобусов, находящихся в парке и на маршруте
    vector <BUS> Moscow(size);
    //Moscow.resize(size);

    // Создаем новый файл
    fstream DB;

    while (true) {
        system("cls");

        // Проверка на пустого класса
        if (check_class(Moscow) == true) {
            //cout << "Пустой класс" << endl;
            // Если пустой класс, то из файла заполяют в класс
            read_and_add_into_class_TextFile(DB, Moscow, size);
            // Если содержимое в файле нет, тогда в классе нет содержимых,
            // теперь потребуется подтверждении о отсутствии содержимых в классе
            if (!Moscow.empty())
                warning = false;
        }
        else {
            warning = false;
            //print(Moscow);
            //cout << "Класс не пустой" << endl;
            //cout << endl;

            // Файл не пустой
        }

        cout << "№1. Начальное формирование данных" << endl;
        if (!warning) {
            cout << "№2. Имитация выезда автобуса из парка" << endl;
            cout << "№3. Имитация въезда автобуса в парк" << endl;
            cout << "№4. Вывод сведений об автобусах" << endl;
            cout << "№5. Операция над данными" << endl;
        }
        cout << "№0. Выход с программы" << endl;

        int sw;

        // Не позволяет пользователю выбрать другой пункт
        while (check) {
            cout << "Введите номер пункт: ";
            cin >> sw;
            if (warning) {
                if (sw == 1 || sw == 0) check = false;
                else
                    cout << "Ошибка! Введите перечень доступных пунктов!" << endl;
            }
            else {
                check = false;
            }
        }
        check = true;

        switch (sw)
        {
            case 1:
            {
                system("cls");
                cout << "№1. Начальное формирование данных" << endl;

                cout << "Введите новый размер объект класса: ";
                cin >> size;
                Moscow.resize(size);

                // Поддержка на правильность оформления
                support_build_text();

                for (int i = 0; i < size; i++) {
                    cin >> Moscow[i];
                    cout << endl;
                }
                // Присвоим начальные формированные данные
                writeTextFile(DB, Moscow);

                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                cout << "№2. Имитация выезда автобуса из парка" << endl;

                string number, request;
                bool check = true;
                // Функция, предлагающаяся на распечатку всех данных
                offer_for_printing(Moscow);

                // Функция, подсказывающаяся на правильность оформлении
                support_build_text();

                cout << "Введите номер автобуса, который собирался выехать с автобусного парка" << endl;
                cin.ignore();
                cin_number_request(number);

                // Определение и удаление номер текущего автобуса с автобусного парка и добавление в список маршрутов
                delete_number_bus(Moscow, number);

                // Присвоим начальные формированные данные
                writeTextFile(DB, Moscow);

                system("pause");
                break;
            }
            case 3:
            {
                system("cls");
                cout << "№3. Имитация въезда автобуса в парк" << endl;

                string number, request;
                bool check = true;

                // Функция, предлагающаяся на распечатку всех данных
                offer_for_printing(Moscow);

                // Функция, подсказывающаяся на правильность оформлении
                support_build_text();

                cout << "Введите номер автобуса, который собирался въехать в автобусный парк" << endl;
                cin.ignore();
                cin_number_request(number);

                add_number_bus(Moscow, number);

                // Присвоим начальные формированные данные
                writeTextFile(DB, Moscow);


                system("pause");
                break;
            }
            case 4:
            {
                system("cls");
                cout << "№4. Вывод сведений об автобусах." << endl;

                cout << "Список автобусов, находящихся в автобусном парке: " << endl << endl;
                // ЧТЕНИЕ И РАСПЕЧАТКА ФАЙЛА
                //readTextFile(DB);
                print_also_park(Moscow);

                cout << "Список автобусов, находящихся на маршруте: " << endl << endl;
                print_also_route(Moscow);

                system("pause");
                break;
            }
            case 5:
            {
                system("cls");
                cout << "№5. Операция над данными" << endl;

                cout << "Введите нижеперечисленные пункты, которых вы будете взаимодействовать" << endl;

                cout << "№1. Добавление данных" << endl;
                cout << "№2. Изменение данных" << endl;
                cout << "№3. Удаление данных" << endl;
                cout << "№4. Отсортировать по алфавитному порядку по возрастанию" << endl;
                cout << "№5. Отсортировать по алфавитному порядку по убыванию" << endl;
                cout << "№0. Назад в меню" << endl;

                cout << "Введите номер пункт: ";
                cin >> sw;

                switch (sw)
                {
                    case 1:
                    {
                        cout << "№1. Добавление данных" << endl;

                        // Поддержка на правильность оформлении
                        support_build_text();

                        BUS tmp;
                        cin >> tmp;

                        if (check_number_bus(Moscow, tmp)) {
                            cout << "Данный новый номер совпадает с номером в базе данных! Отмена добавление. Возврат в меню!" << endl;
                            system("pause");
                        }
                        else {
                            // Добавление элемент в конец вектора
                            Moscow.emplace_back(tmp);
                        }

                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        cout << "№2. Изменение данных" << endl;

                        string number = "";
                        bool check_0 = true;
                        // Если пользователь вводит несколько ошибок, тогда перебрасывает в меню
                        int count_warn = 0;
                        int id = NULL;

                        // Функция, предлагающаяся на распечатку всех данных
                        offer_for_printing(Moscow);
                        cin.ignore();

                        // Функция, подсказывающаяся на правильность оформлении
                        support_build_text();
                        cin.ignore();
                        cout << endl;

                        cout << "Введите номер автобуса для поиска" << endl;

                        while (check_0) {
                            cin_number_request(number);

                            if (!check_cin_number(Moscow, number, id)) {
                                cout << "Данный номер не существует в базе данных. Повторно введите" << endl;
                                count_warn++;
                            }
                            else {
                                cout << "Данный номер существует в базе данных!" << endl;
                                check_0 = false;
                            }
                            if (count_warn == 3) break;
                        }
                        if (count_warn == 3) {
                            cout << "Вы ввели несколько ошибок. Возврат в главное меню" << endl;
                            break;
                        }

                        cout << endl;
                        cout << "Введите номер пункта для изменения данных:" << endl;
                        cout << "№1. Номера автобуса" << endl;
                        cout << "№2. Фамилия и инициалы водителя" << endl;
                        cout << "№3. Номер маршрута" << endl;
                        cout << "№0. Назад" << endl;

                        cout << "Введите номер пункт: ";
                        cin >> sw;
                        cout << endl;

                        switch (sw)
                        {
                            case 1:
                            {
                                string str;
                                cout << "Введите новый номер автобуса: ";
                                cin.ignore();
                                getline(cin, str, '\n');

                                if (!check_cin_number_bus(str)) {
                                    cout << "Ошибка оформления! Возврат в главное меню." << endl;
                                    system("pause");
                                    break;
                                }

                                for (int i = 0; i < Moscow.size(); i++) {
                                    if (Moscow[i].get_id() == id) {
                                        Moscow[i].set_number_bus(str);
                                        break;
                                    }
                                }

                                writeTextFile(DB, Moscow);

                                break;
                            }
                            case 2:
                            {
                                string str;
                                cout << "Введите новые фамилия и инициалы водителя: ";
                                cin.ignore();
                                getline(cin, str, '\n');

                                if (!check_cin_FIODRIVER(str)) {
                                    cout << "Ошибка оформления! Возврат в главное меню." << endl;
                                    system("pause");
                                    break;
                                }

                                for (int i = 0; i < Moscow.size(); i++) {
                                    if (Moscow[i].get_id() == id) {
                                        Moscow[i].set_FIODRIVER(str);
                                        break;
                                    }
                                }

                                writeTextFile(DB, Moscow);

                                break;
                            }
                            case 3:
                            {
                                int new_route;
                                cout << "Введите новый номер маршрута: ";
                                cin >> new_route;

                                if (!(new_route > 0 && new_route < 1000)) {
                                    cout << "Ошибка! Номер должен быть не более 1000 и не менее 1!\nВозврат в главное меню." << endl;
                                    system("pause");
                                    break;
                                }

                                for (int i = 0; i < Moscow.size(); i++) {
                                    if (Moscow[i].get_id() == id) {
                                        Moscow[i].set_route_number(new_route);
                                        break;
                                    }
                                }

                                writeTextFile(DB, Moscow);

                                break;
                            }
                            case 0:
                            {
                                cout << "Возврат в главное меню" << endl;
                                break;
                            }
                            default:
                            {
                                cout << "Ошибка! Указанный номер пункта отсутствует! Возврат к главному меню!" << endl;
                                system("pause");
                                break;
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        cout << "№3. Удаление данных" << endl;

                        string number = "";
                        bool check_0 = true;
                        // Если пользователь вводит несколько ошибок, тогда перебрасывает в меню
                        int count_warn = 0;
                        int id = NULL;

                        // Функция, предлагающаяся на распечатку всех данных
                        offer_for_printing(Moscow);

                        cout << "Введите номер автобуса для поиска" << endl;
                        cin.ignore();

                        // Функция, подсказывающаяся на правильность оформлении
                        support_build_text();
                        cin.ignore();

                        while (check_0) {
                            cin_number_request(number);

                            if (!check_cin_number(Moscow, number, id)) {
                                cout << "Данный номер не существует в базе данных. Повторно введите" << endl;
                                count_warn++;
                            }
                            else {
                                cout << "Данный номер существует в базе данных!" << endl;
                                check_0 = false;
                            }
                            if (count_warn == 3) break;
                        }
                        if (count_warn == 3) {
                            cout << "Вы ввели несколько ошибок. Возврат в главное меню" << endl;
                            break;
                        }

                        for (int i = 0; i < Moscow.size(); i++) {
                            if (Moscow[i].get_id() == id) {
                                Moscow.erase(Moscow.begin() + i);
                                break;
                            }
                        }

                        writeTextFile(DB, Moscow);

                        break;
                    }
                    case 4:
                    {
                        system("cls");
                        cout << "№4. Отсортировать по алфавитному порядку по возрастанию" << endl;

                        // а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я

                        cout << "Введите номер пункта для изменения данных:" << endl;
                        cout << "№1. Сортировать по номеру автобуса" << endl;
                        cout << "№2. Сортировать по фамилию водителя" << endl;
                        cout << "№3. Сортировать по номеру маршруту" << endl;
                        cout << "№0. Назад" << endl;

                        cout << "Введите номер пункт: ";
                        cin >> sw;
                        cout << endl;

                        switch (sw)
                        {
                            case 1:
                            {
                                int str_size0 = NULL, str_size1 = NULL, size = NULL, length = 0;
                                string str0 = "", str1 = "";
                                BUS tmp;
                                for (int k = 0; k < Moscow.size(); k++)
                                    for (int i = 0; i < Moscow.size() - 1; i++) {

                                        str_size0 = Moscow[i].get_number_bus().size();
                                        str_size1 = Moscow[i + 1].get_number_bus().size();

                                        if (str_size0 > str_size1)
                                            size = str_size1;
                                        else
                                            size = str_size0;

                                        for (int j = 0; j < 2; j++) {
                                            str0 = str0 + Moscow[i].get_number_bus()[j];
                                            str1 = str1 + Moscow[i + 1].get_number_bus()[j];
                                            if (str0 > str1) {
                                                tmp = Moscow[i];
                                                Moscow[i] = Moscow[i + 1];
                                                Moscow[i + 1] = tmp;
                                                break;
                                            }
                                        }
                                        str0 = ""; str1 = "";
                                    }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 2:
                            {
                                int str_size0 = NULL, str_size1 = NULL, size = NULL, length = 0;
                                string str0 = "", str1 = "";
                                BUS tmp;
                                for (int k = 0; k < Moscow.size(); k++)
                                    for (int i = 0; i < Moscow.size() - 1; i++) {

                                        str_size0 = Moscow[i].get_FIODRIVER().size();
                                        str_size1 = Moscow[i + 1].get_FIODRIVER().size();

                                        if (str_size0 > str_size1)
                                            size = str_size1;
                                        else
                                            size = str_size0;

                                        for (int j = 0; j < 2; j++) {
                                            str0 = str0 + Moscow[i].get_FIODRIVER()[j];
                                            str1 = str1 + Moscow[i + 1].get_FIODRIVER()[j];
                                            if (str0 > str1) {
                                                tmp = Moscow[i];
                                                Moscow[i] = Moscow[i + 1];
                                                Moscow[i + 1] = tmp;
                                                break;
                                            }
                                        }
                                        str0 = ""; str1 = "";
                                    }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 3:
                            {
                                int str0, str1, size = 0, sizecheck = 0;
                                BUS tmp;
                                bool value_check = true;
                                for (int i = 0; i < Moscow.size() - 1; i++) {
                                    for (int j = 0; j < Moscow.size() - 1; j++) {
                                        str0 = Moscow[j].get_route_number();
                                        str1 = Moscow[j + 1].get_route_number();

                                        if (str0 > str1)
                                            sizecheck = str1;
                                        else
                                            sizecheck = str0;

                                        while (value_check) {
                                            if (sizecheck == 0) { value_check = false; break; }
                                            sizecheck = sizecheck / 10;
                                            size++;
                                        }

                                        if (str0 > str1) {
                                            tmp = Moscow[j];
                                            Moscow[j] = Moscow[j + 1];
                                            Moscow[j + 1] = tmp;
                                            //break;
                                        }
                                    }
                                }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 0:
                            {
                                cout << "Возврат в главное меню" << endl;
                                break;
                            }
                            default:
                            {
                                cout << "Ошибка! Указанный номер пункта отсутствует! Возврат к главному меню!" << endl;
                                system("pause");
                                break;
                            }
                        }

                        break;
                    }
                    case 5:
                    {
                        system("cls");
                        cout << "№5. Отсортировать по алфавитному порядку по убыванию" << endl;

                        // а, б, в, г, д, е, ё, ж, з, и, й, к, л, м, н, о, п, р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я

                        cout << "Введите номер пункта для изменения данных:" << endl;
                        cout << "№1. Сортировать по номеру автобуса" << endl;
                        cout << "№2. Сортировать по фамилию водителя" << endl;
                        cout << "№3. Сортировать по номеру маршруту" << endl;
                        cout << "№0. Назад" << endl;

                        cout << "Введите номер пункт: ";
                        cin >> sw;
                        cout << endl;

                        switch (sw)
                        {
                            case 1:
                            {
                                int str_size0 = NULL, str_size1 = NULL, size = NULL, length = 0;
                                string str0 = "", str1 = "";
                                BUS tmp;
                                for (int k = 0; k < Moscow.size(); k++)
                                    for (int i = 0; i < Moscow.size() - 1; i++) {

                                        str_size0 = Moscow[i].get_number_bus().size();
                                        str_size1 = Moscow[i + 1].get_number_bus().size();

                                        if (str_size0 > str_size1)
                                            size = str_size1;
                                        else
                                            size = str_size0;

                                        for (int j = 0; j < 2; j++) {
                                            str0 = str0 + Moscow[i].get_number_bus()[j];
                                            str1 = str1 + Moscow[i + 1].get_number_bus()[j];
                                            if (str0 < str1) {
                                                tmp = Moscow[i];
                                                Moscow[i] = Moscow[i + 1];
                                                Moscow[i + 1] = tmp;
                                                break;
                                            }
                                        }
                                        str0 = ""; str1 = "";
                                    }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 2:
                            {
                                int str_size0 = NULL, str_size1 = NULL, size = NULL, length = 0;
                                string str0 = "", str1 = "";
                                BUS tmp;
                                for (int k = 0; k < Moscow.size(); k++)
                                    for (int i = 0; i < Moscow.size() - 1; i++) {

                                        str_size0 = Moscow[i].get_FIODRIVER().size();
                                        str_size1 = Moscow[i + 1].get_FIODRIVER().size();

                                        if (str_size0 > str_size1)
                                            size = str_size1;
                                        else
                                            size = str_size0;

                                        for (int j = 0; j < 2; j++) {
                                            str0 = str0 + Moscow[i].get_FIODRIVER()[j];
                                            str1 = str1 + Moscow[i + 1].get_FIODRIVER()[j];
                                            if (str0 < str1) {
                                                tmp = Moscow[i];
                                                Moscow[i] = Moscow[i + 1];
                                                Moscow[i + 1] = tmp;
                                                break;
                                            }
                                        }
                                        str0 = ""; str1 = "";
                                    }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 3:
                            {
                                int str0, str1, size = 0, sizecheck = 0;
                                BUS tmp;
                                bool value_check = true;
                                for (int i = 0; i < Moscow.size() - 1; i++) {
                                    for (int j = 0; j < Moscow.size() - 1; j++) {
                                        str0 = Moscow[j].get_route_number();
                                        str1 = Moscow[j + 1].get_route_number();

                                        if (str0 > str1)
                                            sizecheck = str1;
                                        else
                                            sizecheck = str0;

                                        while (value_check) {
                                            if (sizecheck == 0) { value_check = false; break; }
                                            sizecheck = sizecheck / 10;
                                            size++;
                                        }

                                        if (str0 < str1) {
                                            tmp = Moscow[j];
                                            Moscow[j] = Moscow[j + 1];
                                            Moscow[j + 1] = tmp;
                                            //break;
                                        }
                                    }
                                }

                                writeTextFile(DB, Moscow);
                                break;
                            }
                            case 0:
                            {
                                cout << "Возврат в главное меню" << endl;
                                break;
                            }
                            default:
                            {
                                cout << "Ошибка! Указанный номер пункта отсутствует! Возврат к главному меню!" << endl;
                                system("pause");
                                break;
                            }
                        }

                        break;
                    }
                    case 0:
                    {
                        cout << "Возврат в главное меню" << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Ошибка! Указанный номер пункта отсутствует! Возврат к главному меню!" << endl;
                        system("pause");
                        break;
                    }
                }

                break;
            }
            case 0:
            {
                cout << "Выход с программы" << endl;
                system("pause");
                exit(1);
                break;
            }
            default:
            {
                cout << "Ошибка! Указанный номер пункта отсутствует! Возврат к главному меню!" << endl;
                system("pause");
                break;
            }
        }
    }
}
