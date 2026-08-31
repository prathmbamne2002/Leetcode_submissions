class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        long long z = stoll(s);
        if(z<=n || z>INT_MAX) return -1;
        
        return z;
    }
};