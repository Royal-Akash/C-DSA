class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
//         vector<int> ans;
//         int row=matrix.size();
//         int col=matrix[0].size();
        
//         int startingRow=0;
//         int startingCol=0;
//         int endingRow=row-1;
//         int endingCol=col-1;
//         int count=0;
        
//         int total=row*col;
        
//         for(int j=startingRow; j<=endingRow;j++){
            
//             for(int i=endingCol; i>=startingCol; i--){
//                 ans.push_back(matrix[i][j]);
//                 swap(matrix[i][j], matrix[j][i]);
                
//             }
//             endingCol--;
            
//             for(int i=startingRow; i<=endingRow; i++){
//                 ans.push_back(matrix[startingRow][i]);
//                 count++;
//             }
//             startingRow++;
//         }
        
        
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(auto &it: matrix){
            reverse(it.begin(),it.end());
        }
    }
};