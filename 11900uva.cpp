#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        int n,p,q;
        cin>>n>>p>>q;
        vector<int> v(n);
        for(int &a: v)
            cin>>a;
        sort(v.begin(),v.end());
        int tot=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            tot+=v[i];
            if(tot>q || cnt>=p)
                break;
            cnt++;

        }
        printf("Case %d: %d\n",cs,cnt);
    }
    return 0;
}
