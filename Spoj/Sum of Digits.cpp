#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
int dp[20][100][2];
int target;
string small_ans = "";
int sol(int pos, int sum, bool take_all, string &as, string small)
{
    if (pos < 0)
    {
        if (sum == target)
        {
            if (small_ans == "")
                small_ans = small;
            return 1;
        }
        else
            return 0;
    }
    if (dp[pos][sum][take_all] != -1)
        return dp[pos][sum][take_all];
    int ans = 0;
    if (take_all) //if we can take all digits
    {
        for (int D = 0; D < 10; D++)
            ans += sol(pos - 1, sum + D, take_all, as, small + to_string(D));
    }
    else
    {
        int limit = as[pos] - '0';
        for (int D = 0; D <= limit; D++)
            ans += sol(pos - 1, sum + D, D != limit, as, small + to_string(D));
    }
    dp[pos][sum][take_all] = ans;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b >> target;
    string as = to_string(a - 1);
    string bs = to_string(b);
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());

    memset(dp, -1, sizeof dp);
    int ans1 = sol(as.length() - 1, 0, false, as, "");
    memset(dp, -1, sizeof dp);
    int ans2 = sol(bs.length() - 1, 0, false, bs, "");
    cout << ans2 - ans1 << endl;
    cout<<small_ans;
    return 0;
}