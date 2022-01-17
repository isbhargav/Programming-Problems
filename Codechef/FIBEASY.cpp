#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll M = 1000000000000000005;

int dp[121];

void fib()
{
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    // cout << dp[1] << endl;
    // cout << dp[2] << endl;

    for (ll i = 3; i <= 120; i++)
    {
        //dp[i % 3] = (dp[(i - 2) % 3] + dp[(i - 1) % 3]) % 10;
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
        //  sum = (sum + dp[i]) % 10;
        //  cout << dp[i] << endl;
    }
}

int main()
{
    fib();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << dp[1] << endl;
        }

        else
        {

            ll start = 1;
            while (n != 1)
            {
                n = n / 2;
                start += start;
            }

            ll r = start % 60;
            //cout << r << " -r\n";
            cout << dp[r] << endl;
        }
    }
    return 0;
}