#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "funcs.h"
using namespace std;

void funcScientificJournal(PrintedEdition*& pe)
{
    Article** articals;
    int count = 0;
    string* paragraphs;
    string* news;
    fstream outputarticals("1.txt");
    if (outputarticals.is_open())
    {
        string tempStr;
        while (!outputarticals.eof())
        {
            getline(outputarticals, tempStr);
            if (tempStr == "")
                count++;
        }
        count++;
        articals = new Article * [count];
        outputarticals.clear();
        outputarticals.seekp(0, ios::beg);
        string name;
        string title;
        string paragraph;
        int countSimbols, day, month, year;
        for (int i = 0; i < count; i++)
        {
            getline(outputarticals, name);
            getline(outputarticals, title);
            getline(outputarticals, paragraph);
            outputarticals >> countSimbols >> day >> month >> year;
            if (!outputarticals.eof())
            {
                getline(outputarticals, tempStr);
                getline(outputarticals, tempStr);
            }
            try
            {
                articals[i] = new Article(name.data(), title.data(), paragraph.data(), countSimbols, Data(day, month, year));
            }
            catch (const Exception& ex)
            {
                cout << ex.what() << endl;
                return;
            }
        }
    }
    else
    {
        cout << "���� �� ��� ������!!!" << endl;
        return;
    }
    outputarticals.close();
    paragraphs = new string[4];
    paragraphs[0] = "��������";
    paragraphs[1] = "�������";
    paragraphs[2] = "��������";
    paragraphs[3] = "���������";
    news = new string[4];
    news[0] = "������� 1";
    news[1] = "������� 2";
    news[2] = "������� 3";
    news[3] = "������� 4";
    try
    {
        pe = new ScientificJournal("����� � �����", 4, paragraphs, 230, 150.7, count, articals);
    }
    catch (const Exception& ex)
    {
        cout << ex.what() << endl;
    }

    for (int i = 0; i < count; i++)
    {
        delete articals[i];
    }
    delete[]articals;
    delete[]paragraphs;
}


void funcNewspapper(PrintedEdition*& pe)
{
    string* str = new string[2];
    str[0] = "����� ������������� � ��������";
    str[1] = "���� � ���������� A�����";
    try
    {
        pe = new Newspapper("������������� ������", 20, 156.7, str, 2);
    }
    catch (const Exception& ex)
    {
        cout << "!!!!!!!!!!!!!!!!" << endl;
        cout << ex.what() << endl;
    }
    delete[]str;
}

void funcHoroscope(PrintedEdition*& pe)
{
    Prediction** predictions;
    int count = 0;
    fstream outputarticals("2.txt");
    if (outputarticals.is_open())
    {
        string tempStr;
        while (!outputarticals.eof())
        {
            getline(outputarticals, tempStr);
            if (tempStr == "")
                count++;
        }
        count++;
        cout << count << endl;
        predictions = new Prediction*[count];
        outputarticals.clear();
        outputarticals.seekp(0, ios::beg);
        string zadiak;
        string financ;
        string emot;
        string health;
        for (int i = 0; i < count; i++)
        {
            getline(outputarticals, zadiak);
            getline(outputarticals, financ);
            getline(outputarticals, emot);
            getline(outputarticals, health);
            if (!outputarticals.eof())
            {
                getline(outputarticals, tempStr);
            }
            try
            {
                predictions[i] = new Prediction(zadiak, financ, emot, health);
            }
            catch (const Exception& ex)
            {
                cout << ex.what() << endl;
                return;
            }
        }
    }
    else
    {
        cout << "���� �� ��� ������!!!" << endl;
        return;
    }
    outputarticals.close();
    if (predictions != nullptr)
    {
        pe = new Horoscope("��������_��_�.�����", 15, 187.6, predictions);
        for (int i = 0; i < count; i++)
        {
            delete predictions[i];
        }
        delete[]predictions;
    }
}

