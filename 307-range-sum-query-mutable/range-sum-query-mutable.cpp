class NumArray {
public:
    vector<int> bit;
    vector<int> nums;
    int n;

   NumArray(vector<int>& inputNums) {
        n = inputNums.size();
        nums.assign(n, 0); 
        bit.assign(n + 1, 0);

        for(int i = 0; i < n; i++){
            update(i, inputNums[i]);
        }
    }
    
    void update(int index, int val) {
        int x = val - nums[index];
        nums[index] = val;

        for(int i = index + 1; i <= n; i += (i & -i)){
            bit[i] += x;
        }
    }
    
    int sumRange(int left, int right) {
        int sum1 = 0;

        for(int i = right + 1; i > 0; i -= (i & -i)){
            sum1 += bit[i];
        }

        int sum2 = 0;

        for(int i = left; i > 0; i -= (i & -i)){
            sum2 += bit[i];
        }

        return sum1 - sum2;
    }
};