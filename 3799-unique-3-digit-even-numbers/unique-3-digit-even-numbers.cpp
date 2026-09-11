class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>arr(10,0);

        for(int i:digits) arr[i]++;

        int ans = 0;

        for(int i=0;i<10;i++){
            if(i%2==0 && arr[i]>0){

                
                arr[i]--;

                int cnt_unique = 0;
                int cnt_double = 0;

                for(int j=1;j<10;j++){
                    if(arr[j]>0) cnt_unique++;
                }

                for(int j=0;j<10;j++){
                    if(arr[j]>0) cnt_double++;
                }

                
                int unique_contri = 0;

                for(int j=1;j<10;j++){
                    if(arr[j]>0){
                        unique_contri += cnt_double - (arr[j]>0);
                    }
                }

                
                for(int j=1;j<10;j++){
                    if(arr[j]>1){
                        ans++;
                    }
                }

                ans += unique_contri;

                arr[i]++;
            }
        }

        return ans;
    }
};