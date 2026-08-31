class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        int MOD = 1000000007;
        for(int i=0;i<n;i++){
            ans = (ans + mp[target-arr[i]]) % MOD;
            for(int j=0;j<i;j++) mp[arr[i]+arr[j]]++;
        }

        return ans;
    }
};