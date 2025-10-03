#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
};

// Function to create new node
Node* createNode(int coeff, int power) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = nullptr;
    return newNode;
}

// Insert a term at end of polynomial
void insertNode(Node*& poly, int coeff, int power) {
    Node* newNode = createNode(coeff, power);

    if (poly == nullptr) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display polynomial
void display(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coeff << "x^" << poly->power;
        poly = poly->next;
        if (poly != nullptr && poly->coeff >= 0)
            cout << " + ";
    }
    cout << endl;
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        if (poly1->power > poly2->power) {
            insertNode(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) {
            insertNode(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else {
            // powers equal → add coefficients
            insertNode(result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Copy remaining terms
    while (poly1 != nullptr) {
        insertNode(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    while (poly2 != nullptr) {
        insertNode(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* result = nullptr;

    // Example input (can be modified or read from user)
    insertNode(poly1, 6, 3);
    insertNode(poly1, 5, 2);
    insertNode(poly1, 9, 1);
    insertNode(poly1, 5, 0);

    insertNode(poly2, 3, 3);
    insertNode(poly2, 8, 1);
    insertNode(poly2, 7, 0);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    result = addPolynomials(poly1, poly2);

    cout << "Result (Addition): ";
    display(result);

    return 0;
}