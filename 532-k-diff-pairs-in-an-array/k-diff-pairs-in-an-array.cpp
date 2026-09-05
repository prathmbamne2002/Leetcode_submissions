class Solution {
public:
    // int find2(vector<int>&nums,int k){
    //     int n = nums.size();
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[j]-nums[i]<=k) cnt++;
    //         }
    //     }

    //     return cnt;
    // }
    int find(vector<int>&nums,int k){
        int n = nums.size();
        int l = 0,r = -1;
        int cnt=0;
        while(l<n){
            while(r+1<n && nums[r+1]-nums[l]<k){
                r++;
            }

            cnt += r-l+1;

            if(r<l){
                l++;
                r= l-1;
            }
            else{
                l++;
            }
        }

        return cnt;
    }
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>a;
        a.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else a.push_back(nums[i]);
        }
        if(k==0){
            unordered_map<int,int>mp;
            int cnt=0;
            for(int i:nums)mp[i]++;
            for(auto &[key,value]:mp){
                if(value>1) cnt++;
            }
            return cnt;
        }
        int c = find(a,k+1);
        int d = find(a,k);
        // int a1 = find2(nums,k);
        // int b1 = find2(nums,k);
        // cout<<a<<" "<<a1<<endl;
        // cout<<b<<" "<<b1<<endl;
        return c-d;
    }
};