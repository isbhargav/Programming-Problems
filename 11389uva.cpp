#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,r;
    while(cin>>n>>d>>r,!(n==0 && d==0 && r==0))
    {
        vector<int> days(n);
        vector<int> nights(n);
        for(int &x: days)
            cin>>x;
        for(int &x: nights)
            cin>>x;
        sort(days.begin(),days.end());
        sort(nights.rbegin(),nights.rend());
        int ans=0;
        for(int i=0;i<n;i++)
        {
           int sum = days[i]+nights[i];
           ans+=(sum>d?sum-d:0)*r;

        }
    
        printf("%d\n",ans);

    }
    return 0;
}
