#include <bits/stdc++.h>
using namespace std;
int dp[100005][3];
int main()
{
    int n;
    cin >> n;
    
    
    for (int i = 1; i <= n; i++)
    {
        vector<int> c(3);

        for (int j = 0; j < 3; j++)
            cin >> c[j];

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j != k) //for currrent k find max of previous
                    dp[i][k] = max(dp[i][k], c[k] + dp[i - 1][j]);
            }
        }
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;

    return 0;
}