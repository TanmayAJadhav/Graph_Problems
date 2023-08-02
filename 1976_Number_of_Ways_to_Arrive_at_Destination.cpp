class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<long long,long long>>adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>distance(n,LONG_MAX), ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        
        int mod = (int)(1000000007);
        distance[0] = 0;
        ways[0] = 1;
        while(!pq.empty())
        {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                long long adjnode = it.first;
                long long edjwght = it.second;

                if(edjwght + dis < distance[adjnode])
                {
                    distance[adjnode] = edjwght + dis;
                    ways[adjnode] = ways[node];
                    pq.push({distance[adjnode], adjnode});
                }
                else if(edjwght + dis == distance[adjnode])
                {
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }
        }    

        return ways[n-1]%mod;
    }
};