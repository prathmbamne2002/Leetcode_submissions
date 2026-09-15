class Solution {
public:

   int cnt=0;

   void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&bridges,vector<int>&tin,vector<int>&low){

        vis[node]=1;
        tin[node]=low[node]=cnt;
        cnt++;

        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,bridges,tin,low);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }

   }
    

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);

        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        vector<int>tin(n,0),low(n,0);

       dfs(0,-1,vis,adj,bridges,tin,low);

        return bridges;

    }
};