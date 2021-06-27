/*
Your Task:  
You don't need to read input or print anything.
Your task is to complete the function lastIndex() which takes the string S as 
inputs and returns the last index of '1'. If '1' is not present, return "-1" (without quotes).

*/
class Solution{
    public:
    int lastIndex(string s) 
    {
        int i,index=-1;
        reverse(s.begin(),s.end());
        for(i=0;i<s.length();i++)
            if(s[i] == '1')
            {
                index = s.length()-1-i;
                break;
            }
                
        return index;
    }

};
