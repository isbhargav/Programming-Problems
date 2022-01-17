#include <bits/stdc++.h>
using namespace std;
int hamming_dist(string a, string b)
{
    int ans = 0;
    for (int i = 0; i < a.length(); i++)
    {
        ans += abs(a[i] - b[i]);
    }
    return ans;
}
int main()
{
    int m, q;
    cin >> m >> q;
    string db[m];
    for (int i = 0; i < m; i++)
    {
        cin >> db[i];
    }

    for (int i = 0; i < q; i++)
    {
        int ans = 10000, fs = 0;
        string qs;
        cin >> qs;
        for (int j = 0; j < m; j++)
        {
            if (db[j].length() >= qs.length())
            {

                for (int k = 0; k <= db[j].length() - qs.length(); k++)
                {
                    string s = db[j].substr(k, qs.length());
                    int tmp = hamming_dist(s, qs);
                    if (tmp < ans)
                    {
                        ans = tmp;
                        fs = j + 1;
                    }
                }
            }
        }
        cout << fs << endl;
    }

    return 0;
}