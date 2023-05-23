#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream MyFile;
    string s;
    cin >> s;
    MyFile.open("test.txt");

    MyFile << s;
}