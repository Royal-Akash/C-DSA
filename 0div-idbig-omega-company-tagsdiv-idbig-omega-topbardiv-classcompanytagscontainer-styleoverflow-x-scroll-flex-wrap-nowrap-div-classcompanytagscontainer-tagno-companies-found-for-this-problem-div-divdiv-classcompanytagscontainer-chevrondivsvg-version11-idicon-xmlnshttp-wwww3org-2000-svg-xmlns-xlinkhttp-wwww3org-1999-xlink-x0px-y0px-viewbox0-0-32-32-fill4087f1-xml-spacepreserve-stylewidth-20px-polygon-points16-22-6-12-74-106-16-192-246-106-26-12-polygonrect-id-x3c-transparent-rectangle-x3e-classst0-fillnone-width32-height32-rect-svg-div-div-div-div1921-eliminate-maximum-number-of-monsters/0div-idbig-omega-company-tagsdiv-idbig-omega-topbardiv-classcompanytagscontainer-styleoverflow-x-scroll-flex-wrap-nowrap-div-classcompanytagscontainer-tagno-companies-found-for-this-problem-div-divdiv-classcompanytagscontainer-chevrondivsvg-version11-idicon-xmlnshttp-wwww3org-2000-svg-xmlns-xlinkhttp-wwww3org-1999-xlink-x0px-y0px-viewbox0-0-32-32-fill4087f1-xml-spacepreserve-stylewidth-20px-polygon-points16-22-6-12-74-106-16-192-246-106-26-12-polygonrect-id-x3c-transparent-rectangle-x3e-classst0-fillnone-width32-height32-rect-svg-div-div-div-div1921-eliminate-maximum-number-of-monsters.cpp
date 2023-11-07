class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        for(int i = 0 ; i<dist.size();i++)
        {
            time.push_back((double)dist[i] / (double)speed[i]);
        }
        // sorted to get the monster that is nearest so that we can kill that on first
        sort(time.begin(),time.end());
        int timer= 0 ;
        int cnt = 0;
        for(auto a : time)
        {
            if(a<=timer)
            {
                break;
            }
            else{ 
                timer++;
                cnt++;
            }
        }
        return timer;
    }
};