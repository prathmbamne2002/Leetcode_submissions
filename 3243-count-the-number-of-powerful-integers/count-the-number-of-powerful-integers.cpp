class Solution {
public:
    string s,suffix;
    int maxlimit;
    long long dp[20][2];

    long long solve(int idx,bool tight){
        if(idx==(int)s.size()) return 1;

        if(!tight && dp[idx][0]!=-1) return dp[idx][0];

        int lim = tight ? (s[idx]-'0') : 9;
        long long ans=0;
        int suffstart = (int)s.size() - (int)suffix.size();

        if(idx>=suffstart){
            int req = suffix[idx-suffstart]-'0';

            if(req<=maxlimit && req<=lim){
                ans += solve(idx+1,tight&&(req==lim));
            }
        }
        else{
            for(int dig=0;dig<=min(lim,maxlimit);dig++){
                ans += solve(idx+1,tight&&(dig==lim));
            }
        }

        if(!tight) dp[idx][0] = ans;
        return ans;
    }

    long long calc(long long n){
        
        s = to_string(n);
        if(s.size()<suffix.size()) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,true);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        suffix = s;
        maxlimit = limit;
        return calc(finish)-calc(start-1);

    }
};