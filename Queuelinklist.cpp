#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front; // points to first element
    Node* rear;  // points to last element

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue: Insert at rear
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;

        if (rear == nullptr) { 
            // Empty queue
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << x << " enqueued to queue\n";
    }

    // Dequeue: Remove from front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << front->data << " dequeued from queue\n";
        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Peek: Get front element
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element is: " << front->data << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // extra dequeue

    return 0;
}