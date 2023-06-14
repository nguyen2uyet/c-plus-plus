#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>

using namespace std;

string decimalToHex(double number)
{
    int n = (int)number;
    string answer = "";
    while (n != 0)
    {
        int rem = 0;
        char ch;
        rem = n % 16;
        if (rem < 10)
        {
            ch = rem + 48;
        }
        else
        {
            ch = rem + 55;
        }
        answer += ch;
        n = n / 16;
    }
    int i = 0, j = answer.size() - 1;
    while (i <= j)
    {
        swap(answer[i], answer[j]);
        i++;
        j--;
    }
    string prefix = "0x";
    for (char c : answer)
    {
        prefix += c;
    }
    return prefix;
}

string doubleToString(double number)
{
    double prefix = round(number / 0.01) * 0.01;
    stringstream stream;
    // Set precision level to 3
    stream.precision(2);
    stream << fixed;

    // Convert double to string
    stream << prefix;
    string str = stream.str();
    if (str[0] != '-')
    {
        string new_str = "+";
        for (char ch : str)
        {
            new_str += ch;
        }
        return new_str;
    }
    return str;
}

string doubleToScientificString(double number)
{
    stringstream stream;
    // Set precision level to 9
    stream.precision(9);
    stream << scientific;

    // Convert double to string
    stream << number;
    string str = stream.str();
    str[11] = 'E';
    return str;
}
string prettyNumberType2(string number)
{
    string str = "_______________";
    int j = str.size() - 1 - number.size();
    for (int i = str.size() - 1; i >= j; i--)
    {
        str[i] = number[i - j];
    }
    return str;
}
int main()
{
    int N;
    cin >> N;
    // cout << setiosflags(ios::uppercase);
    // cout << setw(0xf) << internal;
    while (N--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;
        cout << decimalToHex(A) << endl;
        cout << prettyNumberType2(doubleToString(B)) << endl;
        cout << doubleToScientificString(C);
    }
}