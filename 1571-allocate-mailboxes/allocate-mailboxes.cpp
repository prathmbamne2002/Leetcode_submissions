class Solution {
public:
    int cost[105][105];
    int dp[105][105];
    int n;

    int recurr(int start,int k,vector<int>&houses){
        
        if(k==0 && start==n) return 0;
        if(k==0 || start==n) return 1e9;

        if(dp[start][k]!=-1) return dp[start][k];

        int mini=1e9;

        for(int i=start;i<n;i++){
            mini=min(mini,cost[start][i]+recurr(i+1,k-1,houses));
        }

        return dp[start][k]=mini;
    }

    int minDistance(vector<int>& houses, int k) {
        n=houses.size();
        sort(houses.begin(),houses.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cost[i][j]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=i;k<=j;k++){
                    cost[i][j]+= abs(houses[(i+j)/2]-houses[k]);
                }
            }
        }

        memset(dp,-1,sizeof(dp));

        return recurr(0,k,houses);

    }
};