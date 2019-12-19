#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end(), [](pair<int, int> &aa, pair<int, int> &bb) {
            return aa.first + max(aa.second, bb.first) + bb.second < bb.first + max(bb.second, aa.first) + aa.second;
        });
        int ans = 0;
        int start_time = 0;
        for (int i = 0; i < n; i++)
        {
            start_time += a[i].first;
            ans = max(start_time, ans); //this step is
            ans += a[i].second;
        }
        cout << ans << endl;
    }
    return 0;
}