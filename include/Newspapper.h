#pragma once

#include "PrintedEdition.h"


class Newspapper : public PrintedEdition
{
private:
    int counternews;
    std::string* newscolumn{ nullptr };
    void validatorNewscolumn(int, const std::string*);
public:
    Newspapper();
    Newspapper(const char*, int, double, const std::string*, int);
    void func();
    virtual void setNewscolumn(const std::string*, int) override;
    virtual void appendNews(const std::string) override;
    virtual void show() const override;
    virtual ~Newspapper();
};