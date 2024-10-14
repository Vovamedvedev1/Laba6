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
    //Пример раннего связывания
    cout << endl;
    cout << "Пример раннего связывания" << endl;
    string* strnews = new string[3];
    strnews[0] = "Новость1";
    strnews[1] = "Новость2";
    strnews[2] = "Новость3";
    PrintedEdition* pr1 = new PrintedEdition("Журнал 1", 245, 135.7);
    PrintedEdition* pr2 = new Newspapper("Газета 1", 214, 135.8, strnews, 3);
    pr1->show();
    pr1->func();
    pr2->show();
    pr1->func();
    delete[]strnews;
    delete pr1;
    delete pr2;
    return 0;
}
