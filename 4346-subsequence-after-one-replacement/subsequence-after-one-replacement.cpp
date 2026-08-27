class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.length()==1) return true;
        int n=s.size();
        int m=t.size();
        vector<int>prefix(n,1e9),suffix(n,1e9);
        int p1=0,p2=0;
        while(p1<n && p2<m){
            if(s[p1]==t[p2]){
                prefix[p1]=p2;
                p1++;
                p2++;
            }
            else{
                p2++;
            }
            //cout<<p1<<" "<<p2<<endl;
        }

        
        p1=n-1,p2=m-1;
        while(p1>=0 && p2>=0){
            if(s[p1]==t[p2]){
                suffix[p1]=p2;
                p1--;
                p2--;
            }
            else{
                p2--;
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==1e9) cnt++;
        }

        // for(int i=0;i<n;i++){
        //     cout<<prefix[i]<<" "<<suffix[i]<<endl;
        // }

        

        //if(cnt>1) return false;
        //cout<<suffix[1]<<endl;
        if(suffix[1]>0 && suffix[1]!=1e9){
            return true;
        }
        if(prefix[n-2]<m-1) return true;

        for(int i=1;i<n-1;i++){
            if((prefix[i-1]+1)<(suffix[i+1]) && prefix[i-1]!=1e9 && suffix[i+1] != 1e9){
                cout<<i<<endl;
                return true;
            }
        }

        return false;
    }
};