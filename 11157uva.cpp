#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        int n,d;
        cin>>n>>d;
        vector<int> big;
        vector<int> small;
        big.push_back(0);
        big.push_back(d);

        while(n--)
        {
            char s,_;
            int dist;
            cin>>s>>_>>dist;
            if(s=='B')
                big.push_back(dist);
            else
                small.push_back(dist);
        }
        sort(big.begin(),big.end());
        sort(small.begin(),small.end());
        int ans=0;
        for(int i=0;i<big.size()-1;i++)//N
        {
            int start=big[i];
            int end = big[i+1];

            auto it1 = lower_bound(small.begin(),small.end(),start);//Log N
            auto it2 = it1+1;
            auto it_end = lower_bound(small.begin(),small.end(),end);

            int prev=start;
            for(it1;it1<it_end;it1+=2)
            {
                ans=max(*it1-prev,ans);
                prev=*it1;
            }
            ans=max(end-prev,ans);

            prev=start;
            for(it2;it2<it_end;it2+=2)
            {
                ans=max(*it2-prev,ans);
                prev=*it2;
            }
            ans=max(end-prev,ans);

        }
        cout<<"Case "<<cs<<": "<<ans<<endl;
    }
    return 0;
}
