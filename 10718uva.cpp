#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int n, l, u;
    while (cin >> n >> l >> u)
    {
        // int lz = __builtin_clz(u);
        // int pos = 32 - lz - 1;
        int a[32];
        for (int i = 0; i < 32; i++, n >>= 1)
            a[i] = n % 2;

        unsigned long long int m = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (a[i]) //if it is 1 than i dont need to trun it 1 but if i dont turn on will it be in range
            {
                // it is 1 so i dont need to on this bit but if i on this bit and still its less than l then i need to on this bit
                if ((m | (1LL << i)) <= l)
                {
                    m = m | (1LL << i);
                }
            }
            else // it is 0 so i need to turn this on but turing it on will it exceed range
            {

                if ((m | (1LL << i)) <= u) // turning it on does not exceed range
                {
                    m = m | (1LL << i);
                }
                else // truning it on exceeds range hence we cannot turn this on
                {
                    m = m;
                }
            }
        }
        cout << (n | m) << endl;
    }

    return 0;
}