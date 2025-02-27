/*

Link: https://leetcode.com/problems/powx-n/?envType=study-plan-v2&envId=top-interview-150
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


*/

class Solution {
    public:
        double myPow(double x, int n) {
    
            double ans = 1.0;
            long long currPower = n;
    
            if(currPower < 0) currPower *= -1;
    
            while(currPower)
            {
                if(currPower % 2 == 1) // if it is not divisible by 2
                {
                    ans = ans* x;
                    currPower--;
                }
                else{
                    x = x * x; // ex - 2^6 == (2*2)^5 
                    currPower= currPower/2;
                }
            } 
    
            if(n < 0) ans = (double)1.0/double(ans);
            return ans;
            
        }
    };

    // Video link - https://youtu.be/l0YC3876qxg