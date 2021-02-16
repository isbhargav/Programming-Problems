#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m && (n && m))
    {
        vector<vector<int> > mp(n, vector<int>(m, 0));
        vector<vector<int> > mp_i(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
                mp_i[j][i] = mp[i][j];
            }
        }



        int q;
        cin >> q;
        while (q--)
        {
            int l, p;
            cin >> l >> p;
            int ans = 0;
            // col_min will store the row index such that it is >= l
            vector<int> col_min(m, INT_MAX);
            for (int j = 0; j < m; j++)
            {
                if (lower_bound(mp_i[j].begin(), mp_i[j].end(), l) != mp_i[j].end())
                    col_min[j] = lower_bound(mp_i[j].begin(), mp_i[j].end(), l) - mp_i[j].begin();

            }

            for (int j = 0; j < m; j++)
                for (int k = ans; k < m; k++)
                {
                    //  (left_bottom row)   (top_right col)  (mp[right_bottom])
                    if (col_min[j] + k >= n || j + k >= m || (mp_i[j + k][col_min[j] + k] > p || mp[col_min[j] + k][j + k]> p))
                        break;
                    if (k + 1 > ans)
                        ans = k + 1;
                }
            cout << ans << endl;
        }
        cout << "-\n";
    }
    return 0;
}
// Complexity - O(M*log n + M*N)
