class Solution {
    private:
    
    int count_land(vector<vector<int>>& grid , int i , int j , int &count){
            
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
            
            if(grid[i][j]==0) return 0;
            
            grid[i][j]=0;
            
            if(count_land(grid , i-1 , j , count)) count++;
            if(count_land(grid , i+1 , j , count)) count++;
            if(count_land(grid , i , j-1 , count)) count++;
            if(count_land(grid , i , j+1 , count)) count++;
            
            return 1;
        }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    int count=1;
                    count_land(grid , i , j , count);
                    maxi = max(maxi , count);
                }
                
            }
            
        }
        
        
        return maxi;
    }
};