#include <iostream>

using namespace std;

int main()
{

    int x = 35;

    int *p = &x;

    // address of x
    cout << p << endl;
    // address of p
    cout << &p << endl;
    // address of x
    cout << &x << endl;
    // value of p (equal with x)
    cout << *p << endl;

    return 0;
}