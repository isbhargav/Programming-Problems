#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        if (sum % n == 0)
        {

            int avg = sum / n;
            for (int i = 0; i < n; i++)
            {
                ans += abs(nums[i] - avg);
            }
            ans = ans / 2;
        }
        else
        {
            ans = -2;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}