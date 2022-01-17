#include <bits/stdc++.h>
using namespace std;
long long int dp[101][100005];
int main()
{
    int n, w;
    cin >> n >> w;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= w; j++)
        {
            if (i == 0)
            {
                if (weight[i] <= j)
                    dp[i][j] = value[i];
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (j - weight[i] >= 0)
                dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], max(dp[i - 1][j], dp[i][j - 1]));
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    cout << dp[n - 1][w] << endl;
    return 0;
}

//Errichto

int main()
{
    int n, W;
    cin >> n >> W;
    long long int ks_dp[W];
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;

        for (int weight_ks = 0; weight_ks <= W - weight; weight_ks++)
            ks_dp[weight_ks + weight] = max(ks_dp[weight_ks + weight], ks_dp[weight_ks] + value);
    }
    return 0;
}