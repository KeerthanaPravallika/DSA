/*

Link: https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

*/

class Solution {
    public:
        int mySqrt(int x) {
    
            if(x == 0 || x == 1)
                return x;
    
            int high = x, low = 1;
    
            // Perform binary search to find the square root of x.
            while(low <= high)
            {
                long mid = low+ (high - low)/2;
                long val = (mid*mid);
    
                if(val <= x)
                    low = mid+1;
                else
                    high = mid-1;
    
            }
            return high;
            
        }
    };

    // Video link - https://youtu.be/Bsv3FPUX_BA