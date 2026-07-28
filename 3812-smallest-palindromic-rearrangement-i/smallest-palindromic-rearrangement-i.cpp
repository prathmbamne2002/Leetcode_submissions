class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        multiset<char>st;
        for(int i=0;i<n/2;i++){
            st.insert(s[i]);
        }

        vector<char>a(n);
        if(n%2!=0){
            a[n/2]= s[n/2];
        }

        for(int i=0;i<n/2;i++){
            auto it = *(st.begin());
            a[i]= it;
            a[n-1-i]=it;
            st.erase(st.begin());
        }

        string ans="";
        for(char c:a) ans+=c;

        return ans;
    }
};