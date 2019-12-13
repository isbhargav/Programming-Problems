#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int case_id = 1;
    while (t--)
    {
        int n;
        cin >> n;
        n--;
        vector<int> nums(n);
        for (auto &x : nums)
        {
            cin >> x;
        }

        //apply kadane
        int sum = 0, ans = 0;
        int i = 0, j = 0, prev_i = 0;
        for (int k = 0; k < n; k++)
        {

            sum += nums[k];
            if (sum >= ans)
            {
                // if curee sum is greater than ans or if sum==ans then check len(K-prev_i)>len()
                if (sum > ans || k-prev_i > j-i)
                {
                    i = prev_i;
                    j = k;
                    ans = sum;
                }
                
            }

            if (sum < 0)
            {
                prev_i = k + 1;
                sum = 0;
            }
        }

        if (ans > 0 && i < n)
        {
            printf("The nicest part of route %d is between stops %d and %d\n", case_id++, i + 1, j + 2);
        }
        else
        {
            printf("Route %d has no nice parts\n", case_id++);
        }
    }
    return 0;
}