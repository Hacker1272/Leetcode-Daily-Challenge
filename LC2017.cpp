class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int m = grid[0].size();
        if(m==1){
            return 0;
        }
        
        vector<vector<long long>> temp(2,vector<long long>(m));
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp[i][j] = grid[i][j];
            }
        }
        for(int j=1;j<m;j++){
            temp[0][j]+=temp[0][j-1];
        }

        for(int j=m-2;j>=0;j--)
        {
            temp[1][j]+=temp[1][j+1];
        }

        long long ans=1e18;
        for(int i=0;i<m;i++){
           long long d=1e18,p=1e18;
           d=temp[0][m-1]-temp[0][i];
           p=temp[1][0]-temp[1][i];
           long long f=max(d,p);
           ans=min(ans,f);
        }
        return ans;
    }
};
