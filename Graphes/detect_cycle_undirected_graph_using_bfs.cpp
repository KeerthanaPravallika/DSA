/* 

Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example : 
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.

*/

bool bfs(int src, vector<int>adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto n : adj[node]){
                if(!vis[n]){
                    vis[n]=1;
                    q.push({n,node});
                }
                else if(parent != n){ // if it is visited and it is not the parent then it is a cycle
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v] = {0};
        for(int i=0;i<v;i++){ // because graph can be disconnected 
            if(!vis[i]){
                if(bfs(i,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
