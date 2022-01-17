#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
bitset<101> colored;
int color[101];
vector<int> ansl;
int ans;

void sol(int id, int n)
{
    if (id > n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 1)
                cnt++;
        }
        if (ans <= cnt)
        {
            ans = cnt;
            ansl.clear();
            for (int i = 1; i <= n; i++)
            {
                if (color[i] == 1)
                    ansl.push_back(i);
            }
        }
        return;
    }

    bool can_black = true;
    //check if i can color this as black
    for (int i = 0; i < graph[id].size(); i++)
    {
        int nb = graph[id][i];
        if (color[nb] != -1 && color[nb] == 1)
        {
            can_black = false;
            break;
        }
    }
    //Now we will try coloring it in black and white.
    //if we can color it in black
    if (can_black)
    {
        color[id] = 1;
        sol(id + 1, n);
    }
    color[id] = 0;
    sol(id + 1, n);
    color[id] = -1;
    //colored.reset(id);
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n, k;
        cin >> n >> k;
        graph.clear();
        graph.assign(n + 1, vector<int>());
        ansl.clear();
        ans = 0;
        memset(color, -1, sizeof(color));

        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        sol(1, n);
        cout << ans << endl;
        for (int i = 0; i < ansl.size(); i++)
            cout << ansl[i] << (i == ansl.size() - 1 ? "\n" : " ");
    }

    return 0;
}