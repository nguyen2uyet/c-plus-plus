#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string n;
        cin >> n;
        int number = stoi(s);
        m[n] = number;
    }
    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        if (m.find(key) == m.end())
        {
            cout << "Not found";
        }
        else
        {
            cout << key << " = " << m[key];
        }
        cout << endl;
    }
    return 0;
}
