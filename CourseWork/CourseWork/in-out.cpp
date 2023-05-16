#include "header.h"

ostream& shapka(ostream& stream) {
    setlocale(LC_ALL, "rus");
    stream << endl << FinishL << endl;
    stream << setw(5) << "Курс"
        << setw(15) << "Группа"
        << setw(15) << "ФИО"
        << setw(25) << subjects1
        << setw(20) << subjects2
        << setw(20) << subjects3
        << setw(20) << subjects4
        << setw(20) << "Ср.Оценка"
        << setw(16) << "Метка" << endl;
    stream << FinishL << endl;
    return stream;
}

ostream& FinishL(ostream& stream) {
    stream << setfill('-') << setw(106) << '|' << setfill(' ');
    return stream;
}

ostream& FinishL2(ostream& stream) {
    stream << setfill('-') << setw(59) << '|' << setfill(' ');
    return stream;
}


ostream& shapka2(ostream& stream) {
    setlocale(LC_ALL, "rus");
    stream << endl << FinishL2 << endl;
    stream << setw(5) << "Курс"
        << setw(15) << "Группа"
        << setw(15) << "ФИО"
        << setw(30) << "Ср.Оценка"
        << setw(16) << "Метка" << endl;
    stream << FinishL2 << endl;
    return stream;
}
