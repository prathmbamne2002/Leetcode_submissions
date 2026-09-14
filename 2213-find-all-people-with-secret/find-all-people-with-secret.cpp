class Solution {
public:
    static const int M = 100005;
    int size[M];
    int par[M];
    
    void init(int n){
        for(int i=0;i<n;i++){
            size[i]=1;
            par[i]=i;
        }
    }

    int findparent(int u){
        if(u==par[u]) return u;
        return par[u]=findparent(par[u]);
    }

    void Union(int a,int b){
        a = findparent(a);
        b = findparent(b);

        if(a==b) return;

        if(size[b]>size[a]) swap(a,b);

        par[b]=a;
        size[a]+=size[b];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        init(n);

        sort(meetings.begin(),meetings.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });

        Union(0,firstPerson);

        int i=0;

        while(i<meetings.size()){

            int j=i;
            vector<int> people;

            
            while(j<meetings.size() && meetings[j][2]==meetings[i][2]){

                int u = meetings[j][0];   
                int v = meetings[j][1];   

                Union(u,v);

                people.push_back(u);
                people.push_back(v);

                j++;
            }

            
            for(int p:people){
                if(findparent(p)!=findparent(0)){
                    par[p]=p;
                    size[p]=1;
                }
            }

            i=j;
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(findparent(i)==findparent(0))
                ans.push_back(i);
        }

        return ans;
    }
};