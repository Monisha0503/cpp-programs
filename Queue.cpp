#include <iostream>
using namespace std;

#define SIZE 5

int linearQueue[SIZE];
int circularQueue[SIZE];

// Linear Queue variables
int front1 = -1, rear1 = -1;

// Circular Queue variables
int front2 = -1, rear2 = -1;

// ---------- Linear Queue Functions ----------
void linearInsert(int value) {
    if (rear1 == SIZE - 1) {
        cout << "Linear Queue is Full\n";
    } else {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        linearQueue[rear1] = value;
        cout << "Inserted in Linear Queue: " << value << endl;
    }
}

void linearDelete() {
    if (front1 == -1 || front1 > rear1) {
        cout << "Linear Queue is Empty\n";
    } else {
        cout << "Deleted from Linear Queue: " << linearQueue[front1] << endl;
        front1++;
    }
}

void linearDisplay() {
    if (front1 == -1 || front1 > rear1) {
        cout << "Linear Queue is Empty\n";
    } else {
        cout << "Linear Queue Elements: ";
        for (int i = front1; i <= rear1; i++) {
            cout << linearQueue[i] << " ";
        }
        cout << endl;
    }
}

// ---------- Circular Queue Functions ----------
void circularInsert(int value) {
    if ((front2 == 0 && rear2 == SIZE - 1) || (rear2 + 1) % SIZE == front2) {
        cout << "Circular Queue is Full\n";
    } else {
        if (front2 == -1)
            front2 = rear2 = 0;
        else
            rear2 = (rear2 + 1) % SIZE;
        circularQueue[rear2] = value;
        cout << "Inserted in Circular Queue: " << value << endl;
    }
}

void circularDelete() {
    if (front2 == -1) {
        cout << "Circular Queue is Empty\n";
    } else {
        cout << "Deleted from Circular Queue: " << circularQueue[front2] << endl;
        if (front2 == rear2)
            front2 = rear2 = -1;
        else
            front2 = (front2 + 1) % SIZE;
    }
}

void circularDisplay() {
    if (front2 == -1) {
        cout << "Circular Queue is Empty\n";
    } else {
        cout << "Circular Queue Elements: ";
        int i = front2;
        while (true) {
            cout << circularQueue[i] << " ";
            if (i == rear2)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}

// ---------- Main Function ----------
int main() {
    int choice, queueType, value;

    while (true) {
        cout << "\n========= MENU =========\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }

        cout << "Choose Queue Type:\n1. Linear Queue\n2. Circular Queue\nEnter your choice: ";
        cin >> queueType;

        switch (choice) {
        case 1: // Insert
            cout << "Enter value to insert: ";
            cin >> value;
            if (queueType == 1)
                linearInsert(value);
            else if (queueType == 2)
                circularInsert(value);
            else
                cout << "Invalid Queue Type\n";
            break;

        case 2: // Delete
            if (queueType == 1)
                linearDelete();
            else if (queueType == 2)
                circularDelete();
            else
                cout << "Invalid Queue Type\n";
            break;

        case 3: // Display
            if (queueType == 1)
                linearDisplay();
            else if (queueType == 2)
                circularDisplay();
            else
                cout << "Invalid Queue Type\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}