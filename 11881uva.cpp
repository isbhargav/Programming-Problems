#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    vector<double> cf(10,0.0);
    while(scanf("%d",&t),(t!=0))
    {
        t++;
        for(int i=0;i<t;i++)
            scanf("%lf",&cf[i]);

        double lo=-1,hi=10000,mid;
        for(int x=0;x<100;x++)//precision upto 2 decimal
        {
            mid=(lo+hi)/2;
            double npv=0;
            for(int i=0;i<t;i++)
                npv+=(cf[i]/pow(1+mid,i));
            if(npv>0)//we can increace lo so we get high denomeater
                lo=mid;
            else
                hi=mid;
        }
        mid=(lo+hi)/2;
        printf("%.2lf\n", mid);

    }
    return 0;

}
