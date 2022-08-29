class Solution {
    int find(vector<int>& nums , int k , int j){
        
        if((j-k)==1) return nums[k];
        int prev = nums[k];
        int prev2=0;
        for(int i=k+1;i<j;i++){
            
            int pick = nums[i];
            if(i>k+1){
                pick+=prev2;
            }
            int nopick= prev;
            int curr = max(pick , nopick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        int num1 = find(nums , 0 , n-1);
        int num2 = find(nums, 1 , n);
        cout<<num1<<" "<<num2<<endl;
        return max(num1 , num2);
        
        
    }
};

// int robhelp(int start,int end,vector<int> &nums) {
//         int prev1=nums[start];
//         int prev2=0,curr;
//         int fs,ss;
//         if(end-start==1)
//             return nums[start];
//         for(int i=start+1;i<end;i++)
//         {
//            fs=nums[i];
//            if(i>start+1)
//              fs+=prev2;
//            ss=prev1;
//            curr=max(fs,ss);
//             prev2=prev1;
//             prev1=curr;
//         }
//         return curr;
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)
//             return nums[0];
//        return max(robhelp(0,n-1,nums),robhelp(1,n,nums)) ;
        
//     }
//     };