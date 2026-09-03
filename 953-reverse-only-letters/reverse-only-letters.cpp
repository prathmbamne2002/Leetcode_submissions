class Solution {
public:
    bool isLetter(char c){
        if((c>='A'&& c<='Z')||(c>='a'&& c<='z')) return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        int n = s.size();
        int l=0,r=n-1;
        while(l<=r){
            if((!isLetter(s[l])) && (!isLetter(s[r]))){
                l++;
                r--;
            }
            else if(!isLetter(s[l])) l++;
            else if(!isLetter(s[r])) r--;
            else{
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};