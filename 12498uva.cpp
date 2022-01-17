#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int case_no = 1;
    while (t--)
    {
        cout << "Case " << case_no++ << ": ";
        int R, C;
        cin >> R >> C;
        string grid[R];
        for (int i = 0; i < R; i++)
        {
            cin >> grid[i];
        }
        int ans[C];
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < grid[0].length(); i++)
        {

            for (int j = 0; j < R; j++)
            {
                if (grid[j][i] == '1')
                {
                    string s = grid[j];
                    //shift right
                    string right = s.substr(i + 1);
                    string left = s.substr(0, i);
                    reverse(left.rbegin(), left.rend());

                    int rans = right.find('0') != string::npos ? right.find('0') + 1 : INT_MAX;
                    int lans = left.find('0') != string::npos ? left.find('0') + 1 : INT_MAX;

                    if (rans != INT_MAX || lans != INT_MAX)
                    {
                        ans[i] += min(lans, rans);
                    }
                    else
                    {
                        ans[i] = INT_MAX;
                        break;
                    }
                }
            }
        }
        int fans = ans[0];
        for (int j = 1; j < C; j++)
        {
            fans = min(fans, ans[j]);
        }
        if (fans != INT_MAX)
            cout << fans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}