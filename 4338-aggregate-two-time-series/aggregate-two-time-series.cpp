class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n=series1.size();
        int m=series2.size();
        vector<vector<int>>ans;
        int p1=0,p2=0;
        while(p1<n && p2<m){
            if(series1[p1][0]==series2[p2][0]){
                ans.push_back({series1[p1][0],series1[p1][1]+series2[p2][1]});
                p1++;
                p2++;
            }
            else if(series1[p1][0]>series2[p2][0]){
                ans.push_back({series2[p2][0],series2[p2][1]+series1[p1][1]});
                p2++;
            }
            else{
                ans.push_back({series1[p1][0],series2[p2][1]+series1[p1][1]});
                p1++;
            }
        }

        if(p1<n){
            while(p1<n){
                ans.push_back({series1[p1][0],series1[p1][1]});
                p1++;
            }
        }
        else if(p2<m){
            while(p2<m){
                ans.push_back({series2[p2][0],series2[p2][1]});
                p2++;
            }
        }

        return ans;
    }
};