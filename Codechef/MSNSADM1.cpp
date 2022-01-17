#include <bits/stdc++.h>
using namespace std;
int A[200];
int B[200];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
            int tmp = A[i] * 20 - B[i] * 10;
            ans = max(ans, (tmp > 0 ? tmp : 0));
        }

        cout << ans << endl;
    }
    return 0;
}