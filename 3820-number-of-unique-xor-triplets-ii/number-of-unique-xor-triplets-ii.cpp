class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       
    unordered_set<int> xor_ab, result;
    
    for (int a : nums)
        for (int b : nums)
            xor_ab.insert(a ^ b);

    for (int x : xor_ab)
        for (int c : nums)
            result.insert(x ^ c);

    return result.size();


    }
};