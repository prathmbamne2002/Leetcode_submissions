class Solution {
public:
    //string s;
    int dp[24][405];
    int mod = 1e9+7;

    int solve(string &s,int idx,bool tight,int cnt,int min_sum,int max_sum){
        if(idx==(int)s.size()) return (cnt>=min_sum && cnt<=max_sum) ? 1 : 0;

        if(!tight && dp[idx][cnt]!=-1) return dp[idx][cnt];

        int lim = tight ? (s[idx]-'0') : 9;

        int ans=0;

        for(int dig=0;dig<=lim;dig++){
            ans = (ans + solve(s,idx+1,tight&&(dig==lim),cnt+dig,min_sum,max_sum))%mod;
        }

        if(!tight) dp[idx][cnt]=ans%mod;
        return ans%mod;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int a = solve(num2,0,true,0,min_sum,max_sum);
        memset(dp,-1,sizeof(dp));
        int b = solve(num1,0,true,0,min_sum,max_sum);

        int sum1=0;
        for(char c:num1) sum1+= (c-'0');
        int ans = (a - b + mod) % mod;
        if(sum1>=min_sum && sum1<=max_sum) return (ans+1)%mod;
        return ans;
    }
};