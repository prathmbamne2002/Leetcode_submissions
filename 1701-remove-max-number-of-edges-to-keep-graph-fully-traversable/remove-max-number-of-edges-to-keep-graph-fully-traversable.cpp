class Solution {
public:
    static const int M = 100005;
    int size[2][M];
    int parent[2][M];

    // 0 for Alice
    // 1 for Bob

    void init(int n){
        for(int i=0;i<n;i++){
            size[0][i]=1;
            size[1][i]=1;
            parent[1][i]=i;
            parent[0][i]=i;
        }
    }

    int findParent(int a,int p){
        if(a == parent[p][a]) return a;
        return parent[p][a] = findParent(parent[p][a],p);
    }

    bool Union(int a,int b,int p){
        a = findParent(a,p);
        b = findParent(b,p);

        if(a==b) return false;
        if(size[p][b]>size[p][a]) swap(a,b);

        parent[p][b]=a;
        size[p][a]+=size[p][b];

        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        init(n);

        int cntAlice=0;
        int cntBob = 0;
        int ans = 0;
        
        for(auto it:edges){
            if(it[0]==3){
                bool used = false;
                if(Union(it[1]-1,it[2]-1,0)){
                    cntAlice++;
                    used = true;
                }

                if(Union(it[1]-1,it[2]-1,1)){
                    cntBob++;
                    used = true;
                }

                if(!used) ans++;
            }
        }

        for(auto it:edges){
            if(it[0]==1){
                if(Union(it[1]-1,it[2]-1,0)){
                    cntAlice++;
                }
                else ans++;
            }
        }

        for(auto it:edges){
            if(it[0]==2){
                if(Union(it[1]-1,it[2]-1,1)){
                    cntBob++;
                }
                else ans++;
            }
        }

        if(cntAlice!=n-1 || cntBob!=n-1) return -1;

        return ans;
    }
};