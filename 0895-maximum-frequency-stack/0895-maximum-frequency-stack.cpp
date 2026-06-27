class FreqStack {
public:
    map<int,int> mp;
    map<int,stack<int>> order;
    int large=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        order[mp[val]].push(val);
        large=max(large,mp[val]);
    }
    
    int pop() {
        int x=order[large].top();
        order[large].pop();
        mp[x]--;
        if(order[large].empty()){
            large--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */