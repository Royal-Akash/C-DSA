class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(auto it:mp){
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
            
        }
        for(int i=0;i<k;i++){
            pair<int, int>num=pq.top();
            ans.push_back(num.second);
            pq.pop();
        }
        return ans;
    }
};