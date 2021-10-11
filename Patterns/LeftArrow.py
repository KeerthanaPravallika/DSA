'''
Write a program to print the Left Arrow Pattern.You need to do that by  using two for loops only.

Input Format:
Take integer input from stdin.

Output Format:
Print the desired Pattern.

Example Input:
5

Output:

* * * * * * * * * * 
* * * * * * * * 
* * * * * * 
* * * * 
* * 
* * 
* * * * 
* * * * * * 
* * * * * * * * 
* * * * * * * * * * 

'''

n = int(input())

for i in range(n,0,-1):
    for j in range(i*2):
        print('*',end=' ')
    print()
    
for i in range(1,n+1):
    for j in range(i*2):
        print('*',end=' ')
    print()



