class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int tsum = 0;
        for(int i:nums) tsum+=i;

        if(tsum<target){
            return 0;
        }

        if(tsum==target) return n;

        int ans = INT_MAX;
        int l=0,r=-1;
        int currsum=0;
        while(l<n){
            while(r+1<n && currsum+nums[r+1]<target){
                r++;
                currsum+=nums[r];
            }

            if(r+1<n && currsum+nums[r+1]>=target){
                ans = min(ans,r-l+2);
            }
            

            if(r<l){
                l++;
                r=l-1;
            }
            else{
                currsum-=nums[l];
                l++;
            }
        }


        return ans;
    }
};