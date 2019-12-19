#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n)
    {

        vector<int> bgs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> bgs[i];
        }
        sort(bgs.begin(), bgs.end());
        unordered_map<int, int> dic;
        int maxx = 0;
        for (auto x : bgs)
        {
            dic[x]++;
            maxx = max(dic[x], maxx);
        }
        cout << maxx << endl;
        for (int i = 0; i < maxx; i++)
        {
            cout << bgs[i];
            for (int j = maxx + i; j < n; j += maxx)
            {
                cout << " " << bgs[j];
            }
            cout << endl;
        }
    }
    return 0;
}