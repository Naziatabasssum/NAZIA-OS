#include <bits/stdc++.h>
using namespace std;

int Round_robin(int n,vector<pair<int,int>>&anb,int cpu_time)
{
    
    vector<pair<pair<int, int>, char>> v(n);

    for (int i = 0; i < n; i++)
    {
       
        v[i].first.first=anb[i].first;
        v[i].first.second=anb[i].second;
        v[i].second = 'A' + i;
    }
    sort(v.begin(), v.end());
    
    queue<pair<int, char>> ready;
    int time = 0;
    int j = 0;

    while (j < n && v[j].first.first <= time)
    {
        ready.push({v[j].first.second, v[j].second});

        j++;
    }
    cout << "----------------Gantt Chart-----------------" << endl;
    cout << "Time  : Character " << endl;
    while (!ready.empty())
    {
        pair<int, char> temp = ready.front();
        ready.pop();
        int execute = min(temp.first, cpu_time);
        temp.first -= execute;

        time += execute;
        cout << time << ' ' << temp.second << endl;
        while (j < n && v[j].first.first <= time)
        {
            ready.push({v[j].first.second, v[j].second});

            j++;
        }

        if (temp.first > 0)
        {
            ready.push(temp);
        }
    }
    cout << "Round Robin"<< " took " << time << " Units time" << endl;
    // cout<<"Times : "<<time<<endl;
    return time;
}