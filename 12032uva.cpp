#include <bits/stdc++.h>
using namespace std;

vector<int> r;
bool can(int k)
{
    int prev = 0;
    for(int i=0;i<r.size();i++)
    {
        if(r[i]-prev > k )
            return false;
        if(r[i]-prev == k)
            k--;
        prev=r[i];
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    int cs=1;
    while(t--)
    {
        int n;
        cin>>n;
        r.assign(n,0); 
        for(int i=0;i<n;i++)
        {
            cin>>r[i];
        }
        int lo=1,hi=10000000,mid;
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            if(can(mid))
                hi=mid-1;
            else
                lo=mid+1;

        }
        printf("Case %d: %d\n",cs++,lo);
    }
    return 0;
}
