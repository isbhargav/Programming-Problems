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
    int n;
    while (cin >> n)
    {

        vvi mat(n + 1, vi(n + 1, 0));
        vvi sum_mat(n + 1, vi(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> mat[i][j];
                sum_mat[i][j] = mat[i][j];
                if (i > 0)
                    sum_mat[i][j] += sum_mat[i - 1][j];
                if (j > 0)
                    sum_mat[i][j] += sum_mat[i][j - 1];
                if (i > 0 && j > 0)
                    sum_mat[i][j] -= sum_mat[i - 1][j - 1];
            }
        }
        int maxx = 0;
        for (int x1 = 1; x1 <= n; x1++)
        {
            for (int y1 = 1; y1 <= n; y1++)
            {
                for (int x2 = x1; x2 <= n; x2++)
                {
                    for (int y2 = y1; y2 <= n; y2++)
                    {
                        int sum = sum_mat[x2][y2] + sum_mat[x1 - 1][y1 - 1] - sum_mat[x1 - 1][y2] - sum_mat[x2][y1 - 1];

                        maxx = max(sum, maxx);
                    }
                }
            }
        }
        cout << maxx << endl;
    }
    return 0;
}