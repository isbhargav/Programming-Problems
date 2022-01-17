#include <bits/stdc++.h>
using namespace std;

//version 2 apply sum constrain
int main()
{
    for (int i = 1; 4 * i <= 2000; i++)
    {

        for (int j = i; 3 * j <= 2000 - i; j++)
        {

            for (int k = j; 2 * k <= 2000 - i - j; k++)
            {
                if (i * j * pow(k, 2) > 2000000000)
                    break;

                int B = i * j * k;
                int A = i + j + k;
                if (B <= 1000000)
                    continue;
                int X = A * 1000000;
                int Y = B - 1000000;

                if (X % Y != 0)
                    continue;

                int l = X / Y;
                if (l >= k && A + l <= 2000)
                    printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i / 100, i % 100, j / 100, j % 100, k / 100, k % 100, l / 100, l % 100);
            }
        }
    }

    return 0;
}