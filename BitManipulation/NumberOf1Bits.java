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