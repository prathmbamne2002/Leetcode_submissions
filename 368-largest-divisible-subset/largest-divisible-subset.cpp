class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>par(n,-1);
        

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    par[i]=j;
                }
            }
        }


        int maxi = *max_element(dp.begin(),dp.end());

        int x = -1;

        for(int i=0;i<n;i++) {
            if(dp[i]==maxi){
                x = i;
                break;
            }
        }
        vector<int>ans;
        while(x>=0){
            ans.push_back(nums[x]);
            x = par[x];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};