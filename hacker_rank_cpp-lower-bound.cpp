#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, n;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool numberIsInArray = false;
        int t, p = 0;
        cin >> t;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == t)
            {
                p = j;
                numberIsInArray = true;
                break;
            }
            else
            {
                if (arr[j] >= t)
                {
                    p = j;
                    break;
                }
            }
        }
        if (numberIsInArray)
        {
            cout << "Yes " << p + 1 << endl;
        }
        else
        {
            cout << "No " << p + 1 << endl;
        }
    }
    return 0;
}