class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[row][col]=1;
        //neighbours
        int m = board.size(), n = board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            //validation
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && board[nrow][ncol]=='O' && vis[nrow][ncol]==0)  {
                dfs(nrow,ncol,board,vis);
            }
        }   
    }

    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i < m; i++)
        {
            if(!vis[0][i] && board[0][i] == 'O')
            {
                dfs(0,i,board,vis);
            }

            if(!vis[n-1][i] && board[n-1][i] == 'O')
            {
                dfs(n-1,i,board,vis);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!vis[i][0] && board[i][0] == 'O')
            {
                dfs(i,0,board,vis);
            }

            if(!vis[i][m-1] && board[i][m-1] == 'O')
            {
                dfs(i,m-1,board,vis);
            }
        }
        

        for(int i = 0; i < vis.size(); i++)
        {
            for(int j = 0; j < vis[0].size(); j++)
            {
                if(vis[i][j] == 0 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};