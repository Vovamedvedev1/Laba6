#pragma once

#include "Article.h"
#include "Prediction.h"
#include "PrintedEdition.h"

class Horoscope : public PrintedEdition
{
private:
    std::string* zadiacsign{ nullptr };
    Prediction** predictMassive{ nullptr };
    //ѕереопредел€емые дочерние методы других классов
    virtual void setArticles(Article**, int) override { throw Exception("Error Interface"); };
    virtual int getcountArticles() const override { throw Exception("Error Interface"); return -1; };
    virtual void sort(parametrSort) override { throw Exception("Error Interface"); };
    virtual void pop(std::string&&) override { throw Exception("Error Interface"); };
    virtual void append(const Article&) override { throw Exception("Error Interface"); };
    virtual void setNewscolumn(const std::string*, int) override { throw Exception("Error Interface"); };
    virtual void appendNews(const std::string) override { throw Exception("Error Interface"); };
public:
    Horoscope();
    Horoscope(const char*, int, double, Prediction**);
    virtual void setPredictMassive(Prediction**) override;
    virtual void getPredict(std::string) const override;
    virtual ~Horoscope();
};

