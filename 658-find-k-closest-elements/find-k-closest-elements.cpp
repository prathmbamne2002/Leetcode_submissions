class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int cnt=0;
        int  i = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=i,r=i-1;
        while(cnt<k){
            int distl=1e9,distr=1e9;
            if(r>=0){
                distr = abs(x-arr[r]);
            }
            if(l<arr.size()){
                distl = abs(x-arr[l]);
            }

            if(distr<=distl){
                ans.push_back(arr[r]);
                r--;
                cnt++;
            }
            else{
                ans.push_back(arr[l]);
                l++;
                cnt++;
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};