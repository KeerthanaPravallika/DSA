/*

Link:https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.


*/

// 1st approach

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            vector<vector<string>> result;
    
            for(string str : strs)
            {
                string sorted_str = str;
                sort(sorted_str.begin(),sorted_str.end()); // eat -> aet , tea -> aet
                mp[sorted_str].push_back(str); // mp[aet] -> [eat, tea]
            }
    
            for(auto value : mp)
                result.push_back(value.second);
            return result;
    
            
        }
    };