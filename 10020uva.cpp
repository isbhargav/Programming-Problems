#include<bits/stdc++.h>
using namespace  std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<pair<int,int> > v;
        int x,y;
        while(scanf("%d %d",&x,&y),!(x==0 && y==0))
            v.push_back({x,y});

        sort(v.begin(),v.end());
        
        int max_cover =0; // right most span of current interval
        int cnt=0; // intervals selected
        int n =v.size(); // total
        int i=0; // start with 0
        int max_till; // this is to find longest cover
        vector<pair<int,int> > ans;
        bool done=false;

        while(i<n)
        {
            max_till = max_cover;
            pair<int,int> a={0,0};
            // all intervals who's start is before our current span
            while(i<n && max_cover>=v[i].first)
            {
                // this so we select next interval who's right span is most out of all
                if(v[i].second>max_till)
                {
                    a = {v[i].first,v[i].second};
                }
                // this can be move in above if
                max_till =max(v[i].second,max_till);
                i++;
            }
            ans.push_back(a);
            cnt++;
            if(max_cover==max_till)
            {
                break;
            }
            max_cover=max_till;
            if(max_cover>=m)
            {

                printf("%d\n",cnt);
                for(const auto& [f,s]: ans)
                    printf("%d %d\n",f,s);
                done=true;
                break;
            }

        }

        if(done==false)
                printf("%d\n",0);
        if(t)
            printf("\n");
    }
    return 0;
}
