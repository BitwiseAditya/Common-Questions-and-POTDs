/* 15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int temp = nums[i] + nums[right] + nums[left];
                if (temp > 0)
                {
                    right--;
                }
                else if (temp < 0)
                {
                    left++;
                }
                else if (temp == 0)
                {
                    vector<int> toput = {nums[i], nums[left], nums[right]};
                    sort(toput.begin(), toput.end());
                    ans.push_back(toput);
                    left++;
                    right--;
                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;
    }
};
