class Solution {
public:
    string s;
    long long dp[65][65];
    int stepx;

    long long solve(int idx,bool tight,int cnt){
        if(idx==(int)s.size()) return cnt;

        if(!tight && dp[idx][cnt]!=-1) return dp[idx][cnt];

        int lim = tight ? (s[idx]-'0') :1;

        long long ans = 0;

        for(int dig=0;dig<=lim;dig++){
            int posright = (int)s.size()-idx;
            bool add = ((dig==1)&&(posright%stepx==0));
            ans += solve(idx+1,tight&&(dig==lim),cnt+add);
        }

        if(!tight) dp[idx][cnt] = ans;
        return ans;
    }

    long long countbits(long long n){
        s = "";
        for (int i = 62; i >= 0; i--) {
            if ((n >> i) & 1) {
                while (i >= 0) {
                    s += ((n >> i) & 1) ? '1' : '0';
                    i--;
                }
                break;
            }
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,true,0);
    }

    long long findMaximumNumber(long long k, int x) {
        stepx = x;
        long long lo=1,hi=1e16;
        long long ans = lo;

        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(countbits(mid)<=k){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }


        return ans;
    }
};