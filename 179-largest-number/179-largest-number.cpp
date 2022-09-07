class Solution {
public:
   static bool comp(string& s1 , string& s2){
        
        return (s1+s2)>(s2+s1);
        
    }
    
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        // int x=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         x++;
        //     }
        // }
        // if(x==nums.size()) return "0";
        
//         for(int i=0;i<n;i++){
            
//             for(int j=i+1;j<n;j++){
                
//                 string x = to_string(nums[i]) + to_string(nums[j]);
//                 string y = to_string(nums[j]) + to_string(nums[i]);
                
//                 if(y>x){
//                     swap(nums[i] , nums[j]);
//                 }
                
//             }
//         }
        
        vector<string> s1(n , "");
        for(int i=0;i<n;i++){
            s1[i]=to_string(nums[i]);
        }
        sort(s1.begin() , s1.end() , comp);
        string str;
        if(s1[0]=="0") return "0";
        for(int i=0;i<n;i++){
            str+=s1[i];
        }
            return str;
    }
};