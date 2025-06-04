/*

Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2



*/

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;
        
        // Count the frequency of each character
        for (char c : s) {
            map[c]++;
        }
        
        // Find the index of the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; // Return -1 if no unique character is found
    }
};


// JAVA 

class Solution {
    public int firstUniqChar(String s) {
      char st[]=s.toCharArray();
      HashMap<Character,Integer>map=new HashMap<>();
      for(char c:st){
        map.put(c,map.getOrDefault(c,0)+1);
      }
        for (int i = 0; i < st.length; i++) {
            if (map.get(st[i]) == 1) {
                return i;
            }
        }
        return -1;
    }
}