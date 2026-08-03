class Solution {
public:

    int recurr(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){

        if(j1>=m || j1<0 || j2>=m || j2<0) return -1e9;

        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxi= -1e9;

        for(int p= -1;p<=1;p++){
            for(int q= -1;q<=1;q++){
                int cnt = 0;
                if(j1==j2){
                    cnt=grid[i][j1];
                }
                else{
                    cnt = grid[i][j1] + grid[i][j2];
                }

                maxi=max(maxi,cnt+recurr(i+1,j1+p,j2+q,n,m,grid,dp));
            }
        }

        return dp[i][j1][j2] = maxi;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        return recurr(0,0,m-1,n,m,grid,dp);

    }
};