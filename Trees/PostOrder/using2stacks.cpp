/*

Link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]


*/

/*

Will take 2 stacks 
Initially push root into 1st stack
and then in iteration , pop that element , push to second stack
and then insert its left and right elements in stack 1
continue the iteration , pop the first element , insert into stack 2 and then insert its left and right in stack 1



*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> st1,st2;
        

        st1.push(root);

        while(!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left)
                st1.push(node->left);
            if(node->right)
                st1.push(node->right);
        }

        while(!st2.empty())
        {
            TreeNode *node = st2.top();
            st2.pop();
            res.push_back(node->val);
        }

        return res;
    }
};