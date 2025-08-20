/*

Link: https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


 */

/*

At every recursive step:

If we still have some "(" left → we can add "("

If we have more ")" left than "(" → we can add ")"

When both "(" and ")" are used up → we add the string to the result.

""  
 └── "("  
      └── "(("  
           └── "(((" → must close → "((()))"  
           └── "(()" → more options → "(()())" , "(())()"  
      └── "()"  
           └── "()( " → leads to "()(())" , "()()()"  


*/

class Solution {

    public void backtrack(List<String> res, String str, int open, int close)
    {
        // Base case: if no more parentheses to add
        if(open == 0 && close == 0)
        {
            res.add(str);
            return;
        }
        // If we still have open > 0, we can place a "("
        // → recurse with open - 1
         // If we still have "(" left, we can place it

        if(open > 0)
            backtrack(res,str+"(",open-1,close);

        // If we still have close > open, we can place a ")"
        // → recurse with close - 1
         // We can place ")" only if we have more ")" left than "("
        if(close > open)
            backtrack(res,str+")", open, close-1);
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(res,"",n,n);
        return res;
        
    }
}