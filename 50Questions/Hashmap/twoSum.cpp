/*

Link: https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].



*/

// 1st approach 
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            unordered_map<int,int> mp;
    
            for(int i=0;i<nums.size();i++)
            {
                if(mp[target-nums[i]])
                {
                    res.push_back(i);
                    res.push_back(mp[target-nums[i]]-1);
                    return res;
                }
                else{
                    mp[nums[i]] = i+1; // we need to store i+1 because index will be 0 and if condition can be failed
                }
            }
            return res;
            
        }
    };

// optimized approach

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> mp;
    
            for(int i=0;i<nums.size();i++)
            {
                int num = nums[i];
                if (mp.find(target - num) != mp.end()) {
                    return {i, mp[target - num]};
                }
                mp[num] = i;
            }
            return {};
            
        }
    };