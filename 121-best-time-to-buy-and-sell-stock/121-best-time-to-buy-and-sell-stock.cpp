class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         vector<int> dp;
//         for(int i=0;i<n;i++){
            
//             for(int j = i;j<n;j++){
//                 int y = prices[j]-prices[i];
//                 maxi = max(maxi , y);
//             }
            
//         }
        
//         if(maxi>0){
//             return maxi;
//         }
//         else{
//             return 0;
//         }
        
        int n = prices.size();
        int maxi = 0 , mini=INT_MAX;
        
//         for(int i=1;i<n;i++){
            
//             maxi=max(0 , maxi+=prices[i]-prices[i-1]);
//             curr=max(curr , maxi);
            
//         }
//         return curr;
        
        for(int i=0;i<n;i++){
            
            mini = min(mini , prices[i]);
            maxi = max(maxi , prices[i]-mini);
            
        }
        return maxi;
    }
};