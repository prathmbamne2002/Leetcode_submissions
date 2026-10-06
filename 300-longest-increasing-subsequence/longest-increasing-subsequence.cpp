class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;

        for(int i : nums){
            auto it = lower_bound(st.begin(), st.end(), i);

            if(it != st.end()){
                *it = i;
            }
            else{
                st.push_back(i);
            }
        }

        return st.size();
    }
};