/*
Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:

Double the number
Add one to the number

Example 1:

Input:
N = 8
Output: 4
Explanation: 0 + 1 = 1, 1 + 1 = 2,
2 * 2 = 4, 4 * 2 = 8
*/

class Solution
{
    public int minOperation(int n)
    {
        //code here.
        int arr[] = new int[n+1];
        arr[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            if(i % 2 == 0)
            {
                arr[i] = Math.min(arr[i/2],arr[i-1]) + 1;
            }
            else
            {
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[n];
    }
}

/*

1 - 1
2 - 2
3 - 3   (2+1)
4 it can be from min(2 *2 or 3+1) so 2+1 = 3 steps
5 - 4 + 1 => 4 steps
6 can be from (3*2) or (5+1) min is 3*2 so 3+1 = 4 steps
....
*/
