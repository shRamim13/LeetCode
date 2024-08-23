private:
StackNode *top; // Pointer to the top node of the stack

public:
MyStack()
{
    top = nullptr;
}

// Function to push an element onto the stack
void push(int x)
{
    // Create a new node with the given data
    StackNode *newNode = new StackNode(x);

    // Point the new node to the current top node
    newNode->next = top;

    // Update the top pointer to the new node
    top = newNode;
}

// Function to pop an element from the stack
int pop()
{
    if (top == nullptr)
    {
        return -1; // Stack is empty
    }

    // Get the data from the top node
    int poppedData = top->data;

    // Move the top pointer to the next node
    StackNode *temp = top;
    top = top->next;

    // Delete the old top node
    delete temp;

    return poppedData;
}