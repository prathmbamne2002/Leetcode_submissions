class Solution {
public:
    int dp[6][2];
    string s;

    int solve(int idx,bool tight,bool hasdiff){
        if(idx == (int)s.size()) return hasdiff ? 1 : 0;

        if(!tight && dp[idx][hasdiff]!= -1) return dp[idx][hasdiff];

        int lim = tight ? (s[idx]-'0') : 9;

        int ans = 0;

        for(int dig=0;dig<=lim;dig++){
            if(dig==3 || dig==4 || dig==7) continue;
            bool nxttight = (tight && (dig==lim));
            bool nxtdiff = (hasdiff ||(dig==2 ||dig==5||dig==6 || dig==9));
            ans += solve(idx+1,nxttight,nxtdiff);
        }

        if(!tight) dp[idx][hasdiff] = ans;
        return ans;
    }
    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false);
    }
};