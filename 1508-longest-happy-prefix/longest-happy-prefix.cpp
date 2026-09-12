class Solution {
public:
    void constructlps(string& s,vector<int>&lps){
        int n = s.size();
        int len = 0;
        int i=1;
        lps[0]=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string longestPrefix(string& s) {
        int n = s.size();
        vector<int>lps(n,0);
        constructlps(s,lps);
        //int maxi=0;
        // for(int i:lps) cout<<i<<" ";
        // cout<<endl;
        // for(int i:lps) maxi = max(maxi,i);
        // cout<<maxi<<endl;

        // if(==0) return "";
        return s.substr(0,lps[n-1]);
    }
};