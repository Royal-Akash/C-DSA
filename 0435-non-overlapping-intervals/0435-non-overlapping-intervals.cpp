class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        int k = intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(k>intervals[i][0]){
                count++;
            }
            else{
                k=intervals[i][1];
            }
        }
        return count;
    }
};