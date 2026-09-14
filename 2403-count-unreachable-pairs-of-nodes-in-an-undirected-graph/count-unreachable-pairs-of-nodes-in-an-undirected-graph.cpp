class Solution {
public:

    void dfs(int node,int num,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=num;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,num,adj,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,i+1,adj,vis);
            }
        }

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[vis[i]]++;

        long long ans=0;
        long long add=0;

        for(auto &[key,value]:mp){
            ans += (add*value);
            add+=value;
        }

        return ans;
    }
};