class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
//         int n = rocks.size();
//         int count=0;
//         for(int i=0;i<n;i++){
            
//             int needRocks = capacity[i]-rocks[i];
//             if(needRocks==0){
//                 count++;
//             }
//             else if(needRocks>0 && additionalRocks>=needRocks){
//                 additionalRocks-=needRocks;
//                 count++;
//             }
//             else{
//                 continue;
//             }
            
//         }
//         return count;
        
        int n = rocks.size();
        vector<int>store;
        for(int i=0;i<n;i++){
            store.push_back(capacity[i]-rocks[i]);
        }
        sort(store.begin() , store.end());
        int ans=-1;
        for(int i=0;i<n;i++){
            if(store[i]>0 && additionalRocks>=store[i]){
                additionalRocks-=store[i];
                ans=i;
            }
        }
        // if(ans=-1) return 0;
        
        return ans+1;
    }
};