class Solution {
public:
    void constructlps(string &s,vector<int>&lps){
        int n = s.size();
        int len=0;
        lps[0]=0;
        int i =1;
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
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int>lps(m,0);

        constructlps(needle,lps);

        int i=0;
        int j=0;

        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;

                if(j==m){
                    return (i-j);
                }
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return -1;
    }
};