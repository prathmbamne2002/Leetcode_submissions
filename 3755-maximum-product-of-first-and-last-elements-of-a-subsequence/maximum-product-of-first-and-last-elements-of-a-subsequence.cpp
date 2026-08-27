class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int>suffixpos(n,1),suffixneg(n,1);
         suffixpos[n-1]=nums[n-1];
         suffixneg[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffixpos[i]=max(nums[i],suffixpos[i+1]);
            suffixneg[i]=min(nums[i],suffixneg[i+1]);
        }
        // for(int i:suffixpos) cout<<i<<" ";
        // cout<<endl;
        // for(int i:suffixneg) cout<<i<<" ";

        long long ans=-1e18;
        for(int i=0;i+m-1<n;i++){
            ans=max({ans,1LL*nums[i]*suffixpos[i+m-1],1LL*nums[i]*suffixneg[i+m-1]});
        }

        return ans;
    }
};