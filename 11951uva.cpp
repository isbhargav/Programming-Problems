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
  int c = 0;
  while (t--)
  {
    int n, m, k;
    cin >> n >> m >> k;
    vvi prices(n, vi(m, 0));
    vvi sum_prices(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> prices[i][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        sum_prices[i][j] = prices[i][j];
        if (i > 0)
          sum_prices[i][j] += sum_prices[i - 1][j];
        if (j > 0)
          sum_prices[i][j] += sum_prices[i][j - 1];
        if (i > 0 && j > 0)
          sum_prices[i][j] -= sum_prices[i - 1][j - 1];
      }
    }
    long long int S = 0, P = INT_MAX;

    for (int x1 = 0; x1 < n; x1++)
    {
      for (int y1 = 0; y1 < m; y1++)
      {
        for (int x2 = x1; x2 < n; x2++)
        {
          for (int y2 = y1; y2 < m; y2++)
          {
            long long int subrect = sum_prices[x2][y2];
            if (x1 > 0)
              subrect -= sum_prices[x1 - 1][y2];
            if (y1 > 0)
              subrect -= sum_prices[x2][y1 - 1];
            if (x1 > 0 && y1 > 0)
              subrect += sum_prices[x1 - 1][y1 - 1];

            int tmp_S = (x2 - x1 + 1) * (y2 - y1 + 1);
            long long int tmp_P = subrect;

            if (tmp_S > S && tmp_P <= k)
            {
              P = tmp_P;
              S = tmp_S;
            }

            //if same plot area select the cheaper
            if (tmp_S == S)
            {
              P = min(tmp_P, P);
            }
          }
        }
      }
    }
    if (S == 0)
      cout << "Case #" << ++c << ": " << S << " " << S << endl;

    else
      cout << "Case #" << ++c << ": " << S << " " << P << endl;
  }
  return 0;
}
/*
10  1 10 20 10 10
30  1  1  5  1  1
50  1  1 20  1  1
10  5  5 10  5  1
40 10 90  1 10 10
*/