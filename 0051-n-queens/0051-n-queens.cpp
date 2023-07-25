class Solution {
public:
    void findQ(int col, int n, vector<string>&board, vector<vector<string>>&ans, vector<int>&upper, vector<int>&lower,vector<int>&curr ){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(curr[row]==0 && upper[n-1+col-row]==0 && lower[row+col]==0){
                board[row][col]='Q';
                curr[row]=1;
                upper[n-1+col-row]=1;
                lower[row+col]=1;
                findQ(col+1, n, board, ans, upper, lower, curr);
                board[row][col]='.';
                curr[row]=0;
                upper[n-1+col-row]=0;
                lower[row+col]=0;
                
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>upper(2*n-1,0), lower(2*n-1,0), curr(n,0);
        findQ(0, n, board, ans, upper, lower, curr);
        return ans;
    }
};