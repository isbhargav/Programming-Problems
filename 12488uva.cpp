#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n, 0);
        vector<int> b(n, 0);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        int start = 0;
        int ans = 0;
        while (start < n)
        {
            int s = start;
            while (a[start] != b[s])
            {
                s++;
                ans++;
            }
            if (start == s)
                start++;
            else
            {
                int tmp = b[s];
                for (int i = s; i > start; i--)
                {
                    b[i] = b[i - 1];
                }
                b[start] = tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}