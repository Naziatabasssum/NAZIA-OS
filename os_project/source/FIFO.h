#include <bits/stdc++.h>
using namespace std;

int FIFO(int n, vector<pair<int, int>> &anb)
{

    vector<pair<pair<int, int>, char>> v(n);

    for (int i = 0; i < n; i++)
    {

        v[i].first.first = anb[i].first;
        v[i].first.second = anb[i].second;
        v[i].second = 'A' + i;
    }
    sort(v.begin(), v.end());

    cout << "----------------Gantt Chart-----------------" << endl;
    cout << "Time  : Character" << endl;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time = max(v[i].first.first, time);
        time += v[i].first.second;
        cout << time << ' ' << v[i].second << endl;
    }
    cout << endl;
    cout << "FCFS"<< " took " << time << " Units time" << endl;
    // cout<<"Times : "<<time<<endl;

    return time;
}