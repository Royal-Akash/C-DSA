class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int m = i+1;m<n;m++){
                if(m>i+1 && nums[m]==nums[m-1]) continue;
                int j = m+1;
                int k = n-1;

                while(j<k){
                    long long sum = nums[i];
                    sum+=nums[m];
                    sum+=nums[j];
                    sum+=nums[k];
                    if(sum>target){
                        k--;
                    }
                    else if(sum<target){
                        j++;
                    }
                    else if(sum==target){
                        vector<int>temp = {nums[i], nums[m], nums[j], nums[k]};
                        // j++, k--;
                        ans.push_back(temp);
                        while(j<k && nums[j]==nums[j+1]) j++ ;
                        while(j<k && nums[k]==nums[k-1]) k-- ;
                        j++, k--;
                    }
                }
            }
            
        }
        return ans;
        
    }
};