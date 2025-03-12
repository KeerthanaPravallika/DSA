/*

Link: https://leetcode.com/problems/3sum/description
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

*/

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
    
            vector<vector<int>> res;
            int left, right;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++) {
                if ((i == 0) || (i > 0 && nums[i] != nums[i - 1])) {
                    int remSum = 0 - nums[i];
    
                    left = i + 1;
                    right = nums.size() - 1;
    
                    while (left < right) {
    
                        if (nums[left] + nums[right] == remSum) {
                            vector<int> temp;
                            temp.push_back(nums[left]);
                            temp.push_back(nums[right]);
                            temp.push_back(nums[i]);
    
                            res.push_back(temp);
    
                            while (left < right && nums[left] == nums[left + 1])
                                left++;
                            while (left < right && nums[right] == nums[right - 1])
                                right--;
    
                            left++;
                            right--;
                        } else if (nums[left] + nums[right] > remSum)
                            right--;
                        else
                            left++;
                    }
                }
            }
    
            return res;
        }
    };