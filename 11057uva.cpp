#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> price(n, 0);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        int money;
        cin >> money;

        int diff = INT_MAX;
        sort(price.begin(), price.end());
        int st = 0, ed = price.size() - 1;
        pair<int, int> a;
        while (st < ed)
        {
            int ans = price[st] + price[ed];
            if (ans < money)
            {
                st++;
            }
            else if (ans > money)
            {
                ed--;
            }
            else
            {
                //got ans;
                if (diff > abs(price[st] - price[ed]))
                {
                    diff = abs(price[st] + price[ed]);
                    a.first = price[st];
                    a.second = price[ed];
                }
                ed--;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", a.first, a.second);
    }
    return 0;
}