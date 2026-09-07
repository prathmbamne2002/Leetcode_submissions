class Solution {
public:
    long long  check(int mid,vector<int>&nums,int k){
        long long cnt = 0;
        for(int i:nums){
            if(i<mid) cnt+= (mid-i);
        }

        return cnt;
    }

    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1e9+7;
        int kRem = 0;
        
        int lo = *min_element(nums.begin(),nums.end());
        int hi = 1e9;
        int ans = lo;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            long long kUsed = check(mid,nums,k);

            if(kUsed<=k){
                ans =  mid;
                kRem = k-kUsed;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        //cout<<ans<<endl;

        long long product= 1;

        for(int i=0;i<n;i++){
            if(nums[i]<=ans && kRem) {
                product = (1ll*product*(ans+1))%mod;
                kRem--;
                }
            else if(nums[i]<ans) product = (1ll*product*ans)%mod;
            else product = (1ll*product*nums[i])%mod;
        }

        return product;

    }
};