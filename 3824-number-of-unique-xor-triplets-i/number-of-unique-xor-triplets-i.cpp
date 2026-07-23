#include <bits/stdc++.h>
#include <bit>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            set<int> ans;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        ans.insert(nums[i] ^ nums[j] ^ nums[k]);
                    }
                }
            }
            return ans.size();
        }

        int msb = 0;
        for (int x : nums) {
            msb = max(msb, (int)std::bit_width((unsigned int)x));
        }

        return 1 << msb;
    }
};