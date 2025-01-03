/*

Link : https://leetcode.com/problems/diameter-of-binary-tree/description/
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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
 
 While calculating height , we will calculate left subtree height and right subtree height , so at a given node , diameter will be equal to sum of its left subtree and right subtree
 
 
 */
class Solution {
public:
    int maxDepth(TreeNode* root, int &maxValue)
    {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left, maxValue);
        int rh = maxDepth(root->right, maxValue);

        if(lh+rh > maxValue) maxValue = lh+rh;

        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxValue = 0;
        int h = maxDepth(root,maxValue);
        return maxValue;
    }
};