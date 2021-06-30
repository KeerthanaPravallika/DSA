/*

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

 

Example 1:

Input:
s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.
 

Example 2:

Input:
s = GeeksForGeeks, x = For
Output: 5
Explanation: For is present as substring
in GeeksForGeeks from index 5 (0 based
indexing).

*/
//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
     int index = 0,subIndex = 0;
     int i,j,flag=0;
     for(i=0;i<s.size();i++)
     {
         if(s[i] == x[subIndex])
         {
             flag = 0;
             index = i;
             //cout<<index<<endl;
             for(j=0;j<x.size();j++)
             {
                 if(s[index] != x[j])
                 {
                     flag = 1;
                     break;
                 }
                 index++;
             }
             if(flag == 0)
                return i;
         }
     }
     return -1;
}
