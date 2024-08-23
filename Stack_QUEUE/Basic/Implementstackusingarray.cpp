#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};

// } Driver Code Ends
// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

// Function to push an integer into the stack.
void MyStack::push(int x)
{
    if (top == 999)
    { // Check if the stack is full
        return;
    }
    arr[++top] = x; // Insert element and increment size
}

// Function to remove an item from the top of the stack.
int MyStack::pop()
{
    if (top == -1)
    { // Check if the stack is empty
        return -1;
    }
    else
    {
        int poppedValue = arr[top--];
        return poppedValue; // Decrement size and return top element
    }
}

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--)
    {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int QueryType = nums[i++];
            if (QueryType == 1)
            {
                int a = nums[i++];
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
    return 0;
}
