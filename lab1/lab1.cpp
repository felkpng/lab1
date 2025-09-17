#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <fstream>
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
    catch (const invalid_argument) {
        cerr << "Ошибка: " << str << " не может быть преобразована в float (неверный аргумент)." << endl;
        return false;
    }
    catch (const out_of_range) {
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
    catch (const invalid_argument) {
        cerr << "Ошибка: " << str << " не может быть преобразована в int (неверный аргумент)." << endl;
        return false;
    }
    catch (const out_of_range) {
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

    system("cls");
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

    system("cls");
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
        cout << "нет" << endl << endl;
        return;
    }

    if (truba.name != "") {
        cout << "\n\nТруба\nНазвание: " << truba.name << endl;
        cout << "Длина: " << truba.lenght << endl;
        cout << "Диаметр: " << truba.diametr << endl;
        cout << "В работе: " << truba.repair << endl;
    }

    if (station.name != "") {
        cout << endl << "КС\nНазвание: " << station.name << endl;
        cout << "Количество цехов: " << station.workshops_count;
        cout << " (" << station.workshops_working << " в работе)" << endl;
        cout << "Тип: " << station.type << endl << endl;
    }
}

Pipe EditPipe(Pipe truba) {
    system("cls");
    if (truba.name == "") {
        cerr << "У вас нет трубы!" << endl << endl;
        return truba;
    }

    while (true) {
        int choice;
        cout << "Что хотите редактировать?\n1. Имя\n2. Длина\n3. Диаметр\n4. В ремонте\n0. Назад\n";
        cin >> choice;

        switch (choice) {
        case 0:
            return truba;
        case 1:
            system("cls");
            cout << "Новое имя: ";
            cin >> truba.name;
            break;
        case 2:
        {
            system("cls");
            string lenght_nochecked;

            while (true) {
                cout << "Новая длина: ";
                cin >> lenght_nochecked;

                if (toFloat(lenght_nochecked)) {
                    truba.lenght = stof(lenght_nochecked);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            system("cls");
            string diametr_nochecked;

            while (true) {
                cout << "Диаметр: ";
                cin >> diametr_nochecked;

                if (toInt(diametr_nochecked)) {
                    truba.diametr = stoi(diametr_nochecked);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            system("cls");
            string repair_nochecked;

            while (true) {
                cout << "В ремонте? (+/-): ";
                cin >> repair_nochecked;

                if (toBool(repair_nochecked)) {
                    truba.repair = (repair_nochecked == "+");
                    break;
                }
            }
            break;
        }
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
    return truba;
}

Ks EditKs(Ks station) {
    system("cls");
    if (station.name == "") {
        cerr << "У вас нет КС!" << endl << endl;
        return station;
    }

    while (true) {
        int choice;
        cout << "Что хотите редактировать?\n1. Имя\n2. Количество цехов\n3. Цехов в работе\n4. Тип\n0. Назад\n";
        cin >> choice;

        switch (choice) {
        case 0:
            return station;
        case 1:
            system("cls");
            cout << "Новое имя: ";
            cin >> station.name;
            break;
        case 2:
        {
            system("cls");
            string workshops_count_nochecked;

            while (true) {
                cout << "Новое количество цехов: ";
                cin >> workshops_count_nochecked;

                if (toInt(workshops_count_nochecked)) {
                    int new_count = stoi(workshops_count_nochecked);
                    if (new_count >= station.workshops_working) {
                        station.workshops_count = new_count;
                        break;
                    }
                    else {
                        cout << "Количество цехов не может быть меньше количества работающих цехов ("
                            << station.workshops_working << ")" << endl;
                    }
                }
            }
            break;
        }
        case 3:
        {
            system("cls");
            string workshops_working_nochecked;

            while (true) {
                cout << "Цехов в работе: ";
                cin >> workshops_working_nochecked;

                if (toInt(workshops_working_nochecked)) {
                    int new_working = stoi(workshops_working_nochecked);
                    if (new_working <= station.workshops_count) {
                        station.workshops_working = new_working;
                        break;
                    }
                    else {
                        cout << "Количество цехов в работе должно быть <= количества цехов ("
                            << station.workshops_count << ")" << endl;
                    }
                }
            }
            break;
        }
        case 4:
            system("cls");
            cout << "Новый тип: ";
            cin >> station.type;
            break;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
}

bool SaveData(Pipe truba, Ks station) {
    if (truba.name != "") {
        ofstream outFilePipe("truba.txt");
        if (outFilePipe.is_open()) {
            outFilePipe << truba.name << endl;
            outFilePipe << truba.lenght << endl;
            outFilePipe << truba.diametr << endl;
            outFilePipe << truba.repair << endl;
            outFilePipe.close();
        }
        else {
            cerr << "Ошибка: Не удалось открыть файл 'truba.txt' для записи." << endl;
        }
    }
    
    if (station.name != "") {
        ofstream outFileKs("station.txt");
        if (outFileKs.is_open() && station.name != "") {
            outFileKs << station.name << endl;
            outFileKs << station.workshops_count << endl;
            outFileKs << station.workshops_working << endl;
            outFileKs << station.type << endl;
            outFileKs.close();
        }
        else {
            cerr << "Ошибка: Не удалось открыть файл 'station.txt' для записи." << endl;
        }
    }
    system("cls");
    cout << "Данные успешно записаны в файлы 'truba.txt' и 'station.txt'.\n\n";
    return true;
}

Pipe LoadPipe() {
    ifstream inFile("truba.txt");
    string line;
    Pipe truba;

    if (inFile.is_open()) {
        getline(inFile, truba.name);

        getline(inFile, line);
        truba.lenght = stof(line);

        getline(inFile, line);
        truba.diametr = stoi(line);

        getline(inFile, line);
        if (line == "1") { truba.repair = true; }
        else { truba.repair = false; }

        inFile.close();
    }
    return truba;
}

Ks LoadKs() {
    ifstream inFile("station.txt");
    string line;
    Ks station;

    if (inFile.is_open()) {
        getline(inFile, station.name);

        getline(inFile, line);
        station.workshops_count = stoi(line);

        getline(inFile, line);
        station.workshops_working = stoi(line);

        getline(inFile, station.type);

        inFile.close();
    }
    return station;
}

void Menu() {
    Pipe truba;
    Ks station;

    while (true) {
        cout << "Меню:\n1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход\n";
        int choice = -1;
        string enter;
        cin >> enter;
        if (toInt(enter)) {
            choice = stoi(enter);
        }

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
        case 4:
            truba = EditPipe(truba);
            break;
        case 5:
            station = EditKs(station);
            break;
        case 6:
            SaveData(truba, station);
            break;
        case 7:
            truba = LoadPipe();
            station = LoadKs();
            system("cls");
            cout << "Данные успешно загруженны\n";
            break;
        };
    };
};

int main()
{
    setlocale(LC_ALL, "rus");
    Menu();
}
