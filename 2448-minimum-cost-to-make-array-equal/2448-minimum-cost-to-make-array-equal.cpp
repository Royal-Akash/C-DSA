// class Solution {
// public:
//     long long minCost(vector<int>& nums, vector<int>& cost) {
        
//         long long int n = nums.size();
//         vector<pair<int, int>>v;
//         for(int i=0;i<nums.size();i++){
//             v.push_back({nums[i], cost[i]});
//         }
//         sort(v.begin(), v.end());
//         long long sum = 0;
//         for(int i=0;i<nums.size();i++){
//             sum+=1ll*v[i].second;
//         }
//         int no = (sum+1)/2;
//         sum=0;
//         long long median = 0;
//         for(int i=0;i<n;i++){
            
//             if(sum<no){
//                 median = v[i].first;
//                 sum+=1ll*v[i].second;
//             }
            
//         }
//         long long ans = 0;
        
//         for(int i=0;i<n;i++){
//             ans+= abs(1ll*nums[i]-median)*(1LL*cost[i]);
//         }
//         return ans;
//     }
// };
class Solution {
public:

    long long calc(vector<int>&nums, vector<int>& cost, long long median){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median;
        int i=0;

        while(tot < (sum+1)/2 && i<n){

             tot += 1ll*vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        
        return calc(nums,cost,median);
    }
};