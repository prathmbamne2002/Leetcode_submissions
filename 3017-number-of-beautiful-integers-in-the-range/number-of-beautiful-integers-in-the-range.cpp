class Solution {
public:
    int k;
    string s;
    int dp[12][21][21];

    int solve(int idx,bool tight,bool started,int bal,int rem){
        if(idx == (int)s.size()){
            if(started && bal==10 && rem==0) return 1;
            else return 0;
        }

        if(!tight && started && dp[idx][bal][rem]!=-1) return dp[idx][bal][rem];

        int lim = tight ? (s[idx]-'0') : 9;

        int ans = 0;

        for(int dig =0;dig<=lim;dig++){
            bool newstarted  = started || (dig!=0);
            if(!newstarted){
                ans += solve(idx+1,tight && (dig==lim),false,bal,rem);
            }
            else{
                int newbal = bal +((dig%2==0) ? 1 : -1);
                int newrem  = (rem*10 + dig)%k;
                ans += solve(idx+1,tight && (dig==lim),true,newbal,newrem);
            }
        }

        if(!tight && started) dp[idx][bal][rem]=ans;
        return ans;
    }

    int calc(int n){
        if(n<=0) return 0;
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false,10,0);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;
        return calc(high)-calc(low-1);
    }
};