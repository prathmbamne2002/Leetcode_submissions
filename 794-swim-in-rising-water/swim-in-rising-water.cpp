class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};

    bool isvalid(int r,int c,int n){
        if((r>=0 &&r<n)&&(c>=0 && c<n)) return true;
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=1;

        while(!pq.empty()){
            auto it = pq.top();
            int elevation  = it[0];
            int r = it[1];
            int c = it[2];
            pq.pop();

            if(r==n-1 && c==n-1) return elevation;

            for(int i=0;i<4;i++){
                int newrow = r + dx[i];
                int newcol = c + dy[i];

                if(isvalid(newrow,newcol,n) && !vis[newrow][newcol]){
                    vis[newrow][newcol]=1;
                    pq.push({max(elevation,grid[newrow][newcol]),newrow,newcol});
                }
            }
        }
        return 0;
    }
};