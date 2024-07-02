/*

Link : https://leetcode.com/problems/course-schedule/description/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> result;
		queue<int> q;
		vector<int> inDegree(numCourses,0);
		int i, ele;

        for(auto it : prerequisites)
            adj[it[0]].push_back(it[1]);
		
		for(i=0;i< numCourses;i++)
		    for(auto it : adj[i])
		        inDegree[it]++;
		
		for(i=0;i<numCourses;i++)
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
		if(result.size() == numCourses)
		    return true;
		return false;

    }
};