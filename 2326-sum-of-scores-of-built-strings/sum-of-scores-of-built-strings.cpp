class Solution {
public:
    void constructlps(string& s, vector<int>& lps) {
        int n = s.size();
        int len = 0;
        int i = 1;

        lps[0] = 0;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    long long sumScores(string s) {
        int n = s.size();
        vector<int>lps(n,0),lps1(n,0);
        constructlps(s,lps);
        long long res=n;
        vector<int>dp(n,0);
        for (int i = 1; i < n; i++) {
            dp[i] = lps[i] == 0 ? 0: dp[lps[i] - 1] + 1;
            res += dp[i];
        }

        return res;

        // // reverse(s.begin(),s.end());
        // // constructlps(s,lps1);
        // for(int i:lps) cout<<i<<" ";
        // cout<<endl;
        // for(int i:lps1) cout<<i<<" ";
        // cout<<endl;
        // return 0;
    }
};