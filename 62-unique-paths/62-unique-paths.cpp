class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
//         m-- , n--;
//         if(n<m){
//             swap(n ,m);
//         }
        
//         double paths = 1.0;
//         for(int i=1;i<=n;i++){
//             paths = paths*(m+i)/i;
//         }
        int N = n+m-2;
        int R = m-1;
        
        double path = 1;
        for(int i=1;i<=R;i++){
            
            path = path * (N-R+i)/i;
            
        }
        
        return path;
        
    }
};