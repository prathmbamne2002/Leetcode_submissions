class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr(n);
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i] = max(arr[i-1]+1,nums[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++) ans+= (arr[i]-nums[i]);
        return ans;
    }
};