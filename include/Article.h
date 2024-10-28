#pragma once

enum parametrSort { DATA, COUNTSIMBOLS };

class ValidatorString
{
public:
    ValidatorString() = default;
    bool operator()(const char* str);
};

class Exception : public std::exception
{
protected:
    std::string msg;
public:
    Exception(const char* msg) noexcept;
    const char* what() const noexcept override;
};


struct Data
{
    int day;
    int month;
    int year;
    Data();
    Data(int, int, int);
    int operator_int() const;
    friend bool operator <= (const Data&, const Data&);
    ~Data();
};


class Article
{
private:
    char* author{ nullptr };
    char* title{ nullptr };
    char* paragraph{ nullptr };
    int countSimbols;
    Data data;
    void validator(const char*, const char*, const char*, int) const;
public:
    Article();
    Article(const char*, const char*, const char*, int, const Data&);
    void operator=(const Article& other);
    std::string getAuthor() const;
    std::string getTitle() const;
    std::string getParagraph() const;
    int getCountSimbols() const;
    const Data& getData() const;
    friend std::ostream& operator << (std::ostream&, const Article&);
    ~Article();
};