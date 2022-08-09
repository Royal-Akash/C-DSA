class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        map<int , long long int>mp;
        for(int i=0;i<arr.size();i++){
            // mp[arr[i]]=1;
            mp.insert({arr[i] , 1});
            
        }
        sort(arr.begin() , arr.end());
        
        for(int i=1;i<arr.size();i++){
            long long int count=0;
            auto it3 = mp.find(arr[i]);
            for(int j=0;j<i;j++){
                
                if(arr[i]%arr[j]==0){
                    auto it = mp.find(arr[i]/arr[j]);
                    auto it2 = mp.find(arr[j]);
                    if(it!=mp.end()){
                        count+=(it->second)*(it2->second);
                    }
                }
            }
            it3->second+=count;
        }
        long long int sum=0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            sum+=it->second;
            
        }
        return sum % (1000000007);
        
    }
};