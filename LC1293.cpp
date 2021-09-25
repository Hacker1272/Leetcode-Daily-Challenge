//TC = O(n*m*n*k)
//SC = O(n*m*k)

class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        q.push({0,0,k});
        bool visited[n][m][n*m+1];
        memset(visited,false,sizeof(visited));
        visited[0][0][k] = true;
        int dist = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                vector<int> curr = q.front();
                q.pop();
                int i = curr[0];
                int j = curr[1];
                int k = curr[2];
                if(i==n-1 && j==m-1) return dist;
                for(int d=0;d<4;d++)
                {
                    int x = i+dir[d][0];
                    int y = j+dir[d][1];
                    if(x<0 || x==n || y<0 || y==m) continue;
                    int remk = k-grid[x][y];
                    if(remk>=0 && visited[x][y][remk]==false)
                    {
                        q.push({x,y,remk});
                        visited[x][y][remk] = true;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
