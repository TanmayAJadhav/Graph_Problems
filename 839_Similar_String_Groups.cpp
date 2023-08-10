lass Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&graph)
    {
        vis[node] = true;
        for(auto &it:graph[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,graph);
            }
        }
    }

    bool check(string st1, string st2)
    {
        int cnt = 0;
        for(int i = 0; i < st1.size(); i++)
        {
            if(st1[i] != st2[i])
            {
                cnt++;
            }
        }

        return cnt <= 2;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        vector<vector<int>>graph(strs.size());
        for(int i = 1; i < strs.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(check(strs[i],strs[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }      

        int ans = 0;
        vector<int>vis(strs.size());
        for(int i = 0; i < strs.size(); i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,graph);
                ans++;
            }
        }
        return ans;
    }
};