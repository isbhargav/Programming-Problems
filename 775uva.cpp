#include <bits/stdc++.h>
using namespace std;
int n;
char line[100];
int visited[300];
set<int> seen;
vector<int> order;
vector<vector<int>> adj(300, vector<int>());

bool dfs(int id)
{
    visited[id] = 1;
    seen.insert(id);
    for (auto x : adj[id])
    {
        if (seen.size() == n && x == 0)
        {
            order.push_back(id);
            return true;
        }

        if (visited[x] != 1 && dfs(x))
        {
            order.push_back(id);
            return true;
        }
    }
    visited[id] = 0;
    seen.erase(id);
    return false;
}
int main()
{

    while (scanf("%d\n", &n) != EOF)
    {
        adj.clear();
        seen.clear();
        order.clear();
        adj.assign(300, vector<int>());
        memset(visited, 0, sizeof(visited));
        int x, y;
        while (scanf("%d %d", &x, &y) == 2)
        {

            adj[x - 1].push_back(y - 1);
            adj[y - 1].push_back(x - 1);
        }
        getchar();
        if (dfs(0))
        {

            for (auto x = order.rbegin(); x != order.rend(); x++)
                printf("%d ", *x + 1);
            printf("1\n");
        }
        else
            printf("N\n");
    }
    return 0;
}