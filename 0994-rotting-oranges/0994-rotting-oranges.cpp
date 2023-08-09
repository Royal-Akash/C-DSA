class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>>q;
        int vis[n][m];
        int cntfresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1) cntfresh++;
                
            }
        }
        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            for(int i=0;i<4;i++){
                int dr = r+drow[i];
                int dc = c+dcol[i];
                if(dr>=0 && dr<n && dc>=0 && dc<m && grid[dr][dc]==1 && vis[dr][dc]!=2){
                    q.push({{dr, dc}, t+1});
                    vis[dr][dc]=2;
                    cnt++;
                }
            }
            
        }
        if(cntfresh!=cnt) return -1;
        return tm;
        
    }
};