#include<bits/stdc++.h>
using namespace std;

int bill_to_unit(int a)
{
    int ans=0;
    // first 100
    int c = min(a,100*2);
    ans+=c/2;
    a-=c;

    // next 9900
    c = min(a,9900*3);
    ans+=c/3;
    a-=c;

    // next 1000000
    c=min(a,990000*5);
    ans+=c/5;
    a-=c;
    // for the rest
    ans+=(a/7);

    return ans;
}
int unit_to_bill(int u)
{
    int ans=0;
    int c = min(u,100);
    ans+=c*2;
    u-=c;

    c = min(u,9900);
    ans+=c*3;
    u-=c;

    c = min(u,990000);
    ans+=c*5;
    u-=c;

    ans+=u*7;
    return ans;

}

int main()
{
    int a,b;
    while(cin>>a>>b,(a|b))
    {
        int total = bill_to_unit(a);
        int lo=0,hi=total;
        int ans = 0;
        while(lo<hi)
        {
            ans = (lo+hi)/2;
            int diff = unit_to_bill(total-ans)-unit_to_bill(ans);
            if(diff>b)
                lo=ans;
            else if(diff<b)
                hi=ans;
            else
                break;
        }
        cout<<unit_to_bill(ans)<<"\n";

    }
    return 0;
}


/*
 *
 *              Target              Mid
 *________________|__________________|_______________________________
 *                                   <----------   diff  ----------->
 *                <-----------------  b ---------------------------->
 *
 *                So from above pic we can clearly see:
 *                      if diff < b -> hi=mid
 *
 *
 *
 */
