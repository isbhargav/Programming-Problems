#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x,y,d;
    int cas=0;
    while(scanf("%d %lf",&n,&d),n)
    {
        bool flag =false;
        vector<pair<double,double> > points;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            //When its not reachable
            if(y>d)
                flag=true;

            double a = x - sqrt(d*d - y*y);
            double b = x + sqrt(d*d - y*y);
            points.push_back({a,b});
        }


        sort(points.begin(),points.end());

        for(const auto& [a,b]: points)
            cout<<a<<" "<<b<<"\n";

        double  max_cover = -1e9;
        int cnt=0;
        int i=0;
        while(i<n && !flag)
        {

            while(i<n && points[i].first <= max_cover)
            {
                // why???->  this is becuase large interval can cover smaller interval
                max_cover = min(max_cover,points[i].second);
                i++;
            }
            ++cnt;
            if(i<n)
                max_cover = points[i].second;
        }
         printf("Case %d: %d\n", ++cas, flag ? -1 : cnt-1);
    }   
    return 0;
}

/*
 * Intercval covering problem
 * - sort based on x,y
 *  - select the first pos
 *  - if covers
 */
