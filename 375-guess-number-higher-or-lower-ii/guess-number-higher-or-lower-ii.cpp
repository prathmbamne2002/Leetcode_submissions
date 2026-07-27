class Solution {
public:
    int dp[201][201];

    int recurr(int start,int end){
        //base case
        if(start>=end) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        int minicost=INT_MAX;

        for(int i=start;i<=end;i++){
            int worstcost = i +  max(recurr(start,i-1),recurr(i+1,end));
            minicost=min(minicost,worstcost);
        }

        return dp[start][end]=minicost;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return recurr(1,n);
    }
};