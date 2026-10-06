class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // dp[0][i] = max profit up to day i with 1 transaction
        // dp[1][i] = max profit up to day i with 2 transactions
        vector<vector<int>> dp(2, vector<int>(n, 0));

        int min1 = prices[0]; // Minimum cost for the 1st buy
        int min2 = prices[0]; // Effective minimum cost for the 2nd buy

        for(int i = 1; i < n; i++){
            // --- First Transaction ---
            // Track the lowest price seen so far
            min1 = min(min1, prices[i]);
            // Max profit is either previous profit, or selling today minus min1
            dp[0][i] = max(dp[0][i-1], prices[i] - min1);

            // --- Second Transaction ---
            // Effective buy price is today's price MINUS the profit we already made
            min2 = min(min2, prices[i] - dp[0][i]);
            // Max profit is either previous profit, or selling today minus effective min2
            dp[1][i] = max(dp[1][i-1], prices[i] - min2);
        }

        return dp[1][n-1];
    }
};