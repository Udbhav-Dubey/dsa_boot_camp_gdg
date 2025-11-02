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

// ===== INSERTION FUNCTIONS =====

// Insert at beginning
void insertAtBegin(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
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

// Insert at specific position
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

// ===== DELETION FUNCTIONS =====

// Delete at beginning
void deleteAtBegin(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value: " << temp->data << endl;
    delete temp;
}

// Delete at end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr) { // only one node
        cout << "Deleted node with value: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted node with value: " << temp->next->data << endl;
    delete temp->next;
    temp->next = nullptr;
}

// Delete at specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        deleteAtBegin(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted node with value: " << nodeToDelete->data << endl;
    delete nodeToDelete;
}

// ===== DISPLAY FUNCTION =====
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

// ===== MAIN FUNCTION =====
int main() {
    Node* head = nullptr;

    // Insertion demo
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << "\nInitial List:" << endl;
    display(head);

    // Deletion at beginning
    cout << "\nDeleting at beginning..." << endl;
    deleteAtBegin(head);
    display(head);

    // Deletion at end
    cout << "\nDeleting at end..." << endl;
    deleteAtEnd(head);
    display(head);

    // Deletion at position
    cout << "\nDeleting at position 2..." << endl;
    deleteAtPosition(head, 2);
    display(head);

    // Clean up all remaining nodes
    cout << "\nDeleting all remaining nodes..." << endl;
    while (head != nullptr)
        deleteAtBegin(head);

    display(head);

    return 0;
}
