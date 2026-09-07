class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1e9+7;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i:nums) pq.push(i);

        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(top+1);
        }

        long long product = 1;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            product = (1ll * product * top)%mod;
        }


        return product;
    }
};