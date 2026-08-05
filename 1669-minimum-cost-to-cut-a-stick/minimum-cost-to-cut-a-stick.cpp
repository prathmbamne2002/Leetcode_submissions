class Solution {
public:
    
    int recurr(int i,int j,vector<int>&a,vector<vector<int>>&dp){

        if(i +1 == j){
            return 0;
        }

        if(dp[i][j]!= -1) return dp[i][j];

        int mini = 1e9;
        for(int idx = i+1;idx<j;idx++){
            mini  = min(mini,a[j]-a[i] + recurr(i,idx,a,dp)+recurr(idx,j,a,dp));
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int>a = cuts;
        a.push_back(0);
        a.push_back(n);

        sort(a.begin(),a.end());

         int sz = a.size();

         vector<vector<int>>dp(sz+5,vector<int>(sz+5,-1));

         return recurr(0,sz-1,a,dp);
    }
};