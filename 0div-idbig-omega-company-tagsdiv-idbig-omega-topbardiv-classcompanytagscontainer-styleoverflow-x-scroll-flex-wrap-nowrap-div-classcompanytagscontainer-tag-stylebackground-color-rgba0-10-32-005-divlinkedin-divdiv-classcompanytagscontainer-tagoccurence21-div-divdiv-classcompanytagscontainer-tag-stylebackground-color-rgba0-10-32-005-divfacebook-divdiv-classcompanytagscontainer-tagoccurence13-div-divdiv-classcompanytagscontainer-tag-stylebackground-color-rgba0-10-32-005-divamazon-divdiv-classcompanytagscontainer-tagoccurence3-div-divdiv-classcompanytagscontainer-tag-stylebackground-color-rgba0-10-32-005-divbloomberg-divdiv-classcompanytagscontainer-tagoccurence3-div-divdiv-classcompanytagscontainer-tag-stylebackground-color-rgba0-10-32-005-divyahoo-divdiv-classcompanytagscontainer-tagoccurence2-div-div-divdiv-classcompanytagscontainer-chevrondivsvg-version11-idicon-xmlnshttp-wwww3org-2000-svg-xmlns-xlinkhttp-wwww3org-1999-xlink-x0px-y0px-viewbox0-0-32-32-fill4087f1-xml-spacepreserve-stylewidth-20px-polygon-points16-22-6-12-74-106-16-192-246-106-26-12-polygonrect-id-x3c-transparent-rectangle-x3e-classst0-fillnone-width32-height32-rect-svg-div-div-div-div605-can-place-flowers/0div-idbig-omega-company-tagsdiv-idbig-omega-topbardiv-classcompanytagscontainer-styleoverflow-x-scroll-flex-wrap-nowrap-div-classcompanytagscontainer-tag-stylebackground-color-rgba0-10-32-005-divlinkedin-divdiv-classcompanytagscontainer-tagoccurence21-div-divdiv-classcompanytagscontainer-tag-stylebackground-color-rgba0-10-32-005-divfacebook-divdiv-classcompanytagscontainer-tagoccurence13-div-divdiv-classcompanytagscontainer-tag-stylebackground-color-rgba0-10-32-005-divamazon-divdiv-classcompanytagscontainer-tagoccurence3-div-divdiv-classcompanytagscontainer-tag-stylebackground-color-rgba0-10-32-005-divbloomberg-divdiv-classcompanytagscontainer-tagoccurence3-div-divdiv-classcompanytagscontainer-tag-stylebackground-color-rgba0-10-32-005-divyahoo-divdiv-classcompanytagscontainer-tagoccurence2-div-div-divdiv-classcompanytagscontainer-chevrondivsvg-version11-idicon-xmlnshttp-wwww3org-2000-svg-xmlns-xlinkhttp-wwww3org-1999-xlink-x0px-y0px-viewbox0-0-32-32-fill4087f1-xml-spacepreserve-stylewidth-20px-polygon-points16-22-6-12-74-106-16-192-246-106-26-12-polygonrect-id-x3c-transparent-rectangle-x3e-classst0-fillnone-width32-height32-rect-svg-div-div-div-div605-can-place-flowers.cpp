class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        
        // int m = flowerbed.size();
        // int count1 = 0, count0 = 0;;
        // int i=0, tsum = 0;
        // while(i<m && flowerbed[i]==0){
        //     count0++;
        //     i++;
        // }
        // tsum = count0/2;
        // count0=0;
        // while(i<m){
        //     if(flowerbed[i]==1 && count1==0){
        //         count1++;
        //         i++;
        //     }
        //     else if(flowerbed[i]==0){
        //         count0++;
        //         i++;
        //     }
        //     else if(flowerbed[i]==1 && count1==1){
        //         count1=0;
        //         tsum+=(count0-1)/2;
        //         count0=0;
        //         i++;
        //     }
        // }
        // if(count0>0){
        //     tsum+=(count0)/2;
        // }
        // // cout<<tsum<<endl;
        // return tsum>=n;
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                count++;
                flowerbed[i]=1;
            }
        }
        
        return count>=n;
        
    }
};