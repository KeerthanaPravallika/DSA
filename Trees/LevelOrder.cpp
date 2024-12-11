/*

Link -  https://leetcode.com/problems/binary-tree-level-order-traversal/description/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;

        q.push(root);
        

        while(!q.empty())
        {
            vector<int> temp;

            int count = q.size(); // need to take becaue at each level we need to know how many elements are there and iterate throgh each element
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            res.push_back(temp);
        }

        return res;
        
    }
};