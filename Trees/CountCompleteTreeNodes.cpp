/*

Link : https://leetcode.com/problems/count-complete-tree-nodes/description

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.




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
    int countNodes(TreeNode* root) {

        // BFS and count the nodes
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int n=0;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            n++;
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);  
        }
        return n;
    }
};