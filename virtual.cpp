#include <iostream>

using namespace std;

class Enemy
{
public:
    virtual void attack()
    {
        cout << "Enemy attack !";
    }
};

class Ninja : public Enemy
{
public:
    void attack()
    {
        cout << "Ninja attack !";
    }
};

int main()
{
    Ninja n;
    Enemy *e = &n;
    Enemy e1;
    e->attack();
    e1.attack();
    return 0;
}