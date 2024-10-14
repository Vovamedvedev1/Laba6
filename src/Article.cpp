#define  _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include "string.h"
#include "Article.h"
using namespace std;

Exception::Exception(const char* msg) noexcept
{
    this->msg = msg;
}
const char* Exception::what() const noexcept
{
    return this->msg.c_str();
}

bool ValidatorString::operator()(const char* str)
{
    if (strlen(str) == 0 || strlen(str) > 70)
        return false;
    return true;
}
Data::Data() 
{
    this->year = 0;
    this->month = 0;
    this->day = 0;
};
Data::Data(int day, int month, int year)
{
    if (year <= 10 || year >= 25)
        throw Exception("Неверное значение года");
    if (month <= 0 || month >= 13)
        throw Exception("Неверное значение месяца");
    if (day <= 0 || day >= 30)
        throw Exception("Неверное значение дня");
    this->year = year;
    this->month = month;
    this->day = day;
}
Data::~Data() {};
int Data::operator_int() const
{
    return this->year * 365 + this->month * 30 + this->day;
}

bool operator <= (const Data& data1, const Data& data2)
{
    if (data1.operator_int() <= data2.operator_int())
        return true;
    return false;
}

void Article::validator(const char* author, const char* title, const char* paragraph, int countSimbols) const
{
    ValidatorString validator;
    if (!validator(author))
        throw Exception("Неверное значение author");
    if (!validator(title))
        throw Exception("Неверное значение title");
    if (!validator(paragraph))
        throw Exception("Неверное значение paragraph");
    if (countSimbols <= 0)
        throw Exception("Неверное количество символов в статье");
}

Article::Article()
{
    this->author = new char();
    this->title = new char();
    this->paragraph = new char();
    this->countSimbols = 0;
}
Article::Article(const char* author, const char* title, const char* paragraph, int countSimbols, const Data& data)
{
    this->validator(author, title, paragraph, countSimbols);
    this->author = new char[strlen(author) + 1];
    strncpy(this->author, author, strlen(author));
    this->author[strlen(author)] = '\0';
    this->title = new char[strlen(title) + 1];
    strncpy(this->title, title, strlen(title));
    this->title[strlen(title)] = '\0';
    this->paragraph = new char[strlen(paragraph) + 1];
    strncpy(this->paragraph, paragraph, strlen(paragraph));
    this->paragraph[strlen(paragraph)] = '\0';
    this->countSimbols = countSimbols;
    this->data = data;
}

void Article::operator=(const Article& other)
{
    if (this->author != nullptr)
    {
        delete[]this->author;
        this->author = nullptr;
    }
    if (this->title != nullptr)
    {
        delete[]this->title;
        this->title = nullptr;
    }
    if (this->paragraph != nullptr)
    {
        delete[]this->paragraph;
        this->paragraph = nullptr;
    }
    this->author = new char[strlen(other.getAuthor().data()) + 1];
    this->title = new char[strlen(other.getTitle().data()) + 1];
    this->paragraph = new char[strlen(other.getParagraph().data()) + 1];
    strncpy(this->author, other.getAuthor().data(), strlen(other.getAuthor().data()));
    strncpy(this->title, other.getTitle().data(), strlen(other.getTitle().data()));
    strncpy(this->paragraph, other.getParagraph().data(), strlen(other.getParagraph().data()));
    this->author[strlen(other.getAuthor().data())] = '\0';
    this->title[strlen(other.getTitle().data())] = '\0';
    this->paragraph[strlen(other.getParagraph().data())] = '\0';
    this->countSimbols = other.getCountSimbols();
    this->data = other.getData();
}

string Article::getAuthor() const
{
    return string(this->author);
}
string Article::getTitle() const
{
    return string(this->title);
}
string Article::getParagraph() const
{
    return string(this->paragraph);
}
int Article::getCountSimbols() const
{
    return this->countSimbols;
}

const Data& Article::getData() const
{
    return this->data;
}

Article::~Article()
{
    delete[]this->author;
    delete[]this->title;
    delete[]this->paragraph;
}

ostream& operator << (ostream& os, const Article& it)
{
    os << "------------------------------------------" << endl;
    os << "Автор статьи: " << it.getAuthor() << endl;
    os << "Название статьи: " << it.getTitle() << endl;
    os << "Глава журнала: " << it.getParagraph() << endl;
    os << "Количество символов: " << it.getCountSimbols() << endl;
    os << "Дата публикации: " << it.getData().day << ":" << it.getData().month << ":" << it.getData().year << endl;
    os << "------------------------------------------" << endl;
    return os;
}
