/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        //Todo special cases

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int partial_target1 = target - nums[i];

            for (int j = i + 1; j < nums.size(); j++)
            {
                int partial_target2 = partial_target1 - nums[j];

                int front = j + 1, rear = nums.size() - 1;
                while (front < rear)
                {
                    int sum = nums[front] + nums[rear];

                    if (sum < partial_target2)
                        front++;

                    else if (sum > partial_target2)
                        rear--;

                    else
                    {
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[front];
                        temp[3] = nums[rear];
                        ans.push_back(temp);
                        while (nums[front + 1] == temp[2] && front < nums.size() - 1)
                            front++;
                        while (nums[rear - 1] == temp[3] && rear > 0)
                            rear--;
                    }
                }
                while (nums[j] == nums[j + 1] && j < nums.size())
                    j++;
            }
            while (nums[i] == nums[i + 1] && i < nums.size())
                i++;
        }

        return ans;
    }
};
