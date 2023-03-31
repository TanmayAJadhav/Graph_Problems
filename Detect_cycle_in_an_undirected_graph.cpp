vector<int>vis;
  public:
    bool detectcycle(int node, vector<int> adj[])
    {
        vis[node] = true;
        queue<pair<int,int>>q;
        q.push({node,-1});
        
        while(!q.empty())
        {
            auto currnode = q.front().first;
            auto parentnode = q.front().second;
            
            q.pop();
            
            for(auto adjacent : adj[currnode])
            {
                if(!vis[adjacent])
                {
                    vis[adjacent] = 1;
                    q.push({adjacent,currnode});
                }
                else if(parentnode != adjacent)
                {
                    return true;
                }
            }
        }
        return false;
    }
        
    bool isCycle(int V, vector<int> adj[]) {
        vis.resize(V+1,0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(detectcycle(i,adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }