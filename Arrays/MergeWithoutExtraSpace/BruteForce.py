'''
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.

'''
#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        #code here

        p1 = 0     # pointer to first array
        p2 = 0      # pointer to second array
        while(p2 < m):
            if arr1[p1] > arr2[p2]:                # inserting element into array 1
                arr1.insert(p1,arr2[p2])
                p2 += 1
            else:
                p1 += 1
            if p1 == len(arr1):
                break
            
        if p2 != m :
            for k in range(p2,m):
                arr1.append(arr2[k])
                
        arr2.clear()                                 
        for i in range(n,len(arr1)):          # to insert last m elements into arr2
            arr2.append(arr1[i])
        for i in range(n,len(arr1)):          # to remove last elements m elements in arr1
            arr1.pop()
                
