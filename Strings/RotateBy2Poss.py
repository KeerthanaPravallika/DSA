'''
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam.
'''
class Solution:
    def isRotated(self,str1,str2):
        #code here
        antiClockRotateSt = str1[2:]+str1[:2]
        if antiClockRotateSt == str2:
            return True
        clockRotateSt = str1[-2:]+str1[:len(str1)-2]
        
        if clockRotateSt == str2:
            return True
        return False
