class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
        
        int n = co.size();
        if(n==2) return true;
        int x1 = co[0][0];
        int y1 = co[0][1];
        int x2 = co[1][0];
        int y2 = co[1][1];
        for(int i=2;i<n;i++){
            int x3 = co[i][0], y3 = co[i][1];
            if((y3 - y1) * (x3 - x2) != (y3 - y2) * (x3 - x1)){
                return false;
            } 
        }
        return true;
        
    }
};