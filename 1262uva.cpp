#include <bits/stdc++.h>
using namespace std;
string ans_l[5];
string ans;
int cnt;
int k;
void sol(int id, string s)
{
    if (id >= 5)
    {
        cnt++;
        if (cnt == k)
            ans = s;
        return;
    }
    for (int i = 0; i < ans_l[id].length(); i++)
    {
        if (i > 0 && ans_l[id][i - 1] == ans_l[id][i])
            continue;  
        sol(id + 1, s + ans_l[id][i]);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> k;
        cnt = 0;
        string a[6], b[6];
        for (int i = 0; i < 6; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 6; i++)
        {
            cin >> b[i];
        }

        string tmp_a[5], tmp_b[5];
        for (int j = 0; j < 5; j++)
        {
            tmp_a[j] = "";
            tmp_b[j] = "";
            ans_l[j].clear();
            for (int i = 0; i < 6; i++)
            {
                tmp_a[j] += a[i][j];
                tmp_b[j] += b[i][j];
            }
            sort(tmp_a[j].begin(), tmp_a[j].end());
            sort(tmp_b[j].begin(), tmp_b[j].end());
            set_intersection(tmp_a[j].begin(), tmp_a[j].end(), tmp_b[j].begin(), tmp_b[j].end(), back_inserter(ans_l[j]));
            //ans_l[j] = unique(ans_l[j].begin(), ans_l[j].end());
        }
        sol(0, "");
        if (cnt < k)
            cout << "NO\n";
        else
            cout << ans << endl;
    }
    return 0;
}