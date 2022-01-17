#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int cnt = 0;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        cnt = 0;

        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> dic, have;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            dic[v[i]]++;
        }

        int i = 0;
        sort(v.begin(), v.end());
        for (i = 0; i < k; i++)
        {
            have[v[i]]++;
        }
        if (have[v[i - 1]] < dic[v[i - 1]])
        {
            //find combination
            int r = have[v[i - 1]];
            int N = dic[v[i - 1]];
            int mx = max((N - r), r);
            int mn = min((N - r), r);

            unsigned long long int ncr = 1, di = 1;
            for (unsigned long long int j = N; j > mx; j--)
            {
                ncr *= j;
            }
            for (unsigned long long int j = 1; j <= mn; j++)
            {
                di *= j;
            }
            ncr /= di;
            cout << ncr << endl;
        }
        else //have==find
        {
            cout << 1 << endl;
        }
    }
    return 0;
}