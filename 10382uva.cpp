#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double l,w;
    while( cin>>n>>l>>w){
        vector<pair<double,double> > v;
        for(int i=0;i<n;i++)
        {
            double x,r;
            cin>>x>>r;
            // to get rid of nan
            if(2*r<=w) continue;
            double delta = sqrt(r*r - (w/2.0)*(w/2.0));
            v.push_back({x-delta,x+delta});
        }
        sort(v.begin(),v.end());

        double max_cover = 0.0;
        int i=0;
        int cnt = 0;
        n = v.size();
        double max_till;
        bool gap=false;
        while(i<n && max_cover<l)
        {
            max_till=max_cover;
            while(i<n && max_cover>=v[i].first)
            {
                if(max_till<v[i].second)
                {
                    max_till=v[i].second;
                }
                i++;
            }
            // this will only occure where there is gap
            if(max_till==max_cover)
            {
                //gap
                gap=true;
                break;
            }
            cnt++;
            max_cover=max_till;

        }
        if(gap)
            printf("%d\n",-1);
        else if(max_cover>=l)
            printf("%d\n",cnt);
        else
            printf("%d\n",-1);
    }
    
    return 0;
}
