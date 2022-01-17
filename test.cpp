#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, m, q;
vi g[1001];
int c[1001];
int s[10];
set<int> r[10][1001];

void dfs(int i, int z, int p)
{
    r[i][z] = r[i][p];
    for (int x : r[i][p])
        if (x + c[z] < 1001)
            r[i][z].insert(x + c[z]);

    for (int y : g[z])
        if (y != p)
            dfs(i, y, z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (int i = 1; i <= n - 1; ++i)
    {
        int x;
        cin >> x;
        g[i + 1].push_back(x);
        g[x].push_back(i + 1);
    }

    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    for (int i = 0; i < m; ++i)
        cin >> s[i];

    for (int i = 0; i < m; ++i)
    {
        r[i][0].insert(0);
        dfs(i, s[i], 0);
    }

    while (q--)
    {
        int b, e, w;
        cin >> b >> e >> w;

        int pv = 0;
        for (int i = 0; i < m; ++i)
        {
            auto bi = --upper_bound(r[i][b].begin(), r[i][b].end(), w);
            auto ei = --upper_bound(r[i][e].begin(), r[i][e].end(), w);

            while (bi != r[i][b].begin() && ei != r[i][e].begin())
            {
                if (*bi > *ei)
                    --bi;
                else if (*bi < *ei)
                    --ei;
                else
                {
                    pv = max(pv, *bi * 2);
                    break;
                }
            }
        }

        cout << pv << '\n';
    }
}