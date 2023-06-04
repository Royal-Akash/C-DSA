class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& que) {
        vector<long long> rowChanges(n, 0);
        vector<long long> colChanges(n, 0);
        long long ans = 0;
        int col = 0;
        int row = 0;
        reverse(que.begin(), que.end());
        for (const auto& query : que) {
            int type = query[0];
            int index = query[1];
            int val = query[2];

            if (type == 1 && !colChanges[index] && (n-row)>0) {
                
                colChanges[index] = 1;
                ans += (val * (n-row));  
                col++;
            } 
            else if(type == 0 && !rowChanges[index] && (n-col)>0){
                
                rowChanges[index] = 1;
                ans += (val * (n-col)); 
                row++;
            }
        }

        return ans;
    }
};

