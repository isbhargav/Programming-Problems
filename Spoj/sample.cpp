#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[20][2]; // index, tight

// function calculate the decimal value of
// number from index idx to last -1
lli func(int idx, int last, string s)
{
    lli num = 0;
    for (int i = idx; i < last; i++)
    {
        num = num * 10 + s[i] - '0';
    }
    return num;
}

lli solve(int idx, bool tight, string s, int n)
{

    if (idx >= n)
        return 0;
    else if (dp[idx][tight] != -1)
        return dp[idx][tight];
    else if (tight == 1)
    {

        lli ret = 0;
        for (int i = 0; i <= s[idx] - '0'; i++)
        {
            if (i == s[idx] - '0')
                ret += solve(idx + 1, 1, s, n) + i * (func(idx + 1, s.length(), s) + 1);
            else
                ret += solve(idx + 1, 0, s, n) + i * pow(10, n - idx - 1);
        }
        dp[idx][tight] = ret;
        return ret;
    }
    else
    {
        lli ret = 0;
        for (int i = 0; i <= 9; i++)
        {
            ret += solve(idx + 1, 0, s, n) + i * pow(10, n - idx - 1);
        }
        dp[idx][tight] = ret;
        return ret;
    }
}
int main()
{

    while (1)
    {
        
        string a, b;
        cin >> a >> b;
        lli as = 0;

        //sum of all digits of a
        for (int i = 0; i < a.length(); i++)
            as += a[i] - '0';
        // cout<<as<<endl;

        if (a == "-1" && b == "-1")
            break;
        else
        {
            memset(dp, -1, sizeof dp);
            lli ans1 = solve(0, 1, b, b.length());
            memset(dp, -1, sizeof dp);
            lli ans2 = solve(0, 1, a, a.length());

            lli ans = ans1 - ans2 + as;
            cout << ans << endl;
        }
    }
}