#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> value(n), weight(n);
    ll total_value_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
        total_value_sum += value[i];
    }
    vector<ll> dp(total_value_sum + 1, 1e18L+5);
    dp[0]=0;
    for (int item = 0; item < n; item++)
    {
        for(ll value_curr=total_value_sum;value_curr>=value[item];value_curr--)
        {
            dp[value_curr]=min(dp[value_curr],weight[item]+dp[value_curr-value[item]]);
        }
    }
    ll ans=INT_MIN;
    for(ll i=0;i<=total_value_sum;i++)
    {
        if(dp[i]<=w)
            ans=max(ans,i);
    }
    cout<<ans;
    return 0;
}