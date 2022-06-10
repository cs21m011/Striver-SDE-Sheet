class MyStack {
    int f,b,size,count;
    int *queue;
public:
    MyStack() {
        f=-1;
        b=-1;
        count=0;
        size=500;
        queue=new int[size];
    }
    
    void push(int x) {
        if(count==size)
            return;
        
        if(f==-1)
            f=0;
        
        b=(b+1)%size;
        queue[b]=x;
    }
    
    int pop() {
        if((f==-1 && b==-1) || (b+1==f))
            return -1;
        return queue[b--];
    }
    
    int top() {
        if(f==-1 && b==-1)
            return -1;
        return queue[b];
    }
    
    bool empty() {
        if((f==-1 && b==-1) || (b+1==f))
            return true;
        return false;
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