class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> v;
        unordered_map<int , int>mp;
            for(int i=0;i<arr.size();i++){
                mp[arr[i]]++;
            }
        int sum=0 , count=0;
        for(auto it : mp){
            v.push_back(it.second);
        }
//         for(int i=0;i<arr.size();i++){
            
            
//             if(sum>=((arr.size())/2)){
//                 break;
//             }
//             count++;
//             sum+=mp[arr[i]];
            
//         }
        
//         for(auto it : mp){
            
//             sum+=it.second;
//             count++;
//             if(sum>=((arr.size())/2)){
//                 break;
//             }
            
            
//         }
        
        sort(v.begin() , v.end());
        for(int i=v.size()-1;i>=0;i--){
            sum+=v[i];
            count++;
            if(sum>=(arr.size()/2)){
                break;
            }
        }
        return count;
    }
};