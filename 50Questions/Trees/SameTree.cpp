/*

Link : https://leetcode.com/problems/same-tree/description
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Input: p = [1,2,3], q = [1,2,3]
Output: true

*/

/*

We can use any traversal and check whether it is identical or not

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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p == NULL || q == NULL)
                return p==q;
            
            return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            
        }
    };
    
    
    // 2nd approach
    
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
            bool isSameTree(TreeNode* p, TreeNode* q) {
        
               // If both nodes are NULL, they are identical
                if (p == NULL && q == NULL) {
                    return true;
                }
        
                // If only one of the nodes is NULL, they are not identical
                if (p == NULL || q == NULL) {
                    return false;
                }
        
                // Check if values are equal and recursively check left and right subtrees
                if (p->val == q->val) {
                    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
                }
        
                 // Values are not equal, they are not identical
                return false;
                
            }
        };