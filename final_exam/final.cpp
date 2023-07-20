#include <iostream>
#include <vector>

using namespace std;

class Sportsman
{
protected:
    string name;
    int register_year;
    double _salary;

public:
    Sportsman(string name, int register_year, double salary)
    {
        this->name = name;
        this->register_year = register_year;
        this->_salary = salary;
    }
    // a
    bool operator<(const Sportsman &s)
    {
        if (register_year < s.register_year)
            return true;
        return false;
    }
    bool operator>(const Sportsman &s)
    {
        if (register_year > s.register_year)
            return true;
        return false;
    }

    bool operator==(const Sportsman &s)
    {
        if (register_year == s.register_year)
            return true;
        return false;
    }

    // b
    double salary()
    {
        if (register_year < 2010)
        {
            return _salary * 110 / 100;
        }
        return _salary;
    }
};
enum Style
{
    FREE_STYLE,
    BREASTSTROKE,
    BUTTERFLY,
    BACKSTROKE
};

class Swimmer : public Sportsman
{
private:
    Style swimming_style;
    bool opening_water;

public:
    Swimmer(string name, int register_year, double salary, Style swimming_style, bool opening_water) : Sportsman(name, register_year, salary)
    {
        this->swimming_style = swimming_style;
        this->opening_water = opening_water;
    }
    // 2.a
    bool checkSwimmingStyle()
    {
        if (swimming_style == FREE_STYLE)
        {
            return true;
        }
        return false;
    }
    // 2.b
    double salary()
    {
        if (register_year < 2010)
        {
            if (opening_water)
            {
                return _salary * 115 / 100;
            }
            else
            {
                return _salary * 110 / 100;
            }
        }
        else
        {
            if (opening_water)
            {
                return _salary * 105 / 100;
            }
            else
            {
                return _salary;
            }
        }
    }
    bool is_open()
    {
        return opening_water;
    }
};

class SwimmingCompetition
{
private:
    vector<Swimmer> list;
    bool opening_water;

public:
    SwimmingCompetition(bool opening_water)
    {
        this->opening_water = false;
    }
    // 3.a
    void addSwimmer(Swimmer s)
    {
        if (s.is_open() != opening_water)
        {
            throw "Swimmer is not valid !";
        }
        else
        {
            list.push_back(s);
        }
    }
};

int main()
{
    Sportsman s1("s1", 2020, 1000);
    Sportsman s2("s2", 2010, 2000);
    // 1.a
    if (s1 < s2)
    {
        cout << "s1<s2" << endl;
    }
    // 1.b
    cout << "s1 salary: " << s1.salary() << endl;
    cout << "s2 salary: " << s2.salary() << endl;
    // 2.a
    Swimmer s3("s3", 2010, 3000, FREE_STYLE, true);
    if (s3.checkSwimmingStyle())
        cout << "s3's style is FREE STYLE";
    // 2.b
    cout << "s3 salary: " << s3.salary() << endl;
    // 3.a
    SwimmingCompetition l1(true);
    SwimmingCompetition l2(false);
    l1.addSwimmer(s3);
    l2.addSwimmer(s3);
    return 0;
}