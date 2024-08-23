class MyQueue
{
private:
    stack<int> st, at;

public:
    MyQueue() {}

    // Push element x to the back of the queue.
    void push(int x)
    {
        // Transfer all elements from st to at
        while (!st.empty())
        {
            at.push(st.top());
            st.pop();
        }

        // Push the new element to st
        st.push(x);

        // Transfer all elements back to st from at
        while (!at.empty())
        {
            st.push(at.top());
            at.pop();
        }
    }

    // Removes the element from the front of the queue and returns it.
    int pop()
    {
        int top = st.top(); // Get the top element
        st.pop();           // Remove the top element
        return top;
    }

    // Get the front element.
    int peek()
    {
        return st.top(); // Return the top element
    }

    // Returns whether the queue is empty.
    bool empty()
    {
        return st.empty(); // Check if the stack is empty
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
