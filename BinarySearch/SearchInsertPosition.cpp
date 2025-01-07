/*

Link: https://leetcode.com/problems/search-insert-position/description/

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int mid_index ;

        int left = 0,right = size-1;
        while(left <= right)
        {
            mid_index = (left+right)/2;
            if(nums[mid_index] == target)
                return mid_index;
            if(target > nums[mid_index])
                left = mid_index+1;
            else
                right = mid_index-1;
        }
        return left;
    }
};