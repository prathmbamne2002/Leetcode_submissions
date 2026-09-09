class Solution {
public:
    int dp[350][10];
    int mod = 1000000007;
    int base;

    string divide(string num, int b, int& rem) {
        string quotient;
        long long cur = 0;

        for (char c : num) {
            cur = cur * 10 + (c - '0');

            if (!quotient.empty() || cur >= b) {
                quotient += char('0' + cur / b);
            }

            cur %= b;
        }

        rem = cur;

        if (quotient.empty())
            quotient = "0";

        return quotient;
    }

    string getnumwithbase(string num, int base) {
        if (num == "0")
            return "0";

        string ans;

        while (num != "0") {
            int rem;
            num = divide(num, base, rem);

            ans += char('0' + rem);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool startisnondec(string &s) {
        if (s.size() <= 1) return true;

        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] < s[i - 1]) return false;
        }

        return true;
    }

    long long solve(string& s, int idx, bool tight, bool started, int prev) {
        if (idx == (int)s.size()) {
            return started ? 1 : 0;
        }

        if (!tight && started && dp[idx][prev] != -1)
            return dp[idx][prev];

        int lim = tight ? (s[idx] - '0') : (base - 1);

        long long ans = 0;

        for (int dig = 0; dig <= lim; dig++) {
            bool newstarted = started || (dig != 0);

            if (!newstarted) {
                ans = (ans + solve(
                    s,
                    idx + 1,
                    tight && (dig == s[idx] - '0'),
                    false,
                    prev
                )) % mod;
            }
            else {
                if (!started || dig >= prev) {
                    ans = (ans + solve(
                        s,
                        idx + 1,
                        tight && (dig == s[idx] - '0'),
                        true,
                        dig
                    )) % mod;
                }
            }
        }

        if (!tight && started)
            dp[idx][prev] = ans;

        return ans;
    }

    long long calc(string& n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, true, false, 0);
    }

    int countNumbers(string l, string r, int b) {
        base = b;

        string start = getnumwithbase(l, b);
        string end = getnumwithbase(r, b);

        long long a = calc(start);
        long long c = calc(end);

        int ans = (c - a + mod) % mod;

        if (startisnondec(start))
            ans = (ans + 1) % mod;

        return ans;
    }
};