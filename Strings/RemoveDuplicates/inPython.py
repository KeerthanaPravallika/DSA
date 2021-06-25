'''
Given a string without spaces, the task is to remove duplicates from it.

Note: The original order of characters must be kept the same. 

Example 1:

Input: S = "zvvo"
Output: "zvo"
Explanation: Only keep the first
occurrence
'''


class Solution:
	def removeDups(self, S):
		# code here
		
		st = ''
		for ch in S:
		    if ch not in st:
		        st += ch
		return st
		        
