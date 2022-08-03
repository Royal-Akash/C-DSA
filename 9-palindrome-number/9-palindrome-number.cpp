class Solution {
public:
    bool isPalindrome(int x) {
        
        long long int val =0 , t=x;
        if(x<0) return false;
        while(t!=0){
            
            val = val*10 + t%10;
            t=t/10;
            
        }
        return x==val;
    }
};