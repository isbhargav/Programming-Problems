#include <bits/stdc++.h>
using namespace std;
int area[5][5];
int ans[5];
int dist(int i, int j, int k, int l)
{
    return abs(i - k) + abs(j - l);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(area, 0, sizeof area);
        int min_dist = INT_MAX;

        int n;
        cin >> n;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            cin >> area[x][y];
        }
        for (int a = 0; a < 25; a++)
        {
            for (int b = a + 1; b < 25; b++)
            {
                for (int c = b + 1; c < 25; c++)
                {
                    for (int d = c + 1; d < 25; d++)
                    {
                        for (int e = d + 1; e < 25; e++)
                        {

                            int sum = 0;
                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5; j++)
                                {
                                    int A = dist(a / 5, a % 5, i, j) * area[i][j];
                                    int B = dist(b / 5, b % 5, i, j) * area[i][j];
                                    int C = dist(c / 5, c % 5, i, j) * area[i][j];
                                    int D = dist(d / 5, d % 5, i, j) * area[i][j];
                                    int E = dist(e / 5, e % 5, i, j) * area[i][j];

                                    sum += min(min(min(A, B), min(C, D)), E);
                                }
                            }
                            if (sum < min_dist)
                            {
                                min_dist = sum;
                                ans[0] = a;
                                ans[1] = b;
                                ans[2] = c;
                                ans[3] = d;
                                ans[4] = e;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++)
            cout << ans[i] << (i == 4 ? "\n" : " ");
    }
    return 0;
}