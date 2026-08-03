class Solution {
public:
    int n;
    int dp[50010];
    int recurr(int level,vector<int>&stones){
        if(level>=n) return 0;

        if(dp[level]!=INT_MIN) return dp[level];

        int ans=INT_MIN;

        ans=max(ans,stones[level]-recurr(level+1,stones));
        if(level+1<n){
            ans=max(ans,stones[level]+stones[level+1]-recurr(level+2,stones));
        }
        if(level+2<n){
            ans=max(ans,stones[level]+stones[level+1]+stones[level+2]-recurr(level+3,stones));
        }

        return dp[level]=ans;
    }

    string stoneGameIII(vector<int>& stones) {
        n=stones.size();
        for(int i=0;i<50010;i++) dp[i]=INT_MIN;
        int diff=recurr(0,stones);

        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        
        return "Tie";
    }
};