#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> m;
    map<string, int>::iterator it;
    int queries, type, data;
    string key;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> key;
            cin >> data;
            if (m.find(key) == m.end())
            {
                m.insert(make_pair(key, data));
            }
            else
            {
                data += m.find(key)->second;
                m.erase(key);
                m.insert(make_pair(key, data));
            }
        }
        else if (type == 2)
        {
            cin >> key;
            m.erase(key);
            m.insert(make_pair(key, 0));
        }
        else
        {
            cin >> key;
            it = m.find(key);
            if (it != m.end())
            {
                cout << it->second << endl;
            }
        }
    }
    return 0;
}
