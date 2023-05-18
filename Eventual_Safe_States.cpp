class Solution {
  public:
  
    bool dfscheck(int node, vector<int>&vis, vector<int>&pathvis, vector<int>&check, vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                if(dfscheck(child,vis,pathvis,check,adj))
                {
                    return true;
                }
            }
            else if(pathvis[child])
            {
                return true;
            }
        }
        
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfscheck(i,vis,pathvis,check,adj);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(check[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};