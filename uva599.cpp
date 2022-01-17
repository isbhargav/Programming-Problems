#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> edge_count(26, 0);
        int v = 0, e = 0, acorns = 0;
        string s, vertices;
        while (cin >> s)
        {
            if (s[0] == '*')
                break;
            edge_count[s[1] - 'A']++;
            edge_count[s[3] - 'A']++;
            e++;
        }
        cin >> vertices;
        for (auto c : vertices)
        {
            if (c != ',')
            {
                if (edge_count[c - 'A'] == 0)
                    acorns++;
                v++;
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n", v - e - acorns, acorns);
    }
    return 0;
}