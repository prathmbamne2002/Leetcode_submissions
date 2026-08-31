class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0,r= sqrt(c)+1;
        while(l<=r){
            long long  sum= 1ll*l*l + 1LL*r*r;
            if( sum == c){
                return true;
            }
            else if(sum<c){
                l++;
            }
            else{

                r--;
            }
        }

        return false;
    }
};