/*
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123

Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
*/

class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int i,num=0;
        for(i=0;i<str.size();i++)
        {
            if(str[i] >= 48 && str[i] <= 57){
                int ascii = str[i] - 48;
                num = ((num*10) + ascii);
            }
            else if(i != 0 && str[0] != '-')
                return -1;
                
        }
        if(str[0] == '-')
            num = num*(-1);
        return num;
    }
};
