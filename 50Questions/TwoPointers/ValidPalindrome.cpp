/*

Link: https://leetcode.com/problems/valid-palindrome/

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.


*/
class Solution {
public:
    bool isPalindrome(string s) {
        string st;

        for(int i = 0;i<s.length();i++)
        {
            if(s[i] >= 65 && s[i] <= 90)
                st += (char)tolower(s[i]);
            if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
                st += s[i];
        }

        int i = 0,j = st.length()-1;

        while(i<j)
        {
            if(st[i] != st[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

