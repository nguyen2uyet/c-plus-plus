#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> s;
    set<int>::iterator it;
    int queries, type, number;
    cin >> queries;

    for (int i = 0; i < queries; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> number;
            s.insert(number);
        }
        else if (type == 2)
        {
            cin >> number;
            s.erase(number);
        }
        else
        {
            cin >> number;
            it = s.find(number);
            if (it != s.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
