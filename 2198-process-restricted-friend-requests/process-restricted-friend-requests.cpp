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

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {

        init(n);  

        vector<bool> ans;

        for(auto it:requests){
            int a = findParent(it[0]);
            int b = findParent(it[1]);

            bool norestriction = true;

            for(auto r:restrictions){
                int x = findParent(r[0]);
                int y = findParent(r[1]);

                if((x==a && y==b) || (x==b && y==a)){
                    norestriction = false;
                    break;
                }
            }

            if(norestriction){
                ans.push_back(true);
                Union(a,b);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};