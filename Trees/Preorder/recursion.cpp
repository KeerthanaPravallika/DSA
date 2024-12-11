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
class Solution {
public:

    void preorder(TreeNode *root, vector<int> &preorderList)
    {
        if(root == NULL)
            return;
        preorderList.push_back(root->val);
        preorder(root->left, preorderList);
        preorder(root->right, preorderList);

    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorderList;
        preorder(root, preorderList);

        return preorderList;

        
    }
};
