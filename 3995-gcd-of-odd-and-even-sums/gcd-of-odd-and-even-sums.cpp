class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        n*=2;
        int sumOdd=0;
        int sumEven=0;

        for(int i=1;i<=n;i++){
            if(i%2==0) sumEven+=i;
            else sumOdd+=i;
        }

        return gcd(sumEven,sumOdd);
    }
};