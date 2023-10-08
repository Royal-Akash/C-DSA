class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int n, int m){
        
        if(i==n && j==m) return 0;
        else if(i<n && j>=m) return INT_MIN;
        else if(i>=n && j<m) return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        int num1 = nums1[i]*nums2[j];
        if(solve(i+1, j+1, nums1, nums2, n, m)>=0){
            num1+=solve(i+1, j+1, nums1, nums2, n, m);
        }
        int num2 = solve(i, j+1, nums1, nums2, n, m);
        int num3 = solve(i+1, j, nums1, nums2, n, m);

        return dp[i][j]=max({num1, num2, num3});
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2, n, m);
    }
};