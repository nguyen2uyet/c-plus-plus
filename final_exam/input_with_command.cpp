#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

void input_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void caculate_the_array(int *arr, int size)
{

    map<int, unsigned int> rv;

    for (int i = 0; i < size; i++)
    {
        rv[arr[i]]++;
    }

    map<int, unsigned int>::iterator it = rv.begin();

    // cout.precision(2);
    cout << endl;

    while (it != rv.end())
    {
        double percentage = (((double)it->second) / size) * 100;
        cout << "Number " << it->first << " occurs " << percentage << "%" << endl;
        ++it;
    }
}

int main()
{

    int *arr = new int;
    int size = 10;

    input_array(arr, size);
    print_array(arr, size);
    caculate_the_array(arr, size);

    delete arr;

    return 0;
}