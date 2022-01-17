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
#define nl "\n"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (b >= a)
        {
            cout << b << endl;
        }
        else if (c <= d)
            cout << -1 << endl;
        else
        {
            int y = ceil((a - b) / (double)(c - d));
            // cout << y << "Y" << nl;
            long long int ans = b + (y * c);
            cout << ans << endl;
        }
    }
    return 0;
}