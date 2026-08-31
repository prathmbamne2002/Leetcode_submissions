class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        const int MOD = 1e9 + 7;

        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 2) % MOD;

        long long ans = 0;

        int l = 0, r = n - 1;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + power[r - l]) % MOD;
                l++;
            }
            else {
                r--;
            }
        }

        return ans;
    }
};