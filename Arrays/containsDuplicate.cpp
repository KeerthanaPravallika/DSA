/*

Link: https://leetcode.com/problems/contains-duplicate/description/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

*/


// 1st approach 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]])
                return true;
            else
                mp[nums[i]]++;
        }
        return false;
        
    }
};

//2nd approach

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            return numSet.size() < nums.size();        
        }
    };