#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "ScientificJournal.h"
using namespace std;

void ScientificJournal::validatorParagraphs(int countParagraphs, const string* str) const
{
    if (countParagraphs <= 0 || countParagraphs >= 30)
        throw Exception("Неверное значение countParagraphs");
    ValidatorString validator;
    for (int i = 0; i < countParagraphs; i++)
    {
        if (!validator(str[i].data()))
            throw ("Ошибка в названии параграфа");
    }
}

void ScientificJournal::validatorCountArticles(int countArticles) const
{
    if (countArticles <= 0)
        throw Exception("Неверное значение countArticles");
}

void ScientificJournal::validatorArticle(Article** massiveArticles, const Article& art, int countArticles) const
{
    bool flag = false;
    for (int i = 0; i < *this->countParagraphs; i++)
    {
        if (string(this->paragraphs[i]) == art.getParagraph())
        {
            flag = true;
            break;
        }
    }
    if (flag == false)
        throw Exception("Указанного парагрофа для размещения статьи не существует!!!");
    for (int i = 0; i < countArticles; i++)
    {
        if (massiveArticles[i]->getTitle() == art.getTitle())
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
        throw Exception("Статья с таким именем уже существует!!!");
}

ScientificJournal::ScientificJournal() : PrintedEdition()
{
    this->countParagraphs = new int();
    this->paragraphs = new string();
    this->countArticles = new int();
    this->articles = new Article * ();
}

ScientificJournal::ScientificJournal(const char* name, int countParagraphs, string* str, int countPages, double price, int countArticles, Article** articles) : PrintedEdition(name, countPages, price)
{
    this->setParagraphs(str, countParagraphs);
    this->setArticles(articles, countArticles);
}

void ScientificJournal::setParagraphs(const string* str, int countParagraphs)
{
    this->validatorParagraphs(countParagraphs, str);
    if (this->paragraphs != nullptr)
    {
        delete[]this->paragraphs;
        this->paragraphs = nullptr;
    }
    if (this->countParagraphs != nullptr)
    {
        delete this->countParagraphs;
        this->countParagraphs = nullptr;
    }
    this->countParagraphs = new int();
    *this->countParagraphs = countParagraphs;
    this->paragraphs = new string[*this->countParagraphs];
    for (int i = 0; i < *this->countParagraphs; i++)
    {
        this->paragraphs[i] = str[i];
    }
}

void ScientificJournal::setArticles(Article** articles, int countArticles)
{
    this->validatorCountArticles(countArticles);
    for (int i = 0; i < countArticles; i++)
        this->validatorArticle(articles, *articles[i], i);
    if (this->articles != nullptr)
    {
        for (int i = 0; i < *this->countArticles; i++)
        {
            delete this->articles[i];
        }
        delete[]this->articles;
        this->articles = nullptr;
        *this->countArticles = 0;
    }
    if (this->countArticles != nullptr)
    {
        delete this->countArticles;
        this->countArticles = nullptr;
    }
    this->countArticles = new int();
    *this->countArticles = countArticles;
    this->articles = new Article * [*this->countArticles];
    for (int i = 0; i < *this->countArticles; i++)
    {
        this->articles[i] = new Article();
        *this->articles[i] = *(articles[i]);
    }
}

int ScientificJournal::getcountArticles() const
{
    return *this->countArticles;
}
Article** ScientificJournal::getArticles()
{
    return this->articles;
}


void ScientificJournal::sort(parametrSort par)
{
    if (par != parametrSort::DATA && par != parametrSort::COUNTSIMBOLS)
        throw Exception("Неверный параметр сортировки");
    int* dataMassive = new int[*this->countArticles];
    for (int i = 0; i < *this->countArticles; i++)
    {
        if (par == parametrSort::DATA)
            dataMassive[i] = this->articles[i]->getData().operator_int();
        if (par == parametrSort::COUNTSIMBOLS)
            dataMassive[i] = this->articles[i]->getCountSimbols();
    }
    this->shell_sort(dataMassive, this->articles, *this->countArticles);
    delete[]dataMassive;
}

void ScientificJournal::pop(string title)
{
    bool flag = false;
    int index = 0;
    for (int i = 0; i < *this->countArticles; i++)
    {
        if (title == this->articles[i]->getTitle())
        {
            index = i;
            flag = true;
            break;
        }
    }
    if (flag == false)
        return;

    Article** temp = new Article * [*this->countArticles - 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = new Article();
        *temp[i] = *this->articles[i];
    }
    for (int i = index + 1; i < *this->countArticles; i++)
    {
        temp[i - 1] = new Article();
        *temp[i - 1] = *this->articles[i];
    }
    this->setArticles(temp, *this->countArticles - 1);
    for (int i = 0; i < *this->countArticles; i++)
        delete temp[i];
    delete[]temp;
}

void ScientificJournal::append(const Article& art)
{
    this->validatorCountArticles(*this->countArticles + 1);
    this->validatorArticle(this->articles, art, *this->countArticles);
    Article** temp = new Article * [*this->countArticles + 1];
    for (int i = 0; i < *this->countArticles; i++)
    {
        temp[i] = new Article();
        *temp[i] = *this->articles[i];
    }
    temp[*this->countArticles] = new Article();
    *temp[*this->countArticles] = art;
    this->setArticles(temp, *this->countArticles + 1);
    for (int i = 0; i < *this->countArticles; i++)
    {
        delete temp[i];
    }
    delete[]temp;
}


ScientificJournal::~ScientificJournal()
{
    for (int i = 0; i < *this->countArticles; i++)
    {
        delete this->articles[i];
    }
    delete[]this->articles;
    this->articles = nullptr;
    delete this->countArticles;
    delete[]this->paragraphs;
    this->paragraphs = nullptr;
    delete this->countParagraphs;
    cout << "Деструктор ScientificJournal" << endl;
}

void ScientificJournal::shell_sort(int* a, Article** articles, int n)
{
    int j, h = 1;
    int x;
    Article* y;
    while (h <= n)
        h = 3 * h + 1;
    h = (h - 1) / 3;
    while (h >= 1)
    {
        for (int p = 0; p < h; p++)
        {
            for (int i = p + h; i < n; i += h)
            {
                x = a[i];
                y = articles[i];
                j = i - h;
                while (x < a[j] && j >= 0)
                {
                    a[j + h] = a[j];
                    articles[j + h] = articles[j];
                    j = j - h;
                }
                a[j + h] = x;
                articles[j + h] = y;
            }
        }
        h = (h - 1) / 3;
    }
}




void ScientificJournal::show() const
{
    cout << "Информация об научном журнале" << endl;
    this->PrintedEdition::show();
    cout << "Количество параграфов:  " << *this->countParagraphs << endl;
    cout << "Количество статей/новостей:  " << *this->countArticles << endl;
    cout << "Содержание:   " << endl;
    for (int i = 0; i < *this->countParagraphs; i++)
    {
        cout << "Параграф: " << this->paragraphs[i] << endl;
        cout << "-------------------------------" << endl;
        for (int j = 0; j < *this->countArticles; j++)
        {
            if (this->articles[j]->getParagraph() == this->paragraphs[i])
                cout << *this->articles[j] << endl;
        }
    }
}

PrintedEdition* ScientificJournal::copy() const
{
    ScientificJournal* SJ = new ScientificJournal(this->name, *this->countParagraphs, this->paragraphs, *this->countPages, *this->price, *this->countArticles, this->articles);
    return SJ;
}
