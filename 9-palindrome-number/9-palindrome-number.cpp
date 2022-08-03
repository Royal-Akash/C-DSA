class Solution {
public:
    bool isPalindrome(int x) {
        
        vector<int> ans;
        if(x<0){
            return false;
        }
        int rem =0;
        while(x){
            
            rem = x%10;
            x=x/10;
            ans.push_back(rem);
        }
        int n = ans.size();
        for(int i=0;i<n;i++){
            
            if(ans[i]!=ans[n-i-1]) return false;
            
        }
        return true;
    }
};