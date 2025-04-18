
/*

Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


*/




/*

Approach 

If root is null or if root is x or if root is y then return root
Made a recursion call for both
i) Left subtree 

ii)Right subtree

Because we would find LCA in the left or right subtree only.

If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
 If both left & right calls give values (not null)  that means the root is the LCA.
 
 
 */




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL)
            return right;
        else if(right == NULL)
            return left;
        else 
            return root;
    }
};


// 2nd approach

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL){
                return NULL;
            }
    
            if(root->val == p->val || root->val == q->val){
                return root;
            }
    
            TreeNode* lca_left = lowestCommonAncestor(root->left, p, q);
            TreeNode* lca_right = lowestCommonAncestor(root->right, p, q);
    
            if(lca_left && lca_right){
                return root;
            }
    
            return lca_left ? lca_left : lca_right;
            
        }
    };