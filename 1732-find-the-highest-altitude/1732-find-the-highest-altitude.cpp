class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            
            x+=gain[i];
            sum=max(sum, x);
            
        }
        return sum;
    }
};