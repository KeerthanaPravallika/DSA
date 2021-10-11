'''
Write a program to take String if the length of String is odd print X pattern otherwise print INVALID.

Input Format:
Take a String as input from stdin.

Output Format:
print the desired Pattern or INVALID.

Example Input:
edyst

Output:

e   t
 d s 
  y  
 d s 
e   t

'''

word = input()

if len(word) % 2 == 0:
    print("INVALID")
else:
    n = len(word)
    for i in range(n):
        for j in range(n):
            if(i == j) or (j == n-i-1):
                print(word[j],end='')
            else:
                print(' ',end='')
        print()
