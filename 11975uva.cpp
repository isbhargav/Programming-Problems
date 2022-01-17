#include <bits/stdc++.h>
using namespace std;
int ticket[25][25];
vector<int> v(4, 0);
int ans = 0;
void check1()
{
    if (ticket[0][0] == -1 && ticket[4][0] == -1 && ticket[0][4] == -1 && ticket[4][4] == -1)
        ans += v[0];
}
void check2()
{
    for (int i = 0; i < 5; i++)
    {
        if (ticket[2][i] != -1)
            return;
    }
    ans += v[1];
}
void check3()
{
    for (int i = 0; i < 5; i++)
    {
        if (ticket[i][i] != -1 || ticket[i][4 - i] != -1)
            return;
    }
    ans += v[2];
}
void check4()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (ticket[i][j] != -1)
            {
                return;
            }
        }
    }
    ans += v[3];
}
int main()
{
    int t;
    cin >> t;
    int case_id = 1;
    while (t--)
    {
        cout << "Case " << case_id++ << ":" << endl;
        int n, l;
        cin >> n >> l;

        vector<int> draws(n, 0);
        for (int i = 0; i < n; i++)
            cin >> draws[i];

        for (int i = 0; i < 4; i++)
        {
            cin >> v[i];
        }

        for (int tt = 0; tt < l; tt++)
        {
            ans = 0;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cin >> ticket[i][j];
                }
            }
            int k;
            for (k = 0; k < draws.size(); k++)
            {
                int number = draws[k];
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (ticket[i][j] == number)
                        {
                            ticket[i][j] = -1;
                        }
                    }
                }
                if (k == 34)
                    check1();
                else if (k == 39)
                    check2();
                else if (k == 44)
                    check3();
            }
            k--;
            check4();
            if (k < 34)
            {
                check1();
                check2();
                check3();
            }
            else if (k < 39)
            {
                check2();
                check3();
            }
            else if (k < 44)
            {
                check3();
            }

            cout << ans << endl;
        }
        if (t)
            cout << endl;
    }
    return 0;
}