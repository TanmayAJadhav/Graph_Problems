class Solution {
public:
    vector<int>calcord(int curr,int n)
    {
        int r = n - (curr-1)/n - 1;
        int c = (curr-1)%n;

        if(r%2 == n%2)
        {
            return {r,n-1-c};
        }
        else
        {
            return {r,c};
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<int>q;
        q.push(1);

        visited[n-1][0] = true;
        int steps = 0;
        while(!q.empty())
        {
            int sze = q.size();
            for(int i = 0; i < sze; i++)
            {
                auto it = q.front();
                q.pop();

                if(it == n*n)
                {
                    return steps;
                }
                for(int k = 1; k <= 6; k++)
                {
                    if(k+it > n*n)
                    {
                        break;
                    }
                    vector<int>cord = calcord(k+it,n);
                    int row = cord[0];
                    int col = cord[1];

                    if(visited[row][col] == true)
                    {
                        continue;
                    }
                    visited[row][col] = true;
                    if(board[row][col] == -1)
                    {
                        q.push(k+it);
                    }
                    else
                    {
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }   
        cout<<"heh r";
        return -1;
    }
};909. Snakes and Ladders
