class Solution {
public:
    static const int M = 100005;
    int size[M];
    int parent[M];

    void init(int n){
        for(int i=0;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }

    int findParent(int a){
        if(a==parent[a]) return a;
        return parent[a]=findParent(parent[a]);
    }

    void Union(int a,int b){
        a = findParent(a);
        b = findParent(b);

        if(a==b) return;

        if(size[b]>size[a]) swap(a,b);

        parent[b]=a;
        size[a]+=size[b];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        init(n);

        sort(edgeList.begin(),edgeList.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });

        vector<vector<int>> q;

        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][0],queries[i][1],queries[i][2],i});
        }

        sort(q.begin(),q.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });

        vector<bool>ans(queries.size());

        int i=-1;

        for(auto it:q){
            int a = it[0];
            int b = it[1];
            int wt = it[2];
            int idx = it[3];

            while(i+1<edgeList.size() && edgeList[i+1][2]<wt){
                i++;
                Union(edgeList[i][0],edgeList[i][1]);
            }

            a = findParent(a);
            b = findParent(b);

            if(a==b) ans[idx]=true;
            else ans[idx]=false;
        }

        return ans;
    }
};