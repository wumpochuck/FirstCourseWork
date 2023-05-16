#include <iostream>
#include "header.h"

char menu();

const char fname[20] = "file.bin";
int len = sizeof(Student);

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Здравствуйте! ";
    fstream p(fname, ios::app);


    if (p) {
        p.close();
        p.open(fname, ios::in | ios::out | ios::ate | ios::binary);
    }


    while (true) {

        char choise = menu();
        switch (choise) {
        case '1': {
            writeZap(p);
            break;
        }
        case '2': {
            readAll(p);
            break;
        }
        case '3': {
            cout << "Введите номер записи: ";
            int number; cin >> number;
            readN(p, number);
            break;
        }
        case '4': {
            int a;
            char name[20];
            cout << "\n\tВведите фамилию: ";
            cin >> name;
            a = metkaDel(p, name);
            cout << endl;
            break;
        }
        case '5': {
            UNmetkaDel(p);
            break;
        }
        case '6': {
            Delete(p);
            cout << "Удаление завершено!" << endl;
            break;
        }
        case '7': {
            cout << "Введите номер курса: ";
            int course; cin >> course;
            other_print(p, course);
            break;
        }
        case '8': {
            vivod_spravki();
            break;
        }
        case '0': {
            cout << endl << endl << "До свидания! " << endl;
            exit(0);
            break;
        }
        }
    }


}

char menu() {
    setlocale(LC_ALL, "Russian");
    char choise;

    cout << "Выберите действие: ";
    cout << endl << "\n\t1-> Добавить нового студента"
        << endl << "\t2-> Показать таблицу студентов"
        << endl << "\t3-> Показать определенного студента"
        << endl << "\t4-> Пометить на удаление"
        << endl << "\t5-> Снять пометки на удаление"
        << endl << "\t6-> Удалить отмеченных"
        << endl << "\t7-> Показать лучших студентов курса"
        << endl << "\t8-> Вывести справку"
        << endl << "\t0-> EXIT" << endl << "\t";

    cin >> choise;
    return choise;
}
