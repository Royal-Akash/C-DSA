class Solution {
public:
    long long totalCost(vector<int>& a, int k, int c) {
        int i=0,j=a.size()-1;
        priority_queue<int,vector<int>,greater<int>> qs,qe;
        long long ans=0;

        while(c-- && i<=j)
        {
            qs.push(a[i++]);
            if(i<=j) qe.push(a[j--]);
        }

        while(k--)
        {
            if(qs.empty())
            {
                ans+=qe.top();
                qe.pop();
            }
            else if(qe.empty())
            {
                ans+=qs.top();
                qs.pop();
            }
            else if(qs.top()<=qe.top())
            {
                ans+=qs.top();
                qs.pop();

                if(i<=j)
                qs.push(a[i++]);
            }
            else
            {
                ans+=qe.top();
                qe.pop();

                if(i<=j)
                qe.push(a[j--]);
            }
        }

        return ans;
    }
};