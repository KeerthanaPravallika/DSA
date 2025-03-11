/*

Link : https://leetcode.com/problems/longest-consecutive-sequence/description/
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/


// Before it got submitted now it is showing time limit exceeded
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
            int longest = 0;
    
            for (int num : nums) {
                /* 
                find Return Value:
    
                If the value is found in the range, returns an iterator to its position.
                If the value is not found, returns an iterator to the end of the range.
                
                
                */
    
                // check if it is starting of index by checking whether num -1 exist or not
    
                // if it is not existing means it is the starting element and we can find the length from there
    
                if (numSet.find(num - 1) == numSet.end()) // num - 1 doesn't exist so finding length
                {
                    int length = 1;
    
                    while (numSet.find(num + length) != numSet.end()) { // if next element exists , we need to increment the length value 
                        length++;
                    }
    
                    longest = max(longest, length);
                }
            }
    
            return longest;
        }
    };


// 2nd approach -optimized

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
    
            sort(nums.begin(),nums.end());
    
            int i,maxLen = 0, currLen = 1;
    
            for(i=1;i<nums.size();i++)
            {
                if(nums[i] - nums[i-1] == 1)
                    currLen++;
                else if(nums[i] - nums[i-1] > 1) // for this input [1,0,1,2] , duplicates can be there , so only else wont be suffcient , we need to write condition
                {
                    maxLen = max(maxLen,currLen);
                    currLen = 1;
                }
            }
    
            if(nums.size() != 0)
                maxLen = max(maxLen,currLen);
            return maxLen;
            
        }
    };