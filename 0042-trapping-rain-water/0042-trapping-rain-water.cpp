class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int maxleft = 0, maxright=0;
        int count = 0;
        int left = 0 , right = n-1;
        while(left<=right){
            
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else{
                    cout<<maxleft-height[left]<<";"<<endl;
                    count+=maxleft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxright) maxright = height[right];
                else{
                    cout<<maxright-height[right]<<"''"<<endl;
                    count+=maxright-height[right];
                }
                right--;
            }
            
        }
        return count;
        
    }
};