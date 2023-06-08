class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size()-1;
        int m = grid[0].size();
        
        int count = 0, row = 0;
        while(n>=0 && row<m){
            
            if(grid[n][row]<0){
                count+=m-row;
                n--;
            }
            else{
                row++;
            }
            
        }
        return count;
        
    }
};