class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return isPalindrome(s.substr(l, r - l)) ||isPalindrome(s.substr(l + 1, r - l));
            }
        }

        return true;
    }
};