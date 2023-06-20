class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k==0) return nums;
        long long sum = 0;
        if(2*k>=n || k>n){
            vector<int>ans(n, -1);
            return ans;
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(-1);
        }
        for(int i=0;i<=2*k && i<n;i++){
            sum+=nums[i];
        }
        int z = 2*k+1;
        ans.push_back(sum/z);
        int i=0, j=z;
        while(j<n){
            
            sum-=nums[i];
            sum+=nums[j];
            ans.push_back(sum/z);
            i++, j++;
        }
        for(int i=0;i<k;i++){
            ans.push_back(-1);
        }
        return ans;
    }
};