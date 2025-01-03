/*

Link : https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is 
height-balanced
.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Input: root = [3,9,20,null,null,15,7]
Output: true

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
 
 If it is height balanced means it will return the height of the tree else it will return -1 
 
 */

class Solution {
public:
    int dfsHeight(TreeNode *node)
    {
        if(node == NULL) return 0;
        int lh = dfsHeight(node->left);
        if(lh == -1)
            return -1;
        int rh = dfsHeight(node->right);
        if(rh == -1)
            return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1; 
    }
};