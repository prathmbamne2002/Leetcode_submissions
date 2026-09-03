class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>>ans = image;
        int n = ans.size();
        int m = ans[0].size();
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<=r){
                //cout<<ans[i][l]<<" "<<ans[i][r]<<endl;
                swap(ans[i][l],ans[i][r]);
                //cout<<ans[i][l]<<" "<<ans[i][r]<<endl;
                if(l==r){
                    ans[i][l] = (ans[i][l]^1);
                }
                else{
                    ans[i][l] = (ans[i][l]^1);
                    ans[i][r] = (ans[i][r]^1);
                }
                
                //cout<<(ans[i][l]^1)<<endl;
                //cout<<ans[i][l]<<" "<<ans[i][r]<<endl;
                //cout<<endl;
                l++;
                r--;
            }
        }

        return ans;

    }
};