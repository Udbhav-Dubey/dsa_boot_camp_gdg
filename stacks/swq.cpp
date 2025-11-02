#include <iostream>
using namespace std;

// Simple fixed-size queue implementation
struct myQueue {
    int arr[100];
    int front, rear, size;

    void init() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == 100;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % 100;
        size--;
        return val;
    }

    int frontElement() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
};

// Stack using two manual queues
struct myStack {
    myQueue q1, q2;

    void init() {
        q1.init();
        q2.init();
    }

    void push(int x) {
        // Push x to empty q2
        q2.enqueue(x);

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Swap queues (by value)
        myQueue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.frontElement();
    }

    int size() {
        return q1.size;
    }
};

// Driver code
int main() {
    myStack st;
    st.init();

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl; // 3
    st.pop();
    cout << st.top() << endl; // 2
    st.pop();
    cout << st.top() << endl; // 1

    cout << st.size() << endl; // 1

    return 0;
}


#include <iostream>
using namespace std;

// Manual fixed-size queue structure
struct myQueue {
    int arr[100];
    int front, rear, size;

    void init() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (size == 100) {
            cout << "Queue Overflow\n";
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % 100;
        size--;
        return val;
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

// Stack using two queues
struct myStack {
    myQueue q1, q2;

    void init() {
        q1.init();
        q2.init();
    }

    void push(int x) {
        q1.enqueue(x);
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        // Move all but last element to q2
        while (q1.size > 1) {
            q2.enqueue(q1.dequeue());
        }

        // Remove the last (top) element
        q1.dequeue();

        // Swap queues
        myQueue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        while (q1.size > 1) {
            q2.enqueue(q1.dequeue());
        }

        int temp = q1.frontElement();
        q1.dequeue();
        q2.enqueue(temp);

        // Swap queues
        myQueue t = q1;
        q1 = q2;
        q2 = t;

        return temp;
    }

    int size() {
        return q1.size;
    }
};

// Driver code
int main() {
    myStack st;
    st.init();

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl; // 3
    st.pop();
    cout << st.top() << endl; // 2
    st.pop();
    cout << st.top() << endl; // 1
    cout << st.size() << endl; // 1

    return 0;
}
