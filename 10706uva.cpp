#include <bits/stdc++.h>
#include <string>
using namespace std;
vector<long long> dp(31268+1,0);  // dp[i] stores length of string at index i(cumulative sum dp[3]=6->"112123"")
vector<long long> cnt(31268+1,0); // cnt[i] stores the length of i(cnt[3]=3->"123")
long long k=1l,f=0l;
int main()
{
    for(int i=1;i<=31268;i++)
    {
        if(i==k) k*=10,++f;
        cnt[i] = cnt[i-1]+f;
        dp[i]=dp[i-1]+cnt[i];
        

    }
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        if(q==1)
        {
            printf("1\n");
                continue;
        }
        int l=1,h=31268;
        bool done=false;
        while(h-l > 1)
        {
            int mid = l+(h-l)/2;
            int nums = dp[mid];
            if(q>nums)
                l=mid;
            else if(q<nums)
                h=mid;
            else
            {
                printf("%d\n",mid%10);
                done=true;
                break;
            }

        }
        if(done)
            continue;
        long long s = dp[l];
        string st = "";
        for(int i=1;i<=l+1;i++)
        {
            st+=to_string(i);
            if(s+cnt[i] >= q)
                {
                    printf("%c\n",st[q-s-1]);
                    break;
                }
        }

    }
    return 0;

}
/*
1
12
123
1234
12345
123456
1234567
12345678
123456789
12345678910
1234567891011
123456789101112
*/

