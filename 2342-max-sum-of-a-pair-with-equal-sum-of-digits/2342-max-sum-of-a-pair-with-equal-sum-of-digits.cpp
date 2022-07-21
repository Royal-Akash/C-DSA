class Solution {
  
public:
    
    int digit(int val){
        int n=0 ;
        
        while(val){
            n+=(val%10);
            val/=10;
        }
        return n;
    }
    
    int maximumSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end() , greater<int>());
        int n = nums.size();
        map<int , vector<int>> mp;
        
        
        for(int i=0;i<n;i++){
            
            int temp = digit(nums[i]);
            mp[temp].push_back(nums[i]);
            
        }
        int maxi = -1;
        
        for(auto& it:mp){
            
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second.size()<=1) continue;
            else{
                
            vector<int> temp = it.second;
            maxi = max(maxi , temp[0] + temp[1]);
            cout<<maxi<<" "<<endl;
                
            }
            
        }

        
        return maxi;
    }
};