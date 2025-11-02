#include <iostream>
using namespace std;

// Manual stack structure (no STL)
struct myStack {
    int arr[100];
    int top;
    int capacity;

    void init(int cap) {
        capacity = cap;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

// Queue using two manual stacks
struct myQueue {
    myStack s1, s2;

    void init() {
        s1.init(100);
        s2.init(100);
    }

    // Enqueue operation
    void enqueue(int x) {
        // Move all elements from s1 to s2
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }

        // Push the new element into s1
        s1.push(x);

        // Move elements back to s1
        while (!s2.isEmpty()) {
            s1.push(s2.pop());
        }
    }

    // Dequeue operation
    void dequeue() {
        if (s1.isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        s1.pop();
    }

    // Front operation
    int front() {
        if (s1.isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.peek();
    }

    // Size operation
    int size() {
        return s1.size();
    }
};

// Driver code
int main() {
    myQueue q;
    q.init();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << '\n';
    cout << "Size: " << q.size() << '\n';

    q.dequeue();
    cout << "Front: " << q.front() << '\n';
    cout << "Size: " << q.size() << '\n';

    return 0;
}

#include <iostream>
using namespace std;


struct myStack {
    int arr[100];
    int top;
    int capacity;

    void init(int cap) {
        capacity = cap;
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

// Queue using two manual stacks
struct myQueue {
    myStack s1, s2;

    void init() {
        s1.init(100);
        s2.init(100);
    }

    // Enqueue operation (O(1))
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue operation (O(n) in worst case)
    void dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Move elements only if s2 is empty
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        s2.pop();
    }

    // Return front element
    int front() {
        if (!s2.isEmpty())
            return s2.peek();

        if (!s1.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
            return s2.peek();
        }

        cout << "Queue is empty\n";
        return -1;
    }

    // Return queue size
    int size() {
        return s1.size() + s2.size();
    }
};

// Driver code
int main() {
    myQueue q;
    q.init();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << "\n";
    cout << "Size: " << q.size() << "\n";

    q.dequeue();
    cout << "Front: " << q.front() << "\n";
    cout << "Size: " << q.size() << "\n";

    return 0;
}
