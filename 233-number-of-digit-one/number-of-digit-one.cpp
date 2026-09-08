class Solution {
public:
    string s;
    int dp[12][12];

    int solve(int idx,bool tight,int cnt){
        if(idx == (int)s.size()) return cnt;

        if(!tight && dp[idx][cnt]!= -1) return dp[idx][cnt];

        int lim = tight ? (s[idx]-'0') : 9;
        int ans=0;
        for(int dig = 0;dig <= lim; dig++){
            ans += solve(idx+1,tight && (dig==lim), cnt+(dig==1));
        }

        if(!tight) dp[idx][cnt] = ans;
        return ans;
    }

    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,0);
    }
};