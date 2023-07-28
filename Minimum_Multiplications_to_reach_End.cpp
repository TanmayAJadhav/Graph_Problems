class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        queue<pair<int,int>>q;
        q.push({start,0});
        
        vector<int>store(100000,1e9);
        store[start] = 0;
        
        if(start==end)
        {
            return 0;
        }
        
        int mod = 100000;
        while(!q.empty())
        {
            
            int num = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(auto it:arr)
            {
                int mulnum = (num*it)%mod;
                if(1+steps < store[mulnum])
                {
                    store[mulnum] = 1 + steps;
                    if(mulnum == end)
                    {
                        return steps+1;
                    }
                    q.push({mulnum,steps+1});
                }
            }
        }
        return -1;
        
        
    }
};
