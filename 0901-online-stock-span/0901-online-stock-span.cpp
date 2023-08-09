class StockSpanner {
public:
    stack<int>st;
    unordered_map<int, int>mp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int num = 1;
        if(st.empty()){
            st.push(price);
            mp[price]++;
        }
        else{
            while(!st.empty() && st.top()<=price){
                num+=mp[st.top()];
                st.pop();
            }
            st.push(price);
            mp[price]=num;
        }
        return num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */