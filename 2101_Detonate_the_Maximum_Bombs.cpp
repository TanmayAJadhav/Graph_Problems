#define ll long long
class Solution {
public:
    void dfs(int node, vector<bool>&vis, int&cnt, vector<int>adj[])
    {
        vis[node] = true;
        cnt++;
        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                dfs(child,vis,cnt,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        vector<int>adj[n];   

        for(int i = 0; i < n; i++)
        {
            ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];

            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    ll x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                    ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

                    if(dist <= r1*r1) 
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        } 

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            vector<bool>vis(n,0);
            int cnt = 0;
            dfs(i,vis,cnt,adj);
            ans = max(ans,cnt);
        }
        return ans;
    }
};