#pragma once

class Prediction
{
private:
    std::string zodiacSign;
    std::string finance;
    std::string emotions;
    std::string health;
public:
    Prediction();
    Prediction(std::string, std::string, std::string, std::string);
    std::string operator[](int index);
    friend std::ostream& operator << (std::ostream&, Prediction&);
    ~Prediction();
};