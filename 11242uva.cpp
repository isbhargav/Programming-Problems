#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;

    while(cin>>n && n)
    {
        cin>>m;
        vector<int> fs(n,0);
        vector<int> rs(m,0);

        for(int i=0;i<n;i++)
            cin>>fs[i];
        for(int i=0;i<m;i++)
            cin>>rs[i];

        vector<double> ds;
        for(auto x : rs)
        {
            for(auto y: fs)
            {
                ds.push_back((double)x/y);
            }
        }
        sort(ds.begin(),ds.end());

        double ans = -DBL_MAX;
        for(int i=1;i<ds.size();i++)
        {
            ans = max(ans,ds[i]/ds[i-1]); 
        }
        printf("%.2f\n", ans);
        



    }
    return 0;
}