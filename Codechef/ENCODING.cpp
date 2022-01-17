#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int num[1 << 17][10][2], dp[1 << 17][10][2]; // dp[index][digit][equal_or_not] - the sum of f(x) up to index, such that the last digit is digit and it is still equal to the initial number iff equal_or_not == 1
int p[1 << 17];
int t;

void add(int &x, int val)
{
    x += val;
    if (x >= mod)
        x -= mod;
}

pair<int, int> f(vector<int> vec) // pair<sum of all f less than x,sum of all f less than or equal to x>
{
    for (int idx = 0; idx <= (vec.size()); idx++)
    {
        for (int digit = 0; digit < 10; digit++)
        {
            for (int equal = 0; equal < 2; equal++)
            {
                dp[idx][digit][equal] = num[idx][digit][equal] = 0;
            }
        }
    }
    num[0][0][1] = 1;
    for (int idx = 0; idx < (vec.size()); idx++)
    {
        for (int digit = 0; digit < 10; digit++)
        {
            for (int equal = 0; equal < 2; equal++)
            {
                int idx_next = idx + 1;
                for (int next_digit = 0; next_digit < 10; next_digit++)
                {
                    // if equal==1 && next_digit>vec[idx] then breakout because equal can only be max vec[idx]
                    if (equal && (next_digit > vec[idx]))
                        break;

                    //if equal ==1 && next_digit==vec[idx]
                    int equal_next = (equal & (next_digit == vec[idx]));

                    add(num[idx_next][next_digit][equal_next], num[idx][digit][equal]);
                    add(dp[idx_next][next_digit][equal_next], dp[idx][digit][equal]);

                    if (next_digit != digit)
                        add(dp[idx_next][next_digit][equal_next], (((num[idx][digit][equal] * p[((vec.size()) - 1 - idx)]) % mod) * next_digit) % mod);
                    // ^^ if the next digit is equal to the current one, we shouldn't change the sum, else we should add 10^idx * next_digit.
                }
            }
        }
    }
    pair<int, int> ans = {0, 0};
    for (int digit = 0; digit < 10; digit++)
    {
        ans = make_pair((ans.first + dp[(vec.size())][digit][0]) % mod, (ans.second + dp[(vec.size())][digit][0] + dp[(vec.size())][digit][1]) % mod);
    }
    return ans;
}
int main()
{
    p[0] = 1;
    for (int i = 1; i <= 100005; i++)
        p[i] = (p[i - 1] * 10) % mod;
    int t;
    cin >> t;
    while (t--)
    {
        int lnum, rnum;
        string l, r;
        vector<int> vecl, vecr;
        cin >> lnum >> l;
        cin >> rnum >> r;
        for (auto it : l)
            vecl.push_back(it - '0');
        for (auto it : r)
            vecr.push_back(it - '0');
        cout << (mod + f(vecr).second - f(vecl).first) % mod << '\n'; // sum of f(x) for x in l..r = (sum of f(x) for x in 1..r) - (sum of f(x) for x in 1..l - 1)
    }

    return 0;
}