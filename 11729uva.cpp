#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int cs=1;
    while(cin>>n,n!=0)
    {
        vector<pair<int,int> > v(n);
        for(auto &p: v)
        {
            cin>>p.second; // breifing
            cin>>p.first; // Jobs
        }


        //The key thing here is no matter in what order we breif it will add up to same
        //But the order in which we execute jobs does matter as 2 soldiers can work togather.
        //Hence, we start with longest time soldier so that others can start working parallely

        //{task_time,breif_time}
        sort(v.rbegin(),v.rend());
        int breif_start =0;
        int latest_running_task=0;
        for(auto &p: v)
        {
            breif_start+=p.second;
            latest_running_task=max(latest_running_task,breif_start+p.first);
            
        }
        printf("Case %d: %d\n",cs++,latest_running_task);


    }
    return 0;
}
