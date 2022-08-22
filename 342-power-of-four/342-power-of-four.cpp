class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0) return false;
        // if(n==1) return true;
        
        float val = log(n)/log(4);
        if(val==ceil(val)) return true;
        
        return false;
        
    }
};