#include <bits/stdc++.h>
using namespace std;
int t, n;
int nums[20];
map<vector<int>, bool> sols;
bool flg;
void dfs(int id, int sum, vector<int> prev_id)
{
    if (sum == t)
    {
        flg = true;
        if (sols.find(prev_id) != sols.end())
            return;
        sols.insert({prev_id, true});
        for (int i = 0; i < prev_id.size(); i++)
        {
            cout << prev_id[i] << (i == prev_id.size() - 1 ? "\n" : "+");
        }
        return;
    }
    if (sum > t || id >= n)
        return;

    prev_id.push_back(nums[id]);
    dfs(id + 1, sum + nums[id], prev_id);
    prev_id.pop_back();
    dfs(id + 1, sum, prev_id);
}
int main()
{

    while (cin >> t >> n && (t || n))
    {
        flg = false;
        sols.clear();
        cout << "Sums of " << t << ":\n";
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<int> dm;
        dfs(0, 0, dm);
        if (!flg)
            cout << "NONE\n";
    }
    return 0;
}