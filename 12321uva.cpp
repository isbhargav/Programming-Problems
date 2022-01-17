#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,g;
    while(cin>>l>>g,!(l==0 && g==0))
    {
        vector<pair<int,int> > pts;
        for(int i=0;i<g;i++)
        {
            int x,y;
            cin>>x>>y;
            pts.push_back({x-y,x+y});
        }

        sort(pts.begin(),pts.end());

        int i=0;
        int n=g;
        int cnt=0;
        int max_cover=0;
        int max_till;
        bool gap=false;
        while(i<n && max_cover<l)
        {
            max_till=max_cover;
            while(i<n && pts[i].first<=max_cover)
            {
                max_till=max(max_till,pts[i].second);
                i++;
            }

            if(max_cover==max_till)
            {
                //gap
                gap=true;
                break;
            }
            cnt++;
            max_cover=max_till;
            
        }
        if(gap || max_cover<l)
            printf("%d",-1);
        else
            printf("%d",g-cnt);
        printf("\n");
    }
    return 0;
}
