class Solution {
public:
    set<int>st;
    string s;
    int dp[10][2];

    int solve(int idx,bool tight,bool started){
        if(idx==(int)s.size()){
            return started ? 1 : 0;
        }

        if(!tight && dp[idx][started]!=-1) return dp[idx][started];

        int lim = tight ? (s[idx]-'0') : 9;

        int ans = 0;

        for(int dig=0;dig<=lim;dig++){
            bool newstarted = started ||(dig!=0);

            if(!newstarted){
                ans += solve(idx+1, tight&&(dig==lim),false);
            }
            else if(st.count(dig)){
                ans += solve(idx+1,tight&&(dig==lim),true);
            }
        }

        if(!tight) dp[idx][started] = ans;
        return ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        s = to_string(n);
        for(string str:digits){
            st.insert(str[0]-'0');
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false);
    }
};