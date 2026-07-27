class Solution {
public:
    int dp[502][502];
    int recurr(int i,int j,vector<int>&piles){
        if(i>j) return 0;
        

        if(dp[i][j]!= -1) return dp[i][j];

        int takefirst = piles[i] - recurr(i+1,j,piles);
        int takelast  = piles[j] - recurr(i,j-1,piles);

        return dp[i][j]=max(takefirst,takelast);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        //recurr returns the max stones alice can collect
        // int tsum=0;
        // for(int i:piles) tsum+=i;
        memset(dp,-1,sizeof(dp));
        int ans = recurr(0,n-1,piles);
        if(ans> 0) return true;
        else return false;
    }
};