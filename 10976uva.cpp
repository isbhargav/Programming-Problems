#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while (cin >> t)
    {
        vector<pair<int, int>> ans;
        for (int i = t + 1; i <= 2 * t; i++)
        {
            if (!((t * i) % (i - t)))
            {
                ans.push_back({i, (t * i) / (i - t)});
            }
        }
        cout << ans.size() << endl;
        for (auto p : ans)
        {
            printf("1/%d = 1/%d + 1/%d\n", t, p.second, p.first);
        }
    }
    return 0;
}