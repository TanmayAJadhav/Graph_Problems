// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.Return the modified image after performing the flood fill.

class Solution {
public:
    void dfs(vector<vector<int>>&ans, int delrow[], int delcol[], int row, int col, int changecolor, int inCol)
    {
        ans[row][col] = changecolor;
        int n = ans.size(), m = ans[0].size();
        for(int i = 0; i < 4; i++)
        {
            int newr = delrow[i] + row;
            int newc = delcol[i] + col;

            if(newr >= 0 && newc >= 0 && newr < n && newc < m && ans[newr][newc] == inCol && ans[newr][newc] != changecolor)
            {
                dfs(ans,delrow,delcol,newr,newc,changecolor,inCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int inCol = image[sr][sc];
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        dfs(image,delrow,delcol,sr,sc,color,inCol);
        return image;
    }
};