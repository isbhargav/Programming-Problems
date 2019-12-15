#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            sum += nums[i];
        }
        //sort(nums.begin(), nums.end());
        if (sum)
        {
            bool first = true;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                }
                else
                {

                    cout << (first ? "" : " ") << nums[i];
                    first = false;
                }
                if (i == n - 1)
                    cout << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}