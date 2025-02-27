/*

Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.


*/

class Solution {
    public:
    
    /*
    Trailing Zeroes in Factorials: Trailing zeroes in the factorial of a number are produced by the factors 10 in the product. Since 10 is the product of 2 and 5, we need both factors to form a trailing zero.
    Counting Factors of 2 and 5
    Factors of 2: In any factorial, there are usually more factors of 2 than factors of 5. This is because every second number is a multiple of 2.
    Factors of 5: Factors of 5 are less frequent. They appear in multiples of 5 (e.g., 5, 10, 15, 20, etc.).
    Key Insight: Since there are more factors of 2 than 5, the number of trailing zeroes is determined by the number of times 5 is a factor in the numbers from 1 to n.
    */
        int trailingZeroes(int n) {
             int ans=0;
            for(int i=5; i<=n; i=i*5){
                ans+=n/i;
            }
            return ans;
        }
    };



    /*
    
    
    Trailing Zeroes in Factorials
Definition: Trailing zeroes are the zeroes at the end of a number. For example, 100 has two trailing zeroes.
Factorials and Trailing Zeroes
Factorial: The factorial of a number n (denoted as n!) is the product of all positive integers up to n. For example, 5! = 5 * 4 * 3 * 2 * 1 = 120.
Trailing Zeroes in Factorials: Trailing zeroes in the factorial of a number are produced by the factors 10 in the product. Since 10 is the product of 2 and 5, we need both factors to form a trailing zero.
Counting Factors of 2 and 5
Factors of 2: In any factorial, there are usually more factors of 2 than factors of 5. This is because every second number is a multiple of 2.
Factors of 5: Factors of 5 are less frequent. They appear in multiples of 5 (e.g., 5, 10, 15, 20, etc.).
Determining Trailing Zeroes
Key Insight: Since there are more factors of 2 than 5, the number of trailing zeroes is determined by the number of times 5 is a factor in the numbers from 1 to n.
Counting Factors of 5:
We count how many multiples of 5 are there in the range from 1 to n.
We also count higher powers of 5 (like 25, 125, etc.) because they contribute additional factors of 5.
Example Calculation


Summary
Trailing zeroes in n! are determined by the number of times 5 is a factor in the numbers from 1 to n.
Count multiples of 5 and higher powers of 5 to get the total number of trailing zeroes.
    
    
    */