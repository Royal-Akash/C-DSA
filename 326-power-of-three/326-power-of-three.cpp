class Solution {
public:
    bool isPowerOfThree(int n) {
        
//         if(n==0) return false;
//         if(n==1) return true;
//         long double y = (log(n)/log(3));
//         cout<<y<<endl;
        
//         if(y==int(y)) return true;
//         return false;
        
        
        if(n>0){
            long long int y = pow(3 , 19);
            if(y%n==0) return true;
        }
        return false;
    }
};