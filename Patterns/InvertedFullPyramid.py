'''
Given an integer n as input, print an inverted full pyramid of n rows.

Input Format:

Take input an integer from stdin
Output Format:

Print the pattern
Example Input:
10

Output:

* * * * * * * * * * 
 * * * * * * * * * 
  * * * * * * * * 
   * * * * * * * 
    * * * * * * 
     * * * * * 
      * * * * 
       * * * 
        * * 
         * 
'''
n = int(input())

space = 0
for j in range(n,0,-1):
    for k in range(space):
        print(' ',end='')
    for i in range(j):
        print('*',end=" ")
    space +=1
    print()
    




