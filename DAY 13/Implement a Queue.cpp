class Queue {
    int f,b,size,count;
    int *queue;
public:
    Queue() {
        // Implement the Constructor
        f=-1;
        b=-1;
        size=1000;
        count=0;
        queue=new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(b+1==f || (f==-1 && b==-1))
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(count==size)
            return;
        if(f==-1)
            f=0;
        
        b=(b+1)%size;
        queue[b]=data;
        count++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if((b+1)!=f && f!=-1)
            return queue[f++];
        return -1;
    }

    int front() {
        // Implement the front() function
        if(f==-1 || (b+1)==f)
            return -1;
        return queue[f];
    }
};