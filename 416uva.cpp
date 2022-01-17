#include <bits/stdc++.h>
using namespace std;
vector<int> ansl;
int bad[10];
string numbers[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
vector<int> guess_number(string s)
{
    vector<int> poss;
    for (int i = 9; i >= 0; i--)
    {
        bool i_possible = true;
        for (int j = 0; j < 8; j++)
        {
            if (s[j] == 'Y' && numbers[i][j] != s[j])
            {
                i_possible = false;
                break;
            }
        }
        if (i_possible)
        {
            poss.push_back(i);
        }
    }
    return poss;
}
void set_bad_bits(string s, int i)
{
    for (int j = 0; j < 8; j++)
        if (s[j] == 'N' && numbers[i][j] != s[j])
            bad[j] = 1;
}
bool can_it_be(string s, int a)
{
    string w = numbers[a];
    for (int j = 0; j < 8; j++)
    {
        if ((bad[j] == 1 && s[j] == 'Y') || (s[j] == 'Y' && w[j] != s[j]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        ansl.clear();
        string seq[n];
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
        }
        vector<int> a = guess_number(seq[0]);
        bool m = true;
        for (auto x : a)
        {
            if (x < n - 1)
            {
                m = false;
                break;
            }
            memset(bad, 0, sizeof(bad));
            set_bad_bits(seq[0], x);
            // cout << x << endl;
            m = true;
            for (int i = 1; i < n; i++)
            {
                if (--x >= 0 && can_it_be(seq[i], x))
                {
                    string s = numbers[x];
                    for (int j = 0; j < 8; j++)
                        if (s[j] == 'Y' && seq[i][j] == 'N')
                            bad[j] = 1;
                }
                else
                {
                    m = false;
                    break;
                }
            }
            if (m)
                break;
        }
        if (m)
            cout << "MATCH\n";
        else
            cout << "MISMATCH\n";
    }
    return 0;
}