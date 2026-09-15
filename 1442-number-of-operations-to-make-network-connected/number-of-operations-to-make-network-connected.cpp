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

    bool Union(int a,int b){
        a = findParent(a);
        b = findParent(b);

        if(a==b) return false;

        if(size[b]>size[a]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];

        return true;
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        init(n);
        int reduntant = 0;
        for(auto it:connections){
            if(!Union(it[0],it[1])){
              reduntant++;
            }
        }

        set<int>st;
        for(int i=0;i<n;i++) st.insert(findParent(i));
        int components = st.size();

        // cout<<reduntant<<" "<<components<<endl;

        if(reduntant>=components-1) return components-1;

        return -1;
    }
};