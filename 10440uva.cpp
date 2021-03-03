#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cs;
    cin>>cs;
    while(cs--)
    {

        int n,m,t;
        cin>>n>>t>>m;
        vector<int> v(m);

        for(int &x: v) cin>>x;
        sort(v.begin(),v.end());

        int pos,ans;
        ans=pos=0; 
        int cnt=0;

        if((n+m)%n == 0)
        {
            ans = v[n-1]+2*t;
            pos = n;
        }
        else {
            ans = v[(m+n)%n -1]+2*t;
            pos = (m+n)%n;
        }
        cnt++;
        while(pos<m)
        {
            ans = max(ans,v[pos+n-1])+2*t;
            pos+=n;
            cnt++;
        }
        ans-=t;
        /* cout<<cnt<<endl; */
        /* printf("%d %d\n",ans,(m+n-1)/n); */
        printf("%d %d\n",ans,cnt);
    }
    return 0;
}
