/*

Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].



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
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> res;
        double sum;
        if (!root) return res;

        queue<TreeNode*> q;

        q.push(root);
        

        while(!q.empty())
        {
            vector<int> temp;
            sum = 0;

            int count = q.size(); // need to take becaue at each level we need to know how many elements are there and iterate throgh each element
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                sum += (curr->val);
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
            }
            res.push_back(sum/count);
        }
        return res;

        
    }
};