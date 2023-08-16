class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int sum = 0;
        vector<int>vis(V);
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wght = it.first;
            int nd = it.second;
            
            if(vis[nd]==1)
            {
                continue;
            }
            vis[nd] = 1;
            sum += wght;
            
            for(auto it2 : adj[nd])
            {
                int adjnode = it2[0];
                int edgwght = it2[1];
                if(!vis[adjnode])
                {
                    pq.push({edgwght,adjnode});
                }
            }
        }
        return sum;
    }
};
