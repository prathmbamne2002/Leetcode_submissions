class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l=0,r=-1;
        vector<int>freq(n+1,0),freq1(n+1,0);
        int unique=0;
        int subArrayLessOrEqual=0;
        while(l<n){
            while(r+1<n && (freq[nums[r+1]]!=0 || (freq[nums[r+1]]==0 && unique+1<=k))){
                r++;
                if(freq[nums[r]]==0) unique++;
                freq[nums[r]]++;
               
            }

            subArrayLessOrEqual += (r-l+1);

            if(r<l){
                l++;
                r=l-1;
            }
            else{
                freq[nums[l]]--;
                if(freq[nums[l]]==0) unique--;
                l++;
            }

        }

        l=0,r=-1;
        unique = 0;
        int subArrayLess=0;

         while(l<n){
            while(r+1<n && (freq1[nums[r+1]]!=0 || (freq1[nums[r+1]]==0 && unique+1<k))){
                r++;
                if(freq1[nums[r]]==0) unique++;
                freq1[nums[r]]++;
               
            }

            subArrayLess += (r-l+1);

            if(r<l){
                l++;
                r=l-1;
            }
            else{
                freq1[nums[l]]--;
                if(freq1[nums[l]]==0) unique--;
                l++;
            }

        }

        return subArrayLessOrEqual - subArrayLess;

        
    }
};