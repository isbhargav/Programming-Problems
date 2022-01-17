#include <bits/stdc++.h>
using namespace std;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cnt;

bool is_hard(string s)
{
    for (int i = 1; i <= s.length() / 2; i++)
    {
        bool isvalid = false;
        for (int j = 0; j < i; j++)
        {
            if (s[s.length() - 1 - j] != s[s.length() - 1 - j - i])
            {
                isvalid = true;
                break;
            }
        }
        if (isvalid == false)
            return false;
    }
    return true;
}
bool sol(int n, int l, string s)
{
    if (!is_hard(s))
        return false;

    if (++cnt == n)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i && i % 4 == 0)
            {
                if (i % 64 == 0)
                    cout << endl;
                else
                    cout << " ";
            }

            cout << s[i];
        }
        cout << "\n"
             << s.length() << "\n";
        return true;
    }

    for (int i = 0; i < l; i++)
    {
        if (sol(n, l, s + letters[i]))
            return true;
    }
    return false;
}
int main()
{
    int n, l;
    while (cin >> n >> l && (n && l))
    {
        cnt = -1;
        sol(n, l, "");
    }
    return 0;
}
