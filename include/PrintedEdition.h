#pragma once

#include "Article.h"
#include "Prediction.h"


class PrintedEdition
{
protected:
    char* name{ nullptr };
    int* countPages{ nullptr };
    double* price{ nullptr };

    void validatorName(const char*) const;
    void validatorCountPages(int) const;
    void validatorPrice(double) const;
public:
    PrintedEdition();
    PrintedEdition(const char*, int, double);
    void setName(const char*);
    void setCountPages(int);
    void setPrice(double);
    std::string getName() const;
    int getCountPages() const;
    double getPrice() const;
    void func();
    //Виртуальные методы для ScientificJournal
    virtual void setArticles(Article**, int) {};
    virtual int getcountArticles() const { return 0; };
    virtual void sort(parametrSort) {};
    virtual void pop(std::string&&) {};
    virtual void append(const Article&) {};
    //Виртуальные методы для Newspapper
    virtual void setNewscolumn(const std::string*, int) {};
    virtual void appendNews(const std::string) {};
    //Виртуальные методы для Horoscope
    virtual void setPredictMassive(Prediction**) {};
    virtual void getPredict(std::string) const {};
    //Виртуальные методы для всех классов
    virtual void show() const;
    virtual ~PrintedEdition();
};