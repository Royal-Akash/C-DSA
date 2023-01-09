class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        for(int i=0;i<points.size();i++){
            double x1 = points[i][0] , y1 = points[i][1];
            unordered_map<double , int>mp;
            for(int j=0;j<points.size();j++){
                double x2 = points[j][0] , y2 = points[j][1];
                double slope;
                if(x1==x2 && y2 ==y1) continue;
                
                if((x2-x1)==0) slope = INT_MAX;
                else{
                    slope = (y2-y1)/(x2-x1);
                }
                mp[slope]++;       
                ans=max(ans , mp[slope]);
            }
        }
        return ans+1;
    }
};