/*
Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.

*/

class Solution:

    def longestSubstrDitinctChars(self, S):
        # code here
        maxLen = 0 
        length=0
        string = ""
        flag = 0
        for i in range(len(S)):
            if S[i] not in string :
                string += S[i]
            else:
                flag = 1
                length = len(string)
                if maxLen < length:
                    maxLen = length
                index = string.index(S[i])
                string = string[index+1:] + S[i]
        if flag == 0:
            return len(S)
        if len(string) > maxLen:
            maxLen = len(string)
        return maxLen
