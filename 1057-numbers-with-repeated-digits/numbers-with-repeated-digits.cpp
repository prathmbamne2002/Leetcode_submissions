class Solution {
public:
    string s;
    int dp[11][1<<10];

    int solve(int idx,bool tight,bool started,int mask){
        if(idx== (int)s.size()) return started ? 1:0;

        if(!tight && started && dp[idx][mask]!=-1) return dp[idx][mask];

        int lim = tight ? (s[idx]-'0') : 9;
        int ans = 0;
        for(int dig=0;dig<=lim;dig++){
            bool newstarted = started || (dig!=0);
            if(!newstarted){
                ans += solve(idx+1,tight&&(dig==lim),false,mask);
            }
            else if(!((mask>>dig)&1)){
                int newmask = (mask | (1<<dig));
                ans+= solve(idx+1,tight&&(dig==lim),true,newmask);
            }
        }

        if(!tight && started) dp[idx][mask]=ans;
        return ans;
    }

    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        int unique =  solve(0,true,false,0);
        return n - unique;
    }
};