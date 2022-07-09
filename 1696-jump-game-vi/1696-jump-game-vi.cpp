class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    int n=nums.size();
        vector<int>v(n,INT_MIN);
        
        priority_queue<pair<int,int>>pq;
        
        v[0]=nums[0];
        pq.push({v[0],0});
        
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && pq.top().second<(i-k))
                pq.pop();
            v[i]=pq.top().first+nums[i];
          
            pq.push({v[i],i});
        }
        return v[n-1];
    }
};