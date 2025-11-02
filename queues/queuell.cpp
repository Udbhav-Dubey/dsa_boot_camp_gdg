#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue structure
struct myQueue {
    int currSize;
    Node* front;
    Node* rear;

    // initialize the queue
    void init() {
        currSize = 0;
        front = rear = nullptr;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int new_data) {
        Node* node = new Node;
        node->data = new_data;
        node->next = nullptr;

        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }

        currSize++;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        Node* temp = front;
        int removedData = temp->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        currSize--;
        return removedData;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Get size
    int size() {
        return currSize;
    }
};

int main() {
    myQueue q;
    q.init();  // initialize queue

    q.enqueue(10);
    q.enqueue(20);

    cout << "Dequeue: " << q.dequeue() << "\n";

    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
