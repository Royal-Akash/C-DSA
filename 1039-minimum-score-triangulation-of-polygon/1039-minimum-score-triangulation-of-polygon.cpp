class Solution {
public:
    int dp[1001][1001];
    int findsoln(vector<int>& values , int i , int j){
        
        if(i>=j){return 0;}
        if(dp[i][j]!=-1) {return dp[i][j];}
        
        // dp[i][j]=INT_MAX;
        int count = INT_MAX;
        for(int k=i;k<=j-1;k++){
            
            // dp[i][j] = min(dp[i][j] , findsoln(values , i , k)+findsoln(values , k+1 , j)+
            //     values[i-1]*values[k]*values[j]);
            
            // count=min(count , temp);
            
            int temp = findsoln(values , i , k)+findsoln(values , k+1 , j)+
                values[i-1]*values[k]*values[j];
            count=min(count , temp);

        }
        dp[i][j]=count;
        return dp[i][j];
    }
    
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        // int i=0 , j=n-1;
        memset(dp , -1 , sizeof(dp));
        return findsoln(values , 1 , n-1);
        
    }
};