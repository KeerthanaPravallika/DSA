/*

Link: https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

Given an integer x, return true if x is a palindrome, and false otherwise.

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


*/

class Solution {
    public:
        bool isPalindrome(int x) {
            string st = to_string(x);
            string st1 = st;
            reverse(st.begin(), st.end());
            if(st1 == st)
                return true;
            return false;
        }
    };