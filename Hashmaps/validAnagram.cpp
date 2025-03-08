/*

Link: https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

*/

// 1st approach

class Solution {
    public:
        bool isAnagram(string s, string t) {
            unordered_map<char,int> freq;
    
            int i,j;
            for (char c : s) {
                freq[c]++;
            }
            for (char c : t)
                if (freq[c] == 0)
                    return false;
                else
                    freq[c]--;
            for(char c : s)
                if(freq[c] != 0)
                    return false;
            return true;
            
        }
    };


// Optimized approach

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) {
                return false;
            }
    
            unordered_map<char, int> sCount, tCount;
    
            for (int i = 0; i < s.length(); i++) {
                sCount[s[i]]++;
                tCount[t[i]]++;
            }
    
            return sCount == tCount;        
        }
    };