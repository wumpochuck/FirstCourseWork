#include "header.h"

using namespace std;

const char subjects1[] = "Экзамен 1";
const char subjects2[] = "Экзамен 2";
const char subjects3[] = "Экзамен 3";
const char subjects4[] = "Экзамен 4";

//////////////////////////////////////////////////////////////////////

void writeZap(fstream& p)
{
    p.clear();
    p.seekg(0, ios::end);
    Student zap;
    zap = vvod(p);
    write(p, zap);
}

//////////////////////////////////////////////////////////////////////

void write(fstream& p, Student zap, int num)
{
    p.clear(); // Чистка потока
    if (num) p.seekg((num - 1) * len, ios::beg);
    p.write((char*)&zap, len);
}

//////////////////////////////////////////////////////////////////////

Student vvod(fstream& p)
{

    Student zap;
    setlocale(LC_ALL, "rus");
    cout << "\nВведите номер курса: "; cin >> zap.numberOfCourse;
    cout << "\nВведите номер группы: "; cin >> zap.numberOfGroup;
    cout << "\nВведите ФИО студента: "; cin >> zap.name;
    for (int i = 0; i < 4; i++) {
        cout << "\nВведите оценку за " << i + 1 << "ый/ий экзамен: "; cin >> zap.ocenki[i];
    }
    zap.srednee = (zap.ocenki[0] + zap.ocenki[1] + zap.ocenki[2] + zap.ocenki[3] + 0.0) / 4;
    strcpy(zap.mark, "+");
    return zap;
}

//////////////////////////////////////////////////////////////////////

void readAll(fstream& p)
{
    p.clear();
    p.seekg(0, ios::beg);
    Student zap;
    cout << shapka;
    while (read(p, zap))
        print(zap);
    cout << endl << FinishL << endl;
}

//////////////////////////////////////////////////////////////////////

void readN(fstream& p, int N)
{
    p.clear();
    p.seekg(0, ios::beg);
    Student zap;
    if (read(p, zap, N))
    {
        cout << shapka;
        print(zap);
        cout << endl << FinishL << endl;
    }
    else
        cout << endl << "Такой записи нет" << endl;
}

//////////////////////////////////////////////////////////////////////

fstream& read(fstream& p, Student& zap, int num)
{
    p.clear();
    if (num)
        p.seekg((num - 1) * len, ios::beg);
    p.read((char*)&zap, len);
    return p;
}

//////////////////////////////////////////////////////////////////////

void print(Student zap)
{
    setlocale(LC_ALL, "ru");
    cout << endl
        << setw(1) << zap.numberOfCourse
        << setw(13) << zap.numberOfGroup
        << setw(15) << zap.name;
    cout << setw(11) << zap.ocenki[0]
        << setw(13) << zap.ocenki[1]
        << setw(13) << zap.ocenki[2]
        << setw(13) << zap.ocenki[3]
        << setw(13) << zap.srednee;
    cout << setw(12) << zap.mark;

}

//////////////////////////////////////////////////////////////////////

void UNmetkaDel(fstream& p)
{
    p.clear();
    Student zap;
    p.seekp(0, ios::beg);
    for (int i = 1; read(p, zap, i); i++)
    {
        if (strcmp(zap.mark, "-") == 0)
        {
            strcpy(zap.mark, "+");
            write(p, zap, i);
        }
    }
}

//////////////////////////////////////////////////////////////////////

int metkaDel(fstream& p, char* imya)
{
    p.clear();
    Student zap;
    p.seekp(0, ios::beg);
    int kol = 0;
    for (int i = 1; read(p, zap, i); i++)
    {
        if (strcmp(zap.name, imya) == 0)
        {
            strcpy(zap.mark, "-");
            write(p, zap, i);
            kol++;
        }
    }
    return kol;
}

//////////////////////////////////////////////////////////////////////

int Delete(fstream& p)
{
    fstream p1("temp.txt", ios::app);
    p.clear();
    Student zap;
    p.seekp(0, ios::beg);
    int kol = 0;
    for (int i = 1; read(p, zap, i); i++)
    {
        if (strcmp(zap.mark, "+") == 0)
        {
            write(p1, zap);
            kol++;
        }
    }
    p.close();
    p1.close();
    remove(fname);
    rename("temp.txt", fname);
    p.open(fname, ios::in | ios::out | ios::binary);
    return kol;
}

//////////////////////////////////////////////////////////////////////

void other_print(fstream& p, int course) {
    p.clear();
    Student zap;
    p.seekp(0, ios::beg);
    // Переменная для индексов и счетчик количества записей
    int count = 0; int count1 = 0;
    // Создание массива с индексами и средними баллами
    float arr_indexes[2][100];
    // Заполнение
    while (read(p, zap)) {

        // Если данные подходят, то записываем их
        if (zap.numberOfCourse == course) {
            arr_indexes[0][count] = count;
            arr_indexes[1][count] = zap.srednee;
            count1++;
        }
        // Иначе записываем отрицательные числа чтобы не мешались.
        else {
            arr_indexes[0][count] = count;
            arr_indexes[1][count] = -10;
        }
        count++;
    }

    int temp[count1];
    // Циклы для нахождения максимальных
    for (int i = 0; i < count1; i++) {
        float maxi = 0;

        for (int j = 0; j < count; j++) {

            if (arr_indexes[1][j] > maxi) {
                maxi = arr_indexes[1][j];
                temp[i] = arr_indexes[0][j];
            }
        }
        arr_indexes[1][temp[i]] = -10;
    }

    // Вывод максимальных
    cout << shapka2;
    for (int i = 0; i < count1; i++) {
        if (i == 3) break;
        if (read(p, zap, temp[i] + 1))
        {
            print2(zap);
        }

    }
    cout << endl << FinishL2 << endl;
}

//////////////////////////////////////////////////////////////////////

void print2(Student zap)
{
    setlocale(LC_ALL, "ru");
    cout << endl
        << setw(1) << zap.numberOfCourse
        << setw(13) << zap.numberOfGroup
        << setw(15) << zap.name;
    cout << setw(13) << zap.srednee;
    cout << setw(12) << zap.mark;

}

void vivod_spravki()
{
    cout << "" << endl;
    cout << "" << endl;
    cout << " Литературный институт заказал программу контроля успеваемости студентов для" << endl;
    cout << " деканата.В деканатах института для каждого студента в файле хранится следующая" << endl;
    cout << " информация : номер курса, номер группы, ФИО, оценки по 4 экзаменам. Информация в" << endl;
    cout << " файле не отсортирована.Выдать на экран справку о трех лучших(по среднему балу)" << endl;
    cout << " студентах заданного курса." << endl;
    cout << "" << endl;
    cout << "" << endl;
    
    
}
