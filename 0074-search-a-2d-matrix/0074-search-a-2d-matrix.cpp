class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        if(target>=matrix[0][0] & target<=matrix[n-1][m-1]){
            
            for(int i=0;i<n;i++){
            
                if(matrix[i][m-1]>=target){
                    for(int j=0;j<m;j++){
                        if(matrix[i][j]==target){
                            return true;
                        }
                    }
                }
                
            }
        }
        else{
            return false;
        }
        
        return false;
    }
};