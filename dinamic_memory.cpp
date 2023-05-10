#include <iostream>

using namespace std;

int main()
{

    int *arr = new int;

    int size = 0;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        size += 1;
    }

    // cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    delete arr;

    return 0;
}