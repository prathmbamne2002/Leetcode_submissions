class Solution {
public:
    vector<int> bit;

    void update(int idx,int x){
        for(int i=idx;i<(int)bit.size();i+=(i & -i)){
            bit[i]+=x;
        }
    }

    int sum(int l,int r){
        int sum1=0;
        for(int i=r;i>0;i-=(i & -i)){
            sum1+=bit[i];
        }

        int sum2=0;
        for(int i=l-1;i>0;i-=(i & -i)){
            sum2+=bit[i];
        }

        return sum1-sum2;
    }

    long long countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        vector<long long> a;

        for(long long i:prefix){
            a.push_back(i);
            a.push_back(i-lower);
            a.push_back(i-upper);
        }

        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());

        bit.assign(a.size()+1,0);

        long long ans=0;

        
        int zero = lower_bound(a.begin(),a.end(),0LL)-a.begin()+1;
        update(zero,1);

        for(int i=1;i<=n;i++){

            int it = lower_bound(a.begin(),a.end(),prefix[i]-lower)-a.begin()+1;

            int it1 = lower_bound(a.begin(),a.end(),prefix[i]-upper)-a.begin()+1;

            ans += sum(it1,it);

            int it2 = lower_bound(a.begin(),a.end(),prefix[i])-a.begin()+1;

            update(it2,1);
        }

        return ans;
    }
};