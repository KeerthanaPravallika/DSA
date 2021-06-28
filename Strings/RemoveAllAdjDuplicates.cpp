/*
Given a string s, remove all its adjacent duplicate characters recursively. 

Example 1:

Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgkâ€‹
*/
class Solution{
public:
    string remove(string s){
        // code here
        
        int last = 0,flag = 0,i,j , l=0,r=0;
        int len = s.size();
        string s2;
        
        for(i=0;i<len;)
        {
            j = i + 1;
            flag = 0;
            while(s[i] == s[j] && j < len)
            {
                j++;
                flag = 1;
                last = 1;
            }
            if(flag == 1)
            {
                l = j;
                i = j;
            }
            else
            {
                r = i;
                s2.append(s.substr(l,(r-l+1)));
                l = j;
                i++;
            }
        }
        if(last == 0)
            return s2;
        else
            return remove(s2);
        
    }
};
