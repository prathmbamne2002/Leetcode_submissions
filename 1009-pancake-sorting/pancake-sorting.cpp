class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        int curr = n;
        
        for(int i=0;i<n;i++){
            int ind = -1;
            //cout<<curr<<endl;
            for(int j=0;j<n;j++){
                if(arr[j]==curr){
                    ind = j;
                }
            }
            reverse(arr.begin(),arr.begin()+ind+1);
            reverse(arr.begin(),arr.begin()+curr);
            //cout<<ind<<endl;
            ans.push_back(ind+1);
            ans.push_back(curr);
            curr--;
            //cout<<curr<<endl;
            //cout<<endl;
        }

        return ans;
    }
};