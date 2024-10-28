#include <iostream>
#include <string>
#include <string.h>
#include "PublisherHouse.h"
using namespace std;

//!!!!!!!!!!!!!!!!!!!!!Fabric!!!!!!!!!!!!!!!!!!!
void Fabric::setType(typePublisherHouse t)
{
	type = t;
}

PublisherHouse* Fabric::make_obj(PrintedEdition* printedEdition, string emblem, string address)
{
	PublisherHouse* PE;
	switch (type)
	{
	case JournalPubl:
		PE = JournalPublisherHouse::make_obj(dynamic_cast<ScientificJournal*>(printedEdition), emblem, address);
		break;
	case NewspapperPubl:
		PE = NewspapperPublisherHouse::make_obj(dynamic_cast<Newspapper*>(printedEdition), emblem, address);
		break;
	case HoroscopePubl:
		PE = HoroscopePublisherHouse::make_obj(dynamic_cast<Horoscope*>(printedEdition), emblem, address);
		break;
	}
	return PE;
}

//!!!!!!!!!!!!!!!!!!!!!!!PublisherHouse!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
PublisherHouse::PublisherHouse(string emblem, string addres, PrintedEdition* printedEdition)
{
	this->emblem = emblem;
	this->addres = addres;
	this->printedEdition = printedEdition->copy();
}
string PublisherHouse::getEmblem() const
{
	return this->emblem;
}
string PublisherHouse::getAddress() const
{
	return this->addres;
}
void PublisherHouse::setName(const char* name)
{
	this->printedEdition->setName(name);
}
void PublisherHouse::setCountPages(int countPages)
{
	this->printedEdition->setCountPages(countPages);
}
void PublisherHouse::setPrice(double price)
{
	this->printedEdition->setPrice(price);
}
std::string PublisherHouse::getName() const
{
	return this->printedEdition->getName();
}
int PublisherHouse::getCountPages() const
{
	return this->printedEdition->getCountPages();
}
double PublisherHouse::getPrice() const
{
	return this->printedEdition->getPrice();
}
void PublisherHouse::show() const
{
	cout << "Emblem:   " << this->getEmblem() << endl;
	cout << "Address:  " << this->getAddress() << endl;
}
PublisherHouse::~PublisherHouse()
{
	cout << "~PublisherHouse()" << endl;
	delete[]this->printedEdition;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!JournalPublisherHouse!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
JournalPublisherHouse* JournalPublisherHouse::make_obj(ScientificJournal* SJ, string emblem, string address)
{
	return new JournalPublisherHouse(emblem, address, SJ);
}
void JournalPublisherHouse::setArticles(Article** art, int countArticles)
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	SJ->setArticles(art, countArticles);
}
Article** JournalPublisherHouse::getArticles()
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	return SJ->getArticles();
}
int JournalPublisherHouse::getcountArticles() const
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	return SJ->getcountArticles();
}
void JournalPublisherHouse::sort(parametrSort parametr)
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	SJ->sort(parametr);
}
void JournalPublisherHouse::pop(std::string str)
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	SJ->pop(str);
}
void JournalPublisherHouse::append(const Article& article)
{
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	SJ->append(article);
}
void JournalPublisherHouse::show() const
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!JournalPublisherHouse !!!!!!!!!!!!!!!!!!!!!!"<< endl;
	this->PublisherHouse::show();
	ScientificJournal* SJ = dynamic_cast<ScientificJournal*>(this->printedEdition);
	SJ->show();
}
JournalPublisherHouse::~JournalPublisherHouse()
{
	cout << "~JournalPublisherHouse()" << endl;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!NewspapperPublisherHouse!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
NewspapperPublisherHouse* NewspapperPublisherHouse::make_obj(Newspapper* NP, string emblem, string address)
{
	return new NewspapperPublisherHouse(emblem, address, NP);
}
void NewspapperPublisherHouse::setNewscolumn(const std::string* newsCol, int count)
{
	Newspapper* NP = dynamic_cast<Newspapper*>(this->printedEdition);
	NP->setNewscolumn(newsCol, count);
}
void NewspapperPublisherHouse::appendNews(const std::string news)
{
	Newspapper* NP = dynamic_cast<Newspapper*>(this->printedEdition);
	NP->appendNews(news);
}
void NewspapperPublisherHouse::pop(std::string news)
{
	Newspapper* NP = dynamic_cast<Newspapper*>(this->printedEdition);
	NP->pop(news);
}
void NewspapperPublisherHouse::show() const
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!NewspapperPublisherHouse !!!!!!!!!!!!!!!!!!!!!!"<< endl;
	this->PublisherHouse::show();
	Newspapper* NP = dynamic_cast<Newspapper*>(this->printedEdition);
	NP->show();
}
NewspapperPublisherHouse::~NewspapperPublisherHouse()
{
	cout << "~NewspapperPublisherHouse()" << endl;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!HoroscopePublisherHouse!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HoroscopePublisherHouse* HoroscopePublisherHouse::make_obj(Horoscope* H, string emblem, string address)
{
	return new HoroscopePublisherHouse(emblem, address, H);
}
void HoroscopePublisherHouse::setPredictMassive(Prediction** pred)
{
	Horoscope* HC = dynamic_cast<Horoscope*>(this->printedEdition);
	HC->setPredictMassive(pred);
}
void HoroscopePublisherHouse::getPredict(std::string zc) const
{
	Horoscope* HC = dynamic_cast<Horoscope*>(this->printedEdition);
	HC->getPredict(zc);
}
void HoroscopePublisherHouse::show() const
{
	cout << "-----------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!HoroscopePublisherHouse !!!!!!!!!!!!!!!!!!!!!!"<< endl;
	PublisherHouse::show();
	Horoscope* HC = dynamic_cast<Horoscope*>(this->printedEdition);
	HC->show();
}
HoroscopePublisherHouse::~HoroscopePublisherHouse()
{
	cout << "~HoroscopePublisherHouse()" << endl;
}

typePublisherHouse Fabric::type = JournalPubl; //инициализация по умолчанию