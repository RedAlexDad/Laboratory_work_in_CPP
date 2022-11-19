#include "Class.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <locale>

// #pragma warning(disable : 4996)

using namespace std;


// Методы классы, описанные вне класса

// Конструкторы без параметров
BUS::BUS() { id = count++; number_bus = ""; FIODRIVER = ""; route_number = NULL; status = NULL; }

// Конструкторы с параметрами
BUS::BUS(int NUMBER_BUS, string FIO, int ROUTNUM, int WHERE) {
    number_bus = NUMBER_BUS; FIODRIVER = FIO; route_number = ROUTNUM; status = WHERE;
}

// Функция, возвращающаяся определенные значения
string BUS::get_number_bus() { return number_bus; }
string BUS::get_FIODRIVER() { return FIODRIVER; }
int BUS::get_status() { return status; }
int BUS::get_route_number() { return route_number; }
int BUS::get_id() { return id; }

// Функция, принимающаяся определенные значения
void BUS::set_number_bus(string num) { number_bus = num; }
void BUS::set_FIODRIVER(string FIO) { FIODRIVER = FIO; }
void BUS::set_status(int WHERE) { status = WHERE; }
void BUS::set_route_number(int route) { route_number = route; }
void BUS::set_id(int ID) { id = ID; }

// Поток вывода в консольном окне
ostream& operator<<(ostream& output, BUS& obj) {
    output << "Идентификатор класса: " << obj.id << endl;
    output << "Номер автобуса: " << obj.number_bus << endl
           << "Фамилия и инициалы водителя: " << obj.FIODRIVER << endl
           << "Номер маршрута: " << obj.route_number << endl;
    //output << "Статус автобуса (0 - парк, 1 - маршрут): " << obj.status << endl;

    return output;
}

// Поток ввода пользователем
istream& operator>>(istream& input, BUS& obj) {
    // Проверка ошибки. Если есть ошибка, тогда true
    bool check = true;

    // Если пользователь допускает несколько ошибок по оформлению, тогда ему вновь предлагают подсказку по оформлении
    int count_warn = 0;
    bool check_warn = true;

    string str_check = "";
    int count_str_value = 0;

    cin.ignore();

    while (check_warn) {
        // Если пользователь вводит несколько ошибок, тогда ему снова предлагают
        if (count_warn == 3) {
            cout << endl;
            cout << "Вы ввели несколько ошибок подряд!" << endl;
            support_build_text(); count_warn = 0;
            cin.ignore();
        }

        while (check) {
            if (count_warn == 3) break;
            cout << "Введите номер автобуса: ";
            getline(input, obj.number_bus, '\n');

            // Проверка заполнения
            if (check_cin_number_bus(obj.number_bus) == false) {
                cout << "Ошибка оформления! Введите заново!" << endl;
                count_warn++;
            }
            else {
                count_warn = 0;
                check = false;
            }
        }
        check = true;
        while (check) {
            if (count_warn == 3) break;
            cout << "Введите фамилия и инициалы водителя: ";
            getline(input, obj.FIODRIVER, '\n');

            // Проверка заполнения
            if (check_cin_FIODRIVER(obj.FIODRIVER) == false) {
                cout << "Ошибка оформления! Введите заново!" << endl;
                count_warn++;
            }
            else {
                count_warn = 0;
                check = false;
            }
        }
        check = true;
        while (check) {
            if (count_warn == 3) break;
            cout << "Введите номер маршрута: ";
            getline(input, str_check, '\n');

            for (int i = 0; i < str_check.size(); i++) {
                if (str_check[i] >= '0' && str_check[i] <= '9')
                    count_str_value++;
            }

            if (count_str_value == str_check.size()) {
                obj.route_number = stoi(str_check);

                if (obj.route_number > 0 && obj.route_number < 1000) {
                    count_warn = 0;
                    check = false;
                }
                else
                    count_warn++;
            }
            else {
                count_str_value = 0;
                count_warn++;
            }
        }

        // По умолчанию автобус находится в парке
        if (count_warn != 3) {
            obj.status = 0;
            check_warn = false;
        }
        else
            check = true;

    }
    //cout << endl;

    return input;
}

//==========================================================================================

// Остальные функции

// Печатает все данные
void print(vector<BUS> bus) {
    for (int i = 0; i < bus.size(); i++) {
        cout << bus[i] << endl;
    }
}

// Печатает только данные, в которых содержатся автобусы, находящихся в парке
void print_also_park(vector<BUS> bus) {
    // Проверка на присутствии данных, если их нет, то false
    bool check = false;

    for (int i = 0; i < bus.size(); i++)
        if (bus[i].get_status() == 0)
            check = true;

    if (check)
        for (int i = 0; i < bus.size(); i++) {
            if (bus[i].get_status() == 0) {
                cout << bus[i] << endl;
            }
        }
    else
        cout << "Отсутствует" << endl << endl;
}

