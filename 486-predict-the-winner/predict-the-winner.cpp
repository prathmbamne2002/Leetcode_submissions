
class Solution {
public:
    int dp[21][21];
    int recurr(int start,int end,vector<int>&nums){

        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int takefirst = nums[start] - recurr(start+1,end,nums);
        int takelast  = nums[end] - recurr(start,end-1,nums);

        return dp[start][end]=max(takefirst,takelast);
        
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int score = recurr(0,n-1,nums);
        if(score>=0) return true;
        else return false;
    }
};