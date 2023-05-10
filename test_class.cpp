#include <iostream>
#include "MyClass.h"

using namespace std;

int main()
{
    MyClass obj;
    cout << obj.add(2, 3);
    MyClass *ptr = &obj;
    cout << ptr->add(2, 5);
    cout << (*ptr).add(2, 6);
    return 0;
}