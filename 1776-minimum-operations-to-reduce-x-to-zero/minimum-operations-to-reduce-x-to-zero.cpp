class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tsum = 0;
        for(int i:nums) tsum+=i;

        int target = tsum - x;

        if(target<0) return -1;
        if(target==0) return n;
        //cout<<1<<endl;

        int ans = -1;
        int currsum = 0;
        int l =0,r=-1;


        while(l<n){
            while(r+1<n && currsum + nums[r+1]<target){
                r++;
                currsum+=nums[r];
            }

            if(r+1<n && currsum+nums[r+1]==target){
                ans = max(ans,r-l+2);
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

        if(ans==-1) return -1;
        
        return n - ans;

    }
};