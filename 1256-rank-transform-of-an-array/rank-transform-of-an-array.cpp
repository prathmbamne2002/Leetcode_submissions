class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>a=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int cnt=1;
        for(int i=0;i<n;i++) {
            auto it=mp.find(arr[i]);
            if(it==mp.end()){
                mp[arr[i]]=cnt;
                cnt++;
            }
        }

        for(int i=0;i<n;i++){
            int temp=mp[a[i]];
            a[i]=temp;
        }

        return a;
        
    }
};