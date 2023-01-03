class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs.size(), m = strs[0].size();

        int ans = 0;
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                if (strs[i][j] < strs[i - 1][j]) {
                    ans++;
                    break;
                }

        return ans;
    }
};
// int n = strs.size();
//         int m = strs[0].size();
//         int count=0;
//         for(int i=0;i<n;i++){
            
//             for(int j=0;j<m-1;j++){
                
//                 if(strs[i].size()==1){
//                     break;
//                 }
//                 if((strs[i][j]-'a')>(strs[i][j+1]-'a')){
//                     count++;
//                     break;
//                 }
                
//             }
//         }
//         return count;