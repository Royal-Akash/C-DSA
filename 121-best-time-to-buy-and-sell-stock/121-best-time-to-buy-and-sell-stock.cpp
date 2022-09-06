class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxi = 0 , curr=0;
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
        
        for(int i=1;i<n;i++){
            
            maxi=max(0 , maxi+=prices[i]-prices[i-1]);
            curr=max(curr , maxi);
            
        }
        return curr;
    }
};