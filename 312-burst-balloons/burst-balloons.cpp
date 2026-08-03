class Solution {
public:
    int n;
    int dp[305][305];
    int recurr(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j){
            int temp = nums[i];
            if(i-1>0) temp*=nums[i-1];
            if(i+1<n) temp*=nums[i+1];
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;
        for(int k=i;k<=j;k++){
            int temp = nums[k];
            if(j+1<n) temp *= nums[j+1];
            if(i-1>=0) temp *=nums[i-1];

            maxi=max(maxi,temp+recurr(i,k-1,nums)+recurr(k+1,j,nums));
        }

        return dp[i][j]=maxi;
    }

    int maxCoins(vector<int>& nums) {
        vector<int>a;
        a.push_back(1);
        for(int i:nums) a.push_back(i);
        a.push_back(1);
        n = a.size();

        memset(dp,-1,sizeof(dp));
        return recurr(1,n-2,a);
    }
};