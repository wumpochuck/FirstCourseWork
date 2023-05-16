// Библиотеки
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <iomanip>

using namespace std;

// Константы (если есть)
extern int len;
extern const char fname[20];
extern const char subjects1[];
extern const char subjects2[];
extern const char subjects3[];
extern const char subjects4[];

// Структура "Студент"
struct Student {
    int numberOfCourse;
    char numberOfGroup[10];
    char name[20];
    int ocenki[4];
    float srednee;
    char mark[2];
};

// Прототипы функций
ostream& shapka(ostream& stream);
ostream& FinishL(ostream& stream);
ostream& shapka2(ostream& stream);
ostream& FinishL2(ostream& stream);

void writeZap(fstream& p);
void write(fstream& p, Student zap, int num = 0);
Student vvod(fstream& p);
void readAll(fstream& p);
fstream& read(fstream& p, Student& zap, int num = 0);
void readN(fstream& p, int N);
void print(Student zap);
int Delete(fstream& p);
int metkaDel(fstream& p, char* imya);
void UNmetkaDel(fstream& p);
void other_print(fstream& p, int course);
void print2(Student zap);
void vivod_spravki();