// Печатает только данные, в которых содержатся автобусы, находящихся на маршруте
void print_also_route(vector<BUS> bus) {
    // Проверка на присутствии данных, если их нет, то false
    bool check = false;

    for (int i = 0; i < bus.size(); i++)
        if (bus[i].get_status() == 1)
            check = true;

    if (check)
        for (int i = 0; i < bus.size(); i++) {
            if (bus[i].get_status() == 1) {
                cout << bus[i] << endl;
            }
        }
    else
        cout << "Отсутствует" << endl << endl;
}

// Проверка на правильность заполнения данных

// Проверка на номер автобуса: АА 559 70
bool check_cin_number_bus(string str) {
    int count = 0;
    int size = str.size();
    bool check_number = false;
    // Первые две символы должны быть заглавными
    bool check_letter = false;

    if (size <= 10) {
        for (int i = 0; i < size; i++)
            if ((str[i] >= '0') && (str[i] <= '9')) {
                count++;
                // Если есть число
                check_number = true;
            }

        if (!check_number) {
            cout << "Ошибка! Отсутвуют числа!" << endl;
            return false;
        }

        if (str[0] >= 'А' && str[0] <= 'Я' && str[1] >= 'А' && str[1] <= 'Я')
            check_letter = true;
        else {
            cout << "Первые две символы должны быть заглавными русскими буквами!" << endl;
            return false;
        }

        // Проверка на инициалы
        int pos_point0 = 0;
        int pos_point1 = 0;

        pos_point0 = str.find(' ', pos_point0);
        //cout << "pos_point0: " << pos_point0 << endl;
        str = str.replace(pos_point0, 1, ".");
        //cout << "str.erase: " << str << endl;
        pos_point1 = str.find(' ', pos_point1);
        str = str.replace(pos_point0, 1, " ");
        //cout << "pos_point1: " << pos_point1 << endl;

        if (pos_point1 - pos_point0 != 4) {
            cout << "После заглавной русской буквы должны стоять три любые цифры" << endl;
            return false;
        }

        if (count == size - 4 && check_number == true && check_letter == true)
            return true;
        else
            return false;
    }
    else {
        cout << "Ошибка! Слишком длинный номер!" << endl;
        return false;
    }
}

// Проверка на ФИО водителя и его инициалы: Игнатьев В.В.
bool check_cin_FIODRIVER(string str) {

    // Количество пробелов должен быть 1
    const int space = 1;
    // Количество точек должен быть 2
    const int point = 2;

    int check_space = 0;
    int check_point = 0;

    // Позиция точек
    int pos_point0 = 0;
    int pos_point1 = 0;

    // Не должен присутствовать любое число
    bool check_number = false;
    // Проверка на инициалы
    bool check_initials = false;

    int size = str.size();

    if (size >= 7) {

        for (int i = 0; i < size; i++) {
            // Количество пробелов должен быть 1
            if (str[i] == ' ') check_space++;

            // Количество точек должен быть 2
            if (str[i] == '.') check_point++;

            if ((str[i] >= '0') && (str[i] <= '9')) {
                // Если есть число
                check_number = true;
            }
        }

        if (!(str[0] >= 'А' && str[0] <= 'Я')) {
            cout << "Фамилия должна начинаться с заглавной буквой!" << endl;
            return false;
        }

        if (check_space != 1) {
            cout << "Ошибка! Пробел должен быть один!" << endl;
            return false;
        }

        if (check_point != 2) {
            cout << "Ошибка! Точки должны быть две!" << endl;
            return false;
        }

        if (check_number) {
            cout << "Ошибка! Присутствуют числа!" << endl;
            return false;
        }

        // Проверка на инициалы
        pos_point0 = str.find('.', pos_point0);
        //cout << "pos_point0: " << pos_point0 << endl;
        str = str.replace(pos_point0, 1, ",");
        //cout << "str.erase: " << str << endl;
        pos_point1 = str.find('.', pos_point1);
        str = str.replace(pos_point0, 1, ".");
        //cout << "pos_point1: " << pos_point1 << endl;

        if (pos_point1 - pos_point0 != 2) {
            cout << "Ошибка заполнения инициалы! Инициалы должны быть одними заглавными буквами.\nНапример: Фамилия И.О." << endl;
            return false;
        }

        // Игнатьев В.В.
        // Инициалы должны быть заглавными русскими буквами
        if (str[size - 2] >= 'А' && str[size - 2] <= 'Я')
            if (str[size - 4] >= 'А' && str[size - 4] <= 'Я')
                check_initials = true;

        if (!check_initials) {
            cout << "Ошибка! Инициалы должны быть заглавными русскими буквами!" << endl;
            return false;
        }

        // Общая проверка
        if (check_space == space && check_point == point && check_number == false && check_initials == true)
            return true;
        else
            return false;
    }
    else {
        cout << "Короткие фамилия и инициалы!" << endl;
        return false;
    }
}

