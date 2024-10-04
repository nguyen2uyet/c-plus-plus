#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
private:
    int initialAge;

public:
    Person(int initialAge)
    {
        if (initialAge >= 0)
        {
            this->initialAge = initialAge;
        }
        else
        {
            cout << "Age is not valid, setting age to 0." << endl;
            this->initialAge = 0;
        }
    }

    void yearPasses()
    {
        this->initialAge++;
    }
    void amIOld()
    {
        if (initialAge < 13)
        {
            cout << "You are young." << endl;
        }
        else if (initialAge >= 13 && initialAge < 18)
        {
            cout << "You are a teenager." << endl;
        }
        else
        {
            cout << "You are old." << endl;
        }
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int age;
        cin >> age;
        Person p(age);
        p.amIOld();
        p.yearPasses();
        p.yearPasses();
        p.yearPasses();
        p.amIOld();
        cout << endl;
    }
    return 0;
}