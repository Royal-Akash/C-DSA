class Solution {
public:
    
//     long long int find(int n){
        
//         if(n==0){
//             return 1;
//         }
//         return n*find(n-1);
//         // return fac;
//     }
    
    
    int uniquePaths(int m, int n) {
        
        m-- , n--;
        if(n<m){
            swap(n ,m);
        }
        
        double paths = 1.0;
        for(int i=1;i<=n;i++){
            paths = (paths*(m+i)/i);
        }
        
        return paths;
        
    }
};