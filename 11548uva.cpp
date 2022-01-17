#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    //  cout << lcs("ALICE", "BOB");
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string db[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> db[i];
        }
        int ans = 0;

        for (int a = 0; a < n; ++a)
        {
            for (int b = 0; b < n; ++b)
            {

                if(a==b)
                    continue;

                int tmp = 0;
                int M = db[a].length();
                int N = db[b].length();

                
                    for (int j = 0; j < N; ++j)
                    {
                        int sum = 0;
                        for (int k = 0, l = j; k < M && l < N; ++k, ++l)
                        {
                            if (db[a][k] == db[b][l])
                                sum++;
                        }
                        tmp = max(tmp, sum);
                    }
              
                ans = max(tmp, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}