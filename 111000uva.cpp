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

        // this will store the count of duplicates
        unordered_map<int, int> dic;
        int maxx = 0; // max duplicate count we have

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


/*
 *  1 1 2 2 2 3 4 5
 *  ______
 *    ______  
 *      ______
 */
