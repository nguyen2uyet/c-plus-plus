#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> to_binary(int n)
{
    vector<int> binary_num;
    while (n > 0)
    {
        binary_num.push_back(n % 2);
        n = n / 2;
    }

    reverse(binary_num.begin(), binary_num.end());

    // for (int i = 0; i < binary_num.size(); i++)
    // {
    //     cout << binary_num.at(i);
    // };
    return binary_num;
}

void max_num_of_consecutive(vector<int> binary_num)
{
    int m = 0;
    int t = 0;
    for (int i = 0; i < binary_num.size(); i++)
    {
        if (binary_num.at(i) == 1)
        {
            t++;
        }
        else
        {
            if (m <= t)
            {
                m = t;
            }
            t = 0;
        }
    }
    if (m <= t)
    {
        m = t;
    }
    cout << m;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    max_num_of_consecutive(to_binary(n));

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
