/*
Link: https://leetcode.com/problems/number-of-1-bits/

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

*/

// Approach 1 
class Solution {
    public int hammingWeight(int n) {
        return (int) Integer.toBinaryString(n).chars().filter(ch -> ch =='1').count();
        
    }
}

// Approach 2 - Optimized one

/**
 * 

Why does n & (n - 1) work?
It turns the lowest 1 in n into 0, and keeps the other bits unchanged.

For example:

n     =  12  → 1100
n-1   =  11  → 1011
n & (n-1) = 1000  (removes the last 1)
🧮 Each time we remove a 1:
We increment count++.

The loop continues until n becomes 0 (i.e., no more 1s left).

 * Let’s walk through n = 13 → Binary: 1101

Iteration	n (Binary)	Operation	Result	Count
1	1101	1101 & 1100	1100	1
2	1100	1100 & 1011	1000	2
3	1000	1000 & 0111	0000	3

✅ Total set bits in 13 = 3
 */

class Solution {
    public int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
    return count;
    }
}