#pragma once
#include "PrintedEdition.h"
#include "ScientificJournal.h"
#include "Newspapper.h"
#include "Horoscope.h"
using namespace std;

enum typePublisherHouse{JournalPubl, NewspapperPubl, HoroscopePubl};

class PublisherHouseException : public std::exception
{
protected:
	std::string msg;
public:
	PublisherHouseException(const char* msg) noexcept;
	const char* what() const noexcept override;
};

class PublisherHouse
{
protected:
	string emblem;
	string addres;
	PrintedEdition* printedEdition;
	PublisherHouse(string emblem, string adddres, PrintedEdition* printedEdition);
	void validateEmblemAddres(string emblem, string addres);
public:
	string getEmblem() const;
	string getAddress() const;
	void setName(const char* name);
	void setCountPages(int countPages);
	void setPrice(double price);
	std::string getName() const;
	int getCountPages() const;
	double getPrice() const;
	virtual void show() const;
	virtual ~PublisherHouse();
	//Funcs, overrided in doughter classes
	virtual void setArticles(Article**, int) {};
	virtual Article** getArticles() { return nullptr;  };
	virtual int getcountArticles() const { return -1; };
	virtual void sort(parametrSort) {};
	virtual void append(const Article&) {};
	virtual void setNewscolumn(const std::string*, int) {};
	virtual void appendNews(const std::string) {};
	virtual void pop(std::string) {};
	virtual void setPredictMassive(Prediction**) {};
	virtual void getPredict(std::string) const {};
};

class JournalPublisherHouse : public PublisherHouse
{
private:
	JournalPublisherHouse(string emblem, string address, ScientificJournal* SJ) : PublisherHouse(emblem, address, SJ) {};
public:
	static JournalPublisherHouse* make_obj(ScientificJournal* SJ, string emblem, string address);
	void setArticles(Article**, int) override;
	Article** getArticles() override;
	int getcountArticles() const override;
	void sort(parametrSort) override;
	void pop(std::string) override;
	void append(const Article&) override;
	void show() const override;
	virtual ~JournalPublisherHouse();
};

class NewspapperPublisherHouse : public PublisherHouse
{
private:
	NewspapperPublisherHouse(string emblem, string address, Newspapper* NP) : PublisherHouse(emblem, address, NP) {};
public:
	static NewspapperPublisherHouse* make_obj(Newspapper* NP, string emblem, string address);
	void setNewscolumn(const std::string*, int) override;
	void appendNews(const std::string) override;
	void pop(std::string) override;
	void show() const override;
	virtual ~NewspapperPublisherHouse();
};

class HoroscopePublisherHouse : public PublisherHouse
{
private:
	HoroscopePublisherHouse(string emblem, string address, Horoscope* HC) : PublisherHouse(emblem,address,HC) {};
public:
	static HoroscopePublisherHouse* make_obj(Horoscope* H, string emblem, string address);
	void setPredictMassive(Prediction**) override;
	void getPredict(std::string) const override;
	void show() const override;
	virtual ~HoroscopePublisherHouse();
};

class Fabric
{
private:
	static typePublisherHouse type;
public:
	static void setType(typePublisherHouse t);
	static typePublisherHouse getType();
	static PublisherHouse* make_obj(PrintedEdition* printedEdition, string emblem, string address);
};
