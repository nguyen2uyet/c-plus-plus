#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
public:
    string name;
    int age;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
protected:
    static int nextID;

public:
    int publications;
    int cur_id = 1;
    void getdata()
    {
        cin >> this->name;
        cin >> this->age;
        cin >> this->publications;
        cur_id = ++nextID;
    }
    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::nextID = 0;

class Student : public Person
{
protected:
    static int nextID;

public:
    int marks[6];
    int cur_id;
    int sum = 0;
    void getdata()
    {
        cin >> this->name;
        cin >> this->age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
            sum += marks[i];
        }
        cur_id = ++nextID;
    }
    void putdata()
    {
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

int Student::nextID = 0;

int main()
{

    int n, val;
    cin >> n; // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
