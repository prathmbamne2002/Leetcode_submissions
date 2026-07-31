class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(char i:word) mp[i]++;

        int ans=0;
        int cnt=0;
        int mulfactor=1;
        vector<int>a;

        for(auto &[key,value]:mp) a.push_back(value);
        sort(a.rbegin(),a.rend());

        for(auto it:a){
            if(cnt<8){
                ans+=mulfactor*it;
                cnt++;
            }
            else{
                mulfactor++;
                cnt=1;
                ans+=mulfactor*it;
            }
        }

        return ans;
    }
};