class KthLargest {
public:
    priority_queue<int>max;
    priority_queue<int,vector<int>, greater<int>>min;
    int z = 0;
    KthLargest(int k, vector<int>& nums) {
        z=k;
        for(int i=0;i<nums.size();i++){
            min.push(nums[i]);
        }
        while(min.size()>k){
            max.push(min.top());
            min.pop();
        }
    }
    
    int add(int val) {
        
        min.push(val);
        if(min.size()>z){
            while(min.size()>z){
                max.push(min.top());
                min.pop();
            }
        }
        // max.push(min.top());
        // min.pop();
        return min.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */