#include <bits/stdc++.h>
using namespace std;

int priority_scheduling_non_pre(int n,vector<pair<int,int>>&anb,vector<int>pri)
{
    
    vector<pair<pair<pair<int, int>, char>, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        // cin >> v[i].first.first.first >> v[i].first.first.second >> v[i].second;
        v[i].first.first.first=anb[i].first;
        v[i].first.first.second=anb[i].second;
        v[i].second=pri[i];

        v[i].first.second = 'A' + i;
    }
    sort(v.begin(), v.end());

    priority_queue<pair<int, pair<int, char>>> pq;

    int time = 0;
    cout << "----------------Gantt Chart-----------------" << endl;
    cout << "Time  : Character " << endl;
    for (int i = 0; i < n;)
    {
        time = max(time, v[i].first.first.first);
        pq.push({v[i].second, {v[i].first.first.second, v[i].first.second}});
        i++;
        while (i < n && v[i].first.first.first <= time)
        {
            pq.push({v[i].second, {v[i].first.first.second, v[i].first.second}});
            i++;
        }

        while (!pq.empty())
        {
            pair<int, pair<int, char>> temp = pq.top();
            pq.pop();
            time += temp.second.first;
            cout << time << ' ' << temp.second.second << endl;
            while (i < n && v[i].first.first.first <= time)
            {
                pq.push({v[i].second, {v[i].first.first.second, v[i].first.second}});
                i++;
            }
        }
    }
    cout << "Priority scheduling(Non-preemptive)"<< " took " << time << " Units time" << endl;
    return time;
}