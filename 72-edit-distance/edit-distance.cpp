class Solution {
public:
    int recurr(int i,int j,string & word1,string &word2,vector<vector<int>>&dp){
        if(word1.size()==0) return word2.size();
        if(word2.size()==0) return word1.size();
        if(i== word1.size()) return  word2.size()-j;
        if(j==word2.size()) return word1.size()-i;

        if(dp[i][j]!= -1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=recurr(i+1,j+1,word1,word2,dp);
        }
        else{
            return dp[i][j]=1+min({recurr(i+1,j,word1,word2,dp),recurr(i,j+1,word1,word2,dp),recurr(i+1,j+1,word1,word2,dp)});
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recurr(0,0,word1,word2,dp);
    }
};