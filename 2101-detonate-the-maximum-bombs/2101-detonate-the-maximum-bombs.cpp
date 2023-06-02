// class Solution {
// public:
//     int maximumDetonation(vector<vector<int>>& bombs) {
        
//         int n = bombs.size();
//         vector<vector<int>> area;
//         for(int i=0;i<n;i++){
            
//             int x1 = bombs[i][0]-bombs[i][2];
//             int x2 = bombs[i][0]+bombs[i][2];
//             int y1 = bombs[i][1]-bombs[i][2];
//             int y2 = bombs[i][1]+bombs[i][2];
//             vector<int>temp = {x1, x2, y1, y2};
            
//             area.push_back(temp);
//         }
        
//         int maxcnt = 0;
        
//         for(int i=0;i<n;i++){
//             int cnt = 0;
//             int x1 = area[i][0];
//             int x2 = area[i][1];
//             int y1 = area[i][2];
//             int y2 = area[i][3];
//             for(int j=i;j<n;j++){
                
//                 if(x1<=area[j][0] && area[j][0]<=x2) cnt++;
//                 else if(x1<=area[j][1] && area[j][1]<=x2) cnt++;
//                 else if(y1<=area[j][2] && area[j][2]<=y2) cnt++;
//                 else if(y1<=area[j][3] && area[j][3]<=y2) cnt++;
//             }
//             maxcnt= max(maxcnt, cnt);
//         }
//         return maxcnt;
//     }
// };

class Solution {
public:
    //Time Complexity O(n*n)
    //Space Complexity O(n*n)
    #define ll long long
    void dfs(int src,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;
        for(int x:adj[src]){
            if(vis[x]==0){
                dfs(x,vis,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            ll r1=bombs[i][2];
            ll x1=bombs[i][0],y1=bombs[i][1];
            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x2=bombs[j][0], y2=bombs[j][1], r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);;
                    if(dsq<=r1*r1){
                        adj[i].push_back(j); //directed edge
                    }
                }
            }
        }
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dfs(i,vis,adj); //You can also use bfs to find largest connected component
            int cnt=0;
            for(int j=0;j<n;j++) if(vis[j]==1) cnt++;
            ans=max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }
};