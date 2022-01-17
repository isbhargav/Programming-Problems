#include <bits/stdc++.h>
using namespace std;
int n, k;
int last_num;

int ans = 0;
int cnt = 0;
void sol(int id, int sum, int taken, vector<int> &v)
{
    if (taken == k)
    {
        if (sum < ans)
        {
            ans = sum;
            cnt = 1;
            last_num = v[id];
        }
        else if (sum == ans)
        {
            cnt++;
        }
        return;
    }

    if (id >= n || v[id] > last_num)
        return;

    sol(id + 1, sum + v[id], taken + 1, v);

    // if next number is same
    // while (id < n - 1 && v[id + 1] == v[id])
    //     id++;

    sol(id + 1, sum, taken, v);
}
using namespace std;
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        last_num = INT_MAX;
        ans = INT_MAX;
        cnt = 0;
        cin >> n >> k;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        if (k == n)
        {
            cout << 1 << endl;
            continue;
        }

        sol(0, 0, 0, v);
        cout << cnt << endl;
    }
    return 0;
}