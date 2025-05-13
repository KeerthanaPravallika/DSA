/*
Link: https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1



*/

/*
A^A=0
A^B^A=B

Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
*/

class Solution {
    public int singleNumber(int[] nums) {
        int i,ans=0;
        for(int num : nums)
            ans ^= num;
        return ans;
        
    }
}