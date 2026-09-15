class Solution {
public:

    static const int M = 1000005;
    int size[M];
    int parent[M];

    int n;

    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};

    void init(int n){
        for(int i=0;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }

    int findParent(int a){
        if(a==parent[a]) return a;
        return parent[a] = findParent(parent[a]);
    }

    void Union(int a,int b){
        a = findParent(a);
        b = findParent(b);

        if(a==b) return;

        if(size[b]>size[a]) swap(a,b);

        parent[b]=a;
        size[a]+=size[b];
    }

    bool isvalid(int i,int j){
        if((i>=0 && i<n) && (j>=0 && j<n)) return true;
        return false;
    }

    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int newrow = i + dx[k];
            int newcol = j + dy[k];

            if(isvalid(newrow,newcol) && 
               grid[newrow][newcol]==1 && 
               !vis[newrow][newcol]){
                
                Union(i*n+j,newrow*n+newcol);
                dfs(newrow,newcol,grid,vis);
            }
        }
    }

    void findinitialIsland(vector<vector<int>>&grid){
        vector<vector<int>>vis(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        init(n*n);

        findinitialIsland(grid);

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0){

                    set<int>components;

                    for(int k=0;k<4;k++){
                        int newrow = i + dx[k];
                        int newcol = j + dy[k];

                        if(isvalid(newrow,newcol) && 
                           grid[newrow][newcol]==1){

                            components.insert(
                                findParent(newrow*n+newcol)
                            );
                        }
                    }

                    int sz = 0;

                    for(auto it:components){
                        sz += size[it];
                    }

                    ans = max(ans,sz+1);
                }
            }
        }

        for(int i=0;i<n*n;i++){
            ans = max(ans,size[findParent(i)]);
        }

        return ans;
    }
};