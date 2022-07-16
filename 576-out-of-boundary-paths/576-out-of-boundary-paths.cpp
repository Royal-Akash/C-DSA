
class Solution {
    vector<vector<int>> dist = {{-1,0},{1,0},{0,-1},{0,1}};
    int dp[51][51][51];
    int mod = 1e9+7;

     long int utilfunc(int i,int j,int m,int n,int move)
    { 
       if((i<0 || j<0 || i >= m || j >= n))
          return 1;
       
       if(move<=0)
          return 0;
      
       if(dp[move][i][j] != -1)
          return dp[move][i][j];
		  
       long int count = 0;
        
       for(int x=0;x<4;x++)
       {
           count += utilfunc(i+dist[x][0],j+dist[x][1],m,n,move-1)%mod;
       }    
       return dp[move][i][j]  = count%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        for(int i=0;i<51;i++)
        {
            for(int j=0;j<51;j++)
            {
               for(int k=0;k<51;k++)
               {
                 dp[i][j][k] = -1;
			   }
            }
        }
        long int ans =  utilfunc(startRow,startColumn,m,n,maxMove);    
        return  ans;
    }
};
