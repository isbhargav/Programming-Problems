#include <bits/stdc++.h>
using namespace std;
pair<int, int> prev_dom;
pair<int, int> ends_dom[2];
int can_take(pair<int, int> &d)
{
    if (prev_dom.second == d.first || prev_dom.second == d.second)
        return 1;
    return 0;
}
int sol(int id, int n, int taken, vector<pair<int, int>> &domino)
{
    if (id > n)
    {
        //return can_take(ends_dom[1]);

        return prev_dom.second == ends_dom[1].first;
    }

    for (int i = 0; i < domino.size(); i++)
    {
        if ((!((1 << i) & taken)) && can_take(domino[i])) //if not taken try
        {
            pair<int, int> remb_prev = prev_dom;
            if (prev_dom.second == domino[i].first)
            {
                prev_dom = domino[i];
            }
            else
            {
                prev_dom = {domino[i].second, domino[i].first};
            }

            if (sol(id + 1, n, taken | (1 << i), domino))
            {
                //  cout << "ok " << prev_dom.first << " " << prev_dom.second << endl;
                return 1;
            }
            prev_dom = remb_prev;
        }
    }
    return 0;
}
int main()
{
    int n, m;

    while (cin >> n && n)
    {
        cin >> m;

        vector<pair<int, int>> domino(m);
        cin >> ends_dom[0].first >> ends_dom[0].second;
        cin >> ends_dom[1].first >> ends_dom[1].second;

        for (auto &x : domino)
            cin >> x.first >> x.second;
        prev_dom = ends_dom[0];
        if (sol(1, n, 0, domino))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
