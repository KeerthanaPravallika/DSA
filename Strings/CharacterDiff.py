'''
. You are given a string that contains only lowercase and uppercase alphabets. 
2. You have to form a string that contains the difference of ASCII values of every two consecutive characters between those characters.
   For "abecd", the answer should be "a1b3e-2c1d", as 
   'b'-'a' = 1
   'e'-'b' = 3
   'c'-'e' = -2
   'd'-'c' = 1
  '''
s = input()
for i in range(len(s)-1):
    print(s[i]+str(ord(s[i+1])-ord(s[i])),end="")
print(s[-1])
