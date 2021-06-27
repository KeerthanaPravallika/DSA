'''
Given a string S. The task is to print all permutations of a given string.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
'''
from itertools import permutations

class Solution:
    def find_permutation(self, S):
        # Code here
        
        permutation = [''.join(p) for p in permutations(S)]
        permutation.sort()
        return permutation
        
