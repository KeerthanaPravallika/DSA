/*
Link - https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}


Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.

*/

#include <queue>
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        /* Steps to follow 
        
        1. Create a queue having starting node
        2. created a visited array
        3. pop up the element from queue and display and Insert all the neighbours of element in queue which are not visited
        
        */
        
        queue<int> bfs;
        bfs.push(0);
        unordered_map<int,int> visited_array;
        visited_array[0] = 1;
        vector<int> result;
        int i,ele;

        while(!bfs.empty())
        {
            ele = bfs.front();
            result.push_back(ele);
            bfs.pop();
            for(i=0;i<adj[ele].size();i++)
            {
                if(!visited_array[adj[ele][i]])
                {
                    bfs.push(adj[ele][i]);
                    visited_array[adj[ele][i]] = 1;
                }
            }
        }
        return result;
        
        
      
    }
};
