#include <bits/stdc++.h>
using namespace std;
int n, t;
int cds[30];
int ans;
vector<int> items;
void solve(int id, int sum, vector<int> a)
{
    if (id < t && sum <= n)
    {

        //without taking this item
        solve(id + 1, sum, a);
        //take this item
        a.push_back(cds[id]);
        solve(id + 1, sum + cds[id], a);
    }
    else if (sum <= n)
    {
        if (ans <= sum)
        {
            ans = sum;
            items = a;
        }
    }
}
int main()
{

    while (cin >> n >> t)
    {
        for (int i = 0; i < t; i++)
            cin >> cds[i];
        ans = 0;
        items.clear();
        solve(0, 0, items);
        for (int s : items)
            cout << s << " ";
        cout << "sum:" << ans << endl;
    }
    return 0;
}