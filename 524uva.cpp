#include <bits/stdc++.h>
using namespace std;
int neckless[16];
int n;
bool isprime(int n)
{
    if ((n & 1) == 0)
        return false;

    for (int i = 3; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
void solve(int id)
{
    if (id == 0)
    {
        neckless[id] = 1;
        solve(id + 1);

        return;
    }
    if (id == n - 1)
    {

        for (int i = 2; i <= n; i++)
        {
            bool flg = true;
            for (int j = 0; j < id; j++)
            {
                if (neckless[j] == i)
                {
                    flg = false;
                    break;
                }
            }

            if (isprime(neckless[id - 1] + i) && isprime(i + neckless[0]) && flg)
            {
                neckless[id] = i;
                for (int k = 0; k < n; k++)
                {
                    cout << neckless[k] << (k == n - 1 ? "\n" : " ");
                }
            }
        }
        return;
    }

    for (int i = 2; i <= n; i++)
    {
        bool flg = true;
        for (int j = 0; j < id; j++)
        {
            if (neckless[j] == i)
            {
                flg = false;
                break;
            }
        }

        if (isprime(neckless[id - 1] + i) && flg)
        {
            neckless[id] = i;
            solve(id + 1);
        }
    }
}
int main()
{
    int case_id = 1;

    while (cin >> n)
    {
        if (case_id > 1)
            cout << endl;
        cout << "Case " << case_id++ << ":\n";
        solve(0);
    }
    return 0;
}