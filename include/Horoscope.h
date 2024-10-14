#pragma once

#include "Article.h"
#include "Prediction.h"
#include "PrintedEdition.h"

class Horoscope : public PrintedEdition
{
private:
    std::string* zadiacsign{ nullptr };
    Prediction** predictMassive{ nullptr };
public:
    Horoscope();
    Horoscope(const char*, int, double, Prediction**);
    virtual void setPredictMassive(Prediction**) override;
    virtual void getPredict(std::string) const override;
    virtual ~Horoscope();
};

