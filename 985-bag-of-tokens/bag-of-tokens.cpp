class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int l = 0, r = n - 1;
        int score = 0;
        int ans = 0;

        while (l <= r) {

            
            if (tokens[l] <= power) {
                power -= tokens[l];
                l++;
                score++;
                ans = max(ans, score);
            }

           
            else if (score > 0 && l < r) {
                power += tokens[r];
                r--;
                score--;
            }

            else {
                break;
            }
        }

        return ans;
    }
};