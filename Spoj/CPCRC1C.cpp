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
1
int dp[100][10][2]; //dp[pos][edge]
int hit = 0;

int sol(int pos, bool take_all, string as)
{
    if (pos == 0)
    {
        
    }

    int ans = 0;
   
    if (take_all) //if we can take all digits
    {
        for (int D = 0; D < 10; D++)
            ans += sol(pos - 1, take_all, as);
    }
    else
    {
        int limit = as[pos] - '0';
        for (int D = 0; D <= limit; D++)
            ans += sol(pos - 1, D != limit, as);
    }
    // dp[pos][take_all][sum] = ans;
    // return ans;
}
int main()
{

    int a, b;
    string as, bs;
    while (cin >> b >> a)
    {
        if (a == -1 && b == -1)
            break;

        memset(dp, -1, sizeof dp);
        as = to_string(a);
        bs = to_string(b - 1);
        hit = 0;

        reverse(as.begin(), as.end());
        int ans1 = sol(as.length() - 1, false, 0, as);
        memset(dp, -1, sizeof dp);
        reverse(bs.begin(), bs.end());
        int ans2 = sol(as.length() - 1, false, 0, bs);
        cout << ans1 - ans2 << endl;
    }
    return 0;
}