class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int &cnt,int &edgecnt){
        vis[node]=1;
        cnt++;
        edgecnt+= adj[node].size();

        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis,cnt,edgecnt);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }

        vector<int>vis(n,0);
        int components=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt=0;
                int edgecnt=0;
                dfs(i,adj,vis,cnt,edgecnt);

                if(cnt*(cnt-1)==edgecnt) components++;
            }
        }

        return components;
    }
};