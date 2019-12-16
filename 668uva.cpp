#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> nums;
        for (int i = 2;; i++)
        {
            if (sum + i > n)
                break;
            sum += i;
            nums.push_back(i);
        }
        int rem = n-sum;
        int pt=nums.size()-1;
        while(rem)
        {
            nums[pt]++;
            rem--;
            pt =( pt==0?nums.size()-1:pt-1);
        }
        for (int i = 0;i<nums.size(); i++)
        {
            cout<<nums[i]<<(i==nums.size()-1?"\n":" ");
        }
        if(m)
        cout<<endl;

    }
    return 0;
}