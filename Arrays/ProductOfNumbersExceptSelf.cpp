/*

Link: https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]



*/

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(),0);
            int prefixProduct = 1, suffixProduct = 1;
    
            
            for(int i=0;i<nums.size();i++)
            {
                res[i] = prefixProduct;
                prefixProduct *= nums[i];
            }
    
            for(int i = nums.size()-1;i>=0;i--)
            {
                res[i] *= suffixProduct;
                suffixProduct *= nums[i];
            }
    
            return res;
    
            
        }
    };