#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // Empty list

// -------- CREATE FUNCTION --------
void createList() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    head = nullptr; // reset

    for (int i = 1; i <= n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> value;

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode; // first node
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    cout << "List created.\n";
}

// -------- INSERT FUNCTIONS --------
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted at beginning: " << value << endl;
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted at end: " << value << endl;
}

void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted at position 1: " << value << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at position " << position << ": " << value << endl;
}

// -------- DELETE FUNCTIONS --------
void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted from beginning: " << temp->data << endl;
    delete temp;
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted from end: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    cout << "Deleted from end: " << temp->data << endl;
    delete temp;
}

void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted at position 1: " << temp->data << endl;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    for (int i = 1; i < position && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }
    prev->next = temp->next;
    cout << "Deleted at position " << position << ": " << temp->data << endl;
    delete temp;
}

// -------- SEARCH FUNCTION --------
void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << key << " not found." << endl;
}

// -------- DISPLAY FUNCTION --------
void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// -------- MAIN (Menu) --------
int main() {
    int choice, value, position;
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Create List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete at Beginning\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete at Position\n";
        cout << "8. Search\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(value, position);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                cout << "Enter position: ";
                cin >> position;
                deleteAtPosition(position);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 9:
                display();
                break;
            case 10:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);

    return 0;
}