class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n,0);
        dp[0]=0;
        int mini = prices[0];

        for(int i=1;i<n;i++){
           dp[i]=dp[i-1];
           if(dp[i]<=dp[i-1]+prices[i]-mini){
            dp[i]=dp[i-1]+prices[i]-mini;
            mini=prices[i];
           }
           else{
            mini=min(mini,prices[i]);
           }
        }

        return dp[n-1];
    }
};