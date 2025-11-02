#include <iostream>
using namespace std;

struct myStack {
    int arr[100];   //initializing a fixed-size array for elemnts
    int capacity;   // depicts the maximum stack size
    int top;        // for tracking the index of top element

    // initialize stack in this function
    void init(int cap) {
        capacity = cap;
        top = -1;
    }

    // push operation(inserting elements)
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // pop operation(removing elements)
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // peek (or top) operation(presenting the topmost element as output)
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    //to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    //to check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    myStack st;
    st.init(4);   // initialize stack with capacity 4

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // popping one element
    cout << "Popped: " << st.pop() << "\n";

    // checking top element
    cout << "Top element: " << st.peek() << "\n";

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";

    // checking if stack is full
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";

    return 0;
}
