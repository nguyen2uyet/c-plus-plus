#include <iostream>

using namespace std;

void printSpaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}

void printNumbers(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i;
    }
    for (int i = n - 1; i > 0; i--)
    {
        cout << i;
    }
}

int main()
{
    int N;
    cin >> N;
    int j = N - 1;
    for (int i = 1; i <= N; i++)
    {
        printSpaces(j--);
        printNumbers(i);
        cout << endl;
    }
    return 0;
}