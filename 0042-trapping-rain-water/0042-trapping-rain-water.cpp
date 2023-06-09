class Solution {
public:
    int trap(vector<int>& height) {
        
//         int n = height.size();
//         int maxleft = 0, maxright=0;
//         int count = 0;
//         int left = 0 , right = n-1;
//         while(left<=right){
            
//             if(height[left]<=height[right]){
//                 if(height[left]>=maxleft) maxleft=height[left];
//                 else{
//                     cout<<maxleft-height[left]<<";"<<endl;
//                     count+=maxleft-height[left];
//                 }
//                 left++;
//             }
//             else{
//                 if(height[right]>=maxright) maxright = height[right];
//                 else{
//                     cout<<maxright-height[right]<<"''"<<endl;
//                     count+=maxright-height[right];
//                 }
//                 right--;
//             }
            
//         }
//         return count;
        int n = height.size();
        vector<int>mini(n), maxi(n);
        int sum =0;
        mini[0]=height[0];
        maxi[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            mini[i]=max(mini[i-1], height[i]);
        }
        for(int j=n-2;j>=0;j--){
            maxi[j]=max(maxi[j+1], height[j]);
        }
        for(int i=0;i<n;i++){
            sum+=min(mini[i], maxi[i])-height[i];
        }
        return sum;
        
    }
};