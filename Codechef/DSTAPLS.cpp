#include <bits/stdc++.h>
using namespace std;
long long int divide(long long int dvd, long long int dvs)
{
    long long int ans = 0;
    while (dvd >= dvs)
    {
        unsigned long long int temp = dvs, m = 1;
        while (temp << 1 <= dvd)
        {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long int n, k;
        cin >> n >> k;
        if (k == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        if (n == k)
        {
            cout << "YES" << endl;
            continue;
        }
        long long int f = divide(n, k);
        long long int res = f - divide(f, k) * k;

        if (res == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}