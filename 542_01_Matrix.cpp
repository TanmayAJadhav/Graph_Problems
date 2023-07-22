class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int r = mat.size(), c = mat[0].size();

        queue<pair<pair<int,int>,int>>q; 
        vector<vector<int>>ans(r,vector<int>(c,0));
        vector<vector<int>>vis(r,vector<int>(c,0));

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;

            ans[row][col] = steps;

            for(int i = 0; i < 4; i++)
            {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if(newrow >= 0 && newcol >= 0 && newrow < r && newcol < c && !vis[newrow][newcol])
                {
                    q.push({{newrow,newcol},steps+1});
                    vis[newrow][newcol] = 1;
                }
            }
        }
        return ans;
    }
};