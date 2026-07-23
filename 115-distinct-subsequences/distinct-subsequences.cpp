class Solution {
public:
    int recurr(int i,int j,string&s,string &t,vector<vector<int>>&dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(dp[i][j]!= -1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=recurr(i+1,j,s,t,dp)+recurr(i+1,j+1,s,t,dp);
        }
        else return dp[i][j]=recurr(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurr(0,0,s,t,dp);
    }
};