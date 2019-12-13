#include <bits/stdc++.h>
using namespace std;
int dp[22][201];
int inf = 1e6 + 6;
int solve(int g, int money_left, vector<vector<int>> &models)
{
    if (money_left <= 0)
        return inf;

    if (g == models.size() - 1 && money_left > 0)
    {
        int minn = inf;
        for (int i = 0; i < models[g].size(); i++)
        {
            if (money_left >= models[g][i])
                minn = min(minn, money_left - models[g][i]);
        }
        return dp[g][money_left] = minn;
    }

    if (dp[g][money_left] != -1)
        return dp[g][money_left];
    int minn = inf;
    for (int i = 0; i < models[g].size(); i++)
    {

        minn = min(minn, solve(g + 1, money_left - models[g][i], models));
    }
    return dp[g][money_left] = minn;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        int m, c;
        cin >> m >> c;
        vector<vector<int>> models(c, vector<int>());
        for (int i = 0; i < c; i++)
        {
            int x;
            cin >> x;
            while (x--)
            {
                int w;
                cin >> w;
                models[i].push_back(w);
            }
        }
        int ans = solve(0, m, models);
        if (ans == inf)
            cout << "no solution\n";
        else
            cout << m - ans << endl;
    }

    return 0;
}