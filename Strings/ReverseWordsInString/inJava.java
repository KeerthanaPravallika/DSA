/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
*/

class Solution 
{
    //Function to reverse words in a given string.
    String reverseWords(String S)
    {
        // code here 
        String[] arr = S.split("\\.");
 
        String st="";
        for(int i=arr.length-1;i>=0;i--)
                st += (arr[i]+".");

        return st.substring(0,st.length()-1);
    }
}
