class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> indices (heights);
        sort(indices.begin(), indices.end());
        int count=0;
        
        for(int i=0;i<heights.size();i++){
            
            if(indices[i]!=heights[i]){
                count++;
            }
        }
        return count;
    }
};