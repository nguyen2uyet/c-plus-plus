#include <iostream>

using namespace std;

class CString
{
public:
    string s = "";
    int size = 0;
    CString()
    {
    }
    CString(string s)
    {
        this->s = s;
    }
    string get()
    {
        return this->s;
    }
    void set(string s)
    {
        this->s = s;
    }
    void find(string s)
    {
        size_t found = this->s.find(s);
        if (found != string::npos)
        {
            cout << s << " has found in " << this->s << endl;
        }
        else
        {
            cout << "string not found !";
        }
    }
    void add(string s)
    {
        this->s += s;
    }
    friend ostream &operator<<(ostream &output, const CString c1)
    {
        output << c1.s << endl;
        return output;
    };
    friend istream &operator>>(istream &input, CString c)
    {
        input >> c.s;
        return input;
    };
};

int main()
{
    CString c1("string1");
    CString c2;
    CString c3;
    cout << "Enter string c2: " << endl;
    cin >> c2;
    c3.set("This is string c3 !");
    c3.find("This");
    c3.find("Not");
    return 0;
}