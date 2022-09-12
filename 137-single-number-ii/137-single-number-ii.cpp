class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unsigned int shift=1 , ans=0;
        for(int i=0;i<32;i++){
            int count =0;
            for(auto it:nums){
                if(it&shift){
                    count++;
                }
            }
            if(count%3!=0){
                ans+=shift;
            }
            shift<<=1;
        }
        return ans;
//         unsigned int ans=0,shift=1;
//         for(int i=0;i<32;++i)
//         {
//             int count=0;
//             for(auto ele: nums)
//             {
//                 if(ele & shift)
//                     count+=1;
//             }
//             if(count%3 != 0)
//                 ans += shift;
//             shift*=2;
            
//         }
//         return ans;
    }
};