#pragma once

#include "PrintedEdition.h"


class Newspapper : public PrintedEdition
{
private:
    int counternews;
    std::string* newscolumn{ nullptr };
    void validatorNewscolumn(int, const std::string*);

    //ѕереопредел€емые дочерние методы других классов
    virtual void setPredictMassive(Prediction**) override { throw Exception("Error Interface"); };
    virtual void getPredict(std::string) const override { throw Exception("Error Interface"); };
    virtual void setArticles(Article**, int) override { throw Exception("Error Interface"); };
    virtual Article** getArticles() override { throw Exception("Error Interface"); return nullptr; };
    virtual int getcountArticles() const override { throw Exception("Error Interface"); return -1; };
    virtual void sort(parametrSort) override { throw Exception("Error Interface"); };
    virtual void append(const Article&) override { throw Exception("Error Interface"); };
public:
    Newspapper();
    Newspapper(const char*, int, double, const std::string*, int);
    virtual void setNewscolumn(const std::string*, int) override;
    virtual void appendNews(const std::string) override;
    virtual void pop(std::string) override;
    virtual void show() const override;
    virtual PrintedEdition* copy() const override;
    virtual ~Newspapper();
};