class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                x++;
            }
        }
        if(x==nums.size()) return "0";
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                string x = to_string(nums[i]) + to_string(nums[j]);
                string y = to_string(nums[j]) + to_string(nums[i]);
                
                if(y>x){
                    swap(nums[i] , nums[j]);
                }
                
            }
        }
        string str;
        for(int i=0;i<n;i++){
            str+=to_string(nums[i]);
        }
            return str;
    }
};