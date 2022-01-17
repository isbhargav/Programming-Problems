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

int main(int ac, char **av)
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int min_l = 0;
        unordered_map<int, int> dc;
        for (int i = 1; i < 4; i++)
        {
            dc[i] = -1;
        }

        for (int i = 0; i < s.length(); i++)
        {
            int x = s[i] - '0';
            dc[x] = i;
            if (dc[1] != -1 && dc[2] != -1 && dc[3] != -1)
            {
                int n_min = max({dc[1], dc[2], dc[3]}) - min({dc[1], dc[2], dc[3]}) + 1;
                if (n_min == 3)
                {
                    min_l = 3;
                    break;
                }
                else
                {
                    if (min_l == 0)
                        min_l = n_min;
                    else
                        min_l = min(min_l, n_min);
                }
            }
        }
        cout << min_l << endl;
    }
    return 0;
}