#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;

        vector<pair<pair<int,int>,int> > job;
        for (int i = 0; i < N; ++i)
        {
            int t,f;
            cin>>t>>f;
            job.push_back({{t,f},i+1});
        }
        // Because you i and i+1 selection only depends on those 2 only and does not affect the previous N-2 selection
        // so we can sort it!!
        stable_sort(job.begin(),job.end(),
                [](const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2){
                    return p1.first.first*p2.first.second<p2.first.first*p1.first.second;
                });

        cout << job[0].second;
        for (int i = 1; i < N; ++i)
            cout << " " << job[i].second;
        cout << endl;

        if (T)
            cout << endl;
    }
    return 0;
}
