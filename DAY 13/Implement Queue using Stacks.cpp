class MyQueue {
    int top,bottom,size,count;
    int *stack;
public:
    MyQueue() {
        top=-1;
        bottom=-1;
        size=500;
        count=0;
        stack=new int[size];
    }
    
    void push(int x) {
        if(count==size)
            return;
        
        if(bottom==-1)
            bottom=0;
        stack[++top]=x;
    }
    
    int pop() {
        if((top==-1 && bottom==-1) || (top+1)==bottom)
            return -1;
        return stack[bottom++];
    }
    
    int peek() {
        if(bottom==-1)
            return -1;
        return stack[bottom];
    }
    
    bool empty() {
        if((top==-1 && bottom==-1) || (top+1)==bottom)
            return true;
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