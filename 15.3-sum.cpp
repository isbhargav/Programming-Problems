/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int partial_target = - nums[i];
            int front =i+1,rear=nums.size()-1;
            while(front<rear)
            {
                int sum = nums[front]+nums[rear];
                if(sum<partial_target)
                    front++;
                else if(sum>partial_target)
                    rear--;
                else
                {
                    vector<int> tt={nums[i],nums[front],nums[end]};
                    ans.push_back(tt);
                    while(front<rear && nums[front]==nums[front+1])
                        front++;
                    if(front<rear && nums[rear]==nums[rear-1])
                        rear--;
                }

            }
             while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;
        }
        return ans;
    }
};

