/*

Link: https://leetcode.com/problems/count-good-numbers/

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.


*/
/*

We’re applying the rule of counting:

For each even position → 5 ways (0,2,4,6,8)

For each odd position → 4 ways (2,3,5,7)

Now:

If n = 1 → only 1 even position → 5 good strings

If n = 2 → one even, one odd → 5 * 4 = 20 good strings

If n = 4 → two even, two odd → 5² * 4² = 400 good strings

Where:

even_positions = (n + 1) / 2 (extra one if n is odd)

odd_positions = n / 2

So in general 
5 pow evenPositions * 4 pow oddPositions 

We use recursive fast exponentiation because:

Brute force multiplication would take O(n) steps (too slow for large n like 10¹⁸).

Recursion reduces it to O(log n) by halving the exponent each time.

*/

class Solution {
    private static final int MOD = 1000000007;

    public int countGoodNumbers(long n) {
        // Number of even positions (0, 2, 4...) = ceil(n/2)
        long evenPositions = (n + 1) / 2;

        // Number of odd positions (1, 3, 5...) = floor(n/2)
        long oddPositions  = n / 2;

        // Calculate power(5, evenPositions) % MOD
        long evenWays = powMod(5, evenPositions);

        // Calculate power(4, oddPositions) % MOD
        long oddWays  = powMod(4, oddPositions);

        // Multiply results under modulo
        return (int)((evenWays * oddWays) % MOD);
    }

    // Recursive fast exponentiation
    private long powMod(long base, long exp) {
        // Base case: x^0 = 1
        if (exp == 0) return 1;

        // Divide: compute half power recursively
        long half = powMod(base, exp / 2);

        // Combine: square the half result
        long result = (half * half) % MOD;

        // If exponent is odd, multiply one extra base
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }
}
