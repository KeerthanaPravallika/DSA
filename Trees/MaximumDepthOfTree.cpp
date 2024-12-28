/*

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Input: root = [3,9,20,null,null,15,7]
Output: 3



*/

/*

use level order traversal and instead of storing the element , increase the height of it


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res=0;
        if (!root)
            return 0;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            res++;

            int count = q.size(); // need to take becaue at each level we need
                                  // to know how many elements are there and
                                  // iterate throgh each element
            for (int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        return res;
    }
};