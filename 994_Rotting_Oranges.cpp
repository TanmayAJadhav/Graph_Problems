class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<vector<int>>vis = grid;
        int r = grid.size(), c = grid[0].size();
        int ans = 0;
        int cntone = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i  = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(vis[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                if(vis[i][j] == 1)
                {
                    cntone++;
                }
            }
        }
        if(cntone == 0)
        {
            return ans;
        }

        if(q.empty()==true)
        {
            return -1;
        }

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto it = q.front();
                q.pop();
                int row = it.first.first;
                int col = it.first.second;
                int time = it.second;
                
                ans = max(time,ans);

                for(int j = 0; j < 4; j++)
                {
                    int newr = row + delr[j];
                    int newc = col + delc[j];

                    if(newr >= 0 && newc >= 0 && newr < r && newc < c && vis[newr][newc] == 1)
                    {
                        q.push({{newr,newc},time+1});
                        cntone--;
                        vis[newr][newc] = 2;
                    }
                }
            }
        }
        if(cntone == 0)
        {
            return ans;
        }
        return -1;
    }
};