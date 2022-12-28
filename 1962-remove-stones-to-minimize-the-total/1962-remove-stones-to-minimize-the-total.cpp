class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++){
            int k = pq.top();
            pq.pop();
            // cout<<k<<" ";
            pq.push(ceil((double(k))/2));
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};