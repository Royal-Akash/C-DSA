class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>left , right(n , 0);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
            left.push_back(ans);
        }
        ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=nums[i];
            right[i]=ans;
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;
        
    }
};


// int n = nums.size();
//         int i = 0;
//         int j = n-1;
//         int left=nums[0] , right=nums[n-1];
//         while(i<j){
            
//             if(left>right){
//                 j--;
//                 right+=nums[j];
//             }
//             else if(right>left){
//                 i++;
//                 left+=nums[i];
//             }
//             else if(right==left && i+1!=j){
//                 return i+1;
//             }
//             else{
//                 break;
//             }
//         }
//         return -1;