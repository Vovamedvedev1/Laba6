#define  _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "PrintedEdition.h"
using namespace std;


void PrintedEdition::validatorName(const char* name) const
{
    ValidatorString vl;
    if (!vl(name))
        throw Exception("Неверное значение name");
}


void PrintedEdition::validatorCountPages(int countPages) const
{
    if (countPages <= 0)
        throw Exception("Неверное значение countPages");
}
void PrintedEdition::validatorPrice(double price) const
{
    if (price <= 0)
        throw Exception("Неверное значение countPages");
}


PrintedEdition::PrintedEdition()
{
    this->name = new char();
    this->countPages = new int();
    this->price = new double();
}

PrintedEdition::PrintedEdition(const char* name, int countPages, double price)
{
    this->setName(name);
    this->setCountPages(countPages);
    this->setPrice(price);
}

void PrintedEdition::setName(const char* name)
{
    this->validatorName(name);
    if (this->name != nullptr)
    {
        delete[]this->name;
        this->name = nullptr;
    }
    this->name = new char[strlen(name) + 1];
    strncpy(this->name, name, strlen(name));
    this->name[strlen(name)] = '\0';
}


void PrintedEdition::setCountPages(int coutPages)
{
    this->validatorCountPages(coutPages);
    if (this->countPages != nullptr)
    {
        delete this->countPages;
        this->countPages = nullptr;
    }
    this->countPages = new int();
    *this->countPages = coutPages;

}
void PrintedEdition::setPrice(double price)
{
    this->validatorPrice(price);
    if (this->price != nullptr)
    {
        delete this->price;
        this->price = nullptr;
    }
    this->price = new double();
    *this->price = price;
}

std::string PrintedEdition::getName() const
{
    return string(this->name);
}
int PrintedEdition::getCountPages() const
{
    return *this->countPages;
}
double PrintedEdition::getPrice() const
{
    return *this->price;
}

void PrintedEdition::func()
{
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!1Func from PrintedEdition!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void PrintedEdition::show() const
{
    cout << "Название:  " << this->getName() << endl;
    cout << "Количество страниц:  " << *this->countPages << endl;
    cout << "Цена:  " << *this->price << endl;
}


PrintedEdition::~PrintedEdition()
{
    delete[]this->name;
    this->name = nullptr;
    delete this->countPages;
    delete this->price;
    cout << "Деструктор PrintedEdition " << endl;
}
