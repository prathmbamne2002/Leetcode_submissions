class Solution {
public:
    bool recurr(int i, int j, string &s, string &p,vector<vector<int>>&dp) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;

        if (i == s.size()) {
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        }

        if(dp[i][j]!= -1) return dp[i][j];

        if (p[j] == '*') {
            return dp[i][j]=recurr(i, j + 1, s, p,dp) || recurr(i + 1, j, s, p,dp);
        }

        if (p[j] == '?' || s[i] == p[j]) {
            return dp[i][j]=recurr(i + 1, j + 1, s, p,dp);
        }

        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurr(0, 0, s, p,dp);
    }
};