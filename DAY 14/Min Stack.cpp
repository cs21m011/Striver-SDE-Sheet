class MinStack {
    int stack_top,bottom,size,minimum;
    int *stack;
public:
    MinStack() {
        stack_top=-1;
        bottom=-1;
        size=10000;
        stack=new int[size];
        minimum=INT_MAX;
    }
    
    void push(int val) {
        if(stack_top==-1 && bottom==-1){
            stack[++stack_top]=val;
            bottom++;
        }
        else
            stack[++stack_top]=val;
        
        if(stack[stack_top]<minimum)
            minimum=stack[stack_top];
    }
    
    void pop() {
        if(stack_top==-1 && bottom==-1)
            return;
        
        if(stack[stack_top]==minimum)
            minimum=INT_MAX;
        
        stack_top--;
        
        for(int i=bottom;i<=stack_top;i++){
            if(stack[i]<minimum)
                minimum=stack[i];
        }
    }
    
    int top() {
        if(stack_top==-1 && bottom==-1)
            return -1;
        
        return stack[stack_top];
    }
    
    int getMin() {
        if(stack_top==-1 && bottom==-1)
            return -1;
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */