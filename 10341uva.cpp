#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7
int p, q, r, s, t, u;
double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0f) + u;
}
int main()
{
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6)
    {
        bool flag = false;
        double low = 0.0, high = 1.0;
        if (f(low) * f(high) > 0)
        {
            printf("No solution\n");
        }
        else
        {

            while (low + EPS <= high)
            {
                double mid = (high + low) / 2.0;
                if (f(low) * f(mid) <= 0)
                {
                    high = mid;
                }
                else
                    low = mid;
            }
            printf("%.4lf\n", low);
        }
    }

    return 0;
}