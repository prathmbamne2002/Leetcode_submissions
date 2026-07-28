class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long>diff(n);
        long long  tsum=0;
        for(int i=0;i<n;i++){
            diff[i] =  (nums[i]^k) - nums[i];
            tsum+= nums[i];
        }

        sort(diff.rbegin(),diff.rend());

        for(int i=0;i<n;i+=2){
            if(i+1==n) break;

            int change = diff[i] + diff[i+1];

            if(change>0) tsum+= change;
        }

        return tsum;
    }
};