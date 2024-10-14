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
    friend class Item;
public:
    ScientificJournal();
    ScientificJournal(const char*, int, std::string*, int, double, int, Article**);
    void setParagraphs(const std::string*, int);
    virtual void setArticles(Article**, int) override;
    virtual int getcountArticles() const override;
    Article** getArticles();
    virtual void sort(parametrSort) override;
    virtual void pop(std::string&&) override;
    virtual void append(const Article&) override;
    virtual void show() const override;
    virtual ~ScientificJournal();
};



