#include <bits/stdc++.h>

using namespace std;

struct ds
{
    int L, H;
    string M;
    ds()
    {
    }
    ds(int _L, int _H, string _M)
    {
        L = _L;
        H = _H;
        M = _M;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        vector<ds> db;
        while (d--)
        {
            int L, H;
            string M;
            cin >> M >> L >> H;
            db.push_back(ds(L, H, M));
        }

        int q;
        cin >> q;
        while (q--)
        {
            int p;
            cin >> p;
            ds ans;
            int cnt = 0;
            for (int i = 0; i < db.size(); i++)
            {
                if (db[i].L <= p && db[i].H >= p)
                {
                    if (cnt == 0)
                    {
                        ans = db[i];
                        cnt++;
                    }
                    else
                    {
                        cnt++;

                        break;
                    }
                }
            }
            if (cnt == 1)
                cout << ans.M << endl;
            else
            {
                cout << "UNDETERMINED" << endl;
            }
        }
        if (t > 0)
            cout << endl;
    }

    return 0;
}