class Solution {
public:
    int n,m;
    vector<vector<int>>prefixsum(vector<vector<int>>& mat){
        vector<vector<int>>prefix(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = mat[i][j];
                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        return prefix; 
    }

    int check(int mid,vector<vector<int>>&prefix){
        vector<pair<int,int>>rows,cols;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int r2 = i-mid+1;
                int c2 = j-mid+1;

                if (r2 < 0 || c2 < 0) continue; 

                int sum = prefix[i][j];
                if(r2-1>=0)  sum -= prefix[r2-1][j];
                if(c2-1>=0)  sum -= prefix[i][c2-1];
                if(r2-1>=0 && c2-1>=0) sum += prefix[r2-1][c2-1];

                if(sum == mid * mid){
                    rows.push_back({r2,i});
                    cols.push_back({c2,j});
                }
            }
        }

        sort(rows.begin(),rows.end(),[](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        sort(cols.begin(),cols.end(),[](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        
        if(rows.size() >= 2){
            if(rows.back().first > rows.front().second || cols.back().first > cols.front().second){
                return 1;
            }
        }

        return 0;
    }

    int maxArea(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>>prefix =  prefixsum(mat);

        int lo=1;           
        int hi=min(n,m);    
        int ans=0;          

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,prefix)){
                ans = mid;
                lo = mid +1;
            }
            else{
                hi = mid -1;
            }
        }

        return ans*ans;
    }
};