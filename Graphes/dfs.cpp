/* 

Link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.

*/

class Solution {
  public:
  
  /* 
   Steps :
   1. have a visited array initiated with 0s
   2. need to do recursion as it is depth
   3. First we will go to one element , and check adj list to see the children of it, will go 
    one child of it and goes down till its depth
    4. while visiting ech node, we will change the visisted arra of the element to 1 and add to 
    the result vector.
  
  */
  
  void dfs(int node, vector<int> adj[], int vis[], vector<int> &res )
  {
      vis[node] = 1;
      res.push_back(node);
      for(auto it : adj[node])
      {
          if(!vis[it])
            dfs(it,adj,vis,res);
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> res;
        dfs(start,adj,vis,res);
        return res;
    }
};
