#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    // complete the function
    if (x == 0)
    {
        return false;
    }
    else
    {
        int *arr = new int;
        int size = 0;
        while (x > 0)
        {
            arr[size] = x % 10;
            x = (x - x % 10) / 10;
            size = size + 1;
        }
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != arr[size - i - 1])
            {
                return false;
            }
        }
        delete arr;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (isPalindrome(n))
    {
        cout << n << " is a palindrome";
    }
    else
    {
        cout << n << " is NOT a palindrome";
    }
    return 0;
}