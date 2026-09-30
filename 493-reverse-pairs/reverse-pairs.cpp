class Solution {
public:
    vector<int> bit;

    void update(int idx, int x, int n) {
        for(int i = idx; i <= n; i += (i & -i)) {
            bit[i] += x;
        }
    }

    int sum(int idx) {
        int ans = 0;
        for(int i = idx; i > 0; i -= (i & -i)) {
            ans += bit[i];
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> a = nums;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int sz = a.size();
        bit.assign(sz + 1, 0);

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            
            int pos = upper_bound(a.begin(), a.end(), 2LL * nums[i]) - a.begin();

            
            ans += sum(sz) - sum(pos);

            int idx = lower_bound(a.begin(), a.end(), nums[i]) - a.begin() + 1;
            update(idx, 1, sz);
        }

        return ans;
    }
};