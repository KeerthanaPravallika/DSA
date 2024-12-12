/* 

Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]

Output: [1,2,3]

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

 /*
 
 Approach


 Take a stack
 Push the root of it 
 and in loop , take the ele, append to list
 push its right and then left because stack follows LIFO and preorder means root left right 
 
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;

        st.push(root);
        while(!st.empty())
        {
            // This commented code is giving time limit exceeded
            // res.push_back(st.top()->val);
            
            // if(st.top()->right != NULL)
            //     st.push(root->right);
            // if(st.top()->left != NULL)
            //     st.push(root->left);
            // st.pop();
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);

            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }

        return res;

        
    }
};