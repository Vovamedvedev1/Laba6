#pragma once

#include "PrintedEdition.h"

class ScientificJournal : public PrintedEdition
{
private:
    int* countParagraphs{ nullptr };
    std::string* paragraphs{ nullptr };
    int* countArticles{ nullptr };
    Article** articles{ nullptr };

    void shell_sort(int* a, Article** articles, int n);
    void validatorParagraphs(int, const std::string*) const;
    void validatorCountArticles(int) const;
    void validatorArticle(Article**, const Article&, int) const;
    void setParagraphs(const std::string*, int);
    //ѕереопредел€емые дочерние методы других классов
    virtual void setNewscolumn(const std::string*, int) override { throw Exception("Error Interface"); };
    virtual void appendNews(const std::string) override { throw Exception("Error Interface"); };
    virtual void setPredictMassive(Prediction**) override { throw Exception("Error Interface"); };
    virtual void getPredict(std::string) const override { throw Exception("Error Interface"); };
public:
    ScientificJournal();
    ScientificJournal(const char*, int, std::string*, int, double, int, Article**);
    virtual void setArticles(Article**, int) override;
    virtual Article** getArticles() override;
    virtual int getcountArticles() const override;
    virtual void sort(parametrSort) override;
    virtual void pop(std::string) override;
    virtual void append(const Article&) override;
    virtual void show() const override;
    virtual PrintedEdition* copy() const override;
    virtual ~ScientificJournal();
};



