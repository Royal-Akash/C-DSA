class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,double>>adj[n+1];
        
        int i=0;
        for(auto x:edges){
            adj[x[0]].push_back({x[1],succProb[i]});
            adj[x[1]].push_back({x[0],succProb[i]});
            i++;
        }
        set<double>st;
        priority_queue<int>pq;
        pq.push(start);
        
        vector<double>dist(n,0);
        dist[start]=1.0;
        while(pq.empty()==false){
            auto it=pq.top();
            pq.pop();
            for(auto x:adj[it]){
                if(dist[it]*x.second>dist[x.first]){
                    dist[x.first]=dist[it]*x.second;
                    pq.push(x.first);
                }
            }
        }
        return dist[end];
    }
};