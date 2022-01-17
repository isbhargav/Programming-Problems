#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n = t;
        vector<int> arr(t, 0);
        for (int i = 0; i < t; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        for (int a = 0; a < n - 5; a++)
            for (int b = a + 1; b < n - 4; b++)
                for (int c = b + 1; c < n - 3; c++)
                    for (int d = c + 1; d < n - 2; d++)
                        for (int e = d + 1; e < n - 1; e++)
                            for (int f = e + 1; f < n; f++)
                                cout << arr[a] << " " << arr[b] << " " << arr[c] << " " << arr[d] << " " << arr[e] << " " << arr[f] << endl;

        cin >> t;
        if (t)
            cout << endl;
    }

    return 0;
}