//==========================================================================================

// Работа с текстовыми файлами

// Запись в текстовыый файл
void writeTextFile(fstream& DB, vector<BUS> BUS) {

    DB.open("Moscow.txt", ios_base::out);
    if (!DB)
        cout << "Файл открыть невозможно\n";

    // Цикл записи файла
    for (int i = 0; i < BUS.size(); i++)
        // Запись в файл
        DB << BUS[i].get_id() << endl
           << BUS[i].get_number_bus() << endl
           << BUS[i].get_FIODRIVER() << endl
           << BUS[i].get_route_number() << endl
           << BUS[i].get_status() << endl;

    DB.clear();
    // Закрытие файла
    DB.close();
}

// Распечатка файла
void readTextFile(fstream& DB) {
    BUS bus_buff;

    DB.open("Moscow.txt", ios_base::in);

    if (!DB.is_open()) {
        cout << "Файл отсутствует! Открыть его невозможно!\n";
    }
    else {
        char buff[100];
        while (!DB.eof()) {
            DB.getline(buff, 100, '\n');
            cout << buff << endl;
        }
    }
    DB.clear();
    DB.close(); // Закрытие файла
}

// Чтение и изменение объекта класса
void read_and_add_into_class_TextFile(fstream& DB, vector<BUS>& newBUS, int& size) {
    DB.open("Moscow.txt", ios_base::in);

    int count = 0, i = 0;
    size = size_file(DB);

    string str = "";

    DB.open("Moscow.txt", ios_base::in);

    //vector<BUS> newBUS(size);
    newBUS.resize(size);

    if (!DB.is_open()) {
        //cout << "Файл отсутствует! Открыть его невозможно!\n";
    }
    else {
        char buff[100] = "";
        while (!DB.eof()) {
            DB.getline(buff, 100, '\n');
            if (buff[0] != '\0') {
                //cout << buff << endl;
                str = buff;
                switch (count) {
                    case 0: { newBUS[i].set_id(atoi(buff)); count++; break; }
                    case 1: { newBUS[i].set_number_bus(str); count++; break; }
                    case 2: { newBUS[i].set_FIODRIVER(str); count++; break; }
                    case 3: { newBUS[i].set_route_number(atoi(buff)); count++; break; }
                    case 4: { newBUS[i].set_status(atoi(buff)); count = 0; i++; break; }
                }
            }
        }
    }

    DB.clear();
    DB.close(); // Закрытие файла
}


//==========================================================================================

// Дополнительные поддержки

// Определение и удаление номер текущего автобуса с автобусного парка и добавление в список маршрутов
void delete_number_bus(vector<BUS>& bus, string number) {
    string tmp = "";
    // Проверяет на наличие присутствии совпадающего номера
    int check = NULL;

    for (int i = 0; i < bus.size(); i++) {
        tmp = bus[i].get_number_bus();
        if (tmp == number && bus[i].get_status() == 1) {
            check = 2;
            break;
        }
        if (tmp == number) {
            //bus.erase(bus.begin() + i);
            // Если в парке, то 0, если на маршруте, то 1
            bus[i].set_status(1);
            check = 1;
            // Размер изменился
            //size = bus.size();
            break;
        }
        else {
            check = 0;
        }
    }

    if (check == 0)
        cout << "Нет совпадающего номера, которого Вы ввели ранее!" << endl;
    else if (check == 1)
        cout << "Есть совпадающий номер!" << endl;
    else if (check == 2)
        cout << "Ошибка! Данный номер автобуса находится на маршруте! Выход на главное меню!" << endl;

}

// Определение и добавление номер текущего автобуса на автобусный парк в списке автобусного парка
void add_number_bus(vector<BUS>& bus, string number) {
    string tmp = "";
    // Проверяет на наличие присутствии совпадающего номера
    int check = NULL;

    for (int i = 0; i < bus.size(); i++) {
        tmp = bus[i].get_number_bus();
        if (tmp == number && bus[i].get_status() == 0) {
            check = 2;
            break;
        }
        if (tmp == number) {
            bus[i].set_status(0);
            check = 1;
            break;
        }
        else {
            check = 0;
        }
    }

    if (check == 0)
        cout << "Нет совпадающего номера, которого Вы ввели ранее!" << endl;
    else if (check == 1)
        cout << "Есть совпадающий номер!" << endl;
    else if (check == 2)
        cout << "Ошибка! Данный номер автобуса находится в парке! Выход на главное меню!" << endl;

}

