#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF)
    {

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (mp.find(x) != mp.end())
                mp[x].push_back(i + 1);
            else
                mp[x] = vector<int>(1, i + 1);
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (mp.find(b) == mp.end() || mp[b].size() < a)
                cout << 0 << endl;
            else
                cout << mp[b][a - 1] << endl;
        }
    }
    return 0;
}