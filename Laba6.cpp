#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include "funcs.h"
#include "Newspapper.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    PrintedEdition* ourprintedEdition {nullptr};
    cout << "Выберете тип издания" << endl;
    cout << "[1] Газета" << endl;
    cout << "[2] Научный журнал" << endl;
    cout << "[3] Гороскоп" << endl;
    int n;
    cout << "Выберете тип издания"; cin >> n;
    
    
    switch (n)
    {
    case 1:
        funcNewspapper(ourprintedEdition);
        ourprintedEdition->appendNews("Скандал Филиппа Киркорова и Николая Баскова");
        ourprintedEdition->appendNews("Рост цен на продукты питания");
        ourprintedEdition->appendNews("Израильско-палестинский конфликт");
        ourprintedEdition->pop("Рост цен на продукты питания");
        break;
    case 2:
        funcScientificJournal(ourprintedEdition);
        ourprintedEdition->append(Article("Виктор Тимофеев", "Природа Кении", "География", 1700, Data(11, 8, 13)));
        ourprintedEdition->append(Article("Федор Тимохин", "История Золотой Орды", "История", 4000, Data(11, 8, 17)));
        ourprintedEdition->pop("Популяция Сибирской рыси на террритории Кузбасса");
        break;
    case 3:
        funcHoroscope(ourprintedEdition);
        string yourzadiak;
        cout << "Введите свой знак задиака: ";
        cin >> yourzadiak;
        ourprintedEdition->getPredict(yourzadiak);
        break;
    }
    //Пример позднего связывания 
    if (ourprintedEdition != nullptr)
    {
        ourprintedEdition->show();

        delete ourprintedEdition;
    }
    return 0;
}
