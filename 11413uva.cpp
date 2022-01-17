#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int m,n;
bool can(int cap)
{
    int cnt = 1;
    int rem = cap;
    for(int c: v)
    {
        if(rem < c)
            cnt++,rem=cap;
        rem-=c;
    }
    if(cnt>m)
    return false;
        return true;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        v.assign(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int lo=*max_element(v.begin(),v.end());
        int hi=accumulate(v.begin(),v.end(),0);
        int ans;
        while(hi>=lo)
        {
            int mid=hi+lo;
            mid/=2;
            if(can(mid)) // so we can lower the upperbound
                hi=mid-1,ans=mid;
            else        // we cannot so we increase the lowerbound
                lo=mid+1;
        }
        cout<<lo<<endl;
    
    }
    return 0;
}
