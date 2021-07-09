/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.
*/
class Solution{
    static int equalPartition(int N, int nums[])
    {
        // code here
         int n = nums.length;
        int sum = 0;
        for(int i=0;i<n;++i)
            sum += nums[i];
        
        if(sum%2 == 1)
            return 0;
        
        boolean[][] dp = new boolean[n+1][sum/2+1];
        
        for(int i=0;i<=n;++i)
        for(int j=0;j<=sum/2;++j)
        {
            if(i==0 || j==0)    //Base Case
                dp[i][j] = false;
            else if(nums[i-1] > j)    //SkIP case
                dp[i][j] = dp[i-1][j];
            else if(nums[i-1]==j)
                dp[i][j] = true;
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        }        
        if(dp[n][sum/2])
            return 1;
        return 0;
    }
}
