#include <bits/stdc++.h>
using namespace std;
string s;
void sol(int id, int n)
{
    if (id == n - 1)
    {
        if (s[id] == '1')
            cout << "WIN\n";
        else
            cout << "LOSE\n";
        return;
    }

    if (s[id] == '1')
    {
        int cnt = 1;
        while (id + 1 < n && s[id + 1] == '1')
        {
            id++;
            cnt++;
        }

        if (cnt & 1)
        {
            if (id == n - 1)
                sol(n - 1, n);
            else
            {
                s[id + 1] = s[id + 1] == '1' ? '0' : '1';
                sol(id + 1, n);
            }`
        }
        else
        {
            s[id] = s[id] == '1' ? '0' : '1';
            sol(id, n);
        }
        }
    else
        sol(id + 1, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        sol(0, s.length());
    }
    return 0;
}