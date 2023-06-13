class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        // int m - grid[0].size();
        
        int count=0;
        for(int i=0;i<n;i++){
            vector<int>v1(grid[i].begin(), grid[i].end());
            for(int j=0;j<n;j++){
                vector<int>v2;
                for(int k=0;k<n;k++){
                    v2.push_back(grid[k][j]);
                }
                if(v1==v2){
                    count++;
                }
            }
        }
        return count;
        
    }
};