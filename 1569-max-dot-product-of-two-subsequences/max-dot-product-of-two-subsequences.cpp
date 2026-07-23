class Solution {
public:
    int recurr(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()) return -1e9;

        if(dp[i][j]!=-1e9) return dp[i][j];

        int take = max(nums1[i]*nums2[j],nums1[i]*nums2[j] + recurr(i+1,j+1,nums1,nums2,dp));
        int nottake=max( recurr(i+1,j,nums1,nums2,dp),recurr(i,j+1,nums1,nums2,dp));

        return dp[i][j]=max(take,nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1e9));
        return recurr(0,0,nums1,nums2,dp);
    }
};