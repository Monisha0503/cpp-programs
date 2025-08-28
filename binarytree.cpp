#include <iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert node on the left chain
void insertLeft(Node* root, int val) {
    if (root->left == nullptr)
        root->left = new Node(val);
    else
        insertLeft(root->left, val);
}

// Insert node on the right chain
void insertRight(Node* root, int val) {
    if (root->right == nullptr)
        root->right = new Node(val);
    else
        insertRight(root->right, val);
}

// Search for a key in the tree
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    return search(root->left, key) || search(root->right, key);
}

// Delete the entire tree
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Traversal functions
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int choice, val, key;

    do {
        cout << "\n======= Binary Tree Menu =======\n";
        cout << "1. Create Root\n";
        cout << "2. Insert Left\n";
        cout << "3. Insert Right\n";
        cout << "4. Search\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Inorder Traversal\n";
        cout << "7. Postorder Traversal\n";
        cout << "8. Delete Entire Tree\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (root == nullptr) {
                    cout << "Enter root value: ";
                    cin >> val;
                    root = new Node(val);
                    cout << "Root created with value " << val << endl;
                } else {
                    cout << "Root already exists!\n";
                }
                break;

            case 2:
                if (root == nullptr)
                    cout << "Create root first!\n";
                else {
                    cout << "Enter value to insert left: ";
                    cin >> val;
                    insertLeft(root, val);
                }
                break;

            case 3:
                if (root == nullptr)
                    cout << "Create root first!\n";
                else {
                    cout << "Enter value to insert right: ";
                    cin >> val;
                    insertRight(root, val);
                }
                break;

            case 4:
                if (root == nullptr) {
                    cout << "Tree is empty! Search failed.\n";
                } else {
                    cout << "Enter value to search: ";
                    cin >> key;
                    cout << (search(root, key) ? "Found" : "Not Found") << endl;
                }
                break;

            case 5:
                if (root == nullptr)
                    cout << "Tree is empty!\n";
                else {
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                }
                break;

            case 6:
                if (root == nullptr)
                    cout << "Tree is empty!\n";
                else {
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                break;

            case 7:
                if (root == nullptr)
                    cout << "Tree is empty!\n";
                else {
                    cout << "Postorder: ";
                    postorder(root);
                    cout << endl;
                }
                break;

            case 8:
                if (root == nullptr)
                    cout << "Tree is already empty!\n";
                else {
                    deleteTree(root);
                    root = nullptr;
                    cout << "Tree deleted successfully.\n";
                }
                break;

            case 9:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice — try again.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}