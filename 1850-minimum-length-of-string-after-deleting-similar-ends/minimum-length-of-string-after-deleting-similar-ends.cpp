class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                break;
            }
            while(s[r]==s[l] && r>l){
                r--;
            }
            if(r==l) return 0;
            while(s[l]==s[l+1]){
                l++;
            }
            l++;
            //if(l>r) return 0;
        }

        return max(0,r-l+1);
    }
};