'''

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0


'''

'''

Approach 
1. Trim the extra spaces
2. Check the sign 
3. Move the index till there is no leading zero
4. in recursion getNum(s,index,0,sign) , check if it is a digit and length should be < 
5. result = result * 10 + current number
6, check whether it is integer limit 
'''

class Solution:
    def myAtoi(self, s: str) -> int:

        def getNum(number , index , result , sign):

            # if the parsing is completed or if we get a non digit 
            if(index >= len(number) or not number[index].isdigit()):
                return sign * int(result)

            # calculate the current result
            result = result * 10 + int(number[index])

            # check if it is more than highest +ve int value
            if sign * result >=2**31-1 :
                return 2**31-1
            
            # check if it is less than lowest -ve int value
            if sign * result <= -2**31 :
                return -2**31

            return getNum(number,index+1, result , sign)
            

    
        # step 1 : trim the extra space
        s = s.strip()

        if not s :
            return 0

        # step 2 : Checking the sign , if exists what it should be 
        sign = 1 # it should ne 1 because if it is only "42" it means positive
        index = 0
        if s[0] in '+-':
            sign = 1 if s[0] == '+' else -1
            index += 1

        # step 3: checking leading zeros and moving the index till you get a number
        while(index < len(s) and s[index] == 0):
            index += 1

        return getNum(s,index,0,sign)

        