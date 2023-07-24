class Solution {
public:
    string getPermutation(int n, int k) {
        string v;
        for(int i=1;i<=n;i++){
            v+=to_string(i);
        }
        for(int i=1;i<k;i++){
            next_permutation(v.begin(), v.end());
        }
        return v;
    }
};