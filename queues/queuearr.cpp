#include <iostream>
using namespace std;

struct myQueue {
    int arr[100];   // fixed-size array
    int capacity;   // maximum number of elements
    int size;       // current number of elements

    // initialize the queue
    void init(int c) {
        capacity = c;
        size = 0;
    }

    // check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // check if queue is full
    bool isFull() {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    // Removes the front element of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Returns the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Returns the last element of the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[size - 1];
    }
};

int main() {
    myQueue q;
    q.init(3);   // initialize with capacity 3

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.getFront() << endl;

    q.dequeue();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.enqueue(40);

    return 0;
}
