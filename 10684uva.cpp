#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    while(cin>>n,n!=0){
        vector<int> nums(n);
        for(int &x: nums)
            cin>>x;

        int ans=0,curr_sum=0;
        for(int i=0;i<nums.size();++i)
        {
            curr_sum+=nums[i];
            ans = max(ans,curr_sum);
            curr_sum = max(curr_sum,0);
        }
        if(ans<=0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",ans);
    }
    return 0;
}
