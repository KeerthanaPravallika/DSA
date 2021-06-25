
/* 
Given a string without spaces, the task is to remove duplicates from it.

Note: The original order of characters must be kept the same. 

Example 1:

Input: S = "zvvo"
Output: "zvo"
Explanation: Only keep the first
occurrence
*/

class Solution {
    String removeDups(String S) {
        // code here
        
        String ns="";
        int i;
        String ch;
        char[] sarr = S.toCharArray();
        for(i=0;i<sarr.length;i++)
        {
            //ch = sarr[i];
            if(ns.indexOf(sarr[i]) == -1)
                ns += sarr[i];
        }
        return ns;
    }
}
