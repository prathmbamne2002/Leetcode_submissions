class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int>prefix(n),suffix(n);
        int l=0,r=0;
        while(l<n){
            if(skill[l]==station[r]){
                prefix[l]=r;
                l++;
                r++;
            }
            else{
                r++;
            }
        }

         l=n-1,r=m-1;
        while(l>=0){
            if(skill[l]==station[r]){
                suffix[l]=r;
                l--;
                r--;
            }
            else{
                r--;
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,suffix[i+1]-prefix[i]);
        }
        return ans;
    }
};