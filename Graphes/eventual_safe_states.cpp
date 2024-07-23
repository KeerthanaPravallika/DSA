/* 

Link : https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.



*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        // we need to reverse the adj matrix because terminal node
        // and safe nodes depends on outgoing edges
        // but in topo sort we do based on in degree
        // so we need to reverse the edges direction
        vector<int> adjRev[V];
        int i,inDegree[V] = {0};
        
        for(i=0;i<V;i++)
        {
            // it -> i
            for(auto it : adj[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        for(i=0;i<V;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int ele = q.front();
            q.pop();
            safeNodes.push_back(ele);
            for(auto it : adjRev[ele])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};