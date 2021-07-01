/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
*/
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int list[n],i,j,maxElement=0;
       list[0] = 1;
       for(i=1;i<n;i++)
       {
           list[i] = 1;
           for(j=0;j<i;j++)
           {
               if(a[i] > a[j] && list[i] < list[j]+1)
                list[i] = list[j] + 1;
           }
           if(maxElement < list[i])
            maxElement = list[i];
       }
       return maxElement; 
       
    }
};
