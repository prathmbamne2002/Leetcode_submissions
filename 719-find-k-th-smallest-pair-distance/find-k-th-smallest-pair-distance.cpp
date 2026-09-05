class Solution {
public:
    int check(int mid,vector<int>&nums,int k){
        int n = nums.size();
        int cnt = 0;
        int l=0,r=-1;
        
        while(l<n){
            while(r+1<n && nums[r+1]-nums[l]<=mid){
                r++;
                
            }
            cnt += r-l;

            if(r<l){
                l++;
                r=l-1;
            }
            else{
                
                l++;
            }
        }

        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int hi = nums[n-1]-nums[0];
        int lo = 0;
        int ans = lo;

        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,nums,k)){
                
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }


        return lo;

    }
};