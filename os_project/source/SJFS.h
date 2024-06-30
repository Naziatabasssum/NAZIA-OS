#include <bits/stdc++.h>
using namespace std;

int SJFS(int n,vector<pair<int,int>>&anb)
{
    
    vector<pair<pair<int, int>, char>> v(n);

    for (int i = 0; i < n; i++)
    {
       
        v[i].first.second=anb[i].first;
        v[i].first.first=anb[i].second;
        v[i].second = 'A' + i;
    }
    sort(v.begin(), v.end());
     cout << "----------------Gantt Chart-----------------" << endl;
    cout << "Time  : Character " << endl;
    int time=0;
    for(int i=0;i<n;i++){
        time=max(v[i].first.second,time);
        time+=v[i].first.first;
        cout<<time<<' '<<v[i].second<<endl;
    }
    
    // cout<<"Times : "<<time<<endl;
    cout << "SJFS"<< " took " << time << " Units time" << endl;

    return time;
}