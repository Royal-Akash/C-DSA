class MyQueue {
public:
    stack<int>input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int num = output.top();
            output.pop();
            return num;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int num = output.top();
            output.pop();
            return num;
        }
    }
    
    int peek() {
        if(!output.empty()){
            int num = output.top();
            return num;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int num = output.top();
            return num;
        }
    }
    
    bool empty() {
        if(output.size()==0 && input.size()==0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */