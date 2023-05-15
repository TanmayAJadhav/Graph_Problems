bool check(int start, vector<int>&color, vector<int>adj[])
{
    queue<int>q;
    q.push(start);
    color[start] = 1;
    while(!q.empty())
    {
        int it = q.front();
        q.pop();
        for(auto it2 : adj[it])
        {
            if(color[it2] == -1)
            {
                color[it2] = !color[it];
                q.push(it2);
            }
            else if(color[it2] == color[it])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int>color(V,-1);
    
    for(int i = 0; i < V; i++)
    {
        if(color[i] == -1)
        {
            if(check(i, color, adj)==false)
            {
                return false;
            }
        }
    }
    
    return true;
    // Code here
}