'''
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
'''
class Solution:
    
    #Function to reverse words in a given string.
    def reverseWords(self,S):
        # code here 
        l = S.split('.')
        st = ''
        for i in range(len(l)-1,-1,-1):
            st += l[i] + '.'
           
        return st[:len(st)-1]
            
