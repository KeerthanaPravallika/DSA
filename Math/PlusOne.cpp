/*

Link: https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].


*/

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int i, carry = 1, index = digits.size() - 1;
            vector<int> res;
            for (i = index; i > -1; i--) {
    
                if (digits[i] + carry > 9) {
                    res.push_back(0);
                    carry = 1;
                } else {
    
                    res.push_back(digits[i] + carry);
                    carry = 0;
                }
            }
    
            if (carry == 1)
                res.push_back(1);
            reverse(res.begin(), res.end());
            return res;
        }
    };