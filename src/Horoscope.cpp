#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "Horoscope.h"
using namespace std;

Horoscope::Horoscope() : PrintedEdition()
{
    this->zadiacsign = new string[12];
    this->zadiacsign[0] = "Овен";
    this->zadiacsign[1] = "Телец";
    this->zadiacsign[2] = "Близнецы";
    this->zadiacsign[3] = "Рак";
    this->zadiacsign[4] = "Лев";
    this->zadiacsign[5] = "Дева";
    this->zadiacsign[6] = "Весы";
    this->zadiacsign[7] = "Скорпион";
    this->zadiacsign[8] = "Стрелец";
    this->zadiacsign[9] = "Козерог";
    this->zadiacsign[10] = "Водолей";
    this->zadiacsign[11] = "Рыба";
    this->predictMassive = new Prediction * [12];
    for (int i = 0; i < 12; i++)
        this->predictMassive[i] = new Prediction();
}
Horoscope::Horoscope(const char* name, int countPages, double price, Prediction** predictMassive) : PrintedEdition(name, countPages, price)
{
    this->zadiacsign = new string[12];
    this->zadiacsign[0] = "Oven";
    this->zadiacsign[1] = "Telec";
    this->zadiacsign[2] = "Blizneci";
    this->zadiacsign[3] = "Rak";
    this->zadiacsign[4] = "Lev";
    this->zadiacsign[5] = "Deva";
    this->zadiacsign[6] = "Veci";
    this->zadiacsign[7] = "Scorpion";
    this->zadiacsign[8] = "Strelec";
    this->zadiacsign[9] = "Kozerog";
    this->zadiacsign[10] = "Vodolei";
    this->zadiacsign[11] = "Ribi";
    this->setPredictMassive(predictMassive);
}
void Horoscope::setPredictMassive(Prediction** predictMassive)
{
    if (this->predictMassive != nullptr)
    {
        for (int i = 0; i < 12; i++)
            delete this->predictMassive[i];
        delete[]this->predictMassive;
        this->predictMassive = nullptr;
    }

    this->predictMassive = new Prediction*[12];
    for (int i = 0; i < 12; i++)
    {
        this->predictMassive[i] = new Prediction();
        *(this->predictMassive[i]) = *(predictMassive[i]);
    }
}
void Horoscope::getPredict(string zc) const
{
    bool flag = false;
    for (int i = 0; i < 12; i++)
    {
        if (zc == this->zadiacsign[i])
        {
            flag = true;
            cout << *(this->predictMassive[i]) << endl;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Такого знака задиака не существует" << endl;
        return;
    }
}
Horoscope::~Horoscope()
{
    for (int i = 0; i < 12; i++)
        delete this->predictMassive[i];
    delete[]this->predictMassive;
    this->predictMassive = nullptr;
    delete[]this->zadiacsign;
    cout << "Деструктор Horoscope" << endl;
}