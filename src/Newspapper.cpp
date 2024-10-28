#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "Newspapper.h"
using namespace std;


void Newspapper::validatorNewscolumn(int counternews, const std::string* newscolumn)
{
    if (counternews <= 0 || counternews >= 30)
        throw Exception("Неверное количество срочных новостей!!!");
    ValidatorString validator;
    for (int i = 0; i < counternews; i++)
    {
        if (!validator(newscolumn[i].data()))
            throw Exception("Неверный формат новости!!!");
    }
}

Newspapper::Newspapper() : PrintedEdition()
{
    this->newscolumn = new string();
    this->counternews = 0;
}
Newspapper::Newspapper(const char* name, int countPages, double price, const std::string* massive, int counternews) : PrintedEdition(name, countPages, price)
{
    this->setNewscolumn(massive, counternews);
}

void Newspapper::setNewscolumn(const string* newscolumn, int counternews)
{
    validatorNewscolumn(counternews, newscolumn);
    if (this->newscolumn != nullptr)
    {
        delete[]this->newscolumn;
        this->newscolumn = nullptr;
    }
    this->counternews = counternews;
    this->newscolumn = new string[this->counternews];
    for (int i = 0; i < counternews; i++)
        this->newscolumn[i] = newscolumn[i];
}

void Newspapper::appendNews(const string news)
{
    if ((this->counternews + 1) <= 0 || (this->counternews + 1) >= 30)
        throw Exception("Неверное количество срочных новостей!!!");
    ValidatorString validator;
    if (!validator(news.data()))
        throw Exception("Неверный формат новости!!!");
    this->counternews += 1;
    string* temp = new string[this->counternews];
    for (int i = 0; i < this->counternews - 1; i++)
        temp[i] = this->newscolumn[i];
    temp[this->counternews - 1] = news;
    delete[]this->newscolumn;
    this->newscolumn = temp;
    temp = nullptr;
}

void Newspapper::pop(string news)
{
    int index = -1;
    for (int i = 0; i < this->counternews; i++)
    {
        if (this->newscolumn[i] == news)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        return;
    string* Mnews = new string[this->counternews - 1];
    for (int i = 0; i < index; i++)
        Mnews[i] = this->newscolumn[i];
    for (int i = index + 1; i < this->counternews; i++)
        Mnews[i - 1] = this->newscolumn[i];
    this->setNewscolumn(Mnews, this->counternews - 1);
    delete[]Mnews;
}

void Newspapper::show() const
{
    cout << "Информация об новостном издании" << endl;
    this->PrintedEdition::show();
    cout << "Количество новостей: " << this->counternews << endl;
    cout << "Список срочных новостей: " << endl;
    for (int i = 0; i < this->counternews; i++)
    {
        cout << this->newscolumn[i] << endl;
    }
}

PrintedEdition* Newspapper::copy() const
{
    PrintedEdition* NP = new Newspapper(this->name, *this->countPages, *this->price, this->newscolumn, this->counternews);
    return NP;
}

Newspapper::~Newspapper()
{
    cout << "Деструктор Newspapper" << endl;
    if (this->newscolumn != nullptr)
        delete[]this->newscolumn;

}