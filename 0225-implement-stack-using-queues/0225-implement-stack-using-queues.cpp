class MyStack {
public:
    queue<int> q1, q2;
int current_size;

/** Initialize your data structure here. */
MyStack() {
    current_size = 0;
}

/** Push element x onto stack. */
void push(int x) {
    
    //Increase size
    current_size++;
    
    //Push x into empty queue 2 first
    q2.push(x);
    
    //Push all the remaining elements in q1 to q2
    while(q1.empty() == false)
    {
        q2.push(q1.front());
        q1.pop();
    }
    
    //Swap the two queues
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    
}

/** Removes the element on top of the stack and returns that element. */
int pop() {
    
    //If no elements are in q1 simply return
    if(q1.empty() == true)
        return -1;
    
	//Store element before popping
    int pop = q1.front();
	
	//Pop element and decrease size
    q1.pop();
    current_size-=1;
    
    return pop;
}

/** Get the top element. */
int top() {
    
    if(q1.empty() == true)
        return -1;
    
    return q1.front();
    
}

/** Returns whether the stack is empty. */
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