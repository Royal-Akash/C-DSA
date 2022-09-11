class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        long int dd = abs(dividend) , dv = abs(divisor);
        
        long int res=0;
        while(dv<=dd){
            
            long int sum=dv , count=1;
            while((sum<<1)<=dd){
                sum<<=1;
                count<<=1;
            }
            res+=count;
            dd-=sum;
        }
        
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) return -res;
        
            return res;
    }
};