// Проверяет, пустой ли класс?
bool check_class(vector<BUS> bus) {
    // Если пустой, тогда true
    bool check = false;
    if (bus.size() == NULL) check = true;
    else {
        for (int i = 0; i < bus.size(); i++) {
            if (bus[i].get_number_bus() == "" && bus[i].get_FIODRIVER() == "" && bus[i].get_route_number() == NULL && bus[i].get_status() == NULL )
                check = true;
        }
    }

    return check;
}

// Выявляет размер файла
int size_file(fstream& DB) {

    int count = 0;
    if (!DB.is_open()) {
        //cout << "Файл отсутствует! Открыть его невозможно!\n";
    }
    else {
        char buff[100] = "";
        while (!DB.eof()) {
            DB.getline(buff, 100, '\n');
            //cout << buff << endl;
            if (strlen(buff) != 0)
                count++;
        }
    }

    DB.clear();
    DB.close(); // Закрытие файла

    return (count / 5);
}

// Функция, выводящаяся подсказку по правильности оформлении
void support_build_text() {
    bool check = true;
    // Если пользователь допускает несколько раз ошибок, тогда ему вновь предлагают включить функцию на подсказку
    //int count = 0;
    string request = "";

    cout << "Нужна подсказка по оформлению?\nВведите 'да' или 'нет'" << endl;
    while (check) {
        cout << "Ваш ответ: ";
        cin >> request;
        if (request == "да") {
            cout << "Пример заполнения: " << endl
                 << "Номер автобуса: АА 559 70 \nСправочник по оформлению:\n\tАА - любые заглавные русские алфавиты, только 2 символы;\n\t559 - любые цифры, только 3 символы;\n\t70 код региона, 2 или 3 символы." << endl << endl
                 << "Фамилия и инициалы водителя: Игнатьев В.В." << endl
                 << "Номер маршрута: 440" << endl << endl;
            check = false;
        }
        else if (request == "нет") {
            cout << "Ответ принят. Не подсказывать." << endl;
            check = false;
        }
        else {
            cout << "Ошибка! Введите только 'да' или 'нет' !" << endl;
        }
    }
}

// Функция, предлагающаяся распечатать все данные
void offer_for_printing(vector<BUS> bus) {
    string request;
    // Проверяет на правильность заполнения
    int check = 0;
    while (check == 0) {
        cout << "Распечатать все данные? Введите да или нет или другое." << endl;
        cout << "Ваш ответ: ";
        cin >> request;
        cout << endl;
        if (request == "да") {
            cout << "Список автобусов, находящихся в парке:" << endl;
            print_also_park(bus);
            cout << "Список автобусов, находящихся на маршруте:" << endl;
            print_also_route(bus);
            check = 1;
            break;
        }
        else if (request == "нет") {
            cout << "Ответ принят. Не распечатать." << endl;
            check = 1;
            break;
        }
        else if (request == "другое") {
            check = 2;
            cout << "Распечатать данные автобуса, находящегося в парке или на маршруте?\nВведите парк или маршрут или назад." << endl;
            while (check == 2) {
                cin >> request;

                if (request == "парк") {
                    print_also_park(bus);
                    check = 3;
                    break;
                }
                else if (request == "маршрут") {
                    print_also_route(bus);
                    check = 3;
                    break;
                }
                else if (request == "назад") {
                    check = 0;
                }
                else {
                    cout << "Ошибка! Введите только 'парк' или 'маршрут' или 'назад'!" << endl;
                }
            }
        }
        else
            cout << "Ошибка! Введите только 'да' или 'нет' или 'другое'!" << endl;
    }
    cout << endl;
}

// Функция, требующая повторно ввести для правильности оформлении
void cin_number_request(string& number) {
    bool check = true;
    while (check) {
        cout << "Номер автобуса: ";
        getline(cin, number, '\n');
        if (check_cin_number_bus(number) == false)
            cout << "Ошибка оформления! Введите заново!" << endl;
        else
            check = false;
    }
}

// Проверка на существующего номера
bool check_cin_number(vector<BUS> bus, string number, int& id) {
    for (int i = 0; i < bus.size(); i++) {
        if (bus[i].get_number_bus() == number) {
            id = bus[i].get_id();
            return true;
        }
    }
    return false;
}

// Проверка на присуствии совпадающих номеров в базе данных
bool check_number_bus(vector<BUS> DB, BUS bus) {
    for (int i = 0; i < DB.size(); i++)
        if (DB[i].get_number_bus() == bus.get_number_bus())
            return true;
    return false;
}
