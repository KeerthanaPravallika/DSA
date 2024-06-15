/*

Link : https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.



*/

class Solution {
  public:
  
    void dfs(int node,vector<int> adjLst[], int visited_list[])
    {
        visited_list[node] = 1;
        for(auto it : adjLst[node])
      {
          if(!visited_list[it])
            dfs(it,adjLst,visited_list);
      }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjLst[V];
        
        // Converting adj matrix to adj list
        int i,j;
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }
        
        // dfs traversal but as they are not connected , 
        // will check each vertex and find how many provinces are there
        int count=0,visited_list[V] = {0};
        for(i=0;i<V;i++)
        {
            if(!visited_list[i])
            {
                count++;
                dfs(i,adjLst, visited_list);
            }
        }
        return count;
        
    }
};
