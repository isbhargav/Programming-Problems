#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int lim = sqrt(c);
        bool sol = false;
        for (int i = -lim; i < lim; i++)
        {
            for (int j = i + 1; j < lim; j++)
            {
                int k = a - i - j;
                int div = i * j;
                if (div == 0 || i == k || j == k)
                    continue;

                if (b % (div) != 0)
                    continue;

                if (i * j * k == b && (i * i + j * j + k * k) == c)
                {
                    cout << i << " " << j << " " << k << endl;
                    sol = true;
                    break;
                }
            }
            if (sol)
                break;
        }
        if (!sol)
            cout << "No solution.\n";
    }
    return 0;
}