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
    switch (n)
    {
    case 1:
        funcNewspapper(ourprintedEdition);
        Fabric::setType(NewspapperPubl);
        ourPublisherHouse = Fabric::make_obj(ourprintedEdition, name, address);
        delete[]ourprintedEdition;
        tempStr = ourPublisherHouse->getName() + "123";
        ourPublisherHouse->setName(tempStr.data());
        ourPublisherHouse->setCountPages(ourPublisherHouse->getCountPages() + 10);
        ourPublisherHouse->setPrice(ourPublisherHouse->getPrice() + 10);
        ourPublisherHouse->appendNews("Скандал Филиппа Киркорова и Николая Баскова");
        ourPublisherHouse->appendNews("Рост цен на продукты питания");
        ourPublisherHouse->appendNews("Израильско-палестинский конфликт");
        ourPublisherHouse->pop("Рост цен на продукты питания");
        break;
    case 2:
        funcScientificJournal(ourprintedEdition);
        Fabric::setType(JournalPubl);
        ourPublisherHouse = Fabric::make_obj(ourprintedEdition, name, address);
        delete[]ourprintedEdition;
        tempStr = ourPublisherHouse->getName() + "456";
        ourPublisherHouse->setName(tempStr.data());
        ourPublisherHouse->setCountPages(ourPublisherHouse->getCountPages() + 20);
        ourPublisherHouse->setPrice(ourPublisherHouse->getPrice() + 20);
        ourPublisherHouse->append(Article("Виктор Тимофеев", "Природа Кении", "География", 1700, Data(11, 8, 13)));
        ourPublisherHouse->append(Article("Федор Тимохин", "История Золотой Орды", "История", 4000, Data(11, 8, 17)));
        ourPublisherHouse->pop("Популяция Сибирской рыси на террритории Кузбасса");
        ourPublisherHouse->sort(DATA);
        cout << " Список статей отсортированный по дате " << endl;
        for (int i = 0; i < ourPublisherHouse->getcountArticles(); i++)
            cout << *ourPublisherHouse->getArticles()[i] << endl;
        ourPublisherHouse->sort(COUNTSIMBOLS);
        cout << " Список статей отсортированный по количеству символов " << endl;
        for (int i = 0; i < ourPublisherHouse->getcountArticles(); i++)
            cout << *ourPublisherHouse->getArticles()[i] << endl;
        break;
    case 3:
        funcHoroscope(ourprintedEdition);
        Fabric::setType(HoroscopePubl);
        ourPublisherHouse = Fabric::make_obj(ourprintedEdition, name, address);
        delete[]ourprintedEdition;
        tempStr = ourPublisherHouse->getName() + "789";
        ourPublisherHouse->setName(tempStr.data());
        ourPublisherHouse->setCountPages(ourPublisherHouse->getCountPages() + 30);
        ourPublisherHouse->setPrice(ourPublisherHouse->getPrice() + 30);
        string yourzadiak;
        cout << "Введите свой знак задиака: ";
        cin >> yourzadiak;
        ourPublisherHouse->getPredict(yourzadiak);
        break;
    }
    if (ourPublisherHouse != nullptr)
    {
        ourPublisherHouse->show();
        delete[]ourPublisherHouse;
    }
    return 0;
}
