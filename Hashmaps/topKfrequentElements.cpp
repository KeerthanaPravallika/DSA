/*

Link: https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


*/

// first approach

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int,int> mp;
            for(int num : nums)
                mp[num]++;
            
            // storing those key value in vector in reverse way like value , key
            vector<pair<int,int>> vec;
    
            for(auto it:mp)
                vec.push_back({it.second,it.first});
    
            // sorting them in decending order 
            sort(vec.rbegin(),vec.rend());
    
            // return first k numbers 
            vector<int>ans;
            for(int i=0;i<k;i++)
                ans.push_back(vec[i].second);
            return ans;
            
        }
    };

// optimized approach

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            for (int num : nums)
                mp[num]++;
            vector<pair<int, int>> vec(mp.begin(), mp.end());
    
            // sorting based on second value 
            sort(vec.begin(), vec.end() ,[](auto &a, auto &b) { return a.second > b.second; });
    
            vector<int> ans;
            for (int i = 0; i < k; i++)
                ans.push_back(vec[i].first);
            return ans;
        }
    };