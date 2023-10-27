class Solution {
public:
    int integerBreak(int n) {
        
        if(n<=3) return n-1;
        else if(n%3==0){
            int p = n/3;
            int ans = pow(3, p);
            return ans;
        }
        else if(n%3==1){
            int p =(n/3)-1;
            int ans = pow(3, p);
            return ans*4;
        }
        else if(n%3==2){
            int p =(n/3);
            int ans = pow(3, p);
            return ans*2;
        }
        return 0;
    }
};