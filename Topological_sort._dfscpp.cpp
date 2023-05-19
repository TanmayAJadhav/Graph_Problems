class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node, vector<int>&vis, stack<int>&st, vector<int> adj[])
	{
	    vis[node] = 1;
	    
	    for(auto child : adj[node])
	    {
	        if(!vis[child])
	        {
	            dfs(child,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    vector<int>vis(V,0);
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,st,adj);
	        }
	    }
	    
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};