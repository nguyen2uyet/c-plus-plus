#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

void input_array(int *arr, int size)
{
    string inFileName = "C:\\Users\\nguye\\Desktop\\C++\\final_exam\\numbers.txt";
    ifstream inFile;
    inFile.open(inFileName.c_str());

    if (inFile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            inFile >> arr[i];
        }

        inFile.close(); // CLose input file
    }
    else
    { // Error message
        cerr << "Can't find input file " << inFileName << endl;
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void output_to_file(int *arr, int size, string filename)
{
    map<int, unsigned int> rv;
    ofstream MyFile(filename);

    for (int i = 0; i < size; i++)
    {
        rv[arr[i]]++;
    }

    map<int, unsigned int>::iterator it = rv.begin();

    // cout.precision(2);
    cout << endl;

    while (it != rv.end())
    {
        double percentage = (((double)it->second) / size) * 100;
        MyFile << "Number " << it->first << " occurs " << percentage << "%" << endl;
        ++it;
    }

    // Close the file
    MyFile.close();
}

void input_array_and_size(int *arr, int &size)
{
    string inFileName = "C:\\Users\\nguye\\Desktop\\C++\\final_exam\\numbers.txt";
    ifstream inFile;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void caculate_the_array(int *arr, int size)
{

    map<int, unsigned int> rv;

    for (int i = 0; i < size; i++)
    {
        rv[arr[i]]++;
    }

    map<int, unsigned int>::iterator it = rv.begin();

    cout.precision(3);
    cout << endl;

    while (it != rv.end())
    {
        double percentage = (((double)it->second) / size) * 100;
        cout << "Number " << it->first << " occurs " << percentage << "%" << endl;
        ++it;
    }
}

int main()
{
    int *arr = new int;
    int size = 10;
    string filename = "C:\\Users\\nguye\\Desktop\\C++\\final_exam\\output.txt";
    // input_array(arr, size);
    input_array_and_size(arr, size);
    print_array(arr, size);
    caculate_the_array(arr, size);
    output_to_file(arr, size, filename);
    return 0;
}