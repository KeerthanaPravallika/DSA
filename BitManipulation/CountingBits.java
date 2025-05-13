/*

Link: https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

*/

// Approach 1

class Solution {
    public String convertToBinary(int n)
    {
        String s="";
        while(n >= 1)
        {
            s += (char) n%2;
            n = n/2;
        }
        return s;
    }
    public int[] countBits(int n) {
        int i;
        String binaryNumber;
        int res[] = new int[n+1];
        res[0] = 0;
        for(int num=1;num<n+1;num++)
        {
            binaryNumber = convertToBinary(num);
            res[num] = (int) binaryNumber.chars().filter(ch -> ch == '1').count();
        }
        return res;
        
    }
}


/*

Approach 2

Intuition :

To find the number of 1s in the binary representation of numbers from 0 to ( n ), we can use a pattern:

If ( i ) is even, the number of 1s in ( i ) is the same as the number of 1s in ( i/2 ) (right-shifting an even number halves it without adding a new 1).

If ( i ) is odd, the number of 1s in ( i ) is the number of 1s in ( i - 1 ) plus one additional 1 (as adding 1 to an even number makes it odd).

Approach :

Initialize the Array: Create an array ans of size ( n + 1 ) and set the base case ans[0] = 0.

Iterate from 1 to n:

For each ( i ):

If ( i ) is even, set ans[i] = ans[i / 2].

If ( i ) is odd, set ans[i] = ans[i - 1] + 1.

Return the array ans after completing the iteration.

*/

class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        ans[0] = 0; // base case

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                ans[i] = ans[i / 2];       // even: same number of 1s as i / 2
            } else {
                ans[i] = ans[i - 1] + 1;   // odd: one more 1 than i - 1
            }
        }

        return ans;
    }
}

/*

Approach 3 - Most optimized

If we do right shift of the number , last bit will be removed or we can say it will be divided by 2 
5 -> 0101 
5 >> 1 -> 0010

And to see whether last bit is 1 or 0 , we can use i & 1 , 


So the formula will be , we can do have the value of right shift and then check the last bit whether it is 1 or 0

So 5 >> 1 -> 0010 ( prev we will cmpute this value for 2 which is 1 and then (i & 1) will be 1 , final answer will be 2)
*/

class Solution {
    public int[] countBits(int n) {
        int [] ans = new int[n+1];
        for(int i = 1;i <= n;i++)
            ans[i] = ans[i >> 1] + (i & 1);
        return ans;
    }
}
