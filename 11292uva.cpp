#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m && (n && m))
    {
        vector<int> drg(n), knights(m);
        for (int i = 0; i < n; i++)
        {
            cin >> drg[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> knights[i];
        }

        sort(drg.begin(), drg.end());
        sort(knights.begin(), knights.end());

        int i = 0, j = 0;
        int coins = 0;
        while (i < n && j < m)
        {
            // skip all till we find k[i]>=d[i]
            while (j < m && knights[j] < drg[i])
                j++;
            // if we reach the end break
            if (j == m)
                break;
            // Kill!!! add coin
            coins += knights[j];
            j++;
            i++;
        }
        if (j >= m && i < n)
        {
            cout << "Loowater is doomed!" << endl;
        }
        else
            cout << coins << endl;
    }

    return 0;
}
