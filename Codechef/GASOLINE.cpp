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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ii> in(n);
        for (int i = 0; i < n; i++)
            cin >> in[i].second;
        for (int i = 0; i < n; i++)
            cin >> in[i].first;

        int need = n;
        long long total = 0LL;
        sort(all(in));
        for (auto p : in)
        {
            int c = min(need, p.second);
            total += (long long)c * p.first;
            need -= c;
        }
        cout << total << endl;
    }
    return 0;
}
