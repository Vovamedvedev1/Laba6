#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include "funcs.h"
#include "Article.h"
#include "ScientificJournal.h"
#include "Newspapper.h"
#include "Horoscope.h"
#include "PublisherHouse.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string tempStr;
    PrintedEdition* ourprintedEdition {nullptr};
    PublisherHouse* ourPublisherHouse{ nullptr };
    cout << "Выберете тип издательства" << endl;
    cout << "[1] Газетное издательство" << endl;
    cout << "[2] Научное издательство" << endl;
    cout << "[3] Астралогическое издательство " << endl;
    int n;
    cout << "Выберете тип издания"; cin >> n;
    string name, address;
    cout << "Введите название Издательства: " << endl;
    getline(cin, name);
    getline(cin, name);
    cout << "Введите адрес Издательства: " << endl;
    getline(cin, address);
    string yourzadiak;
    switch (n)
    {
    case 1:
        try
        {
            funcNewspapper(ourprintedEdition);
        }
        catch (Exception& ex)
        {
            cout << ex.what() << endl;
            return 0;
        }
        Fabric::setType(NewspapperPubl);
        break;
    case 2:
        try
        {
            funcScientificJournal(ourprintedEdition);
        }
        catch (Exception& ex)
        {
            cout << ex.what() << endl;
            return 0;
        }
        Fabric::setType(JournalPubl);
        break;
    case 3:
        try
        {
            funcHoroscope(ourprintedEdition);
        }
        catch (Exception& ex)
        {
            cout << ex.what() << endl;
            return 0;
        }
        Fabric::setType(HoroscopePubl);
        break;
    }
    try
    {
        ourPublisherHouse = Fabric::make_obj(ourprintedEdition, name, address);
    }
    catch (const char* str)
    {
        cout << str << endl;
        while (name == "" || size(name) >= 30)
        {
            cout << "Введите название Издательства: " << endl;
            getline(cin, name);
        }
        while (address == "" || size(address) >= 30)
        {
            cout << "Введите адрес Издательства: " << endl;
            getline(cin, address);
        }
        ourPublisherHouse = Fabric::make_obj(ourprintedEdition, name, address);
    }
    delete[]ourprintedEdition;
    try
    {
        tempStr = ourPublisherHouse->getName() + "123";
        ourPublisherHouse->setName(tempStr.data());
    }
    catch (PublisherHouseException& ex)
    {
        cout << ex.what() << endl;
    }
    try
    {
        ourPublisherHouse->setCountPages(ourPublisherHouse->getCountPages() + 2000);
    }
    catch (PublisherHouseException& ex)
    {
        cout << ex.what() << endl;
    }
    try
    {
        ourPublisherHouse->setPrice(ourPublisherHouse->getPrice() + 3000000);
    }
    catch (PublisherHouseException& ex)
    {
        cout << ex.what() << endl;
    }
    if (Fabric::getType() == HoroscopePubl)
    {
        try
        {
            cout << "Введите свой знак задиака: ";
            cin >> yourzadiak;
            ourPublisherHouse->getPredict(yourzadiak);
        }
        catch (int ex)
        {
            cout << ex << endl;
            while (yourzadiak == "" || size(yourzadiak) > 10)
            {
                cout << "Введите свой знак задиака: ";
                cin >> yourzadiak;
            }
            ourPublisherHouse->getPredict(yourzadiak);
        }
    }
    ourPublisherHouse->show();
    delete[]ourPublisherHouse;
    return 0;
}
