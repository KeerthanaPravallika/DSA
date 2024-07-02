/* 

Link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

*/

bool isCyclic(int V, vector<int> adj[]) {
        // code here
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
		if(result.size() == V)
		    return false;
		return true;
    }

    /*
    
    If we can't do topological sort then it is cyclic because topo sort applies only on directed acyclic graph
    
    
    */