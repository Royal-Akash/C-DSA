class MyStack {
public:
    queue<int>q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        for(int i=0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int num = q1.front();
        q1.pop();
        int m = q2.size();
        for(int i=0;i<m;i++){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
    
    int top() {
        int n = q1.size();
        int num = 0;
        for(int i=0;i<n;i++){
            num = q1.front();
            q2.push(num);
            q1.pop();
        }
        int m = q2.size();
        for(int i=0;i<m;i++){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */