/*

Link: https://www.naukri.com/code360/problems/number-of-mismatching-bits_920394?topList=wells-fargo-interview-questions&problemListRedirection=true&count=25&page=2&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav

Given two integers "first" and "second". Find the number of bits that do not match in the binary representation of the given numbers.

For example, let "first" be 11 and "second" be 15. Writing both the given numbers in binary we get first = 1011(binary representation of 11) and second = 1111(binary representation of 15) we can see all the bits are the same except the second bit.


Therefore only 1 bit differs hence we return 1 as shown in the diagram.

Note:
1. Do not print anything, just implement the provided function and return the number of mismatching bits for the given numbers.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10 ^ 5
0 <= first, second <= 10^9

Where ‘T’ is the total number of test cases and "first", " second" are the given numbers.

Time limit: 1 second
Sample Input 1:
2
11 15
12 16
Sample Output 1:
1
3
Explanation of sample input 1 :
Test Case 1:

We get "first" is equal to 11 and "second" is equal to 15.

Converting to binary representation, we get 
First = 11 = 2^3 + 2^1 + 2^0
First = 1011
Second = 15 = 2^3 + 2^2 + 2^1 + 2^0
Second = 1111

We can see that the first third and fourth bits are the same in both the numbers but the second bit is different,  it is 0 in the first number and 1 in the second number. Since only 1 bit differs, we return 1.


*/


#include <bits/stdc++.h> 

int numberOfMismatchingBits(int first, int second)

{

    //  Write your code here.

    int res =0;

    while(first!=0||second!=0)

    {

        int firstKaLastBit = first&1;

        int secondKaLastBit = second&1;

        if(firstKaLastBit!=secondKaLastBit)res++;

        first>>=1;

        second>>=1;

    }

    return res;

}