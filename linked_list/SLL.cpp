#include <iostream>
using namespace std;

// Define structure for a node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert at the beginning
void insertAtBegin(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Function to insert at a specific position
void insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        insertAtBegin(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;  // initially empty list

    cout << "Inserting 10 at beginning..." << endl;
    insertAtBegin(head, 10);
    display(head);

    cout << "Inserting 20 at end..." << endl;
    insertAtEnd(head, 20);
    display(head);

    cout << "Inserting 30 at end..." << endl;
    insertAtEnd(head, 30);
    display(head);

    cout << "Inserting 15 at position 2..." << endl;
    insertAtPosition(head, 15, 2);
    display(head);

    cout << "Inserting 5 at position 1..." << endl;
    insertAtPosition(head, 5, 1);
    display(head);

    cout << "Inserting 40 at position 6..." << endl;
    insertAtPosition(head, 40, 6);
    display(head);

    return 0;
}
