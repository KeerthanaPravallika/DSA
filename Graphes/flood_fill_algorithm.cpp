/* 

Link : https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.

*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        
        // use bfs traversal and check 4 sides
        
        int starting_color = image[sr][sc];
        
        if(starting_color == newColor)
            return image;
            
        int new_row, new_col;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = newColor;
        
        
        while(!q.empty())
        {
            new_row = q.front().first;
            new_col = q.front().second;
            q.pop();

            
            // checking 4 sides 
            
            // top
            if(new_row-1 >=0 && image[new_row-1][new_col] == starting_color)
            {
                image[new_row-1][new_col] = newColor;
                q.push({new_row-1,new_col});
            }
            //bottom
            if(new_row+1 < n && image[new_row+1][new_col] == starting_color)
            {
                image[new_row+1][new_col] = newColor;
                q.push({new_row+1,new_col});
            }
            // left
            if(new_col-1 >= 0 && image[new_row][new_col-1] == starting_color)
            {
                image[new_row][new_col-1] = newColor;
                q.push({new_row,new_col-1});
            }
            //right
            if(new_col+1 < m && image[new_row][new_col+1] == starting_color)
            {
                image[new_row][new_col+1] = newColor;
                q.push({new_row,new_col+1});
            }
            
        }
        
        
        return image;
        
        
    }
    
    /* 
    
    Things to notice
    1. Don't take another matrix as it is time excleeding
    2. While pushing into queue itslef change the colour instead of doing it seperatly
    3. if the starting colour and new colour is same , check it and return at that time
    
    
    
    
    */
};
