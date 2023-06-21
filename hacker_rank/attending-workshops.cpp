#include <bits/stdc++.h>

using namespace std;

// Define the structs Workshops and Available_Workshops.
struct Workshops
{
    friend ostream &operator<<(ostream &os, const Workshops &obj);
    int start_time;
    int duration;
    int end_time;
    bool operator<(const Workshops &w)
    {
        return (this->end_time < w.end_time);
    }
};

ostream &operator<<(ostream &os, const Workshops &obj)
{
    os << obj.start_time << ": " << obj.end_time << ": "
       << obj.duration << "\n";
    return os;
}

struct Available_Workshops
{
    int n;
    vector<Workshops> vec;
};

Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *a = new Available_Workshops;
    a->n = n;
    Workshops t;
    for (int i = 0; i < n; i++)
    {
        t.start_time = start_time[i];
        t.duration = duration[i];
        t.end_time = start_time[i] + duration[i];
        a->vec.push_back(t);
    }
    sort(a->vec.begin(), a->vec.end());
    return a;
};
int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    int counter = 1;
    int end_time = ptr->vec.at(0).end_time;
    for (int i = 1; i < ptr->n; i++)
    {
        if (ptr->vec.at(i).start_time >= end_time)
        {
            counter++;
            end_time = ptr->vec.at(i).end_time;
        }
    }
    return counter;
};
// Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
