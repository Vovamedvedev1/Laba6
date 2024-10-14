#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "Prediction.h"
using namespace std;

Prediction::Prediction() {}
Prediction::Prediction(string zodiacSign, string finance, string emotions, string health)
{
    this->zodiacSign = zodiacSign;
    this->finance = finance;
    this->emotions = emotions;
    this->health = health;
}
string Prediction::operator[](int index)
{
    string output;
    switch (index)
    {
    case 0:
        output = this->zodiacSign;
    case 1:
        output = this->finance;
    case 2:
        output = this->emotions;
    case 3:
        output = this->health;
    }
    return output;
}
ostream& operator << (std::ostream& os, Prediction& pr)
{
    os << "--------------------------------------------------" << endl;
    os << "«нак задиака:   " << pr[0] << endl;
    os << "‘инансовое состо€ние:   " << pr[1] << endl;
    os << "Ёмоциональное состо€ние:   " << pr[2] << endl;
    os << "«доровье:   " << pr[3] << endl;
    return os;
}

Prediction::~Prediction()
{

}