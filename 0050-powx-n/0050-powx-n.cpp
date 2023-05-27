class Solution {
public:
    double myPow(double x, int n) {
        
        long long dn = n;
        if(dn<0) dn= -1*dn;
        double ans = 1.0;
        while(dn>0){
            
            if(dn%2==1){
                ans = ans * x;
                dn = dn-1;
            }
            else{
                x = x * x;
                dn = dn/2;
            }
        }
        if(n<0) ans = (double)1.0/(double)ans;
        return ans;
        
    }
};