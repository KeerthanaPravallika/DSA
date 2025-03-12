/*

Link: https://leetcode.com/problems/container-with-most-water/
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/

// Runtime is 7ms and beats 8.30%
class Solution {
public:
    int maxArea(vector<int>& height) {

        int lp=0,rp=height.size()-1,maxAmt = 0;
        while(lp < rp)
        {
            maxAmt = max(maxAmt, min(height[lp],height[rp])*(rp-lp));
            if(height[lp] > height[rp])
                rp--;
            else
                lp++;
        }
        return maxAmt;
        
    }
};


// if we just change the if condition to ternary , runtime was 0% and beats 100%
class Solution {
public:
    int maxArea(vector<int>& height) {

        int lp = 0, rp = height.size() - 1, maxAmt = 0;
        while (lp < rp) {
            maxAmt = max(maxAmt, min(height[lp], height[rp]) * (rp - lp));
            height[lp] > height[rp] ? rp-- : lp++;
        }
        return maxAmt;
    }
};
