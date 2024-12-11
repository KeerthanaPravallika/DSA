/*

Link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]


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

    void postorder(TreeNode* root, vector<int> &postorderlist)
    {
        if(root == NULL)
            return;
        postorder(root->left,postorderlist);
        postorder(root->right,postorderlist);
        postorderlist.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> postorderlist;

        postorder(root, postorderlist);

        return postorderlist;
        
    }
};