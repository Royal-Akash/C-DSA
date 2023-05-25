class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        // vector<int>temp = intervals[0];
        // if(n<=1){
        //     return intervals;
        // }
        // for(int i=1;i<n;i++){
        //     if(temp[1]>=intervals[i][0]){
        //         temp[1]=max(temp[1], intervals[i][1]);
        //     }
        //     else{
        //         ans.push_back(temp);
        //         temp=intervals[i];
        //     }
        // }
        // ans.push_back(temp);
        // return ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};