class Solution {
public:
    static const int N = 100005;
    vector<int>bit=vector<int>(N,0);

    void update(int index,int x){
        for(int i=index;i<=N;i+=(i & -i)){
            bit[i]+=x;
        }
    }

    int sum(int idx){
        int ans=0;
        for(int i=idx;i>0;i-=(i & -i)){
            ans+=bit[i];
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int i:nums) mp[i]++;

        int cnt=1;
        for(auto &[key,value]:mp){
            mp[key]=cnt;
            cnt++;
        }

        for(int i=0;i<n;i++){
            nums[i]=mp[nums[i]];
        }

        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            ans.push_back(sum(nums[i]-1));
            update(nums[i],1);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};