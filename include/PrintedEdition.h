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
    //Виртуальные методы для ScientificJournal
    virtual void setArticles(Article**, int) = 0;
    virtual Article** getArticles() = 0;
    virtual int getcountArticles() const = 0;
    virtual void sort(parametrSort)  = 0;
    virtual void append(const Article&) = 0;
    //Виртуальные методы для Newspapper
    virtual void setNewscolumn(const std::string*, int) = 0;
    virtual void appendNews(const std::string) = 0;
    //Виртуальные методы для Horoscope
    virtual void setPredictMassive(Prediction**) = 0;
    virtual void getPredict(std::string) const  = 0;
    //Виртуальные методы для всех классов
    virtual void show() const;
    virtual void pop(std::string) = 0;
    virtual PrintedEdition* copy() const = 0;
    virtual ~PrintedEdition();
};