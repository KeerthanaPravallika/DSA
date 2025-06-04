
/*

Link: https://www.naukri.com/code360/problems/tree-traversal_981269?topList=wells-fargo-interview-questions&problemListRedirection=true&count=25&page=2&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav
You have been given a Binary Tree of 'N'

nodes, where the nodes have integer values.



Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.



*/

void inorder(vector<int>&ino ,TreeNode *root){

    if(root==NULL){

        return;

    }

    inorder(ino,root->left);

    ino.push_back(root->data);

    inorder(ino,root->right);

}

void preorder(vector<int>&pre, TreeNode *root){

    if(root==NULL){

        return;

    }

    pre.push_back(root->data);

    preorder(pre,root->left);

    preorder(pre,root->right);

}

void postorder(vector<int>&pos, TreeNode *root){

    if(root==NULL){

        return;

    }

    postorder(pos,root->left);

    postorder(pos,root->right);

    pos.push_back(root->data);

}

vector<vector<int>> getTreeTraversal(TreeNode *root){

    vector<int> ino,pre,pos;

    inorder(ino,root);

    preorder(pre,root);

    postorder(pos,root);

 

    vector<vector<int>>ans;

    ans.push_back(ino);

    ans.push_back(pre);

    ans.push_back(pos);

    return ans;

}

// JAVA

import java.util.ArrayList;

import java.util.List;

public class Solution {

    public static List<List<Integer>> getTreeTraversal(TreeNode root) {

        // Write your code here.

        List<List<Integer>>res=new ArrayList<>();

        res.add(inOrder(root,new ArrayList<Integer>()));

        res.add(preOrder(root,new ArrayList<Integer>()));

        res.add(postOrder(root,new ArrayList<Integer>()));

        return res;

    }

    public static List<Integer> inOrder(TreeNode root,ArrayList<Integer>li){

        if(root==null){

            return li;

        }

        inOrder(root.left,li);

        li.add(root.data);

        inOrder(root.right,li);

        return li;

    }

    public static List<Integer> preOrder(TreeNode root,ArrayList<Integer>li){

        if(root==null){

            return li;

        }

        li.add(root.data);

        preOrder(root.left,li);

        preOrder(root.right,li);

        return li;

    }

    public static List<Integer> postOrder(TreeNode root,ArrayList<Integer>li){

        if(root==null){

            return li;

        }

        postOrder(root.left,li);

        postOrder(root.right,li);

        li.add(root.data);

        return li;

    }

}