/* 

Link : https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.



*/

vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> result;
		queue<int> q;
		vector<int> inDegree(V,0);
		int i, ele;
		
		for(i=0;i< V;i++)
		    for(auto it : adj[i])
		        inDegree[it]++;
		
		for(i=0;i<V;i++)
		    if(inDegree[i] == 0)
		        q.push(i);
		
		while(!q.empty())
		{
		    ele = q.front();
		    result.push_back(ele);
		    q.pop();
		    
		    for(auto it : adj[ele])
		    {
		        inDegree[it]--;
		        if(inDegree[it] == 0)
    		        q.push(it);
		    }
		        
		    
		}
		return result;
		
		
	}


    /*
    
    Use auto for less time complexity
    
    */