class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>ans;
        
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                
                ans.push(matrix[i][j]);
                if(ans.size()>k) ans.pop();
            }
            
        }
        // sort(ans.begin() ,ans.end());
        return ans.top();
        
    }
};