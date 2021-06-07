/* 
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
*/

class Solution {
    public int subarraySum(int[] nums, int k) {
       int count=0,i,j,sum;
        for(i=0;i<nums.length;i++)
        {
            sum = nums[i];
             if(sum == k)
                    count++;
            for(j=i+1;j<nums.length;j++)
            {
                 sum += nums[j];
                if(sum == k)
                    count++;
                
               
            }
        }
        return count;
    }
}
