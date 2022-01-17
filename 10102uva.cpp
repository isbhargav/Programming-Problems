#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int N;

int start, end;

int main()
{

    while (cin >> N)
    {
        int ans = INT_MIN;
        vector<pair<int, int>> ones, threes;
        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = s[j] - '0';
                if (arr[i][j] == 1)
                {
                    ones.push_back({i, j});
                }
                else if (arr[i][j] == 3)
                {
                    threes.push_back({i, j});
                }
            }
        }
        for (auto x : ones)
        {
            int tmp = INT_MAX;
            for (auto y : threes)
            {
                tmp = min(tmp, (abs(x.first - y.first) + abs(x.second - y.second)));
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }

    return 0;
}