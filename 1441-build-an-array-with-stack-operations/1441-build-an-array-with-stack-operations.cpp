class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int k = target[target.size()-1];
        string push1 = "Push";
        string pop1 = "Pop";
        
        int num = 1;
        int i=0;
        while(i<target.size()){
            ans.push_back(push1);
            if(target[i]!=num){
                ans.push_back(pop1);
            }
            if(target[i]==num){
                i++;
            }
            num++;
        }
        return ans;
    }
};