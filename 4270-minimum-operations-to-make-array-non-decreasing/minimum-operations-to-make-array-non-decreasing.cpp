class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) ans+= 1LL*(nums[i-1]-nums[i]);
        }
        return ans;
    }
};