
class Solution {
public:
    int recurr(int start,int end,vector<int>&nums){

        if(start>end) return 0;

        int takefirst = nums[start] - recurr(start+1,end,nums);
        int takelast  = nums[end] - recurr(start,end-1,nums);

        return max(takefirst,takelast);
        
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int score = recurr(0,n-1,nums);
        if(score>=0) return true;
        else return false;
    }
};