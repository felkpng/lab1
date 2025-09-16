#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <string>
using namespace std;

struct Pipe {
    string name;
    float lenght;
    int diametr;
    bool repair;
};

struct Ks {
    string name;
    int workshops_count;
    int workshops_working;
    string type;
};

Pipe NewPipe(string name, float lenght, int diametr, bool repair) {
    Pipe truba;
    truba.name = name;
    truba.lenght = lenght;
    truba.diametr = diametr;
    truba.repair = repair;

    return truba;
};

Ks NewKs(string name, int workshops_count, int workshops_working, string type) {
    Ks station;
    station.name = name;
    station.workshops_count = workshops_count;
    station.workshops_working = workshops_working;
    station.type = type;

    return station;
};

bool toFloat(string str) {
    try {
        if (stof(str) < 0) {
            cerr << "Ошибка: Число должно быть положительным!" << endl;
            return false;
        }
        return true;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << str << " не может быть преобразована в float (неверный аргумент)." << endl;
        return false;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << str << " выходит за пределы диапазона float." << endl;
        return false;
    }
}

bool toInt(string str) {
    try {
        if (stoi(str) < 0) {
            cerr << "Ошибка: Число должно быть положительным" << endl;
            return false;
        }
        return true;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << str << " не может быть преобразована в int (неверный аргумент)." << endl;
        return false;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка: " << str << " выходит за пределы диапазона int." << endl;
        return false;
    }
}

bool toBool(string str) {
    if (str == "+" || str == "-") {
        return true;
    }
    cerr << "Ошибка: используйте только да или нет." << endl;
    return false;  
}

Pipe AddPipe() {
    string name;
    string lenght_nochecked;
    string diametr_nochecked;
    string repair_nochecked;

    float lenght;
    int diametr;
    bool repair;

    cout << "Название: ";
    cin >> name;

    while (true){
        cout << "Длина: ";
        cin >> lenght_nochecked;

        if (toFloat(lenght_nochecked)) {
            lenght = stof(lenght_nochecked);
            break;
        }
    }

    while (true) {
        cout << "Диаметр: ";
        cin >> diametr_nochecked;

        if (toInt(diametr_nochecked)) {
            diametr = stoi(diametr_nochecked);
            break;
        }
    }

    while (true) {
        cout << "В ремонте? (+/-): ";
        cin >> repair_nochecked;

        if (toBool(repair_nochecked)) {
            if (repair_nochecked == "+") { repair = true; }
            else { repair = false; }
            break;
        }
    }

    Pipe truba = NewPipe(name, lenght, diametr, repair);
    system("cls");
    cout << "Труба успешно создана!" << endl << endl;

    return truba;

}

Ks AddKs() {
    string name;
    string workshops_count_nochecked;
    string workshops_working_nochecked;
    string type;

    int workshops_count;
    int workshops_working;

    cout << "Название: ";
    cin >> name;

    while (true) {
        cout << "Количество цехов: ";
        cin >> workshops_count_nochecked;

        if (toInt(workshops_count_nochecked)) {
            workshops_count = stoi(workshops_count_nochecked);
            break;
        }
    }

    while (true) {
        cout << "Количество цехов в работе: ";
        cin >> workshops_working_nochecked;

        if (toInt(workshops_working_nochecked)) {
            workshops_working = stoi(workshops_working_nochecked);
            if (workshops_working > workshops_count) {
                cout << "Количество цехов в работе должно быть <= количества цехов." << endl;
            }
            else { break; }
        }
    }

    cout << "Тип станции: ";
    cin >> type;

    Ks station = NewKs(name, workshops_count, workshops_working, type);
    system("cls");
    cout << "Станция успешно создана!" << endl << endl;

    return station;

}

void ShowObjects(Pipe truba, Ks station) {
    system("cls");
    cout << "Объекты: ";

    if (truba.name == "" && station.name == "") {
        cout << "нет" << endl;
        return;
    }

    if (truba.name != "") {
        cout << endl << "Название: " << truba.name << endl;
        cout << "Длина: " << truba.lenght << endl;
        cout << "Диаметр: " << truba.diametr << endl;
        cout << "В работе: " << truba.repair << endl << endl;
    }

    if (station.name != "") {
        cout << endl << "Название: " << station.name << endl;
        cout << "Количество цехов: " << station.workshops_count;
        cout << " (" << station.workshops_working << " в работе)" << endl;
        cout << "Тип: " << station.type << endl << endl;
    }
}

void Menu() {
    Pipe truba;
    Ks station;

    while (true) {
        cout << "Меню:\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 0:
            return;
        case 1:
            truba = AddPipe();
            break;
        case 2:
            station = AddKs();
            break;
        case 3:
            ShowObjects(truba, station);
            break;
        };
    };
};

int main()
{
    setlocale(LC_ALL, "rus");
    Menu();
}
