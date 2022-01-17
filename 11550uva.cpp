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

// Two cases to satisify
// 1. Sum in column can be 2 or 0
// 2. No two different edges can join same two edge.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        bool flag = true;

        set<string> ss;
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            string s = "";
            for (int j = 0; j < n; j++)
            {
                sum += mat[j][i];
                if (mat[j][i] != 0)
                {
                    s += ('0' + j);
                }
            }
            //cout << s << endl;
            if (sum != 2 || s.length() != 2 || ss.find(s) != ss.end())
            {
                flag = false;
                break;
            }

            ss.insert(s);
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}