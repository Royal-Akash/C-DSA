class Solution {
public:
    int check(string num, int start, int end){
        bool d2 = false;
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            
            int sum = num[i]-'0';
            if(sum==end && d2==false){
                d2=true;
            }
            else if(sum==start && d2==true){
                return n-i-2;
            }
        }
        return n;
        
    }
    int minimumOperations(string num) {
        
        int n = num.size();
        int ans = INT_MAX;
        ans = min (ans, check(num, 0, 0));
        ans = min (ans, check(num, 2, 5));
        ans = min (ans, check(num, 5, 0));
        ans = min (ans, check(num, 7, 5));
        
        int count0 = 0;
        for(int i=0;i<n;i++){
            int sum = num[i]-'0';
            if(sum==0){
                count0++;
            }
        }
        
        return min(ans, n-count0);
        
    }
};