#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>matrix(m , vector<int> (n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                unordered_set<int> st;
                int x = i, y = j;
                while(x<=m-2 && y<=n-2){
                    x=x+1, y=y+1;
                    st.insert(grid[x][y]);
                    
                }
                int left = st.size();
                st.clear();
                x=i, y=j;
                while(x>=1 && y>=1){
                    x--, y--;
                    st.insert(grid[x][y]);
                    
                }
                int right = st.size();
                matrix[i][j]=abs(left-right);
            }
        }
        return matrix;
        
    }
};