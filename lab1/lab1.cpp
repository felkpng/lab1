#include <iostream>
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

bool toFloat(string str) {
    try {
        stof(str);
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
        stoi(str);
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
            diametr = stof(diametr_nochecked);
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
    cout << "Труба успешно создана!" << endl << endl;

    return truba;

}

void Menu() {
    Pipe truba;
    Ks station;

    while (true) {
        cout << "Меню:\n1. Добавить трубу\n2. Добавить КС\n3. Показать объекты\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 0:
            return;
        case 1:
            truba = AddPipe();
        };
    };
};

int main()
{
    setlocale(LC_ALL, "rus");
    Menu();
}
