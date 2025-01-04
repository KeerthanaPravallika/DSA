/*

Link: https://leetcode.com/problems/invert-binary-tree/description
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

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

    void swap(TreeNode* curr)
    {
        if(curr == NULL) return ;
        swap(curr->left); // going to its left most node
        swap(curr->right); // going to right most node

        // if it is leaf nodes , will go to its parent and swap its left and right pointers
        TreeNode* temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};