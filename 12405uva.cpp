#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int i = 0;
        int cnt = 0;
        while (i < n)
        {
            if (s[i] == '.')
            {
                cnt++;
                i += 3;
            }

            while (i < n && s[i] == '#')
                i++;
        }
        cout << "Case " << c << ": " << cnt << endl;
    }
    return 0;
}