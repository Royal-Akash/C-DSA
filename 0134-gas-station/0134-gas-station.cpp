class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int gassum=accumulate(gas.begin() , gas.end() ,0);
        int costsum=accumulate(cost.begin() , cost.end() ,0);
        
        if(costsum>gassum) return -1;
        int curr=0 , ans=0;
        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        return ans;
    }
};